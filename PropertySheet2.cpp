// PropertySheet2.cpp : implementation file
//

#include "stdafx.h"
#include "ifc97ifc67.h"
#ifndef VC_UESOFT
#include "PropertySheet2.h"
#endif
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet2
#ifndef VC_UESOFT
IMPLEMENT_DYNAMIC(CPropertySheet2, CPropertySheet)

CPropertySheet2::CPropertySheet2(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CPropertySheet2::CPropertySheet2(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CPropertySheet2::~CPropertySheet2()
{
}


BEGIN_MESSAGE_MAP(CPropertySheet2, CPropertySheet)
	//{{AFX_MSG_MAP(CPropertySheet2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet2 message handlers

BOOL CPropertySheet2::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	//SHSipPreference(AfxGetMainWnd()->m_hWnd,SIP_UP); 


	return bResult;
}
void CPropertySheet2::OnOK()
{
	/*CDialog::OnOK();
	DestroyWindow();*/
	exit(1);

}

void CPropertySheet2::OnCancel()
{
	/*CDialog::OnOK();
	DestroyWindow();*/
	exit(1);

}
#endif