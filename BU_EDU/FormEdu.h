#pragma once



// FormEdu 폼 보기

class FormEdu : public CFormView
{
	DECLARE_DYNCREATE(FormEdu)

public:
	FormEdu();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormEdu();

	CImage image4, image5, image6;
	CFont m_font;
	int count = 0;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_EDU };
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
	virtual void OnInitialUpdate();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	CString result;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


