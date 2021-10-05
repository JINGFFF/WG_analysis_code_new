#!/usr/bin/env python
import sys
import os
import re
#from uncertainty_unfold import *
import ROOT
from ROOT import gROOT, THStack, TH1D, TList, TFile, TH2D
from math import fabs, sqrt

sideband1      = sys.argv[1]
sideband2      = sys.argv[2]
outputdir      = sys.argv[3]
os.system("mkdir -p " + outputdir)

f_in_1   = TFile.Open(sideband1)
f_in_2   = TFile.Open(sideband2)

hist_sideband1_barrel = f_in_1.Get("barrel_fraction")
hist_sideband1_endcap = f_in_1.Get("endcap_fraction")

hist_sideband2_barrel = f_in_2.Get("barrel_fraction")
hist_sideband2_endcap = f_in_2.Get("endcap_fraction")

uncer_barrel = []
uncer_endcap = []

hist_barrel_uncer = hist_sideband1_barrel.Clone()
hist_barrel_uncer.SetName("hist_barrel_uncer")
hist_barrel_uncer.SetTitle("hist_barrel_uncer")
hist_endcap_uncer = hist_sideband1_endcap.Clone()
hist_endcap_uncer.SetName("hist_endcap_uncer")
hist_endcap_uncer.SetTitle("hist_endcap_uncer")

for i in range(hist_sideband1_barrel.GetNbinsX()) :
    tmp_uncer_barrel = abs(hist_sideband1_barrel.GetBinContent(i+1) - hist_sideband2_barrel.GetBinContent(i+1))*2/(hist_sideband1_barrel.GetBinContent(i+1) + hist_sideband2_barrel.GetBinContent(i+1))
    tmp_uncer_endcap = abs(hist_sideband1_endcap.GetBinContent(i+1) - hist_sideband2_endcap.GetBinContent(i+1))*2/(hist_sideband1_endcap.GetBinContent(i+1) + hist_sideband2_endcap.GetBinContent(i+1))

    uncer_barrel.append(tmp_uncer_barrel)
    uncer_endcap.append(tmp_uncer_endcap)

    hist_barrel_uncer.SetBinContent(i+1, tmp_uncer_barrel)
    hist_endcap_uncer.SetBinContent(i+1, tmp_uncer_endcap)

fout = TFile( outputdir + '/closuretest_uncertainty.root', 'RECREATE' )
fout.cd()
hist_barrel_uncer.Write()
hist_endcap_uncer.Write()
fout.Close()
f_in_1.Close()
f_in_2.Close()
print(uncer_barrel)
print(uncer_endcap)
