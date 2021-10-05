#!/usr/bin/env python2

import sys
import os
#import re
print('ok')

import numpy

import ROOT
from ROOT import gROOT, THStack, TH1D, TList, TFile, TH2D, TCanvas, TPad, TLegend

name = sys.argv[1]
uncer_theory = sys.argv[2]
uncer_sys = sys.argv[3]

acc_file = sys.argv[4]
input_2016 = sys.argv[5]
input_2017 = sys.argv[6]
input_2018 = sys.argv[7]
sample = sys.argv[8]

['ptlep1', "\'p_{T}^{lep1} [GeV]\'"],
['etalep1', "\'#eta^{lep1}\'"],
['mtVlepJECnew', "\'M(T)_{W} [GeV]\'"],
['ptVlepJEC', "\'p_{T}^{W,lep} [GeV]\'"],
['photonet', "\'p_{T}^{#gamma} [GeV]\'"],
['photoneta', "\'#eta^{#gamma}\'"],
['photoneta', "\'#eta_{super cluster}^{#gamma}\'"],
['jet1pt', "\'p_{T}^{j1} [GeV]\'"],
['jet1eta', "\'#eta^{j1}\'"],
['jet2pt', "\'p_{T}^{j2} [GeV]\'"],
['jet2eta', "\'#eta^{j2}\'"],
['Mjj', "\'M_{jj} [GeV]\'"],
['zepp', 'zepp'],
['deltaeta', "\'#Delta#eta_{jj}\'"],
['MET_et', "\'E_{T}^{miss} [GeV]\'"],
['Dphiwajj', "\'|#phi_{W#gamma}-#phi_{j1,j2}|\'"],
['Mla', "\'M_{l#gamma} [GeV]\'"],

xtitle = ''
if name == 'ptlep' : 
   xtitle = "p_{T}^{lep1} [GeV]"
if name == 'jet1pt' :
   xtitle = "p_{T}^{j1} [GeV]"
if name == 'mla' :
   xtitle = "M_{l#gamma} [GeV]"
if name == 'photonet' :
   xtitle = "p_{T}^{#gamma} [GeV]"

total_xs = 20.30
if sample == 'WGJJ':
    total_xs = 20.30
else:
    total_xs = 90.85

print('ok')
uncer_theory_list = numpy.loadtxt(uncer_theory)
print(uncer_theory_list)
uncer_sys_file = open(uncer_sys, "r")

#print ok
f_in_WGJJ_2016 = TFile.Open(input_2016)
f_in_WGJJ_2017 = TFile.Open(input_2017)
f_in_WGJJ_2018 = TFile.Open(input_2018)
acc = TFile.Open(acc_file)

hh = acc.Get("acc_" + name)
bin_num = hh.GetNbinsX()

uncer_list_down = []
uncer_list_up = []

def read(file_u):
    lines = file_u.readlines()
    t_uncer_list_down, t_uncer_list_up = [], []
    for i in range(0, len(lines)):
        for j in range(0, len(lines)):
            if "r_Bin" + str(bin_num-i) + " :    +1.000" in lines[j]:
                xx = lines[j].split(' ')
                print (xx[11])
                xxx = xx[11].split('/')
                t_uncer_list_down.append(xxx[0])
                t_uncer_list_up.append(xxx[1])
    return t_uncer_list_down, t_uncer_list_up

#uncer_list_down_all, uncer_list_up_all = read(uncer_all_file)
uncer_list_down_sys, uncer_list_up_sys = read(uncer_sys_file)

#for i in range(len(uncer_list_down_all)):
#    uncer_list_up.append(abs((float(uncer_list_up_all[i])**2 - float(uncer_list_up_sys[i])**2))**0.5)
#    uncer_list_down.append(abs((float(uncer_list_down_all[i])**2 - float(uncer_list_down_sys[i])**2))**0.5)

    # sys_down = abs((uncer_down**2 - tmp_uncer_down**2))**0.5

print (uncer_list_down)
print (uncer_list_up)


h_acc = TH1D("h_acc","h_acc", bin_num, 0 ,bin_num)
h_acc.Print()
hh.Scale(total_xs/hh.GetSum())
bin_with = []
#bin_with = [20,40,70,110,400]
for i in range(hh.GetNbinsX()+1) :
    if i == hh.GetNbinsX():
        bin_with.append(hh.GetBinLowEdge(i+1))
    else:
        bin_with.append(hh.GetBinLowEdge(i+1))
print(bin_with)
error = []
h_sys = h_acc.Clone()

for i in range(hh.GetNbinsX()) :
    h_acc.SetBinContent(i+1,hh.GetBinContent(i+1)/(bin_with[i+1] - bin_with[i]))
    h_acc.GetXaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')
    h_acc.SetBinError(i+1,  h_acc.GetBinContent(i+1)*uncer_theory_list[i])
    h_sys.SetBinContent(i+1,hh.GetBinContent(i+1)/(bin_with[i+1] - bin_with[i]))
    h_sys.SetBinError(i+1,  h_sys.GetBinContent(i+1)*(abs(float(uncer_list_down_sys[i])) + abs(float(uncer_list_up_sys[i])) )/2)
    h_acc.GetXaxis().SetLabelSize(0);
    h_sys.GetXaxis().SetLabelSize(0);

    error.append(h_sys.GetBinError(i+1))
#c2 = TCanvas("XS","XS",900,700)
#c2.cd()
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

fPads1.cd();
h_acc.Draw(" text E2")
h_acc.SetTitle("")
h_acc.SetStats(0)
#h_acc.SetLineColor(2)
h_acc.SetFillColor(2);
h_acc.SetLineColor(2);
h_acc.SetLineWidth(0);
h_acc.SetMarkerSize(0);
h_acc.SetFillStyle(3005);

#h_acc.SetLineStyle(1);
#h_acc.SetLineColor(2);
#h_acc.SetLineWidth(3);
#h_acc.SetFillStyle(3002);
#h_acc.SetFillColor(2)

h_sys.SetLineColor(1)
h_sys.SetMarkerStyle(20)
h_sys.SetMarkerSize(1)
h_sys.SetMarkerColor(1)

h_acc.GetXaxis().SetTitle(xtitle)
h_acc.GetYaxis().SetTitle("fb / GeV")
h_acc.SetMaximum(1.3 * (h_acc.GetMaximum() + max(error)))
h_acc.SetMinimum(0)

h_sys.Draw("same p e")
l1=TLegend(0.6,0.7,0.9,0.88);
l1.SetBorderSize(0);
l1.AddEntry(h_acc,"EW W#gamma MadGraph");
l1.AddEntry(h_sys,"Expected result (stat.#oplus syst.)");
l1.Draw()

fPads2.cd();
divide_acc = h_acc.Clone()
divide_sys = h_sys.Clone()
divide_acc.Divide(h_acc);
divide_sys.Divide(h_acc);
divide_acc.Print("all")
for k in range(h_sys.GetNbinsX()):
    if h_acc.GetBinContent(k+1) == 0 :
        divide_acc.SetBinError(k+1, 0)
        divide_sys.SetBinError(k+1, 0)
    else :
        divide_acc.SetBinError(k+1, h_acc.GetBinError(k+1) / h_acc.GetBinContent(k+1))
        divide_sys.SetBinError(k+1, h_sys.GetBinError(k+1) / h_sys.GetBinContent(k+1))

divide_acc.Print("all")
divide_sys.Print("all")

divide_acc.SetTitle("");
divide_acc.SetStats(0);
#divide_acc.SetLineColor();
#divide_acc.SetLineWidth(1);
divide_acc.GetYaxis().SetTitle("Data/MG");
divide_acc.GetYaxis().CenterTitle();
divide_acc.GetYaxis().SetTitleSize(0.1);
divide_acc.GetYaxis().SetTitleOffset(0.3);
divide_acc.GetYaxis().SetLabelSize(0.07);

error_r = []
for i in range(hh.GetNbinsX()) :
    error_r.append(divide_sys.GetBinError(i+1))
rrr = 1
if (1.05*max(error_r)) >=1:
    rrr = 1
else:
    rrrr = 1.05*max(error_r)
divide_acc.GetYaxis().SetRangeUser(1 - rrr, 1+rrr);
divide_acc.GetYaxis().SetNdivisions(-5);
divide_acc.GetYaxis().SetTickLength(0.02);

divide_acc.GetXaxis().SetTitle(xtitle );
divide_acc.GetXaxis().SetLabelSize(0.12);
divide_acc.GetXaxis().SetTitleSize(0.13);
divide_acc.GetXaxis().SetTitleOffset(1.2);
divide_acc.SetMarkerStyle(20);
divide_acc.SetMarkerSize(0.8);

divide_acc.Draw("E2 ");
#divide_acc.Print("all")
divide_sys.Draw("p e same");

cv.SaveAs('XS_'+sample+"_"+name+'.png')



h_2016, h_2017, h_2018 = [], [], []

h = f_in_WGJJ_2016.Get("hist_")
#bin_num = h.GetNbinsX()
#h.Print()
# read hist
for i in range(bin_num):
   h_2016.append(f_in_WGJJ_2016.Get("hist_in_" + str(i) + "_"))
   h_2016[i].Scale(35.92)
   h_2017.append(f_in_WGJJ_2017.Get("hist_in_" + str(i) + "_"))
   h_2017[i].Scale(41.50)
   h_2018.append(f_in_WGJJ_2018.Get("hist_in_" + str(i) + "_"))
   h_2018[i].Scale(59.74)



#bin_with = [20,40,70,110,400]
h_matrix = TH2D("h_matrix","h_matrix", bin_num, 0 ,bin_num, bin_num, 0 ,bin_num)
for i in range(bin_num) :
    content_gen = 0
    for j in range(bin_num) :
        content_gen = content_gen + h_2016[j].GetBinContent(i+1) + h_2017[j].GetBinContent(i+1) + h_2018[j].GetBinContent(i+1)
    for k in range(bin_num) :
        matrix_content = h_2016[k].GetBinContent(i+1) + h_2017[k].GetBinContent(i+1) + h_2018[k].GetBinContent(i+1)
        h_matrix.SetBinContent(i+1, k+1, matrix_content / content_gen)
    h_matrix.GetXaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')
    h_matrix.GetYaxis().SetBinLabel(i+1,str(' '))
    #h.GetYaxis().SetBinLabel(i+1,str(bin_with[i]) + '~' + str(bin_with[i+1]) + ' GeV')

c1 = TCanvas("Acceptance","Acceptance", 900,600)
c1.cd()
h_matrix.Draw("coloz text")
h_matrix.SetTitle("")
h_matrix.SetStats(0)
#h.SetLineColor(2)
h_matrix.GetXaxis().SetTitle("Gen "+ name)
h_matrix.GetYaxis().SetTitle("Reco "+ name)
#h.GetYaxis().SetTitleOffset(0.3)
h_matrix.SetMaximum(1.3 * h.GetMaximum())
c1.SaveAs('matrix_'+sample+"_"+name+'.png')
