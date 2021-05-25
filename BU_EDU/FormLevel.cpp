// FormLevel.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormLevel.h"


// FormLevel

IMPLEMENT_DYNCREATE(FormLevel, CFormView)

FormLevel::FormLevel()
	: CFormView(IDD_FORM_LEVEL)
{

}

FormLevel::~FormLevel()
{
}

void FormLevel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormLevel, CFormView)
END_MESSAGE_MAP()

BOOL FormLevel::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormLevel::OnInitialUpdate()
{

}
// FormLevel 진단

#ifdef _DEBUG
void FormLevel::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormLevel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormLevel 메시지 처리기
