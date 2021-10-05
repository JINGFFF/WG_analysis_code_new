#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TString.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TMath.h"
#include "TROOT.h"
#include <TFractionFitter.h>
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

TFile* output;

void fake_photon_weight(TString year, TString input_fraction, TString input_pt_distribution){

   //TFile* output = new TFile("fake_photon_weight.root","RECREATE");

   TFile * fraction_file = TFile::Open(input_fraction + "/result_.root");
   TFile * closure_fraction_file = TFile::Open(input_fraction + "/closure_.root");
   TFile * sideband_fraction_file = TFile::Open(input_fraction + "/sideband.root");

   TFile * fake_input = TFile::Open(input_pt_distribution + "/" + year + "_medium_btag_fake.root");
   TFile * data_input = TFile::Open(input_pt_distribution + "/" + year + "_medium_btag_data.root");
cout<<"ok1"<<endl;
   TH1F* fraction_barrel = (TH1F*)fraction_file->Get("barrel_fraction");
fraction_barrel->SetTitle("fraction_barrel");
fraction_barrel->SetName("fraction_barrel");

   TH1F* fraction_endcap = (TH1F*)fraction_file->Get("endcap_fraction");



   TH1F* fraction_barrel_error = (TH1F*)fraction_file->Get("barrel_fraction_error");
   TH1F* fraction_endcap_error = (TH1F*)fraction_file->Get("endcap_fraction_error");
//barrel_fraction_error

   TH1F* fraction_barrel_up = (TH1F*)fraction_file->Get("barrel_fraction");
fraction_barrel_up->SetTitle("fraction_barrel_up");
fraction_barrel_up->SetName("fraction_barrel_up");

   TH1F* fraction_endcap_up = (TH1F*)fraction_file->Get("endcap_fraction");

   TH1F* fraction_barrel_down = (TH1F*)fraction_file->Get("barrel_fraction");
   TH1F* fraction_endcap_down = (TH1F*)fraction_file->Get("endcap_fraction");



   TH1F* closure_fraction_barrel = (TH1F*)closure_fraction_file->Get("barrel_fraction");
   TH1F* closure_fraction_endcap = (TH1F*)closure_fraction_file->Get("endcap_fraction");

   TH1F* sideband_fraction_barrel = (TH1F*)sideband_fraction_file->Get("barrel_fraction");
   TH1F* sideband_fraction_endcap = (TH1F*)sideband_fraction_file->Get("endcap_fraction");

    for (int i=1; i<=7; i++){
cout<<1 + sqrt(pow(fraction_barrel_error->GetBinContent(i),2) + pow(closure_fraction_barrel->GetBinContent(i),2) + pow(sideband_fraction_barrel->GetBinContent(i),2) )<<endl;
        fraction_barrel_up->SetBinContent(i,fraction_barrel_up->GetBinContent(i)*(1 + sqrt(pow(fraction_barrel_error->GetBinContent(i),2) + pow(closure_fraction_barrel->GetBinContent(i),2) + pow(sideband_fraction_barrel->GetBinContent(i),2) )));
        fraction_barrel_down->SetBinContent(i,fraction_barrel_down->GetBinContent(i)*(1 - sqrt(pow(fraction_barrel_error->GetBinContent(i),2) + pow(closure_fraction_barrel->GetBinContent(i),2) + pow(sideband_fraction_barrel->GetBinContent(i),2) )));
        fraction_endcap_up->SetBinContent(i,fraction_endcap_up->GetBinContent(i)*(1 + sqrt(pow(fraction_endcap_error->GetBinContent(i),2) + pow(closure_fraction_endcap->GetBinContent(i),2) + pow(sideband_fraction_endcap->GetBinContent(i),2) )));
        fraction_endcap_down->SetBinContent(i,fraction_endcap_down->GetBinContent(i)*(1 - sqrt(pow(fraction_endcap_error->GetBinContent(i),2) + pow(closure_fraction_endcap->GetBinContent(i),2) + pow(sideband_fraction_endcap->GetBinContent(i),2) )));
    }


cout<<"ok2"<<endl;
   TH1F* fake_barrel = (TH1F*)fake_input->Get("barrel_photonpt");
   TH1F* fake_endcap = (TH1F*)fake_input->Get("endcap_photonpt");

   TH1F* data_barrel = (TH1F*)data_input->Get("barrel_photonpt");
   TH1F* data_endcap = (TH1F*)data_input->Get("endcap_photonpt");
cout<<"ok3"<<endl;
   TH1F barrel_fake_photon_weight = (*data_barrel)*(*fraction_barrel);
   barrel_fake_photon_weight.Divide(fake_barrel);
   barrel_fake_photon_weight.SetTitle("barrel_fake_photon_weight");
   barrel_fake_photon_weight.SetName("barrel_fake_photon_weight");

   TH1F barrel_fake_photon_weight_up = (*data_barrel)*(*fraction_barrel_up);
   barrel_fake_photon_weight_up.Divide(fake_barrel);
   barrel_fake_photon_weight_up.SetTitle("barrel_fake_photon_weight_up");
   barrel_fake_photon_weight_up.SetName("barrel_fake_photon_weight_up");

   TH1F barrel_fake_photon_weight_down = (*data_barrel)*(*fraction_barrel_down);
   barrel_fake_photon_weight_down.Divide(fake_barrel);
   barrel_fake_photon_weight_down.SetTitle("barrel_fake_photon_weight_down");
   barrel_fake_photon_weight_down.SetName("barrel_fake_photon_weight_down");

cout<<"ok4"<<endl;
   TH1F endcap_fake_photon_weight = (*data_endcap)*(*fraction_endcap);
   endcap_fake_photon_weight.Divide(fake_endcap);
   endcap_fake_photon_weight.SetTitle("endcap_fake_photon_weight");
   endcap_fake_photon_weight.SetName("endcap_fake_photon_weight");

   TH1F endcap_fake_photon_weight_up = (*data_endcap)*(*fraction_endcap_up);
   endcap_fake_photon_weight_up.Divide(fake_endcap);
   endcap_fake_photon_weight_up.SetTitle("endcap_fake_photon_weight_up");
   endcap_fake_photon_weight_up.SetName("endcap_fake_photon_weight_up");

   TH1F endcap_fake_photon_weight_down = (*data_endcap)*(*fraction_endcap_down);
   endcap_fake_photon_weight_down.Divide(fake_endcap);
   endcap_fake_photon_weight_down.SetTitle("endcap_fake_photon_weight_down");
   endcap_fake_photon_weight_down.SetName("endcap_fake_photon_weight_down");

cout<<"ok5"<<endl;
   output->cd();  
cout<<"ok6"<<endl;
fraction_barrel->SetTitle("fraction_barrel");
fraction_barrel->SetName("fraction_barrel");

fraction_barrel->Write();
fraction_barrel_up->Write();


   barrel_fake_photon_weight.Write();
   barrel_fake_photon_weight_up.Write();
   barrel_fake_photon_weight_down.Write();

   endcap_fake_photon_weight.Write();
   endcap_fake_photon_weight_up.Write();
   endcap_fake_photon_weight_down.Write();
   //output->Close();
}

int main(int argc, char** argv){
   TString year = argv[1];
   TString input_fraction = argv[2];
   TString input_pt_distribution = argv[3];
   TString outdir = argv[4];
   system("mkdir -p " + outdir);
   output = new TFile(outdir + "/fake_photon_weight.root","RECREATE");
   fake_photon_weight(year, input_fraction, input_pt_distribution);

   output->Close();
cout<<"ok9"<<endl;

   return 0;
cout<<"ok10"<<endl;

}
