// DialogAbout.cpp : implementation file
//

#include "stdafx.h"
#include "ifc97ifc67.h"
#include "MainDialog.h"
#include "PropertyPageAbout.h"
#include "PropertySheet2.h"
#include "AboutDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDialog dialog

bool RADIO_97=TRUE;
CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialog)
	//{{AFX_MSG_MAP(CMainDialog)
	ON_COMMAND(IDR_MENU2, OnMenu2)
	ON_COMMAND(IDR_MENU3, OnMenu3)
	ON_COMMAND(IDR_ABOUT, OnAbout)
	ON_COMMAND(IDR_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDialog message handlers
BOOL CMainDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
    CPropertySheet2 *ps=new CPropertySheet2(_T("水蒸汽性质计算"));	
    //CPropertyPageAbout *ppa=new CPropertyPageAbout();
    this->ShowWindow(SW_HIDE); 
	CPropertyPageInput *ppi=new CPropertyPageInput();
	CPropertyPageResult * ppr=new CPropertyPageResult();	
	ps->AddPage(ppi);
	ps->AddPage(ppr);
    //ps->AddPage(ppa);	
	 ps->Create(this);	 
    CCeCommandBar *pCommandBar=(CCeCommandBar *)m_pWndEmptyCB;	 
	m_Menu=pCommandBar->InsertMenuBar(IDR_MENU1);	    
    m_Menu->CheckMenuRadioItem( IDR_MENU2,IDR_MENU3, IDR_MENU2,MF_BYCOMMAND);
    m_pnHwnd=ps;
	m_pPage=ppi;
	return TRUE;
}

void CMainDialog::OnMenu2() 
{
	//DO: / TOAdd your command handler code here
	 m_Menu->CheckMenuRadioItem( IDR_MENU2,IDR_MENU3, IDR_MENU2,MF_BYCOMMAND);
	 RADIO_97=TRUE;

   CPropertySheet *ps_t;
   //CPropertyPageInput *ppi;
  CMainDialog *md;
   md=(CMainDialog *)(AfxGetApp()->m_pMainWnd);
  ps_t=(CPropertySheet *)(md->m_pnHwnd);
  if(ps_t->GetActiveIndex()==1)
  {
	 //ppi=(CPropertyPageInput *)(ps_t->GetActivePage());
	m_pPage->OnCompute(); 
  }
}

void CMainDialog::OnMenu3() 
{
	// TODO: Add yo//ur command handler code here
  
	 RADIO_97=FALSE;
	 m_Menu->CheckMenuRadioItem( IDR_MENU2,IDR_MENU3, IDR_MENU3,MF_BYCOMMAND);
   
	 CPropertySheet *ps_t;
   //CPropertyPageInput *ppi;
  CMainDialog *md;
   md=(CMainDialog *)(AfxGetApp()->m_pMainWnd);
  ps_t=(CPropertySheet *)(md->m_pnHwnd);
  if(ps_t->GetActiveIndex()==1)
  {
	 //ppi=(CPropertyPageInput *)(ps_t->GetActivePage());
	m_pPage->OnCompute(); 
  }
}

void CMainDialog::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDialog *da=new CAboutDialog(AfxGetApp()->m_pMainWnd);
	da->Create(IDD_ABOUTBOX,AfxGetApp()->m_pMainWnd);
	da->ShowWindow(SW_SHOW); 
}

void CMainDialog::OnButtonHelp() 
{
	// TODO: Add your command handler code here
	
}
