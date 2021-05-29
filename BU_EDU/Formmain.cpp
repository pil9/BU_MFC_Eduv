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
}

BEGIN_MESSAGE_MAP(Formmain, CFormView)
END_MESSAGE_MAP()


BOOL Formmain::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void Formmain::OnInitialUpdate()
{

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
