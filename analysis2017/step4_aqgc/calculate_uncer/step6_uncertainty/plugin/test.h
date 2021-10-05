//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Jul 12 17:08:56 2020 by ROOT version 6.10/05
// from TTree PKUCandidates/PKU Candidates
// found on file: treePKU_69.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <TH1D.h>
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <TTreeReaderArray.h>
#include <TH2.h>
#include "TF1.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "mytool/common_set.C"
#include "mytool/hist.C"
#include "mytool/ele_channel_scale.C"
#include "mytool/muon_channel_scale.C"
#include "mytool/add_cut.C"
#include "mytool/pujetID.C"
using namespace std;

// Header file for the classes stored in the TTree if any.

class test {
public :
   // some thing important
   TString m_year;
   TString m_sample;
   TString m_type;
   TString m_channel;
   TString m_region;
   TString m_bORe;
   TString m_btag_workpoint;
   TString m_pujet_workpoint;

   TFile*filexx;
   TH2F*h2_eff_mc2017_L;
   TH2F*h2_eff_mc2017_M;
   TH2F*h2_eff_mc2017_T;
   TH2F*h2_mistag_mc2017_L;
   TH2F*h2_mistag_mc2017_M;
   TH2F*h2_mistag_mc2017_T;

   TFile*filexxx;
   TH2F*h2_eff_sf2017_L;
   TH2F*h2_eff_sf2017_M;
   TH2F*h2_eff_sf2017_T;
   TH2F*h2_mistag_sf2017_L;
   TH2F*h2_mistag_sf2017_M;
   TH2F*h2_mistag_sf2017_T;
   TH2F*h2_eff_sf2017_L_Systuncty;
   TH2F*h2_eff_sf2017_M_Systuncty;
   TH2F*h2_eff_sf2017_T_Systuncty;
   TH2F*h2_mistag_sf2017_L_Systuncty;
   TH2F*h2_mistag_sf2017_M_Systuncty;
   TH2F*h2_mistag_sf2017_T_Systuncty;
   // value to fill histogram or use for cut
   double fill_Mjj;
   double fill_Mjj_JEC_up;
   double fill_Mjj_JEC_down;
   double fill_Mjj_JER_up;
   double fill_Mjj_JER_down;

   double fill_nVtx;
   double fill_jet1pt;
   double fill_jet1eta;

   double fill_jet1pt_JEC_up;
   double fill_jet1eta_JEC_up;
   double fill_jet1pt_JEC_down;
   double fill_jet1eta_JEC_down;

   double fill_jet1pt_JER_up;
   double fill_jet1eta_JER_up;
   double fill_jet1pt_JER_down;
   double fill_jet1eta_JER_down;

   double fill_jet1pf;
   double fill_jet1pf_JEC_up;
   double fill_jet1pf_JEC_down;
   double fill_jet1pf_JER_up;
   double fill_jet1pf_JER_down;


   double fill_jet2pt;
   double fill_jet2eta;

   double fill_jet2pt_JEC_up;
   double fill_jet2eta_JEC_up;
   double fill_jet2pt_JEC_down;
   double fill_jet2eta_JEC_down;

   double fill_jet2pt_JER_up;
   double fill_jet2eta_JER_up;
   double fill_jet2pt_JER_down;
   double fill_jet2eta_JER_down;

   double fill_jet2pf;
   double fill_jet2pf_JEC_up;
   double fill_jet2pf_JEC_down;
   double fill_jet2pf_JER_up;
   double fill_jet2pf_JER_down;

   double fill_lep;
   double fill_HLT_muon;
   double fill_HLT_electron;

   double fill_ptlep1;
   double fill_etalep1;
   double fill_ngoodmus;
   double fill_ngoodeles;
   double fill_nloosemus;
   double fill_nlooseeles;
   double fill_photonhaspixelseed;
   double fill_photonet;

   double fill_MET_et;
   double fill_MET_et_JEC_up;
   double fill_MET_et_JEC_down;
   double fill_MET_et_JER_up;
   double fill_MET_et_JER_down;

   double fill_mtVlepJECnew;
   double fill_mtVlepJECnew_JEC_up;
   double fill_mtVlepJECnew_JEC_down;
   double fill_mtVlepJECnew_JER_up;
   double fill_mtVlepJECnew_JER_down;


   double fill_drla;

   double fill_drj1l;
   double fill_drj2l;
   double fill_drj1a;
   double fill_drj2a;

   double fill_drj1l_JEC_up;
   double fill_drj2l_JEC_up;
   double fill_drj1a_JEC_up;
   double fill_drj2a_JEC_up;

   double fill_drj1l_JEC_down;
   double fill_drj2l_JEC_down;
   double fill_drj1a_JEC_down;
   double fill_drj2a_JEC_down;

   double fill_drj1l_JER_up;
   double fill_drj2l_JER_up;
   double fill_drj1a_JER_up;
   double fill_drj2a_JER_up;

   double fill_drj1l_JER_down;
   double fill_drj2l_JER_down;
   double fill_drj1a_JER_down;
   double fill_drj2a_JER_down;

   double fill_j1metPhi;
   double fill_j2metPhi;
   double fill_jet1deepcsv;
   double fill_jet2deepcsv;

   double fill_j1metPhi_JEC_up;
   double fill_j2metPhi_JEC_up;
   double fill_jet1deepcsv_JEC_up;
   double fill_jet2deepcsv_JEC_up;

   double fill_j1metPhi_JEC_down;
   double fill_j2metPhi_JEC_down;
   double fill_jet1deepcsv_JEC_down;
   double fill_jet2deepcsv_JEC_down;

   double fill_j1metPhi_JER_up;
   double fill_j2metPhi_JER_up;
   double fill_jet1deepcsv_JER_up;
   double fill_jet2deepcsv_JER_up;

   double fill_j1metPhi_JER_down;
   double fill_j2metPhi_JER_down;
   double fill_jet1deepcsv_JER_down;
   double fill_jet2deepcsv_JER_down;


   double fill_photonsceta;

   double fill_ptVlepJEC;

   double fill_ptVlepJEC_JEC_up;
   double fill_ptVlepJEC_JEC_down;
   double fill_ptVlepJEC_JER_up;
   double fill_ptVlepJEC_JER_down;

   double fill_photoneta;

   double fill_zepp;
   double fill_deltaeta;
   double fill_Dphiwajj;

   double fill_zepp_JEC_up;
   double fill_deltaeta_JEC_up;
   double fill_Dphiwajj_JEC_up;

   double fill_zepp_JEC_down;
   double fill_deltaeta_JEC_down;
   double fill_Dphiwajj_JEC_down;

   double fill_zepp_JER_up;
   double fill_deltaeta_JER_up;
   double fill_Dphiwajj_JER_up;

   double fill_zepp_JER_down;
   double fill_deltaeta_JER_down;
   double fill_Dphiwajj_JER_down;

   double fill_Mla;
   double fill_Mva;
   double fill_Mva_JEC_up;
   double fill_Mva_JEC_down;
   double fill_Mva_JER_up;
   double fill_Mva_JER_down;

   double fill_jet1phi;
   double fill_jet1phi_JEC_up;
   double fill_jet1phi_JEC_down;
   double fill_jet1phi_JER_up;
   double fill_jet1phi_JER_down;
   double fill_jet2phi;
   double fill_jet2phi_JEC_up;
   double fill_jet2phi_JEC_down;
   double fill_jet2phi_JER_up;
   double fill_jet2phi_JER_down;
   double fill_genjet_eta[6], fill_genjet_phi[6];

   double fill_jet1puId;
   double fill_jet1puId_JEC_up;
   double fill_jet1puId_JEC_down;
   double fill_jet1puId_JER_up;
   double fill_jet1puId_JER_down;

   double fill_jet2puId;
   double fill_jet2puId_JEC_up;
   double fill_jet2puId_JEC_down;
   double fill_jet2puId_JER_up;
   double fill_jet2puId_JER_down;
   // cut for muon and electron channel
   Bool_t muon_cut, electron_cut, cut;
   Bool_t gen_muon_cut_signal_region, gen_muon_cut_control_region, gen_electron_cut_signal_region, gen_electron_cut_control_region, gen_muon_cut_aqgc_region, gen_electron_cut_aqgc_region;
   Bool_t muon_cut_signal_region, muon_cut_signal_region_jec_up, muon_cut_signal_region_jec_down, muon_cut_signal_region_jer_up, muon_cut_signal_region_jer_down;
   Bool_t muon_cut_control_region, muon_cut_control_region_jec_up, muon_cut_control_region_jec_down, muon_cut_control_region_jer_up, muon_cut_control_region_jer_down;
   Bool_t muon_cut_aqgc_region, muon_cut_aqgc_region_jec_up, muon_cut_aqgc_region_jec_down, muon_cut_aqgc_region_jer_up, muon_cut_aqgc_region_jer_down;
   Bool_t electron_cut_signal_region, electron_cut_signal_region_jec_up, electron_cut_signal_region_jec_down, electron_cut_signal_region_jer_up, electron_cut_signal_region_jer_down;
   Bool_t electron_cut_control_region, electron_cut_control_region_jec_up, electron_cut_control_region_jec_down, electron_cut_control_region_jer_up, electron_cut_control_region_jer_down;
   Bool_t electron_cut_aqgc_region, electron_cut_aqgc_region_jec_up, electron_cut_aqgc_region_jec_down, electron_cut_aqgc_region_jer_up, electron_cut_aqgc_region_jer_down;

   // define all scalef
   Double_t        photon_ID_SF;
   Double_t        electron_ID_SF;
   Double_t        electron_Reco_SF;
   Double_t        electron_HLT_SF;
   Double_t        muon_ID_SF;
   Double_t        muon_iso_SF;
   Double_t        muon_HLT_SF;

   Double_t        photon_ID_up_SF;
   Double_t        electron_ID_up_SF;
   Double_t        electron_Reco_up_SF;
   Double_t        electron_HLT_up_SF;
   Double_t        muon_ID_up_SF;
   Double_t        muon_iso_up_SF;
   Double_t        muon_HLT_up_SF;

   Double_t        photon_ID_low_SF;
   Double_t        electron_ID_low_SF;
   Double_t        electron_Reco_low_SF;
   Double_t        electron_HLT_low_SF;
   Double_t        muon_ID_low_SF;
   Double_t        muon_iso_low_SF;
   Double_t        muon_HLT_low_SF;

   Double_t        btag_jet1_SF;
   Double_t        btag_jet1_up_SF;
   Double_t        btag_jet1_low_SF;

   Double_t        btag_jet1_SF_JEC_up;
   Double_t        btag_jet1_up_SF_JEC_up;
   Double_t        btag_jet1_low_SF_JEC_up;
   Double_t        btag_jet1_SF_JEC_down;
   Double_t        btag_jet1_up_SF_JEC_down;
   Double_t        btag_jet1_low_SF_JEC_down;
   Double_t        btag_jet1_SF_JER_up;
   Double_t        btag_jet1_up_SF_JER_up;
   Double_t        btag_jet1_low_SF_JER_up;
   Double_t        btag_jet1_SF_JER_down;
   Double_t        btag_jet1_up_SF_JER_down;
   Double_t        btag_jet1_low_SF_JER_down;

   Double_t        btag_jet2_SF;
   Double_t        btag_jet2_up_SF;
   Double_t        btag_jet2_low_SF;

   Double_t        btag_jet2_SF_JEC_up;
   Double_t        btag_jet2_up_SF_JEC_up;
   Double_t        btag_jet2_low_SF_JEC_up;
   Double_t        btag_jet2_SF_JEC_down;
   Double_t        btag_jet2_up_SF_JEC_down;
   Double_t        btag_jet2_low_SF_JEC_down;
   Double_t        btag_jet2_SF_JER_up;
   Double_t        btag_jet2_up_SF_JER_up;
   Double_t        btag_jet2_low_SF_JER_up;
   Double_t        btag_jet2_SF_JER_down;
   Double_t        btag_jet2_up_SF_JER_down;
   Double_t        btag_jet2_low_SF_JER_down;

   double pu_jet1_SF;
   double pu_jet1_up_SF;
   double pu_jet1_down_SF;

   double pu_jet1_JEC_up_SF;
   double pu_jet1_JEC_down_SF;
   double pu_jet1_JER_up_SF;
   double pu_jet1_JER_down_SF;

   double pu_jet2_SF;
   double pu_jet2_up_SF;
   double pu_jet2_down_SF;

   double pu_jet2_JEC_up_SF;
   double pu_jet2_JEC_down_SF;
   double pu_jet2_JER_up_SF;
   double pu_jet2_JER_down_SF;

   double pu_jet1_mistag_SF;
   double pu_jet1_mistag_up_SF;
   double pu_jet1_mistag_down_SF;

   double pu_jet1_mistag_JEC_up_SF;
   double pu_jet1_mistag_JEC_down_SF;
   double pu_jet1_mistag_JER_up_SF;
   double pu_jet1_mistag_JER_down_SF;

   double pu_jet2_mistag_SF;
   double pu_jet2_mistag_up_SF;
   double pu_jet2_mistag_down_SF;

   double pu_jet2_mistag_JEC_up_SF;
   double pu_jet2_mistag_JEC_down_SF;
   double pu_jet2_mistag_JER_up_SF;
   double pu_jet2_mistag_JER_down_SF;

   Double_t        pu_weight_SF;
   Double_t        pu_weight_up_SF;
   Double_t        pu_weight_down_SF;

   Double_t        cross_section_SF;

   Double_t        p_event = 0, n_event = 0;


   // aqgc histgrams
   double WGbin[6] = {150,400,600,800, 1000, 2000};

   // btag eff and scale function
   TString fuction_b_jet_tight[19] ;
   TString fuction_b_jet_medium[19];
   TString fuction_b_jet_loose[19];

   TString fuction_c_jet_tight[19];
   TString fuction_c_jet_medium[19];
   TString fuction_c_jet_loose[19];

   TString fuction_l_jet_tight[3];
   TString fuction_l_jet_medium[3];
   TString fuction_l_jet_loose[3];
   /// define histogram for fake lepton

   /// define histogram for fake photon
   //

   Int_t           fCurrent; //!current Tree number in a TChain
   TString m_dataset;

   Double_t lumi;
   Double_t cut_value[3];

   test();
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init();
   virtual void     Loop(TDirectory * dir, TTree * tree);
   //virtual void     Loop_fake_lepton(TDirectory * dir);

   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual Double_t beff(TString workpoint, Double_t x);
   virtual Double_t ceff(TString workpoint, Double_t x);
   virtual Double_t leff(TString workpoint, Double_t x);
   virtual Double_t b_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t c_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t l_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low);
   void ResetValue();
   Double_t delta_R(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2);
   void set_cut_value(TString year = "2018");
   //void hist_Sumw2();
   //void hist_Scale();
   //void fill_hist(TString region, double fill_Mjj, double fill_deltaeta, TH1D* hist, double weight);
   //void creat_hist(TString region);

   void init_sf();
   void read_csv_info();
   void endJob();
   TFile *fout;
};

#endif

#ifdef test_cxx
test::test()  
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   //if (tree == 0) {
   //   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treePKU_69.root");
   //   if (!f || !f->IsOpen()) {
   //      f = new TFile("treePKU_69.root");
   //   }
      //TDirectory * dir = (TDirectory*)f->Get("treePKU_69.root:/treeDumper");
      //dir->GetObject("PKUCandidates",tree);

   //}
   //m_dataset = outname;
   //m_year = year;
   //Init(f);
   hist_Sumw2();
}

test::~test()
{
   //if (!fReader) return;
   //delete fReader.GetCurrentEntry();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   //if (!fReader) return 0;
   //return fReader->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   //if (!fChain) return -5;
   //Long64_t centry = fChain->LoadTree(entry);
   //if (centry < 0) return centry;
   //if (fChain->GetTreeNumber() != fCurrent) {
   //   fCurrent = fChain->GetTreeNumber();
   //   Notify();
   //}
   //return centry;
}

void test::Init()
{
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   //if (!f) return;
   //fCurrent = -1;

   //pujet ID
   filexx=new TFile("./scalef/pujetID/PUIDMaps.root");
   h2_eff_mc2017_T=(TH2F*)filexx->Get("h2_eff_mc"+m_year+"_"+m_pujet_workpoint);
   h2_mistag_mc2017_T=(TH2F*)filexx->Get("h2_mistag_mc"+m_year+"_"+m_pujet_workpoint);

   filexxx=new TFile("./scalef/pujetID/scalefactorsPUID_81Xtraining.root");
   h2_eff_sf2017_T=(TH2F*)filexx->Get("h2_eff_sf"+m_year+"_"+m_pujet_workpoint);
   h2_mistag_sf2017_T=(TH2F*)filexx->Get("h2_mistag_sf"+m_year+"_"+m_pujet_workpoint);
   h2_eff_sf2017_T_Systuncty=(TH2F*)filexxx->Get("h2_eff_sf"+m_year+"_"+m_pujet_workpoint+"_Systuncty");
   h2_mistag_sf2017_T_Systuncty=(TH2F*)filexxx->Get("h2_mistag_sf"+m_year+"_"+m_pujet_workpoint+"_Systuncty");

}

Bool_t test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void test::read_csv_info()
{
   cout<<"start load Btag info!"<<endl;
   //ifstream fin("./scalef/jet/DeepCSV_102XSF_WP_V1.csv");
   string line_info,input_result;
   vector<string> vectorString;
   if(fin) 
   {
      while (getline (fin, line_info))
      {
         stringstream input(line_info);
         //cout<<"line_info: "<<line_info<<endl;
         while(input>>input_result){
            while (input_result.find(',') != -1) 
               input_result.erase(input_result.find(','),1);
            while (input_result.find('"') != -1) 
               input_result.erase(input_result.find('"'),1);
            vectorString.push_back(input_result);
         }
         //cout<<vectorString.size()<<endl;
         // for b jet
         if(vectorString[3] == "0"){
            if(vectorString[0] == "2"){            
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_b_jet_tight[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_tight[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_tight[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_tight[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_tight[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_tight[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_tight[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_tight[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_tight[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_tight[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_tight[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_tight[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_tight[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_tight[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_tight[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_tight[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_tight[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_tight[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_tight[18] = vectorString[10];
            }

            if(vectorString[0] == "1"){
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_b_jet_medium[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_medium[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_medium[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_medium[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_medium[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_medium[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_medium[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_medium[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_medium[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_medium[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_medium[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_medium[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_medium[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_medium[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_medium[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_medium[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_medium[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_medium[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_medium[18] = vectorString[10];
            }

            if(vectorString[0] == "0"){
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_b_jet_loose[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_loose[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_loose[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_loose[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_loose[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_loose[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_loose[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_loose[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_loose[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_loose[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_b_jet_loose[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_b_jet_loose[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_b_jet_loose[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_b_jet_loose[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_b_jet_loose[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_b_jet_loose[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_b_jet_loose[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_b_jet_loose[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_b_jet_loose[18] = vectorString[10];
            }
         }

         //for c jet
         if(vectorString[3] == "0"){
            if(vectorString[0] == "2"){
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_c_jet_tight[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_tight[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_tight[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_tight[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_tight[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_tight[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_tight[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_tight[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_tight[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_tight[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_tight[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_tight[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_tight[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_tight[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_tight[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_tight[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_tight[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_tight[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_tight[18] = vectorString[10];
            }

            if(vectorString[0] == "1"){
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_c_jet_medium[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_medium[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_medium[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_medium[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_medium[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_medium[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_medium[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_medium[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_medium[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_medium[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_medium[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_medium[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_medium[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_medium[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_medium[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_medium[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_medium[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_medium[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_medium[18] = vectorString[10];
            }

            if(vectorString[0] == "0"){
               if( vectorString[1] == "comb" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_c_jet_loose[0] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_loose[1] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_loose[2] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_loose[3] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_loose[4] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_loose[5] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_loose[6] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_loose[7] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_loose[8] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "up" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_loose[9] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "30")fuction_c_jet_loose[10] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "30" && vectorString[7] == "50")fuction_c_jet_loose[11] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "50" && vectorString[7] == "70")fuction_c_jet_loose[12] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "70" && vectorString[7] == "100")fuction_c_jet_loose[13] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "100" && vectorString[7] == "140")fuction_c_jet_loose[14] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "140" && vectorString[7] == "200")fuction_c_jet_loose[15] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "200" && vectorString[7] == "300")fuction_c_jet_loose[16] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "300" && vectorString[7] == "600")fuction_c_jet_loose[17] = vectorString[10];
               if( vectorString[1] == "comb" && vectorString[2] == "down" && vectorString[6] == "600" && vectorString[7] == "1000")fuction_c_jet_loose[18] = vectorString[10];
            }
         }
  
         //for l jet
         if(vectorString[3] == "2"){
            if(vectorString[0] == "2"){
               if( vectorString[1] == "incl" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_tight[0] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_tight[1] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_tight[2] = vectorString[10];
            }

            if(vectorString[0] == "1"){
               if( vectorString[1] == "incl" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_medium[0] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_medium[1] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_medium[2] = vectorString[10];
            }

            if(vectorString[0] == "0"){
               if( vectorString[1] == "incl" && vectorString[2] == "central" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_loose[0] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "up" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_loose[1] = vectorString[10];
               if( vectorString[1] == "incl" && vectorString[2] == "down" && vectorString[6] == "20" && vectorString[7] == "1000")fuction_l_jet_loose[2] = vectorString[10];
            }
         }


         //for(int j=0;j<vectorString.size();j++){
         //   cout<<vectorString[j]<<endl;
         //}
         vectorString.clear();
      }
   }
   else 
   {
      cout<<"no such file"<<endl;;
   }

   //for (int j=0;j<19;j++){
     // cout<<fuction_c_jet_medium[j]<<endl;
      cout<<"Btag info has been loaded!"<<endl;
   //}
}


void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
}
/*
void test::endJob() {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();

         th2_barrel[ii]->Write();
         th2_endcap[ii]->Write();
   fout->Close();
   delete fout;
}

void test::hist_Sumw2()
{

   hist_WGmass_fakephoton_endcap_up->Sumw2();
   hist_WGmass_fakephoton_endcap_down->Sumw2();

}

void test::hist_Scale()
{
         hist_WGmass_muon_down->Scale(1/(p_event - n_event));

}
*/
void test::init_sf()
{
      photon_ID_SF = 1;
      electron_ID_SF = 1;
      electron_Reco_SF = 1;
      electron_HLT_SF = 1;
      muon_ID_SF = 1;
      muon_iso_SF = 1;
      muon_HLT_SF = 1;

      photon_ID_up_SF = 1;
      electron_ID_up_SF = 1;
      electron_Reco_up_SF = 1;
      electron_HLT_up_SF = 1;
      muon_ID_up_SF = 1;
      muon_iso_up_SF = 1;
      muon_HLT_up_SF = 1;

      photon_ID_low_SF = 1;
      electron_ID_low_SF = 1;
      electron_Reco_low_SF = 1;
      electron_HLT_low_SF = 1;
      muon_ID_low_SF = 1;
      muon_iso_low_SF = 1;
      muon_HLT_low_SF = 1;

      btag_jet1_SF = 1;
      btag_jet1_up_SF = 1;
      btag_jet1_low_SF = 1;

      btag_jet2_SF = 1;
      btag_jet2_up_SF = 1;
      btag_jet2_low_SF = 1;

      pu_weight_SF = 1;
      pu_weight_up_SF = 1;
      pu_weight_down_SF = 1;

      cross_section_SF = 1;
}

void test::set_cut_value(TString year)
{ 
   if(year == "2016"){ //cut_value[3] = {0.8953, 0.6321, 0.2217}
      cut_value[0] = 0.8953;
      cut_value[1] = 0.6321;
      cut_value[2] = 0.2217;
      lumi = 35.92;
   }
   if(year == "2017"){ //cut_value[3] = {0.8001, 0.4941, 0.1522};
      cut_value[0] = 0.8001;
      cut_value[1] = 0.4941;
      cut_value[2] = 0.1522;
      lumi = 41.50;
   }
   if(year == "2018"){ //cut_value[3] = {0.7527, 0.4184, 0.1241};
      cut_value[0] = 0.7527;
      cut_value[1] = 0.4184;
      cut_value[2] = 0.1241;
      lumi = 59.74;
   }
}


Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

Double_t test::btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low){
   double tmp_SF = 1;
   if(fabs(eta)<2.5){
      if(fabs(pf)==5){
         if(CSV>cut_value){
            tmp_SF     = b_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-beff(workpoint,pt)*b_scale(up_and_low,workpoint,pt))/(1-beff(workpoint,pt));
         }
      }

      if(fabs(pf)==4){
         if(CSV>cut_value){
            tmp_SF     = c_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-ceff(workpoint,pt)*c_scale(up_and_low,workpoint,pt))/(1-ceff(workpoint,pt));
         }
      }

      if(fabs(pf)!=4 && fabs(pf)!=5){
//cout<<"l jet"<<endl;

         if(CSV>cut_value){
            tmp_SF     = l_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-leff(workpoint,pt)*l_scale(up_and_low,workpoint,pt))/(1-leff(workpoint,pt));
         }
      }
   }

   else{
      tmp_SF     = 1;
   }

   return tmp_SF;

}

// ----------------------------- b eff and scalef ----------------------------------------------
Double_t test::beff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_b_jet_tight[0];
      if(x>=30 && x<50)return eff_b_jet_tight[1];
      if(x>=50 && x<70)return eff_b_jet_tight[2];
      if(x>=70 && x<100)return eff_b_jet_tight[3];
      if(x>=100 && x<140)return eff_b_jet_tight[4];
      if(x>=140 && x<200)return eff_b_jet_tight[5];
      if(x>=200 && x<300)return eff_b_jet_tight[6];
      if(x>=300 && x<600)return eff_b_jet_tight[7];
      if(x>=600 && x<1000)return eff_b_jet_tight[8];
      else return eff_b_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_b_jet_medium[0];
      if(x>=30 && x<50)return eff_b_jet_medium[1];
      if(x>=50 && x<70)return eff_b_jet_medium[2];
      if(x>=70 && x<100)return eff_b_jet_medium[3];
      if(x>=100 && x<140)return eff_b_jet_medium[4];
      if(x>=140 && x<200)return eff_b_jet_medium[5];
      if(x>=200 && x<300)return eff_b_jet_medium[6];
      if(x>=300 && x<600)return eff_b_jet_medium[7];
      if(x>=600 && x<1000)return eff_b_jet_medium[8];
      else return eff_b_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_b_jet_loose[0];
      if(x>=30 && x<50)return eff_b_jet_loose[1];
      if(x>=50 && x<70)return eff_b_jet_loose[2];
      if(x>=70 && x<100)return eff_b_jet_loose[3];
      if(x>=100 && x<140)return eff_b_jet_loose[4];
      if(x>=140 && x<200)return eff_b_jet_loose[5];
      if(x>=200 && x<300)return eff_b_jet_loose[6];
      if(x>=300 && x<600)return eff_b_jet_loose[7];
      if(x>=600 && x<1000)return eff_b_jet_loose[8];
      else return eff_b_jet_loose[9];
   }
}

Double_t test::b_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;
   double tmp_sf;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }


}

// ----------------------------- c eff and scalef ------------------------------------
Double_t test::ceff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_c_jet_tight[0];
      if(x>=30 && x<50)return eff_c_jet_tight[1];
      if(x>=50 && x<70)return eff_c_jet_tight[2];
      if(x>=70 && x<100)return eff_c_jet_tight[3];
      if(x>=100 && x<140)return eff_c_jet_tight[4];
      if(x>=140 && x<200)return eff_c_jet_tight[5];
      if(x>=200 && x<300)return eff_c_jet_tight[6];
      if(x>=300 && x<600)return eff_c_jet_tight[7];
      if(x>=600 && x<1000)return eff_c_jet_tight[8];
      else return eff_c_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_c_jet_medium[0];
      if(x>=30 && x<50)return eff_c_jet_medium[1];
      if(x>=50 && x<70)return eff_c_jet_medium[2];
      if(x>=70 && x<100)return eff_c_jet_medium[3];
      if(x>=100 && x<140)return eff_c_jet_medium[4];
      if(x>=140 && x<200)return eff_c_jet_medium[5];
      if(x>=200 && x<300)return eff_c_jet_medium[6];
      if(x>=300 && x<600)return eff_c_jet_medium[7];
      if(x>=600 && x<1000)return eff_c_jet_medium[8];
      else return eff_c_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_c_jet_loose[0];
      if(x>=30 && x<50)return eff_c_jet_loose[1];
      if(x>=50 && x<70)return eff_c_jet_loose[2];
      if(x>=70 && x<100)return eff_c_jet_loose[3];
      if(x>=100 && x<140)return eff_c_jet_loose[4];
      if(x>=140 && x<200)return eff_c_jet_loose[5];
      if(x>=200 && x<300)return eff_c_jet_loose[6];
      if(x>=300 && x<600)return eff_c_jet_loose[7];
      if(x>=600 && x<1000)return eff_c_jet_loose[8];
      else return eff_c_jet_loose[9];
   }


}

Double_t test::c_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;
   double tmp_sf;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[3],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[4],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[5],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[6],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[7],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[8],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[9],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[10],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[11],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[12],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[13],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[14],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[15],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[16],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[17],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[18],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }
}

// ----------------------------- l eff and scalef ---------------------
Double_t test::leff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_l_jet_tight[0];
      if(x>=30 && x<50)return eff_l_jet_tight[1];
      if(x>=50 && x<70)return eff_l_jet_tight[2];
      if(x>=70 && x<100)return eff_l_jet_tight[3];
      if(x>=100 && x<140)return eff_l_jet_tight[4];
      if(x>=140 && x<200)return eff_l_jet_tight[5];
      if(x>=200 && x<300)return eff_l_jet_tight[6];
      if(x>=300 && x<600)return eff_l_jet_tight[7];
      if(x>=600 && x<1000)return eff_l_jet_tight[8];
      else return eff_l_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_l_jet_medium[0];
      if(x>=30 && x<50)return eff_l_jet_medium[1];
      if(x>=50 && x<70)return eff_l_jet_medium[2];
      if(x>=70 && x<100)return eff_l_jet_medium[3];
      if(x>=100 && x<140)return eff_l_jet_medium[4];
      if(x>=140 && x<200)return eff_l_jet_medium[5];
      if(x>=200 && x<300)return eff_l_jet_medium[6];
      if(x>=300 && x<600)return eff_l_jet_medium[7];
      if(x>=600 && x<1000)return eff_l_jet_medium[8];
      else return eff_l_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_l_jet_loose[0];
      if(x>=30 && x<50)return eff_l_jet_loose[1];
      if(x>=50 && x<70)return eff_l_jet_loose[2];
      if(x>=70 && x<100)return eff_l_jet_loose[3];
      if(x>=100 && x<140)return eff_l_jet_loose[4];
      if(x>=140 && x<200)return eff_l_jet_loose[5];
      if(x>=200 && x<300)return eff_l_jet_loose[6];
      if(x>=300 && x<600)return eff_l_jet_loose[7];
      if(x>=600 && x<1000)return eff_l_jet_loose[8];
      else return eff_l_jet_loose[9];
   }

}

Double_t test::l_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;
   double tmp_sf;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[0],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[1],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[2],19.0,1001.);tmp_sf = f1->Eval(x); delete f1; return tmp_sf;}
         else return 1;
      }

   }

}






#endif // #ifdef test_cxx
