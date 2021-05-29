// FormMypage.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormMypage.h"


// FormMypage

IMPLEMENT_DYNCREATE(FormMypage, CFormView)

FormMypage::FormMypage()
	: CFormView(IDD_FORM_MYPAGE)
{

}

FormMypage::~FormMypage()
{
}

void FormMypage::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormMypage, CFormView)
	ON_WM_CTLCOLOR()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// FormMypage 진단

#ifdef _DEBUG
void FormMypage::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormMypage::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormMypage 메시지 처리기


HBRUSH FormMypage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	pDC->SetBkColor(RGB(246, 238, 225));

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


int FormMypage::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


BOOL FormMypage::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void FormMypage::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
