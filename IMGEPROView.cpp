
// IMGEPROView.cpp : CIMGEPROView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "IMGEPRO.h"
#endif

#include "IMGEPRODoc.h"
#include "IMGEPROView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMGEPROView

IMPLEMENT_DYNCREATE(CIMGEPROView, CView)

BEGIN_MESSAGE_MAP(CIMGEPROView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMGEPROView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CIMGEPROView 构造/析构

CIMGEPROView::CIMGEPROView()
{
	// TODO:  在此处添加构造代码

}

CIMGEPROView::~CIMGEPROView()
{
}

BOOL CIMGEPROView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CIMGEPROView 绘制

void CIMGEPROView::OnDraw(CDC* /*pDC*/)
{
	CIMGEPRODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CIMGEPROView 打印


void CIMGEPROView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMGEPROView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CIMGEPROView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CIMGEPROView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CIMGEPROView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMGEPROView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMGEPROView 诊断

#ifdef _DEBUG
void CIMGEPROView::AssertValid() const
{
	CView::AssertValid();
}

void CIMGEPROView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMGEPRODoc* CIMGEPROView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMGEPRODoc)));
	return (CIMGEPRODoc*)m_pDocument;
}
#endif //_DEBUG


// CIMGEPROView 消息处理程序
