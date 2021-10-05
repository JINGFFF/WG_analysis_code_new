#include "TFile.h"
#include "TH1D.h"
#include "TString.h"
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
/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString filetxt = argv[1];
   TString indir = argv[2];
   TString outdir = argv[3];
   TString which_year = argv[4]; // 2016,2017,2018

   ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;

   double lumi;
   if(which_year == "2016") {
      lumi = 35.92;
   }
   if(which_year == "2017") {
      lumi = 41.50;
   }
   if(which_year == "2018") {
      lumi = 59.74;
   }
 
cout<<"ok "<<lumi<<endl;
   //TString outname= outdir + "/" + which_year + "_" + which_channel + "_" + which_type + "_" + which_btag_workpoint + "_btag_" + which_sample + ".root";
   while (k>0){
      getline (infile, buffer) ;
      n++;
      infilename = indir + "/" + buffer;
cout<<infilename<<endl;
      if(infilename.Contains(".root")==0) {k=-2; continue;}
      TString outname= outdir + "/scaled_"+ buffer; 
      //if(infilename.Contains("#")==0) continue;
      cout<<"file "<<n<<" : "<<infilename<<endl;
      cout<<"lumi : "<<lumi<<endl;
      if(infilename.Contains("#")) {
         cout<<"Do not run this file !!!"<<endl; 
         continue;
      }

      TFile *file1 =new TFile(infilename);
      TFile *fout = new TFile(outname, "RECREATE");
      TH1D	*hist_nominal = (TH1D*)file1->Get("nominal");
      TH1D  *hist_up = (TH1D*)file1->Get("up");
      TH1D  *hist_down = (TH1D*)file1->Get("down");

      hist_nominal->Scale(lumi);
      hist_up->Scale(lumi);
      hist_down->Scale(lumi);

      fout->cd();
      hist_nominal->Write();
      hist_up->Write();
      hist_down->Write();
      fout->Close();
      file1->Close();
   }

   return 0;
}
