// FormEdu.cpp: 구현 파일
//

#include "pch.h"
#include "resource.h"
#include "FormEdu.h"

#pragma comment(lib, "winmm")
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
	DDX_Control(pDX, IDC_BUTTON1, m_btn_edu_start);
	DDX_Control(pDX, IDC_BUTTON2, m_btn_edu_next);
	DDX_Control(pDX, IDC_BUTTON3, m_btn_edu_listen);
}

BEGIN_MESSAGE_MAP(FormEdu, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &FormEdu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &FormEdu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &FormEdu::OnBnClickedButton2)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



BOOL FormEdu::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


//void FormEdu::OnInitialUpdate()
//{
////	CFormView::OnInitialUpdate();
//
//	
//}

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
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
	CClientDC dc(this);

	int a = 0;
	srand((int)time(NULL));
	a = rand() % 3;

	image4.Load(_T("./res/여우.jpg"));
	image4.BitBlt(dc.m_hDC, 190, 120, 200, 200, 200, 180, SRCCOPY);
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
		rq1 = L"Fox";
	}
	if (count == 2) {
		rq1 = L"Apple";
	}
	if (count == 3) {
		rq1 = L"Fish";
	}
	if (count == 4) {
		rq1 = L"I'm thirsty";
	}
	if (count == 5) {
		rq1 = L"He's excited";
	}
	if (count == 6) {
		rq1 = L"some toast for";
	}
	if (count == 7) {
		rq1 = L"is he copying";
	}

	GetDlgItemText(IDC_EDIT1, q1);

	if (q1 == rq1) {
		MessageBox(_T("Good! 잘했어요!"), _T("집중~!"));
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
			image5.BitBlt(dc.m_hDC, 190, 120, 200, 200, 200, 180, SRCCOPY);

			CButton* rr1 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			rr1->SetWindowTextW(_T("Apple"));
			rr1->SetCheck(false);
		}
		if (count == 3) {
			CButton* title = (CButton*)GetDlgItem(IDC_STATIC3);
			title->SetWindowTextW(_T("생선은 영어로 Fish !"));

			image6.Load(_T("./res/생선.jpg"));
			image6.BitBlt(dc.m_hDC, 190, 120, 200, 200, 0, 0, SRCCOPY);

			CButton* rr1 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			rr1->SetWindowTextW(_T("Fish"));
		}
		if (count == 4) {
			
			InvalidateRect(CRect(0, 0, 500, 600), TRUE);
			CButton* title = (CButton*)GetDlgItem(IDC_HTEXT);
			title->SetWindowTextW(_T("다음 우리말을 영어로 적어 봅시다."));
			CButton* word = (CButton*)GetDlgItem(IDC_STATIC_LONG);
			word->SetWindowTextW(_T("'나는 목이 마릅니다.'"));
			CButton* title2 = (CButton*)GetDlgItem(IDC_STATIC3);
			title2->SetWindowTextW(_T(""));
			CButton* title3 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			title3->SetWindowTextW(_T(""));
			CButton* title4 = (CButton*)GetDlgItem(IDC_STATIC_TITLE);
			title4->SetWindowTextW(_T("<중급 영어 문장 학습>"));
			GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);

		}if (count == 5) {
			InvalidateRect(CRect(0, 0, 500, 600), TRUE);
			CButton* title = (CButton*)GetDlgItem(IDC_HTEXT);
			title->SetWindowTextW(_T("다음 우리말을 영어로 적어 봅시다."));
			CButton* word = (CButton*)GetDlgItem(IDC_STATIC_LONG);
			word->SetWindowTextW(_T("'그는 신났습니다.'"));
			CButton* title2 = (CButton*)GetDlgItem(IDC_STATIC3);
			title2->SetWindowTextW(_T(""));
			CButton* title3 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			title3->SetWindowTextW(_T(""));
			CButton* title4 = (CButton*)GetDlgItem(IDC_STATIC_TITLE);
			title4->SetWindowTextW(_T("<중급 영어 문장 학습>"));
			GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
		}if (count == 6) {
			InvalidateRect(CRect(0, 0, 500, 600), TRUE);
			CButton* title = (CButton*)GetDlgItem(IDC_HTEXT);
			title->SetWindowTextW(_T("다음 빈칸에 알맞는 문장을 적어 봅시다."));
			CButton* word = (CButton*)GetDlgItem(IDC_STATIC_LONG);
			word->SetWindowTextW(_T("'나는 아침 식사로 약간의 토스트를 먹습니다.'"));
			CButton* title2 = (CButton*)GetDlgItem(IDC_STATIC3);
			title2->SetWindowTextW(_T(""));
			CButton* title3 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			title3->SetWindowTextW(_T(""));
			CButton* title4 = (CButton*)GetDlgItem(IDC_STATIC_TITLE);
			title4->SetWindowTextW(_T("<고급 영어 문장 학습>"));
			CButton* title5 = (CButton*)GetDlgItem(IDC_STATIC_HINT2);
			title5->SetWindowTextW(_T("I have"));
			CButton* title6 = (CButton*)GetDlgItem(IDC_STATIC_HINT);
			title6->SetWindowTextW(_T("breakfast"));
			GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
		}
		if (count == 7) {
			InvalidateRect(CRect(0, 0, 500, 600), TRUE);
			CButton* title = (CButton*)GetDlgItem(IDC_HTEXT);
			title->SetWindowTextW(_T("※다음 빈칸에 알맞는 문장을 적어 봅시다."));
			CButton* word = (CButton*)GetDlgItem(IDC_STATIC_LONG);
			word->SetWindowTextW(_T("'어디서 그는 보고서를 복사하고 있습니까?'"));
			CButton* title2 = (CButton*)GetDlgItem(IDC_STATIC3);
			title2->SetWindowTextW(_T(""));
			CButton* title3 = (CButton*)GetDlgItem(IDD_ABOUTBOX);
			title3->SetWindowTextW(_T(""));
			CButton* title4 = (CButton*)GetDlgItem(IDC_STATIC_TITLE);
			title4->SetWindowTextW(_T("<고급 영어 문장 학습>"));
			CButton* title5 = (CButton*)GetDlgItem(IDC_STATIC_HINT2);
			title5->SetWindowTextW(_T("Where"));
			CButton* title6 = (CButton*)GetDlgItem(IDC_STATIC_HINT);
			title6->SetWindowTextW(_T("the report?"));
		}
		if (count == 8) {
			MessageBox(_T("수고하셨습니다! 학습종료~!."), _T("학습끝~"));
			//Invalidate();
			//count = 0;
			//RedrawWindow();
		}
	}
	else {
		MessageBox(_T("단어를 알맞게 입력하세요."), _T("다시 학습하기~"));
	}


}


HBRUSH FormEdu::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	pDC->SetBkColor(RGB(246, 238, 225));
	return hbr;
}


void FormEdu::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_btn_edu_start.LoadBitmaps(IDB_MAIN_EDU_ON, IDB_MAIN_EDU, NULL, NULL);
	m_btn_edu_start.SizeToContent();
	m_btn_edu_listen.LoadBitmaps(IDB_MAIN_LISTEN_ON, IDB_MAIN_LISTEN, NULL, NULL);
	m_btn_edu_listen.SizeToContent();
	m_btn_edu_next.LoadBitmaps(IDB_MAIN_NEXT_ON, IDB_MAIN_NEXT, NULL, NULL);
	m_btn_edu_next.SizeToContent();

	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
