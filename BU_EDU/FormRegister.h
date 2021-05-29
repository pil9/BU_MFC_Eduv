#pragma once



// FormRegister 폼 보기

class FormRegister : public CFormView
{
	DECLARE_DYNCREATE(FormRegister)

public:
	FormRegister();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormRegister();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_REG };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CFont newFont;
	DECLARE_MESSAGE_MAP()
public:
	CString u_fname;
	CString u_email;
	CString u_gender;
	CString u_bday;
	CString u_address;
	CString u_uname;
	CString u_password;
	CString u_confirm;
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
	int mRadio;
	
	afx_msg void OnEnChangeEdit7();
	CBitmapButton m_btn_submit;
};
extern CString test_name;


