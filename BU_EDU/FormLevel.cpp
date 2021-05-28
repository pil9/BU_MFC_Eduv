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
	ON_BN_CLICKED(IDC_BUTTON1, &FormLevel::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &FormLevel::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
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


void FormLevel::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int wran;
	srand((int)time(NULL));
	wran = rand() % 2;
	CClientDC dc(this);

	if (wran == 0) {
		image1.Load(_T("./res/불.jpg"));
		image2.Load(_T("./res/토마토.jpg"));
		image3.Load(_T("./res/조심해.jpg"));
		image1.BitBlt(dc.m_hDC, 40, 150, 150, 150, 0, 0, SRCCOPY);
		image2.BitBlt(dc.m_hDC, 280, 150, 150, 150, 0, 0, SRCCOPY);
		image3.BitBlt(dc.m_hDC, 520, 150, 150, 150, 100, 90, SRCCOPY);
	}
	else if (wran == 1) {
		image1.Load(_T("./res/구름.jpg"));
		image2.Load(_T("./res/바나나.jpg"));
		image3.Load(_T("./res/배고픔.jpg"));
		image1.BitBlt(dc.m_hDC, 40, 150, 150, 150, 200, 200, SRCCOPY);
		image2.BitBlt(dc.m_hDC, 280, 150, 150, 150, 0, 0, SRCCOPY);
		image3.BitBlt(dc.m_hDC, 520, 150, 150, 150, 0, 0, SRCCOPY);
	}

	//SetDlgItemText(IDC_RADIO1, _T("현재 점수 0 점"));
	SetTimer(1, 1000, NULL);
	b_state = 1;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);

	//CPaintDC dc(this);
	COLORREF c = RGB(255, 0, 0); dc.SetTextColor(c);
	CString str; str.Format(_T("남은시간 : %d 초"), Timer);
	dc.TextOutW(295, 30, str);

}


void FormLevel::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int testsum = 0;
	CString q1;
	if (wran == 0) {
		rq1 = L"fire";
	}
	else if (wran == 1) {
		rq1 = L"cloud";
	}

	GetDlgItemText(IDC_result1, q1);
	if (q1 == rq1) {
		testsum++;
	}
	CButton* qf2 = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton* qf1 = (CButton*)GetDlgItem(IDC_RADIO1);
	if (wran == 0) {
		if (qf2->GetCheck()) {//정답 토마토
			testsum++;
		}
	}
	else if (wran == 1) {
		if (qf1->GetCheck()) {//정답 바나나
			testsum++;
		}
	}
	CButton* c2 = (CButton*)GetDlgItem(IDC_RADIO4);
	if (c2->GetCheck()) {
		testsum++;
	}

	if (testsum == 0) {
		MessageBox(_T("이럴수가 0점 입니다... Level 1입니다."), _T("노력합시다 ㅠ"));
	}
	else if (testsum == 1) {
		MessageBox(_T("33점 입니다. 조금만 더! Level 2입니다."), _T("노력합시다 ㅠ"));
	}
	else if (testsum == 2) {
		MessageBox(_T("66점 입니다. 와우! Level 3입니다."), _T("Good~!"));
	}
	else if (testsum == 3) {
		MessageBox(_T("100점 입니다. 대단해요! Level 4입니다."), _T("Great~!"));
	}

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);

	b_state = 0;
	KillTimer(1);

}


void FormLevel::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (b_state == 1 && Timer > 0) {
		//Invalidate();
		UpdateData(false);
		InvalidateRect(CRect(295, 30, 750, 100), TRUE);
		Timer--;
		CPaintDC dc(this);
		COLORREF c = RGB(255, 0, 0); dc.SetTextColor(c);
		CString str; str.Format(_T("남은시간 : %d 초"), Timer);
		dc.TextOutW(295, 30, str);

		if (Timer < 1) {
			FormLevel::OnBnClickedButton2();
		}

	}
	//CDialog::OnTimer(nIDEvent);

	CFormView::OnTimer(nIDEvent);
}


HBRUSH FormLevel::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	return hbr;
}
