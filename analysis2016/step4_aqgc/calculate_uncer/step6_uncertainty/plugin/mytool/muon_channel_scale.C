#include "TGraphAsymmErrors.h"

double get_muon_ID(double etalep, double ptlep, TH2D* ID, TString sys_error){
	double ptlep_tmp=ptlep;
	if(ptlep>110) ptlep_tmp=110.;
//cout<<"ok3.1.1"<<endl;

	double lep_ID_scale=-1;
	lep_ID_scale=ID->GetBinContent(ID->FindBin(fabs(etalep), ptlep_tmp));
//cout<<"ok3.1.2"<<endl;

    if(sys_error == "up") lep_ID_scale = lep_ID_scale + ID->GetBinErrorUp(ID->FindBin(fabs(etalep), ptlep_tmp));
//cout<<"ok3.1.3"<<endl;

    if(sys_error == "low") lep_ID_scale = lep_ID_scale - ID->GetBinErrorLow(ID->FindBin(fabs(etalep), ptlep_tmp));	
	return lep_ID_scale;
}

double get_muon_iso(double etalep, double ptlep, TH2D* iso, TString sys_error){
	double ptlep_tmp=ptlep;
    if(ptlep>110) ptlep_tmp=110.;
    double lep_iso_scale=-1;
	lep_iso_scale=iso->GetBinContent(iso->FindBin(fabs(etalep), ptlep_tmp));
    if(sys_error == "up") lep_iso_scale = lep_iso_scale + iso->GetBinErrorUp(iso->FindBin(fabs(etalep), ptlep_tmp));
    if(sys_error == "low") lep_iso_scale = lep_iso_scale - iso->GetBinErrorLow(iso->FindBin(fabs(etalep), ptlep_tmp));	
    return lep_iso_scale;
}

double get_muon_HLT(double etalep, double ptlep, TH2D* HLT, TString sys_error){
    double ptlep_tmp=ptlep;
    if(ptlep>800) ptlep_tmp=800.;
    double lep_HLT_scale=-1;
    lep_HLT_scale=HLT->GetBinContent(HLT->FindBin(fabs(etalep),ptlep_tmp));
    if(sys_error == "up") lep_HLT_scale = lep_HLT_scale + HLT->GetBinErrorUp(HLT->FindBin(fabs(etalep),ptlep_tmp));
    if(sys_error == "low") lep_HLT_scale = lep_HLT_scale - HLT->GetBinErrorLow(HLT->FindBin(fabs(etalep),ptlep_tmp));
    return lep_HLT_scale;       

}
