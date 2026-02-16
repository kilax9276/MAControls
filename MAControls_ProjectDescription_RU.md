# MAControls / MAMSHFlexGridEx — описание проекта (актуально для текущих исходников)

## 1) Что это за DLL и какие компоненты она содержит

Проект собирает **MAControls.dll** (ATL/ActiveX). Внутри DLL зарегистрированы два COM‑контрола:

1) **C935_Gen34.MA_MSHFlexGridEx** (`MAMSHFlexGridEx`)
   - Это *обёртка* над сторонним ActiveX **MSHFlexGrid** (ProgID: `MSHierarchicalFlexGridLib.MSHFlexGrid`).
   - Контрол создаёт настоящий MSHFlexGrid внутри себя и добавляет поверх него логику **настраиваемого редактирования ячеек**:
     - для текстовых ячеек — **внешний Win32 EDIT** в popup‑окне (показывается ниже/выше активной ячейки),
     - для Combo/List‑ячеек — **внешний ActiveX MAComboBoxEx**, который в свою очередь хостит `MSForms.ComboBox`.

2) **C935_Gen34.MA_ComboBoxEx** (`MAComboBoxEx`)
   - Небольшой ActiveX‑контрол‑обёртка, который хостит **MSForms.ComboBox** внутри ATL `CAxWindow`.
   - Предназначен для использования как «оверлей‑редактор» поверх клетки грида.

> Важно: в `MAMSHFlexGridEx.cpp` эти ProgID зафиксированы константами:
> - `PROGID_MSHFLEXGRID = "MSHierarchicalFlexGridLib.MSHFlexGrid"`
> - `PROGID_EDITOR     = "C935_Gen34.MA_ComboBoxEx.1"`

---

## 2) Основная идея реализации (как всё работает вместе)

### 2.1 Внутренние окна (HWND) и зачем нужен `SetWindowSubclass`

ActiveX‑контролы (MSHFlexGrid и MSForms.ComboBox) внутри контейнера (VB6/ThunderForm/и т.п.) создают цепочку вложенных окон.
Чтобы корректно перехватывать клавиши и управлять фокусом, проект делает две вещи:

1) **Хостит** ActiveX внутри `CAxWindow`:
   - `m_axGrid` — хост для MSHFlexGrid
   - `m_axEdit` — хост для MAComboBoxEx (оверлей‑редактор)

2) Находит «самое глубокое» дочернее окно (deep child) внутри `m_axGrid`/`m_axEdit`
   и ставит на него `SetWindowSubclass(...)`, чтобы перехватывать **WM_KEYDOWN/WM_CHAR/WM_KILLFOCUS**:
   - `GridSubclassProc(...)` — перехват клавиатуры в режиме *не редактируем* (старт редактирования, стрелки, печать и т.п.)
   - `EditSubclassProc(...)` — перехват клавиатуры в режиме *редактируем* (Enter/Esc, Up/Down для списка)
   - `PopupEditSubclassProc(...)` — перехват клавиш в popup Win32 EDIT

### 2.2 Почему нужны «отложенные» действия через WM_APP

Для стабильности (особенно в VB6/ThunderForm) проект часто выполняет действия не сразу, а **постит сообщение самому себе**:

- `PostBeginEdit(...)` → `WM_APP_BEGINEDIT` → `BeginEdit(...)`
- `PostEndEdit(...)`   → `WM_APP_ENDEDIT`   → `EndEdit(...)`
- `PostFocusGrid()`    → `WM_APP_FOCUSGRID` → `FocusGridNow()`

Это решает типовые гонки, когда:
- при скрытии редактора фокус «прыгает» на форму/контейнер,
- стрелки после commit перестают двигать выделение в гриде,
- сообщения клавиатуры начинают уходить не туда.

---

## 3) Подробно про MAMSHFlexGridEx

### 3.1 Жизненный цикл и создание вложенных контролов

Ключевой вход: `CMAMSHFlexGridEx::OnCreate(...)`

В `OnCreate`:
1) вызывается `AtlAxWinInit()` (инициализация окна‑хоста для ActiveX),
2) создаётся `m_axGrid` (дочерний контейнер для грида),
3) в `CreateGrid()` создаётся сам MSHFlexGrid (через `CreateAxControlWithLicFallback(...)`),
4) создаётся `m_axEdit` (контейнер для оверлей‑редактора, изначально скрыт),
5) вызывается `Layout()`,
6) в UserMode запускается таймер `TIMER_HOOK`, который периодически пытается найти inner HWND и поставить subclass.

### 3.2 Почему `CreateAxControlWithLicFallback(...)`

Функция находится в `AxHostHelpers.h`. Она делает 2 попытки:
1) обычный `AtlAxCreateControlEx(...)`,
2) если получен `CLASS_E_NOTLICENSED`/`E_ACCESSDENIED`, пытается создать через `IClassFactory2` и лиценз‑ключ.

Это нужно для ActiveX, которые в некоторых окружениях требуют лицензирования.

### 3.3 Конфигурация типов ячеек и список значений

Конфигурация хранится на 3 уровнях:
- `m_defaultCfg` — дефолт для всех ячеек,
- `m_colCfg[col]` — дефолт для столбца,
- `m_cellCfg[(row,col)]` — конфигурация конкретной ячейки.

Типы ячеек определены в `MAControls.idl` (enum `MACellEditorType`):
- `maCellText` (0) — свободный текст
- `maCellCombo` (1) — список + свободный текст
- `maCellList` (2) — только список
- `maCellReadOnly` (3) — запрет редактирования

Публичные методы конфигурации:
- `SetCellType/SetCellItems/ClearCellItems/ClearCellConfig`
- `SetColumnType/SetColumnItems/ClearColumnConfig`
- `SetDefaultCellType/SetDefaultCellItems/ClearDefaultCellItems`

### 3.4 Настройки popup текстового редактора

В `MAControls.idl` это свойства:
- `TextEditWidthPx` (0 = ширина ячейки)
- `TextEditVisibleLines` (используется в multiline‑режиме, >=1)
- `TextEditMultiline` (VARIANT_BOOL)

В реализации:
- popup создаётся в `EnsurePopupEditorCreated(bool wantMultiline)`
- multiline поведение в `PopupEditSubclassProc`:
  - **Enter** вставляет новую строку (EDIT должен быть с `ES_WANTRETURN`)
  - **Ctrl+Enter** выполняет commit (вызов `PostEndEdit(true)`)
  - **Escape** делает cancel

Позиционирование относительно активной ячейки — `PositionPopupEditorBelowCell()`:
- окно старается появиться ниже,
- если снизу не хватает места — поднимается наверх,
- позиция «зажимается» в пределах root‑окна владельца.

### 3.5 Навигация при выходе из редактирования (Level‑B)

Навигация управляется через enum `MANavExitKeys` (mask) и структуру `NavConfig`.
Поддерживается 4 настройки:
- `exitKeysMask` (битовая маска `MANavExitKeys`)
- `tabWrap` (перенос на следующую/предыдущую строку при Tab/Shift+Tab)
- `skipReadOnly` (пропуск фиксированных рядов/колонок и `maCellReadOnly`)
- `beginEditAfterMove` (после перемещения автоматически начать редактирование)

Уровни навигации:
- `m_defaultNav` — общий дефолт
- `m_colNav[col]`, `m_rowNav[row]`, `m_cellNav[(row,col)]` — локальные переопределения

Ключевой механизм:
- при нажатии «выходной» клавиши в редакторе выставляется `m_navPending`,
- после `EndEdit(...)` вызывается `ApplyNavAfterEdit()` и выполняется перемещение.

### 3.6 Роутинг клавиатуры: `TranslateAccelerator(...)`

`MAMSHFlexGridEx` переопределяет `IOleInPlaceActiveObject::TranslateAccelerator`.

Идея:
- пока **не редактируем** — сообщения идут в `m_gridAO` (ActiveObject грида),
- пока **редактируем** — сообщения идут в `m_editAO` (ActiveObject редактора),
- но прежде выполняется ранняя обработка `TryHandleEditExitKeyInTranslateAccelerator(...)`
  (чтобы MSForms.ComboBox не «съел» Tab/стрелки до нашей логики выхода из редактирования).

---

## 4) Подробно про MAComboBoxEx

### 4.1 Назначение

`MAComboBoxEx` — не «самодельный комбобокс», а **контейнер** для `MSForms.ComboBox`.
Это сделано для того, чтобы:
- иметь управляемый `IDispatch` на внутренний объект (`Combo`),
- при необходимости перехватывать клавиши/контекстное меню,
- вести себя «по‑VB‑шному» там, где MSForms отличается от VB6 TextBox/ComboBox.

### 4.2 Что хранит класс (MAComboBoxEx.h)

- `m_ax` — `CAxWindow`, который хостит `MSForms.ComboBox`
- `m_cbDisp` — `IDispatch` внутреннего MSForms.ComboBox
- `m_hInner` — HWND глубинного окна ввода
- `m_oldProc` — предыдущая WndProc (внутреннее окно перехватывается через SetWindowLongPtr)
- `m_hMenu` — контекстное меню (создаётся/показывается самим контролом)

### 4.3 Основные функции (MAComboBoxEx.cpp)

- `OnCreate` — создаёт `MSForms.ComboBox`, находит inner HWND, подменяет WndProc
- `InnerWndProc` — перехват:
  - контекстного меню (правый клик),
  - клавиш копировать/вставить,
  - вставки CRLF (если реализовано через отдельную команду)
- `get_Text/put_Text` — проксируют свойство Text к внутреннему MSForms.ComboBox

---

## 5) Вспомогательные файлы

### DispatchHelpers.h
Набор маленьких функций:
- преобразование `VARIANT <-> std::wstring`
- упрощённый `IDispatch` invoke/get/put/getIndexed/putIndexed`
- чтение/запись текста в буфер обмена (`CF_UNICODETEXT`)

### AxHostHelpers.h
`CreateAxControlWithLicFallback(...)` — создание ActiveX по ProgID/CLSID
с попыткой лиценз‑fallback (IClassFactory2).

### MAControls.idl
Типы (`MACellEditorType`, `MANavExitKeys`) и интерфейсы:
- `IMAComboBoxEx`
- `IMAMSHFlexGridEx`
Плюс coclass‑регистрация в `library MAControlsLib`.

### MAControls.cpp, dllmain.cpp/h
Стандартный ATL каркас DLL:
- `DllRegisterServer/DllUnregisterServer`
- `DllGetClassObject/DllCanUnloadNow`
- `CMAControlsModule` и вход `DllMain`

### *.rgs / *.rc
- `.rgs` — скрипты регистрации ProgID/CLSID.
- `.rc` — ресурсы (иконки toolbox bitmap и т.п.).

---

## 6) Где смотреть «ключевые места» в коде

Если нужно быстро разобраться, начни с этих точек:

1) `CMAMSHFlexGridEx::OnCreate` → `CreateGrid` → `StartHookTimer`
2) `CMAMSHFlexGridEx::TranslateAccelerator` + `TryHandleEditExitKeyInTranslateAccelerator`
3) `CMAMSHFlexGridEx::BeginEdit` / `EndEdit`
4) `CMAMSHFlexGridEx::HookGridInnerIfPossible` / `HookEditInnerIfPossible`
5) `GridSubclassProc` / `EditSubclassProc` / `PopupEditSubclassProc`
6) `PostFocusGrid` → `FocusGridNow` (возврат стрелок/фокуса)

---

## 7) Диагностика фокуса

В `MAMSHFlexGridEx.cpp` есть диагностический блок под макросом:

- `#define MA_DIAG_FOCUS 0`

Если поставить `1`, включатся `OutputDebugStringW(...)`‑логи, которые показывают:
- какой HWND в фокусе,
- на каких окнах сейчас редактирование,
- что происходит при EndEdit/FocusGrid.

Это удобно, когда «стрелки перестали работать» из‑за того, что фокус остался на контейнере формы, а не на внутреннем окне грида.

---

## 8) Примечания по текущему состоянию исходников

1) `CreateGrid()` заполняет таблицу тестовыми значениями (Rows=6, Cols=4, заголовки в (0,*)).
2) Встроенное редактирование MSHFlexGrid выключено: `Editable = 0`.
3) Редактирование делается только через внешние редакторы (popup EDIT или MAComboBoxEx).

Если ты хочешь, я могу подготовить «шпаргалку» в виде одной страницы:
- какие COM‑методы вызывать из VB6,
- как настроить типы/списки/навигацию для диапазона ячеек,
- какие маски `MANavExitKeys` обычно используются.
