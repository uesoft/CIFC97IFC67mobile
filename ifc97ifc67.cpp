// IFC97IFC67.cpp : Defines the class behaviors for the application.
//

//************************************************************
//     作    者：                                            *
//              长沙优易软件开发有限公司(UESoft Corp.) 邝祝芳*
//     文件名称：                                            * 
//                                                           *
//     完成时间：                                            *
//                2005年5月                                  *
//************************************************************

#include "stdafx.h"
#ifndef VC_UESOFT
#include "MainDialog.h"
#endif
#include "IFC97IFC67.h"
#include "PropertyPageAbout.h"
#include "PropertyPageInput.h"
#ifndef VC_UESOFT
#include "PropertySheet2.h"///***************need to edit
#else
#include "PropertySheet1.h"///***************need to edit
#include "HtmlHelp.h"
#endif

#ifdef _DEBUG 
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67App

BEGIN_MESSAGE_MAP(CIFC97IFC67App, CWinApp)
	//{{AFX_MSG_MAP(CIFC97IFC67App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
#if defined(VC_UESOFT)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)///set for VC_UESOFT
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67App construction

CIFC97IFC67App::CIFC97IFC67App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIFC97IFC67App object


CIFC97IFC67App theApp;

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67App initialization

BOOL CIFC97IFC67App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	#if defined(VC_UESOFT)
	#ifdef _AFXDLL
		Enable3dControls();			// Call this when using MFC in a shared DLL
	#else
		Enable3dControlsStatic();	// Call this when linking to MFC statically
	#endif
	#endif ///////set for VC_UESOFT

    #if defined(VC_UESOFT)
	BOOL bEngLang=true;//使用英文版
	
	DWORD dwID;
	if(bEngLang)
	{
			WORD id = MAKELANGID(LANG_ENGLISH,SUBLANG_DEFAULT );
			dwID = MAKELCID( id,SORT_DEFAULT );
	}
	else
	{
			WORD id = MAKELANGID( LANG_CHINESE,SUBLANG_DEFAULT );
			dwID = MAKELCID( id,SORT_DEFAULT );		
	}
	SetThreadLocale( dwID );
    #endif

	//设置帮助文件
	CString strHelpPath;
	CString strHelpFile;
	::GetModuleFileName(NULL,strHelpPath.GetBuffer(MAX_PATH),MAX_PATH);
	strHelpPath.ReleaseBuffer();
	TCHAR ch='\\';
	short i=strHelpPath.ReverseFind(ch);
	strHelpPath=strHelpPath.Left(i);

	strHelpFile=strHelpPath+"\\waterpro.chm";

	TRY
	{
	   free((void*)m_pszHelpFilePath);//首先要释放默认分配的堆空间
	   AfxGetApp()->m_pszHelpFilePath=_tcsdup(strHelpFile);
	}
	CATCH( CFileException, e )
	{
	   #ifdef _DEBUG
		  afxDump << "File could not be opened " << e->m_cause << "\n";
	   #endif
	}
	END_CATCH
int nResponse;
#ifndef VC_UESOFT
    SHInitExtraControls();
	CMainDialog da;
    m_pMainWnd = &da;
    nResponse=da.DoModal();
#else
CPropertySheet1 ps("水蒸汽性质计算");	
    //CPropertyPageAbout ppa;
	CPropertyPageInput ppi;
	CPropertyPageResult ppr;
	m_pMainWnd = &ps;	
	ps.AddPage(&ppi);
	ps.AddPage(&ppr); 
//	ps.AddPage(&ppa);    
	 nResponse = ps.DoModal();
#endif
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

#if defined(VC_UESOFT)
void CIFC97IFC67App::OnHelp() 
{
	// TODO: Add your command handler code here
	HtmlHelp(this->m_pMainWnd->m_hWnd,this->m_pszHelpFilePath,HH_DISPLAY_TOC,NULL);
}

void CIFC97IFC67App::WinHelp(DWORD dwData, UINT nCmd) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet1*)AfxGetMainWnd())->OnHelp();/////////////////******************xiehui
}
#endif /////set for VC_UESOFT
