#pragma once



// FormLogin 폼 보기

class FormLogin : public CFormView
{
	DECLARE_DYNCREATE(FormLogin)

public:
	FormLogin();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormLogin();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_LOGIN };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
//	virtual void OnInitialUpdate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnReg();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnEnChangeEdit1();
//	CString m_Username;
//	CString m_Password;
//	CString m_Username;
//	CString m_Password;
	CString m_Username;
	CString m_Password;
//	CBitmapButton main_login;
//	CBitmap m_login;
//	CButton m_btn_login;
	afx_msg void OnPaint();
	CBitmapButton m_btn_login;
	/*CBitmap m_bitmap_login;*/
	virtual void OnInitialUpdate();
	CBitmapButton m_btn_reg;
};
extern bool login_check;

