#if !defined(AFX_PROPERTYSHEET1_H__757C9916_B73D_4A65_AE70_E8885C545C9A__INCLUDED_)
#define AFX_PROPERTYSHEET1_H__757C9916_B73D_4A65_AE70_E8885C545C9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertySheet1.h : header file
//
#include <afxres.h>
/////////////////////////////////////////////////////////////////////////////
// CPropertySheet1

class CPropertySheet1 : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropertySheet1)

// Construction
public:
	CPropertySheet1(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertySheet1(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
    CMenu   *m_Menu;
    #if defined(VC_UESOFT)
public:	
	virtual void OnHelp();
	#endif
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheet1)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropertySheet1();

	// Generated message map functions
protected:
HICON m_hIcon;	
protected:
	//{{AFX_MSG(CPropertySheet1)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnMenu2();
	afx_msg void OnMenu3();
	afx_msg void OnButtonHelp();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYSHEET1_H__757C9916_B73D_4A65_AE70_E8885C545C9A__INCLUDED_)
