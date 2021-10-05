using namespace std;

   Double_t eff_b_jet_tight[10]  =  {0.375338, 0.493779, 0.553314, 0.575056, 0.579706, 0.563553, 0.491523, 0.327807, 0.105522, 0.0292929};
   Double_t eff_b_jet_medium[10] = {0.565127, 0.663282, 0.714194, 0.737916, 0.750325, 0.745599, 0.701239, 0.590619, 0.390365, 0.216667};
   Double_t eff_b_jet_loose[10] =  {0.753404, 0.813243, 0.850107, 0.87129, 0.88806, 0.89424, 0.881965, 0.846197, 0.798682, 0.70404};
   Double_t eff_c_jet_tight[10]  =  {0.0178263, 0.0219464, 0.0242307, 0.0269731, 0.0299322, 0.0316588, 0.0287384, 0.0180558, 0.00498598, 0.00366972};
   Double_t eff_c_jet_medium[10] = {0.120439, 0.128175, 0.130494, 0.13781, 0.14765, 0.154195, 0.146221, 0.120963, 0.0666874, 0.0311927};
   Double_t eff_c_jet_loose[10] =  {0.392685, 0.415126, 0.42917, 0.445494, 0.462387, 0.473021, 0.461477, 0.451609, 0.421237, 0.348624};
   Double_t eff_l_jet_tight[10]  =  {0.00115722, 0.000821689, 0.000900955, 0.00110315, 0.0014241, 0.00181297, 0.0020553, 0.00198708, 0.000801618, 0};
   Double_t eff_l_jet_medium[10] = {0.00904002, 0.00806116, 0.00810405, 0.00924306, 0.0113922, 0.0137251, 0.0159489, 0.0189461, 0.0130992, 0.004265};
   Double_t eff_l_jet_loose[10] =  {0.125149, 0.0924003, 0.0847756, 0.0946918, 0.113998, 0.134914, 0.15921, 0.19733, 0.229773, 0.206426};
   ifstream fin("./scalef/jet/DeepCSV_102XSF_WP_V1.csv");

   TFile * pu_weight_input = new TFile ("./scalef/puweight_2018.root");
   TH1D* h_pu_weight = (TH1D*)pu_weight_input->Get("h2");
   TFile * pu_weight_up_input = new TFile ("./scalef/puweight_2018.root");
   TH1D* h_pu_weight_up = (TH1D*)pu_weight_input->Get("h2");
   TFile * pu_weight_down_input = new TFile ("./scalef/puweight_2018.root");
   TH1D* h_pu_weight_down = (TH1D*)pu_weight_input->Get("h2");

   // photon medium ID weight
   TFile * photon_ID_weight_input = new TFile ("./scalef/photon/2018_PhotonsMedium.root");
   TH2D* h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   TFile * muon_HLT_weight_input = new TFile ("./scalef/muon/EfficienciesAndSF_2018Data_AfterMuonHLTUpdate.root");
   TDirectory * muon_HLT_weight_dir  = (TDirectory*)muon_HLT_weight_input->Get("IsoMu24_PtEtaBins");
   TH2D* h_muon_HLT_weight = (TH2D*)muon_HLT_weight_dir->Get("abseta_pt_ratio");

   // muon ID weight
   TFile * muon_ID_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ID.root");
   TH2D* h_muon_ID_weight = (TH2D*)muon_ID_weight_input->Get("NUM_TightID_DEN_TrackerMuons_pt_abseta");

   // muon iso scale
   TFile * muon_iso_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ISO.root");
   TH2D* h_muon_iso_weight = (TH2D*)muon_iso_weight_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

   // electron reco scale
   TFile * electron_reco_weight_input = new TFile ("./scalef/electron/EGM2D_electron_Reco.root");
   TH2D* h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID scale
   TFile * electron_ID_weight_input = new TFile ("./scalef/electron/2018_ElectronTight.root");
   TH2D* h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");

   // electron HLT scale
   TFile * electron_HLT_weight_input = new TFile ("./scalef/electron/2018_egamma_hlt_sf.root");
   TH2D* h_electron_HLT_weight = (TH2D*)electron_HLT_weight_input->Get("EGamma_SF2D");

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

