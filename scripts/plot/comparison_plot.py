#!/usr/bin/env python
import sys
import os
import re
import ROOT
from ROOT import gROOT, TCanvas, TPad, TGraph, TPad, TFile, TH1D, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array

indir                = sys.argv[1]
outdir               = sys.argv[2]
which_year           = sys.argv[3]
which_region         = sys.argv[4]
which_channel        = sys.argv[5]
barrel_or_endcap     = sys.argv[6]
expect_or_observe    = sys.argv[7]
hist_name            = sys.argv[8]
xtitle               = sys.argv[9]

os.system("mkdir -p " + outdir)

lumi =0
if which_year == "2016":
    lumi = 35.86

if which_year == "2017":
    lumi = 41.52

if which_year == "2018":
    lumi = 59.7

def read_hist(h_name, tmp_hist, indir, which_year, which_channel, which_type, which_region, barrel_or_endcap, which_sample) :
    infilename= indir + "/" + which_year + "_" + which_channel +  "_" + which_type + "_" + which_region + "_"+barrel_or_endcap+"_" + which_sample + ".root"
    f_in = TFile.Open(infilename)
    hist       = f_in.Get(h_name)
    #hist.Print()
    binEdge_arr = array('d')
    binEdge_arr.append(hist.GetXaxis().GetBinLowEdge(1))
    for i in range(hist.GetNbinsX()):
        binEdge_arr.append(hist.GetXaxis().GetBinUpEdge(i+1))

    tmp_hist.SetBins(len(binEdge_arr)-1, binEdge_arr)    
    for j in range(hist.GetNbinsX()):
        tmp_hist.SetBinContent(j+1, hist.GetBinContent(j+1))

def set_hist(t_hist, sample, type_h, color) :
    if type_h == 'mc':
        t_hist.Scale(lumi)
    #t_hist.Sumw2()
    t_hist.SetLineColor(color)
    t_hist.SetFillColor(color)

h1  = TH1D()#wgjj
h2  = TH1D()#wgjets
h3  = TH1D()#zg
h4  = TH1D()#ww
h5  = TH1D()#wz
h6  = TH1D()#zz
h7  = TH1D()#st_s
h8  = TH1D()#st_t
h9  = TH1D()#st_tbar
h10 = TH1D()#st_tw
h11 = TH1D()#st_tbarw
h12 = TH1D()#ttg
h13 = TH1D()#data
h14 = TH1D()#fakelepton
h15 = TH1D()#fakephoton
h16 = TH1D()#doublefake

h = []
h.append(h1)
h.append(h2)
h.append(h3)
h.append(h4)
h.append(h5)
h.append(h6)
h.append(h7)
h.append(h8)
h.append(h9)
h.append(h10)
h.append(h11)
h.append(h12)
h.append(h13)
h.append(h14)
h.append(h15)
h.append(h16)


setting_for_h = [
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
['fakelepton',  'data', 5],
['fakephoton',  'data',15],
['doublefake',  'data',30],
['WGJJ',     'mc',         2],
['WGJets',   'mc',         7],
['data',  'data',       1],
]

for i in range(len(h)):
    read_hist(hist_name, h[i], indir, which_year, which_channel, setting_for_h[i][1], which_region, barrel_or_endcap, setting_for_h[i][0])
    set_hist(h[i], setting_for_h[i][0], setting_for_h[i][1], setting_for_h[i][2])

h[10].Add(h[12],-1)
h[11].Add(h[12],-1)

cv = TCanvas("cv_", "cv_", 900, 900)
fPads1 = TPad("pad1", "", 0.00, 0.225, 1.00, 1.00);
fPads2 = TPad("pad2", "", 0.00, 0.00, 1.00, 0.23);
fPads1.SetFillColor(0);
fPads1.SetLineColor(1);
fPads2.SetFillColor(0);
fPads2.SetLineColor(1);
#fPads1.GetFrame().SetBorderSize(120)
#fPads2.GetFrame().SetBorderSize(120)
fPads1.SetBottomMargin(0.02);
fPads1.SetTicks(1,1);
fPads1.SetTicks(1,1);
fPads2.SetTopMargin(0.02);
fPads2.SetBottomMargin(0.4);
fPads1.Draw();
fPads2.Draw();

#cv.SetLogy()
hs = THStack(" ", " ")
hmc = h[1].Clone()
hmc.Reset()
for i in range(len(h) - 1):
    #ii = 15 - i
    hs.Add(h[i])
    hmc.Add(h[i])

leg1 = TLegend(0.35,0.65,0.53,0.89);
leg1.SetBorderSize(0);
#leg1.AddEntry(DATA,  "DATA","lp");
leg1.AddEntry(h[13],  "WGJJ", "f");
leg1.AddEntry(h[14],"WGJets","f");
#leg1.AddEntry(h[12],    "Double Fake","f");
#leg1.AddEntry(h[11],    "Fake Photon","f");
#leg1.AddEntry(h[10],    "Fake Lepton","f");

leg2 = TLegend(0.55,0.65,0.68,0.89);
leg2.SetBorderSize(0);
leg2.AddEntry(h[0],    "ZA","f");
leg2.AddEntry(h[1],    "VV","f");
#leg2.AddEntry(h[2],    "WZ","f");
#leg2.AddEntry(h[3],    "ZZ","f");
leg2.AddEntry(h[9],   "TTA","f");
leg2.AddEntry(h[4],    "Single Top","f");


leg3 = TLegend(0.7,0.65,0.88,0.89);
leg3.SetBorderSize(0);
#leg3.AddEntry(h[4],    "Single Top","f");
leg3.AddEntry(h[12],    "Double Fake","f");
leg3.AddEntry(h[11],    "Fake Photon","f");
leg3.AddEntry(h[10],    "Fake Lepton","f");

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

lumiText = str(lumi) + " fb^{-1} (13 TeV)";
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

posX_=0;
posY_ = 1-t - relPosY*(1-t-b)
latex.SetTextFont(cmsTextFont);
latex.SetTextSize(0.8*cmsTextSize*t);
latex.SetTextAlign(align_);

extraTextSize = extraOverCmsTextSize*cmsTextSize;
latex.SetTextFont(extraTextFont);
latex.SetTextAlign(align_);
latex.SetTextSize(0.8*extraTextSize*t);

hs.SetMaximum(1.6 * hs.GetMaximum())

fPads1.cd();
hs.Draw("HIST")
hs.GetYaxis().SetTitle("Events/bin")
hs.GetYaxis().SetTitleSize(0.04)
hs.GetYaxis().SetTickLength(0.02)
hs.GetYaxis().SetTitleOffset(1.2)
hs.GetXaxis().SetTitleOffset(1.3)
hs.GetXaxis().SetLabelSize(0.0)
#hs.GetXaxis().SetTitle("M_{jj} [GeV]")   

bin_width_signal = ['500', '600', '700', '1000', 'inf']
bin_width_control = ['200', '300', '400', '500']
  
latex.DrawLatex(0.55,1.03-t+lumiTextOffset*t,lumiText);
latex.DrawLatex(1.3*l, posY_, cmsText);
latex.DrawLatex(1.3*l, posY_- relExtraDY*cmsTextSize*t, extraText);

latex1 = TLatex()
latex1.SetNDC();
latex1.SetTextAngle(0);
latex1.SetTextColor(1);
latex1.SetTextSize(0.03);

if expect_or_observe == 'observe':
    h[15].SetMarkerStyle(20);
    h[15].SetMarkerSize(1);
    h[15].SetStats(0);
    h[15].Draw("same p e")
    leg1.AddEntry(h[15],  "DATA","lp")

leg1.Draw()
leg2.Draw()
leg3.Draw()


fPads2.cd();
fPads2.SetGridy()
fPads2.SetGridx()

divide = TH1D()
if expect_or_observe == 'expect':
    divide = hmc.Clone()
    divide.Divide(hmc);
    for kk in range(divide.GetNbinsX()):
        if hmc.GetBinContent(kk+1) == 0 :
            divide.SetBinError(kk+1, 0)
        else :
            divide.SetBinError(kk+1, hmc.GetBinError(kk+1) / hmc.GetBinContent(kk+1))
else: 
    divide = h[15].Clone()
    divide.Divide(hmc);
    for kk in range(divide.GetNbinsX()):
        #print (h[15].GetBinError(i+1), hmc.GetBinError(i+1))
        #print (h[15].GetBinContent(i+1), hmc.GetBinContent(i+1))
        if hmc.GetBinContent(kk+1) == 0 :
            divide.SetBinError(kk+1, 0)
        else :
            divide.SetBinError(kk+1, h[15].GetBinError(kk+1) / hmc.GetBinContent(kk+1))
        print (kk, h[15].GetBinError(kk+1), hmc.GetBinError(kk+1), divide.GetBinError(kk+1))
        print (kk, h[15].GetBinContent(kk+1), hmc.GetBinContent(kk+1), divide.GetBinContent(kk+1))
#hmc.Print("all")

divide.SetTitle("");
divide.SetStats(0);
divide.SetLineColor(1);
divide.SetLineWidth(1);
divide.GetYaxis().SetTitle("Data/MC");
divide.GetYaxis().CenterTitle();
divide.GetYaxis().SetTitleSize(0.1);
divide.GetYaxis().SetTitleOffset(0.3);
divide.GetYaxis().SetLabelSize(0.07);
divide.GetYaxis().SetRangeUser(0,2);
divide.GetYaxis().SetNdivisions(-5);
divide.GetYaxis().SetTickLength(0.02);

divide.GetXaxis().SetTitle(xtitle );
divide.GetXaxis().SetLabelSize(0.12);
divide.GetXaxis().SetTitleSize(0.13);
divide.GetXaxis().SetTitleOffset(1.2);
divide.SetMarkerStyle(20);
divide.SetMarkerSize(0.8);

#divide.GetXaxis().SetLabelSize(0.13)
divide.Draw("p ");
#divide.Print("all")
xlow  = divide.GetXaxis().GetXmin();
xhigh = divide.GetXaxis().GetXmax();
f1 = TF1("f1","1",-500,500);
f1.SetLineStyle(2);
f1.Draw("same");

cv.SaveAs(outdir + "/"+ which_year + "_" + which_channel + "_" + which_region + "_"+barrel_or_endcap+ "_" + hist_name +".png")
outf = TFile( outdir + '/'+which_year + "_" + which_channel  + "_" + which_region + "_"+barrel_or_endcap+ "_" + hist_name+'.root', 'RECREATE' )
cv.Write()
outf.Close()
