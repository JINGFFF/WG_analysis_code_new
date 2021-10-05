#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TPad, TFile, TH1, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack

indir                = sys.argv[1]
outdir               = sys.argv[2]
which_year           = sys.argv[3]
#which_type           = sys.argv[4]
which_region         = sys.argv[4]
which_channel        = sys.argv[5]
barrel_or_endcap     = sys.argv[6]
#which_btag_workpoint = sys.argv[7]

os.system("mkdir -p " + outdir)
py_uncer_dir = outdir + "/" + which_region + "_" + which_channel + "_" + barrel_or_endcap
os.system("mkdir -p " + py_uncer_dir)
graph_dir = outdir + "/" + which_region + "_" + which_channel + "_" + barrel_or_endcap + "/graph"
os.system("mkdir -p " + graph_dir)

lumi =0
if which_year == "2016":
    lumi = 35.92

if which_year == "2017":
    lumi = 41.50

if which_year == "2018":
    lumi = 59.74


#genbins = 0

def print_uncer(which_sample, which_type,hist_name):
    #print (which_sample + ' ' + which_year + ' ' + which_region + ' ' + which_channel + ' ' + barrel_or_endcap + ' ' + hist_name + ' : ')
    infilename= indir + "/" + which_year + "_" + which_channel +  "_" + which_type + "_" + which_region + "_"+barrel_or_endcap+"_" + which_sample + ".root"

    f_xxx = TFile.Open(infilename)
    h_xxx   = f_xxx.Get("hist_")
    if which_type == 'mc':
        h_xxx.Scale(lumi)
    yields = round(h_xxx.GetSum(), 2)
    error = 0
    for i in range(h_xxx.GetNbinsX()):
       #print(which_sample +'bin' + str(i+1) + ' '+str(h_xxx.GetBinContent(i+1)) + ' '+str(h_xxx.GetBinError(i+1))) 
       error = error + (h_xxx.GetBinError(i+1))**2
    error = error**0.5
    #print(error)
    return yields, error

sample_list = ['WGJJ', 'WGJets', 'TTG', 'ZG', 'ST_s', 'ST_t', 'ST_tbar', 'ST_tW', 'ST_tbarW', 'WW', 'WZ', 'ZZ', 'fakephoton', 'doublefake', 'fakelepton']
sample_type = ['mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'mc', 'data', 'data', 'data']
sample_dict = {k: [] for k in sample_list}
#sample_list_data = ['fakephoton', 'doublefake']
all_yields = []
all_error = []
#for i in range(1):
for i in range(len(sample_list)):
    tmp_y, tmp_error = print_uncer(sample_list[i], sample_type[i], 'hist_')
    #print(sample_list[i], tmp_y, tmp_error)
    sample_dict[sample_list[i]].append(tmp_y)
    sample_dict[sample_list[i]].append(tmp_error)
    #print(all_error)

sample_dict['fakelepton'][0] = sample_dict['fakelepton'][0] - sample_dict['doublefake'][0]
sample_dict['fakephoton'][0] = sample_dict['fakephoton'][0] - sample_dict['doublefake'][0]
sample_dict['total predict'], sample_dict['VV'], sample_dict['ST'] = [], [], []
sample_dict['VV'].append(sample_dict['WW'][0] + sample_dict['WZ'][0] + sample_dict['ZZ'][0])
sample_dict['VV'].append((sample_dict['WW'][1]**2 + sample_dict['WZ'][1]**2 + sample_dict['ZZ'][1]**2)**0.5)
sample_dict['ST'].append(sample_dict['ST_t'][0] + sample_dict['ST_s'][0] + sample_dict['ST_tbar'][0] + sample_dict['ST_tW'][0] + sample_dict['ST_tbarW'][0])
sample_dict['ST'].append((sample_dict['ST_s'][1]**2 + sample_dict['ST_t'][1]**2 + sample_dict['ST_tbar'][1]**2 + sample_dict['ST_tW'][1]**2 + sample_dict['ST_tbarW'][1]**2)**0.5)

samplexx = ['WGJJ', 'WGJets', 'TTG', 'ZG', 'ST', 'VV', 'fakephoton', 'doublefake', 'fakelepton']
sample_dict['total predict'] = 0
#print(sample_dict)



print str(which_year) + ',',
for i in range(len(samplexx)):
    #print str(sample_list[i]) + ' : ' + str(all_yields[i])
    print str(samplexx[i]) + ',',
print 'total predict'

print str(which_region) + ' '+ str(which_channel) + ' ' + str(barrel_or_endcap) + ',',
for i in range(len(samplexx)):
    #print str(sample_list[i]) + ' : ' + str(all_yields[i])
    print str(round(sample_dict[samplexx[i]][0], 3)) + ' + / - ' + str(round(sample_dict[samplexx[i]][1], 3)) + ',',
    sample_dict['total predict'] = sample_dict['total predict'] + sample_dict[samplexx[i]][0]
#print 'total predict : ' + 
print str(round(sample_dict['total predict'], 3))

