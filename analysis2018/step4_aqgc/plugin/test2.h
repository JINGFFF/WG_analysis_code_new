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
#include <TH2.h>
#include "TF1.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Header file for the classes stored in the TTree if any.

class test {
public :
   // some thing important
   TString m_year;
   TString m_sample;
   TString m_type;
   TString m_channel;
   TString m_btag_workpoint;

   // fake lepton weight
   TFile * file_fake_muon_weight;
   TFile * file_fake_electron_weight;
   TH2D* hist_fake_muon_weight;
   TH2D* hist_fake_electron_weight;

   // fake photon weight
   TFile * file_fake_photon_weight;
   TH1F* hist_barrel_fake_photon_weight;
   TH1F* hist_endcap_fake_photon_weight;

   // pile up weight
   TFile * pu_weight_input;
   TH1D* h_pu_weight;

   // photon medium ID weight
   TFile * photon_ID_weight_input;
   TH2D* h_photon_ID_weight;

   // muon HLT weight
   TFile * muon_HLT_weight_B_F_input;
   TDirectory * muon_HLT_weight_B_F_dir;
   TH2D* h_muon_HLT_B_F_weight;

   // muon ID weight
   TFile * muon_ID_weight_B_F_input;
   TH2D* h_muon_ID_B_F_weight;

   // muon iso scale
   TFile * muon_iso_weight_B_F_input;
   TH2D* h_muon_iso_B_F_weight;

   // muon HLT weight
   TFile * muon_HLT_weight_G_H_input;
   TDirectory * muon_HLT_weight_G_H_dir;
   TH2D* h_muon_HLT_G_H_weight;

   // muon ID weight
   TFile * muon_ID_weight_G_H_input;
   TH2D* h_muon_ID_G_H_weight;

   // muon iso scale
   TFile * muon_iso_weight_G_H_input;
   TH2D* h_muon_iso_G_H_weight;
   // electron reco scale
   TFile * electron_reco_weight_input;
   TH2D* h_electron_reco_weight;

   // electron ID scale
   TFile * electron_ID_weight_input;
   TH2D* h_electron_ID_weight;

   // electron HLT scale
   TFile * electron_HLT_weight_input;
   TH2D* h_electron_HLT_weight;

   // value to fill histogram or use for cut
   double fill_Mjj;
   double fill_nVtx;
   double fill_jet1pt;
   double fill_jet1eta;
   double fill_jet2pt;
   double fill_jet2eta;
   double fill_lep;
   double fill_HLT_muon;
   double fill_HLT_electron;

   double fill_ptlep1;
   double fill_etalep1;
   double  fill_ngoodmus;
   double fill_ngoodeles;
   double fill_nloosemus;
   double fill_nlooseeles;
   double fill_photonhaspixelseed;
   double fill_photonet;
   double fill_MET_et;
   double fill_mtVlepJECnew;
   double fill_drla;
   double fill_drj1l;
   double fill_drj2l;
   double fill_drj1a;
   double fill_drj2a;
   double fill_j1metPhi;
   double fill_j2metPhi;
   double fill_jet1deepcsv;
   double fill_jet2deepcsv;

   double fill_photonsceta;
   double fill_ptVlepJEC;
   double fill_photoneta;
   double fill_zepp;
   double fill_deltaeta;
   double fill_Dphiwajj;
   double fill_Mla;
   double fill_Mva;
   // cut for muon and electron channel
   Bool_t muon_cut, electron_cut, cut;

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

   Double_t        btag_jet2_SF;
   Double_t        btag_jet2_up_SF;
   Double_t        btag_jet2_low_SF;

   Double_t        pu_weight_SF;
   Double_t        cross_section_SF;

   Double_t        p_event = 0, n_event = 0;

   double WGbin[6] = {150,400,600,800,1000,1500};
   TH1D *PTA1        = new TH1D("nominal"," ",5,WGbin);
   TH1D *PTA1_up     = new TH1D("up"," ",5,WGbin);
   TH1D *PTA1_down   = new TH1D("down"," ",5,WGbin);

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

Double_t eff_b_jet_tight[10] ={ 0.320501, 0.438741, 0.494037, 0.516037, 0.521717, 0.511363, 0.463285, 0.380385, 0.268077, 0.22774};
Double_t eff_b_jet_medium[10] ={ 0.494944, 0.604301, 0.655748, 0.680486, 0.693248, 0.693765, 0.667501, 0.616062, 0.535007, 0.505137};
Double_t eff_b_jet_loose[10] ={ 0.686011, 0.764027, 0.805729, 0.831279, 0.849252, 0.860238, 0.858505, 0.849354, 0.843092, 0.849315};
Double_t eff_c_jet_tight[10] ={ 0.0183726, 0.0223202, 0.0220486, 0.0226769, 0.024171, 0.0263377, 0.0265894, 0.0277639, 0.032798, 0.0315315};
Double_t eff_c_jet_medium[10] ={ 0.106603, 0.119726, 0.114486, 0.114447, 0.118432, 0.12676, 0.128575, 0.138768, 0.151776, 0.189189};
Double_t eff_c_jet_loose[10] ={ 0.354013, 0.383178, 0.384509, 0.389559, 0.39991, 0.416174, 0.426847, 0.467101, 0.51934, 0.617117};
Double_t eff_l_jet_tight[10] ={ 0.00116083, 0.00108697, 0.0010221, 0.00107856, 0.00123402, 0.00159878, 0.00193249, 0.00285934, 0.00374868, 0.00664452};
Double_t eff_l_jet_medium[10] ={ 0.0130506, 0.0120923, 0.00997784, 0.00970286, 0.0105707, 0.0128526, 0.0161229, 0.0244205, 0.0325238, 0.0340532};
Double_t eff_l_jet_loose[10] ={ 0.113448, 0.109686, 0.0945654, 0.0941139, 0.102728, 0.122753, 0.15118, 0.205856, 0.277138, 0.35299};
   
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

   void read_csv_info();
   Double_t btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low);

   void set_cut_value(TString year = "2018");
   void hist_Sumw2();
   void hist_Scale();

   void init_sf();
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

   // fake lepton weight
   file_fake_muon_weight = TFile::Open("./scalef/data_driven_weight/muon_fakerate.root");
   file_fake_electron_weight = TFile::Open("./scalef/data_driven_weight/electron_fakerate.root");
   hist_fake_muon_weight = (TH2D*)file_fake_muon_weight->Get("weight");
   hist_fake_electron_weight = (TH2D*)file_fake_electron_weight->Get("weight");

   // fake photon weight
   file_fake_photon_weight = TFile::Open("./scalef/data_driven_weight/fake_photon_weight.root");
   hist_barrel_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("barrel_fake_photon_weight");
   hist_endcap_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("endcap_fake_photon_weight");

   // pile up weight
   pu_weight_input = new TFile ("./scalef/puweight_2016.root");
   h_pu_weight = (TH1D*)pu_weight_input->Get("h2");

   // photon medium ID weight
   photon_ID_weight_input = new TFile ("./scalef/photon/Fall17V2_2016_Medium_photons.root");
   h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   muon_HLT_weight_B_F_input = new TFile ("./scalef/muon/EfficienciesAndSF_RunBtoF.root");
   muon_HLT_weight_G_H_input = new TFile ("./scalef/muon/EfficienciesAndSF_Period4.root");

   muon_HLT_weight_B_F_dir  = (TDirectory*)muon_HLT_weight_G_H_input->Get("IsoMu24_OR_IsoTkMu24_PtEtaBins");
   muon_HLT_weight_G_H_dir  = (TDirectory*)muon_HLT_weight_G_H_input->Get("IsoMu24_OR_IsoTkMu24_PtEtaBins");

   h_muon_HLT_B_F_weight = (TH2D*)muon_HLT_weight_B_F_dir->Get("abseta_pt_ratio");
   h_muon_HLT_G_H_weight = (TH2D*)muon_HLT_weight_G_H_dir->Get("abseta_pt_ratio");


   // muon ID weight
   muon_ID_weight_B_F_input = new TFile ("./scalef/muon/RunBCDEF_SF_ID.root");
   h_muon_ID_B_F_weight = (TH2D*)muon_ID_weight_B_F_input->Get("NUM_TightID_DEN_genTracks_eta_pt");

   muon_ID_weight_G_H_input = new TFile ("./scalef/muon/RunGH_SF_ID.root");
   h_muon_ID_G_H_weight = (TH2D*)muon_ID_weight_G_H_input->Get("NUM_TightID_DEN_genTracks_eta_pt");


   // muon iso weight
   muon_iso_weight_B_F_input = new TFile ("./scalef/muon/RunBCDEF_SF_ISO.root");
   h_muon_iso_B_F_weight = (TH2D*)muon_iso_weight_B_F_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_eta_pt");

   muon_iso_weight_G_H_input = new TFile ("./scalef/muon/RunGH_SF_ISO.root");
   h_muon_iso_G_H_weight = (TH2D*)muon_iso_weight_G_H_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_eta_pt");

   // electron reco weight
   electron_reco_weight_input = new TFile ("./scalef/electron/EGM2D_BtoH_GT20GeV_RecoSF_Legacy2016.root");
   h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID weight
   electron_ID_weight_input = new TFile ("./scalef/electron/2016LegacyReReco_ElectronTight_Fall17V2.root");
   h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");

   // electron HLT weight
   electron_HLT_weight_input = new TFile ("./scalef/electron/egammaEffi.txt_EGM2D.root");
   h_electron_HLT_weight = (TH2D*)electron_HLT_weight_input->Get("EGamma_SF2D");


    

/*
   for (int k =0; k<=9; k++){
      cout<<eff_b_jet_tight[k]<<" "<<eff_b_jet_medium[k]<<" "<<eff_b_jet_loose[k]<<endl;

   }
*/
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
   ifstream fin("./scalef/jet/DeepCSV_2016LegacySF_WP_V1.csv");
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
            //cout<<vectorString[j]<<endl;
         //}
         vectorString.clear();
      }
   }
   else 
   {
      cout<<"no such file"<<endl;;
   }

      cout<<"Btag info has been loaded!"<<endl;
}
void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
}
void test::endJob() {
   fout = new TFile(m_dataset + "/" + m_year + "_aqgc_WG_" + m_type + "_" + m_channel + "_" + m_sample + "_" + m_btag_workpoint  +".root" , "RECREATE");
   TString m_sample;
   TString m_type;
   TString m_channel;
   TString m_btag_workpoint;


   PTA1->SetBinContent(5, PTA1->GetBinContent(5)+PTA1->GetBinContent(6));
   PTA1_up->SetBinContent(5, PTA1_up->GetBinContent(5)+PTA1_up->GetBinContent(6));
   PTA1_down->SetBinContent(5, PTA1_down->GetBinContent(5)+PTA1_down->GetBinContent(6));
   double xe=sqrt(PTA1->GetBinError(5)*PTA1->GetBinError(5)+PTA1->GetBinError(6)*PTA1->GetBinError(6));
   double xe_up=sqrt(PTA1_up->GetBinError(5)*PTA1_up->GetBinError(5)+PTA1_up->GetBinError(6)*PTA1_up->GetBinError(6));
   double xe_down=sqrt(PTA1_down->GetBinError(5)*PTA1_down->GetBinError(5)+PTA1_down->GetBinError(6)*PTA1_down->GetBinError(6));
   PTA1->SetBinError(5, xe);   
   PTA1_up->SetBinError(5, xe_up);   
   PTA1_down->SetBinError(5, xe_down);

   fout->cd();
   PTA1->Write();
   PTA1_up->Write();
   PTA1_down->Write();

   fout->Close();
   delete fout;
}

void test::hist_Sumw2()
{
   PTA1->Sumw2();
   PTA1_up->Sumw2();
   PTA1_down->Sumw2();
 
   ///// fake lepton
   //h_fake_lepton->Sumw2();

}

void test::hist_Scale()
{
   if(m_type == "mc"){
      PTA1->Scale(1/(p_event - n_event));
      PTA1_up->Scale(1/(p_event - n_event));
      PTA1_down->Scale(1/(p_event - n_event));

      ///////// fake lepton
   //   h_fake_lepton->Scale(1/(p_event - n_event));


   }
}
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

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[18],19.0,1001.);return  f1->Eval(x);}
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

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[18],19.0,1001.);return  f1->Eval(x);}
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

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

}






#endif // #ifdef test_cxx
