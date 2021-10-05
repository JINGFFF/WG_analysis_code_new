// -- g++ -Wall -o fakerate `root-config --cflags --glibs` -L $ROOTSYS/lib -lRooFit -lRooFitCore -lFoam -lHtml -lMinuit tff.cc
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TString.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TMath.h"
#include "TROOT.h"
#include <TFractionFitter.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

ofstream out;
//TFile * file_cv = new TFile("tff_v3/cv_result.root", "RECREATE");
int      with_error = 0;  // -- 0 without_error, 1 with error

Double_t edges[8]  = {25, 30, 40, 50, 70, 100, 135, 400};
TH1F* barrel_fraction = new TH1F("barrel_fraction", "barrel_fraction", 7, edges);
TH1F* endcap_fraction = new TH1F("endcap_fraction", "endcap_fraction", 7, edges);
TH1F* barrel_fraction_error = new TH1F("barrel_fraction_error", "barrel_fraction_error", 7, edges);
TH1F* endcap_fraction_error = new TH1F("endcap_fraction_error", "endcap_fraction_error", 7, edges);

void fit(TString year, TString indir, TString outdir, TFile * file_cv, Double_t ptlow, Double_t pthigh, string isbarrel_, TString fake_type) {
    TString isbarrel = isbarrel_;

    Double_t lumi;
    if(year == "2016") lumi = 35.92;
    if(year == "2017") lumi = 4.794;//41.53;
    if(year == "2018") lumi = 59.74;

    Double_t sieie_cut;
    if (isbarrel.Contains("barrel")) {
        sieie_cut = 0.01015;
    }
    else {
        sieie_cut = 0.0272;
    }
    TFile* fdata = TFile::Open(indir + "/" + year + "_medium_btag_data.root");
    TFile* ftrue = TFile::Open(indir + "/" + year + "_medium_btag_true.root");
    TFile* ffake = TFile::Open(indir + "/" + year + "_medium_btag_"+fake_type+".root");

    TString histname, cv;
    if (isbarrel == "barrel" && ptlow == 25 ) { histname = "hist_barrel_25to30"; cv = "cv_barrel_25to30";}
    if (isbarrel == "barrel" && ptlow == 30 ) { histname = "hist_barrel_30to40"; cv = "cv_barrel_30to40";}
    if (isbarrel == "barrel" && ptlow == 40 ) { histname = "hist_barrel_40to50"; cv = "cv_barrel_40to50";}
    if (isbarrel == "barrel" && ptlow == 50 ) { histname = "hist_barrel_50to70"; cv = "cv_barrel_50to70";}
    if (isbarrel == "barrel" && ptlow == 70 ) { histname = "hist_barrel_70to100"; cv = "cv_barrel_70to100";}
    if (isbarrel == "barrel" && ptlow == 100 ) { histname = "hist_barrel_100to135"; cv = "cv_barrel_100to135";}
    if (isbarrel == "barrel" && ptlow == 135 ) { histname = "hist_barrel_135to400"; cv = "cv_barrel_135to400";}
    if (isbarrel == "endcap" && ptlow == 25 ) { histname = "hist_endcap_25to30"; cv = "cv_endcap_25to30";}
    if (isbarrel == "endcap" && ptlow == 30 ) { histname = "hist_endcap_30to40"; cv = "cv_endcap_30to40";}
    if (isbarrel == "endcap" && ptlow == 40 ) { histname = "hist_endcap_40to50"; cv = "cv_endcap_40to50";}
    if (isbarrel == "endcap" && ptlow == 50 ) { histname = "hist_endcap_50to70"; cv = "cv_endcap_50to70";}
    if (isbarrel == "endcap" && ptlow == 70 ) { histname = "hist_endcap_70to100"; cv = "cv_endcap_70to100";}
    if (isbarrel == "endcap" && ptlow == 100 ) { histname = "hist_endcap_100to135"; cv = "cv_endcap_100to135";}
    if (isbarrel == "endcap" && ptlow == 135 ) { histname = "hist_endcap_135to400"; cv = "cv_endcap_135to400";}
    TH1F* hdata = (TH1F*)fdata->Get(histname);
    TH1F* htrue = (TH1F*)ftrue->Get(histname);
    htrue->Scale(lumi);

    TH1F* hfake = (TH1F*)ffake->Get(histname);
    for (Int_t i = 0; i < hdata->GetNbinsX() + 2; i++) {
        if (hdata->GetBinContent(i) < 0) {
            hdata->SetBinContent(i, 0);
        }
        if (htrue->GetBinContent(i) < 0) {
            htrue->SetBinContent(i, 0);
        }
        if (hfake->GetBinContent(i) < 0) {
            hfake->SetBinContent(i, 0);
        }
    }

    //hdata->Scale(35.875);
    //hfake->Scale(35.875);

    hdata->Sumw2();
    htrue->Sumw2();
    hfake->Sumw2();
    TObjArray* mc = new TObjArray(2);
    mc->Add(htrue);
    mc->Add(hfake);
    TFractionFitter* fit = new TFractionFitter(hdata, mc);  // initialise
    fit->Constrain(1, 0.0, 1.0);                            // constrain fraction 1 to be between 0 and 1
    //fit->SetRangeX(1,15);                    // use only the first 15 bins in the fit
    Int_t status = fit->Fit();  // perform the fit
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ fit status in pt" << ptlow << "_" << pthigh << ": " << status << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$" << htrue->GetBinContent(56) << '\n';

    TCanvas* c1 = new TCanvas(cv, cv, 1000, 700);
    Double_t val0, err0;
    Double_t val1, err1;
    Double_t n_data_total = hdata->Integral();
    fit->GetResult(0, val0, err0);  // fit fraction of true
    fit->GetResult(1, val1, err1);  // fit fraction of fake

    //-- get fake rate
    Int_t    nbin  = hdata->FindFixBin(sieie_cut) - 1;
    Int_t    nbins = hdata->GetNbinsX();
    Double_t fake_err_in_window, fake_err_total, data_err_in_window, data_err_total;

    Double_t n_hfake_in_window = hfake->IntegralAndError(1, nbin, fake_err_in_window);  // value in n_hfake_in_window
    Double_t n_hfake_total     = hfake->IntegralAndError(1, nbins, fake_err_total);     // value in n_hfake_in_total
    Double_t sector1           = n_hfake_in_window / n_hfake_total;                     // value in n_hfake_in_window/n_hfake_total

    Double_t n_hdata_in_window = hdata->IntegralAndError(1, nbin, data_err_in_window);  // n_hdata_in_window
    Double_t n_hdata_total     = hdata->IntegralAndError(1, nbins, data_err_total);     // n_hdata_total
    Double_t sector2           = n_hdata_in_window / n_hdata_total;                     // value in n_hdata_in_window/n_hdata_total

    Double_t fakerate = val1 * sector1 / sector2;

    //-- get fake rate error

    Double_t err_sector1  = TMath::Sqrt(TMath::Power(sector1, 2) * (TMath::Power(fake_err_in_window / n_hfake_in_window, 2) + TMath::Power(fake_err_total / n_hfake_total, 2)));  // error in n_hfake_in_window/n_hfake_total
    Double_t err_sector2  = TMath::Sqrt(TMath::Power(sector2, 2) * (TMath::Power(data_err_in_window / n_hdata_in_window, 2) + TMath::Power(data_err_total / n_hdata_total, 2)));  // error in n_hdata_in_window/n_hdata_total
    Double_t tmp          = val1 * sector1;
    Double_t tmp_err      = TMath::Sqrt(TMath::Power(val1 * sector1, 2) * (TMath::Power(err_sector1 / sector1, 2) + TMath::Power(err1 / val1, 2)));   // error in n_hfake_in_window/n_hfake_total
    Double_t fakerate_err = TMath::Sqrt(TMath::Power(tmp / sector2, 2) * (TMath::Power(tmp_err / tmp, 2) + TMath::Power(err_sector2 / sector2, 2)));  // error in n_hfake_in_window/n_hfake_total

    if (true) {  // check on fit status
        TH1F* result = (TH1F*)fit->GetPlot();
        hdata->Draw("p e");
        hdata->GetYaxis()->SetTitle("Events/bin");
        hdata->GetYaxis()->SetTitleOffset(1.45);
        hdata->GetXaxis()->SetTitle("#sigma_{i#etai#eta}");
        hdata->SetStats(kFALSE);
        hdata->SetLineColor(kBlack);
        hdata->SetMarkerStyle(20);
        result->Draw("HIST same");
        result->SetLineColor(kGreen);
        result->SetLineWidth(2);
        result->SetStats(kFALSE);

        // draw template nomalized to the frac*n_data_total
        htrue->SetLineColor(kRed);
        htrue->SetLineWidth(2);

        //htrue->SetMarkerColor(kRed);
        htrue->SetStats(kFALSE);
        htrue->DrawNormalized("HIST e same", val0 * n_data_total);
        hfake->SetLineColor(kBlue);
        hfake->SetLineWidth(2);

        //hfake->SetMarkerColor(kBlue);
        hfake->SetStats(kFALSE);
        hfake->DrawNormalized("HIST e same", val1 * n_data_total);


        double maximum_data           = 1.3 * hdata->GetMaximum();
        double maximum_prediction     = 1.3 * result->GetMaximum();
        double maximumForStack = (maximum_data > maximum_prediction ? maximum_data : maximum_prediction);

        hdata->SetMaximum(maximumForStack);


        //output info
        TString range =  isbarrel;
        TLatex  latex0;
        latex0.SetNDC();
        latex0.SetTextSize(0.03);
        latex0.SetLineWidth(1);
        latex0.DrawLatex(0.75, 0.90, range);

        TLegend* leg = new TLegend(0.53, 0.48, 0.88, 0.88, NULL, "brNDC");
        leg->SetFillStyle(0);
        leg->SetLineColor(0);
        leg->SetFillColor(10);
        leg->SetBorderSize(0);
        leg->SetHeader(Form("%0.fGeV<p_{T}^{#gamma}<%0.fGeV", ptlow, pthigh), "c");
        leg->AddEntry(hdata, "Data", "LPE");
        leg->AddEntry(result, "Template prediction", "LPE");
        leg->AddEntry(htrue, "True template from W#gamma", "LPE");
        leg->AddEntry(hfake, "Fake template from Data", "LPE");
        leg->Draw("same");

        TString statusStr = "fit status: ";
        statusStr += status;
        TLatex latex1;
        latex1.SetNDC();
        latex1.SetTextSize(0.03);
        latex1.SetLineWidth(1);
        latex1.DrawLatex(0.55, 0.44, statusStr);

        TString  strChi    = "#chi^{2}/ndf=";
        Double_t chi2      = fit->GetChisquare();
        Int_t    ndf       = fit->GetNDF();
        Double_t chi2ToNDF = chi2 / ndf;
        float    chiFloat  = (100 * chi2ToNDF);
        int      chiInt    = chiFloat;
        strChi += (chiInt / 100);
        strChi += ".";
        strChi += (chiInt % 100);
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.03);
        latex.SetLineWidth(1);
        latex.DrawLatex(0.55, 0.38, strChi);

        TString strFR = "fake rate = (";
        if (with_error) {
            out << setprecision(3) << fakerate << "+/-" << setprecision(3) << fakerate_err << "|";
        }
        else {
            out << setprecision(3) << fakerate << "|";
        }
        float FRFloat = (10000 * fakerate);
        int   FRInt   = FRFloat;
        strFR += (FRInt / 100);
        strFR += ".";
        strFR += (FRInt % 100);
        strFR += "#pm";
        float FRErrFloat = (10000 * fakerate_err);
        int   FRErrInt   = FRErrFloat;
        strFR += (FRErrInt / 100);
        strFR += ".";
        strFR += (FRErrInt % 100);
        strFR += ")%";
        TLatex* textFR = new TLatex(0.55, 0.34, strFR);
        textFR->SetNDC();
        textFR->SetTextSize(0.03);
        textFR->SetLineWidth(1);
        textFR->Draw();
        //gStyle->SetOptStat(0);
    }
    //TFile * file_cv = new TFile("tff_v3/cv_result.root", "RECREATE");
    if(isbarrel == "barrel"){ 
        barrel_fraction->SetBinContent(barrel_fraction->FindBin((ptlow+pthigh)/2.),fakerate);
        barrel_fraction_error->SetBinContent(barrel_fraction_error->FindBin((ptlow+pthigh)/2.),fakerate_err);
    }
    if(isbarrel == "endcap"){ 
        endcap_fraction->SetBinContent(endcap_fraction->FindBin((ptlow+pthigh)/2.),fakerate); 
        endcap_fraction_error->SetBinContent(endcap_fraction_error->FindBin((ptlow+pthigh)/2.),fakerate_err);
    }

    file_cv->cd();
    c1->Write();
    c1->SaveAs(outdir + "/" + year + "_"  + cv + "_.png");
}
//true_MUON_BARREL_pt_30_40.root
int main(int argc, char** argv) {
    with_error = atoi(argv[1]);
    TString year = argv[2];
    TString indir = argv[3];
    TString outdir = argv[4];
    TString fake_type = argv[5];

    system("mkdir -p " + outdir);
    TFile * file_cv = new TFile(outdir + "/result_.root", "RECREATE");
    TString outtxt = outdir + "/fit_result.md";
    out.open(outtxt, ios::out);
    out << "## fake photon rate \n";
    TString table_header = "|photon pt bin|endcap|barrel| \n";
    out << table_header;
    out << "|:-----------:|:---------:|:-------------:| \n";
    Double_t ptlow[7]  = {25, 30, 40, 50, 70, 100, 135};
    Double_t pthigh[7] = {30, 40, 50, 70, 100, 135, 400};
    for (size_t i = 0; i < 7; i++) {
        out << "|" << ptlow[i] << "-" << pthigh[i] << " GeV|";
        fit(year, indir, outdir, file_cv, ptlow[i], pthigh[i], "endcap", fake_type);
        fit(year, indir, outdir, file_cv, ptlow[i], pthigh[i], "barrel", fake_type);
        out << "\n";
    }
    out.close();
    file_cv->cd();
    barrel_fraction->Write();
    endcap_fraction->Write();
    barrel_fraction_error->Write();
    endcap_fraction_error->Write();
    file_cv->Close();
    return 0;
}
