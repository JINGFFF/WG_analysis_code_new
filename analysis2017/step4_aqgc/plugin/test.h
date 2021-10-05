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

#include <iostream>
#include "TLatex.h"
#include "TH1D.h"
#include "TH1F.h"
#include "THStack.h"
#include "TString.h"
#include "TLegend.h"
#include "TLine.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TCut.h"
#include "TGraph.h"
#include "math.h"

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
   TString name;
   double WGbin[6] = {150,400,600,800, 1000, 2e4};
   double rf[17] ={0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
   
   int abin, index, iii;
   // pile up weight
   TFile * pu_weight_input;
   TH1D* h_pu_weight;

   // photon medium ID weight
   TFile * photon_ID_weight_input;
   TH2D* h_photon_ID_weight;

   // muon HLT weight
   TFile * muon_HLT_weight_input;
   TDirectory * muon_HLT_weight_dir;
   TH2D* h_muon_HLT_weight;

   // muon ID weight
   TFile * muon_ID_weight_input;
   TH2D* h_muon_ID_weight;

   // muon iso scale
   TFile * muon_iso_weight_input;
   TH2D* h_muon_iso_weight;

   // electron reco scale
   TFile * electron_reco_weight_input;
   TH2D* h_electron_reco_weight;

   // electron ID scale
   TFile * electron_ID_weight_input;
   TH2D* h_electron_ID_weight;

   // electron HLT scale
   TFile * electron_HLT_weight_input;
   TH2D* h_electron_HLT_weight;

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

   Double_t eff_b_jet_tight[10]  =  {0.375338, 0.493779, 0.553314, 0.575056, 0.579706, 0.563553, 0.491523, 0.327807, 0.105522, 0.0292929};
   Double_t eff_b_jet_medium[10] = {0.565127, 0.663282, 0.714194, 0.737916, 0.750325, 0.745599, 0.701239, 0.590619, 0.390365, 0.216667};
   Double_t eff_b_jet_loose[10] =  {0.753404, 0.813243, 0.850107, 0.87129, 0.88806, 0.89424, 0.881965, 0.846197, 0.798682, 0.70404};
   Double_t eff_c_jet_tight[10]  =  {0.0178263, 0.0219464, 0.0242307, 0.0269731, 0.0299322, 0.0316588, 0.0287384, 0.0180558, 0.00498598, 0.00366972};
   Double_t eff_c_jet_medium[10] = {0.120439, 0.128175, 0.130494, 0.13781, 0.14765, 0.154195, 0.146221, 0.120963, 0.0666874, 0.0311927};
   Double_t eff_c_jet_loose[10] =  {0.392685, 0.415126, 0.42917, 0.445494, 0.462387, 0.473021, 0.461477, 0.451609, 0.421237, 0.348624};
   Double_t eff_l_jet_tight[10]  =  {0.00115722, 0.000821689, 0.000900955, 0.00110315, 0.0014241, 0.00181297, 0.0020553, 0.00198708, 0.000801618, 0};
   Double_t eff_l_jet_medium[10] = {0.00904002, 0.00806116, 0.00810405, 0.00924306, 0.0113922, 0.0137251, 0.0159489, 0.0189461, 0.0130992, 0.004265};
   Double_t eff_l_jet_loose[10] =  {0.125149, 0.0924003, 0.0847756, 0.0946918, 0.113998, 0.134914, 0.15921, 0.19733, 0.229773, 0.206426};



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
   virtual void     Loop(TDirectory * dir , TTree* tree);
   //virtual void     Loop_fake_lepton(TDirectory * dir);

   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual Double_t beff(TString workpoint, Double_t x);
   virtual Double_t ceff(TString workpoint, Double_t x);
   virtual Double_t leff(TString workpoint, Double_t x);
   virtual Double_t b_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t c_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t l_scale(TString type, TString workpoint, Double_t x);
   Double_t btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low);
   void read_csv_info();

   void set_cut_value(TString year = "2018");
   void hist_Sumw2();
   void hist_Scale();
   void save_result();
   void init_sf();
   void endJob();
   TFile *fout;
   ofstream ParamSetf ;
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


   // pile up weight
   pu_weight_input = new TFile ("./scalef/puweight_2018.root");
   h_pu_weight = (TH1D*)pu_weight_input->Get("h2");

   // photon medium ID weight
   photon_ID_weight_input = new TFile ("./scalef/photon/2018_PhotonsMedium.root");
   h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   muon_HLT_weight_input = new TFile ("./scalef/muon/EfficienciesAndSF_2018Data_AfterMuonHLTUpdate.root");
   muon_HLT_weight_dir  = (TDirectory*)muon_HLT_weight_input->Get("IsoMu24_PtEtaBins");
   h_muon_HLT_weight = (TH2D*)muon_HLT_weight_dir->Get("abseta_pt_ratio");

   // muon ID weight
   muon_ID_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ID.root");
   h_muon_ID_weight = (TH2D*)muon_ID_weight_input->Get("NUM_TightID_DEN_TrackerMuons_pt_abseta");

   // muon iso weight
   muon_iso_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ISO.root");
   h_muon_iso_weight = (TH2D*)muon_iso_weight_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

   // electron reco weight
   electron_reco_weight_input = new TFile ("./scalef/electron/EGM2D_electron_Reco.root");
   h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID weight
   electron_ID_weight_input = new TFile ("./scalef/electron/2018_ElectronTight.root");
   h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");

   // electron HLT weight
   electron_HLT_weight_input = new TFile ("./scalef/electron/2018_egamma_hlt_sf.root");
   h_electron_HLT_weight = (TH2D*)electron_HLT_weight_input->Get("EGamma_SF2D");

   if(index==1)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM0_paramsets_" + ".txt"); name = "fM0";}
   if(index==2)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM1_paramsets_" + ".txt"); name = "fM1";}
   if(index==3)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM2_paramsets_" + ".txt"); name = "fM2";}
   if(index==4)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM3_paramsets_" + ".txt"); name = "fM3";}
   if(index==5)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM4_paramsets_" + ".txt"); name = "fM4";}
   if(index==6)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM5_paramsets_" + ".txt"); name = "fM5";}
   if(index==7)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM6_paramsets_" + ".txt"); name = "fM6";}
   if(index==8)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fM7_paramsets_" + ".txt"); name = "fM7";}
   if(index==9)  {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT0_paramsets_" + ".txt"); name = "fT0";}
   if(index==10) {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT1_paramsets_" + ".txt"); name = "fT1";}
   if(index==11) {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT2_paramsets_" + ".txt"); name = "fT2";}
   if(index==12) {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT5_paramsets_" + ".txt"); name = "fT5";}
   if(index==13) {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT6_paramsets_" + ".txt"); name = "fT6";}
   if(index==14) {ParamSetf.open(m_dataset + "/" + m_year + "_" +  m_channel + "_fT7_paramsets_" + ".txt"); name = "fT7";}
/*
   if(index==1)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM0_paramsets_" + ".txt"); name = "fM0";}
   if(index==2)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM1_paramsets_" + ".txt"); name = "fM1";}
   if(index==3)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM2_paramsets_" + ".txt"); name = "fM2";}
   if(index==4)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM3_paramsets_" + ".txt"); name = "fM3";}
   if(index==5)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM4_paramsets_" + ".txt"); name = "fM4";}
   if(index==6)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM5_paramsets_" + ".txt"); name = "fM5";}
   if(index==7)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM6_paramsets_" + ".txt"); name = "fM6";}
   if(index==8)  {ParamSetf.open(m_dataset + "/" + m_year + "_fM7_paramsets_" + ".txt"); name = "fM7";}
   if(index==9)  {ParamSetf.open(m_dataset + "/" + m_year + "_fT0_paramsets_" + ".txt"); name = "fT0";}
   if(index==10) {ParamSetf.open(m_dataset + "/" + m_year + "_fT1_paramsets_" + ".txt"); name = "fT1";}
   if(index==11) {ParamSetf.open(m_dataset + "/" + m_year + "_fT2_paramsets_" + ".txt"); name = "fT2";}
   if(index==12) {ParamSetf.open(m_dataset + "/" + m_year + "_fT5_paramsets_" + ".txt"); name = "fT5";}
   if(index==13) {ParamSetf.open(m_dataset + "/" + m_year + "_fT6_paramsets_" + ".txt"); name = "fT6";}
   if(index==14) {ParamSetf.open(m_dataset + "/" + m_year + "_fT7_paramsets_" + ".txt"); name = "fT7";}
*/
   fout = new TFile(m_dataset + "/" + m_year + "_" + m_channel + "_" + name + "_WG_aqgc_" + m_btag_workpoint + ".root" , "RECREATE");
   iii = 1+(index-1)*16;

   TString m_year;
   TString m_sample;
   TString m_type;
   TString m_channel;
   TString m_btag_workpoint;
   TString name;
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
   ifstream fin("./scalef/jet/DeepCSV_102XSF_WP_V1.csv");
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

void test::save_result() {
   //fout = new TFile(m_dataset, "RECREATE");
   fout->cd();

   double rsm = rf[8];
   rf[0]=rf[0]/rsm;
   rf[1]=rf[1]/rsm;
   rf[2]=rf[2]/rsm;
   rf[3]=rf[3]/rsm;
   rf[4]=rf[4]/rsm;
   rf[5]=rf[5]/rsm;
   rf[6]=rf[6]/rsm;
   rf[7]=rf[7]/rsm;
   rf[8]=rf[8]/rsm; //SM
   rf[9]=rf[9]/rsm;
   rf[10]=rf[10]/rsm;
   rf[11]=rf[11]/rsm;
   rf[12]=rf[12]/rsm;
   rf[13]=rf[13]/rsm;
   rf[14]=rf[14]/rsm;
   rf[15]=rf[15]/rsm;
   rf[16]=rf[16]/rsm;
   //TGraph *gr = new TGraph(17,xf,rf);
   double low;
   double high;

   TGraph *gr ;
   if(index==1) {low=-120; high=120; double xf[17] = { -120, -60, -30, -25, -20, -15, -10, -8, 0, 8, 10, 15, 20, 25, 30, 60, 120}; gr = new TGraph(17,xf,rf);}
   if(index==2) {low=-200; high=200; double xf[17] = {-200, -80, -60, -40, -30, -25, -20, -10, 0, 10, 20, 25, 30, 40, 60, 80, 200}; gr = new TGraph(17,xf,rf);}
   if(index==3) {low=-50;  high=50;  double xf[17] = {-50, -20, -15, -13, -11, -10, -5, -1, 0, 1, 5, 10, 11, 13, 15, 20, 50}; gr = new TGraph(17,xf,rf);}
   if(index==4) {low=-80;  high=80;  double xf[17] = {-80, -40, -30, -25, -20, -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 40, 80}; gr = new TGraph(17,xf,rf);}
   if(index==5) {low=-80;  high=80;  double xf[17] = {-80, -40, -30, -20, -15, -13, -10, -8, 0, 8, 10, 13, 15, 20, 30, 40, 80}; gr = new TGraph(17,xf,rf);}
   if(index==6) {low=-90;  high=90;  double xf[17] = {-90, -40, -30, -20, -18, -15, -13, -10, 0, 10, 13, 15, 18, 20, 30, 40, 90}; gr = new TGraph(17,xf,rf);}
   if(index==7) {low=-200; high=200; double xf[17] = {-200, -80, -60, -50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 80, 200}; gr = new TGraph(17,xf,rf);}
   if(index==8) {low=-200; high=200; double xf[17] = {-200, -80, -60, -50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 80, 200}; gr = new TGraph(17,xf,rf);}
   if(index==9) {low=-10;  high=10;  double xf[17] = {-10, -6, -4, -2, -1.5, -1.2, -1, -0.8, 0, 0.8, 1, 1.2, 1.5, 2, 4, 6, 10}; gr = new TGraph(17,xf,rf);}
   if(index==10) {low=-10; high=10;  double xf[17] = {-10, -6, -4, -2.5, -1.5, -1, -0.8, -0.5, 0, 0.5, 0.8, 1, 1.5, 2.5, 4, 6, 10}; gr = new TGraph(17,xf,rf);}
   if(index==11) {low=-20; high=20;  double xf[17] = {-20, -12, -8, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 8, 12, 20}; gr = new TGraph(17,xf,rf);}
   if(index==12) {low=-8;  high=8;   double xf[17] = {-8, -5, -3, -2.5, -2, -1.5, -1, -0.6, 0, 0.6, 1, 1.5, 2, 2.5, 3, 5, 8}; gr = new TGraph(17,xf,rf);}
   if(index==13) {low=-8;  high=8;   double xf[17] = {-8, -5, -3.5, -2.5, -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2, 2.5, 3.5, 5, 8}; gr = new TGraph(17,xf,rf);}
   if(index==14) {low=-15; high=15;  double xf[17] = {-15, -8, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 8, 15}; gr = new TGraph(17,xf,rf);}
   
   //TGraph *gr = new TGraph(17,xf,rf);
   TString tf1_name = TString("signal_proc_")+name+Form("_bin%u",abin+1);
   TF1 *fitFunc = new TF1(tf1_name,"[0]*(x**2) + [1]*x + 1",low,high) ;

   cout<<"OK"<<endl;
   fitFunc->SetParLimits(0,0.,1000) ;
   cout<<"OK"<<endl;
   fitFunc->SetLineColor(kBlue) ;
   cout <<"x1"<<endl;
   //TFitResult * r = gr->Fit(tf1_name,"ESR") ;
   gr->Fit(tf1_name,"ESR") ;
   Double_t chi2   = fitFunc->GetChisquare() ;
   Double_t par0   = fitFunc->GetParameter(0);
   Double_t par1   = fitFunc->GetParameter(1);
   Double_t err0   = fitFunc->GetParError(0) ;
   Double_t err1   = fitFunc->GetParError(1) ;
   //r->Print("V") ;
   fitFunc->Write();
   cout <<"x2"<<endl;

   TCanvas *c1= new TCanvas("c1","fitFunc",500,500) ;
   c1->SetGridx(1) ;
   c1->SetGridy(1) ;
   cout <<"x3"<<endl;

   gr->SetTitle(TString(" Fitted line of AQGC/SM in WGmass : ")+Form("(%.0f,%.0f)",WGbin[abin],WGbin[abin+1])) ;
   cout <<"x4"<<endl;
   gr->GetYaxis()->SetTitleOffset(1.4) ;
   char buffer2[256];
   if(index==1) sprintf(buffer2, "fM0/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==2) sprintf(buffer2, "fM1/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==3) sprintf(buffer2, "fM2/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==4) sprintf(buffer2, "fM3/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==5) sprintf(buffer2, "fM4/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==6) sprintf(buffer2, "fM5/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==7) sprintf(buffer2, "fM6/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==8) sprintf(buffer2, "fM7/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==9) sprintf(buffer2, "fT0/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==10) sprintf(buffer2, "fT1/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==11) sprintf(buffer2, "fT2/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==12) sprintf(buffer2, "fT5/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==13) sprintf(buffer2, "fT6/#Lambda^{4} (#times 10^{-12} GeV)");
   if(index==14) sprintf(buffer2, "fT7/#Lambda^{4} (#times 10^{-12} GeV)");
		gr->GetXaxis()->SetTitle(buffer2) ;
		gr->GetYaxis()->SetTitle("Ratio") ;
		gr->SetMarkerStyle(4) ;
		cout <<"x5"<<endl;
		gr->SetLineWidth(2) ;
		gr->SetLineColor(kBlue) ;
		gr->Draw("AP") ;
		cout <<"x6"<<endl;
		TLegend *leg = new TLegend(0.3,0.58,0.70,0.88) ;
		leg->SetFillColor(10) ;
		leg->AddEntry(gr,"Fitted line: r =  p0 x^{2} + p1 x + 1","L") ;
		cout <<"x7"<<endl;
		leg->AddEntry(gr,Form("p0 = %f ",par0),"") ;
		leg->AddEntry(gr,Form("p1 = %f ",par1),"") ;
		cout <<"x8"<<endl;
		leg->Draw("SAME") ;
		cout <<"x9"<<endl;
		if(index==1) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM0_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==2) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM1_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==3) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM2_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==4) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM3_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==5) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM4_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==6) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM5_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==7) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM6_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==8) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fM7_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==9) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT0_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==10) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT1_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==11) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT2_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==12) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT5_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==13) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT6_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
        if(index==14) c1->SaveAs(m_dataset + "/" + m_year + "_" + m_channel + TString("_fT7_fit")+Form("_WGbin_%u",abin)+TString(".png")) ;
		ParamSetf <<"Bin"<<abin<< ": " << par0 << " " << par1 << " " << endl;
		cout <<"x10 "<<abin<<endl;

   //fout->Close();
   //delete fout;
}

void test::endJob() {
   //fout = new TFile(m_dataset, "RECREATE");
   //fout->cd();
   fout->Close();
   delete fout;
   ParamSetf.close();
}

void test::hist_Sumw2()
{

}

void test::hist_Scale()
{

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
