// FormAudio.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormAudio.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>

// FormAudio

IMPLEMENT_DYNCREATE(FormAudio, CFormView)

int idx_row = 0;
int idx_col = 0;
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
	DDX_Control(pDX, IDC_LIST1, m_audio_list);
	DDX_Control(pDX, IDC_BTN_RECORD, m_record);
	DDX_Control(pDX, IDC_BTN_STOP, m_stop);
	DDX_Control(pDX, IDC_BTN_PLAY, m_play);
}



void FormAudio::OnPaint() {

	//CPaintDC dc(this); // device context for painting
	//CRect rect;
	//GetWindowRect(&rect); // 스크린과 호환되는 DC생성.
	//HDC hMemDC = CreateCompatibleDC(dc);
	//SetStretchBltMode(hMemDC, HALFTONE); // 호환DC에 비트맵을 선정.
	//SelectObject(hMemDC, m_hBitmap); // 메모리 DC에서 스크린 DC로 이미지 복사
	//StretchBlt(dc, 0, 0, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY); // 메모리 DC삭제
	//DeleteDC(hMemDC);
}
BOOL FormAudio::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
void FormAudio::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_record.LoadBitmaps(IDB_MAIN_RECORD, NULL, NULL, NULL);
	m_record.SizeToContent();
	m_play.LoadBitmaps(IDB_MAIN_PLAY_ON, IDB_MAIN_PLAY, NULL, NULL);
	m_play.SizeToContent();
	m_stop.LoadBitmaps(IDB_MAIN_STOP, NULL, NULL, NULL);
	m_stop.SizeToContent();

	CString tpath = _T(".\\res\\audio\\*.*");

	//검색 클래스
	CFileFind finder;

	//CFileFind는 파일, 디렉터리가 존재하면 TRUE 를 반환함
	BOOL bWorking = finder.FindFile(tpath); //

	CString fileName;
	CString DirName;
	CBitmap bmp;
	bmp.LoadBitmap(IDB_MAIN_MUSIC);
	static CImageList ImgList;
	ImgList.Create(60, 48, ILC_COLOR32, 1, 1); //이미지 아이콘의 크기를 결정하는듯
	ImgList.Add(&bmp, RGB(0, 0, 0)); // 두번째 인자는 마스크로 검정색으로 해야 이미지 주변이 하얗게 나온다.
	m_audio_list.SetImageList(&ImgList, LVSIL_NORMAL);
	while (bWorking)
	{
		//다음 파일 / 폴더 가 존재하면다면 TRUE 반환
		bWorking = finder.FindNextFile();
		//파일 일때
		if (finder.IsArchived())
		{
			//파일의 이름
			CString _fileName = finder.GetFileName();

			// 현재폴더 상위폴더 썸네일파일은 제외
			if (_fileName == _T(".") ||
				_fileName == _T("..") ||
				_fileName == _T("Thumbs.db")) continue;

			fileName = finder.GetFileTitle();
			
			m_audio_list.InsertItem(0, fileName);
			//읽어온 파일 이름을 리스트박스에 넣음
		}
		// 디렉터리 일때
		//if (finder.IsDirectory())
		//{
				// 필요하면 여기서 처리
		//DirName = finder.GetFileName();
		//}
	}

	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BURI);
	//static CImageList ImgList;
	//ImgList.Create(20, 20, ILC_COLOR32, 1, 1); //이미지 아이콘의 크기를 결정하는듯
	//ImgList.Add(&bmp, RGB(0, 0, 0)); // 두번째 인자는 마스크로 검정색으로 해야 이미지 주변이 하얗게 나온다.

	//m_audio_list.SetImageList(&ImgList, LVSIL_NORMAL);
	//m_audio_list.InsertItem(0, _T("첫번째 아이템"));
}

BEGIN_MESSAGE_MAP(FormAudio, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &FormAudio::OnBnClickedButton3)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON4, &FormAudio::OnBnClickedButton4)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &FormAudio::OnNMClickList1)
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


HBRUSH FormAudio::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	
	return hbr;
}


void FormAudio::OnBnClickedButton4()
{
	CString sIndexValue;
	sIndexValue = m_audio_list.GetItemText(idx_row,idx_col);
	CString sound_data = _T("./res/audio/") + sIndexValue + ".wav";
	//sound_data += fileName;
	PlaySound(sound_data, AfxGetInstanceHandle(), SND_ASYNC);
	//MessageBox(_T("Test"));
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormAudio::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	idx_row = pNMListView->iItem;
	idx_col = pNMListView->iSubItem;
	/*CString str;
	str.Format(("%d", idx));
	MessageBox((CString)));*/
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
