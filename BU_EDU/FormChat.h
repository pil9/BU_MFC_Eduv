#pragma once

struct Dictionary
{
	CString English;
	CString Korea;

	Dictionary()
	{
		English.Empty();
		Korea.Empty();

	}
};

// FormChat 폼 보기

class FormChat : public CFormView
{
	DECLARE_DYNCREATE(FormChat)

public:
	FormChat();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormChat();

public:
	CArray<Dictionary*, Dictionary*> m_arrDictionary; // 배열 변수 선언
	CImage image1;
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;

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
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CString message;
	CString result;
	CStatic Buricon;
	CRect m_image_rect;
	CImage m_image;
	CEdit m_result;
	CBitmapButton m_submit;
	/*CString m_strBGImgPath;
	CImage	m_BGImg;*/
	/*int m_resizeX;
	int m_resizeY;
	int m_verticalCent;*/
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


