#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TDirectoryFile, TPad, TGraph, TPad, TFile, TH1D, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array

infilename2016           = sys.argv[1]
infilename2017           = sys.argv[2]
infilename2018           = sys.argv[3]

outdir               = sys.argv[4]
#which_year           = sys.argv[5]

os.system("mkdir -p " + outdir)

#f_in = TFile.Open(infilename)

muon_barrel     = [[1 ,1] , [2, 2] , [3, 3] , [4, 4] , [5, 5] , [6, 6] , [7, 7] , [8, 8] , [9, 9] , [10, 10], [11, 11], [12, 12]]
muon_endcap     = [[1, 13], [2, 14], [3, 15], [4, 16], [5, 17], [6, 17], [7, 18], [8, 20], [9, 21], [10, 22], [11, 23], [12, 24]]
electron_barrel = [[1, 25], [2, 26], [3, 27], [4, 28], [5, 29], [6, 30], [7, 31], [8, 32], [9, 33], [10, 34], [11, 35], [12, 36]]
electron_endcap = [[1, 37], [2, 38], [3, 39], [4, 40], [5, 41], [6, 42], [7, 43], [8, 44], [9, 45], [10, 46], [11, 47], [12, 48]]

hist_name = [
['VBS', 'EW WG'],
['WGJets', 'QCD WG'],
['other', 'other'],
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

def read_hist(infilename, bin_num, channnel_num, process, h) :
    f_in = TFile.Open(infilename)
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

def run(infilename):
    h_muon_barrel, h_muon_endcap, h_electron_barrel, h_electron_endcap = [], [], [], []

    for i in range(len(hist_name)):
        h_muon_barrel.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
        h_muon_endcap.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
        h_electron_barrel.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))
        h_electron_endcap.append(TH1D("", "", len(muon_barrel), 0, len(muon_barrel)))

    for i in range(len(hist_name)):
        for j in range(len(muon_barrel)):
            read_hist(infilename, muon_barrel[j][0], muon_barrel[j][1], hist_name[i][0], h_muon_barrel[i])
            read_hist(infilename, muon_endcap[j][0], muon_endcap[j][1], hist_name[i][0], h_muon_endcap[i])
            read_hist(infilename, electron_barrel[j][0], electron_barrel[j][1], hist_name[i][0], h_electron_barrel[i])
            read_hist(infilename, electron_endcap[j][0], electron_endcap[j][1], hist_name[i][0], h_electron_endcap[i])
    #h_muon_endcap[i].Print()
#h_muon_endcap[1].Print()

    yield_list_muon_barrel, yield_list_muon_endcap, yield_list_electron_barrel, yield_list_electron_endcap = [], [], [], []
    uncertainty_list_muon_barrel, uncertainty_list_muon_endcap, uncertainty_list_electron_barrel, uncertainty_list_electron_endcap = [], [], [], []
    for k in range(len(hist_name)):
        yields_and_error(h_muon_barrel[k], yield_list_muon_barrel, uncertainty_list_muon_barrel)
        yields_and_error(h_muon_endcap[k], yield_list_muon_endcap, uncertainty_list_muon_endcap)
        yields_and_error(h_electron_barrel[k], yield_list_electron_barrel, uncertainty_list_electron_barrel)
        yields_and_error(h_electron_endcap[k], yield_list_electron_endcap, uncertainty_list_electron_endcap)
    #print(yield_list_muon_barrel)
    #print(uncertainty_list_muon_barrel)
    return yield_list_muon_barrel, yield_list_muon_endcap, yield_list_electron_barrel, yield_list_electron_endcap, uncertainty_list_muon_barrel, uncertainty_list_muon_endcap, uncertainty_list_electron_barrel, uncertainty_list_electron_endcap

#print(run(infilename2018))
yield_2016 = run(infilename2016)
yield_2017 = run(infilename2017)
yield_2018 = run(infilename2018)
for kk in range(len(hist_name)):
    mb_y = yield_2016[0][kk] + yield_2017[0][kk] + yield_2018[0][kk]
    mb_e = ((yield_2016[4][kk])**2 + (yield_2017[4][kk])**2 + (yield_2018[4][kk])**2)**0.5

    me_y = yield_2016[1][kk] + yield_2017[1][kk] + yield_2018[1][kk]
    me_e = ((yield_2016[5][kk])**2 + (yield_2017[5][kk])**2 + (yield_2018[5][kk])**2)**0.5

    eb_y = yield_2016[2][kk] + yield_2017[2][kk] + yield_2018[2][kk]
    eb_e = ((yield_2016[6][kk])**2 + (yield_2017[6][kk])**2 + (yield_2018[7][kk])**2)**0.5

    ee_y = yield_2016[3][kk] + yield_2017[3][kk] + yield_2018[3][kk]
    ee_e = ((yield_2016[7][kk])**2 + (yield_2017[7][kk])**2 + (yield_2018[7][kk])**2)**0.5

    print (hist_name[kk][1] + ' &  ' + str(round(mb_y,2)) + ' $\\pm $ ' + str(round(mb_e,2)) + ' &  ' + str(round(me_y,2)) + ' $\\pm $ ' + str(round(me_e,2)) + ' &  ' + str(round(eb_y,2)) + ' $\\pm $ ' + str(round(eb_e,2)) + '  &  ' + str(round(ee_y,2)) + ' $\\pm $ ' + str(round(ee_e,2)) + '   \\\\')
#outf = TFile( outdir + '/'+which_year + "_" + which_channel  + "_" + which_region + "_"+barrel_or_endcap+ "_" + hist_name+'.root', 'RECREATE' )
#cv.Write()
#outf.Close()
