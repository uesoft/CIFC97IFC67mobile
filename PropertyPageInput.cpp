// IFC97IFC67Dlg.cpp : implementation file
//

//************************************************************
//     作    者：                                            *
//              长沙优易软件开发有限公司(UESoft Corp.) 邝祝芳*
//     文件名称：                                            * 
//                                                           *
//     完成时间：							                    *
//                2005年5月                                  *
//************************************************************
 
#include "stdafx.h"
#include "IFC97IFC67.h"
#include "uewasp.h"
#include "PropertyPageInput.h"
#ifndef VC_UESOFT
#include "MainDialog.h"
#endif


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
IMPLEMENT_DYNAMIC(CPropertyPageInput, CPropertyPage)
/////////////////////////////////////////////////////////////////////////////
// CPropertyPageResult dialog used for App About

BOOL CPropertyPageResult::OnInitDialog()
{
	CDialog::OnInitDialog();
  	return TRUE;
}
CPropertyPageResult::CPropertyPageResult() : CPropertyPage(CPropertyPageResult::IDD)
{
	//{{AFX_DATA_INIT(CPropertyPageResult)
	//}}AFX_DATA_INIT
}
void CPropertyPageResult::OnCancel()
{
	CDialog::OnCancel();
	DestroyWindow();
}

void CPropertyPageResult::OnOK()
{
	CDialog::OnOK();
	DestroyWindow();

}/*
#ifdef VC_UESOFT
void CPropertyPageResult::OnBackMenu()
 {
	 OnBack();
 }
#endif
*/
void CPropertyPageResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertyPageResult)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropertyPageResult, CDialog)
	//{{AFX_MSG_MAP(CPropertyPageResult) 
	#ifdef VC_UESOFT
    //ON_BN_CLICKED(IDC_BACK, OnBack)
    ON_WM_DESTROY()
   // ON_COMMAND(IDR_BACKWND, OnBackMenu)
	#endif
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/*
#ifdef VC_UESOFT
void CPropertyPageResult:: OnBack()
{
	OnCancel();	
}*/
/*void CPropertyPageResult::OnDestroy() 
{
	CPropertyPage::OnDestroy();
	
	//delete this;
	
	// TODO: Add your message handler code here
	
}
#endif*/


/////////////////////////////////////////////////////////////////////////////
// CPropertyPageInput dialog

CPropertyPageInput::CPropertyPageInput()
	: CPropertyPage(CPropertyPageInput::IDD)
{
	//{{AFX_DATA_INIT(CPropertyPageInput)
	m_X = 0.0;
	m_V = 0.0;
	m_T = 0.0;
	m_S = 0.0;
	m_P = 0.0;
	m_H = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	}

void CPropertyPageInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertyPageInput)	
	DDX_Control(pDX, IDC_OUT_List, m_ResultList);
	DDX_Control(pDX, IDC_CHX, m_CHX);
	DDX_Control(pDX, IDC_CHV, m_CHV);
	DDX_Control(pDX, IDC_CHT, m_CHT);
	DDX_Control(pDX, IDC_CHS, m_CHS);
	DDX_Control(pDX, IDC_CHP, m_CHP);
	DDX_Control(pDX, IDC_CHH, m_CHH);
	DDX_Control(pDX, IDC_EdX, m_EDX);
	DDX_Control(pDX, IDC_EdV, m_EDV);
	DDX_Control(pDX, IDC_EdT, m_EDT);
	DDX_Control(pDX, IDC_EdS, m_EDS);
	DDX_Control(pDX, IDC_EdP, m_EDP);
	DDX_Control(pDX, IDC_EdH, m_EDH);
	DDX_Text(pDX, IDC_EdX, m_X);
	DDX_Text(pDX, IDC_EdV, m_V);
	DDX_Text(pDX, IDC_EdT, m_T);
	DDX_Text(pDX, IDC_EdS, m_S);
	DDX_Text(pDX, IDC_EdP, m_P);
	DDX_Text(pDX, IDC_EdH, m_H);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropertyPageInput, CDialog)
	//{{AFX_MSG_MAP(CPropertyPageInput)	
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_Compute, OnCompute)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_CHP, OnChp)
	ON_BN_CLICKED(IDC_CHH, OnChh)
	ON_BN_CLICKED(IDC_CHS, OnChs)
	ON_BN_CLICKED(IDC_CHT, OnCht)
	ON_BN_CLICKED(IDC_CHV, OnChv)
	ON_BN_CLICKED(IDC_CHX, OnChx)
	

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyPageInput message handlers

BOOL CPropertyPageInput::OnInitDialog()
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
#ifndef VC_UESOFT
    	SHSipPreference(this->m_hWnd,SIP_UP); 
#endif
	m_EDX.EnableWindow(FALSE);
	m_EDV.EnableWindow(FALSE);
    m_EDT.EnableWindow(FALSE);
	m_EDS.EnableWindow(FALSE);
	m_EDP.EnableWindow(FALSE);
    m_EDH.EnableWindow(FALSE);
	m_bX=false;
	m_bV=false;
	m_bT=false;
	m_bS=false;
	m_bP=false;
	m_bH=false;
	Index=0;
    stdid=67;

	SWStatus67[1] =_T("IFC67区间1; 低于350℃的未饱和水");
    SWStatus67[2] =_T("IFC67区间2; 过热蒸汽");
    SWStatus67[3] =_T("IFC67区间3; 超临界");
    SWStatus67[4] =_T("IFC67区间4; 亚临界未");
    SWStatus67[5] =_T("IFC67区间5; 亚临界湿蒸汽");
    SWStatus67[6] =_T("IFC67区间6; 低于350℃的湿蒸汽");
    SWStatus67[7] =_T("IFC67区间7; 临 界 点");

    SWStatus97[1] =_T("IAPWS-IF97区间1; 低于350℃的未饱和水");
    SWStatus97[2] =_T("IAPWS-IF97区间2; 过热蒸汽");
    SWStatus97[3] =_T("IAPWS-IF97区间3; 临界点附近水和蒸汽");
    SWStatus97[4] =_T("IAPWS-IF97区间4; 湿蒸汽或饱和线");
    SWStatus97[5] =_T("IAPWS-IF97区间5; 高温低压蒸汽");
#ifndef VC_UESOFT
	CMainDialog *md;
    md=(CMainDialog *)(AfxGetApp()->m_pMainWnd);
  	m_Menu=md->m_Menu; 
#endif
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CPropertyPageInput::OnPaint() 
{

		CDialog::OnPaint();
	
}

void CPropertyPageInput::OnCompute() 
{
// TODO: Add your control notification handler code here
	/*CMainDialog *md;
   md=(CMainDialog *)(Afx);
  	m_Menu=md->m_Menu;*/ 
#ifndef VC_UESOFT
	extern bool RADIO_97;

	
	UINT  chi; 
   m_ResultList.SetWindowText(_T(""));
   
   //if(m_Menu->GetMenuState(IDR_MENU3, MF_BYCOMMAND )==512||m_Menu->GetMenuState(IDR_MENU3, MF_BYCOMMAND )==0)
	 if(RADIO_97)chi=IDC_RADIO_97; 

   else chi=IDC_RADIO_67;/////****************************xiehui  added
#else
m_Menu=AfxGetApp()->m_pMainWnd->GetMenu();
	//if(m_Menu==NULL)AfxMessageBox("hhjhj"); 
	UINT  chi;//=GetCheckedRadioButton(IDC_RADIO_97,IDC_RADIO_67); ////you need renew  *******************************xiehui
   m_ResultList.SetWindowText(_T(""));/////****************************xiehui  added
   
   if(m_Menu->GetMenuState(IDR_MENU3, MF_BYCOMMAND )==512||m_Menu->GetMenuState(IDR_MENU3, MF_BYCOMMAND )==0)chi=IDC_RADIO_97; /////****************************xiehui  added

   else chi=IDC_RADIO_67;/////****************************xiehui  added

#endif

   
	if (chi==IDC_RADIO_97)  
		stdid=97;
	else
		stdid=67;
    SETSTD_WASP(stdid);  //设置计算标准 IF97/IFC67
    
	int *stdid1;
	stdid1=new int;
	GETSTD_WASP(stdid1);  //设置计算标准 IF97/IFC67
	//int stdid2=*stdid1;
	switch (Index) 
	{
	case 1:
		{
	       ComputeP2XYZ(); break;
		}
    case 12:
		{    
	       ComputePT2XYZ(); break;
		}
	case 13:
		{
		   ComputePH2XYZ(); break;
		}
	case 14:
		{ 
		   ComputePS2XYZ(); break;
		}
	case 15:
		{
		  ComputePV2XYZ(); break;
		}
	case 16:
		{
		  ComputePX2XYZ(); break;
		}
	
	case 2:
		{
			ComputeT2XYZ(); break;
		}
    case 23:
		{
			ComputeTH2XYZ(); break;
		}
	case 24:
		{
		    ComputeTS2XYZ(); break;
		}
    case 25:
		{
			ComputeTV2XYZ(); break;
		}
	case 26:
		{
			ComputeTX2XYZ(); break;
		}

	case 34:
		{
			ComputeHS2XYZ();break;
		}
	case 35:
		{
			ComputeHV2XYZ(); break;
		}
    case 36:
		{
			ComputeHX2XYZ(); break;
		}

	case 45:
		{
			ComputeSV2XYZ(); break;
		}
    case 46:
		{
			ComputeSX2XYZ(); break;
		}

	case 56:
		{
			ComputeVX2XYZ(); break;
		}
    default:
		{
		}
	}
 ShowResult();	
   delete stdid1;
}

void CPropertyPageInput::ComputeP2XYZ()
{
    double  P;
	double  *T, t;
   double  *H,h;
   double  *S,s;
   double  *V,v;
   double  *X,x;
   double  *CV,cv;
   double  *CP,cp;
   double  *E,e;
   double  *SSP,ssp;
   double  *KS,ks;
   double  *ETA,eta;
   double  *U,u;
   double  *RAMD,ramd;
   double  *PRN,prn;
   double  *EPS,eps;
   double  *N,n;
   double  *SURFT,surft;

	int *Range, range;
	CString cs0,cs,cs1,cs2,cs3l,cs3g;
	T=&t;
	H=&h;
	S=&s;
	V=&v;
	X=&x;
	CV=&cv;
	CP=&cp;
	E=&e;
	SSP=&ssp;
	KS=&ks;
	ETA=&eta;
	U=&u;
	RAMD=&ramd;
	PRN=&prn;
	EPS=&eps;
	N=&n;
	SURFT=&surft;
	Range=&range;

	m_ResultList.SetWindowText(_T(""));
	cs.Format(IDS_NEWLINE);
	UpdateData(TRUE);	
	P=m_P;   
	
	P2T(P,T,Range);	
	if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
	if (stdid==97) //(*Range==4)
	{
      cs0.Format(SWStatus97[*Range]+_T("\r\n\r\n"));
	}
	else
	{
		if(stdid==67)   //(*Range==5)||(*Range==6)
		{
          cs0.Format(SWStatus67[*Range]+_T("\r\n\r\n"));
		}	
	}

   cs1.Format(IDS_PRESSURE,_T(" "),P);
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);
   CString cs02;
   cs02.Format(IDS_DRYNESS_INCERTITUDE);
   cs2=cs2+cs02;
 
    //计算饱和水参数
	P2L(P,T,H,S,V,X,Range);
    P2CPL(P,CP,Range);    
	P2CVL(P,CV,Range);    
	P2EL(P,E,Range);   	
    P2SSPL(P,SSP,Range);    
	P2KSL(P,KS,Range);   
    P2ETAL(P,ETA,Range);
    P2UL(P,U,Range);   
	P2RAMDL(P,RAMD,Range);    
    P2PRNL(P,PRN,Range);   
    P2EPSL(P,EPS,Range);    
	P2NL(P,2.265E-7,N,Range);  
	cs3l.Format(IDS_WATER_SATURATION_PARAMETER);
    cs=cs0+cs+cs1+cs2+cs3l;
	ShowSaturationParameter(H,S,V,CP,CV,E,SSP, KS,ETA,U, RAMD, PRN,EPS,N, cs);//显示饱和水参数

    //计算饱和汽参数
	P2G(P,T,H,S,V,X,Range);
	P2CPG(P,CP,Range); 
	P2CVG(P,CV,Range);
	P2EG(P,E,Range);
	P2SSPG(P,SSP,Range);
	P2KSG(P,KS,Range);
	P2ETAG(P,ETA,Range);
	P2UG(P,U,Range);
	P2RAMDG(P,RAMD,Range);
	P2PRNG(P,PRN,Range); 
	P2EPSG(P,EPS,Range); 
	P2NG(P,2.265E-7,N,Range);
	cs3g.Format(IDS_SATURATION_VAPOUR_PARAMETER);
	cs=cs+cs3g;
    ShowSaturationParameter(H,S,V,CP,CV,E,SSP, KS,ETA,U, RAMD, PRN,EPS,N, cs);//显示饱和汽参数

   //下面计算亚稳态参数 6.2 Supplementary Equation for the Metastable-Vapor Region
   //by ligb on 2007.08.14
 	PT2MV( P,*T,H, S, V, E,CP, CV,SSP,Range);
   if(*Range>=128)
   {
	  PT2HMV(P,*T,H);
	  PT2SMV(P,*T,S);
	  PT2VMV(P,*T,V);
	  PT2EMV(P,*T,E);
	  PT2CPMV(P,*T,CP);
	  PT2CVMV(P,*T,CV);
	  PT2SSPMV(P,*T,SSP);
	  ShowMetastableSteamParameter(H,S,V,CP,CV,E,SSP, cs);//显示亚稳态蒸参数

   }

	m_ResultList.SetWindowText(cs);///SUBTRACT 2 CHARACTER*/
}

void CPropertyPageInput::ComputePT2XYZ()
{	
   double  P,T;
   double  *H,h;
   double  *S,s;
   double  *V,v;
   double  *X,x;
   double  *CV,cv;
   double  *CP,cp;
   double  *E,e;
   double  *SSP,ssp;
   double  *KS,ks;
   double  *ETA,eta;
   double  *U,u;
   double  *RAMD,ramd;
   double  *PRN,prn;
   double  *EPS,eps;
   double  *N,n;  
   int *Range, range;

//  CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6,cs7,cs8,cs9,cs10,cs11,cs12,cs13,cs14,cs15,cs16,cs17;
   CString  cs0,cs,cs1,cs2;
   Range=&range;
   H=&h;
   S=&s;
   V=&v;
   X=&x;
   CV=&cv;
   CP=&cp;
   E=&e;
   SSP=&ssp;
   KS=&ks;
   ETA=&eta;
   U=&u;
   RAMD=&ramd;
   PRN=&prn;
   EPS=&eps;
   N=&n;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);  
   UpdateData(TRUE);	
   P=m_P;
   T=m_T;   
   cs1.Format(IDS_PRESSURE,_T(" "),P);   
   cs2.Format(IDS_TEMPERATURE,_T(" "),T);   

  // PT2H(P,T,H,Range); 
  PT(P,T,H,S,V,X,Range);

  
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }

   PT2CP(P,T,CP,Range);   
   PT2CV(P,T,CV,Range);   
   PT2E(P,T,E,Range);
   PT2SSP(P,T,SSP,Range);  
   PT2KS(P,T,KS,Range);  
   PT2ETA(P,T,ETA,Range);  
   PT2U(P,T,U,Range);  
   PT2RAMD(P,T,RAMD,Range);    
   PT2PRN(P,T,PRN,Range);  
   PT2EPS(P,T,EPS,Range);  
   PT2N(P,T,2.265E-7,N,Range);
   cs=cs0+cs+cs1+cs2;
   ShowSaturationParameter(H,S,V,CP,CV,E,SSP, KS,ETA,U, RAMD, PRN,EPS,N, cs); 
   //下面计算亚稳态参数 6.2 Supplementary Equation for the Metastable-Vapor Region
   //by ligb on 2007.08.14
  PT2MV( P, T,H, S, V, E,CP, CV,SSP,Range);
  if(*Range>=128)
   {
	  PT2HMV(P,T,H);
	  PT2SMV(P,T,S);
	  PT2VMV(P,T,V);
	  PT2EMV(P,T,E);
	  PT2CPMV(P,T,CP);
	  PT2CVMV(P,T,CV);
	  PT2SSPMV(P,T,SSP);
	  ShowMetastableSteamParameter(H,S,V,CP,CV,E,SSP, cs);

   }

   m_ResultList.SetWindowText(cs);/////SUBTRACT 4 CHARACTER*/

}

void CPropertyPageInput::ComputePH2XYZ()
{
   double P,H;
   double *T,t;
   double *S,s;
   double *V,v;
   double *X,x;
   int   *Range,range;
   double *SSP,ssp;
   double  *CV,cv;
   double  *CP,cp;
   double  *E,e;
   double  *KS,ks;
   double  *ETA,eta;
   double  *U,u;
   double  *RAMD,ramd;
   double  *PRN,prn;
   double  *EPS,eps;
   double  *N,n;  
   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6,cs7;
   T=&t;
   S=&s;
   V=&v;
   X=&x;
   Range=&range;
   SSP=&ssp;
   CV=&cv;
   CP=&cp;
   E=&e;
   KS=&ks;
   ETA=&eta;
   U=&u;
   RAMD=&ramd;
   PRN=&prn;
   EPS=&eps;
   N=&n;
   
   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   
   UpdateData(TRUE);	
   P=m_P;
   H=m_H;

   cs1.Format(IDS_PRESSURE,_T(" "),P);
     
   PH2T(P,H,T,Range);
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T); 
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),H);  
   
   PH2S(P,H,S,Range);  
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);
   
   PH2V(P,H,V,Range);   
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);

   PH2SSP(P,H,SSP,Range);
   cs6.Format(IDS_SPEED_OF_SOUND,_T(" "),*SSP);

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6+cs7;
   m_ResultList.SetWindowText(cs);
/////SUBTRACT 5 CHARACTERS*/


}

void CPropertyPageInput::ComputePS2XYZ()
{/////SUBTRACT 5 CHARACTERS
   double P,S;
   double *T,t;
   double *H,h;
   double *V,v;
   double *X,x;
   int   *Range,range;

   CString cs0, cs,cs1,cs2,cs3,cs4,cs5;
   T=&t;
   H=&h;
   V=&v;
   X=&x;
   Range=&range;

   
   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   
   UpdateData(TRUE);	
   P=m_P;
   S=m_S;

   cs1.Format(IDS_PRESSURE,_T(" "),P);
      
   PS2T(P,S,T,Range);

   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);    

   PS2H(P,S,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
         
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),S);
   
   PS2V(P,S,V,Range);  
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5;

   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputePV2XYZ()
{/////SUBTRACT 5 CHARACTERS
   double P,V;
   double *T,t;
   double *H,h;
   double *S,s;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5;
   T=&t;
   H=&h;
   S=&s;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   
   UpdateData(TRUE);	
   P=m_P;
   V=m_V;

   cs1.Format(IDS_PRESSURE,_T(" "),P);
      
   PV2T(P,V,T,Range); 

   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);
   
   PV2H(P,V,H,Range);   
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
   
    
   PV2S(P,V,S,Range);   
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);  
  
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),V);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputePX2XYZ()
{/////SUBTRACT 5 CHARACTERS
   double P,X;
   double *T,t;
   double *H,h;
   double *S,s;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   T=&t;
   H=&h;
   S=&s;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   

   UpdateData(TRUE);	
   P=m_P;
   X=m_X;

   cs1.Format(IDS_PRESSURE,_T(" "),P);
      
   PX2T(P,X,T,Range); 
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);
   
   PX2H(P,X,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
      
   PX2S(P,X,S,Range);   
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S); 

   PX2V(P,X,V,Range); 
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);
   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeT2XYZ()
{///SUBTRACT 1 CHARACTERS
    double  T;
	double  *P,p;
   double  *H,h;
   double  *S,s;
   double  *V,v;
   double  *X,x;
   double  *CV,cv;
   double  *CP,cp;
   double  *E,e;
   double  *SSP,ssp;
   double  *KS,ks;
   double  *ETA,eta;
   double  *U,u;
   double  *RAMD,ramd;
   double  *PRN,prn;
   double  *EPS,eps;
   double  *N,n;
   double  *SURFT,surft;
   int *Range, range;

   CString cs0,cs1,cs2,cs3,cs3l,cs3g,cs;
	P=&p;	
	H=&h;
	S=&s;
	V=&v;
	X=&x;
	CV=&cv;
	CP=&cp;
	E=&e;
	SSP=&ssp;
	KS=&ks;
	ETA=&eta;
	U=&u;
	RAMD=&ramd;
	PRN=&prn;
	EPS=&eps;
	N=&n;
	SURFT=&surft;
	Range=&range;

	
    m_ResultList.SetWindowText(_T(""));   
    cs.Format(IDS_NEWLINE);
	UpdateData(TRUE);	
	T=m_T;    
	
	T2P(T,P,Range);	

	if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
	if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
	cs1.Format(IDS_TEMPERATURE,_T(" "),T);
    cs2.Format(IDS_PRESSURE,_T(" "),*P);	
    
   CString cs02;
   cs02.Format(IDS_DRYNESS_INCERTITUDE);
   cs2=cs2+cs02;
	
    //计算饱和水参数
	T2L(P,T,H,S,V,X,Range);
  	T2CPL(T,CP,Range);    
	T2CVL(T,CV,Range);    
	T2EL(T,E,Range);   
    T2SSPL(T,SSP,Range);   
	T2KSL(T,KS,Range);   
    T2ETAL(T,ETA,Range);    	
    T2UL(T,U,Range);  
	T2RAMDL(T,RAMD,Range);   
    T2PRNL(T,PRN,Range);    
    T2EPSL(T,EPS,Range);  
	T2NL(T,2.265E-7,N,Range);
    T2SURFT(T,SURFT,Range);     
 	cs3l.Format(IDS_WATER_SATURATION_PARAMETER);
    cs=cs0+cs+cs1+cs2+cs3l;
	ShowSaturationParameter(H,S,V,CP,CV,E,SSP, KS,ETA,U, RAMD, PRN,EPS,N, cs);
    cs3.Format(IDS_SURFACE_TENSION,_T(" "),*SURFT);//表面张力
	//计算饱和汽参数
	T2G(P,T,H,S,V,X,Range);	 
   	T2CPG(T,CP,Range);   
	T2CVG(T,CV,Range);   	
	T2EG(T,E,Range);   
    T2SSPG(T,SSP,Range);    
	T2KSG(T,KS,Range);    
    T2ETAG(T,ETA,Range); 
    T2UG(T,U,Range);    
 	T2RAMDG(T,RAMD,Range);     
    T2PRNG(T,PRN,Range);   
    T2EPSG(T,EPS,Range);  
	T2NG(T,2.265E-7,N,Range);    
	cs3g.Format(IDS_SATURATION_VAPOUR_PARAMETER);
	cs=cs+cs3+cs3g;
	ShowSaturationParameter(H,S,V,CP,CV,E,SSP, KS,ETA,U, RAMD, PRN,EPS,N, cs);
	//计算对应亚稳态蒸汽参数

	PT2MV( *P, T,H, S, V, E,CP, CV,SSP,Range);
	if(*Range>=128)
	{
	  PT2HMV(*P,T,H);
	  PT2SMV(*P,T,S);
	  PT2VMV(*P,T,V);
	  PT2EMV(*P,T,E);
	  PT2CPMV(*P,T,CP);
	  PT2CVMV(*P,T,CV);
	  PT2SSPMV(*P,T,SSP);

	  ShowMetastableSteamParameter(H,S,V,CP,CV,E,SSP, cs);
	}
	m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeTH2XYZ()
{////SUBTRACT 5 CHARACTRS
   double T,H;
   double *P,p;
   double *V,v;
   double *S,s;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   V=&v;
   S=&s;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   
   UpdateData(TRUE);	
   T=m_T;
   H=m_H;

   TH2P(T,H,P,Range);  
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);
     
   cs2.Format(IDS_TEMPERATURE,_T(" "),T);
   
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),H);   
    
   TH2S(T,H,S,Range); 
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);  

   TH2V(T,H,V,Range);   
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);
   
   TH2X(T,H,X,Range);   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeTS2XYZ()
{//SUBTRACT 5 CHARACTERS
   double T,S;
   double *P,p;
   double *V,v;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   V=&v;
   H=&h;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);
   

   UpdateData(TRUE);	
   T=m_T;
   S=m_S;

   TS2P(T,S,P,Range);
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);      
   cs2.Format(IDS_TEMPERATURE,_T(" "),T);    

   TS2H(T,S,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);       
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),S);
   
   TS2V(T,S,V,Range);   
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);   

   TS2X(T,S,X,Range); 
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeTV2XYZ()
{
	///SUBTRACT 5 CHARACTERS
   double T,V;
   double *P,p;
   double *S,s;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   S=&s;
   H=&h;
   X=&x;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   T=m_T;
   V=m_V;

   TV2P(T,V,P,Range);  

   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);    
  
   cs2.Format(IDS_TEMPERATURE,_T(" "),T);    

   TV2H(T,V,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
     
   TV2S(T,V,S,Range);   
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);
      
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),V);
  
   TV2X(T,V,X,Range);   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);
 
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeTX2XYZ()
{///SUBTRACT 5 CHARACTERS
   double T,X;
   double *P,p;
   double *S,s;
   double *H,h;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   S=&s;
   H=&h;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   T=m_T;
   X=m_X;

   TX2P(T,X,P,Range);  
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);
      
   cs2.Format(IDS_TEMPERATURE,_T(" "),T);   

   TX2H(T,X,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
       
   TX2S(T,X,S,Range);   
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);
   
   TX2V(T,X,V,Range);   
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);
   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeHS2XYZ()
{///SUBTRACT 5 CHARACTERS
   double H,S;
   double *P,p;
   double *T,t;
   double *X,x;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   X=&x;
   V=&v;
   Range=&range;

   
   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);

   UpdateData(TRUE);	
   H=m_H;
   S=m_S;

   HS2P(H,S,P,Range);    

   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);
    
   HS2T(H,S,T,Range);   
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);    

   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),H);      
 
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),S);
   
   HS2V(H,S,V,Range);  
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);

   HS2X(H,S,X,Range);   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);

}

void CPropertyPageInput::ComputeHV2XYZ()
{
   double H,V;
   double *P,p;
   double *T,t;
   double *X,x;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   X=&x;
   S=&s;
   Range=&range;

   
   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   H=m_H;
   V=m_V;

   HV2P(H,V,P,Range);  
  
   if (*Range==0)
   {
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
    if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);
   
   
   HV2T(H,V,T,Range);
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);
   
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),H);   
    
   HV2S(H,V,S,Range);
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);  

   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),V);   

   HV2X(H,V,X,Range);
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeHX2XYZ()
{
   double H,X;
   double *P,p;
   double *T,t;
   double *V,v;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   V=&v;
   S=&s;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));  
   cs.Format(IDS_NEWLINE);
   
   UpdateData(TRUE);	
   H=m_H;
   X=m_X;

   HX2P(H,X,P,Range);  
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);   
   
   HX2T(H,X,T,Range);  
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T); 

   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),H); 
    
   HX2S(H,X,S,Range);
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);   

   HX2V(H,X,V,Range);  
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);
   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),X);
   
   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeSV2XYZ()
{
   double S,V;
   double *P,p;
   double *T,t;
   double *H,h;
   double *X,x;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   X=&x;
   Range=&range;
   
   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   S=m_S;
   V=m_V;

   SV2P(S,V,P,Range); 
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);  
   
   SV2T(S,V,T,Range);  
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);  

   SV2H(S,V,H,Range); 
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);  
    
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),S); 

   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),V);
 
   SV2X(S,V,X,Range);   
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),*X);

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
  
}

void CPropertyPageInput::ComputeSX2XYZ()
{
   double S,X;
   double *P,p;
   double *T,t;
   double *H,h;
   double *V,v;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   V=&v;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   S=m_S;
   X=m_X;

   SX2P(S,X,P,Range); 
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE," ",*P);
      
   SX2T(S,X,T,Range);
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);
   
   SX2H(S,X,H,Range); 
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);  
    
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),S);
  
   SX2V(S,X,V,Range);   
   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V); 
  
   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);
}

void CPropertyPageInput::ComputeVX2XYZ()
{
   double V,X;
   double *P,p;
   double *T,t;
   double *H,h;
   double *S,s;
   int   *Range,range;

   CString  cs0,cs,cs1,cs2,cs3,cs4,cs5,cs6;
   P=&p;
   T=&t;
   H=&h;
   S=&s;
   Range=&range;

   m_ResultList.SetWindowText(_T(""));   
   cs.Format(IDS_NEWLINE);   

   UpdateData(TRUE);	
   V=m_V;
   X=m_X;

   VX2P(V,X,P,Range); 
   
   if (*Range==0)
	{
		CString str;
		str.LoadString(IDS_PARAMETER_SLOP_OVER);
		MessageBox(str);
		return;
	}
   if(stdid==97)
   {
	   cs0.Format(SWStatus97[*Range]+_T("\r\n"));
   }
   else
   {
	   cs0.Format(SWStatus67[*Range]+_T("\r\n"));
   }
   cs1.Format(IDS_PRESSURE,_T(" "),*P);
     
   VX2T(V,X,T,Range);  
   cs2.Format(IDS_TEMPERATURE,_T(" "),*T);   

   VX2H(V,X,H,Range);  
   cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);   
   
   VX2S(V,X,S,Range);   
   cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S); 

   cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),V);   

   cs6.Format(IDS_DRYNESS_FRACTION,_T(" "),X);   

   cs=cs0+cs+cs1+cs2+cs3+cs4+cs5+cs6;
   m_ResultList.SetWindowText(cs);

}

int CPropertyPageInput::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CPropertyPageInput::OnChp() 
{
	// TODO: Add your control notification handler code here
	
	if (m_bP==FALSE)
    {	
		m_EDP.EnableWindow(TRUE); 
		m_bP=true;
		if (Index==0)
		{
			Index=1; //P
		}
		if (Index==2)
		{
			Index=12; //PT
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 

		}
		if (Index==3)
		{
			Index=13; //PH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
		if (Index==4)
		{
			Index=14; //PS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE); 
		}
		if (Index==5)
		{
			Index=15; //PV
			m_EDX.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
		if (Index==6)
		{
			Index=16;//PX
			m_EDH.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHH.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 
		}
	}
	else
	{
		m_EDP.EnableWindow(FALSE);
		m_bP=false;
		if (Index==1)
		{
			Index=0;
		}
		if (Index==12)
		{
            Index=2;     //PT

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHH.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==13)
		{
            Index=3;  //PH
			
			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==14)
		{
            Index=4;  //PS
			   

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHH.EnableWindow(true); 
		}
		if (Index==15)
		{
			Index=5;  //PV
			 

			m_CHX.EnableWindow(true);
	        m_CHH.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==16)
		{
			Index=6;  //PX	 		  

			m_CHH.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
	}
}

void CPropertyPageInput::OnChh() 
{
	// TODO: Add your control notification handler code here
	if (m_bH==FALSE)
    {	
		m_EDH.EnableWindow(TRUE); 
		m_bH=true;
		if (Index==0)
		{
			Index=3;   //H
		}
		if (Index==1)
		{
			Index=13; //PH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);   

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE); 

		}
		if (Index==2)
		{
			Index=23;  //TH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE); 
		}
		if (Index==4)
		{
           Index=34;  //HS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=35;  //HV
			m_EDX.EnableWindow(FALSE);
	        m_EDT.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHT.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==6)
		{ 
			Index=36;  //HX
			m_EDT.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHT.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDH.EnableWindow(FALSE);
		m_bH=false;
		if (Index==3)
		{
			Index=0; //H
		}		
		if (Index==13)
		{
			Index=1;  //PH
			//m_EDH.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true); 
		}
		if (Index==23)
		{
			Index=2;  //TH
			//m_EDH.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==34)
		{
            Index=4;  //HS
			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==35)
		{
            Index=5;  //HV
			m_CHX.EnableWindow(true);
	        m_CHT.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
		if (Index==36)
		{
			Index=6;  //HX
			m_CHT.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true); 
		}
	}
}

void CPropertyPageInput::OnChs() 
{
	// TODO: Add your control notification handler code here
	if (m_bS==FALSE)
    {	
		m_EDS.EnableWindow(TRUE); 
		m_bS=true;
		if (Index==0)
		{
			Index=4;  //S
		}
		
		if (Index==1)
		{
			Index=14;  //PS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);   
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);   
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)
		{
			Index=24;  //TS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
         	m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
         	m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=34; //HS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=45; //SV
			m_EDX.EnableWindow(FALSE);
	        m_EDH.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHX.EnableWindow(FALSE);
	        m_CHH.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}	    
	    if (Index==6)
		{
			Index=46; //SX
			m_EDH.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);	
	        m_EDP.EnableWindow(FALSE);  
			
			m_CHH.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);	
	        m_CHP.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDS.EnableWindow(FALSE);
		m_bS=false;
		if (Index==4)
		{
			Index=0; //S
		}
		
		if (Index==14)
		{
			Index=1; //PS
            //m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);   
            m_CHH.EnableWindow(true);
		}
		if (Index==24)
		{
			Index=2; //TS
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
         	m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==34)
		{
			Index=3; //HS
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
		if (Index==45)
		{
           Index=5; //SV
			//m_EDS.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHH.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
		if (Index==46)
		{
			Index=6; //SX
			//m_EDS.EnableWindow(true);

			m_CHH.EnableWindow(true);
	        m_CHV.EnableWindow(true);
            m_CHT.EnableWindow(true);	
	        m_CHP.EnableWindow(true);
		}
	}
}

void CPropertyPageInput::OnCht() 
{
	// TODO: Add your control notification handler code here
	if (m_bT==FALSE)
    {	
		m_EDT.EnableWindow(TRUE); 
		m_bT=true;
		if (Index==0)
		{
			Index=2; //T
		}
		if (Index==1)
		{
			Index=12; //PT
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
            Index=23; //TH
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDP.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHP.EnableWindow(FALSE);  
		}
		if (Index==4)
		{
            Index=24; //TS
			m_EDX.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDP.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHP.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==5)
		{
            Index=25; //TV
			m_EDX.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==6)
		{
			Index=26; //TX
			m_EDP.EnableWindow(FALSE);
	        m_EDV.EnableWindow(FALSE);    
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHP.EnableWindow(FALSE);
	        m_CHV.EnableWindow(FALSE);    
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDT.EnableWindow(FALSE);
		m_bT=false;
		if (Index==2)
		{
			Index=0; //T
		}
		
		if (Index==12)
		{
			Index=1; //PT
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}		
        if (Index==23)
		{
			Index=3; //TH
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHP.EnableWindow(true);
		}
		if (Index==24)
		{
			Index=4; //TS
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHP.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}	
		if (Index==25)
		{
			Index=5; //TV
			//m_EDT.EnableWindow(true);

			m_CHX.EnableWindow(true);
	        m_CHP.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}
		if (Index==26)
		{
			Index=6; //TX
			//m_EDT.EnableWindow(true);

			m_CHP.EnableWindow(true);
	        m_CHV.EnableWindow(true);    
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}		
	}
}

void CPropertyPageInput::OnChv() 
{
	// TODO: Add your control notification handler code here
	if (m_bV==FALSE)
    {	
		m_EDV.EnableWindow(TRUE); 
		m_bV=true;
		if (Index==0)
		{
			Index=5; 
		}
		if (Index==1)
		{
			Index=15; //PV
            m_EDX.EnableWindow(FALSE);	
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);	
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE);	
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)
		{
			Index=25;  //TV
			m_EDX.EnableWindow(FALSE);	
	        m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	
	        m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=35;  //HV
			m_EDX.EnableWindow(FALSE);
            m_EDT.EnableWindow(FALSE);
	        m_EDS.EnableWindow(FALSE);
	        m_EDP.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);
            m_CHT.EnableWindow(FALSE);
	        m_CHS.EnableWindow(FALSE);
	        m_CHP.EnableWindow(FALSE);
    
		}
		if (Index==4)
		{
			Index=45;  //SV
			m_EDX.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHX.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==6)
		{
			Index=56;  //VX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDV.EnableWindow(FALSE);
		m_bV=false;
		if (Index==5)
		{
			Index=0; //V
		}
		if (Index==15)
		{
			Index=1; //PV
            //m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true);	
            m_CHH.EnableWindow(true);
		}
		if (Index==25)
		{
			Index=2; //TV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	
	        m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==35)
		{
			Index=3; //HV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);
            m_CHT.EnableWindow(true);
	        m_CHS.EnableWindow(true);
	        m_CHP.EnableWindow(true);
		}
		if (Index==45)
		{
			Index=4; //SV
			//m_EDV.EnableWindow(true);

			m_CHX.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}	
		if (Index==56)
		{
			Index=6; //VX
			//m_EDV.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}	
	}
}

void CPropertyPageInput::OnChx() 
{
	// TODO: Add your control notification handler code here
	if (m_bX==FALSE)
    {	
		m_EDX.EnableWindow(TRUE); 
		m_bX=true;
		if (Index==0)
		{
			Index=6; //X
		}
		if (Index==1)
		{
			Index=16; //PX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDV.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHV.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==2)  
		{
			Index=26;  //TX
			m_EDV.EnableWindow(FALSE);	        
            m_EDS.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHV.EnableWindow(FALSE);	        
            m_CHS.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==3)
		{
			Index=36;  //HX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDV.EnableWindow(FALSE);

			m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHV.EnableWindow(FALSE);
		}
		if (Index==4)
		{
			Index=46;  //SX
			m_EDV.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

			m_CHV.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
		if (Index==5)
		{
			Index=56;  //VX
			m_EDS.EnableWindow(FALSE);	        
            m_EDT.EnableWindow(FALSE);	        
	        m_EDP.EnableWindow(FALSE);
            m_EDH.EnableWindow(FALSE);

            m_CHS.EnableWindow(FALSE);	        
            m_CHT.EnableWindow(FALSE);	        
	        m_CHP.EnableWindow(FALSE);
            m_CHH.EnableWindow(FALSE);
		}
	}
	else
	{
		m_EDX.EnableWindow(FALSE);
		m_bX=false;
		if (Index==6)
		{
			Index=0; //P
		}
		if (Index==16)
		{
			Index=1;  //PX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHV.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==26)
		{
			Index=2;  //TX
			//m_EDX.EnableWindow(true);

			m_CHV.EnableWindow(true);	        
            m_CHS.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==36)
		{
			Index=3;   //HX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHV.EnableWindow(true);
		}
		if (Index==46)
		{
			Index=4;  //SX
			//m_EDX.EnableWindow(true);

			m_CHV.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
		if (Index==56)
		{
			Index=5;  //VX
			//m_EDX.EnableWindow(true);

			m_CHS.EnableWindow(true);	        
            m_CHT.EnableWindow(true);	        
	        m_CHP.EnableWindow(true);
            m_CHH.EnableWindow(true);
		}
	}
}


void CPropertyPageInput::ShowResult()/////****************************xiehui  added
{
CPropertySheet *ps_t;
#ifndef VC_UESOFT
CMainDialog *md;
md=(CMainDialog *)(AfxGetApp()->m_pMainWnd);
ps_t=(CPropertySheet *)(md->m_pnHwnd);
#else
ps_t=(CPropertySheet *)(AfxGetApp()->m_pMainWnd);
#endif
ps_t->SetActivePage(1);
CPropertyPage *pp_t; 
pp_t=ps_t->GetActivePage();
CEdit *p=(CEdit *)(pp_t->GetDlgItem(IDC_OUT_List_Link));
CRect rt;
 
pp_t->GetClientRect(&rt);
ScreenToClient(&rt);
p->SetWindowPos(p,0,0,rt.Width(),rt.Height(),SWP_DRAWFRAME|SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE);   
CString str; 
m_ResultList.GetWindowText(str);	  
p->SetWindowText(str);    
}
void CPropertyPageInput::ShowSaturationParameter(double* H,double* S,double* V,double* CP,double* CV,
		double* E,double* SSP,double* KS,double*ETA,double* U,double* RAMD,double* PRN,double*EPS,double* N, CString &cs)
{ 
	CString cs3,cs4,cs5,cs6,cs7,cs8,cs9,cs10,cs11,cs12,cs13,cs14,cs15,cs16,cs17;
    cs3.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);	
    cs4.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);	 
    cs5.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);   
    cs6.Format(IDS_SPECIFIC_ISOBAR_HEAT_CAPACITY,_T(" "),*CP);	   
    cs7.Format(IDS_SPECIFIC_ISOCHORIC_HEAT_CAPACITY,_T(" "),*CV);	   
    cs8.Format(IDS_SPECIFIC_INTERNAL_ENERGY,_T(" "),*E);    
    cs9.Format(IDS_SPEED_OF_SOUND,_T(" "),*SSP);	
    cs10.Format(IDS_ISENTROPIC_EXPONENT,_T(" "),*KS);
    cs11.Format(IDS_DYNAMIC_VISCOSITY,_T(" "),*ETA);
    cs12.Format(IDS_KINEMATIC_VISCOSITY,_T(" "),*U);	   
    cs13.Format(IDS_THERMAL_CONDUCTIVITY,_T(" "),*RAMD);	  
    cs14.Format(IDS_PRANDTL_CONSTANT,_T(" "),*PRN);	   
    cs15.Format(IDS_DIELECTRIC_CONSTANT,_T(" "),*EPS);	
    cs16.Format(IDS_WAVELENGTH,0.2265);
	cs17.Format(IDS_REFRACTIVE_INDEX,_T(" "),*N);
	cs=cs+cs3+cs4+cs5+cs6+cs7+cs8+cs9+cs10+cs11+cs12+cs13+cs14+cs15+cs16+cs17;
}

void CPropertyPageInput::ShowMetastableSteamParameter(double* H,double* S,double* V,double* CP,double* CV,double* E,double* SSP,CString &cs)
{
	   CString  cm00,cm18,cm19,cm20,cm21,cm22,cm23,cm24;
       cm00.Format(IDS_METASTABLE_STEAM_PARAMETER);
	   cm18.Format(IDS_SPECIFIC_ENTHALPY,_T(" "),*H);
	   cm19.Format(IDS_SPECIFIC_ENTROPY,_T(" "),*S);
	   cm20.Format(IDS_SPECIFIC_VOLUME,_T(" "),*V);
	   cm21.Format(IDS_SPECIFIC_ISOBAR_HEAT_CAPACITY,_T(" "),*CP);
	   cm22.Format(IDS_SPECIFIC_ISOCHORIC_HEAT_CAPACITY,_T(" "),*CV);
	   cm23.Format(IDS_SPECIFIC_INTERNAL_ENERGY,_T(" "),*E);
	   cm24.Format(IDS_SPEED_OF_SOUND,_T(" "),*SSP);
   
	   cs=cs+cm00+cm18+cm19+cm20+cm21+cm22+cm23+cm24;
}