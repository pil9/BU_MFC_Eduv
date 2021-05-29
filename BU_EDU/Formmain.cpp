// Formmain.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "Formmain.h"


// Formmain

IMPLEMENT_DYNCREATE(Formmain, CFormView)

Formmain::Formmain()
	: CFormView(IDD_FORM_MAIN)
{

}

Formmain::~Formmain()
{
}

void Formmain::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_main_text);
}

BEGIN_MESSAGE_MAP(Formmain, CFormView)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL Formmain::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void Formmain::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	
	
	m_main_text.LoadBitmaps(IDB_MAIN_TEXT, NULL, NULL, NULL);
	m_main_text.SizeToContent();


}


// Formmain 진단

#ifdef _DEBUG
void Formmain::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Formmain::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Formmain 메시지 처리기


HBRUSH Formmain::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	pDC->SetBkColor(RGB(246, 238, 225));
	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void Formmain::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CFormView::OnPaint()을(를) 호출하지 마십시오.
	CStatic* bitmaptemp = (CStatic*)GetDlgItem(IDC_MAIN_LOGO);
	CBitmap image;
	image.LoadBitmap(IDB_TEXT_LOGO);
	bitmaptemp->SetBitmap(image);
}
