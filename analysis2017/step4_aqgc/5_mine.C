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
#include "TString.h"
using namespace std;
/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString year = argv[1];
   TString which_channel = argv[2];
   TString indir = argv[3];
   TString datacard = argv[4];

   TString outdir = argv[5];
   system("mkdir -p " + outdir);
   //TString which_year = argv[4]; // 2016,2017,2018
   TString op[14] = {"fM0","fM1","fM2","fM3","fM4","fM5","fM6","fM7","fT0","fT1","fT2","fT5","fT6","fT7"};
   TString operator2[14] = {"F_{M,0}","F_{M,1}","F_{M,2}","F_{M,3}","F_{M,4}","F_{M,5}","F_{M,6}","F_{M,7}","F_{T,0}","F_{T,1}","F_{T,2}","F_{T,5}","F_{T,6}","F_{T,7}"};
   TString lower[14] = {"-120", "-200", "-50", "-80", "-80", "-90", "-200", "-200", "-10", "-10", "-20", "-8", "-8", "-15"};
   TString upper[14] = {"120", "200", "50", "80", "80", "90", "200", "200", "10", "10", "20", "8", "8", "15"};

   for(int i = 0; i<14; i++){
      cout<<"operator: "<<op[i]<< " "<<lower[i]<<" "<<upper[i]<<endl;
      //system("python 5_mine_all.py " + year + " " + op[i] + " " + indir + " " + outdir + " " + lower[i] + " " + upper[i]);

      system("python 5_mine.py " + year + " " + which_channel + " " + op[i] + " " + indir + " " + outdir + " " + lower[i] + " " + upper[i]);
      //system("python 5_mine.py " + year + " electron " + op[i] + " " + indir + " " + outdir + " " + lower[i] + " " + upper[i]);
      //muon
      system("text2workspace.py -m 126 ./"+datacard+ " -o " + outdir + "/os_" + year + "_" + op[i] + ".root -P HiggsAnalysis.CombinedLimit.OneParameterPhysicsModel:my_1d_model2 --PO range_param=[" + lower[i] + "," + upper[i] + "] --PO scaling_filename="+outdir+"/" + year + "_" + op[i] + "_scaling_refined.root");
      system("combine " + outdir + "/os_" + year + "_" + op[i] + ".root -M MultiDimFit -t -1 -P param --floatOtherPOIs=0 --algo=grid --points=5000 --cminDefaultMinimizerStrategy=2");
      system("mv higgsCombineTest.MultiDimFit.mH120.root " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + op[i] + ".root");
      system("python2.6 5_draw_1d_limit_plot.py " + year +" " + which_channel + " " + outdir + " " + op[i] + " '" + operator2[i] + "/#Lambda^{4} [TeV^{-4}]' " + "'Observed 95% CL interval' " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + op[i] + ".root 'Observed 2#DeltaNLL'");
      cout<<"ok"<<endl;
   }
   return 0;
}
