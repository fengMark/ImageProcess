
// IMGEPROView.cpp : CIMGEPROView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMGEPROView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CIMGEPROView ����/����

CIMGEPROView::CIMGEPROView()
{
	// TODO:  �ڴ˴���ӹ������

}

CIMGEPROView::~CIMGEPROView()
{
}

BOOL CIMGEPROView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CIMGEPROView ����

void CIMGEPROView::OnDraw(CDC* /*pDC*/)
{
	CIMGEPRODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CIMGEPROView ��ӡ


void CIMGEPROView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMGEPROView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CIMGEPROView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CIMGEPROView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CIMGEPROView ���

#ifdef _DEBUG
void CIMGEPROView::AssertValid() const
{
	CView::AssertValid();
}

void CIMGEPROView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMGEPRODoc* CIMGEPROView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMGEPRODoc)));
	return (CIMGEPRODoc*)m_pDocument;
}
#endif //_DEBUG


// CIMGEPROView ��Ϣ�������
