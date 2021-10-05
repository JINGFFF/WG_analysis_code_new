#!/usr/bin/python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TPad, TFile, TH1, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack

inputname = sys.argv[1]
#outputname = sys.argv[2]

out_file_name = 'run_unfolding.sh'
outfile = open(out_file_name, 'w')
    
f_xxx = TFile.Open(inputname)
h_xxx   = f_xxx.Get("hist_")
bins = h_xxx.GetNbinsX()


outfile.write('text2workspace.py -m 125 -o datacard.root $1 -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel ')
for i in range(bins):
    outfile.write("--PO map='.*genbin"+str(i+1)+".*:r_Bin"+str(i+1)+"[1,-2,4]' ")
outfile.write("\n")

outfile.write("combine datacard.root -M MultiDimFit --algo singles -t -1 --setParameters ")
for i in range(bins):
    if i == bins -1 :
        outfile.write("r_Bin"+str(i+1)+"=1")
    else :
        outfile.write("r_Bin"+str(i+1)+"=1,")

outfile.write(" -m 125 --saveFitResult  > tmp.txt" + '\n')


outfile.write("combine datacard.root -M MultiDimFit --algo singles -t -1 --freezeNuisanceGroups Theory --setParameters ")
for i in range(bins):
    if i == bins -1 :
        outfile.write("r_Bin"+str(i+1)+"=1")
    else :
        outfile.write("r_Bin"+str(i+1)+"=1,")

outfile.write(" -m 125 --saveFitResult  > tmp_freeze_Theory.txt" + '\n')

outfile.close()
