double get_ele_ID(double etalep, double ptlep, TH2D* ID, TString sys_error){
	double ptlep_tmp = ptlep;
	if(ptlep>500) ptlep_tmp=499.;
	double lep_ID_scale=-1;
	lep_ID_scale=ID->GetBinContent(ID->FindBin(etalep,ptlep_tmp));
    if(sys_error == "up") lep_ID_scale = lep_ID_scale + ID->GetBinErrorUp(ID->FindBin(etalep,ptlep_tmp));
    if(sys_error == "low") lep_ID_scale = lep_ID_scale - ID->GetBinErrorLow(ID->FindBin(etalep,ptlep_tmp));
	return lep_ID_scale;
}

double get_ele_Reco(double etalep, double ptlep, TH2D* Reco, TString sys_error){
	double ptlep_tmp = ptlep;
	if(ptlep>500) ptlep_tmp=499.;
	double lep_Reco_scale=-1;
	lep_Reco_scale=Reco->GetBinContent(Reco->FindBin(etalep,ptlep_tmp));
    if(sys_error == "up") lep_Reco_scale = lep_Reco_scale + Reco->GetBinErrorUp(Reco->FindBin(etalep,ptlep_tmp));
    if(sys_error == "low") lep_Reco_scale = lep_Reco_scale - Reco->GetBinErrorLow(Reco->FindBin(etalep,ptlep_tmp));
	return lep_Reco_scale;
}

double get_ele_HLT(double etalep, double ptlep, TH2D* HLT, TString sys_error){
    double ptlep_tmp = ptlep;
    if(ptlep>500) ptlep_tmp=499.;
    double lep_HLT_scale=-1;
    lep_HLT_scale=HLT->GetBinContent(HLT->FindBin(etalep,ptlep_tmp));
    if(sys_error == "up") lep_HLT_scale = lep_HLT_scale + HLT->GetBinErrorUp(HLT->FindBin(etalep,ptlep_tmp));
    if(sys_error == "low") lep_HLT_scale = lep_HLT_scale - HLT->GetBinErrorLow(HLT->FindBin(etalep,ptlep_tmp));
    return lep_HLT_scale;
}

double get_photon_ID(double photoneta, double photonet, TH2D* ID_photon, TString sys_error){
    double photonet_tmp = photonet;
    if(photonet>500) photonet_tmp=499.;
	double photon_ID_scale=-1;
	photon_ID_scale=ID_photon->GetBinContent(ID_photon->FindBin(photoneta,photonet_tmp));
    if(sys_error == "up") photon_ID_scale = photon_ID_scale + ID_photon->GetBinErrorUp(ID_photon->FindBin(photoneta,photonet_tmp));
    if(sys_error == "low") photon_ID_scale = photon_ID_scale - ID_photon->GetBinErrorLow(ID_photon->FindBin(photoneta,photonet_tmp));
	return photon_ID_scale;
}
