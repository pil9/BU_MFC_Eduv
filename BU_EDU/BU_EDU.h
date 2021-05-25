
// BU_EDU.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBUEDUApp:
// See BU_EDU.cpp for the implementation of this class
//

class CBUEDUApp : public CWinApp
{
public:
	CBUEDUApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBUEDUApp theApp;
