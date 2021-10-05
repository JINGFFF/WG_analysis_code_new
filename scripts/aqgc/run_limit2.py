#!/usr/bin/python

import sys
import time
import os   
year              = sys.argv[1];
fit_parameter_dir = sys.argv[2];
datacard          = sys.argv[3];
outdir            = sys.argv[4];
a_type            = sys.argv[5];

fit_parameter_dir1 = sys.argv[6];
fit_parameter_dir2 = sys.argv[7];
fit_parameter_dir3 = sys.argv[8];

#EO            = sys.argv[9];

os.system("mkdir -p " + outdir);
   
operator = ["fM0","fM1","fM2","fM3","fM4","fM5","fM6","fM7","fT0","fT1","fT2","fT5","fT6","fT7"]
operator_latex = ["F_{M,0}","F_{M,1}","F_{M,2}","F_{M,3}","F_{M,4}","F_{M,5}","F_{M,6}","F_{M,7}","F_{T,0}","F_{T,1}","F_{T,2}","F_{T,5}","F_{T,6}","F_{T,7}"]
lower = ["-20", "-25", "-10", "-15", "-20", "-30", "-40", "-40", "-5", "-5", "-5", "-5", "-5", "-5"]
upper = ["20", "25", "10", "15", "20", "30", "40", "40", "5", "5", "5", "5", "5", "5"]

#lower = ["-20", "-200", "-50", "-80", "-80", "-90", "-200", "-200", "-10", "-10", "-20", "-8", "-8", "-15"]
#upper = ["20", "200", "50", "80", "80", "90", "200", "200", "10", "10", "20", "8", "8", "15"]
my_1d_model = ''
if a_type == "one":
    my_1d_model = 'my_1d_model2'
if a_type == "combine":
    my_1d_model = 'my_1d_model3'

for i in range(2,3) :
    #for i in range(len(operator)) :
    print("operator: " + lower[i] + " " +upper[i])
    if a_type == "one":
        os.system("re-scale.py " + year + " " + operator[i] + " " + fit_parameter_dir + " " + outdir + " " + a_type + " " + lower[i] + " " + upper[i])
    if a_type == "combine":
        os.system("re-scale.py " + "2016" + " " + operator[i] + " " + fit_parameter_dir1 + " " + outdir + " " + a_type + " " + lower[i] + " " + upper[i])
        os.system("re-scale.py " + "2017" + " " + operator[i] + " " + fit_parameter_dir2 + " " + outdir + " " + a_type + " " + lower[i] + " " + upper[i])
        os.system("re-scale.py " + "2018" + " " + operator[i] + " " + fit_parameter_dir3 + " " + outdir + " " + a_type + " " + lower[i] + " " + upper[i])
        os.system("hadd " + outdir+"/" + year + "_" + operator[i] + "_scaling_refined.root " + outdir+"/" + "2016" + "_" + operator[i] + "_scaling_refined.root " + outdir+"/" + "2017" + "_" + operator[i] + "_scaling_refined.root " + outdir+"/" + "2018" + "_" + operator[i] + "_scaling_refined.root")

    os.system("text2workspace.py -m 126 " + datacard+ " -o " + outdir + "/os_" + year + "_" + operator[i] + ".root -P HiggsAnalysis.CombinedLimit.OneParameterPhysicsModel:"+my_1d_model+" --PO range_param=[" + lower[i] + "," + upper[i] + "] --PO scaling_filename="+outdir+"/" + year + "_" + operator[i] + "_scaling_refined.root")
    print('ok--------------')
    os.system("combine " + outdir + "/os_" + year + "_" + operator[i] + ".root -M MultiDimFit -t -1 -P param --floatOtherPOIs=0 --algo=grid --points=500 --cminDefaultMinimizerStrategy=2")
    os.system("mv higgsCombineTest.MultiDimFit.mH120.root " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + operator[i] + ".root")
    os.system("draw_limit.py " + year + " " + outdir + " " + operator[i] + " '" + operator_latex[i] + "/#Lambda^{4} [TeV^{-4}]' " + "'Expected 95% CL interval' " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + operator[i] + ".root 'Expected 2#DeltaNLL'");
