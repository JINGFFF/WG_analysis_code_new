#define test_cxx
#include "test.h"
#include <TH2.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include "ele_channel_scale.C"
#include "muon_channel_scale.C"
double Pi =3.1415926;

TH2D* h_fake_lepton;

void test::sethist(){
   Int_t n_pt_bin, n_eta_bin;
   if(m_channel == "electron"){
      n_pt_bin   = 2;
      n_eta_bin  = 5;
      Double_t pt_bin[3]  = {30, 40, 50};
      Double_t eta_bin[6] = {0, 0.5, 1.0, 1.5, 2.0, 2.5};
      h_fake_lepton = new TH2D("h","h", n_eta_bin, eta_bin, n_pt_bin, pt_bin);
      h_fake_lepton->SetXTitle("#eta");
      h_fake_lepton->SetYTitle("p^{T}");
   }
   if(m_channel == "muon"){
      n_pt_bin   = 3;
      n_eta_bin  = 5;
      Double_t pt_bin[4]  = {25, 30, 40, 50};
      Double_t eta_bin[6] = {0, 0.5, 1.0, 1.5, 2.0, 2.5};
      h_fake_lepton = new TH2D("h","h", n_eta_bin, eta_bin, n_pt_bin, pt_bin);
      h_fake_lepton->SetXTitle("#eta");
      h_fake_lepton->SetYTitle("p^{T}");
   }


}

void test::endJob() {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();
   h_fake_lepton->Write();
   fout->Close();
   delete fout;
}

void test::hist_Sumw2()
{
   h_fake_lepton->Sumw2();

}

void test::hist_Scale()
{
   if(m_type == "mc"){
         h_fake_lepton->Scale(1/(p_event - n_event));
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
   int nevent_pass = 0;

   Long64_t nbytes = 0, nb = 0;
   set_cut_value(m_year);
   //cout<<cut_value[0]<<" "<<cut_value[1]<<" "<<cut_value[2]<<endl;
   int jentry = 0;

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
   TTreeReaderValue<Int_t>    ngoodmus  = {fReader, "ngoodmus"};
   TTreeReaderValue<Int_t>    ngoodeles  = {fReader, "ngoodeles"};
   TTreeReaderValue<Int_t>    jet1hf_orig  = {fReader, "jet1hf_orig"};
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
   TTreeReaderValue<Int_t>    nevent  = {fReader, "nevent"};
   TTreeReaderValue<Int_t>    run  = {fReader, "run"};
   TTreeReaderValue<Int_t>    ls  = {fReader, "ls"};
   //TTreeReaderValue<Int_t>    nVtx  = {fReader, "nVtx"};
   TTreeReaderValue<Double_t>    theWeight  = {fReader, "theWeight"};
   TTreeReaderValue<Double_t>    ptlep1  = {fReader, "ptlep1"};
   TTreeReaderValue<Double_t>    etalep1  = {fReader, "etalep1"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_new  = {fReader, "mtVlepJECnew_new"};
   TTreeReaderValue<Double_t>    mtVlepJECnew  = {fReader, "mtVlepJECnew"};

   TTreeReaderValue<Double_t>    MET_et_new  = {fReader, "MET_et_new"};
   TTreeReaderValue<Double_t>    MET_et  = {fReader, "MET_et"};

   TTreeReaderValue<Double_t>    npT  = {fReader, "npT"};


   TTreeReaderValue<Int_t>    lep  = {fReader, "lep"};
   //TTreeReaderValue<Double_t>    Mla  = {fReader, "Mla"};
   //TTreeReaderValue<Double_t>    Mla_f  = {fReader, "Mla_f"};
   //TTreeReaderValue<Double_t>    Mva  = {fReader, "Mva"};
   //TTreeReaderValue<Double_t>    Mva_f  = {fReader, "Mva_f"};
   TTreeReaderValue<Int_t>    nlooseeles  = {fReader, "nlooseeles"};
   TTreeReaderValue<Int_t>    nloosemus  = {fReader, "nloosemus"};
   TTreeReaderValue<Int_t>    HLT_Ele1  = {fReader, "HLT_Ele1"};
   TTreeReaderValue<Int_t>    HLT_Ele2  = {fReader, "HLT_Ele2"};
   TTreeReaderValue<Int_t>    HLT_Mu1  = {fReader, "HLT_Mu1"};
   TTreeReaderValue<Int_t>    HLT_Mu2  = {fReader, "HLT_Mu2"};
   TTreeReaderValue<Int_t>    HLT_Mu3  = {fReader, "HLT_Mu3"};
   TTreeReaderValue<Double_t>    lumiWeight  = {fReader, "lumiWeight"};
   TTreeReaderValue<Double_t>    pileupWeight  = {fReader, "pileupWeight"};
   Long64_t maxEntries = fReader.GetEntries(false);
   cout << "Number of events to be analyzed : " << maxEntries << std::endl;
   while (fReader.Next()) {
nevent_pass++;

      if (jentry % 20000 == 0){ 
         int ks = floor(50.*jentry/maxEntries);
         string s1(ks,'>');
         string s2(50-ks,'-');
         cout<<"processing : ["<<"\033[32m"<<s1<<"\033[0m"<<s2<<"]  "<<"\033[33m"<<100.*jentry/maxEntries<<"%  "<<"p_event: "<<p_event<<" n_event: "<<n_event<<"\033[0m"<<endl;
         }

      jentry++;

      // apply selection
      Bool_t muon_cut, electron_cut, cut;
	  muon_cut = *HLT_Mu2 == 1 &&abs(*lep) == 13 &&*ngoodmus == 1 &&*ngoodeles == 0 && (*nloosemus + *nlooseeles) == 1 &&*mtVlepJECnew_new < 20 &&*MET_et_new < 30 &&((*jet1pt_orig > 20 && *drj1l_orig > 0.3) || (*jet2pt_orig > 20 && *drj2l_orig > 0.3));

      electron_cut = *HLT_Ele2 == 1 &&abs(*lep) == 11 &&*ngoodmus == 0 &&*ngoodeles == 1 && (*nloosemus + *nlooseeles) == 1 &&*mtVlepJECnew_new < 20 &&*MET_et_new < 30 &&((*jet1pt_orig > 30 && *drj1l_orig > 0.3) || (*jet2pt_orig > 30 && *drj2l_orig > 0.3));

      if(m_channel == "muon") cut = muon_cut;
      if(m_channel == "electron") cut = electron_cut;
      if(!cut) continue;

      init_sf();
      // cross section SF
      if(m_sample == "WGJJ")          { cross_section_SF=1000.*0.5439   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WGJets")        { cross_section_SF=1000.*192.3    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WJets_0j")        { cross_section_SF=1000.*55971.0  *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WJets_1j")        { cross_section_SF=1000.*6942.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WJets_2j")        { cross_section_SF=1000.*1459.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZJets")         { cross_section_SF=1000.*5765.4   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZG")            { cross_section_SF=1000.*47.46    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "TTG")       { cross_section_SF=1000.*4.078    *fabs(*theWeight)/(*theWeight); }
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
         
         // add factor for muon
         double bf=0.5497;   double gh=0.4503;
         if(abs(*lep)==13)
         {
            //------muon trigger scalefactor
            muon_HLT_SF = bf*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_B-F_weight, " ") + gh*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_G-H_weight, " ");
            muon_HLT_up_SF = bf*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_B-F_weight, "up") + gh*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_G-H_weight, "up");
            muon_HLT_low_SF = bf*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_B-F_weight, "low") + gh*get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_G-H_weight, "low");
            //------muon tight ID  scalefactor
            muon_ID_SF = bf*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_B-F_weight, " ") + gh*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_G-H_weight, " ");
            muon_ID_up_SF = bf*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_B-F_weight, "up") + gh*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_G-H_weight, "up");
            muon_ID_low_SF = bf*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_B-F_weight, "low") + gh*get_muon_ID(*etalep1, *ptlep1, h_muon_ID_G-H_weight, "low");
            //------muon tight ISO scalefactor
            muon_iso_SF = bf*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_B-F_weight, " ") + gh*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_G-H_weight, " ");
            muon_iso_up_SF = bf*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_B-F_weight, "up") + gh*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_G-H_weight, "up");
            muon_iso_low_SF = bf*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_B-F_weight, "low") + gh*get_muon_iso(*etalep1, *ptlep1, h_muon_iso_G-H_weight, "low");
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

      } //add scalef for mc

      double ptl1 = (*ptlep1);
      if (ptl1 >= 50) ptl1 = 45;

      double weight = 1;

      if(m_type == "data") weight = 1;
      else if(m_type == "mc") {
         weight = cross_section_SF * pu_weight_SF;
      }

      if(cut){
         h_fake_lepton->Fill(fabs(*etalep1), ptl1, weight);
      }

      //jentry++;
   }
}
