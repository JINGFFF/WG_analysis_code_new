bool pass_gen_signal_region_cuts( TString channel, int genlep, double genlep1pt, double genlep1eta, double genphotonet,
                                  double genjet1pt, double genjet2pt, double genjet1eta, double genjet2eta,
                                  double genMET,
                                  double gendrla1, double gendrj1a, double gendrj2a, double gendrj1l, double gendrj2l,
                                  double genMjj, double gendetajj)
{
   bool cut1 = false, cut2 = false, cut3 = false;

   if(channel == "muon") {
      cut1 = abs(genlep)==13 && genlep1pt>30. && fabs(genlep1eta)<2.4;
   }
   if(channel == "electron") {
      cut1 = abs(genlep)==11 && genlep1pt>30. && fabs(genlep1eta)<2.5;
   }

   cut2 = genphotonet>25. 
          && genjet1pt>40 && genjet2pt>30 
          && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
          && genMET>30.
          && gendrla1>0.5 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5
          ;

   cut3 = genMjj >500 
          && gendetajj>2.5
          ;

   bool cut = cut3&&cut2&&cut1;
   return cut;

}


bool pass_gen_control_region_cuts( TString channel, int genlep, double genlep1pt, double genlep1eta, double genphotonet,
                                  double genjet1pt, double genjet2pt, double genjet1eta, double genjet2eta,
                                  double genMET,
                                  double gendrla1, double gendrj1a, double gendrj2a, double gendrj1l, double gendrj2l,
                                  double genMjj, double gendetajj)
{
   bool cut1 = false, cut2 = false, cut3 = false;

   if(channel == "muon") {
      cut1 = abs(genlep)==13 && genlep1pt>30. && fabs(genlep1eta)<2.4;
   }
   if(channel == "electron") {
      cut1 = abs(genlep)==11 && genlep1pt>30. && fabs(genlep1eta)<2.5;
   }

   cut2 = genphotonet>25.
          && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
          && genMET>30.
          && gendrla1>0.5 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5;

   cut3 = genMjj < 500 && genMjj > 200;

   bool cut = cut1 && cut2 && cut3;
   return cut;

}

bool pass_signal_region_cuts( TString channel, int fill_HLT, int fill_lep, double fill_ptlep1, double fill_etalep1, int fill_ngoodmus, int fill_ngoodeles, 
                              int fill_nloosemus, int fill_nlooseeles, bool fill_photonhaspixelseed, double fill_photonet, double fill_Mla, 
                              double fill_jet1pt, double fill_jet1eta, double fill_jet2pt, double fill_jet2eta, double fill_MET_et, double fill_mtVlepJECnew,
                              double fill_drla, double fill_drj1l, double fill_drj2l, double fill_drj1a, double fill_drj2a,
                              double fill_j1metPhi, double fill_j2metPhi, double fill_jet1deepcsv, double fill_jet2deepcsv,
                              double fill_Mjj, double fill_Mva, double fill_deltaeta, double fill_Dphiwajj, double fill_zepp, double btag_cut_value)
{
   bool cut1 = false, cut2 = false, cut3 = false, cut_m = false, cut_e = false;
   cut_m = fill_HLT==1 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4
             && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1;
   cut_e = fill_HLT==1 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5
             && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1 && fabs(fill_Mla - 91.2) > 10;
   if(channel == "muon") {
      cut1 = cut_m;
   }
   if(channel == "electron") {
      cut1 = cut_e; 
   }
   if(channel == "all") {
      cut1 = cut_e || cut_m;                                                                         
   }


   cut2 = fill_photonhaspixelseed==0 && fill_photonet>25. && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7 
          && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7 && fill_MET_et>30. && fill_mtVlepJECnew>30 
          && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5 
          && fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5 
          && fill_jet1deepcsv < btag_cut_value && fill_jet2deepcsv < btag_cut_value;

   cut3 = fill_Mjj>500. && fill_Mva > 100. 
          && fill_deltaeta > 2.5 
          && fill_Dphiwajj > 2.0 && fill_zepp < 1.2
          ;
   
   bool cut = cut1 && cut2 && cut3;
   return cut;

}

bool pass_control_region_cuts( TString channel, int fill_HLT, int fill_lep, double fill_ptlep1, double fill_etalep1, int fill_ngoodmus, int fill_ngoodeles,
                              int fill_nloosemus, int fill_nlooseeles, bool fill_photonhaspixelseed, double fill_photonet, double fill_Mla,
                              double fill_jet1pt, double fill_jet1eta, double fill_jet2pt, double fill_jet2eta, double fill_MET_et, double fill_mtVlepJECnew,
                              double fill_drla, double fill_drj1l, double fill_drj2l, double fill_drj1a, double fill_drj2a,
                              double fill_j1metPhi, double fill_j2metPhi, double fill_jet1deepcsv, double fill_jet2deepcsv,
                              double fill_Mjj, double fill_Mva, double fill_deltaeta, double fill_Dphiwajj, double fill_zepp, double btag_cut_value)
{
   bool cut1 = false, cut2 = false, cut3 = false;
   if(channel == "muon") {
      cut1 = fill_HLT==1 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4
             && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1;
   }
   if(channel == "electron") {
      cut1 = fill_HLT==1 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5
             && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1 && fabs(fill_Mla - 91.2) > 10;
   }

   cut2 = fill_photonhaspixelseed==0 && fill_photonet>25. && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7
          && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7 && fill_MET_et>30. && fill_mtVlepJECnew>30
          && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
          && fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
          && fill_jet1deepcsv < btag_cut_value && fill_jet2deepcsv < btag_cut_value;

   cut3 = fill_Mjj >200 && fill_Mjj<500.;

   bool cut = cut1 && cut2 && cut3;
   return cut;

}

bool pass_aqgc_region_cuts( TString channel, int fill_HLT, int fill_lep, double fill_ptlep1, double fill_etalep1, int fill_ngoodmus, int fill_ngoodeles,
                              int fill_nloosemus, int fill_nlooseeles, bool fill_photonhaspixelseed, double fill_photonet, double fill_Mla,
                              double fill_jet1pt, double fill_jet1eta, double fill_jet2pt, double fill_jet2eta, double fill_MET_et, double fill_mtVlepJECnew,
                              double fill_drla, double fill_drj1l, double fill_drj2l, double fill_drj1a, double fill_drj2a,
                              double fill_j1metPhi, double fill_j2metPhi, double fill_jet1deepcsv, double fill_jet2deepcsv,
                              double fill_Mjj, double fill_Mva, double fill_deltaeta, double fill_Dphiwajj, double fill_zepp, double btag_cut_value)
{
   bool cut1 = false, cut2 = false, cut3 = false;
   if(channel == "muon") {
      cut1 = fill_HLT==1 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4
             && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1;
   }
   if(channel == "electron") {
      cut1 = fill_HLT==1 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5
             && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1 && fabs(fill_Mla - 91.2) > 10;
   }

   cut2 = fill_photonhaspixelseed==0 && fill_photonet>100. && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7
          && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7 && fill_MET_et>30. && fill_mtVlepJECnew>30
          && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
          && fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
          && fill_jet1deepcsv < btag_cut_value && fill_jet2deepcsv < btag_cut_value;

   cut3 = fill_Mjj >800 && fill_Mva > 100. && fill_deltaeta > 2.5;

   bool cut = cut1 && cut2 && cut3;
   return cut;

}

