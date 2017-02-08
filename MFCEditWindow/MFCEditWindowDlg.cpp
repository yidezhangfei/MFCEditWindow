
// MFCEditWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCEditWindow.h"
#include "MFCEditWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCEditWindowDlg dialog



CMFCEditWindowDlg::CMFCEditWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCEditWindowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCEditWindowDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_EDIT_HANDLE, m_SearchWindow);
  DDX_Control(pDX, IDC_BUTTON_SETWINPOS, m_SetWinPos);
}

BEGIN_MESSAGE_MAP(CMFCEditWindowDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
        ON_BN_CLICKED(IDC_BUTTON_SETWINPOS, &CMFCEditWindowDlg::OnBnClickedButtonSetwinpos)
END_MESSAGE_MAP()


// CMFCEditWindowDlg message handlers

BOOL CMFCEditWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCEditWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCEditWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCEditWindowDlg::OnBnClickedButtonSetwinpos()
{
  // TODO: Add your control notification handler code here
  CString strHwnd;
  m_SearchWindow.GetWindowText(strHwnd);
  CT2A strHwndii(strHwnd);

  HWND findedWindow = (HWND)strtol(strHwndii.m_psz, NULL, 16);

  if (!::IsWindow(findedWindow))
  {
    ::MessageBox(NULL, L"isn't window", NULL, NULL);
  }
  else
  {
    RECT rect;
    ::GetClientRect(findedWindow, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    int iFlag = SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE;
    ::SetWindowPos(findedWindow, NULL, 0, 0, width / 2, height / 2, iFlag);
  }
}
