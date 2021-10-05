#!/usr/bin/env python
import sys
import os
import re
#from uncertainty_unfold import *
import ROOT
from ROOT import gROOT, THStack, TH1D, TList, TFile, TH2D
sys.path.append(os.path.abspath('.'))

indir = sys.argv[1]
outdir = sys.argv[2]
region = sys.argv[3]
bORe = sys.argv[4]
year = sys.argv[5]
channel = sys.argv[6]
channel_name = ''
if not os.path.exists(outdir):
    os.makedirs(outdir)

if region == 'signal':
    if channel == 'muon':
        if bORe == 'barrel':
            from uncer_signal_muon_barrel import *
            from uncer_pdf_signal_muon_barrel import *
        if bORe == 'endcap':
            from uncer_signal_muon_endcap import *
            from uncer_pdf_signal_muon_endcap import *
        channel_name = 'SingleMuon'
    if channel == 'electron':
        if bORe == 'barrel':
            from uncer_signal_electron_barrel import *
            from uncer_pdf_signal_electron_barrel import *
        if bORe == 'endcap':
            from uncer_signal_electron_endcap import *
            from uncer_pdf_signal_electron_endcap import *
        channel_name = 'SingleElectron'
    if channel == 'all':
        if bORe == 'barrel':
            from uncer_signal_all_barrel import *
            from uncer_pdf_signal_all_barrel import *
        if bORe == 'endcap':
            from uncer_signal_all_endcap import *
            from uncer_pdf_signal_all_endcap import *
        channel_name = 'SingleElectron'


if region  == 'control':
    if channel == 'muon':
        if bORe == 'barrel':
            from uncer_control_muon_barrel import *
            from uncer_pdf_control_muon_barrel import *
        if bORe == 'endcap':
            from uncer_control_muon_endcap import *
            from uncer_pdf_control_muon_endcap import *
        channel_name = 'SingleMuon'
    if channel == 'electron':
        if bORe == 'barrel':
            from uncer_control_electron_barrel import *
            from uncer_pdf_control_electron_barrel import *
        if bORe == 'endcap':
            from uncer_control_electron_endcap import *
            from uncer_pdf_control_electron_endcap import *
        channel_name = 'SingleElectron'
    if channel == 'all':
        if bORe == 'barrel':
            from uncer_control_all_barrel import *
            from uncer_pdf_control_all_barrel import *
        if bORe == 'endcap':
            from uncer_control_all_endcap import *
            from uncer_pdf_control_all_endcap import *
        channel_name = 'SingleElectron'


lumi =0
lumi_uncer = 0
if year == "2016":
    lumi = 35.86
    lumi_uncer = 1.022
if year == "2017":
    lumi = 41.50
    lumi_uncer = 1.020
if year == "2018":
    lumi = 59.74
    lumi_uncer = 1.015

#print(ST_s_photon_ID[(i-1)*3 + j - 1])
print ('-----begin to transfer TH2D to txt for Higgs-combine tool----- \n')
histname = 'ptlep'
f_in_WGJJ = TFile.Open(indir + "/"+year+"_"+channel+"_mc_" + region + "_" + bORe + "_WGJJ.root")
#VBS_in = f_in_WGJJ.Get("hist_in_")
#VBS_in.Scale(lumi)
VBS_out = f_in_WGJJ.Get("hist_out_")
VBS_out.Scale(lumi)
binNum = VBS_out.GetNbinsX()
h_in = []
for in_i in range(binNum):
    h_in.append(f_in_WGJJ.Get('hist_in_'+str(in_i)+'_'))
for in_i2 in range(binNum):
    h_in[in_i2].Scale(lumi)

f_in_WGJets = TFile.Open(indir + "/"+year+"_"+channel+"_mc_" + region + "_" +bORe + "_WGJets.root")
WGJets = f_in_WGJets.Get("hist_")
WGJets.Scale(lumi)

f_in_other = TFile.Open(indir + "/"+year+"_"+channel+"_mc_" + region + "_"+ bORe+ "_other.root")
other = f_in_other.Get("hist_")
other.Scale(lumi)

f_in_data = TFile.Open(indir + "/"+year+"_"+channel+"_data_" + region + "_" + bORe + "_data.root")
data = f_in_data.Get("hist_")

f_in_doublefake = TFile.Open(indir + "/"+year+"_"+channel+"_data_" + region + "_" + bORe + "_doublefake.root")
doublefake = f_in_doublefake.Get("hist_")

f_in_fakephoton = TFile.Open(indir + "/"+year+"_"+channel+"_data_" + region + "_" + bORe + "_fakephoton.root")
fakephoton = f_in_fakephoton.Get("hist_")

f_in_fakelepton = TFile.Open(indir + "/"+year+"_"+channel+"_data_" + region + "_" + bORe + "_fakelepton.root")
fakelepton = f_in_fakelepton.Get("hist_")


#binNum = VBS_out.GetNbinsX();
print(binNum)
print ('>>>>begin to read bin content to the txt file>>>>')

for i in range(1,binNum+1):
    f = open('%s/%s_%s_%s_%s_bin_%d.txt'%(outdir,year,channel, region ,bORe, i-1),'w')
    f.write('imax 1   number of channels\n')
    npro = 5 + binNum
    f.write('jmax '+str(npro)+'   number of processes-1\n')
    #f.write('kmax 1  number of nuisance parameters (sources of systematical uncertainties)\n')
    if year == '2016' or year == '2017':
        f.write('kmax -1  number of nuisance parameters (sources of systematical uncertainties)\n')
    if year == '2018' :
        f.write('kmax -1  number of nuisance parameters (sources of systematical uncertainties)\n')
    f.write('------------\n')
    f.write('# we have just one channel, in which we observe 0 events\n')
    f.write('bin mubarrel\n')
    vbs_gensum = 0
    VBS_bincontent=[0 for ii in range(binNum)]
    #h_in[i-1].Print("all")
    for k0 in range(1,binNum+1):
        #h_in[i].Print("all")
        #print VBS.GetNbinsX
        VBS_bincontent[k0-1] = h_in[i-1].GetBinContent(k0) if h_in[i-1].GetBinContent(k0)>0 else 0
        vbs_gensum = vbs_gensum + VBS_bincontent[k0-1]
    print("VBS_bincontent: ",VBS_bincontent)

    bin_content = other.GetBinContent(i) + WGJets.GetBinContent(i) + vbs_gensum + VBS_out.GetBinContent(i) + fakephoton.GetBinContent(i) + fakelepton.GetBinContent(i) - doublefake.GetBinContent(i)
    # bincontent of each precess
    other_bincontent = other.GetBinContent(i) if other.GetBinContent(i)>0 else 0
    WGJets_bincontent = WGJets.GetBinContent(i) if WGJets.GetBinContent(i)>0 else 0
    #VBS_bincontent=[0 for ii in range(VBS.GetNbinsX())]
    #VBS_bincontent.append(1)
    #VBS_in_bincontent = VBS_in.GetBinContent(i) if VBS_in.GetBinContent(i)>0 else 0
    #VBS_in_bincontent= VBS_in_bincontent + 1
    VBS_out_bincontent = VBS_out.GetBinContent(i) if VBS_out.GetBinContent(i)>0 else 0

    doublefake_bincontent = doublefake.GetBinContent(i) if doublefake.GetBinContent(i)>0 else 0
    fakephoton_bincontent = fakephoton.GetBinContent(i) - doublefake_bincontent if fakephoton.GetBinContent(i)>0 else 0
    fakelepton_bincontent = fakelepton.GetBinContent(i) - doublefake_bincontent if fakelepton.GetBinContent(i)>0 else 0
    #doublefake_bincontent = doublefake.GetBinContent(i) if doublefake.GetBinContent(i)>0 else 0

    # bin error
    WGJets_binerror = WGJets.GetBinError(i)/WGJets_bincontent if WGJets_bincontent>0 else 0
    WGJets_binerror = WGJets_binerror if WGJets_binerror<1 else 1
    WGJets_binerror = WGJets_binerror+1

    other_binerror = other.GetBinError(i)/other_bincontent if other_bincontent>0 else 0
    other_binerror = other_binerror if other_binerror<1 else 1
    other_binerror = other_binerror+1


    #print("VBS_binerror: ", VBS_binerror)
    #VBS_in_binerror = VBS_in.GetBinError(i)/VBS_in_bincontent if VBS_in_bincontent>0 else 0
    #VBS_in_binerror = VBS_in_binerror if VBS_in_binerror<1 else 1
    #VBS_in_binerror = VBS_in_binerror+1

    VBS_out_binerror = VBS_out.GetBinError(i)/VBS_out_bincontent if VBS_out_bincontent>0 else 0
    VBS_out_binerror = VBS_out_binerror if VBS_out_binerror<1 else 1
    VBS_out_binerror = VBS_out_binerror+1

    fakephoton_binerror = fakephoton.GetBinError(i)/fakephoton_bincontent if fakephoton_bincontent>0 else 0
    fakephoton_binerror = fakephoton_binerror if fakephoton_binerror<1 else 1
    fakephoton_binerror = fakephoton_binerror+1

    fakelepton_binerror = fakelepton.GetBinError(i)/fakelepton_bincontent if fakelepton_bincontent>0 else 0
    fakelepton_binerror = fakelepton_binerror if fakelepton_binerror<1 else 1
    fakelepton_binerror = fakelepton_binerror+1

    doublefake_binerror = doublefake.GetBinError(i)/doublefake_bincontent if doublefake_bincontent>0 else 0
    doublefake_binerror = doublefake_binerror if doublefake_binerror<1 else 1
    doublefake_binerror = doublefake_binerror+1

    f.write('observation %.2f\n'%bin_content)
    f.write('------------\n')
    f.write('# now we list the expected events for signal and all backgrounds in that bin\n')
    f.write('# the second process line must have a positive number for backgrounds, and 0 for signal\n')
    f.write('# then we list the independent sources of uncertainties, and give their effect (syst. error)\n')
    f.write('# on each process and bin\n')
    f.write('bin')
    for k1 in range(binNum):
        f.write('\tmubarrel')    
    f.write('\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\n')

    f.write('process')
    for k3 in range(1,binNum+1):
       f.write('\tgenbin'+str(k3))
    f.write('\tVBS_out\tWGJets\tother\tfakephoton\tfakelepton\tdoublefake\n')

    f.write('process')
    for k2 in range(binNum):
        k22 = -1*binNum + k2
        f.write('\t' + str(k22))
    f.write('\t0\t1\t2\t3\t4\t5\n')

    f.write('rate')
    for k in range(1,binNum+1):
       f.write('\t'+str(VBS_bincontent[k-1]))
    f.write('\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n'%(VBS_out_bincontent, WGJets_bincontent, other_bincontent, fakephoton_bincontent, fakelepton_bincontent, doublefake_bincontent))
    #f.write('\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n'%(VBS_out_bincontent, WGJets_bincontent, other_bincontent, fakephoton_bincontent, fakelepton_bincontent))

    f.write('------------\n')

    f.write('lumi\tlnN')
    for k1 in range(binNum):
        f.write('\t'+str(lumi_uncer))
    f.write('\t'+str(lumi_uncer)+'\t'+str(lumi_uncer)+'\t'+str(lumi_uncer)+'\t-\t-\t-\t#lumi\n')

    #f.write('stat\tlnN')
    #for k in range(1,VBS.GetNbinsX()+1):
       #if k == i:
       #f.write('\t'+str(VBS_binerror[k-1]))
       #elif k != i :
        #   f.write('\t-')
    #f.write('\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(VBS_out_binerror, WGJets_binerror, ST_s_binerror, ST_t_binerror, ST_tbar_binerror, ST_tW_binerror, ST_tbarW_binerror, TTG_binerror, WW_binerror, WZ_binerror, ZZ_binerror, ZG_binerror))
    #f.write('WGJJ_in_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + "_"+year+'\tlnN')
    #f.write('\t'+str(VBS_in_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')
    f.write('WGJJ_hist_out__'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t'+str(VBS_out_binerror)+'\t-\t-\t-\t-\t-\n')

    f.write('WGJets_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t-\t'+str(WGJets_binerror)+'\t-\t-\t-\t-\n')

    f.write('other_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t-\t-\t'+str(other_binerror)+'\t-\t-\t-\n')

    f.write('fakephoton_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t-\t-\t-\t'+str(fakephoton_binerror)+'\t-\t-\n')

    f.write('fakelepton_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t-\t-\t-\t-\t'+str(fakelepton_binerror)+'\t-\n')

    f.write('doublefake_'+channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t-\t-\t-\t-\t-\t'+str(doublefake_binerror)+'\n')

    f.write('L1\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__L1[i - 1],WGJets_L1[i - 1], other_L1[i - 1]))

    f.write('photon_ID\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__photon_ID[i - 1],WGJets_photon_ID[i - 1], other_photon_ID[i - 1]))

    f.write('electron_ID\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__electron_ID[i - 1], WGJets_electron_ID[i - 1], other_electron_ID[i - 1]))

    f.write('electron_Reco\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__electron_Reco[i - 1], WGJets_electron_Reco[i - 1], other_electron_Reco[i - 1]))

    f.write('electron_HLT\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__electron_HLT[i - 1],WGJets_electron_HLT[i - 1], other_electron_HLT[i - 1]))

    f.write('muon_ID\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__muon_ID[i - 1], WGJets_muon_ID[i - 1], other_muon_ID[i - 1]))

    f.write('muon_iso\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__muon_iso[i - 1], WGJets_muon_iso[i - 1], other_muon_iso[i - 1]))

    f.write('muon_HLT\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__muon_HLT[i - 1], WGJets_muon_HLT[i - 1], other_muon_HLT[i - 1]))

    #for ke in range(binNum):
    #    f.write('\t-')
    f.write('btag_'+year+'\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__btag[i - 1], WGJets_btag[i - 1], other_btag[i - 1]))

    f.write('JEC_'+year+'\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__JEC[i - 1], WGJets_JEC[i - 1], other_JEC[i - 1]))

    f.write('JER_'+year+'\tlnN')
    for ke in range(binNum):
        f.write('\t-')
    f.write('\t%0.4f\t%0.4f\t%0.4f\t-\t-\t-\n'%(WGJJ_hist_out__JER[i - 1], WGJets_JER[i - 1], other_JER[i - 1]))


    f.write('WGJJ_pdf'+'\tlnN')
    f.write('\t-'*(i-1))
    f.write('\t'+str(1+WGJJ_pdf[i-1]) + '\t-'*(binNum-1) +'\t'+str(1+WGJJ_pdf[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJJ_scale'+'\tlnN')
    f.write('\t-'*(i-1))
    f.write('\t'+str(1+WGJJ_scale[i-1])+ '\t-'*(binNum-1) +'\t'+str(1+WGJJ_scale[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJets_pdf'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_pdf[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muF1'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muF1[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muR1'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muR1[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muRmuF'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muRmuF[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJJ_pdf_0'+'\tlnN')
    f.write('\t-'*(i-1))
    f.write('\t'+str(1+WGJJ_pdf_0[i-1]) + '\t-'*(binNum-1) +'\t'+str(1+WGJJ_pdf_0[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJJ_scale_0'+'\tlnN')
    f.write('\t-'*(i-1))
    f.write('\t'+str(1+WGJJ_scale_0[i-1])+ '\t-'*(binNum-1) +'\t'+str(1+WGJJ_scale_0[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJets_pdf_0'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_pdf_0[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muF1_0'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muF1_0[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muR1_0'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muR1_0[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muRmuF_0'+'\tlnN')
    f.write('\t-'*(binNum+1)+'\t'+str(1+WGJets_muRmuF_0[i-1])+'\t-\t-\t-\t-\n')

    f.write("Theory group = WGJJ_pdf WGJJ_scale WGJets_pdf WGJets_muF1 WGJets_muR1 WGJets_muRmuF" + '\n')

    f.write("Theory0 group = WGJJ_pdf_0 WGJJ_scale_0 WGJets_pdf_0 WGJets_muF1_0 WGJets_muR1_0 WGJets_muRmuF_0" + '\n')

    f.write("TheoryAll group = WGJJ_pdf WGJJ_scale WGJets_pdf WGJets_muF1 WGJets_muR1 WGJets_muRmuF WGJJ_pdf_0 WGJJ_scale_0 WGJets_pdf_0 WGJets_muF1_0 WGJets_muR1_0 WGJets_muRmuF_0" + '\n')

   #prin[i - 1], i,' ',ZA_sig_binerror,' ',ZA_sig_binerror,' ',ZA_binerror,' ',non_prompt_binerror,' ',TTA_binerror,' ',VV_binerror,' ',ST_binerror,' ',WA_binerror
