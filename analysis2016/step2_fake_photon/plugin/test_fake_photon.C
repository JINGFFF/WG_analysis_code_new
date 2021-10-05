#define test_cxx
#include "test_fake_photon.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "ele_channel_scale.C"
#include "muon_channel_scale.C"

double pi =3.1415926;

Double_t delta_R(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
        Double_t dp = phi1-phi2;
        if(fabs(dp) > pi) dp = 2*pi - fabs(dp);
        Double_t dr = sqrt((eta1-eta2)*(eta1-eta2)+dp*dp);
        return dr;
}

   int barrel_Nbins = 128;
   double barrel_sieie_lower = 0.00;
   double barrel_sieie_upper = 0.04;

   int endcap_Nbins = 20;
   double endcap_sieie_lower = 0.01;
   double endcap_sieie_upper = 0.06;

   // barrel histogram
   TH1D* hist_barrel_25to30 = new TH1D("hist_barrel_25to30", "hist_barrel_25to30", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_30to40 = new TH1D("hist_barrel_30to40", "hist_barrel_30to40", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_40to50 = new TH1D("hist_barrel_40to50", "hist_barrel_40to50", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_50to70 = new TH1D("hist_barrel_50to70", "hist_barrel_50to70", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_70to100 = new TH1D("hist_barrel_70to100", "hist_barrel_70to100", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_100to135 = new TH1D("hist_barrel_100to135", "hist_barrel_100to135", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   TH1D* hist_barrel_135to400 = new TH1D("hist_barrel_135to400", "hist_barrel_135to400", barrel_Nbins, barrel_sieie_lower, barrel_sieie_upper);
   // endcap histogram
   TH1D* hist_endcap_25to30 = new TH1D("hist_endcap_25to30", "hist_endcap_25to30", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_30to40 = new TH1D("hist_endcap_30to40", "hist_endcap_30to40", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_40to50 = new TH1D("hist_endcap_40to50", "hist_endcap_40to50", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_50to70 = new TH1D("hist_endcap_50to70", "hist_endcap_50to70", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_70to100 = new TH1D("hist_endcap_70to100", "hist_endcap_70to100", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_100to135 = new TH1D("hist_endcap_100to135", "hist_endcap_100to135", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);
   TH1D* hist_endcap_135to400 = new TH1D("hist_endcap_135to400", "hist_endcap_135to400", endcap_Nbins, endcap_sieie_lower, endcap_sieie_upper);

   Int_t NBINS = 7;
   Double_t edges[8] = {25., 30., 40., 50., 70., 100., 135., 400.};
   TH1F* barrel_photonpt = new TH1F("barrel_photonpt", "barrel_photonpt", 7, edges);
   TH1F* endcap_photonpt = new TH1F("endcap_photonpt", "endcap_photonpt", 7, edges);


void test::hist_Sumw2()
{

   ///// fake lepton
   //h_fake_lepton->Sumw2();

}



void test::endJob() {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();
   hist_barrel_25to30->Write();
   hist_barrel_30to40->Write();
   hist_barrel_40to50->Write();
   hist_barrel_50to70->Write();
   hist_barrel_70to100->Write();
   hist_barrel_100to135->Write();
   hist_barrel_135to400->Write();

   hist_endcap_25to30->Write();
   hist_endcap_30to40->Write();
   hist_endcap_40to50->Write();
   hist_endcap_50to70->Write();
   hist_endcap_70to100->Write();
   hist_endcap_100to135->Write();
   hist_endcap_135to400->Write();

   barrel_photonpt->Write();
   endcap_photonpt->Write();
   fout->Close();
   delete fout;
}

void test::set_for_barrel_and_endcap(TString isbarrel)
{

   if (isbarrel.Contains("barrel")) {
      hoe_cut        = 0.02197;
      chiso_cut_low  = -10;  // -- -10 is the initial value is PKU ntuple
      chiso_cut_high = 1.141;
      nhiso_cut[0]   = 1.189;
      nhiso_cut[1]   = 0.01512;
      nhiso_cut[2]   = 0.00001159;
      phoiso_cut[0]  = 2.08;
      phoiso_cut[1]  = 0.004017;

      photonsc_eta_cut_low  = -1;
      photonsc_eta_cut_high = 1.4442;
   }

   if (isbarrel.Contains("endcap")) {
      hoe_cut        = 0.0326;
      chiso_cut_low  = -10;  // -- -10 is the initial value is PKU ntuple
      chiso_cut_high = 1.051;
      nhiso_cut[0]   = 2.718;
      nhiso_cut[1]   = 0.0117;
      nhiso_cut[2]   = 0.000023;
      phoiso_cut[0]  = 3.867;
      phoiso_cut[1]  = 0.0037;

      photonsc_eta_cut_low  = 1.566;
      photonsc_eta_cut_high = 2.5;
   }

   if (m_template_type.Contains( "fake")){
      chiso_cut_low  = invert_chiso_low;
      chiso_cut_high = invert_chiso_high;
   }


}

void test::hist_Scale()
{
   if(m_type == "mc"){

   hist_barrel_25to30->Scale(1/(p_event - n_event));
   hist_barrel_30to40->Scale(1/(p_event - n_event));
   hist_barrel_40to50->Scale(1/(p_event - n_event));
   hist_barrel_50to70->Scale(1/(p_event - n_event));
   hist_barrel_70to100->Scale(1/(p_event - n_event));
   hist_barrel_100to135->Scale(1/(p_event - n_event));
   hist_barrel_135to400->Scale(1/(p_event - n_event));

   hist_endcap_25to30->Scale(1/(p_event - n_event));
   hist_endcap_30to40->Scale(1/(p_event - n_event));
   hist_endcap_40to50->Scale(1/(p_event - n_event));
   hist_endcap_50to70->Scale(1/(p_event - n_event));
   hist_endcap_70to100->Scale(1/(p_event - n_event));
   hist_endcap_100to135->Scale(1/(p_event - n_event));
   hist_endcap_135to400->Scale(1/(p_event - n_event));

   barrel_photonpt->Scale(1/(p_event - n_event));
   endcap_photonpt->Scale(1/(p_event - n_event));

   }
}

void test::Loop(TDirectory * dir, TTree * tree)
{
   set_cut_value(m_year);
   double btag_cut_value;
   if(m_btag_workpoint == "tight") btag_cut_value = cut_value[0];
   if(m_btag_workpoint == "medium") btag_cut_value = cut_value[1];
   if(m_btag_workpoint == "loose") btag_cut_value = cut_value[2];


   cout<<"LUMI : "<<lumi<<endl<<"btag value cut :  "<<cut_value[1]<<endl;

   Long64_t nbytes = 0, nb = 0;
   set_cut_value(m_year);
   //cout<<cut_value[0]<<" "<<cut_value[1]<<" "<<cut_value[2]<<endl;
   int jentry = 0;
   //p_event = p_event + tree->GetEntries("theWeight>0");
   //n_event = n_event + tree->GetEntries("theWeight<0");
  
   if(!(m_type == "mc")){
      p_event = 1;//p_event + tree->GetEntries("theWeight>0");
      n_event = 100;//n_event + tree->GetEntries("theWeight<0");


   }
   else {
      p_event = p_event + tree->GetEntries("theWeight>0");
      n_event = n_event + tree->GetEntries("theWeight<0");


   }

   TTreeReader fReader ;
   fReader.SetTree("PKUCandidates", dir);
   TTreeReaderValue<Double_t>    hasphoton  = {fReader, "hasphoton"};
   TTreeReaderValue<Int_t>    ngoodmus  = {fReader, "ngoodmus"};
   TTreeReaderValue<Int_t>    ngoodeles  = {fReader, "ngoodeles"};
/*   TTreeReaderValue<Int_t>    jet1hf_orig  = {fReader, "jet1hf_orig"};
   TTreeReaderValue<Int_t>    jet1pf_orig  = {fReader, "jet1pf_orig"};
   TTreeReaderValue<Int_t>    jet2hf_orig  = {fReader, "jet2hf_orig"};
   TTreeReaderValue<Int_t>    jet2pf_orig  = {fReader, "jet2pf_orig"};
   TTreeReaderValue<Double_t>    jet1pt_orig  = {fReader, "jet1pt_orig"};
   TTreeReaderValue<Double_t>    jet1phi_orig  = {fReader, "jet1phi_orig"};
   TTreeReaderValue<Double_t>    jet1eta_orig  = {fReader, "jet1eta_orig"};
   TTreeReaderValue<Double_t>    jet1e_orig  = {fReader, "jet1e_orig"};
   TTreeReaderValue<Double_t>    jet1csv_orig  = {fReader, "jet1csv_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_orig  = {fReader, "jet1deepcsv_probb_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_orig  = {fReader, "jet1deepcsv_probbb_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_orig  = {fReader, "jet1deepcsv_probc_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_orig  = {fReader, "jet1deepcsv_probcc_orig"};
   TTreeReaderValue<Double_t>    jet1icsv_orig  = {fReader, "jet1icsv_orig"};
   TTreeReaderValue<Double_t>    drj1a_orig  = {fReader, "drj1a_orig"};
   TTreeReaderValue<Double_t>    drj1l_orig  = {fReader, "drj1l_orig"};
   TTreeReaderValue<Double_t>    jet2pt_orig  = {fReader, "jet2pt_orig"};
   TTreeReaderValue<Double_t>    jet2phi_orig  = {fReader, "jet2phi_orig"};
   TTreeReaderValue<Double_t>    jet2eta_orig  = {fReader, "jet2eta_orig"};
   TTreeReaderValue<Double_t>    jet2e_orig  = {fReader, "jet2e_orig"};
   TTreeReaderValue<Double_t>    jet2csv_orig  = {fReader, "jet2csv_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_orig  = {fReader, "jet2deepcsv_probb_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_orig  = {fReader, "jet2deepcsv_probbb_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_orig  = {fReader, "jet2deepcsv_probc_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_orig  = {fReader, "jet2deepcsv_probcc_orig"};
   TTreeReaderValue<Double_t>    jet2icsv_orig  = {fReader, "jet2icsv_orig"};
   TTreeReaderValue<Double_t>    drj2a_orig  = {fReader, "drj2a_orig"};
   TTreeReaderValue<Double_t>    drj2l_orig  = {fReader, "drj2l_orig"};
*/   TTreeReaderValue<Float_t>    rawPt  = {fReader, "rawPt"};
   TTreeReaderValue<Int_t>    nevent  = {fReader, "nevent"};
   TTreeReaderValue<Int_t>    run  = {fReader, "run"};
   TTreeReaderValue<Int_t>    ls  = {fReader, "ls"};
   TTreeReaderValue<Int_t>    nVtx  = {fReader, "nVtx"};
   TTreeReaderValue<Double_t>    theWeight  = {fReader, "theWeight"};
   TTreeReaderValue<Double_t>    nump  = {fReader, "nump"};
   TTreeReaderValue<Double_t>    numm  = {fReader, "numm"};
   TTreeReaderValue<Double_t>    npT  = {fReader, "npT"};
   TTreeReaderValue<Int_t>    lep  = {fReader, "lep"};
   TTreeReaderValue<Double_t>    ptVlep  = {fReader, "ptVlep"};
   TTreeReaderValue<Double_t>    ptVlepJEC  = {fReader, "ptVlepJEC"};
   TTreeReaderValue<Double_t>    yVlepJEC  = {fReader, "yVlepJEC"};
   TTreeReaderValue<Double_t>    phiVlepJEC  = {fReader, "phiVlepJEC"};
   TTreeReaderValue<Double_t>    massVlepJEC  = {fReader, "massVlepJEC"};
   TTreeReaderValue<Double_t>    mtVlepJECnew  = {fReader, "mtVlepJECnew"};
   TTreeReaderValue<Double_t>    ptVlepJEC_new  = {fReader, "ptVlepJEC_new"};
   TTreeReaderValue<Double_t>    yVlepJEC_new  = {fReader, "yVlepJEC_new"};
   TTreeReaderValue<Double_t>    phiVlepJEC_new  = {fReader, "phiVlepJEC_new"};
   TTreeReaderValue<Double_t>    massVlepJEC_new  = {fReader, "massVlepJEC_new"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_new  = {fReader, "mtVlepJECnew_new"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JEC_up  = {fReader, "ptVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    yVlepJEC_JEC_up  = {fReader, "yVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JEC_up  = {fReader, "phiVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    massVlepJEC_JEC_up  = {fReader, "massVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JEC_up  = {fReader, "mtVlepJECnew_JEC_up"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JEC_down  = {fReader, "ptVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    yVlepJEC_JEC_down  = {fReader, "yVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JEC_down  = {fReader, "phiVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    massVlepJEC_JEC_down  = {fReader, "massVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JEC_down  = {fReader, "mtVlepJECnew_JEC_down"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JER_up  = {fReader, "ptVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    yVlepJEC_JER_up  = {fReader, "yVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JER_up  = {fReader, "phiVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    massVlepJEC_JER_up  = {fReader, "massVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JER_up  = {fReader, "mtVlepJECnew_JER_up"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JER_down  = {fReader, "ptVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    yVlepJEC_JER_down  = {fReader, "yVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JER_down  = {fReader, "phiVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    massVlepJEC_JER_down  = {fReader, "massVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JER_down  = {fReader, "mtVlepJECnew_JER_down"};
   //TTreeReaderValue<Double_t>    Mla  = {fReader, "Mla"};
   //TTreeReaderValue<Double_t>    Mla_f  = {fReader, "Mla_f"};
   //TTreeReaderValue<Double_t>    Mva  = {fReader, "Mva"};
   //TTreeReaderValue<Double_t>    Mva_f  = {fReader, "Mva_f"};
   TTreeReaderValue<Int_t>    nlooseeles  = {fReader, "nlooseeles"};
   TTreeReaderValue<Int_t>    nloosemus  = {fReader, "nloosemus"};
   TTreeReaderValue<Double_t>    genphoton_pt  = {fReader, "genphoton_pt"};
   TTreeReaderValue<Double_t>    genphoton_eta  = {fReader, "genphoton_eta"};
   TTreeReaderValue<Double_t>    genphoton_phi  = {fReader, "genphoton_phi"};
   TTreeReaderValue<Double_t>    genmuon_pt  = {fReader, "genmuon_pt"};
   TTreeReaderValue<Double_t>    genmuon_eta  = {fReader, "genmuon_eta"};
   TTreeReaderValue<Double_t>    genmuon_phi  = {fReader, "genmuon_phi"};
   TTreeReaderValue<Double_t>    genelectron_pt  = {fReader, "genelectron_pt"};
   TTreeReaderValue<Double_t>    genelectron_eta  = {fReader, "genelectron_eta"};
   TTreeReaderValue<Double_t>    genelectron_phi  = {fReader, "genelectron_phi"};
   TTreeReaderArray<Double_t>    photon_pt  = {fReader, "photon_pt"};
   TTreeReaderArray<Double_t>    photon_eta  = {fReader, "photon_eta"};
   TTreeReaderArray<Double_t>    photon_phi  = {fReader, "photon_phi"};
   TTreeReaderArray<Double_t>    photon_e  = {fReader, "photon_e"};
   TTreeReaderArray<Double_t>    photonsc_eta  = {fReader, "photonsc_eta"};
   TTreeReaderArray<Double_t>    photonsc_phi  = {fReader, "photonsc_phi"};
   TTreeReaderArray<Bool_t>    photon_pev  = {fReader, "photon_pev"};
   TTreeReaderArray<Bool_t>    photon_pevnew  = {fReader, "photon_pevnew"};
   TTreeReaderArray<Bool_t>    photon_ppsv  = {fReader, "photon_ppsv"};
   TTreeReaderArray<Bool_t>    photon_iseb  = {fReader, "photon_iseb"};
   TTreeReaderArray<Bool_t>    photon_isee  = {fReader, "photon_isee"};
   TTreeReaderArray<Double_t>    photon_hoe  = {fReader, "photon_hoe"};
   TTreeReaderArray<Double_t>    photon_sieie  = {fReader, "photon_sieie"};
   TTreeReaderArray<Double_t>    photon_sieie2  = {fReader, "photon_sieie2"};
   TTreeReaderArray<Double_t>    photon_chiso  = {fReader, "photon_chiso"};
   TTreeReaderArray<Double_t>    photon_nhiso  = {fReader, "photon_nhiso"};
   TTreeReaderArray<Double_t>    photon_phoiso  = {fReader, "photon_phoiso"};
   TTreeReaderArray<Int_t>    photon_istrue  = {fReader, "photon_istrue"};
   TTreeReaderArray<Int_t>    photon_isprompt  = {fReader, "photon_isprompt"};
   TTreeReaderArray<Double_t>    photon_drla  = {fReader, "photon_drla"};
   TTreeReaderArray<Double_t>    photon_mla  = {fReader, "photon_mla"};
   TTreeReaderArray<Double_t>    photon_mva  = {fReader, "photon_mva"};
   TTreeReaderValue<Bool_t>    passEleVeto  = {fReader, "passEleVeto"};
   TTreeReaderValue<Bool_t>    passEleVetonew  = {fReader, "passEleVetonew"};
   TTreeReaderValue<Bool_t>    passPixelSeedVeto  = {fReader, "passPixelSeedVeto"};
   TTreeReaderValue<Bool_t>    photonhaspixelseed  = {fReader, "photonhaspixelseed"};
   TTreeReaderValue<Bool_t>    photonhaspixelseed_f  = {fReader, "photonhaspixelseed_f"};
   //TTreeReaderValue<Bool_t>    photonpasseleveto  = {fReader, "photonpasseleveto"};
   //TTreeReaderValue<Bool_t>    photonpasseleveto_f  = {fReader, "photonpasseleveto_f"};
   TTreeReaderValue<Double_t>    photonet  = {fReader, "photonet"};
   TTreeReaderValue<Double_t>    photonet_f  = {fReader, "photonet_f"};
   TTreeReaderValue<Double_t>    photoneta  = {fReader, "photoneta"};
   TTreeReaderValue<Double_t>    photoneta_f  = {fReader, "photoneta_f"};
   TTreeReaderValue<Double_t>    photonphi  = {fReader, "photonphi"};
   TTreeReaderValue<Double_t>    photonphi_f  = {fReader, "photonphi_f"};
   TTreeReaderValue<Double_t>    photone  = {fReader, "photone"};
   TTreeReaderValue<Double_t>    photone_f  = {fReader, "photone_f"};
   TTreeReaderValue<Double_t>    photonsceta  = {fReader, "photonsceta"};
   TTreeReaderValue<Double_t>    photonsceta_f  = {fReader, "photonsceta_f"};
   TTreeReaderValue<Double_t>    photonscphi  = {fReader, "photonscphi"};
   TTreeReaderValue<Double_t>    photonscphi_f  = {fReader, "photonscphi_f"};
   TTreeReaderValue<Double_t>    photonsieie  = {fReader, "photonsieie"};
   TTreeReaderValue<Double_t>    photonsieie_f  = {fReader, "photonsieie_f"};
   TTreeReaderValue<Double_t>    photonphoiso  = {fReader, "photonphoiso"};
   TTreeReaderValue<Double_t>    photonphoiso_f  = {fReader, "photonphoiso_f"};
   TTreeReaderValue<Double_t>    photonchiso  = {fReader, "photonchiso"};
   TTreeReaderValue<Double_t>    photonchiso_f  = {fReader, "photonchiso_f"};
   TTreeReaderValue<Double_t>    photonnhiso  = {fReader, "photonnhiso"};
   TTreeReaderValue<Double_t>    photonnhiso_f  = {fReader, "photonnhiso_f"};
   TTreeReaderValue<Int_t>    iphoton  = {fReader, "iphoton"};
   TTreeReaderValue<Int_t>    iphoton_f  = {fReader, "iphoton_f"};
   //TTreeReaderValue<Double_t>    drla  = {fReader, "drla"};
   //TTreeReaderValue<Double_t>    drla_f  = {fReader, "drla_f"};
   TTreeReaderValue<Int_t>    isTrue  = {fReader, "isTrue"};
   TTreeReaderValue<Int_t>    isprompt  = {fReader, "isprompt"};
   TTreeReaderValue<Int_t>    ispromptLep  = {fReader, "ispromptLep"};
/*   TTreeReaderValue<Int_t>    ak4jet_hf  = {fReader, "ak4jet_hf"};
   TTreeReaderValue<Int_t>    ak4jet_pf  = {fReader, "ak4jet_pf"};
   TTreeReaderValue<Int_t>    jet1hf  = {fReader, "jet1hf"};
   TTreeReaderValue<Int_t>    jet1pf  = {fReader, "jet1pf"};
   TTreeReaderValue<Int_t>    jet2hf  = {fReader, "jet2hf"};
   TTreeReaderValue<Int_t>    jet2pf  = {fReader, "jet2pf"};
   TTreeReaderValue<Int_t>    jet1hf_f  = {fReader, "jet1hf_f"};
   TTreeReaderValue<Int_t>    jet1pf_f  = {fReader, "jet1pf_f"};
   TTreeReaderValue<Int_t>    jet2hf_f  = {fReader, "jet2hf_f"};
   TTreeReaderValue<Int_t>    jet2pf_f  = {fReader, "jet2pf_f"};
   TTreeReaderValue<Int_t>    jet1hf_new  = {fReader, "jet1hf_new"};
   TTreeReaderValue<Int_t>    jet1pf_new  = {fReader, "jet1pf_new"};
   TTreeReaderValue<Int_t>    jet2hf_new  = {fReader, "jet2hf_new"};
   TTreeReaderValue<Int_t>    jet2pf_new  = {fReader, "jet2pf_new"};
   TTreeReaderValue<Int_t>    jet1hf_new_f  = {fReader, "jet1hf_new_f"};
   TTreeReaderValue<Int_t>    jet1pf_new_f  = {fReader, "jet1pf_new_f"};
   TTreeReaderValue<Int_t>    jet2hf_new_f  = {fReader, "jet2hf_new_f"};
   TTreeReaderValue<Int_t>    jet2pf_new_f  = {fReader, "jet2pf_new_f"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_up  = {fReader, "jet1hf_JEC_up"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_up  = {fReader, "jet1pf_JEC_up"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_up  = {fReader, "jet2hf_JEC_up"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_up  = {fReader, "jet2pf_JEC_up"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_up_f  = {fReader, "jet1hf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_up_f  = {fReader, "jet1pf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_up_f  = {fReader, "jet2hf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_up_f  = {fReader, "jet2pf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_down  = {fReader, "jet1hf_JEC_down"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_down  = {fReader, "jet1pf_JEC_down"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_down  = {fReader, "jet2hf_JEC_down"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_down  = {fReader, "jet2pf_JEC_down"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_down_f  = {fReader, "jet1hf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_down_f  = {fReader, "jet1pf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_down_f  = {fReader, "jet2hf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_down_f  = {fReader, "jet2pf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet1hf_JER_up  = {fReader, "jet1hf_JER_up"};
   TTreeReaderValue<Int_t>    jet1pf_JER_up  = {fReader, "jet1pf_JER_up"};
   TTreeReaderValue<Int_t>    jet2hf_JER_up  = {fReader, "jet2hf_JER_up"};
   TTreeReaderValue<Int_t>    jet2pf_JER_up  = {fReader, "jet2pf_JER_up"};
   TTreeReaderValue<Int_t>    jet1hf_JER_up_f  = {fReader, "jet1hf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet1pf_JER_up_f  = {fReader, "jet1pf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet2hf_JER_up_f  = {fReader, "jet2hf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet2pf_JER_up_f  = {fReader, "jet2pf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet1hf_JER_down  = {fReader, "jet1hf_JER_down"};
   TTreeReaderValue<Int_t>    jet1pf_JER_down  = {fReader, "jet1pf_JER_down"};
   TTreeReaderValue<Int_t>    jet2hf_JER_down  = {fReader, "jet2hf_JER_down"};
   TTreeReaderValue<Int_t>    jet2pf_JER_down  = {fReader, "jet2pf_JER_down"};
   TTreeReaderValue<Int_t>    jet1hf_JER_down_f  = {fReader, "jet1hf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet1pf_JER_down_f  = {fReader, "jet1pf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet2hf_JER_down_f  = {fReader, "jet2hf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet2pf_JER_down_f  = {fReader, "jet2pf_JER_down_f"};
   TTreeReaderValue<Double_t>    ak4jet_pt  = {fReader, "ak4jet_pt"};
   TTreeReaderValue<Double_t>    ak4jet_eta  = {fReader, "ak4jet_eta"};
   TTreeReaderValue<Double_t>    ak4jet_phi  = {fReader, "ak4jet_phi"};
   TTreeReaderValue<Double_t>    ak4jet_e  = {fReader, "ak4jet_e"};
   TTreeReaderValue<Double_t>    ak4jet_csv  = {fReader, "ak4jet_csv"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probb  = {fReader, "ak4jet_deepcsv_probb"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probbb  = {fReader, "ak4jet_deepcsv_probbb"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probc  = {fReader, "ak4jet_deepcsv_probc"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probcc  = {fReader, "ak4jet_deepcsv_probcc"};
   TTreeReaderValue<Double_t>    ak4jet_icsv  = {fReader, "ak4jet_icsv"};
   TTreeReaderValue<Double_t>    ak4jet_pt_old  = {fReader, "ak4jet_pt_old"};
   TTreeReaderValue<Double_t>    ak4jet_pt_new  = {fReader, "ak4jet_pt_new"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JEC_up  = {fReader, "ak4jet_pt_JEC_up"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JEC_down  = {fReader, "ak4jet_pt_JEC_down"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JER_up  = {fReader, "ak4jet_pt_JER_up"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JER_down  = {fReader, "ak4jet_pt_JER_down"};
   TTreeReaderValue<Double_t>    ak4jet_e_old  = {fReader, "ak4jet_e_old"};
   TTreeReaderValue<Double_t>    ak4jet_e_new  = {fReader, "ak4jet_e_new"};
   TTreeReaderValue<Double_t>    ak4jet_e_JEC_up  = {fReader, "ak4jet_e_JEC_up"};
   TTreeReaderValue<Double_t>    ak4jet_e_JEC_down  = {fReader, "ak4jet_e_JEC_down"};
   TTreeReaderValue<Double_t>    ak4jet_e_JER_up  = {fReader, "ak4jet_e_JER_up"};
   TTreeReaderValue<Double_t>    ak4jet_e_JER_down  = {fReader, "ak4jet_e_JER_down"};
   TTreeReaderValue<Double_t>    jet1pt  = {fReader, "jet1pt"};
   TTreeReaderValue<Double_t>    jet1pt_new  = {fReader, "jet1pt_new"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_up  = {fReader, "jet1pt_JEC_up"};
   TTreeReaderValue<Double_t>    jet1pt_JER_up  = {fReader, "jet1pt_JER_up"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_down  = {fReader, "jet1pt_JEC_down"};
   TTreeReaderValue<Double_t>    jet1pt_JER_down  = {fReader, "jet1pt_JER_down"};
   TTreeReaderValue<Double_t>    jet1pt_f  = {fReader, "jet1pt_f"};
   TTreeReaderValue<Double_t>    jet1pt_new_f  = {fReader, "jet1pt_new_f"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_up_f  = {fReader, "jet1pt_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1pt_JER_up_f  = {fReader, "jet1pt_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_down_f  = {fReader, "jet1pt_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1pt_JER_down_f  = {fReader, "jet1pt_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1eta  = {fReader, "jet1eta"};
   TTreeReaderValue<Double_t>    jet1eta_new  = {fReader, "jet1eta_new"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_up  = {fReader, "jet1eta_JEC_up"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_down  = {fReader, "jet1eta_JEC_down"};
   TTreeReaderValue<Double_t>    jet1eta_JER_up  = {fReader, "jet1eta_JER_up"};
   TTreeReaderValue<Double_t>    jet1eta_JER_down  = {fReader, "jet1eta_JER_down"};
   TTreeReaderValue<Double_t>    jet1eta_f  = {fReader, "jet1eta_f"};
   TTreeReaderValue<Double_t>    jet1eta_new_f  = {fReader, "jet1eta_new_f"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_up_f  = {fReader, "jet1eta_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_down_f  = {fReader, "jet1eta_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1eta_JER_up_f  = {fReader, "jet1eta_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1eta_JER_down_f  = {fReader, "jet1eta_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1phi  = {fReader, "jet1phi"};
   TTreeReaderValue<Double_t>    jet1phi_new  = {fReader, "jet1phi_new"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_up  = {fReader, "jet1phi_JEC_up"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_down  = {fReader, "jet1phi_JEC_down"};
   TTreeReaderValue<Double_t>    jet1phi_JER_up  = {fReader, "jet1phi_JER_up"};
   TTreeReaderValue<Double_t>    jet1phi_JER_down  = {fReader, "jet1phi_JER_down"};
   TTreeReaderValue<Double_t>    jet1phi_f  = {fReader, "jet1phi_f"};
   TTreeReaderValue<Double_t>    jet1phi_new_f  = {fReader, "jet1phi_new_f"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_up_f  = {fReader, "jet1phi_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_down_f  = {fReader, "jet1phi_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1phi_JER_up_f  = {fReader, "jet1phi_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1phi_JER_down_f  = {fReader, "jet1phi_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1e  = {fReader, "jet1e"};
   TTreeReaderValue<Double_t>    jet1e_new  = {fReader, "jet1e_new"};
   TTreeReaderValue<Double_t>    jet1e_JEC_up  = {fReader, "jet1e_JEC_up"};
   TTreeReaderValue<Double_t>    jet1e_JER_up  = {fReader, "jet1e_JER_up"};
   TTreeReaderValue<Double_t>    jet1e_JEC_down  = {fReader, "jet1e_JEC_down"};
   TTreeReaderValue<Double_t>    jet1e_JER_down  = {fReader, "jet1e_JER_down"};
   TTreeReaderValue<Double_t>    jet1e_f  = {fReader, "jet1e_f"};
   TTreeReaderValue<Double_t>    jet1e_new_f  = {fReader, "jet1e_new_f"};
   TTreeReaderValue<Double_t>    jet1e_JEC_up_f  = {fReader, "jet1e_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1e_JER_up_f  = {fReader, "jet1e_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1e_JEC_down_f  = {fReader, "jet1e_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1e_JER_down_f  = {fReader, "jet1e_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1csv  = {fReader, "jet1csv"};
   TTreeReaderValue<Double_t>    jet1csv_new  = {fReader, "jet1csv_new"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_up  = {fReader, "jet1csv_JEC_up"};
   TTreeReaderValue<Double_t>    jet1csv_JER_up  = {fReader, "jet1csv_JER_up"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_down  = {fReader, "jet1csv_JEC_down"};
   TTreeReaderValue<Double_t>    jet1csv_JER_down  = {fReader, "jet1csv_JER_down"};
   TTreeReaderValue<Double_t>    jet1csv_f  = {fReader, "jet1csv_f"};
   TTreeReaderValue<Double_t>    jet1csv_new_f  = {fReader, "jet1csv_new_f"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_up_f  = {fReader, "jet1csv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1csv_JER_up_f  = {fReader, "jet1csv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_down_f  = {fReader, "jet1csv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1csv_JER_down_f  = {fReader, "jet1csv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb  = {fReader, "jet1deepcsv_probb"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb  = {fReader, "jet1deepcsv_probbb"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc  = {fReader, "jet1deepcsv_probc"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc  = {fReader, "jet1deepcsv_probcc"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_new  = {fReader, "jet1deepcsv_probb_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_new  = {fReader, "jet1deepcsv_probbb_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_new  = {fReader, "jet1deepcsv_probc_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_new  = {fReader, "jet1deepcsv_probcc_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_up  = {fReader, "jet1deepcsv_probb_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_up  = {fReader, "jet1deepcsv_probbb_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_up  = {fReader, "jet1deepcsv_probc_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_up  = {fReader, "jet1deepcsv_probcc_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_down  = {fReader, "jet1deepcsv_probb_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_down  = {fReader, "jet1deepcsv_probbb_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_down  = {fReader, "jet1deepcsv_probc_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_down  = {fReader, "jet1deepcsv_probcc_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_up  = {fReader, "jet1deepcsv_probb_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_up  = {fReader, "jet1deepcsv_probbb_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_up  = {fReader, "jet1deepcsv_probc_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_up  = {fReader, "jet1deepcsv_probcc_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_down  = {fReader, "jet1deepcsv_probb_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_down  = {fReader, "jet1deepcsv_probbb_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_down  = {fReader, "jet1deepcsv_probc_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_down  = {fReader, "jet1deepcsv_probcc_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_f  = {fReader, "jet1deepcsv_probb_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_f  = {fReader, "jet1deepcsv_probbb_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_f  = {fReader, "jet1deepcsv_probc_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_f  = {fReader, "jet1deepcsv_probcc_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_new_f  = {fReader, "jet1deepcsv_probb_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_new_f  = {fReader, "jet1deepcsv_probbb_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_new_f  = {fReader, "jet1deepcsv_probc_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_new_f  = {fReader, "jet1deepcsv_probcc_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_up_f  = {fReader, "jet1deepcsv_probb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_up_f  = {fReader, "jet1deepcsv_probbb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_up_f  = {fReader, "jet1deepcsv_probc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_up_f  = {fReader, "jet1deepcsv_probcc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_down_f  = {fReader, "jet1deepcsv_probb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_down_f  = {fReader, "jet1deepcsv_probbb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_down_f  = {fReader, "jet1deepcsv_probc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_down_f  = {fReader, "jet1deepcsv_probcc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_up_f  = {fReader, "jet1deepcsv_probb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_up_f  = {fReader, "jet1deepcsv_probbb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_up_f  = {fReader, "jet1deepcsv_probc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_up_f  = {fReader, "jet1deepcsv_probcc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_down_f  = {fReader, "jet1deepcsv_probb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_down_f  = {fReader, "jet1deepcsv_probbb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_down_f  = {fReader, "jet1deepcsv_probc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_down_f  = {fReader, "jet1deepcsv_probcc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1icsv  = {fReader, "jet1icsv"};
   TTreeReaderValue<Double_t>    jet1icsv_new  = {fReader, "jet1icsv_new"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_up  = {fReader, "jet1icsv_JEC_up"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_up  = {fReader, "jet1icsv_JER_up"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_down  = {fReader, "jet1icsv_JEC_down"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_down  = {fReader, "jet1icsv_JER_down"};
   TTreeReaderValue<Double_t>    jet1icsv_f  = {fReader, "jet1icsv_f"};
   TTreeReaderValue<Double_t>    jet1icsv_new_f  = {fReader, "jet1icsv_new_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_up_f  = {fReader, "jet1icsv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_up_f  = {fReader, "jet1icsv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_down_f  = {fReader, "jet1icsv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_down_f  = {fReader, "jet1icsv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2pt  = {fReader, "jet2pt"};
   TTreeReaderValue<Double_t>    jet2pt_new  = {fReader, "jet2pt_new"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_up  = {fReader, "jet2pt_JEC_up"};
   TTreeReaderValue<Double_t>    jet2pt_JER_up  = {fReader, "jet2pt_JER_up"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_down  = {fReader, "jet2pt_JEC_down"};
   TTreeReaderValue<Double_t>    jet2pt_JER_down  = {fReader, "jet2pt_JER_down"};
   TTreeReaderValue<Double_t>    jet2pt_f  = {fReader, "jet2pt_f"};
   TTreeReaderValue<Double_t>    jet2pt_new_f  = {fReader, "jet2pt_new_f"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_up_f  = {fReader, "jet2pt_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2pt_JER_up_f  = {fReader, "jet2pt_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_down_f  = {fReader, "jet2pt_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2pt_JER_down_f  = {fReader, "jet2pt_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2eta  = {fReader, "jet2eta"};
   TTreeReaderValue<Double_t>    jet2eta_new  = {fReader, "jet2eta_new"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_up  = {fReader, "jet2eta_JEC_up"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_down  = {fReader, "jet2eta_JEC_down"};
   TTreeReaderValue<Double_t>    jet2eta_JER_up  = {fReader, "jet2eta_JER_up"};
   TTreeReaderValue<Double_t>    jet2eta_JER_down  = {fReader, "jet2eta_JER_down"};
   TTreeReaderValue<Double_t>    jet2phi  = {fReader, "jet2phi"};
   TTreeReaderValue<Double_t>    jet2phi_new  = {fReader, "jet2phi_new"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_up  = {fReader, "jet2phi_JEC_up"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_down  = {fReader, "jet2phi_JEC_down"};
   TTreeReaderValue<Double_t>    jet2phi_JER_up  = {fReader, "jet2phi_JER_up"};
   TTreeReaderValue<Double_t>    jet2phi_JER_down  = {fReader, "jet2phi_JER_down"};
   TTreeReaderValue<Double_t>    jet2phi_f  = {fReader, "jet2phi_f"};
   TTreeReaderValue<Double_t>    jet2phi_new_f  = {fReader, "jet2phi_new_f"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_up_f  = {fReader, "jet2phi_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_down_f  = {fReader, "jet2phi_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2phi_JER_up_f  = {fReader, "jet2phi_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2phi_JER_down_f  = {fReader, "jet2phi_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2eta_f  = {fReader, "jet2eta_f"};
   TTreeReaderValue<Double_t>    jet2eta_new_f  = {fReader, "jet2eta_new_f"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_up_f  = {fReader, "jet2eta_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_down_f  = {fReader, "jet2eta_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2eta_JER_up_f  = {fReader, "jet2eta_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2eta_JER_down_f  = {fReader, "jet2eta_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2e  = {fReader, "jet2e"};
   TTreeReaderValue<Double_t>    jet2e_new  = {fReader, "jet2e_new"};
   TTreeReaderValue<Double_t>    jet2e_JEC_up  = {fReader, "jet2e_JEC_up"};
   TTreeReaderValue<Double_t>    jet2e_JER_up  = {fReader, "jet2e_JER_up"};
   TTreeReaderValue<Double_t>    jet2e_JEC_down  = {fReader, "jet2e_JEC_down"};
   TTreeReaderValue<Double_t>    jet2e_JER_down  = {fReader, "jet2e_JER_down"};
   TTreeReaderValue<Double_t>    jet2e_f  = {fReader, "jet2e_f"};
   TTreeReaderValue<Double_t>    jet2e_new_f  = {fReader, "jet2e_new_f"};
   TTreeReaderValue<Double_t>    jet2e_JEC_up_f  = {fReader, "jet2e_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2e_JER_up_f  = {fReader, "jet2e_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2e_JEC_down_f  = {fReader, "jet2e_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2e_JER_down_f  = {fReader, "jet2e_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2csv  = {fReader, "jet2csv"};
   TTreeReaderValue<Double_t>    jet2csv_new  = {fReader, "jet2csv_new"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_up  = {fReader, "jet2csv_JEC_up"};
   TTreeReaderValue<Double_t>    jet2csv_JER_up  = {fReader, "jet2csv_JER_up"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_down  = {fReader, "jet2csv_JEC_down"};
   TTreeReaderValue<Double_t>    jet2csv_JER_down  = {fReader, "jet2csv_JER_down"};
   TTreeReaderValue<Double_t>    jet2csv_f  = {fReader, "jet2csv_f"};
   TTreeReaderValue<Double_t>    jet2csv_new_f  = {fReader, "jet2csv_new_f"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_up_f  = {fReader, "jet2csv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2csv_JER_up_f  = {fReader, "jet2csv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_down_f  = {fReader, "jet2csv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2csv_JER_down_f  = {fReader, "jet2csv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb  = {fReader, "jet2deepcsv_probb"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb  = {fReader, "jet2deepcsv_probbb"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc  = {fReader, "jet2deepcsv_probc"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc  = {fReader, "jet2deepcsv_probcc"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_new  = {fReader, "jet2deepcsv_probb_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_new  = {fReader, "jet2deepcsv_probbb_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_new  = {fReader, "jet2deepcsv_probc_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_new  = {fReader, "jet2deepcsv_probcc_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_up  = {fReader, "jet2deepcsv_probb_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_up  = {fReader, "jet2deepcsv_probbb_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_up  = {fReader, "jet2deepcsv_probc_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_up  = {fReader, "jet2deepcsv_probcc_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_down  = {fReader, "jet2deepcsv_probb_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_down  = {fReader, "jet2deepcsv_probbb_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_down  = {fReader, "jet2deepcsv_probc_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_down  = {fReader, "jet2deepcsv_probcc_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_up  = {fReader, "jet2deepcsv_probb_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_up  = {fReader, "jet2deepcsv_probbb_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_up  = {fReader, "jet2deepcsv_probc_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_up  = {fReader, "jet2deepcsv_probcc_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_down  = {fReader, "jet2deepcsv_probb_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_down  = {fReader, "jet2deepcsv_probbb_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_down  = {fReader, "jet2deepcsv_probc_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_down  = {fReader, "jet2deepcsv_probcc_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_f  = {fReader, "jet2deepcsv_probb_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_f  = {fReader, "jet2deepcsv_probbb_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_f  = {fReader, "jet2deepcsv_probc_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_f  = {fReader, "jet2deepcsv_probcc_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_new_f  = {fReader, "jet2deepcsv_probb_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_new_f  = {fReader, "jet2deepcsv_probbb_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_new_f  = {fReader, "jet2deepcsv_probc_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_new_f  = {fReader, "jet2deepcsv_probcc_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_up_f  = {fReader, "jet2deepcsv_probb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_up_f  = {fReader, "jet2deepcsv_probbb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_up_f  = {fReader, "jet2deepcsv_probc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_up_f  = {fReader, "jet2deepcsv_probcc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_down_f  = {fReader, "jet2deepcsv_probb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_down_f  = {fReader, "jet2deepcsv_probbb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_down_f  = {fReader, "jet2deepcsv_probc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_down_f  = {fReader, "jet2deepcsv_probcc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_up_f  = {fReader, "jet2deepcsv_probb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_up_f  = {fReader, "jet2deepcsv_probbb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_up_f  = {fReader, "jet2deepcsv_probc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_up_f  = {fReader, "jet2deepcsv_probcc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_down_f  = {fReader, "jet2deepcsv_probb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_down_f  = {fReader, "jet2deepcsv_probbb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_down_f  = {fReader, "jet2deepcsv_probc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_down_f  = {fReader, "jet2deepcsv_probcc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2icsv  = {fReader, "jet2icsv"};
   TTreeReaderValue<Double_t>    jet2icsv_new  = {fReader, "jet2icsv_new"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_up  = {fReader, "jet2icsv_JEC_up"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_up  = {fReader, "jet2icsv_JER_up"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_down  = {fReader, "jet2icsv_JEC_down"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_down  = {fReader, "jet2icsv_JER_down"};
   TTreeReaderValue<Double_t>    jet2icsv_f  = {fReader, "jet2icsv_f"};
   TTreeReaderValue<Double_t>    jet2icsv_new_f  = {fReader, "jet2icsv_new_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_up_f  = {fReader, "jet2icsv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_up_f  = {fReader, "jet2icsv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_down_f  = {fReader, "jet2icsv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_down_f  = {fReader, "jet2icsv_JER_down_f"};
   TTreeReaderValue<Double_t>    drj1a  = {fReader, "drj1a"};
   TTreeReaderValue<Double_t>    drj1a_new  = {fReader, "drj1a_new"};
   TTreeReaderValue<Double_t>    drj1a_JEC_up  = {fReader, "drj1a_JEC_up"};
   TTreeReaderValue<Double_t>    drj1a_JEC_down  = {fReader, "drj1a_JEC_down"};
   TTreeReaderValue<Double_t>    drj1a_JER_up  = {fReader, "drj1a_JER_up"};
   TTreeReaderValue<Double_t>    drj1a_JER_down  = {fReader, "drj1a_JER_down"};
   TTreeReaderValue<Double_t>    drj1a_f  = {fReader, "drj1a_f"};
   TTreeReaderValue<Double_t>    drj1a_new_f  = {fReader, "drj1a_new_f"};
   TTreeReaderValue<Double_t>    drj1a_JEC_up_f  = {fReader, "drj1a_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj1a_JEC_down_f  = {fReader, "drj1a_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj1a_JER_up_f  = {fReader, "drj1a_JER_up_f"};
   TTreeReaderValue<Double_t>    drj1a_JER_down_f  = {fReader, "drj1a_JER_down_f"};
   TTreeReaderValue<Double_t>    drj2a  = {fReader, "drj2a"};
   TTreeReaderValue<Double_t>    drj2a_new  = {fReader, "drj2a_new"};
   TTreeReaderValue<Double_t>    drj2a_JEC_up  = {fReader, "drj2a_JEC_up"};
   TTreeReaderValue<Double_t>    drj2a_JEC_down  = {fReader, "drj2a_JEC_down"};
   TTreeReaderValue<Double_t>    drj2a_JER_up  = {fReader, "drj2a_JER_up"};
   TTreeReaderValue<Double_t>    drj2a_JER_down  = {fReader, "drj2a_JER_down"};
   TTreeReaderValue<Double_t>    drj2a_f  = {fReader, "drj2a_f"};
   TTreeReaderValue<Double_t>    drj2a_new_f  = {fReader, "drj2a_new_f"};
   TTreeReaderValue<Double_t>    drj2a_JEC_up_f  = {fReader, "drj2a_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj2a_JEC_down_f  = {fReader, "drj2a_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj2a_JER_up_f  = {fReader, "drj2a_JER_up_f"};
   TTreeReaderValue<Double_t>    drj2a_JER_down_f  = {fReader, "drj2a_JER_down_f"};
   TTreeReaderValue<Double_t>    drj1l  = {fReader, "drj1l"};
   TTreeReaderValue<Double_t>    drj1l_new  = {fReader, "drj1l_new"};
   TTreeReaderValue<Double_t>    drj1l_JEC_up  = {fReader, "drj1l_JEC_up"};
   TTreeReaderValue<Double_t>    drj1l_JEC_down  = {fReader, "drj1l_JEC_down"};
   TTreeReaderValue<Double_t>    drj1l_JER_up  = {fReader, "drj1l_JER_up"};
   TTreeReaderValue<Double_t>    drj1l_JER_down  = {fReader, "drj1l_JER_down"};
   TTreeReaderValue<Double_t>    drj1l_f  = {fReader, "drj1l_f"};
   TTreeReaderValue<Double_t>    drj1l_new_f  = {fReader, "drj1l_new_f"};
   TTreeReaderValue<Double_t>    drj1l_JEC_up_f  = {fReader, "drj1l_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj1l_JEC_down_f  = {fReader, "drj1l_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj1l_JER_up_f  = {fReader, "drj1l_JER_up_f"};
   TTreeReaderValue<Double_t>    drj1l_JER_down_f  = {fReader, "drj1l_JER_down_f"};
   TTreeReaderValue<Double_t>    drj2l  = {fReader, "drj2l"};
   TTreeReaderValue<Double_t>    drj2l_new  = {fReader, "drj2l_new"};
   TTreeReaderValue<Double_t>    drj2l_JEC_up  = {fReader, "drj2l_JEC_up"};
   TTreeReaderValue<Double_t>    drj2l_JEC_down  = {fReader, "drj2l_JEC_down"};
   TTreeReaderValue<Double_t>    drj2l_JER_up  = {fReader, "drj2l_JER_up"};
   TTreeReaderValue<Double_t>    drj2l_JER_down  = {fReader, "drj2l_JER_down"};
   TTreeReaderValue<Double_t>    drj2l_f  = {fReader, "drj2l_f"};
   TTreeReaderValue<Double_t>    drj2l_new_f  = {fReader, "drj2l_new_f"};
   TTreeReaderValue<Double_t>    drj2l_JEC_up_f  = {fReader, "drj2l_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj2l_JEC_down_f  = {fReader, "drj2l_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj2l_JER_up_f  = {fReader, "drj2l_JER_up_f"};
   TTreeReaderValue<Double_t>    drj2l_JER_down_f  = {fReader, "drj2l_JER_down_f"};
   TTreeReaderValue<Double_t>    Mjj  = {fReader, "Mjj"};
   TTreeReaderValue<Double_t>    Mjj_new  = {fReader, "Mjj_new"};
   TTreeReaderValue<Double_t>    Mjj_JEC_up  = {fReader, "Mjj_JEC_up"};
   TTreeReaderValue<Double_t>    Mjj_JEC_down  = {fReader, "Mjj_JEC_down"};
   TTreeReaderValue<Double_t>    Mjj_JER_up  = {fReader, "Mjj_JER_up"};
   TTreeReaderValue<Double_t>    Mjj_JER_down  = {fReader, "Mjj_JER_down"};
   TTreeReaderValue<Double_t>    Mjj_f  = {fReader, "Mjj_f"};
   TTreeReaderValue<Double_t>    Mjj_new_f  = {fReader, "Mjj_new_f"};
   TTreeReaderValue<Double_t>    Mjj_JEC_up_f  = {fReader, "Mjj_JEC_up_f"};
   TTreeReaderValue<Double_t>    Mjj_JEC_down_f  = {fReader, "Mjj_JEC_down_f"};
   TTreeReaderValue<Double_t>    Mjj_JER_up_f  = {fReader, "Mjj_JER_up_f"};
   TTreeReaderValue<Double_t>    Mjj_JER_down_f  = {fReader, "Mjj_JER_down_f"};
   TTreeReaderValue<Double_t>    deltaeta  = {fReader, "deltaeta"};
   TTreeReaderValue<Double_t>    deltaeta_new  = {fReader, "deltaeta_new"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_up  = {fReader, "deltaeta_JEC_up"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_down  = {fReader, "deltaeta_JEC_down"};
   TTreeReaderValue<Double_t>    deltaeta_JER_up  = {fReader, "deltaeta_JER_up"};
   TTreeReaderValue<Double_t>    deltaeta_JER_down  = {fReader, "deltaeta_JER_down"};
   TTreeReaderValue<Double_t>    deltaeta_f  = {fReader, "deltaeta_f"};
   TTreeReaderValue<Double_t>    deltaeta_new_f  = {fReader, "deltaeta_new_f"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_up_f  = {fReader, "deltaeta_JEC_up_f"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_down_f  = {fReader, "deltaeta_JEC_down_f"};
   TTreeReaderValue<Double_t>    deltaeta_JER_up_f  = {fReader, "deltaeta_JER_up_f"};
   TTreeReaderValue<Double_t>    deltaeta_JER_down_f  = {fReader, "deltaeta_JER_down_f"};
   TTreeReaderValue<Double_t>    zepp  = {fReader, "zepp"};
   TTreeReaderValue<Double_t>    zepp_new  = {fReader, "zepp_new"};
   TTreeReaderValue<Double_t>    zepp_JEC_up  = {fReader, "zepp_JEC_up"};
   TTreeReaderValue<Double_t>    zepp_JEC_down  = {fReader, "zepp_JEC_down"};
   TTreeReaderValue<Double_t>    zepp_JER_up  = {fReader, "zepp_JER_up"};
   TTreeReaderValue<Double_t>    zepp_JER_down  = {fReader, "zepp_JER_down"};
   TTreeReaderValue<Double_t>    zepp_f  = {fReader, "zepp_f"};
   TTreeReaderValue<Double_t>    zepp_new_f  = {fReader, "zepp_new_f"};
   TTreeReaderValue<Double_t>    zepp_JEC_up_f  = {fReader, "zepp_JEC_up_f"};
   TTreeReaderValue<Double_t>    zepp_JEC_down_f  = {fReader, "zepp_JEC_down_f"};
   TTreeReaderValue<Double_t>    zepp_JER_up_f  = {fReader, "zepp_JER_up_f"};
   TTreeReaderValue<Double_t>    zepp_JER_down_f  = {fReader, "zepp_JER_down_f"};
*/   TTreeReaderValue<Double_t>    ptlep1  = {fReader, "ptlep1"};
   TTreeReaderValue<Double_t>    etalep1  = {fReader, "etalep1"};
   TTreeReaderValue<Double_t>    philep1  = {fReader, "philep1"};
   TTreeReaderValue<Double_t>    energylep1  = {fReader, "energylep1"};
/*   TTreeReaderValue<Double_t>    j1metPhi  = {fReader, "j1metPhi"};
   TTreeReaderValue<Double_t>    j1metPhi_new  = {fReader, "j1metPhi_new"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_up  = {fReader, "j1metPhi_JEC_up"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_down  = {fReader, "j1metPhi_JEC_down"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_up  = {fReader, "j1metPhi_JER_up"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_down  = {fReader, "j1metPhi_JER_down"};
   TTreeReaderValue<Double_t>    j1metPhi_f  = {fReader, "j1metPhi_f"};
   TTreeReaderValue<Double_t>    j1metPhi_new_f  = {fReader, "j1metPhi_new_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_up_f  = {fReader, "j1metPhi_JEC_up_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_down_f  = {fReader, "j1metPhi_JEC_down_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_up_f  = {fReader, "j1metPhi_JER_up_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_down_f  = {fReader, "j1metPhi_JER_down_f"};
   TTreeReaderValue<Double_t>    j2metPhi  = {fReader, "j2metPhi"};
   TTreeReaderValue<Double_t>    j2metPhi_new  = {fReader, "j2metPhi_new"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_up  = {fReader, "j2metPhi_JEC_up"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_down  = {fReader, "j2metPhi_JEC_down"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_up  = {fReader, "j2metPhi_JER_up"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_down  = {fReader, "j2metPhi_JER_down"};
   TTreeReaderValue<Double_t>    j2metPhi_f  = {fReader, "j2metPhi_f"};
   TTreeReaderValue<Double_t>    j2metPhi_new_f  = {fReader, "j2metPhi_new_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_up_f  = {fReader, "j2metPhi_JEC_up_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_down_f  = {fReader, "j2metPhi_JEC_down_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_up_f  = {fReader, "j2metPhi_JER_up_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_down_f  = {fReader, "j2metPhi_JER_down_f"};
   TTreeReaderValue<Double_t>    Dphiwajj  = {fReader, "Dphiwajj"};
   TTreeReaderValue<Double_t>    Dphiwajj_f  = {fReader, "Dphiwajj_f"};
   TTreeReaderValue<Double_t>    Dphiwajj_new  = {fReader, "Dphiwajj_new"};
   TTreeReaderValue<Double_t>    Dphiwajj_JEC_up  = {fReader, "Dphiwajj_JEC_up"};
   TTreeReaderValue<Double_t>    Dphiwajj_JEC_down  = {fReader, "Dphiwajj_JEC_down"};
   TTreeReaderValue<Double_t>    Dphiwajj_JER_up  = {fReader, "Dphiwajj_JER_up"};
   TTreeReaderValue<Double_t>    Dphiwajj_JER_down  = {fReader, "Dphiwajj_JER_down"};
*/   TTreeReaderValue<Double_t>    METraw_et  = {fReader, "METraw_et"};
   TTreeReaderValue<Double_t>    METraw_phi  = {fReader, "METraw_phi"};
   TTreeReaderValue<Double_t>    METraw_sumEt  = {fReader, "METraw_sumEt"};
   TTreeReaderValue<Double_t>    genMET  = {fReader, "genMET"};
   TTreeReaderValue<Double_t>    MET_et  = {fReader, "MET_et"};
   TTreeReaderValue<Double_t>    MET_et_new  = {fReader, "MET_et_new"};
   TTreeReaderValue<Double_t>    MET_et_JEC_up  = {fReader, "MET_et_JEC_up"};
   TTreeReaderValue<Double_t>    MET_et_JEC_down  = {fReader, "MET_et_JEC_down"};
   TTreeReaderValue<Double_t>    MET_et_JER_up  = {fReader, "MET_et_JER_up"};
   TTreeReaderValue<Double_t>    MET_et_JER_down  = {fReader, "MET_et_JER_down"};
   TTreeReaderValue<Double_t>    MET_phi  = {fReader, "MET_phi"};
   TTreeReaderValue<Double_t>    MET_phi_new  = {fReader, "MET_phi_new"};
   TTreeReaderValue<Double_t>    MET_phi_JEC_up  = {fReader, "MET_phi_JEC_up"};
   TTreeReaderValue<Double_t>    MET_phi_JEC_down  = {fReader, "MET_phi_JEC_down"};
   TTreeReaderValue<Double_t>    MET_phi_JER_up  = {fReader, "MET_phi_JER_up"};
   TTreeReaderValue<Double_t>    MET_phi_JER_down  = {fReader, "MET_phi_JER_down"};
   TTreeReaderValue<Int_t>    HLT_Ele1  = {fReader, "HLT_Ele1"};
   TTreeReaderValue<Int_t>    HLT_Ele2  = {fReader, "HLT_Ele2"};
   TTreeReaderValue<Int_t>    HLT_Mu1  = {fReader, "HLT_Mu1"};
   TTreeReaderValue<Int_t>    HLT_Mu2  = {fReader, "HLT_Mu2"};
   TTreeReaderValue<Int_t>    HLT_Mu3  = {fReader, "HLT_Mu3"};
   TTreeReaderValue<Double_t>    lumiWeight  = {fReader, "lumiWeight"};
   TTreeReaderValue<Double_t>    pileupWeight  = {fReader, "pileupWeight"};
   TTreeReaderValue<Bool_t>    _passecalBadCalibFilterUpdate  = {fReader, "_passecalBadCalibFilterUpdate"};
   Long64_t maxEntries = fReader.GetEntries(false);
   cout << "Number of events to be analyzed : " << maxEntries << std::endl;

   TString isbarrel;
   double real_weight;

   while (fReader.Next()) {
      if (jentry % 100000 == 0){ 
         int ks = floor(50.*jentry/maxEntries);
         string s1(ks,'>');
         string s2(50-ks,'-');
         cout<<"processing : ["<<"\033[32m"<<s1<<"\033[0m"<<s2<<"]  "<<"\033[33m"<<100.*jentry/maxEntries<<"%  "<<"p_event: "<<p_event<<" n_event: "<<n_event<<"\033[0m"<<endl;
         }
      jentry++;

      // apply selection
      muon_cut     = *HLT_Mu2==1  && abs(*lep) == 13 && *ngoodmus==1 && *ngoodeles==0 && *ptlep1>30. &&fabs(*etalep1)<2.4 && *MET_et_new>30. &&*mtVlepJECnew_new>30.;
      electron_cut = *HLT_Ele2==1 && abs(*lep) == 11 && *ngoodmus==0 && *ngoodeles==1 && *ptlep1>30. &&fabs(*etalep1)<2.5 && *MET_et_new>30. &&*mtVlepJECnew_new>30.;

	  if(m_channel == "muon"){
	     cut = *hasphoton ==1. && muon_cut;
	  }
	  else if(m_channel == "electron"){
		  cut = *hasphoton ==1. && electron_cut;
	  }
	  else{
		  cut = *hasphoton ==1. && (muon_cut || electron_cut);
      }

      if(!cut) continue;

	  // init all SF
      init_sf();
      // cross section SF
      if(m_sample == "WGJJ")          { cross_section_SF=1000.*0.5439   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WGJets")        { cross_section_SF=1000.*192.3    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W0Jets")        { cross_section_SF=1000.*55971.0  *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W1Jets")        { cross_section_SF=1000.*6942.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W2Jets")        { cross_section_SF=1000.*1459.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZJets")         { cross_section_SF=1000.*5765.4   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZG")            { cross_section_SF=1000.*47.46    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "TTGJets")       { cross_section_SF=1000.*4.078    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "TTJets")        { cross_section_SF=1000.*831.76   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_s")          { cross_section_SF=1000.*3.74     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tbarW")      { cross_section_SF=1000.*34.97    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tW")         { cross_section_SF=1000.*34.91    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_t")          { cross_section_SF=1000.*113.3    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tbar")       { cross_section_SF=1000.*67.91    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WW")            { cross_section_SF=1000.*75.8     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WZ")            { cross_section_SF=1000.*27.6     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZZ")            { cross_section_SF=1000.*12.14    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "DY")            { cross_section_SF=1000.*6077.22  *fabs(*theWeight)/(*theWeight); }


      // add scalef for mc
      if(m_type == "mc") {
         // pu weight
         pu_weight_SF = h_pu_weight->GetBinContent(h_pu_weight->GetXaxis()->FindBin(*npT));
         
         // photon medium ID scalefactor
         if(fabs(*photonsceta)<2.5){
            photon_ID_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, " ");
            photon_ID_up_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, "up");
            photon_ID_low_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, "low");
         }
         // add factor for muon
         if(abs(*lep)==13)
         {
            //------muon trigger scalefactor
            muon_HLT_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, " ");
            muon_HLT_up_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, "up");
            muon_HLT_low_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, "low");
            //------muon tight ID  scalefactor
            muon_ID_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, " ");
            muon_ID_up_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, "up");
            muon_ID_low_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, "low");
            //------muon tight ISO scalefactor
            muon_iso_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, " ");
            muon_iso_up_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, "up");
            muon_iso_low_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, "low");
         }
         // add factor for electron
         if(abs(*lep)==11)
         {
            //------electron reco scalefactor
            electron_Reco_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, " ");
            electron_Reco_up_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, "up");
            electron_Reco_low_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, "low");
            //------electron tight ID scalefactor
            electron_ID_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, " ");
            electron_ID_up_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, "up");
            electron_ID_low_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, "low");
            //------electron trigger scalefactor
            electron_HLT_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, " ");
            electron_HLT_up_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, "up");
            electron_HLT_low_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, "low");
         }
         // add factor for jets b, c
         // jet1 : center, jec_up, jec_down, jer_up, jer_down
         // jet1 : center
         //double JET1DEEPCSV      = (*jet1deepcsv_probb_new) + (*jet1deepcsv_probbb_new);
         //double JET2DEEPCSV      = (*jet2deepcsv_probb_new) + (*jet2deepcsv_probbb_new);

         //test
         //btag_jet1_SF     = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "central");
         //btag_jet1_up_SF  = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "up");
         //btag_jet1_low_SF = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "low");

         //btag_jet2_SF     = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "central");
         //btag_jet2_up_SF  = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "up");
         //btag_jet2_low_SF = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "low");

      } //add scalef for mc


      int barrel_flag = -1, endcap_flag = -1;
      int barrel_pt = -1, endcap_pt = -1;

      // for barrel 

      set_for_barrel_and_endcap("barrel");
      for (int barrel_iphoton_index = 0; barrel_iphoton_index < 6; barrel_iphoton_index++){

         if (m_template_type == "true" &&photon_isprompt[barrel_iphoton_index] != 2) continue;
         if (m_template_type == "real_fake" &&photon_isprompt[barrel_iphoton_index] == 2) continue;

         if (photon_mla[barrel_iphoton_index] > 0 && photon_drla[barrel_iphoton_index] > 0.5 &&
             photon_hoe[barrel_iphoton_index] < hoe_cut &&
             photon_nhiso[barrel_iphoton_index] < nhiso_cut[0] + nhiso_cut[1] * photon_pt[barrel_iphoton_index] + nhiso_cut[2] * photon_pt[barrel_iphoton_index] * photon_pt[barrel_iphoton_index] &&
             photon_phoiso[barrel_iphoton_index] < phoiso_cut[0] + phoiso_cut[1] * photon_pt[barrel_iphoton_index] &&
             photon_chiso[barrel_iphoton_index] > chiso_cut_low && photon_chiso[barrel_iphoton_index] < chiso_cut_high &&
             fabs(photonsc_eta[barrel_iphoton_index]) > photonsc_eta_cut_low && fabs(photonsc_eta[barrel_iphoton_index]) < photonsc_eta_cut_high &&
             !photon_ppsv[barrel_iphoton_index])
         {
            if(barrel_pt < photon_pt[barrel_iphoton_index]){

               barrel_pt = photon_pt[barrel_iphoton_index];
               barrel_flag = barrel_iphoton_index;

            }

         }

      } // loop for barrel photon

      // for endcap
      set_for_barrel_and_endcap("endcap");
      for (int endcap_iphoton_index = 0; endcap_iphoton_index < 6; endcap_iphoton_index++){
         if (m_template_type == "true" &&photon_isprompt[endcap_iphoton_index] != 2) continue;
         if (m_template_type == "real_fake" &&photon_isprompt[endcap_iphoton_index] == 2) continue;
         if (photon_mla[endcap_iphoton_index] > 0 && photon_drla[endcap_iphoton_index] > 0.5 &&
             photon_hoe[endcap_iphoton_index] < hoe_cut &&
             photon_nhiso[endcap_iphoton_index] < nhiso_cut[0] + nhiso_cut[1] * photon_pt[endcap_iphoton_index] + nhiso_cut[2] * photon_pt[endcap_iphoton_index] * photon_pt[endcap_iphoton_index] &&
             photon_phoiso[endcap_iphoton_index] < phoiso_cut[0] + phoiso_cut[1] * photon_pt[endcap_iphoton_index] &&
             photon_chiso[endcap_iphoton_index] > chiso_cut_low && photon_chiso[endcap_iphoton_index] < chiso_cut_high &&
             fabs(photonsc_eta[endcap_iphoton_index]) > photonsc_eta_cut_low && fabs(photonsc_eta[endcap_iphoton_index]) < photonsc_eta_cut_high &&
             !photon_ppsv[endcap_iphoton_index])
         {
            if(endcap_pt < photon_pt[endcap_iphoton_index]){

               endcap_pt = photon_pt[endcap_iphoton_index];
               endcap_flag = endcap_iphoton_index;

            }

         }

      } // loop for endcap photon

     // weight and hist fill
      if (m_type == "data") real_weight = 1;
      if (m_type == "mc"  ) real_weight = cross_section_SF * (*lumiWeight) * pu_weight_SF;
      
      if (barrel_flag != -1){
         if (!( *lep ==11 && fabs(photon_mla[barrel_flag] - 91.2) < 10 )){
            if(photon_pt[barrel_flag] > 25 && photon_pt[barrel_flag] <= 30) hist_barrel_25to30->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 30 && photon_pt[barrel_flag] <= 40) hist_barrel_30to40->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 40 && photon_pt[barrel_flag] <= 50) hist_barrel_40to50->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 50 && photon_pt[barrel_flag] <= 70) hist_barrel_50to70->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 70 && photon_pt[barrel_flag] <= 100) hist_barrel_70to100->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 100 && photon_pt[barrel_flag] <= 135) hist_barrel_100to135->Fill(photon_sieie[barrel_flag], real_weight);
            if(photon_pt[barrel_flag] > 135 && photon_pt[barrel_flag] <= 400) hist_barrel_135to400->Fill(photon_sieie[barrel_flag], real_weight);
         }   
      }

      if (endcap_flag != -1){
         if (!( *lep ==11 && fabs(photon_mla[endcap_flag] - 91.2) < 10 )){
            if(photon_pt[endcap_flag] > 25 && photon_pt[endcap_flag] <= 30) hist_endcap_25to30->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 30 && photon_pt[endcap_flag] <= 40) hist_endcap_30to40->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 40 && photon_pt[endcap_flag] <= 50) hist_endcap_40to50->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 50 && photon_pt[endcap_flag] <= 70) hist_endcap_50to70->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 70 && photon_pt[endcap_flag] <= 100) hist_endcap_70to100->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 100 && photon_pt[endcap_flag] <= 135) hist_endcap_100to135->Fill(photon_sieie[endcap_flag], real_weight);
            if(photon_pt[endcap_flag] > 135 && photon_pt[endcap_flag] <= 400) hist_endcap_135to400->Fill(photon_sieie[endcap_flag], real_weight);
         }
      }

      double m_photonsc_eta[6], m_photonsc_phi[6];
      for (int iii = 0; iii<6; iii++){
         m_photonsc_eta[iii] = photonsc_eta[iii];
         m_photonsc_phi[iii] = photonsc_phi[iii];

      }
      //double m_iphoton = iphoton;
      //double m_iphoton_f = iphoton_f;


      double drla   = delta_R(m_photonsc_eta[*iphoton], m_photonsc_phi[*iphoton], *etalep1, *philep1);
      double drla_f = delta_R(m_photonsc_eta[*iphoton_f], m_photonsc_phi[*iphoton_f], *etalep1, *philep1);

      //if(!cut) continue;
      //if(*lep == 11){
      //      if (fabs(photon_mla[*iphoton] - 91.2) < 10) continue;

      //}
      // histogram for fake photon weight
      if(m_template_type == "data"){
         //if( *photonhaspixelseed==0){
         if(*lep == 11){
            if (fabs(photon_mla[*iphoton] - 91.2) < 10) continue;

         }


         if(drla>0.5 && *photonhaspixelseed==0 && *photonet > 25 ){
            if (fabs(*photonsceta) < 1.4442) barrel_photonpt->Fill(*photonet);
            if (fabs(*photonsceta) > 1.566 && fabs(*photonsceta) < 2.5) endcap_photonpt->Fill(*photonet);
         }

      }

      if(m_template_type == "data_fake"){
         //if( *photonhaspixelseed==0){
         if(*lep == 11){
            if (fabs(photon_mla[*iphoton_f] - 91.2) < 10) continue;

         }

         if(drla_f>0.5 && *photonhaspixelseed_f==0 && *photonet_f > 25){
            if (fabs(*photonsceta_f) < 1.4442) barrel_photonpt->Fill(*photonet_f);
            if (fabs(*photonsceta_f) > 1.566 && fabs(*photonsceta_f) < 2.5) endcap_photonpt->Fill(*photonet_f);
         }

      }


      //jentry++;
   }
}
