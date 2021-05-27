// FormEdu.cpp: 구현 파일
//

#include "pch.h"
#include "resource.h"
#include "FormEdu.h"

#pragma comment(lib, "winmm");
#include <mmsystem.h>


// FormEdu

IMPLEMENT_DYNCREATE(FormEdu, CFormView)

FormEdu::FormEdu()
	: CFormView(IDD_FORM_EDU)
{

}

FormEdu::~FormEdu()
{
}

void FormEdu::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, result);
}

BEGIN_MESSAGE_MAP(FormEdu, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &FormEdu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &FormEdu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &FormEdu::OnBnClickedButton2)
END_MESSAGE_MAP()



BOOL FormEdu::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormEdu::OnInitialUpdate()
{

}

// FormEdu 진단

#ifdef _DEBUG
void FormEdu::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormEdu::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormEdu 메시지 처리기


void FormEdu::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);

	int a = 0;
	srand((int)time(NULL));
	a = rand() % 3;

	image4.Load(_T("./res/여우.jpg"));
	image4.BitBlt(dc.m_hDC, 255, 140, 200, 200, 200, 180, SRCCOPY);
	CButton* rr1 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
	rr1->SetWindowTextW(_T("Fox"));
	rr1->SetCheck(false);
	count++; //1

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);

}


void FormEdu::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString sound1;
	if (count == 1) {
		sound1 = (_T("./res/여우음성.wav"));
	}
	if (count == 2) {
		sound1 = (_T("./res/사과음성.wav"));
	}
	if (count == 3) {
		sound1 = (_T("./res/생선음성.wav"));
	}
	PlaySound(sound1, AfxGetInstanceHandle(), SND_ASYNC);

}


void FormEdu::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString q1;
	CString rq1;
	if (count == 1 || count == 0 ) {
		rq1 = L"fox";
	}
	if (count == 2) {
		rq1 = L"Apple";;
	}
	if (count == 3) {
		rq1 = L"fish";
	}

	GetDlgItemText(IDC_EDIT1, q1);

	if (q1 == rq1) {
		CClientDC dc(this);
		result.Empty();
		UpdateData(false);
		count++;//2
		//Invalidate();
		if (count == 2) {
			CButton* title = (CButton*)GetDlgItem(IDC_STATIC3);
			title->SetWindowTextW(_T("사과는 영어로 Apple !"));
			title->SetCheck(false);

			image5.Load(_T("./res/사과.jpg"));
			image5.BitBlt(dc.m_hDC, 255, 140, 200, 200, 200, 180, SRCCOPY);

			CButton* rr1 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			rr1->SetWindowTextW(_T("Apple"));
			rr1->SetCheck(false);
		}
		if (count == 3) {
			CButton* title = (CButton*)GetDlgItem(IDC_STATIC3);
			title->SetWindowTextW(_T("생선은 영어로 Fish !"));
			title->SetCheck(false);

			image6.Load(_T("./res/생선.jpg"));
			image6.BitBlt(dc.m_hDC, 255, 140, 200, 200, 0, 0, SRCCOPY);

			CButton* rr1 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			rr1->SetWindowTextW(_T("Fish"));
			rr1->SetCheck(false);
		}
	}
	else {
		MessageBox(_T("단어를 알맞게 입력하세요."), _T("다시 학습하기~"));
	}


}
