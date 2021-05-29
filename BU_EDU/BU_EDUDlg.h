
// BU_EDUDlg.h : header file
//
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


#include <Mmreg.h>
#include "Mmsystem.h"
#include "FormAudio.h"
#include "Formtest.h"
#include "FormLevel.h"
#include "FormEdu.h"
#include "FormChat.h"
#include "FormLogin.h"
#include "FormRegister.h"

#pragma once

typedef struct BufferNode
{
	int length;
	void* buffer;
};


// CBUEDUDlg dialog
class CBUEDUDlg : public CDialogEx
{
// Construction

public:
	CBUEDUDlg(CWnd* pParent = nullptr);	// standard constructor
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BU_EDU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	CButton * onokbutton;
	FormAudio *p_audio;
	Formtest *p_test;
	FormLevel* p_Level;
	FormEdu* p_Edu;
	FormChat* p_Chat;
	FormRegister* p_Register;
	FormLogin* p_Login;
	
	void AllocForms();
	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void ShowForm(int idx);
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CBitmapButton main_btn1;
	CBitmapButton main_btn2;
	CBitmapButton sub_btn1;
	CBitmapButton sub_btn2;
	CBitmapButton sub_btn3;
	CBitmapButton sub_btn4;
	CBitmapButton sub_btn5;
	CBitmapButton sub_btn6;
	CBitmapButton sub_btn7;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnStnClickedStaticRect();
	afx_msg void OnBnClickedButton7();
	CButton onokbtn;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton10();
};
