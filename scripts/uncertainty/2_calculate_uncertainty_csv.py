#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TPad, TFile, TH1, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from uncer_package.uncertainty_jecr import *
from uncer_package.uncertainty_systematic import *

indir                = sys.argv[1]
outdir               = sys.argv[2]
which_year           = sys.argv[3]
which_type           = sys.argv[4]
which_region         = sys.argv[5]
which_channel        = sys.argv[6]
barrel_or_endcap     = sys.argv[7]
which_btag_workpoint = sys.argv[8]
var_name             = sys.argv[9]
analysis_type        = sys.argv[10]
draw_op              = sys.argv[11]

os.system("mkdir -p " + outdir)
py_uncer_dir = outdir + "/csv/"
os.system("mkdir -p " + py_uncer_dir)
graph_dir = outdir + "/" + which_region + "_" + which_channel + "_" + barrel_or_endcap + "/graph"
os.system("mkdir -p " + graph_dir)

lumi =0
lumi_uncer = 0
uncer_list_mc = []
if which_year == "2016":
    lumi = 35.86
    lumi_uncer = 0.022
    uncer_list_mc = ['pileup', 'L1', 'photon_ID', 'electron_ID', 'electron_Reco', 'electron_HLT', 'muon_ID', 'muon_iso', 'muon_HLT', 'btag']
if which_year == "2017":
    lumi = 41.50
    lumi_uncer = 0.020
    uncer_list_mc = ['pileup', 'L1', 'photon_ID', 'electron_ID', 'electron_Reco', 'electron_HLT', 'muon_ID', 'muon_iso', 'muon_HLT', 'btag']
if which_year == "2018":
    lumi = 59.74
    lumi_uncer = 0.015
    uncer_list_mc = ['pileup', 'photon_ID', 'electron_ID', 'electron_Reco', 'electron_HLT', 'muon_ID', 'muon_iso', 'muon_HLT', 'btag']
#if which_year == "2016":
#    lumi = 35.86

#if which_year == "2017":
#    lumi = 41.50

#if which_year == "2018":
#    lumi = 59.74

uncer_list_data = ['fakephoton'] 
#uncer_list_mc = ['pileup', 'L1', 'photon_ID', 'electron_ID', 'electron_Reco', 'electron_HLT', 'muon_ID', 'muon_iso', 'muon_HLT', 'btag']#, 'pujet', 'pujet_mistag']
if which_type == 'mc':
    uncer_list = uncer_list_mc
else :
    uncer_list = uncer_list_data

#genbins = 0

sample_list_mc = ['WGJJ', 'WGJets', 'qcd_ewk', 'other']

#sample_list_mc = ['WGJJ', 'WGJets', 'TTG', 'ZG', 'ST', 'VV']

sample_list_data = ['fakephoton', 'doublefake']

sample_list = [
['WGJJ',       'mc',   'hist_in_'],
['WGJJ',       'mc',   'hist_out_'],
['WGJets',     'mc',   'hist_'],
['other',      'mc',   'hist_'],
#['fakelepton', 'data', 'hist_'],
#['fakephoton', 'data', 'hist_'],
#['doublefake', 'data', 'hist_']
]
#if which_type == 'mc':
#    sample_list = sample_list_mc
#else :
#    sample_list = sample_list_data


def print_uncer(which_sample, hist_name, data_or_mc, draw_op):
    print (which_sample + ' ' + which_year + ' ' + which_region + ' ' + which_channel + ' ' + barrel_or_endcap + ' ' + hist_name + ' : ')
    infilename= indir + "/" + which_year + "_" + which_channel +  "_" + data_or_mc + "_" + which_region + "_"+barrel_or_endcap+"_" + which_sample + ".root"
    #f = open(py_uncer_dir + "/" + which_sample + "_" + hist_name + ".py", "w")
    uncertainties_list = []

    f_xxx = TFile.Open(infilename)
    h_xxx   = f_xxx.Get("hist_")
    genbins = h_xxx.GetNbinsX()
    f_xxx.Close()
    L = [0 for x in range(genbins)]
    lumi_uncer_list = [lumi_uncer for x in range(genbins)]
    fakelepton_uncer_list = [0.3 for x in range(genbins)]

    kkkkk = which_sample
    if hist_name != 'hist_':
         kkkkk = which_sample + '_' + hist_name
    
    if data_or_mc == 'mc':
        uncertainties_list.append(lumi_uncer_list)
        for i in range(len(uncer_list)):
            tmp= get_systematic_1D(which_region, graph_dir, which_sample, uncer_list[i], infilename, var_name, lumi, hist_name, draw_op)
            print(uncer_list[i],tmp)
            uncertainties_list.append(tmp)
            #f.write(kkkkk + "_" + uncer_list[i] + " = [")
            #for j in range(len(tmp)):
            #    if j < len(tmp) -1 : f.write(str(1+tmp[j]) + ', ')
            #    if j == len(tmp) -1 : f.write(str(1+tmp[j]) + '] ' + '\n')
            
        tmp1= get_jecr_1D(which_region, graph_dir, which_sample, 'JEC', infilename, var_name, lumi, hist_name, draw_op)
        print('JEC', tmp1)

        tmp2= get_jecr_1D(which_region, graph_dir, which_sample, 'JER', infilename, var_name, lumi, hist_name, draw_op)
        print('JER', tmp2)
    
        uncertainties_list.append(tmp1)
        uncertainties_list.append(tmp2)
        #uncertainties_list.append(L)
        #uncertainties_list.append(L)

    if data_or_mc == 'data':
        uncertainties_list.append(L)
        for i in range(len(uncer_list_mc)+2):
            uncertainties_list.append(L)
        if which_sample == 'fakelepton':
            uncertainties_list.append(fakelepton_uncer_list)
            uncertainties_list.append(L)
        elif which_sample == 'fakephoton':
            uncertainties_list.append(L)
            tmp3 = get_systematic_1D(which_region, graph_dir, which_sample, 'fakephoton', infilename, var_name, lumi, hist_name, draw_op)
            uncertainties_list.append(tmp3)
        elif which_sample == 'doublefake':
            uncertainties_list.append(fakelepton_uncer_list)
            tmp3 = get_systematic_1D(which_region, graph_dir, which_sample, 'fakephoton', infilename, var_name, lumi, hist_name, draw_op)
            uncertainties_list.append(tmp3)

    f = open(py_uncer_dir + "/" + which_year + "_" + which_channel +  "_" + data_or_mc + "_" + which_region + "_"+barrel_or_endcap+"_" + hist_name + which_sample + ".csv", "w")
    f.write('lumi, ')
    for k in range(len(uncer_list_mc)):
        f.write(uncer_list_mc[k]+', ')
    f.write('JEC, JER \n')
    for i in range(len(uncertainties_list[0])):
        for j in range(len(uncertainties_list)):
            if j >= len(uncertainties_list)-1:
                f.write(str(uncertainties_list[j][i]+1)+' ')
            else :
                f.write(str(uncertainties_list[j][i]+1)+', ')
        f.write('\n')

    return genbins






#for i in range(1):
for i in range(len(sample_list)):
    genbins = print_uncer(sample_list[i][0], sample_list[i][2], sample_list[i][1], draw_op)#0

