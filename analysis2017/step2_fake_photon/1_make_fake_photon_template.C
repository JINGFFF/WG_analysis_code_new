#include "plugin/test_fake_photon.h"
#include "plugin/test_fake_photon.C"
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
#include <time.h>
#include <stdlib.h>
using namespace std;

string getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64]; 
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
}


/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString filetxt = argv[1];
   TString outdir = argv[2];
   TString which_year = argv[3]; // 2016,2017,2018
   TString which_type = argv[4]; // data, mc
   TString which_channel = argv[5]; // muon, electron, all(ele & mu)
   TString which_template_type = argv[6]; //data, true, fake
   TString which_sample = argv[7]; // WGJets, data_lepton ...
   TString which_btag_workpoint = argv[8]; // tight, medium, loose ...

cout<<"ok0"<<endl;
   double CHISO_LOW, CHISO_HIGH;
cout<<"ok1"<<endl;

   sscanf(argv[9],"%lf",&CHISO_LOW);
cout<<"ok2"<<endl;

   sscanf(argv[10],"%lf",&CHISO_HIGH);
cout<<"ok3"<<endl;

   cout<<"invert_chiso : "<<CHISO_LOW<<"-"<<CHISO_HIGH<<endl;
cout<<"ok4"<<endl;
   ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;

   string   time_start = getTime();

   //TString outname= outdir + "/template_" + which_year + "_" + which_btag_workpoint + "_btag_" + which_sample + "_" + which_template_type +  ".root";
   TString outname= outdir + "/" + which_year + "_" + which_btag_workpoint + "_btag_" + which_sample + "_" + which_template_type+"_"+argv[9]+"_"+ argv[10]+  ".root";

   cout<<"\033[34myear            : "<<which_year<<"\033[0m"<<endl;
   cout<<"\033[34mchannel         : "<<which_channel<<" channel"<<"\033[0m"<<endl;
   cout<<"\033[34mtemplate type   : "<<which_template_type<<"\033[0m"<<endl;
   cout<<"\033[34msample          : "<<which_sample<<"\033[0m"<<endl;
   cout<<"\033[34mbtag workpoint  : "<<which_btag_workpoint<<"\033[0m"<<endl;

   cout<<"\033[34minput file list : "<<filetxt<<"\033[0m"<<endl;
   cout<<"\033[34moutput file     : "<<outname<<"\033[0m"<<endl<<endl;


   class test m;
   m.m_dataset = outname;
   m.m_year = which_year;
   m.m_channel = which_channel;
   m.m_type = which_type;
   m.m_sample = which_sample;
   m.m_template_type = which_template_type;
   m.m_btag_workpoint = which_btag_workpoint;
   m.invert_chiso_low = CHISO_LOW;
   m.invert_chiso_high = CHISO_HIGH;

   m.Init();
   m.read_csv_info();

   system("echo `date '+%Y%m%d - %Hh  %Mm  %Ss'`");
   while (k>0){
      getline (infile, buffer) ;
      n++;
      infilename = buffer;
      if(infilename.Contains(".root")==0) {k=-2; continue;}

      cout<<"file "<<n<<" : "<<infilename<<endl;
      if(infilename.Contains("#")) {
         cout<<"Do not run this file !!!"<<endl; 
         continue;
      }

      TFile *file1 =new TFile(infilename);

      TDirectory * dir1 = (TDirectory*)file1->Get("treeDumper");
      TTree *tree1 = (TTree*) dir1->Get("tree1");

      m.Loop(dir1,tree1);
      file1->Close();
   }
   m.hist_Scale();
   m.endJob();
   string   time_end = getTime();
   cout<<endl<<endl<<"time start : "<<time_start<<endl<<"time end   : "<<time_end<<endl;

   return 0;
}
