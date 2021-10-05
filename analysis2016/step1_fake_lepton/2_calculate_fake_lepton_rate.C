#include "TCanvas.h"
#include "TFile.h"
#include "TH2.h"
#include "TMath.h"
#include "TROOT.h"
#include "TString.h"
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

TH2D* fakerate;
TH2D* fenzi;
TH2D* fenmu;
TH2D* weight;


void calculator(TString year, TString channel, TString inputdir, TFile * output){
   double lumi;
   if(year == "2016") lumi = 35.92;
   if(year == "2017") lumi = 4.794;//41.50;
   if(year == "2018") lumi = 59.74;

   TFile* file_tight_lepton = TFile::Open(inputdir + "/" + channel + "_data_tight_single_" + channel + ".root");
   TFile* file_loose_lepton = TFile::Open(inputdir + "/" + channel + "_data_loose_single_" + channel + ".root");
   TFile* file_tight_wjets_0j = TFile::Open(inputdir + "/" + channel + "_mc_tight_WJets_0j.root");
   TFile* file_loose_wjets_0j = TFile::Open(inputdir + "/" + channel + "_mc_loose_WJets_0j.root");

   TFile* file_tight_wjets_1j = TFile::Open(inputdir + "/" + channel + "_mc_tight_WJets_1j.root");
   TFile* file_loose_wjets_1j = TFile::Open(inputdir + "/" + channel + "_mc_loose_WJets_1j.root");

   TFile* file_tight_wjets_2j = TFile::Open(inputdir + "/" + channel + "_mc_tight_WJets_2j.root");
   TFile* file_loose_wjets_2j = TFile::Open(inputdir + "/" + channel + "_mc_loose_WJets_2j.root");

   TFile* file_tight_dy = TFile::Open(inputdir + "/" + channel + "_mc_tight_DY.root");
   TFile* file_loose_dy = TFile::Open(inputdir + "/" + channel + "_mc_loose_DY.root");

   TH2D* tight_lepton = (TH2D*)file_tight_lepton->Get("h");
   tight_lepton->SetName("tight_lepton");

   TH2D* loose_lepton = (TH2D*)file_loose_lepton->Get("h");
   loose_lepton->SetName("loose_lepton");

   TH2D* tight_wjets_0j = (TH2D*)file_tight_wjets_0j->Get("h");
   tight_wjets_0j->SetName("tight_wjets_0j");
   tight_wjets_0j->Scale(lumi);
   TH2D* loose_wjets_0j = (TH2D*)file_loose_wjets_0j->Get("h");
   loose_wjets_0j->SetName("loose_wjets_0j");
   loose_wjets_0j->Scale(lumi);

   TH2D* tight_wjets_1j = (TH2D*)file_tight_wjets_1j->Get("h");
   tight_wjets_1j->SetName("tight_wjets_1j");
   tight_wjets_1j->Scale(lumi);

   TH2D* loose_wjets_1j = (TH2D*)file_loose_wjets_1j->Get("h");
   loose_wjets_1j->SetName("loose_wjets_1j");
   loose_wjets_1j->Scale(lumi);

   TH2D* tight_wjets_2j = (TH2D*)file_tight_wjets_2j->Get("h");
   tight_wjets_2j->SetName("tight_wjets_2j");
   tight_wjets_2j->Scale(lumi);

   TH2D* loose_wjets_2j = (TH2D*)file_loose_wjets_2j->Get("h");
   loose_wjets_2j->SetName("loose_wjets_2j");
   loose_wjets_2j->Scale(lumi);

   TH2D* tight_dy = (TH2D*)file_tight_dy->Get("h");
   tight_dy->SetName("tight_dy");
   tight_dy->Scale(lumi);

   TH2D* loose_dy = (TH2D*)file_loose_dy->Get("h");
   loose_dy->SetName("loose_dy");
   loose_dy->Scale(lumi);



   fenzi = (TH2D*)tight_lepton->Clone();
   fenzi->Add(tight_wjets_0j,-1);
   fenzi->Add(tight_wjets_1j,-1);
   fenzi->Add(tight_wjets_2j,-1);

   fenzi->Add(tight_dy,-1);
   fenzi->SetName("numerator");
   fenzi->SetTitle("numerator");

   fenmu = (TH2D*)tight_lepton->Clone();
   fenmu->Add(loose_lepton);
   fenmu->Add(tight_wjets_0j,-1);
   fenmu->Add(loose_wjets_1j,-1);
   fenmu->Add(tight_wjets_1j,-1);
   fenmu->Add(loose_wjets_2j,-1);
   fenmu->Add(tight_wjets_2j,-1);
   fenmu->Add(loose_wjets_0j,-1);

   fenmu->Add(tight_dy,-1);
   fenmu->Add(loose_dy,-1);
   fenmu->SetName("denominator");
   fenmu->SetTitle("denominator");

   fakerate = (TH2D*)fenzi->Clone();
   fakerate->Divide(fenmu);
   fakerate->SetName("fakerate");
   fakerate->SetTitle("fake_rate");

   weight = (TH2D*)fakerate->Clone();
   weight->SetName("weight");
   weight->SetTitle("fake_lepton_weight");

   Int_t n_pt_bin, n_eta_bin;
   if(channel == "electron"){
      n_pt_bin   = 2;
      n_eta_bin  = 5;
   }

   if(channel == "muon"){
      n_pt_bin   = 3;
      n_eta_bin  = 5;
   }

   for (int i = 0; i < n_eta_bin; i++) {
      for (int j = 0; j < n_pt_bin; j++) {
         Double_t tmp     = fakerate->GetBinContent(i + 1, j + 1);
         Double_t wgt_tmp = tmp / (1 - tmp);
         weight->SetBinContent(i + 1, j + 1, wgt_tmp);
      }
   }


   output->cd();
   tight_lepton->Write();
   loose_lepton->Write();
   tight_wjets_0j->Write();
   loose_wjets_0j->Write();
   tight_wjets_1j->Write();
   loose_wjets_1j->Write();
   tight_wjets_2j->Write();
   loose_wjets_2j->Write();

   tight_dy->Write();
   loose_dy->Write();
   fenzi->Write();
   fenmu->Write();
   fakerate->Write();
   weight->Write();
}


int main(int argc, char** argv){
   TString year = argv[1];
   TString channel = argv[2];
   TString inputdir = argv[3];
   TString outdir = argv[4];

   system("mkdir -p " + outdir);
cout<<"ok1"<<endl;
   TFile* outfile = new TFile(outdir + "/" + channel + "_fakerate.root","RECREATE");
cout<<"ok2"<<endl;
   calculator(year, channel, inputdir, outfile);
   outfile->Close();
   return 0;
}
