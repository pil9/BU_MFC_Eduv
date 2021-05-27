// FormChat.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormChat.h"


// FormChat

IMPLEMENT_DYNCREATE(FormChat, CFormView)

FormChat::FormChat()
	: CFormView(IDD_FORM_CHAT)
{

}

FormChat::~FormChat()
{
}

void FormChat::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}
BOOL FormChat::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
void FormChat::OnInitialUpdate()
{

}

BEGIN_MESSAGE_MAP(FormChat, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// FormChat 진단

#ifdef _DEBUG
void FormChat::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormChat::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormChat 메시지 처리기


HBRUSH FormChat::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	return hbr;
}
