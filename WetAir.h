//WetAir.h

//************************************************************
//     ��    �ߣ�                                            *
//              ��ɳ��������������޹�˾(UESoft Corp.) �����*
//     �ļ����ƣ�                                            * 
//                DLL�ⲿ�ӿ�(ʪ�������ʼ�����ʪͼ��̬���ӿ�)*
//                Psychrometric charts(��ʪͼ)���㶯̬���ӿ� *
//     ���ʱ�䣺                                            *
//                2006��5��                                  *
//************************************************************ 

//�������������
typedef struct GasData
{
	short iSEQ;//gas sequence number
	char* cName;//gas name,e.g. H2,AIR,etc.
	double fMolecular_Weigh;//gas molecular weight,kg/kmol
	//Molar Specific Heats formula coefficient of true Gases
	//at constant pressure are as follows
	double a0;//temperature coefficient 
	double a1;//temperature coefficient 
	double a2;//temperature coefficient 
	double a3;//temperature coefficient 
	double fMinTemp;//lower temperature range
	double fMaxTemp;//upper temperature range
	double fMaxError;//max error of specific heat 
} mGasData;


extern "C" extern "C" double _stdcall  WetAir_GetRva();

extern "C" void _stdcall  WetAir_SETSTD_WASP(int  STDID);//Ϊʪ���������趨ˮ������ʽIF97/IFC-67
extern "C" void _stdcall  WetAir_GETSTD_WASP(int  *STDID);

extern "C" void _stdcall  WetAir_SETSTD_WetBulbSurface_AirVelocity(double fWetBulbSurface_AirVelocity);
extern "C" void _stdcall  WetAir_SETSTD_atmosphere_pressure(double fLocalAtmospherePressure);
extern "C" void _stdcall  WetAir_GETSTD_atmosphere_pressure(double fLocalAtmospherePressure);

extern "C" short _stdcall  WetAir_GetIndex(char* cName);
extern "C" double _stdcall  WetAir_GetRva();
extern "C" double _stdcall  WetAir_GetCp(short i,double T);
extern "C" double _stdcall  WetAir_GetEnthalpy(short i,double T);
extern "C" double _stdcall  WetAir_D2P(double d);
extern "C" double _stdcall  WetAir_P2D(double P);
extern "C" double _stdcall  WetAir_GetEnthalpy_wetair(double T,double W);
//��֪�����¶�t(��)��ʪ���¶�tw(��)����ˮ����ѹP(MPa)
extern "C" double _stdcall  WetAir_TT2P(double T, double Tw, double phi1);
//��֪�����¶�t(��)�;��ȱ����¶�tw(��)�������ʪ��D(kg/kg.dry)
extern "C" double _stdcall  WetAir_TT2D(double T, double Tw, double phi1);

