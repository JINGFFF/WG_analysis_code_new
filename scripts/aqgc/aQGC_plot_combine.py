#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TPad, TFile, TH1D, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array

indir2016                = sys.argv[1]
indir2017                = sys.argv[2]
indir2018                = sys.argv[3]

outdir               = sys.argv[4]
#which_type           = sys.argv[4]
which_region         = sys.argv[5]
which_channel        = sys.argv[6]
barrel_or_endcap     = sys.argv[7]
fit_para_dir2016     = sys.argv[8]
fit_para_dir2017     = sys.argv[9]
fit_para_dir2018     = sys.argv[10]
hist_name               = sys.argv[11]
#which_btag_workpoint = sys.argv[8]
#var_name             = sys.argv[9]

os.system("mkdir -p " + outdir)

def read_hist(h_name, indir, which_year, which_channel, which_type, which_region, barrel_or_endcap, which_sample) :

    infilename= indir + "/" + which_year + "_" + which_channel +  "_" + which_type + "_" + which_region + "_"+barrel_or_endcap+"_" + which_sample + ".root"
    f_in = TFile.Open(infilename)
    hist       = f_in.Get(h_name)
    #hist.Print()
    binEdge_arr = array('d')
    binEdge_arr.append(hist.GetXaxis().GetBinLowEdge(1))
    for i in range(hist.GetNbinsX()):
        binEdge_arr.append(hist.GetXaxis().GetBinUpEdge(i+1))

    tmp_hist = TH1D()
    tmp_hist.SetBins(len(binEdge_arr)-1, binEdge_arr)
    for j in range(hist.GetNbinsX()):
        tmp_hist.SetBinContent(j+1, hist.GetBinContent(j+1))
        tmp_hist.SetBinError(j+1, hist.GetBinError(j+1))
    return tmp_hist

def set_hist(t_hist, which_year,  sample, type_h, color) :
    lumi =0
    if which_year == "2016":
        lumi = 35.86

    if which_year == "2017":
        lumi = 41.52

    if which_year == "2018":
        lumi = 59.7
    if type_h == 'mc':
        t_hist.Scale(lumi)
    #for i in range(len(bin_with)-1) :
    #    t_hist.GetXaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')

def add_hist(h1, h2, h3, color):
    h = h1.Clone()
    h.Add(h2)
    h.Add(h3)
    h.SetLineColor(color)
    h.SetFillColor(color)
    return h

h = []

data_name = ''
if which_channel == 'muon':
    data_name = 'SingleMuon'
if which_channel == 'electron':
    data_name = 'SingleElectron'

setting_for_h = [
#['WGJJ',     'mc',         2],
#['WGJets',   'mc',         7],
['ZG',       'mc',         8],
['WW',       'mc',        42],
['WZ',       'mc',        42],
['ZZ',       'mc',        42],
['ST_s',     'mc',         9],
['ST_t',     'mc',         9],
['ST_tbar',  'mc',         9],
['ST_tW',    'mc',         9],
['ST_tbarW', 'mc',         9],
['TTG',      'mc',         6],
['data',  'data',       1],
['fakelepton',  'data', 5],
['fakephoton',  'data',15],
['doublefake',  'data',30],
['WGJets',   'mc',         7],
['WGJJ',     'mc',         2],
]
h_ew = []
for i in range(16):
    t_2016 = read_hist(hist_name, indir2016, '2016', which_channel, setting_for_h[i][1], which_region, barrel_or_endcap, setting_for_h[i][0])
    set_hist(t_2016, '2016', setting_for_h[i][0], setting_for_h[i][1], setting_for_h[i][2])

    t_2017 = read_hist(hist_name, indir2017, '2017', which_channel, setting_for_h[i][1], which_region, barrel_or_endcap, setting_for_h[i][0])
    set_hist(t_2017, '2017', setting_for_h[i][0], setting_for_h[i][1], setting_for_h[i][2])

    t_2018 = read_hist(hist_name, indir2018, '2018', which_channel, setting_for_h[i][1], which_region, barrel_or_endcap, setting_for_h[i][0])
    set_hist(t_2018, '2018', setting_for_h[i][0], setting_for_h[i][1], setting_for_h[i][2])
 
    if setting_for_h[i][0] == 'WGJJ':
        h_ew.append(t_2016)
        h_ew.append(t_2017)
        h_ew.append(t_2018)

    h.append(add_hist(t_2016, t_2017, t_2018, setting_for_h[i][2]))
    #read_hist(h[i], indir, which_year, which_channel, setting_for_h[i][1], which_region, barrel_or_endcap, setting_for_h[i][0])
    #set_hist(h[i], setting_for_h[i][0], setting_for_h[i][1], setting_for_h[i][2])

h[13].Add(h[15],-1)
h[14].Add(h[15],-1)

cv = TCanvas("cv_", "cv_", 900, 900)
cv.SetLogy()
hs = THStack(" ", " ")
h_re_scale = h[15].Clone()
h_re_scale.Reset()
def get_ratio(fit_para_dir, which_year):
    input_filename_m = fit_para_dir + '/' + which_year + '_muon_fM2_paramsets_.txt'
    input_file_m = open(input_filename_m, "r")

    ratio = []
    h_re_scale.Reset()
    for l_num, l in enumerate(input_file_m):
        ll = re.split(r'[\s]',l)
        a2_m = float(ll[1])
        a1_m = float(ll[2])
        tmp_ratio = 1 + a1_m * 8 + a2_m * 8 * 8
        ratio.append(tmp_ratio)
    return ratio

ratio2016 = get_ratio(fit_para_dir2016, '2016')
ratio2017 = get_ratio(fit_para_dir2017, '2017')
ratio2018 = get_ratio(fit_para_dir2018, '2018')

for i in range(h_re_scale.GetNbinsX()):
    h_re_scale.SetBinContent(i+1, ratio2016[i]*h_ew[0].GetBinContent(i+1) + ratio2017[i]*h_ew[1].GetBinContent(i+1) + ratio2018[i]*h_ew[2].GetBinContent(i+1))

for i in range(len(h)):
    #ii = 15 - i
    if i == 10:
        continue
    hs.Add(h[i])
    if i != 15:
        h_re_scale.Add(h[i],1)

leg1 = TLegend(0.35,0.75,0.53,0.89);
leg1.SetBorderSize(0);
#leg1.AddEntry(DATA,  "DATA","lp");
leg1.AddEntry(h[15],  "WGJJ", "f");
leg1.AddEntry(h[14],"WGJets","f");
#leg1.AddEntry(h[13],    "Double Fake","f");
#leg1.AddEntry(h[12],    "Fake Photon","f");
#leg1.AddEntry(h[11],    "Fake Lepton","f");

leg2 = TLegend(0.55,0.7,0.68,0.89);
leg2.SetBorderSize(0);
leg2.AddEntry(h[0],    "ZA","f");
leg2.AddEntry(h[1],    "VV","f");
#leg2.AddEntry(h[2],    "WZ","f");
#leg2.AddEntry(h[3],    "ZZ","f");
leg2.AddEntry(h[9],   "TTA","f");
leg2.AddEntry(h[4],    "STop_s","f");

leg0 = TLegend(0.55,0.55,0.88,0.75);
leg0.SetBorderSize(0);
aggc_op = 'F_{M,2}/#Lambda^{4} = 8 #times 10^{-12} [TeV^{-4}]'
leg0.AddEntry(h_re_scale, aggc_op, "l");

#operator_latex[i] + "/#Lambda^{4} [TeV^{-4}]'

leg3 = TLegend(0.7,0.7,0.88,0.89);
leg3.SetBorderSize(0);
#leg1.AddEntry(h[14],"WGJets","f");
leg3.AddEntry(h[13],    "Double Fake","f");
leg3.AddEntry(h[12],    "Fake Photon","f");
leg3.AddEntry(h[11],    "Fake Lepton","f");
#leg3.AddEntry(h[4],    "STop_s","f");
#leg3.AddEntry(h[5],    "STop_t","f");
#leg3.AddEntry(h[6],    "STop_tbar","f");
#leg3.AddEntry(h[8],    "STop_tbarW","f");
#leg3.AddEntry(h[7],    "STop_tW","f");


# set stytle
H = cv.GetWh();
W = cv.GetWw();
l = cv.GetLeftMargin();
t = cv.GetTopMargin();
r = cv.GetRightMargin();
b = cv.GetBottomMargin();

lumiText = str(137.0) + " fb^{-1} (13 TeV)";
lumiTextSize     = 0.5
lumiTextOffset   = 0.2;

cmsText     = "CMS";
cmsTextFont   = 61;
cmsTextSize      = 0.75;
cmsTextOffset    = 0.1;

extraText   = "Preliminary";
extraTextFont = 52;
extraOverCmsTextSize  = 0.76;

relPosX    = 0.045;
relPosY    = 0.035
relExtraDY = 1.2;

alignY_ =3 
alignX_ = 1;
align_ = 10*alignX_ + alignY_;
cv.cd()
latex = TLatex()
latex.SetNDC();
latex.SetTextAngle(0);
latex.SetTextColor(1);

latex.SetTextFont(42);
latex.SetTextAlign(31);
latex.SetTextSize(lumiTextSize*t);
#latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);

posX_=0;
posY_ = 1-t - relPosY*(1-t-b)
latex.SetTextFont(cmsTextFont);
latex.SetTextSize(0.8*cmsTextSize*t);
latex.SetTextAlign(align_);
#latex.DrawLatex(1.3*l, posY_, cmsText);

extraTextSize = extraOverCmsTextSize*cmsTextSize;
latex.SetTextFont(extraTextFont);
latex.SetTextAlign(align_);
latex.SetTextSize(0.8*extraTextSize*t);

#print extraText
#cv.cd()
#latex.DrawLatex(1.3*l, posY_- relExtraDY*cmsTextSize*t, extraText);

hs.SetMaximum(50 * hs.GetMaximum())

#bin_with = [150,400,600,800, 1000, 1500]
#for i in range(len(bin_with)-1) :
#    hs.GetXaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')

hs.Draw("HIST")
hs.GetYaxis().SetTitle("Events/bin")
hs.GetYaxis().SetTitleSize(0.04)
hs.GetYaxis().SetTickLength(0.02)
hs.GetYaxis().SetTitleOffset(1.2)
#hs.GetXaxis().SetLabelSize(0.0)
hs.GetXaxis().SetTitle("M_{W#gamma}")   

h_re_scale.Draw("same hist")
h_re_scale.SetLineColor(12)
h_re_scale.SetFillColor(0)
h_re_scale.SetLineWidth(2)
bin_with = [150,400,600,800, 1000, 1500]

for i in range(len(bin_with)-1) :
    hs.GetXaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')

#hs.Draw("HIST")
   
leg0.Draw()
leg1.Draw()
leg2.Draw()
leg3.Draw()
latex.DrawLatex(0.55,1.03-t+lumiTextOffset*t,lumiText);
latex.DrawLatex(1.3*l, posY_, cmsText);
latex.DrawLatex(1.3*l, posY_- relExtraDY*cmsTextSize*t, extraText);
cv.SaveAs(outdir + "/"+"distribution.png")
outf = TFile( outdir + '/out.root', 'RECREATE' )
cv.Write()
outf.Close()
#print(setting_for_h[0])
