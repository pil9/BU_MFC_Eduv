// Formtest.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "Formtest.h"


// Formtest

IMPLEMENT_DYNCREATE(Formtest, CFormView)

Formtest::Formtest()
	: CFormView(IDD_DIALOG2)
{

}

Formtest::~Formtest()
{
}

void Formtest::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Formtest, CFormView)
END_MESSAGE_MAP()

BOOL Formtest::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void Formtest::OnInitialUpdate()
{

}
// Formtest 진단

#ifdef _DEBUG
void Formtest::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Formtest::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Formtest 메시지 처리기
