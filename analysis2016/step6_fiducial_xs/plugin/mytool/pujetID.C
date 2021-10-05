double pi =3.1415926;

Double_t deta_R(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
        Double_t dp = phi1-phi2;
        if(fabs(dp) > pi) dp = 2*pi - fabs(dp);
        Double_t dr = sqrt((eta1-eta2)*(eta1-eta2)+dp*dp);
        return dr;
}


Double_t get_puIdweight_eff_SF(double genjet_eta[6], double genjet_phi[6], double ak4jet_eta,double ak4jet_phi,double ak4jet_pt, TH2F*h2_eff_mc2017,TH2F*h2_eff_sf2017, TH2F*h2_eff_sf2017_Systuncty, double ak4jet_puId, TString type){
	double DR1=1e4;
	int ip1=-1;
	double MCweight=1,Dataweight=1,puIdweight=1;
	for(int i=0;i<6;i++){
		double DR1_tmp=deta_R(ak4jet_eta,ak4jet_phi,genjet_eta[i],genjet_phi[i]);
		if(DR1_tmp<DR1){
			DR1=DR1_tmp;
			ip1=i;
		}
	}

    int bin_eff = h2_eff_mc2017->FindBin(ak4jet_pt,ak4jet_eta);
    double MCweight_eff = h2_eff_mc2017->GetBinContent(bin_eff);
    double Dataweight_eff_sf = h2_eff_sf2017->GetBinContent(bin_eff);
    double Dataweight_eff_sys = h2_eff_sf2017_Systuncty->GetBinContent(bin_eff);

	if(DR1<0.4 && ak4jet_pt<50){
		int bin=h2_eff_mc2017->FindBin(ak4jet_pt,ak4jet_eta);
		if(ak4jet_puId==1){
			MCweight = MCweight*h2_eff_mc2017->GetBinContent(bin);
			if(type == "center") Dataweight=Dataweight * MCweight_eff * Dataweight_eff_sf;
            if(type == "up")     Dataweight=Dataweight * MCweight_eff * (Dataweight_eff_sf + Dataweight_eff_sys);
            if(type == "down")   Dataweight=Dataweight * MCweight_eff * (Dataweight_eff_sf - Dataweight_eff_sys);

		}
		else{
            MCweight = MCweight*(1 - h2_eff_mc2017->GetBinContent(bin));
            if(type == "center") Dataweight=Dataweight * (1 - MCweight_eff * Dataweight_eff_sf);
            if(type == "up")     Dataweight=Dataweight * (1 - MCweight_eff * (Dataweight_eff_sf + Dataweight_eff_sys));
            if(type == "down")   Dataweight=Dataweight * (1 - MCweight_eff * (Dataweight_eff_sf - Dataweight_eff_sys));
		}
	}

	else{
		MCweight=1;
		Dataweight=1;
	}
//cout<<ak4jet_puId<<" "<<DR1<<" "<<ak4jet_pt<<" "<<MCweight<<Dataweight<<endl;
	if(MCweight!=0) puIdweight=Dataweight/MCweight;
	else puIdweight=1;
	return puIdweight;
}

Double_t get_puIdweight_mistag_SF(double genjet_eta[6], double genjet_phi[6], double ak4jet_eta,double ak4jet_phi,double ak4jet_pt,TH2F*h2_eff_mc2017,TH2F*h2_eff_sf2017, TH2F*h2_eff_sf2017_Systuncty, double ak4jet_puId, TString type){
    double DR1=1e4;
    int ip1=-1;
    double MCweight=1,Dataweight=1,puIdweight=1;
    for(int i=0;i<6;i++){
        double DR1_tmp=deta_R(ak4jet_eta,ak4jet_phi,genjet_eta[i],genjet_phi[i]);
        if(DR1_tmp<DR1){
            DR1=DR1_tmp;
            ip1=i;
        }
    }

    int bin_eff = h2_eff_mc2017->FindBin(ak4jet_pt,ak4jet_eta);
    double MCweight_eff = h2_eff_mc2017->GetBinContent(bin_eff);
    double Dataweight_eff_sf = h2_eff_sf2017->GetBinContent(bin_eff);
    double Dataweight_eff_sys = h2_eff_sf2017_Systuncty->GetBinContent(bin_eff);

    if(DR1>0.4 && ak4jet_pt<50){
        int bin=h2_eff_mc2017->FindBin(ak4jet_pt,ak4jet_eta);
        if(ak4jet_puId==1){
            MCweight = MCweight*h2_eff_mc2017->GetBinContent(bin);
            if(type == "center") Dataweight=Dataweight * MCweight_eff * Dataweight_eff_sf;
            if(type == "up")     Dataweight=Dataweight * MCweight_eff * (Dataweight_eff_sf + Dataweight_eff_sys);
            if(type == "down")   Dataweight=Dataweight * MCweight_eff * (Dataweight_eff_sf - Dataweight_eff_sys);

//cout<<"mistag: "<<ak4jet_puId<<" "<<MCweight_eff<<" "<<Dataweight_eff_sf<<" "<<Dataweight_eff_sys<<" "<<Dataweight/MCweight<<endl;
        }
        else{
            MCweight = MCweight*(1 - h2_eff_mc2017->GetBinContent(bin));
            if(type == "center") Dataweight=Dataweight * (1 - MCweight_eff * Dataweight_eff_sf);
            if(type == "up")     Dataweight=Dataweight * (1 - MCweight_eff * (Dataweight_eff_sf + Dataweight_eff_sys));
            if(type == "down")   Dataweight=Dataweight * (1 - MCweight_eff * (Dataweight_eff_sf - Dataweight_eff_sys));
//cout<<"mistag: "<<ak4jet_puId<<" "<<MCweight_eff<<" "<<Dataweight_eff_sf<<" "<<Dataweight_eff_sys<<" "<<Dataweight/MCweight<<endl;

        }
    }

    else{
//cout<<"mistag: "<<ak4jet_puId<<" "<<MCweight_eff<<" "<<Dataweight_eff_sf<<" "<<Dataweight_eff_sys<<" "<<Dataweight/MCweight<<endl;

        MCweight=1;
        Dataweight=1;
    }

    if(MCweight!=0) puIdweight=Dataweight/MCweight;
    else puIdweight=1;
    return puIdweight;
}

