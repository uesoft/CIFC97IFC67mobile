// PropertyPage1.cpp : implementation file
//

#include "stdafx.h"
#include "ifc97ifc67.h"
#include "PropertyPageAbout.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertyPageAbout property page

IMPLEMENT_DYNCREATE(CPropertyPageAbout, CPropertyPage)


CPropertyPageAbout::CPropertyPageAbout() : CPropertyPage(CPropertyPageAbout::IDD)
{
	//{{AFX_DATA_INIT(CPropertyPageAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPropertyPageAbout::~CPropertyPageAbout()
{
}

void CPropertyPageAbout::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertyPageAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertyPageAbout, CPropertyPage)
	//{{AFX_MSG_MAP(CPropertyPageAbout)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyPageAbout message handlers
