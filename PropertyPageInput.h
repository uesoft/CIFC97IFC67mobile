// IFC97IFC67Dlg.h : header file
//

//************************************************************
//     作    者：                                            *
//              长沙优易软件开发有限公司(UESoft Corp.) 邝祝芳*
//     文件名称：                                            * 
//                                                           *
//     完成时间：                                            *
//                2005年5月                                  *
//************************************************************

#if !defined(AFX_IFC97IFC67DLG_H__B277CA59_E3D8_4C0D_9D0C_EDE687DBA6DA__INCLUDED_)
#define AFX_IFC97IFC67DLG_H__B277CA59_E3D8_4C0D_9D0C_EDE687DBA6DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////b////////////////////////////////////////////////////////////////////////

class CPropertyPageInput : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPageInput)

// Construction
public:    
	bool m_bX;
	bool m_bV;
	bool m_bS;
	bool m_bH;
	bool m_bT;
	bool m_bP;
	int Index;  
	UINT  stdid;
    CString SWStatus67[8];
	CString SWStatus97[6]; 

	void ComputeVX2XYZ();

	void ComputeSX2XYZ();
	void ComputeSV2XYZ();

	void ComputeHX2XYZ();
	void ComputeHV2XYZ();
	void ComputeHS2XYZ();

	void ComputeTX2XYZ();
	void ComputeTV2XYZ();
	void ComputeTS2XYZ();
	void ComputeTH2XYZ();
	void ComputeT2XYZ();

	void ComputePX2XYZ();
	void ComputePV2XYZ();
	void ComputePS2XYZ();
	void ComputePH2XYZ();
	void ComputePT2XYZ();
	void ComputeP2XYZ();
	
	
	CPropertyPageInput();	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPropertyPageInput)
	enum { IDD = IDD_IFC97IFC67_DIALOG };
	CEdit	m_ResultList;
	CButton	m_CHX;
	CButton	m_CHV;
	CButton	m_CHT;
	CButton	m_CHS;
	CButton	m_CHP;
	CButton	m_CHH;
	CEdit	m_EDX;
	CEdit	m_EDV;
	CEdit	m_EDT;
	CEdit	m_EDS;
	CEdit	m_EDP;
	CEdit	m_EDH;
	CMenu   *m_Menu;
	double	m_X;
	double	m_V;
	double	m_T;
	double	m_S;
	double	m_P;
	double	m_H;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyPageInput)    
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
    void ShowResult();///***********************xiehui added
	void ShowMetastableSteamParameter(double* H,double* S,double* V,double* CP,double* CV,double* E,double* SSP,CString &cs);
	void ShowSaturationParameter(double* H,double* S,double* V,double* CP,double* CV,
		double* E,double* SSP,double* KS,double*ETA,double* U,double* RAMD,double* PRN,double*EPS,double* N, CString &cs);
	// Generated message map functions
	//{{AFX_MSG(CPropertyPageInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();	
public:
	afx_msg void OnCompute();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChp();
	afx_msg void OnChh();
	afx_msg void OnChs();
	afx_msg void OnCht();
	afx_msg void OnChv();
	afx_msg void OnChx();    
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

class CPropertyPageResult : public CPropertyPage
{
public:
	CPropertyPageResult();

// Dialog Data
	//{{AFX_DATA(CPropertyPageResult)
	enum { IDD = IDD_RESULT};
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyPageResult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnCancel();
    virtual void OnOK();
	//}}AFX_VIRTUAL

// Implementation
protected:
virtual BOOL OnInitDialog();
	//{{AFX_MSG(CPropertyPageResult)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_IFC97IFC67DLG_H__B277CA59_E3D8_4C0D_9D0C_EDE687DBA6DA__INCLUDED_)
