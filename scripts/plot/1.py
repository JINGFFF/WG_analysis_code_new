import ROOT
from ROOT import gROOT, TCanvas, TPad, TGraph, TPad, TFile, TH1D, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array

h = []
h.append(TH1D("", "", 3, 0, 3))
h.append(TH1D("", "", 4, 0, 4))
#h[0].Print("all")
#h[1].Print("all")
a = []
print(a)
a.append(3)
a[0].append(3)
a[1].append(3)

print(a)
