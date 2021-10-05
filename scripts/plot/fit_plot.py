#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TDirectoryFile, TPad, TGraph, TPad, TFile, TH1D, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array

infilename           = sys.argv[1]
outdir               = sys.argv[2]
which_year           = sys.argv[3]

os.system("mkdir -p " + outdir)

f_in = TFile.Open(infilename)

muon_barrel     = [[1 ,1] , [2, 2] , [3, 3] , [4, 4] , [5, 5] , [6, 6] , [7, 7] , [8, 8] , [9, 9] , [10, 10], [11, 11], [12, 12]]
muon_endcap     = [[1, 13], [2, 14], [3, 15], [4, 16], [5, 17], [6, 17], [7, 18], [8, 20], [9, 21], [10, 22], [11, 23], [12, 24]]
electron_barrel = [[1, 25], [2, 26], [3, 27], [4, 28], [5, 29], [6, 30], [7, 31], [8, 32], [9, 33], [10, 34], [11, 35], [12, 36]]
electron_endcap = [[1, 37], [2, 38], [3, 39], [4, 40], [5, 41], [6, 42], [7, 43], [8, 44], [9, 45], [10, 46], [11, 47], [12, 48]]

hist_name = [
['VBS', 'EW WG'],
['WGJets', 'QCD WG'],
['ZG', 'QCD ZG'],
['TTG', 'TTG'],
['WW', 'WW'],
['WZ', 'WZ'],
['ZZ', 'ZZ'],
['ST_s', 'ST\\_s'],
['ST_t', 'ST\\_t'],
['ST_tbar', 'ST\\_tbar'],
['ST_tW', 'ST\\_tW'],
['ST_tbarW', 'ST\\_tbarW'],
['fakephoton', 'Fake photon'],
['fakelepton', 'Fake lepton'],
['doublefake', 'Double fake'],
['total', 'Total Predict'],
]


h_muon_barrel, h_muon_endcap, h_electron_barrel, h_electron_endcap = [], [], [], []

for i in range(len(hist_name)):
    h_muon_barrel.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
    h_muon_endcap.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
    h_electron_barrel.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
    h_electron_endcap.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))

def read_hist(bin_num, channnel_num, process, h) :
    hname = 'shapes_prefit/ch' + str(channnel_num) + '/' + process
    #f_in.ls()
    #print(hname)
    hist       = f_in.Get(hname)
    #hist.Print()
    if hist :
        #hist.Print()
        #print(hist.GetBinContent(1))
        h.SetBinContent(bin_num, hist.GetBinContent(1))
        h.SetBinError(bin_num,   hist.GetBinError(1))
    else :
        #print('no hist') 
        h.SetBinContent(bin_num, 0)
        h.SetBinError(bin_num,   0)

def yields_and_error(h, y, e):
    #h.Print()
    yields, error = ROOT.Double(0), ROOT.Double(0)
    yields = h.IntegralAndError(0, h.GetNbinsX(), error)
    y.append(yields)
    e.append(error)
    #print (yields, error)

for i in range(len(hist_name)):
    for j in range(len(muon_barrel)):
        read_hist(muon_barrel[j][0], muon_barrel[j][1], hist_name[i][0], h_muon_barrel[i])
        read_hist(muon_endcap[j][0], muon_endcap[j][1], hist_name[i][0], h_muon_endcap[i])
        read_hist(electron_barrel[j][0], electron_barrel[j][1], hist_name[i][0], h_electron_barrel[i])
        read_hist(electron_endcap[j][0], electron_endcap[j][1], hist_name[i][0], h_electron_endcap[i])
    #h_muon_endcap[i].Print()
#h_muon_endcap[1].Print()
yield_list_muon_barrel, yield_list_muon_endcap, yield_list_electron_barrel, yield_list_electron_endcap = [], [], [], []
uncertainty_list_muon_barrel, uncertainty_list_muon_endcap, uncertainty_list_electron_barrel, uncertainty_list_electron_endcap = [], [], [], []
for k in range(len(hist_name)):
    yields_and_error(h_muon_barrel[k], yield_list_muon_barrel, uncertainty_list_muon_barrel)
    yields_and_error(h_muon_endcap[k], yield_list_muon_endcap, uncertainty_list_muon_endcap)
    yields_and_error(h_electron_barrel[k], yield_list_electron_barrel, uncertainty_list_electron_barrel)
    yields_and_error(h_electron_endcap[k], yield_list_electron_endcap, uncertainty_list_electron_endcap)
print(yield_list_muon_barrel)
print(uncertainty_list_muon_barrel)
for kk in range(len(hist_name)):
    print (hist_name[kk][1] + ' & $ ' + str(round(yield_list_muon_barrel[kk],2)) + ' $\\pm ' + str(round(uncertainty_list_muon_barrel[kk],2)) + ' $  & $ ' + str(round(yield_list_muon_endcap[kk],2)) + ' $\\pm ' + str(round(uncertainty_list_muon_endcap[kk],2)) + ' $ & $ ' + str(round(yield_list_electron_barrel[kk],2)) + ' $\\pm ' + str(round(uncertainty_list_electron_barrel[kk],2)) + ' $  & $ ' + str(round(yield_list_electron_endcap[kk],2)) + ' $\\pm ' + str(round(uncertainty_list_electron_endcap[kk],2)) + ' $  \\\\')
#outf = TFile( outdir + '/'+which_year + "_" + which_channel  + "_" + which_region + "_"+barrel_or_endcap+ "_" + hist_name+'.root', 'RECREATE' )
#cv.Write()
#outf.Close()
