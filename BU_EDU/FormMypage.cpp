// FormMypage.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormMypage.h"
#include "BU_EDUDlg.h"

// FormMypage

IMPLEMENT_DYNCREATE(FormMypage, CFormView)

FormMypage::FormMypage()
	: CFormView(IDD_FORM_MYPAGE)
	, m_name(_T(""))
{

}

FormMypage::~FormMypage()
{
}

void FormMypage::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_email);
	DDX_Text(pDX, IDC_EDIT3, m_birth);
	DDX_Text(pDX, IDC_EDIT4, m_address);
	DDX_Text(pDX, IDC_EDIT5, m_level);
	DDX_Control(pDX, IDC_BUTTON2, m_change);
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
	MYSQL mysqlCon;
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "qq1024", "YongoLearn", 3306, NULL, 0))
	{
		MessageBox(_T("Database connection failed!"));
		return;
	}
	else
	{
		//UpdateData(true);
		mysql_query(&mysqlCon, "set names euckr");
		CString select;
		select = _T("select Fname,Email,BirthDay, Address from learnerInfo where Uname = \'") + user_id;
		select += "\'";

		const wchar_t* selectData = (CStringW)select;
		USES_CONVERSION;
		mysql_real_query(&mysqlCon, W2A(selectData), (unsigned long)strlen(W2A(selectData)));

		//select.Format(_T("select Fname,Lname,Email,BirthDay, Address from learnerInfo where Uname ='%s'",checkLogin));
		/*const char* selectData = (CStringA)select;
		mysql_real_query(&mysqlCon, selectData, (unsigned long)strlen(selectData));*/
		int i = 0;
		MYSQL_ROW row;
		MYSQL_RES* result;
		result = mysql_store_result(&mysqlCon);
		//Select the user and password in the database to determine whether it is the same as the user password in the edit box
		while ((row = mysql_fetch_row(result)))
		{
			//UpdateData(true);
			
			//char* LastName = row[1];
			/*char* FirstName = row[0];
			char* Email = row[2];
			char* Birth = row[3];
			char* Address = row[4];*/
			m_name = row[0];
			m_email = row[1];
			m_birth = row[2];
			m_address = row[3];
			m_level = _T("1레벨");
			UpdateData(false);

			/*bringIt = FirstName;
			bringLast = LastName;
			bringEmail = Email;
			bringBirth = Birth;
			bringAddress = Address;*/

		}
	}

	mysql_close(&mysqlCon);
	m_edit.LoadBitmaps(IDB_MAIN_EDIT, NULL, NULL, NULL);
	m_edit.SizeToContent();
	m_change.LoadBitmaps(IDB_MAIN_CHANGE, NULL, NULL, NULL);
	m_change.SizeToContent();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
