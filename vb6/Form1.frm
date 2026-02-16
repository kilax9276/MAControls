VERSION 5.00
Object = "{7D464986-8807-4A52-859C-5D7C4A9F3242}#1.0#0"; "MAControls.dll"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6990
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   15510
   LinkTopic       =   "Form1"
   ScaleHeight     =   6990
   ScaleWidth      =   15510
   StartUpPosition =   3  'Windows Default
   Begin MAControlsLibCtl.MAMSHFlexGridEx MAMSHFlexGridEx1 
      Height          =   4455
      Left            =   1080
      OleObjectBlob   =   "Form1.frx":0000
      TabIndex        =   0
      Top             =   360
      Width           =   11415
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub SetupEditor()
    MAMSHFlexGridEx1.TextEditWidthPx = 360
    MAMSHFlexGridEx1.TextEditVisibleLines = 6
    MAMSHFlexGridEx1.TextEditMultiline = True
End Sub


Private Sub DemoMultiline()
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.WordWrap = True               ' если свойство поддерживается контролом
    g.TextMatrix(1, 3) = "Строка 1" & vbCrLf & "Строка 2" & vbCrLf & "Строка 3"
    g.RowHeight(1) = 1200           ' twips (подбери под себя)
End Sub


Private Sub StyleHeader()
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.FillStyle = flexFillRepeat ' :contentReference[oaicite:11]{index=11}

    g.Row = 0: g.RowSel = 0
    g.Col = 0: g.ColSel = g.Cols - 1

    g.CellBackColor = RGB(200, 200, 200)
    g.CellFontBold = True
    g.CellAlignment = flexAlignCenterCenter ' :contentReference[oaicite:12]{index=12}

    g.FillStyle = flexFillSingle
End Sub



Private Sub StyleRow(ByVal r As Long)
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.FillStyle = flexFillRepeat ' :contentReference[oaicite:9]{index=9}

    g.Row = r: g.RowSel = r
    g.Col = 0: g.ColSel = g.Cols - 1

    g.CellBackColor = RGB(255, 235, 235)
    g.CellForeColor = vbMaroon
    g.CellFontBold = True
    g.CellAlignment = flexAlignCenterCenter ' :contentReference[oaicite:10]{index=10}

    g.FillStyle = flexFillSingle
End Sub


Private Sub StyleColumn(ByVal c As Long)
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.FillStyle = flexFillRepeat ' :contentReference[oaicite:8]{index=8}

    g.Row = 0: g.RowSel = g.Rows - 1
    g.Col = c: g.ColSel = c

    g.CellBackColor = RGB(220, 245, 255)
    g.CellFontBold = True

    g.FillStyle = flexFillSingle
End Sub


'flexAlignLeftTop = 0
'flexAlignLeftCenter = 1
'flexAlignLeftBottom = 2
'flexAlignCenterTop = 3
'flexAlignCenterCenter = 4
'flexAlignCenterBottom = 5
'flexAlignRightTop = 6
'flexAlignRightCenter = 7
'flexAlignRightBottom = 8
'flexAlignGeneral = 9    ' “умное”: строки слева, числа справа


Private Sub AlignColumn(ByVal c As Long)
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.ColAlignment(c) = flexAlignRightCenter ' 7 :contentReference[oaicite:7]{index=7}
End Sub


Private Sub StyleRange(ByVal r1 As Long, ByVal c1 As Long, ByVal r2 As Long, ByVal c2 As Long)
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.FillStyle = flexFillRepeat ' применяем ко всем выделенным :contentReference[oaicite:4]{index=4}

    g.Row = r1: g.Col = c1
    g.RowSel = r2: g.ColSel = c2

    g.CellBackColor = RGB(240, 240, 240)
    g.CellForeColor = vbBlack

    g.CellFontName = "Consolas"
    g.CellFontSize = 10
    g.CellFontBold = False

    g.CellAlignment = flexAlignLeftCenter ' 1 :contentReference[oaicite:5]{index=5}

    g.FillStyle = flexFillSingle ' вернуть дефолт
End Sub


Private Sub StyleOneCell(ByVal r As Long, ByVal c As Long)
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.FillStyle = flexFillSingle ' только текущая ячейка :contentReference[oaicite:1]{index=1}

    g.Row = r
    g.Col = c

    g.CellBackColor = RGB(255, 255, 200)  ' фон
    g.CellForeColor = vbBlue              ' текст

    g.CellFontName = "Tahoma"
    g.CellFontSize = 9
    g.CellFontBold = True                 ' :contentReference[oaicite:2]{index=2}
    g.CellFontItalic = False
    g.CellFontUnderline = False

    g.CellAlignment = flexAlignCenterCenter ' 4 :contentReference[oaicite:3]{index=3}
End Sub


Private Sub Form_Load()

    Const maCellText = 0
    Const maCellCombo = 1
    Const maCellList = 2
    Const maCellReadOnly = 3

    ' Колонка 2: Combo (список + свободный ввод)
    MAMSHFlexGridEx1.SetColumnType 2, maCellCombo
    MAMSHFlexGridEx1.SetColumnItems 2, Array("one", "two", "three")

    ' Ячейка (3,1): только список
    MAMSHFlexGridEx1.SetCellType 3, 1, maCellList
    MAMSHFlexGridEx1.SetCellItems 3, 1, Array("A", "B", "C")

    ' Ячейка (4,1): ReadOnly
    MAMSHFlexGridEx1.SetCellType 4, 1, maCellReadOnly

    ' Доступ к реальному MSHFlexGrid
    Dim g As Object
    Set g = MAMSHFlexGridEx1.Grid

    g.Rows = 40
    g.Cols = 40

    ' ---- Ширина столбцов (в пикселях) ----
    g.ColWidth(0) = 40 * Screen.TwipsPerPixelX   ' 40px
    g.ColWidth(1) = 120 * Screen.TwipsPerPixelX  ' 120px
    g.ColWidth(2) = 160 * Screen.TwipsPerPixelX  ' 160px (там ComboBox)
    g.ColWidth(3) = 200 * Screen.TwipsPerPixelX  ' 200px

    ' ---- Высота строк (в пикселях) ----
    g.RowHeight(0) = 24 * Screen.TwipsPerPixelY  ' строка 0 (часто заголовок/фиксированная)
    g.RowHeight(1) = 20 * Screen.TwipsPerPixelY
    g.RowHeight(2) = 20 * Screen.TwipsPerPixelY
    g.RowHeight(3) = 28 * Screen.TwipsPerPixelY  ' повыше, например под большую строку
    
    g.TopRow = 3     ' первая отображаемая строка (после fixed)
    g.LeftCol = 3    ' первый отображаемый столбец (после fixed)
    
    StyleHeader
    
    StyleRow 2
    StyleRow 4
    StyleColumn 2
    StyleColumn 4
    
    'StyleRange 1, 2, 4, 3
    
    
    Const flexResizeNone = 0
    Const flexResizeColumns = 1
    Const flexResizeRows = 2
    Const flexResizeBoth = 3
    
    ' включить изменение ширины столбцов и высоты строк мышью
    MAMSHFlexGridEx1.AllowUserResizing = flexResizeBoth
    
    ' только столбцы
    'MAMSHFlexGridEx1.AllowUserResizing = flexResizeColumns
    
    ' только строки
    'MAMSHFlexGridEx1.AllowUserResizing = flexResizeRows
    
    ' выключить полностью
    'MAMSHFlexGridEx1.AllowUserResizing = flexResizeNone

    ' Заголовки колонок (пишутся в Row=0)
    MAMSHFlexGridEx1.SetColumnHeaderText 1, "Имя"
    MAMSHFlexGridEx1.SetColumnHeaderText 2, "Статус"
    MAMSHFlexGridEx1.SetColumnHeaderText 3, "Описание"

    ' Заголовки строк (пишутся в Col=0)
    MAMSHFlexGridEx1.SetRowHeaderText 1, "R1"
    MAMSHFlexGridEx1.SetRowHeaderText 2, "R2"

    ' Угол (0,0)
    MAMSHFlexGridEx1.SetCornerHeaderText "#"
    
    DemoMultiline
    
    SetupEditor

End Sub

