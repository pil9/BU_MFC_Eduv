// FormRegister.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormRegister.h"

CString test_name;
// FormRegister

IMPLEMENT_DYNCREATE(FormRegister, CFormView)

FormRegister::FormRegister()
	: CFormView(IDD_FORM_REG)
	, mRadio(FALSE)
{
	
}

FormRegister::~FormRegister()
{
}

void FormRegister::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, u_uname);
	DDX_Text(pDX, IDC_EDIT2, u_password);
	DDX_Text(pDX, IDC_EDIT3, u_confirm);
	DDX_Text(pDX, IDC_EDIT4, u_fname);
	//DDX_Text(pDX, IDC_EDIT5, u_gender);
	DDX_Text(pDX, IDC_EDIT6, u_bday);
	DDX_Text(pDX, IDC_EDIT7, u_address);
	DDX_Text(pDX, IDC_EDIT8, u_email);
	//DDX_Text(pDX, IDC_EDIT9, u);
	DDX_Radio(pDX, IDC_RADIO1, mRadio);
}
BOOL FormRegister::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormRegister::OnInitialUpdate()
{
	
	/*CFont *currentFont = this->GetFont();
	LOGFONT logFont;
	currentFont->GetLogFont(&logFont);
	logFont.lfHeight = 15;
	logFont.lfWeight = FW_BOLD;

	this->newFont.CreateFontIndirectW(&logFont);
	this->GetDlgItem()*/

	CFont g_editFont;

	g_editFont.CreatePointFont(200, TEXT("빙그레 싸만코체"));

	int idc = 1014;
	for (int i = 1; i < 5; i++) {
		
		GetDlgItem(idc++)->SetFont(&g_editFont);
	}
	for (int i = 1; i < 5; i++) {

		GetDlgItem(++idc)->SetFont(&g_editFont);
	}
	/*GetDlgItem(IDC_LOGIN)->SetFont(&g_editFont);
	GetDlgItem(IDC_PASSWORD)->SetFont(&g_editFont);*/

}
BEGIN_MESSAGE_MAP(FormRegister, CFormView)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &FormRegister::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT7, &FormRegister::OnEnChangeEdit7)
END_MESSAGE_MAP()


// FormRegister 진단

#ifdef _DEBUG
void FormRegister::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormRegister::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormRegister 메시지 처리기


HBRUSH FormRegister::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	pDC->SetBkColor(RGB(246, 238, 225));
	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void FormRegister::OnBnClickedOk()
{
	UpdateData(true);
	switch (mRadio)
	{
	case 0: u_gender = _T("남");
		test_name = u_gender;
		break;
	case 1: u_gender = _T("여"); break;
	}
	MYSQL mysqlCon;
	if (u_fname.IsEmpty() || u_email.IsEmpty() || u_gender.IsEmpty() || u_bday.IsEmpty()
		|| u_address.IsEmpty() || u_uname.IsEmpty() || u_password.IsEmpty() || u_confirm.IsEmpty())
	{
		MessageBox(_T("The information is not filled in completely"), _T("Prompt"));
		return;
	}
	//Database Connectivity 
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "qq1024", "YongoLearn", 3306, NULL, 0))
	{
		MessageBox(_T("Database connection failed"));
		return;
	}
	else
	{
		//UpdateData(true);
		mysql_query(&mysqlCon, "set names euckr");

		//char* UserName = (char*) m_Username.GetBuffer();
		//char* Paass = (char*)m_Password.GetBuffer();
		//char insert[1000];

		//sprintf_s(insert, sizeof(insert), "insert into users(Uname,PassMe) values('%s','%s')", m_Username, m_Password);

		CString insert;
		insert.Format(_T("insert into learnerInfo(Fname,Email,Gender,BirthDay,Address,Uname,Password,ConfirmPassword) values ('%s','%s', '%s','%s', '%s','%s', '%s','%s')"), u_fname, u_email, u_gender, u_bday, u_address, u_uname, u_password, u_confirm);

		//MessageBox(insert);

		const wchar_t* str = (CStringW)insert;
		
		USES_CONVERSION;
		if (mysql_query(&mysqlCon,W2A(str)) == 0)
		{
			MessageBox(_T("Insert successfully"));
		}
		else
		{
			MessageBox(_T("insert failure"));
			return;
		}

	}
	UpdateData(false);
	mysql_close(&mysqlCon);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormRegister::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
