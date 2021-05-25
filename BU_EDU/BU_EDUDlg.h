
// BU_EDUDlg.h : header file
//
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


#include <Mmreg.h>
#include "Mmsystem.h"
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
	afx_msg void OnBnClickedButton1();
};
