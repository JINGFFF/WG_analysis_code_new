using namespace std;
   Double_t eff_b_jet_tight[10]  =  {0.364617, 0.486436, 0.547392, 0.569581, 0.571089, 0.549325, 0.472031, 0.302929, 0.083657, 0.0132275};
   Double_t eff_b_jet_medium[10] = {0.550703, 0.655257, 0.708018, 0.733123, 0.743445, 0.73445, 0.685051, 0.559069, 0.337587, 0.156085};
   Double_t eff_b_jet_loose[10] =  {0.747759, 0.817121, 0.85459, 0.876767, 0.891093, 0.894935, 0.880487, 0.835978, 0.761482, 0.655203};

   Double_t eff_c_jet_tight[10]  =  {0.0153558, 0.0200096, 0.0227714, 0.0253193, 0.0274522, 0.0289083, 0.0250352, 0.0149095, 0.00344508, 0.00315457};
   Double_t eff_c_jet_medium[10] = {0.100341, 0.111135, 0.115312, 0.123547, 0.132176, 0.137718, 0.12915, 0.102925, 0.0532662, 0.022082};
   Double_t eff_c_jet_loose[10] =  {0.382709, 0.419236, 0.431463, 0.44594, 0.460301, 0.46941, 0.454488, 0.433304, 0.384656, 0.274448};

   Double_t eff_l_jet_tight[10]  =  {0.00106936, 0.000838236, 0.000886369, 0.00103145, 0.00125678, 0.0015645, 0.00162616, 0.00144056, 0.000416533, 0};
   Double_t eff_l_jet_medium[10] = {0.0073096, 0.00782829, 0.00801778, 0.00894073, 0.0105117, 0.0122973, 0.0130844, 0.0131463, 0.00887536, 0.00256148};
   Double_t eff_l_jet_loose[10] =  {0.0951708, 0.0892728, 0.0866658, 0.0965049, 0.112411, 0.131063, 0.15024, 0.173086, 0.179398, 0.170082};

   ifstream fin("./scalef/jet/DeepCSV_94XSF_WP_V4_B_F.csv");

   TFile * pu_weight_input = new TFile ("./scalef/pileup/puweight2017.root");
   TH1D* h_pu_weight = (TH1D*)pu_weight_input->Get("h2");
   TFile * pu_weight_up_input = new TFile ("./scalef/pileup/puweight2017_up.root");
   TH1D* h_pu_weight_up = (TH1D*)pu_weight_up_input->Get("h2");
   TFile * pu_weight_down_input = new TFile ("./scalef/pileup/puweight2017_down.root");
   TH1D* h_pu_weight_down = (TH1D*)pu_weight_down_input->Get("h2");

   // photon medium ID weight
   TFile * photon_ID_weight_input = new TFile ("./scalef/photon/2017_PhotonsMedium.root");
   TH2D * h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   TFile * muon_HLT_weight_input = new TFile ("./scalef/muon/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
   TDirectory * muon_HLT_weight_dir  = (TDirectory*)muon_HLT_weight_input->Get("IsoMu27_PtEtaBins");
   TH2D * h_muon_HLT_weight = (TH2D*)muon_HLT_weight_dir->Get("abseta_pt_ratio");

   // muon ID weight
   TFile * muon_ID_weight_input = new TFile ("./scalef/muon/RunBCDEF_SF_ID.root");
   TH2D * h_muon_ID_weight = (TH2D*)muon_ID_weight_input->Get("NUM_TightID_DEN_genTracks_pt_abseta");

   // muon iso weight
   TFile * muon_iso_weight_input = new TFile ("./scalef/muon/RunBCDEF_SF_ISO.root");
   TH2D * h_muon_iso_weight = (TH2D*)muon_iso_weight_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

   // electron reco weight
   TFile * electron_reco_weight_input = new TFile ("./scalef/electron/egammaEffi.txt_EGM2D_runBCDEF_passingRECO.root");
   TH2D * h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID weight
   TFile * electron_ID_weight_input = new TFile ("./scalef/electron/2017_ElectronTight.root");
   TH2D * h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");


   // electron HLT weight
   TFile * electron_HLT_weight_input = new TFile ("./scalef/electron/2017_egamma_hlt_sf.root");
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

