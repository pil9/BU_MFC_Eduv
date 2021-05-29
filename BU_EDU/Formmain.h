#pragma once



// Formmain 폼 보기

class Formmain : public CFormView
{
	DECLARE_DYNCREATE(Formmain)

public:
	Formmain();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~Formmain();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_MAIN};
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


