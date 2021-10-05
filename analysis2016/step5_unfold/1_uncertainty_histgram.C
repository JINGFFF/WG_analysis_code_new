#include "plugin/test.h"
//#include "plugin/test.C"
//#include "plugin/test_pujet.C"
#include "plugin/test_pujet_ptlep.C"
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


using namespace std;
/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString filetxt = argv[1];
   TString outdir = argv[2];
   TString which_year = argv[3]; // 2016,2017,2018
   TString which_channel = argv[4]; // muon, electron
   TString which_type = argv[5]; //data, fakelepton, fakephoton, doublefake, mc
   TString which_region = argv[6]; // aqgc, signal, control

   TString barrel_or_endcap = argv[7]; // barrel or endcap
   TString which_sample = argv[8]; // SingleMuon, ...
   TString which_btag_workpoint = argv[9]; // tight, medium, loose ...
   TString which_pujet_workpoint = argv[10]; // T, M, L

   ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;
   
   TString outname= outdir + "/" + which_year + "_" + which_channel + "_" + which_type + "_" + which_region +"_"+barrel_or_endcap+ "_" + which_sample + ".root";

   cout<<"\033[34myear             : "<<which_year<<"\033[0m"<<endl;
   cout<<"\033[34mregion           : "<<which_region<<" region"<<"\033[0m"<<endl;
   cout<<"\033[34mchannel          : "<<which_channel<<" channel"<<"\033[0m"<<endl;
   cout<<"\033[34mbarrel_or_endcap : "<<barrel_or_endcap<<"\033[0m"<<endl;

   cout<<"\033[34mtype             : "<<which_type<<"\033[0m"<<endl;
   cout<<"\033[34msample           : "<<which_sample<<"\033[0m"<<endl;
   cout<<"\033[34mbtag workpoint   : "<<which_btag_workpoint<<"\033[0m"<<endl;
   cout<<"\033[34mpujet workpoint   : "<<which_pujet_workpoint<<"\033[0m"<<endl;

   cout<<"\033[34minput file list  : "<<filetxt<<"\033[0m"<<endl;
   cout<<"\033[34moutput file      : "<<outname<<"\033[0m"<<endl<<endl;
   string   time_start = getTime();


   test m;
   m.m_dataset = outname;
   m.m_year = which_year;
   m.m_channel = which_channel;
   m.m_sample = which_sample;
   m.m_type = which_type;
   m.m_region = which_region;
   m.m_bORe = barrel_or_endcap;

   m.m_btag_workpoint = which_btag_workpoint;
   m.m_pujet_workpoint = which_pujet_workpoint;

   m.Init();
   m.read_csv_info();
   creat_hist();
   //m.hist_Sumw2();
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
   //m.hist_Scale();
   m.endJob();
   string   time_end = getTime();
   cout<<endl<<endl<<"time start : "<<time_start<<endl<<"time end   : "<<time_end<<endl;

   return 0;
}
