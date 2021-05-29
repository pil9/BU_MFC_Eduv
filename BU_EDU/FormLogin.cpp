// FormLogin.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormLogin.h"
#include "BU_EDUDlg.h"
#include "FormRegister.h"

// FormLogin

IMPLEMENT_DYNCREATE(FormLogin, CFormView)

FormLogin::FormLogin()
	: CFormView(IDD_FORM_LOGIN)
	, m_Username(_T(""))
	, m_Password(_T(""))
{
	
}

FormLogin::~FormLogin()
{
}

void FormLogin::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_LOGIN, m_Username);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	DDX_Control(pDX, IDC_BTN_LOGIN, m_btn_login);
	DDX_Control(pDX, IDC_BTN_REG, m_btn_reg);
}

BEGIN_MESSAGE_MAP(FormLogin, CFormView)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_REG, &FormLogin::OnBnClickedBtnReg)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &FormLogin::OnBnClickedBtnLogin)
	ON_EN_CHANGE(IDC_EDIT1, &FormLogin::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// FormLogin 진단

#ifdef _DEBUG
void FormLogin::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormLogin::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormLogin 메시지 처리기

BOOL FormLogin::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
//void FormLogin::OnInitialUpdate()
//{
//	
//	//GetDlgItem(IDC_STATIC)->SetFont(&g_editFont);
//
//	
//	/*DWORD Test = GetLastError();
//	m_login.SizeToContent();*/
//
//}
HBRUSH FormLogin::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	//if (pWnd->GetDlgCtrlID() == IDC_LOGIN)
	//{
	//	pDC->SetBkColor(RGB(246, 238, 225));
	//	//hbr = ::CreateSolidBrush(RGB(255, 0, 0));
	//}
	//if (nCtlColor == CTLCOLOR_STATIC)
	//{
	//	pDC->SetBkColor(RGB(246, 238, 225));
	//}
	pDC->SetBkColor(RGB(246, 238, 225));
	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}



void FormLogin::OnBnClickedBtnReg()
{
	((CBUEDUDlg *)GetParent())->ShowForm(6);
	FormRegister *Test = new FormRegister;
	//CString tname = Test->test_name;
	CString tname = test_name;
	MessageBox(tname);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormLogin::OnBnClickedBtnLogin()
{
	UpdateData(true);

	MYSQL mysqlCon;
	if (m_Username.IsEmpty() || m_Password.IsEmpty())
	{
		MessageBox(_T("Username and password cannot be empty!"));
		return;
	}
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "qq1024", "YongoLearn", 3306, NULL, 0))
	{
		MessageBox(_T("Database connection failed!"));
		return;
	}
	else
	{
		//UpdateData(true);
		mysql_query(&mysqlCon, "set names 'utf-8'");
		CString select = _T("select Uname,Password from learnerInfo");
		/*select.Format(_T("select Uname,Password from learnerInfo"));*/
		const wchar_t* selectData = (CStringW)select;
		USES_CONVERSION;
		mysql_real_query(&mysqlCon, W2A(selectData), (unsigned long)strlen(W2A(selectData)));

		int i = 0;
		MYSQL_ROW row;
		MYSQL_RES* result;
		result = mysql_store_result(&mysqlCon);
		//Select the user and password in the database to determine whether it is the same as the user password in the edit box
		while ((row = mysql_fetch_row(result)))
		{
			char* Name = row[0];
			char* Passwd = row[1];
			if ((m_Username == Name) && (m_Password == Passwd))
			{
				MessageBox(_T("Test"));
				//loginUserName = Name;
				/*CWelcomeDlg goToMenu;
				goToMenu.DoModal();*/
			}
		}
	}
	mysql_close(&mysqlCon);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormLogin::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormLogin::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CFormView::OnPaint()을(를) 호출하지 마십시오.
	
}


void FormLogin::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CFont g_editFont;

	g_editFont.CreatePointFont(200, TEXT("빙그레 싸만코체"));

	GetDlgItem(IDC_LOGIN)->SetFont(&g_editFont);
	GetDlgItem(IDC_PASSWORD)->SetFont(&g_editFont);
	m_btn_login.LoadBitmaps(IDB_MAIN_LOGIN_ON, IDB_MAIN_LOGIN, NULL, NULL);
	m_btn_login.SizeToContent();
	m_btn_reg.LoadBitmaps(IDB_MAIN_REG_ON, IDB_MAIN_REG, NULL, NULL);
	m_btn_reg.SizeToContent();
	/*m_bitmap_login.LoadBitmap(IDB_MAIN_LOGIN_ON);
	m_btn_login.SetBitmap(m_bitmap_login);*/
	
	/*CButton *pButton = (CButton*)GetDlgItem(IDC_BTN_LOGIN);

	pButton->SendMessage(WM_LBUTTONDOWN, 0, 0);
	pButton->SendMessage(WM_LBUTTONUP, 0, 0);*/

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
