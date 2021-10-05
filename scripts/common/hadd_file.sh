hadd -f $1_all_data_signal_barrel_data.root \
$1_muon_data_signal_barrel_data.root \
$1_electron_data_signal_barrel_data.root

hadd -f $1_all_data_signal_barrel_fakephoton.root \
$1_muon_data_signal_barrel_fakephoton.root \
$1_electron_data_signal_barrel_fakephoton.root

hadd -f $1_all_data_signal_barrel_fakelepton.root \
$1_muon_data_signal_barrel_fakelepton.root \
$1_electron_data_signal_barrel_fakelepton.root

hadd -f $1_all_data_signal_barrel_doublefake.root \
$1_muon_data_signal_barrel_doublefake.root \
$1_electron_data_signal_barrel_doublefake.root

hadd -f $1_all_data_signal_endcap_data.root \
$1_muon_data_signal_endcap_data.root \
$1_electron_data_signal_endcap_data.root

hadd -f $1_all_data_signal_endcap_fakephoton.root \
$1_muon_data_signal_endcap_fakephoton.root \
$1_electron_data_signal_endcap_fakephoton.root

hadd -f $1_all_data_signal_endcap_fakelepton.root \
$1_muon_data_signal_endcap_fakelepton.root \
$1_electron_data_signal_endcap_fakelepton.root

hadd -f $1_all_data_signal_endcap_doublefake.root \
$1_muon_data_signal_endcap_doublefake.root \
$1_electron_data_signal_endcap_doublefake.root

hadd -f $1_all_data_control_barrel_data.root \
$1_muon_data_control_barrel_data.root \
$1_electron_data_control_barrel_data.root

hadd -f $1_all_data_control_barrel_fakephoton.root \
$1_muon_data_control_barrel_fakephoton.root \
$1_electron_data_control_barrel_fakephoton.root

hadd -f $1_all_data_control_barrel_fakelepton.root \
$1_muon_data_control_barrel_fakelepton.root \
$1_electron_data_control_barrel_fakelepton.root

hadd -f $1_all_data_control_barrel_doublefake.root \
$1_muon_data_control_barrel_doublefake.root \
$1_electron_data_control_barrel_doublefake.root

hadd -f $1_all_data_control_endcap_data.root \
$1_muon_data_control_endcap_data.root \
$1_electron_data_control_endcap_data.root

hadd -f $1_all_data_control_endcap_fakephoton.root \
$1_muon_data_control_endcap_fakephoton.root \
$1_electron_data_control_endcap_fakephoton.root

hadd -f $1_all_data_control_endcap_fakelepton.root \
$1_muon_data_control_endcap_fakelepton.root \
$1_electron_data_control_endcap_fakelepton.root

hadd -f $1_all_data_control_endcap_doublefake.root \
$1_muon_data_control_endcap_doublefake.root \
$1_electron_data_control_endcap_doublefake.root
#signal barrel
hadd -f $1_all_mc_signal_barrel_qcd_ewk.root \
$1_muon_mc_signal_barrel_WGJJ.root \
$1_electron_mc_signal_barrel_WGJJ.root \
$1_muon_mc_signal_barrel_WGJets.root \
$1_electron_mc_signal_barrel_WGJets.root

hadd -f $1_all_mc_signal_barrel_WGJJ.root \
$1_muon_mc_signal_barrel_WGJJ.root \
$1_electron_mc_signal_barrel_WGJJ.root 

hadd -f $1_all_mc_signal_barrel_WGJets.root \
$1_muon_mc_signal_barrel_WGJets.root \
$1_electron_mc_signal_barrel_WGJets.root

hadd -f $1_all_mc_signal_barrel_other.root \
$1_muon_mc_signal_barrel_WGJJ_interference.root \
$1_muon_mc_signal_barrel_WW.root \
$1_muon_mc_signal_barrel_WZ.root \
$1_muon_mc_signal_barrel_ZZ.root \
$1_muon_mc_signal_barrel_ST_*.root \
$1_muon_mc_signal_barrel_TTG.root \
$1_muon_mc_signal_barrel_ZG.root \
$1_electron_mc_signal_barrel_WGJJ_interference.root \
$1_electron_mc_signal_barrel_WW.root \
$1_electron_mc_signal_barrel_WZ.root \
$1_electron_mc_signal_barrel_ZZ.root \
$1_electron_mc_signal_barrel_ST_*.root \
$1_electron_mc_signal_barrel_TTG.root \
$1_electron_mc_signal_barrel_ZG.root

#signal endcap
hadd -f $1_all_mc_signal_endcap_qcd_ewk.root \
$1_muon_mc_signal_endcap_WGJJ.root \
$1_electron_mc_signal_endcap_WGJJ.root \
$1_muon_mc_signal_endcap_WGJets.root \
$1_electron_mc_signal_endcap_WGJets.root

hadd -f $1_all_mc_signal_endcap_WGJJ.root \
$1_muon_mc_signal_endcap_WGJJ.root \
$1_electron_mc_signal_endcap_WGJJ.root 

hadd -f $1_all_mc_signal_endcap_WGJets.root \
$1_muon_mc_signal_endcap_WGJets.root \
$1_electron_mc_signal_endcap_WGJets.root

hadd -f $1_all_mc_signal_endcap_other.root \
$1_muon_mc_signal_endcap_WGJJ_interference.root \
$1_muon_mc_signal_endcap_WW.root \
$1_muon_mc_signal_endcap_WZ.root \
$1_muon_mc_signal_endcap_ZZ.root \
$1_muon_mc_signal_endcap_ST_*.root \
$1_muon_mc_signal_endcap_TTG.root \
$1_muon_mc_signal_endcap_ZG.root \
$1_electron_mc_signal_endcap_WGJJ_interference.root \
$1_electron_mc_signal_endcap_WW.root \
$1_electron_mc_signal_endcap_WZ.root \
$1_electron_mc_signal_endcap_ZZ.root \
$1_electron_mc_signal_endcap_ST_*.root \
$1_electron_mc_signal_endcap_TTG.root \
$1_electron_mc_signal_endcap_ZG.root

#control barrel
hadd -f $1_all_mc_control_barrel_qcd_ewk.root \
$1_muon_mc_control_barrel_WGJJ.root \
$1_electron_mc_control_barrel_WGJJ.root \
$1_muon_mc_control_barrel_WGJets.root \
$1_electron_mc_control_barrel_WGJets.root

hadd -f $1_all_mc_control_barrel_WGJJ.root \
$1_muon_mc_control_barrel_WGJJ.root \
$1_electron_mc_control_barrel_WGJJ.root

hadd -f $1_all_mc_control_barrel_WGJets.root \
$1_muon_mc_control_barrel_WGJets.root \
$1_electron_mc_control_barrel_WGJets.root

hadd -f $1_all_mc_control_barrel_other.root \
$1_muon_mc_control_barrel_WGJJ_interference.root \
$1_muon_mc_control_barrel_WW.root \
$1_muon_mc_control_barrel_WZ.root \
$1_muon_mc_control_barrel_ZZ.root \
$1_muon_mc_control_barrel_ST_*.root \
$1_muon_mc_control_barrel_TTG.root \
$1_muon_mc_control_barrel_ZG.root \
$1_electron_mc_control_barrel_WGJJ_interference.root \
$1_electron_mc_control_barrel_WW.root \
$1_electron_mc_control_barrel_WZ.root \
$1_electron_mc_control_barrel_ZZ.root \
$1_electron_mc_control_barrel_ST_*.root \
$1_electron_mc_control_barrel_TTG.root \
$1_electron_mc_control_barrel_ZG.root

#control endcap
hadd -f $1_all_mc_control_endcap_qcd_ewk.root \
$1_muon_mc_control_endcap_WGJJ.root \
$1_electron_mc_control_endcap_WGJJ.root \
$1_muon_mc_control_endcap_WGJets.root \
$1_electron_mc_control_endcap_WGJets.root

hadd -f $1_all_mc_control_endcap_WGJJ.root \
$1_muon_mc_control_endcap_WGJJ.root \
$1_electron_mc_control_endcap_WGJJ.root

hadd -f $1_all_mc_control_endcap_WGJets.root \
$1_muon_mc_control_endcap_WGJets.root \
$1_electron_mc_control_endcap_WGJets.root

hadd -f $1_all_mc_control_endcap_other.root \
$1_muon_mc_control_endcap_WGJJ_interference.root \
$1_muon_mc_control_endcap_WW.root \
$1_muon_mc_control_endcap_WZ.root \
$1_muon_mc_control_endcap_ZZ.root \
$1_muon_mc_control_endcap_ST_*.root \
$1_muon_mc_control_endcap_TTG.root \
$1_muon_mc_control_endcap_ZG.root \
$1_electron_mc_control_endcap_WGJJ_interference.root \
$1_electron_mc_control_endcap_WW.root \
$1_electron_mc_control_endcap_WZ.root \
$1_electron_mc_control_endcap_ZZ.root \
$1_electron_mc_control_endcap_ST_*.root \
$1_electron_mc_control_endcap_TTG.root \
$1_electron_mc_control_endcap_ZG.root

# 4 channels
hadd -f $1_muon_mc_signal_barrel_qcd_ewk.root \
$1_muon_mc_signal_barrel_WGJJ.root \
$1_muon_mc_signal_barrel_WGJets.root

hadd -f $1_electron_mc_signal_barrel_qcd_ewk.root \
$1_electron_mc_signal_barrel_WGJJ.root \
$1_electron_mc_signal_barrel_WGJets.root

hadd -f $1_muon_mc_signal_barrel_other.root \
$1_muon_mc_signal_barrel_WGJJ_interference.root \
$1_muon_mc_signal_barrel_WW.root \
$1_muon_mc_signal_barrel_WZ.root \
$1_muon_mc_signal_barrel_ZZ.root \
$1_muon_mc_signal_barrel_ST_*.root \
$1_muon_mc_signal_barrel_TTG.root \
$1_muon_mc_signal_barrel_ZG.root 

hadd -f $1_electron_mc_signal_barrel_other.root \
$1_electron_mc_signal_barrel_WGJJ_interference.root \
$1_electron_mc_signal_barrel_WW.root \
$1_electron_mc_signal_barrel_WZ.root \
$1_electron_mc_signal_barrel_ZZ.root \
$1_electron_mc_signal_barrel_ST_*.root \
$1_electron_mc_signal_barrel_TTG.root \
$1_electron_mc_signal_barrel_ZG.root 

hadd -f $1_muon_mc_signal_endcap_qcd_ewk.root \
$1_muon_mc_signal_endcap_WGJJ.root \
$1_muon_mc_signal_endcap_WGJets.root

hadd -f $1_electron_mc_signal_endcap_qcd_ewk.root \
$1_electron_mc_signal_endcap_WGJJ.root \
$1_electron_mc_signal_endcap_WGJets.root

hadd -f $1_muon_mc_signal_endcap_other.root \
$1_muon_mc_signal_endcap_WGJJ_interference.root \
$1_muon_mc_signal_endcap_WW.root \
$1_muon_mc_signal_endcap_WZ.root \
$1_muon_mc_signal_endcap_ZZ.root \
$1_muon_mc_signal_endcap_ST_*.root \
$1_muon_mc_signal_endcap_TTG.root \
$1_muon_mc_signal_endcap_ZG.root 

hadd -f $1_electron_mc_signal_endcap_other.root \
$1_electron_mc_signal_endcap_WGJJ_interference.root \
$1_electron_mc_signal_endcap_WW.root \
$1_electron_mc_signal_endcap_WZ.root \
$1_electron_mc_signal_endcap_ZZ.root \
$1_electron_mc_signal_endcap_ST_*.root \
$1_electron_mc_signal_endcap_TTG.root \
$1_electron_mc_signal_endcap_ZG.root

hadd -f $1_muon_mc_control_barrel_qcd_ewk.root \
$1_muon_mc_control_barrel_WGJJ.root \
$1_muon_mc_control_barrel_WGJets.root

hadd -f $1_electron_mc_control_barrel_qcd_ewk.root \
$1_electron_mc_control_barrel_WGJJ.root \
$1_electron_mc_control_barrel_WGJets.root

hadd -f $1_muon_mc_control_barrel_other.root \
$1_muon_mc_control_barrel_WGJJ_interference.root \
$1_muon_mc_control_barrel_WW.root \
$1_muon_mc_control_barrel_WZ.root \
$1_muon_mc_control_barrel_ZZ.root \
$1_muon_mc_control_barrel_ST_*.root \
$1_muon_mc_control_barrel_TTG.root \
$1_muon_mc_control_barrel_ZG.root 

hadd -f $1_electron_mc_control_barrel_other.root \
$1_electron_mc_control_barrel_WGJJ_interference.root \
$1_electron_mc_control_barrel_WW.root \
$1_electron_mc_control_barrel_WZ.root \
$1_electron_mc_control_barrel_ZZ.root \
$1_electron_mc_control_barrel_ST_*.root \
$1_electron_mc_control_barrel_TTG.root \
$1_electron_mc_control_barrel_ZG.root 

hadd -f $1_muon_mc_control_endcap_qcd_ewk.root \
$1_muon_mc_control_endcap_WGJJ.root \
$1_muon_mc_control_endcap_WGJets.root

hadd -f $1_electron_mc_control_endcap_qcd_ewk.root \
$1_electron_mc_control_endcap_WGJJ.root \
$1_electron_mc_control_endcap_WGJets.root

hadd -f $1_muon_mc_control_endcap_other.root \
$1_muon_mc_control_endcap_WGJJ_interference.root \
$1_muon_mc_control_endcap_WW.root \
$1_muon_mc_control_endcap_WZ.root \
$1_muon_mc_control_endcap_ZZ.root \
$1_muon_mc_control_endcap_ST_*.root \
$1_muon_mc_control_endcap_TTG.root \
$1_muon_mc_control_endcap_ZG.root 

hadd -f $1_electron_mc_control_endcap_other.root \
$1_electron_mc_control_endcap_WGJJ_interference.root \
$1_electron_mc_control_endcap_WW.root \
$1_electron_mc_control_endcap_WZ.root \
$1_electron_mc_control_endcap_ZZ.root \
$1_electron_mc_control_endcap_ST_*.root \
$1_electron_mc_control_endcap_TTG.root \
$1_electron_mc_control_endcap_ZG.root
