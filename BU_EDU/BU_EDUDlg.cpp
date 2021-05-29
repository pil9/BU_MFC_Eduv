
// BU_EDUDlg.cpp : implementation file
//
#pragma comment(lib, "winmm.lib")
#include "pch.h"
#include "framework.h"
#include "BU_EDU.h"
#include "BU_EDUDlg.h"

#include "afxdialogex.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CBUEDUDlg dialog



CBUEDUDlg::CBUEDUDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BU_EDU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	


}

void CBUEDUDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, main_btn1);
	DDX_Control(pDX, IDC_BUTTON2, sub_btn1);
	DDX_Control(pDX, IDC_BUTTON3, sub_btn2);
	DDX_Control(pDX, IDC_BUTTON4, sub_btn3);

	DDX_Control(pDX, IDC_BUTTON5, main_btn2);
	DDX_Control(pDX, IDC_BUTTON6, sub_btn4);
	DDX_Control(pDX, IDC_BUTTON8, sub_btn5);
	DDX_Control(pDX, IDC_BUTTON9, sub_btn6);
	DDX_Control(pDX, IDC_BUTTON10, sub_btn7);
	DDX_Control(pDX, IDC_BUTTON7, onokbtn);
}

BEGIN_MESSAGE_MAP(CBUEDUDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBUEDUDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBUEDUDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBUEDUDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBUEDUDlg::OnBnClickedButton4)
	ON_STN_CLICKED(IDC_STATIC_RECT, &CBUEDUDlg::OnStnClickedStaticRect)
	ON_BN_CLICKED(IDC_BUTTON7, &CBUEDUDlg::OnBnClickedButton7)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON9, &CBUEDUDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CBUEDUDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CBUEDUDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &CBUEDUDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CBUEDUDlg message handlers

BOOL CBUEDUDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BG));
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	AllocForms();
	//FormAudio::OnPaint();
	main_btn1.LoadBitmaps(IDB_MAIN_BTN1, NULL, NULL, NULL);
	main_btn1.SizeToContent();
	main_btn2.LoadBitmaps(IDB_MAIN_BTN2, NULL, NULL, NULL);
	main_btn2.SizeToContent();
	sub_btn1.LoadBitmaps(IDB_SUB_BTN1, IDB_SUB_BTN1_ON, NULL, NULL);
	sub_btn1.SizeToContent();
	sub_btn2.LoadBitmaps(IDB_SUB_BTN2, IDB_SUB_BTN2_ON, NULL, NULL);
	sub_btn2.SizeToContent();
	sub_btn3.LoadBitmaps(IDB_SUB_BTN3, IDB_SUB_BTN3_ON, NULL, NULL);
	sub_btn3.SizeToContent();
	sub_btn4.LoadBitmaps(IDB_SUB_BTN4, IDB_SUB_BTN4_ON, NULL, NULL);
	sub_btn4.SizeToContent();
	sub_btn5.LoadBitmaps(IDB_SUB_BTN5, IDB_SUB_BTN5_ON, NULL, NULL);
	sub_btn5.SizeToContent();
	sub_btn6.LoadBitmaps(IDB_SUB_BTN6, IDB_SUB_BTN6_ON, NULL, NULL);
	sub_btn6.SizeToContent();
	sub_btn7.LoadBitmaps(IDB_SUB_BTN7, IDB_SUB_BTN7_ON, NULL, NULL);
	sub_btn7.SizeToContent();
	
	

	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBUEDUDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
		
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBUEDUDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetWindowRect(&rect); // 스크린과 호환되는 DC생성.
	HDC hMemDC = CreateCompatibleDC(dc);
	SetStretchBltMode(hMemDC, HALFTONE); // 호환DC에 비트맵을 선정.
	SelectObject(hMemDC, m_hBitmap); // 메모리 DC에서 스크린 DC로 이미지 복사
	StretchBlt(dc, 0, 0, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY); // 메모리 DC삭제
	DeleteDC(hMemDC);


	CStatic* bitmaptemp = (CStatic*)GetDlgItem(IDC_STATIC_LOGO);
	CBitmap image;
	image.LoadBitmap(IDB_MAIN_LOGO);
	bitmaptemp->SetBitmap(image);
	
	CButton* onOkbtn = (CButton*)GetDlgItem(IDC_BUTTON7);
	onOkbtn->ShowWindow(SW_SHOW);
	onOkbtn->RedrawWindow();

}

void CBUEDUDlg::AllocForms()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC_RECT)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	p_audio = new FormAudio();
	p_audio->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_AUDIO, &context);
	p_audio->OnInitialUpdate();
	p_audio->ShowWindow(SW_SHOW);

	/*CButton* onOkbtn = (CButton*)GetDlgItem(IDC_BUTTON7);
	::SetWindowPos(onOkbtn->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);*/


	p_test = new Formtest();
	p_test->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_DIALOG2, &context);
	p_test->OnInitialUpdate();
	p_test->ShowWindow(SW_HIDE);


	p_Level = new FormLevel();
	p_Level->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_LEVEL, &context);
	p_Level->OnInitialUpdate();
	p_Level->ShowWindow(SW_HIDE);

	p_Edu = new FormEdu();
	p_Edu->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_LEVEL, &context);
	p_Edu->OnInitialUpdate();
	p_Edu->ShowWindow(SW_HIDE);

	p_Chat = new FormChat();
	p_Chat->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_CHAT, &context);
	p_Chat->OnInitialUpdate();
	p_Chat->ShowWindow(SW_HIDE);

	p_Register = new FormRegister();
	p_Register->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_REG, &context);
	p_Register->OnInitialUpdate();
	p_Register->ShowWindow(SW_HIDE);

	p_Login = new FormLogin();
	p_Login->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_LOGIN, &context);
	p_Login->OnInitialUpdate();
	p_Login->ShowWindow(SW_HIDE);
	
	/*
	m_pForm3 = new CMyForm3();
	m_pForm3->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM3, &context);
	m_pForm3->OnInitialUpdate();
	m_pForm3->ShowWindow(SW_HIDE);*/

	//GetDlgItem(IDC_STATIC_RECT)->DestroyWindow();
}

void CBUEDUDlg::ShowForm(int idx)
{
	CButton* onOkbtn = (CButton*)GetDlgItem(IDC_BUTTON7);
	switch (idx)
	{
	case 0:
		p_audio->ShowWindow(SW_SHOW);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_HIDE);
		Invalidate();
		onOkbtn->ShowWindow(SW_SHOW);
		onOkbtn->RedrawWindow();
		
		break;
	case 1:
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_SHOW);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_HIDE);
		
		break;
		
	case 2://레벨테스트 페이지로 이동으로 사용하겠슴
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_SHOW);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_HIDE);
		onOkbtn->ShowWindow(SW_SHOW);
		onOkbtn->RedrawWindow();
		break;

	case 3://레벨테스트 페이지로 이동으로 사용하겠슴
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_SHOW);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_HIDE);
		break;

	case 4:
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_SHOW);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_HIDE);
		break;

	case 5: //login
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_SHOW);
		p_Register->ShowWindow(SW_HIDE);
		break;

	case 6: // register
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_HIDE);
		p_Edu->ShowWindow(SW_HIDE);
		p_Chat->ShowWindow(SW_HIDE);
		p_Login->ShowWindow(SW_HIDE);
		p_Register->ShowWindow(SW_SHOW);
		break;
	}

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBUEDUDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBUEDUDlg::OnBnClickedButton1()
{
	
	
	/*::SetWindowPos(onOkbtn->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);*/

	// TODO: Add your control notification handler code here
}


void CBUEDUDlg::OnBnClickedButton2()
{
	ShowForm(5);
	/*
	CButton* onOkbtn = (CButton*)GetDlgItem(IDC_BUTTON7);
	::SetWindowPos(onOkbtn->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);*/
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton3()
{
	ShowForm(6);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnStnClickedStaticRect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton7()
{
	OnOK();
}


int CBUEDUDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	return 0;
}


void CBUEDUDlg::OnBnClickedButton9()
{
	ShowForm(4);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	return hbr;
}


void CBUEDUDlg::OnBnClickedButton6()
{
	ShowForm(2);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton8()
{
	ShowForm(3);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton10()
{
	ShowForm(0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
