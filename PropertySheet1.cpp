// PropertySheet1.cpp : implementation file
//

#include "stdafx.h"
#include "ifc97ifc67.h"
#ifdef VC_UESOFT
#include "PropertySheet1.h"
#include "HtmlHelp.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet1

#ifdef VC_UESOFT
IMPLEMENT_DYNAMIC(CPropertySheet1, CPropertySheet)
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
 
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CPropertySheet1::CPropertySheet1(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

CPropertySheet1::CPropertySheet1(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

CPropertySheet1::~CPropertySheet1()
{
}


BEGIN_MESSAGE_MAP(CPropertySheet1, CPropertySheet)
	//{{AFX_MSG_MAP(CPropertySheet1)
     ON_WM_SYSCOMMAND()
     ON_COMMAND(IDR_MENU2, OnMenu2)/////****************************xiehui  added
	 ON_COMMAND(IDR_MENU3, OnMenu3)/////****************************xiehui  added
	ON_COMMAND(IDR_BUTTON_HELP, OnButtonHelp)
	ON_COMMAND(IDR_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet1 message handlers
void CPropertySheet1::OnSysCommand(UINT nID, LPARAM lParam)
{
    #if defined(VC_UESOFT)
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{		
		CPropertySheet::OnSysCommand(nID, lParam);
	}
  #else
        CPropertySheet::OnSysCommand(nID, lParam);
 #endif
		 
}
BOOL CPropertySheet1::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	CWnd *pWnd;
	UINT nRsID[]= {IDOK,IDCANCEL,ID_APPLY_NOW,IDHELP};

	// TODO: Add your specialized code here
    for(int i=0;i<sizeof nRsID/sizeof nRsID[0];i++)
    {
		pWnd=GetDlgItem(nRsID[i]);
		pWnd->ShowWindow(FALSE); 
	}
#if defined(VC_UESOFT)
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}///*************xiehui
   #endif
    SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);   
	m_Menu=new CMenu();
	if(!m_Menu->LoadMenu(IDR_MENU1))MessageBox(_T("参数越界!"));
    else  SetMenu(m_Menu);   
   m_Menu->CheckMenuRadioItem( IDR_MENU2,IDR_MENU3, IDR_MENU2,MF_BYCOMMAND);
   return bResult;
}
void CPropertySheet1::OnMenu2() /////****************************xiehui  added
{ 
	/*TCHAR str[123];
	::wsprintf(str,"%d",m_Menu.GetMenuState(IDR_MENU2, MF_BYCOMMAND )); 

	if(m_Menu.GetMenuState(IDR_MENU3, MF_BYCOMMAND )==512||m_Menu.GetMenuState(IDR_MENU3, MF_BYCOMMAND )==0)
	::AfxMessageBox("kkkkkkkkkkkkk"); 

    ::wsprintf(str,"%d",m_Menu.GetMenuState(IDR_MENU2, MF_BYCOMMAND )); 

	//if(m_Menu.GetMenuState(IDR_MENU3, MF_BYCOMMAND )==MF_CHECKED)

	::AfxMessageBox(str);*/	
	m_Menu->CheckMenuRadioItem( IDR_MENU2,IDR_MENU3, IDR_MENU2,MF_BYCOMMAND);
   
	// TODO: Add your command handler code here
	 //m_Menu.CheckMenuItem( IDR_MENU2, MF_BYCOMMAN);
}

///**************************xiehui
void CPropertySheet1::OnMenu3() /////****************************xiehui  added
{
m_Menu->CheckMenuRadioItem(IDR_MENU2,IDR_MENU3, IDR_MENU3,MF_BYCOMMAND);
//dlg->ShowWindow(SW_HIDE);
// TODO: Add your command handler code here
}

#if defined(VC_UESOFT)
void CPropertySheet1::OnHelp() 
{
	HtmlHelp(NULL,AfxGetApp()->m_pszHelpFilePath,HH_DISPLAY_TOC,NULL);	
}

void CPropertySheet1::OnButtonHelp()
{
	// TODO: Add your control notification handler code here
	OnHelp(); ////////x********xiehui
}

#endif

void CPropertySheet1::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


#endif