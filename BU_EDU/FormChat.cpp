// FormChat.cpp: 구현 파일
//

#include "pch.h"
#include "BU_EDU.h"
#include "FormChat.h"
#include <locale.h>

// FormChat

IMPLEMENT_DYNCREATE(FormChat, CFormView)

FormChat::FormChat()
	: CFormView(IDD_FORM_CHAT)
	, message(_T(""))
	, result(_T(""))
{

}

FormChat::~FormChat()
{
}

void FormChat::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, message);
	DDX_Text(pDX, IDC_EDIT2, result);
	DDX_Control(pDX, IDC_BURI3, Buricon);
}
BOOL FormChat::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{


	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
void FormChat::OnInitialUpdate()
{

	//m_hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BG));
	//GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);
	//CClientDC dc(this);
	//image1.Load(_T("./res/여우.jpg"));
	//image1.BitBlt(dc.m_hDC, 255, 140, 200, 200, 200, 180, SRCCOPY);
	CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
	Buricon.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
	CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
	dc = Buricon.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.
	//CDC* dc = Buricon.GetWindowDC();
	CImage image;//불러오고 싶은 이미지를 로드할 CImage 
	image.Load(_T("./res/buri.bmp"));//이미지 로드

	image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
	ReleaseDC(dc);//DC 해제

	for (int i = 0; i < m_arrDictionary.GetSize(); ++i)
	{
		Dictionary* pDictionary = m_arrDictionary.GetAt(i); // 해당 배열의 값을 매칭시켜준다.

		if (NULL == pDictionary) // pDictionary 객체가 Null이면 계속 진행하고
			continue;

		delete pDictionary; //그렇지 않을 경우 객체 삭제

		pDictionary = NULL;
	}

	m_arrDictionary.RemoveAll(); //배열 삭제

	_tsetlocale(LC_ALL, _T("Korean")); //한국 지역으로 설정

	FILE* fp = NULL; //파일 객체 선언
	fopen_s(&fp, ".\\res\\dummy2.csv", "r"); //해당 경로에 파일을 읽어라

	Dictionary* pDictionary = new Dictionary;

	if (fp) //해당 파일이 있고
	{
		char szContent[2048] = { 0, };

		memset(szContent, NULL, 2048);

		while (fgets(szContent, 2048, fp))//파일을 한 라인씩 읽어라
		{
			CString strContent;

			strContent = szContent;

			memset(szContent, NULL, 2048);

			strContent.Remove('\r');
			strContent.Remove('\n');

			strContent = strContent; //유니코드 변환하여 저장

			Dictionary* pDictionary = new Dictionary;

			CString rString;
			int nSubString = 0;

			//AfxExtractSubString() 함수를 이용하여 해당 CSV 파일은 , 단위로
			while (AfxExtractSubString(rString, strContent, nSubString++, ','))
			{
				switch (nSubString)
				{
				case 2: pDictionary->English = rString; break;
				case 3: pDictionary->Korea = rString; break;
				}
			}

			m_arrDictionary.Add(pDictionary);

		}
		fclose(fp);//파일 닫기



	}



	SetDlgItemText(IDC_EDIT2, _T("=============단어쟁이 챗봇 =============\r\n안녕하세요! 저는 뷰리입니다~\r\n수업 중 모르는 단어가 있다면 저에게 물어봐주세요~\r\n인터넷을 이용할 경우 수업집중도가 저하될 수가 있어요ㅜㅜ \r\n==================================\r\n"));





}

BEGIN_MESSAGE_MAP(FormChat, CFormView)
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_EDIT2, &FormChat::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &FormChat::OnBnClickedButton1)
END_MESSAGE_MAP()


// FormChat 진단

#ifdef _DEBUG
void FormChat::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormChat::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormChat 메시지 처리기


HBRUSH FormChat::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CreateSolidBrush(RGB(246, 238, 225));
	return hbr;
}


void FormChat::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void FormChat::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData();

	result.Append(_T("[me] "));
	result.Append(message);

	result.Append(_T("\r\n"));

	//입출력 파일 으로 정리한 영어 단어 관련 파일 입출력 구현

	UpdateData(false);



	//		Dictionary* pDictionary;
	CString Word;
	/*= pDictionary->English + ":" + pDictionary->Korea*/
	int count = 0;
	int count2 = 0;

	bool englword = false;
	for (int i = 0; i < m_arrDictionary.GetSize(); i++)
	{
		Dictionary* pDictionary = m_arrDictionary.GetAt(i);
		CString english = pDictionary->English;
		CString korea = pDictionary->Korea;
		//			Word = pDictionary->English + ":" + pDictionary->Korea;


		int test1 = (message.Find(english));
		int test2 = (message.Find(korea));

		if (test2 == 0)
		{
			englword = true;
			Word = english;

		}
		else if (test1 == 0)
		{
			englword = true;
			Word = korea;

		}

		//			AfxMessageBox(Word);
	}

	if (englword)
	{
		//				message를 .find(Word) 사용해서 기면, word 출력?		
		if (count < 2)
		{
			UpdateData();
			result.Append(_T("[chatboot] "));
			result.Append(_T("질문한 단어의 의미는 \""));
			result.Append(Word);
			result.Append(_T("\""));
			result.Append(_T("(이)에요"));
			result.Append(_T("\r\n"));
			result.Append(_T(" "));
			result.Append(_T("\r\n"));
			UpdateData(false);
			count++;
		}
		//pDictionary = m_arrDictionary.GetAt(i);				
	}
	else
	{

		if (count < 2)
		{
			UpdateData();
			result.Append(_T("[chatboot] "));

			result.Append(_T("단어를 이해하지 못했어요 ^^\r\n"));
			result.Append(_T(" "));
			result.Append(_T("\r\n"));
			UpdateData(false);
			count++;
		}
	}






}
