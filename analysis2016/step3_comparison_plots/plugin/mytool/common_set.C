using namespace std;

   Double_t eff_b_jet_tight[10] ={ 0.320501, 0.438741, 0.494037, 0.516037, 0.521717, 0.511363, 0.463285, 0.380385, 0.268077, 0.22774};
   Double_t eff_b_jet_medium[10] ={ 0.494944, 0.604301, 0.655748, 0.680486, 0.693248, 0.693765, 0.667501, 0.616062, 0.535007, 0.505137};
   Double_t eff_b_jet_loose[10] ={ 0.686011, 0.764027, 0.805729, 0.831279, 0.849252, 0.860238, 0.858505, 0.849354, 0.843092, 0.849315};
   Double_t eff_c_jet_tight[10] ={ 0.0183726, 0.0223202, 0.0220486, 0.0226769, 0.024171, 0.0263377, 0.0265894, 0.0277639, 0.032798, 0.0315315};
   Double_t eff_c_jet_medium[10] ={ 0.106603, 0.119726, 0.114486, 0.114447, 0.118432, 0.12676, 0.128575, 0.138768, 0.151776, 0.189189};
   Double_t eff_c_jet_loose[10] ={ 0.354013, 0.383178, 0.384509, 0.389559, 0.39991, 0.416174, 0.426847, 0.467101, 0.51934, 0.617117};
   Double_t eff_l_jet_tight[10] ={ 0.00116083, 0.00108697, 0.0010221, 0.00107856, 0.00123402, 0.00159878, 0.00193249, 0.00285934, 0.00374868, 0.00664452};
   Double_t eff_l_jet_medium[10] ={ 0.0130506, 0.0120923, 0.00997784, 0.00970286, 0.0105707, 0.0128526, 0.0161229, 0.0244205, 0.0325238, 0.0340532};
   Double_t eff_l_jet_loose[10] ={ 0.113448, 0.109686, 0.0945654, 0.0941139, 0.102728, 0.122753, 0.15118, 0.205856, 0.277138, 0.35299};
   ifstream fin("./scalef/jet/DeepCSV_2016LegacySF_WP_V1.csv");

   TFile * pu_weight_input = new TFile ("./scalef/pileup/puweight2016.root");
   TH1D* h_pu_weight = (TH1D*)pu_weight_input->Get("h2");
   TFile * pu_weight_up_input = new TFile ("./scalef/pileup/puweight2016_up.root");
   TH1D* h_pu_weight_up = (TH1D*)pu_weight_up_input->Get("h2");
   TFile * pu_weight_down_input = new TFile ("./scalef/pileup/puweight2016_down.root");
   TH1D* h_pu_weight_down = (TH1D*)pu_weight_down_input->Get("h2");

   // photon medium ID weight
   TFile * photon_ID_weight_input = new TFile ("./scalef/photon/Fall17V2_2016_Medium_photons.root");
   TH2D* h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   TFile * muon_HLT_weight_B_F_input = new TFile ("./scalef/muon/EfficienciesAndSF_RunBtoF.root");
   TFile * muon_HLT_weight_G_H_input = new TFile ("./scalef/muon/EfficienciesAndSF_Period4.root");

   TDirectory * muon_HLT_weight_B_F_dir  = (TDirectory*)muon_HLT_weight_G_H_input->Get("IsoMu24_OR_IsoTkMu24_PtEtaBins");
   TDirectory * muon_HLT_weight_G_H_dir  = (TDirectory*)muon_HLT_weight_G_H_input->Get("IsoMu24_OR_IsoTkMu24_PtEtaBins");

   TH2D * h_muon_HLT_B_F_weight = (TH2D*)muon_HLT_weight_B_F_dir->Get("abseta_pt_ratio");
   TH2D * h_muon_HLT_G_H_weight = (TH2D*)muon_HLT_weight_G_H_dir->Get("abseta_pt_ratio");

   // muon ID weight
   TFile * muon_ID_weight_B_F_input = new TFile ("./scalef/muon/RunBCDEF_SF_ID.root");
   TH2D * h_muon_ID_B_F_weight = (TH2D*)muon_ID_weight_B_F_input->Get("NUM_TightID_DEN_genTracks_eta_pt");

   TFile * muon_ID_weight_G_H_input = new TFile ("./scalef/muon/RunGH_SF_ID.root");
   TH2D * h_muon_ID_G_H_weight = (TH2D*)muon_ID_weight_G_H_input->Get("NUM_TightID_DEN_genTracks_eta_pt");

   // muon iso scale
   TFile * muon_iso_weight_B_F_input = new TFile ("./scalef/muon/RunBCDEF_SF_ISO.root");
   TH2D * h_muon_iso_B_F_weight = (TH2D*)muon_iso_weight_B_F_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_eta_pt");

   TFile * muon_iso_weight_G_H_input = new TFile ("./scalef/muon/RunGH_SF_ISO.root");
   TH2D * h_muon_iso_G_H_weight = (TH2D*)muon_iso_weight_G_H_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_eta_pt");

   // electron reco weight
   TFile * electron_reco_weight_input = new TFile ("./scalef/electron/EGM2D_BtoH_GT20GeV_RecoSF_Legacy2016.root");
   TH2D * h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID weight
   TFile *electron_ID_weight_input = new TFile ("./scalef/electron/2016LegacyReReco_ElectronTight_Fall17V2.root");
   TH2D * h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");

   // electron HLT weight
   TFile * electron_HLT_weight_input = new TFile ("./scalef/electron/egammaEffi.txt_EGM2D.root");
   TH2D * h_electron_HLT_weight = (TH2D*)electron_HLT_weight_input->Get("EGamma_SF2D");

   // data driven
   // fake lepton weight
   TFile * file_fake_muon_weight     = TFile::Open("./scalef/data_driven_weight/muon_fakerate.root");
   TFile * file_fake_electron_weight = TFile::Open("./scalef/data_driven_weight/electron_fakerate.root");
   TH2D* hist_fake_muon_weight     = (TH2D*)file_fake_muon_weight->Get("weight");
   TH2D* hist_fake_electron_weight = (TH2D*)file_fake_electron_weight->Get("weight");
   // fake photon weight
   TFile * file_fake_photon_weight = TFile::Open("./scalef/data_driven_weight/fake_photon_weight.root");
   TH1F* hist_barrel_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("barrel_fake_photon_weight");
   TH1F* hist_endcap_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("endcap_fake_photon_weight");

   TH1F* hist_barrel_fake_photon_weight_up = (TH1F*)file_fake_photon_weight->Get("barrel_fake_photon_weight_up");
   TH1F* hist_endcap_fake_photon_weight_up = (TH1F*)file_fake_photon_weight->Get("endcap_fake_photon_weight_up");
   TH1F* hist_barrel_fake_photon_weight_down = (TH1F*)file_fake_photon_weight->Get("barrel_fake_photon_weight_down");
   TH1F* hist_endcap_fake_photon_weight_down = (TH1F*)file_fake_photon_weight->Get("endcap_fake_photon_weight_down");

