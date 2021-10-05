hadd -f $1_WGJJ.root \
$1_all_mc_signal_barrel_WGJJ.root \
$1_all_mc_signal_endcap_WGJJ.root

hadd -f $1_WGJets.root \
$1_all_mc_signal_barrel_WGJets.root \
$1_all_mc_signal_endcap_WGJets.root

hadd -f $1_qcd_ewk.root $1_WGJets.root $1_WGJJ.root
#hadd $1_qcd_ewk.root $1*qcd_ewk.root
#hadd $1_WGJJ.root $1*WGJJ.root
