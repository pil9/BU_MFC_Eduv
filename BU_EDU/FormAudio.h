#pragma once



// FormAudio 폼 보기

class FormAudio : public CFormView
{
	DECLARE_DYNCREATE(FormAudio)
	
public:
	FormAudio();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormAudio();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_AUDIO };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;
	afx_msg void OnBnClickedButton3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_audio_list;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CBitmapButton m_record;
	CBitmapButton m_stop;
	CBitmapButton m_play;
	afx_msg void OnBnClickedBtnPlay();
};


