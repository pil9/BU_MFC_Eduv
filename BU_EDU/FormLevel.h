#pragma once



// FormLevel 폼 보기

class FormLevel : public CFormView
{
	DECLARE_DYNCREATE(FormLevel)

protected:
	           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormLevel();

public:
	FormLevel();

	CImage image1, image2, image3;
	int b_state = 0, Timer = 60;
	CString rq1;
	int wran;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_LEVEL };
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


