#pragma once



// FormMypage 폼 보기

class FormMypage : public CFormView
{
	DECLARE_DYNCREATE(FormMypage)

public:
	FormMypage();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormMypage();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_MYPAGE };
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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	CBitmapButton m_edit;
	CString m_name;
	CString m_email;
	CString m_birth;
	CString m_address;
	CString m_level;

	CBitmapButton m_change;
};


