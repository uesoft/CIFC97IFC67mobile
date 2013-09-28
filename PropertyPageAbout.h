#if !defined(AFX_PROPERTYPAGE1_H__04066E70_7560_4F2F_8CD7_AA994293D7AA__INCLUDED_)
#define AFX_PROPERTYPAGE1_H__04066E70_7560_4F2F_8CD7_AA994293D7AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertyPage1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyPageAbout dialog

class CPropertyPageAbout : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropertyPageAbout)

// Construction
public:
	CPropertyPageAbout();
	~CPropertyPageAbout();

// Dialog Data
	//{{AFX_DATA(CPropertyPageAbout)
	enum { IDD = IDD_ABOUTBOX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropertyPageAbout)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertyPageAbout)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYPAGE1_H__04066E70_7560_4F2F_8CD7_AA994293D7AA__INCLUDED_)
