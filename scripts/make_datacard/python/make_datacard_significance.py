#!/usr/bin/env python
import sys
import os
import re
import sys
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
VBS = f_in_WGJJ.Get("hist_")
VBS.Scale(lumi)

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

binNum = VBS.GetNbinsX();
print(binNum)
print ('>>>>begin to read bin content to the txt file>>>>')

for i in range(1,VBS.GetNbinsX()+1):
    f = open('%s/%s_%s_%s_%s_bin_%d.txt'%(outdir,str(year),channel, region ,bORe, i-1),'w')
    f.write('imax 1   number of channels\n')
    f.write('jmax '+str(5)+'   number of processes-1\n')
    if year == '2016' or year == '2017':
        f.write('kmax -1  number of nuisance parameters (sources of systematical uncertainties)\n')
    else:
        f.write('kmax -1  number of nuisance parameters (sources of systematical uncertainties)\n')

    f.write('------------\n')
    f.write('# we have just one channel, in which we observe 0 events\n')
    f.write('bin mubarrel\n')
    bin_content = other.GetBinContent(i) + WGJets.GetBinContent(i)   + VBS.GetBinContent(i) + fakephoton.GetBinContent(i) + fakelepton.GetBinContent(i) - doublefake.GetBinContent(i)
    # bincontent of each precess
    other_bincontent = other.GetBinContent(i) if other.GetBinContent(i)>0 else 0
    WGJets_bincontent = WGJets.GetBinContent(i) if WGJets.GetBinContent(i)>0 else 0
    #VBS_bincontent=[0 for ii in range(VBS.GetNbinsX())]
    #VBS_bincontent.append(1)
    VBS_bincontent = VBS.GetBinContent(i) if VBS.GetBinContent(i)>0 else 0

    doublefake_bincontent = doublefake.GetBinContent(i) if doublefake.GetBinContent(i)>0 else 0
    fakephoton_bincontent = fakephoton.GetBinContent(i) if fakephoton.GetBinContent(i)>0 else 0
    fakelepton_bincontent = fakelepton.GetBinContent(i) if fakelepton.GetBinContent(i)>0 else 0
    #doublefake_bincontent = doublefake.GetBinContent(i) if doublefake.GetBinContent(i)>0 else 0

    # bin error
    fakephoton_binerror = fakephoton.GetBinError(i)/fakephoton_bincontent if fakephoton_bincontent>0 else 0
    fakephoton_binerror = fakephoton_binerror if fakephoton_binerror<1 else 1
    fakephoton_binerror = fakephoton_binerror+1

    fakelepton_binerror = fakelepton.GetBinError(i)/fakelepton_bincontent if fakelepton_bincontent>0 else 0
    fakelepton_binerror = fakelepton_binerror if fakelepton_binerror<1 else 1
    fakelepton_binerror = fakelepton_binerror+1

    doublefake_binerror = doublefake.GetBinError(i)/doublefake_bincontent if doublefake_bincontent>0 else 0
    doublefake_binerror = doublefake_binerror if doublefake_binerror<1 else 1
    doublefake_binerror = doublefake_binerror+1

    fakephoton_bincontent = fakephoton.GetBinContent(i) - doublefake_bincontent if fakephoton.GetBinContent(i)>0 else 0
    fakelepton_bincontent = fakelepton.GetBinContent(i) - doublefake_bincontent if fakelepton.GetBinContent(i)>0 else 0

    WGJets_binerror = WGJets.GetBinError(i)/WGJets_bincontent if WGJets_bincontent>0 else 0
    WGJets_binerror = WGJets_binerror if WGJets_binerror<1 else 1
    WGJets_binerror = WGJets_binerror+1

    other_binerror = other.GetBinError(i)/other_bincontent if other_bincontent>0 else 0
    other_binerror = other_binerror if other_binerror<1 else 1
    other_binerror = other_binerror+1
    #print("VBS_binerror: ", VBS_binerror)
    VBS_binerror = VBS.GetBinError(i)/VBS_bincontent if VBS_bincontent>0 else 0
    VBS_binerror = VBS_binerror if VBS_binerror<1 else 1
    VBS_binerror = VBS_binerror+1

    f.write('observation %.2f\n'%bin_content)
    f.write('------------\n')
    f.write('# now we list the expected events for signal and all backgrounds in that bin\n')
    f.write('# the second process line must have a positive number for backgrounds, and 0 for signal\n')
    f.write('# then we list the independent sources of uncertainties, and give their effect (syst. error)\n')
    f.write('# on each process and bin\n')
    f.write('bin')
    f.write('\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\n')

    f.write('process')
    f.write('\tVBS\tWGJets\tother\tfakephoton\tfakelepton\tdoublefake\n')

    f.write('process')
    f.write('\t0\t1\t2\t3\t4\t5\n')

    f.write('rate')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\n'%(VBS_bincontent, WGJets_bincontent, other_bincontent, fakephoton_bincontent, fakelepton_bincontent, doublefake_bincontent))


    f.write('------------\n')

    f.write('lumi_'+year+'\tlnN')
    f.write('\t'+ str(lumi_uncer)+'\t'+ str(lumi_uncer)+'\t'+ str(lumi_uncer)+'\t-\t-\t-\t#lumi\n')

    #f.write('stat\tlnN')
    #for k in range(1,VBS.GetNbinsX()+1):
       #if k == i:
       #f.write('\t'+str(VBS_binerror[k-1]))
       #elif k != i :
        #   f.write('\t-')
    #f.write('\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(VBS_out_binerror, WGJets_binerror, ST_s_binerror, ST_t_binerror, ST_tbar_binerror, ST_tW_binerror, ST_tbarW_binerror, TTG_binerror, WW_binerror, WZ_binerror, ZZ_binerror, ZG_binerror))
    f.write('WGJJ_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i)  + '\tlnN')
    f.write('\t'+str(VBS_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')

    f.write('WGJets_'+year+'_' + region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + '\tlnN')
    f.write('\t-\t'+str(WGJets_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')

    f.write('other_'+year+'_' + region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i)  + '\tlnN')
    f.write('\t-\t-\t'+str(other_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')

    f.write('fakephoton_'+year+'_' + region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i)  + '\tlnN')
    f.write('\t-\t-\t-\t'+str(fakephoton_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')

    f.write('fakelepton_'+year+'_' + region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i)  + '\tlnN')
    f.write('\t-\t-\t-\t-\t'+str(fakelepton_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')

    f.write('doublefake_'+year+'_' + region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i)  + '\tlnN')
    f.write('\t-\t-\t-\t-\t-\t'+str(doublefake_binerror)+'\t-\t-\t-\t-\t-\t-\t-\t-\t-\n')
    f.write('photon_ID\tlnN')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_photon_ID[i - 1], WGJets_photon_ID[i - 1], other_photon_ID[i - 1]))

    if year == '2016' or year == '2017':
        f.write('L1\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_L1[i - 1], WGJets_L1[i - 1], other_L1[i - 1]))

    if channel == 'electron' or channel == 'all':
        f.write('electron_ID\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_electron_ID[i - 1], WGJets_electron_ID[i - 1], other_electron_ID[i - 1]))

        f.write('electron_Reco\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_electron_Reco[i - 1], WGJets_electron_Reco[i - 1], other_electron_Reco[i - 1]))

        f.write('electron_HLT\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_electron_HLT[i - 1], WGJets_electron_HLT[i - 1], other_electron_HLT[i - 1]))
    
    if channel == 'muon' or channel == 'all':
        f.write('muon_ID\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_muon_ID[i - 1], WGJets_muon_ID[i - 1], other_muon_ID[i - 1]))

        f.write('muon_iso\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_muon_iso[i - 1], WGJets_muon_iso[i - 1], other_muon_iso[i - 1]))

        f.write('muon_HLT\tlnN')
        f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_muon_HLT[i - 1], WGJets_muon_HLT[i - 1], other_muon_HLT[i - 1]))

    f.write('btag\tlnN')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_btag[i - 1], WGJets_btag[i - 1], other_btag[i - 1]))

    f.write('JEC_'+year+'\tlnN')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_JEC[i - 1], WGJets_JEC[i - 1], other_JEC[i - 1]))

    f.write('JER_'+year+'\tlnN')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_JER[i - 1], WGJets_JER[i - 1], other_JER[i - 1]))

    #f.write('pujet_'+year+'\tlnN')
    #f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_pujet[i - 1], WGJets_pujet[i - 1], other_pujet[i - 1]))

    #f.write('pujet_mistag_'+year+'\tlnN')
    #f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_pujet_mistag[i - 1], WGJets_pujet_mistag[i - 1], other_pujet_mistag[i - 1]))

    f.write('pileup_'+year+'\tlnN')
    f.write('\t%0.5f\t%0.5f\t%0.5f\t-\t-\t-\n'%(WGJJ_pileup[i - 1], WGJets_pileup[i - 1], other_pileup[i - 1]))

    f.write('fakephoton_'+bORe+'_'+year+'\tlnN')
    f.write('\t-\t-\t-\t%0.5f\t-\t%0.5f\n'%(fakephoton_fakephoton[i - 1], doublefake_fakephoton[i - 1],))

    f.write('fakelepton_'+channel+'_'+year+'\tlnN')
    f.write('\t-\t-\t-\t-\t%0.5f\t%0.5f\n'%(1.3, 1.3))

    f.write('WGJJ_pdf'+'\tlnN')
    f.write('\t'+str(1+WGJJ_pdf[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJJ_scale'+'\tlnN')
    f.write('\t'+str(1+WGJJ_scale[i-1])+'\t-\t-\t-\t-\t-\n')

    f.write('WGJets_pdf'+'\tlnN')
    f.write('\t-\t'+str(1+WGJets_pdf[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muF1'+'\tlnN')
    f.write('\t-\t'+str(1+WGJets_muF1[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muR1'+'\tlnN')
    f.write('\t-\t'+str(1+WGJets_muR1[i-1])+'\t-\t-\t-\t-\n')

    f.write('WGJets_muRmuF'+'\tlnN')
    f.write('\t-\t'+str(1+WGJets_muRmuF[i-1])+'\t-\t-\t-\t-\n')
    
    f.write("Lumi group = " + 'lumi_'+year + '\n')
    f.write("Stat group = ")
    if VBS_bincontent > 0 :
        f.write('WGJJ_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    if WGJets_bincontent > 0 :
        f.write('WGJets_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    if other_bincontent > 0 :
        f.write('other_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    if fakephoton_bincontent > 0 :
        f.write('fakephoton_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    if fakelepton_bincontent > 0 :
        f.write('fakelepton_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    if doublefake_bincontent > 0 :
        f.write('doublefake_' +year+'_' +region + '_' +channel+'_'+bORe+'_stat_bin_'+ str(i) + ' ')
    f.write('\n')

    f.write("photon group = photon_ID" + '\n')

    if year == '2016' or year == '2017':
        f.write("L1pre group = L1" + '\n')

    if channel == 'electron' or channel == 'all':
        f.write("electron group = electron_ID electron_Reco electron_HLT" + '\n')

    if channel == 'muon' or channel == 'all':
        f.write("muon group = muon_ID muon_iso muon_HLT" + '\n')

    f.write("Btag group = btag" + '\n')

    f.write("JECR group = " + 'JEC_'+year + ' ' + 'JER_'+year + '\n')
    f.write("Pileup group = pileup_" + year + '\n')

    f.write("Nonprompt group = " + 'fakephoton_'+bORe+'_'+year+ ' ' + 'fakelepton_'+channel+'_'+year + '\n')

    f.write("Theory group = WGJJ_pdf WGJJ_scale WGJets_pdf WGJets_muF1 WGJets_muR1 WGJets_muRmuF" + '\n')

   #prin[i - 1], i,' ',ZA_sig_binerror,' ',ZA_sig_binerror,' ',ZA_binerror,' ',non_prompt_binerror,' ',TTA_binerror,' ',VV_binerror,' ',ST_binerror,' ',WA_binerror
