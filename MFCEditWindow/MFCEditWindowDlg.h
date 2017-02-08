
// MFCEditWindowDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCEditWindowDlg dialog
class CMFCEditWindowDlg : public CDialogEx
{
// Construction
public:
	CMFCEditWindowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCEDITWINDOW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  CEdit m_SearchWindow;
  CButton m_SetWinPos;
  afx_msg void OnBnClickedButtonSetwinpos();
};
