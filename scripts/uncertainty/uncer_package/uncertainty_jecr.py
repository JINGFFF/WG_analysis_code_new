#!/usr/bin/env python
#import sys
#import os
#import re
#from uncertainty_unfold import *
import ROOT
from ROOT import gROOT, TGraph, TLatex, TCanvas, TPad, TFile, TH1, TH2D, TF1, TLatex, TMath, TROOT, TTree, TString, TH2, TStyle, TLegend, THStack
from array import array
def get_jecr_1D(which_region, outdir, which_sample, uncertainty_hist_name, infilename, var_name, lumi, hist_name, draw_op ):
    f_in = TFile.Open(infilename)
    h_center   = f_in.Get(hist_name)
    h_up       = f_in.Get(hist_name+uncertainty_hist_name+"_up")
    h_down     = f_in.Get(hist_name+uncertainty_hist_name+"_down")
    h_center.Scale(lumi)
    #h_center.Print("all")

    h_up.Scale(lumi)
    h_down.Scale(lumi)

    h_center.SetLineColor(2)
    h_up.SetLineColor(4)
    h_down.SetLineColor(3)

    h_center.SetStats(0)
    h_up.SetStats(0)
    h_down.SetStats(0)

    NbinsX = h_center.GetNbinsX()
    NbinsY = h_center.GetNbinsY()

    Nbins = NbinsX*NbinsY
    h_uncertainty = []

    uncertainty = 0
    for j in range(NbinsX) :
        max_diff = max(0, abs(h_center.GetBinContent(j+1)-h_up.GetBinContent(j+1)), abs(h_center.GetBinContent(j+1)-h_down.GetBinContent(j+1)))
        uncertainty = 0
        if(h_center.GetBinContent(j+1) > 0) :
            uncertainty = max_diff/h_center.GetBinContent(j+1)
        h_uncertainty.append(uncertainty)       

    if draw_op == 'on':
        c1 = TCanvas(uncertainty_hist_name,uncertainty_hist_name,900,600)
        fPads1 = TPad("pad1", "", 0.00, 0.4, 0.99, 0.99)
        fPads2 = TPad("pad2", "", 0.00, 0.00, 0.99, 0.4)
        fPads1.SetBottomMargin(0.02);
        fPads1.SetTicks(1,1);
        fPads1.SetTicks(1,1);

        fPads2.SetTopMargin(0.02);
        fPads2.SetBottomMargin(0.4)
        #fPads1.SetBottomMargin(0)
        #fPads2.SetTopMargin(0)
        #fPads2.SetBottomMargin(0.4)
        c1.cd()
        fPads1.Draw()
        fPads2.Draw()
        fPads1.cd()
        fPads2.SetGridy()
        fPads1.SetGridx()
        fPads2.SetGridx()

   
        h_up.SetTitle(uncertainty_hist_name)
        h_up.SetLineWidth(2)
        h_center.SetLineWidth(2)
        h_up.GetXaxis().SetLabelSize(0.0)
        h_down.SetLineWidth(2)
        h_up.SetLineStyle(7)
        h_down.SetLineStyle(7)

        h_up.Draw("hist")
        h_center.Draw("hist same")
        h_down.Draw("hist same")

        leg3 = TLegend(0.7,0.7,0.9,0.9)
        leg3.AddEntry(h_up,     "up")
        leg3.AddEntry(h_center, "center")
        leg3.AddEntry(h_down,   "down")

        bin_width_signal = ['500', '600', '700', '1000', 'inf']
        bin_width_control = ['200', '300', '400', '500']
        #h_up.Print("all")
        x1 = array('d',(4, 4))
        y1 = array('d',(0, 1.1*h_up.GetMaximum()))
        g1 = TGraph(2, x1, y1)
        g1.SetLineColor(1)
        g1.SetLineStyle(2)
        g1.SetLineWidth(2)

        x2 = array('d',(8, 8))
        y2 = array('d',(0, 1.1*h_up.GetMaximum()))
        g2 = TGraph(2, x2, y2)
        g2.SetLineColor(1)
        g2.SetLineStyle(2)
        g2.SetLineWidth(2)


        latex1 = TLatex()
        latex1.SetNDC();
        latex1.SetTextAngle(0);
        latex1.SetTextColor(1);
        latex1.SetTextSize(0.05);
        if which_region == 'signal':
            g1.Draw("C ")
            g2.Draw("C ")
            latex1.DrawLatex(0.13, 0.4, "30 Gev < M_{l#gamma} < 80 GeV");
            latex1.DrawLatex(0.38, 0.4, "80 Gev < M_{l#gamma} < 130 GeV");
            latex1.DrawLatex(0.65, 0.4, "130 Gev < M_{l#gamma} < inf GeV");
        print('max : ',h_up.GetMaximum())
        #h_up.SetMaximum(1.3 * h_up.GetMaximum())
        #maximum = 1.5 * h_up.GetMaximum()
        leg3.Draw()
        #fPads1.Update()
        fPads2.cd()

        nominal  = h_center.Clone("nominal")
        nomNoErr = nominal.Clone("nomNoErr")
        for i in range(nomNoErr.GetNbinsX()) :
            nomNoErr.SetBinError(i+1,0)
        tmp_h_up   = h_up.Clone()
        tmp_h_down = h_down.Clone()
        nominal.SetTitle("")

        tmp_h_up.Divide(nominal)
        print('tmp_max : ',tmp_h_up.GetMaximum())
        tmp_h_down.Divide(nominal)
        nominal.Divide(nomNoErr)
        for i in range(nominal.GetNbinsX()) :
            nominal.SetBinError(i+1,nominal.GetBinError(i+1)/nomNoErr.GetBinContent(i+1))
        nominal.SetFillStyle(3001)
        nominal.SetFillColor(16)
        nominal.GetYaxis().SetLabelSize(0.07)
        nominal.GetYaxis().SetNdivisions(404)
        nominal.GetXaxis().SetTitle(var_name+" [GeV]")
        nominal.GetXaxis().SetLabelSize(0.1)
        nominal.GetXaxis().SetTitleFont(12)
        nominal.GetXaxis().SetTitleSize(0.1)
        #cout<<tmp_h_down->GetMinimum()-0.1<<" "<<tmp_h_up->GetMaximum()+0.05<<endl
        ra = abs(max(tmp_h_down.GetMinimum(), tmp_h_up.GetMaximum()) -1 )
        print('ra : ', ra)
        nominal.GetYaxis().SetRangeUser(1-1.2*ra,1+1.2*ra);
        #nominal.GetYaxis().SetRangeUser(tmp_h_down.GetMinimum() - 0.1,tmp_h_up.GetMaximum()+0.05)
        nominal.Draw("EP")
        if which_region == 'signal':
            for i in range(nominal.GetNbinsX()) :
                nominal.GetXaxis().SetBinLabel(i+1,str(bin_width_signal[i%4]) + '~' + str(bin_width_signal[i%4+1]) )
            nominal.GetXaxis().SetLabelSize(0.1)

        elif which_region == 'control':
            for i in range(nominal.GetNbinsX()) :
                nominal.GetXaxis().SetBinLabel(i+1,str(bin_width_control[i]) + '~' + str(bin_width_control[i+1]))
            nominal.GetXaxis().SetLabelSize(0.13)

        tmp_h_up.Draw("same hist ][")
        tmp_h_down.Draw("same hist ][")
        fPads2.Update()
        fPads1.cd()
        h_up.SetMaximum(1.5 * h_up.GetMaximum())
        #maximum = 1.5 * h_up.GetMaximum()
        #leg3.Draw()
        fPads1.Update()

        #c1.SaveAs(outdir+"/graph/"+which_sample+"_"+which_region+"_"+uncertainty_hist_name+".png")
        c1.SaveAs(outdir + "/" + which_sample + "_" + hist_name + uncertainty_hist_name + ".png")
        c1.Close()
        #c1.Delete()
    return h_uncertainty
    f_in.Close()
