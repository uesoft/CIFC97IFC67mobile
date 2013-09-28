#if !defined(AFX_DIALOGABOUT_H__30C980CC_E411_4301_B3DF_246560C466B5__INCLUDED_)
#define AFX_DIALOGABOUT_H__30C980CC_E411_4301_B3DF_246560C466B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogAbout.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDialog dialog
#include "resource.h"
#include "PropertyPageInput.h"
class CMainDialog : public CDialog
{
// Construction
public:
	CMainDialog(CWnd* pParent = NULL);   // standard constructor
    CMenu * m_Menu;
	CWnd * m_pnHwnd;
	CPropertyPageInput *m_pPage;

// Dialog Data
	//{{AFX_DATA(CMainDialog)
	enum { IDD = IDD_ABOUTBOX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDialog)
	protected:
   virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDialog)
	afx_msg void OnMenu2();
	afx_msg void OnMenu3();
	afx_msg void OnAbout();
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGABOUT_H__30C980CC_E411_4301_B3DF_246560C466B5__INCLUDED_)
