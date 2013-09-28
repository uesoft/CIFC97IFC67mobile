#if !defined(AFX_PROPERTYSHEET2_H__532C5BF0_0D62_4D6E_97C9_6F8A7C3DCE97__INCLUDED_)
#define AFX_PROPERTYSHEET2_H__532C5BF0_0D62_4D6E_97C9_6F8A7C3DCE97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertySheet2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet2

class CPropertySheet2 : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropertySheet2)

// Construction
public:
	CPropertySheet2(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertySheet2(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheet2)
	public:
	virtual BOOL OnInitDialog();
     virtual void OnOK();
     virtual void OnCancel();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropertySheet2();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheet2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYSHEET2_H__532C5BF0_0D62_4D6E_97C9_6F8A7C3DCE97__INCLUDED_)
