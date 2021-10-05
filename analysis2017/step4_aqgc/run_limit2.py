import sys
import time
import os   
year              = sys.argv[1];
fit_parameter_dir = sys.argv[2];
datacard          = sys.argv[3];
outdir            = sys.argv[4];

os.system("mkdir -p " + outdir);
   
operator = ["fM0","fM1","fM2","fM3","fM4","fM5","fM6","fM7","fT0","fT1","fT2","fT5","fT6","fT7"]
operator_latex = ["F_{M,0}","F_{M,1}","F_{M,2}","F_{M,3}","F_{M,4}","F_{M,5}","F_{M,6}","F_{M,7}","F_{T,0}","F_{T,1}","F_{T,2}","F_{T,5}","F_{T,6}","F_{T,7}"]
lower = ["-120", "-200", "-50", "-80", "-80", "-90", "-200", "-200", "-10", "-10", "-20", "-8", "-8", "-15"]
upper = ["120", "200", "50", "80", "80", "90", "200", "200", "10", "10", "20", "8", "8", "15"]

for i in range(1,2) :
#for i in range(len(operator)) :
    print("operator: " + lower[i] + " " +upper[i])
    os.system("python re-scale.py " + year + " " + operator[i] + " " + fit_parameter_dir + " " + outdir + " " + lower[i] + " " + upper[i])
    os.system("text2workspace.py -m 126 " + datacard+ " -o " + outdir + "/os_" + year + "_" + operator[i] + ".root -P HiggsAnalysis.CombinedLimit.OneParameterPhysicsModel:my_1d_model2 --PO range_param=[" + lower[i] + "," + upper[i] + "] --PO scaling_filename="+outdir+"/" + year + "_" + operator[i] + "_scaling_refined.root")

    os.system("combine " + outdir + "/os_" + year + "_" + operator[i] + ".root -M MultiDimFit -t -1 -P param --floatOtherPOIs=0 --algo=grid --points=5000 --cminDefaultMinimizerStrategy=2")
    os.system("mv higgsCombineTest.MultiDimFit.mH120.root " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + operator[i] + ".root")
    os.system("python draw_limit.py " + year + " " + outdir + " " + operator[i] + " '" + operator_latex[i] + "/#Lambda^{4} [TeV^{-4}]' " + "'Observed 95% CL interval' " + outdir + "/higgsCombineTest.MultiDimFit.mH120.observed." + year + "." + operator[i] + ".root 'Observed 2#DeltaNLL'");
