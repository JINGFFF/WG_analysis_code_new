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
   TFile * fake_input = TFile::Open(input_pt_distribution + "/" + year + "_medium_btag_fake.root");
   TFile * data_input = TFile::Open(input_pt_distribution + "/" + year + "_medium_btag_data.root");
cout<<"ok1"<<endl;
   TH1F* fraction_barrel = (TH1F*)fraction_file->Get("barrel_fraction");
   TH1F* fraction_endcap = (TH1F*)fraction_file->Get("endcap_fraction");
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
cout<<"ok4"<<endl;
   TH1F endcap_fake_photon_weight = (*data_endcap)*(*fraction_endcap);
   endcap_fake_photon_weight.Divide(fake_endcap);
   endcap_fake_photon_weight.SetTitle("endcap_fake_photon_weight");
   endcap_fake_photon_weight.SetName("endcap_fake_photon_weight");
cout<<"ok5"<<endl;
   output->cd();  
cout<<"ok6"<<endl;

   barrel_fake_photon_weight.Write();
cout<<"ok7"<<endl;

   endcap_fake_photon_weight.Write();
cout<<"ok8"<<endl;

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
