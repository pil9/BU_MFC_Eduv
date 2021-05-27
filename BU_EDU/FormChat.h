#pragma once



// FormChat 폼 보기

class FormChat : public CFormView
{
	DECLARE_DYNCREATE(FormChat)

public:
	FormChat();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormChat();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_CHAT };
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

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


