
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFC_ch4.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), 
		//reinterpret_cast<HBRUSH>(COLOR_WINDOW+1)
		(HBRUSH)GetStockObject(GRAY_BRUSH), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	dc.SetBkMode(OPAQUE); //이 줄을 주석 처리해도 결과는 같음
	dc.TextOutW(100, 50, CString(" OPQUE 모드 [1] "));

	dc.SetBkMode(TRANSPARENT);
	dc.TextOutW(100, 100, CString(" TRANSPARETN 모드 "));

	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0, 255, 0)); //배경을 초록색으로 설정
	dc.TextOut(100, 150, CString(" OPQUE 모드 [2]"));


}



