#include "plugin/test.h"
#include "plugin/test.C"
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
   TString outdir = argv[2];
   TString which_year = argv[3]; // 2016,2017,2018
   TString which_channel = argv[4]; // muon, electron
   TString which_type = argv[5]; //data, fakelepton, fakephoton, doublefake, mc
   TString which_sample = argv[6]; // SingleMuon, ...
   TString which_btag_workpoint = argv[7]; // tight, medium, loose ...
 /* index list
 * 1 : fM0
 * 2 : fM1
 * 3 : fM2
 * 4 : fM3
 * 5 : fM4
 * 6 : fM5
 * 7 : fM6
 * 8 : fM7
 * 9 : fT0
 * 10 : fT1
 * 11 : fT2
 * 12 : fT5
 * 13 : fT6
 * 14 : fT7
 */
   TString which_index = argv[8];

   //ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;
   
   TString outname= outdir + "/" + which_year + "_" + which_type + "_" + which_btag_workpoint + "_btag_" + which_sample + ".root";
//   TString outname= outdir + "/" + which_year + "_" + which_channel + "_" + which_type + "_" + which_btag_workpoint + "_btag_" + which_sample + ".root";

   cout<<"\033[34myear            : "<<which_year<<"\033[0m"<<endl;
   cout<<"\033[34mchannel         : "<<which_channel<<" channel"<<"\033[0m"<<endl;
   cout<<"\033[34mtype            : "<<which_type<<"\033[0m"<<endl;
   cout<<"\033[34msample          : "<<which_sample<<"\033[0m"<<endl;
   cout<<"\033[34mbtag workpoint  : "<<which_btag_workpoint<<"\033[0m"<<endl;

   cout<<"\033[34minput file list : "<<filetxt<<"\033[0m"<<endl;
   cout<<"\033[34moutput dir     : "<<outdir<<"\033[0m"<<endl<<endl;

   clock_t startTime,endTime;
   startTime = clock();

   test m;
   m.m_dataset = outdir;
   m.m_year = which_year;
   m.m_channel = which_channel;
   m.m_sample = which_sample;
   m.m_type = which_type;
   m.m_btag_workpoint = which_btag_workpoint;
   if(which_index == "1") m.index = 1;
   if(which_index == "2") m.index = 2;
   if(which_index == "3") m.index = 3;
   if(which_index == "4") m.index = 4;
   if(which_index == "5") m.index = 5;
   if(which_index == "6") m.index = 6;
   if(which_index == "7") m.index = 7;
   if(which_index == "8") m.index = 8;
   if(which_index == "9") m.index = 9;
   if(which_index == "10") m.index = 10;
   if(which_index == "11") m.index = 11;
   if(which_index == "12") m.index = 12;
   if(which_index == "13") m.index = 13;
   if(which_index == "14") m.index = 14;

   m.Init();

   m.read_csv_info();
int bin = 0;
   for(int bin=0; bin<5; bin++){
      ifstream infile(filetxt);
      k = 1;
      n = 0;
      m.abin = bin;
      cout<<"bin : "<<bin<<endl;
      while (k>0){
         getline (infile, buffer) ;
         n++;
         infilename = buffer;
         if(infilename.Contains(".root")==0) {k=-2; continue;}

         //if(infilename.Contains("#")==0) continue;
         cout<<"file "<<n<<" : "<<infilename<<endl;
         if(infilename.Contains("#")) {
            cout<<"Do not run this file !!!"<<endl; 
            continue;
         }

         TFile *file1 =new TFile(infilename);

         //TTree *tree1 = (TTree*) file1->Get("PKUCandidates");
         //m.Init();
         TDirectory * dir1 = (TDirectory*)file1->Get("treeDumper");
      TTree *tree1 = (TTree*) dir1->Get("tree1");
      m.Loop(dir1, tree1);
         endTime = clock();
         file1->Close();
         cout<<"The run time is: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
      }
      infile.close();
      m.save_result();
   }
   //m.hist_Scale();
   m.endJob();
   endTime = clock();

   cout<<"The total run time is: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
   return 0;
}
