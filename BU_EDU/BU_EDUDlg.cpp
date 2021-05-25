
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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
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
}

BEGIN_MESSAGE_MAP(CBUEDUDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBUEDUDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBUEDUDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBUEDUDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CBUEDUDlg message handlers

BOOL CBUEDUDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
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
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
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


	p_test = new Formtest();
	p_test->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_DIALOG2, &context);
	p_test->OnInitialUpdate();
	p_test->ShowWindow(SW_HIDE);


	p_Level = new FormLevel();
	p_Level->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_LEVEL, &context);
	p_Level->OnInitialUpdate();
	p_Level->ShowWindow(SW_HIDE);

	/*
	m_pForm3 = new CMyForm3();
	m_pForm3->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM3, &context);
	m_pForm3->OnInitialUpdate();
	m_pForm3->ShowWindow(SW_HIDE);*/

	//GetDlgItem(IDC_STATIC_RECT)->DestroyWindow();
}

void CBUEDUDlg::ShowForm(int idx)
{
	switch (idx)
	{
	case 0:
		p_audio->ShowWindow(SW_SHOW);
		p_test->ShowWindow(SW_HIDE);

		break;
	case 1:
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_SHOW);
		break;
		
	case 2://레벨테스트 페이지로 이동으로 사용하겠슴
		p_audio->ShowWindow(SW_HIDE);
		p_test->ShowWindow(SW_HIDE);
		p_Level->ShowWindow(SW_SHOW);
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
	ShowForm(0);


	// TODO: Add your control notification handler code here
}


void CBUEDUDlg::OnBnClickedButton2()
{
	ShowForm(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBUEDUDlg::OnBnClickedButton3()
{
	ShowForm(2);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
