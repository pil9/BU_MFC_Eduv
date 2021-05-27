// FormAudio.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormAudio.h"


// FormAudio

IMPLEMENT_DYNCREATE(FormAudio, CFormView)

FormAudio::FormAudio()
	: CFormView(IDD_FORM_AUDIO)
{

}

FormAudio::~FormAudio()
{
}

void FormAudio::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL FormAudio::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormAudio::OnPaint() {

	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetWindowRect(&rect); // 스크린과 호환되는 DC생성.
	HDC hMemDC = CreateCompatibleDC(dc);
	SetStretchBltMode(hMemDC, HALFTONE); // 호환DC에 비트맵을 선정.
	SelectObject(hMemDC, m_hBitmap); // 메모리 DC에서 스크린 DC로 이미지 복사
	StretchBlt(dc, 0, 0, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY); // 메모리 DC삭제
	DeleteDC(hMemDC);
}

void FormAudio::OnInitialUpdate()
{
	
}

BEGIN_MESSAGE_MAP(FormAudio, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &FormAudio::OnBnClickedButton3)
END_MESSAGE_MAP()


// FormAudio 진단

#ifdef _DEBUG
void FormAudio::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormAudio::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormAudio 메시지 처리기


void FormAudio::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
