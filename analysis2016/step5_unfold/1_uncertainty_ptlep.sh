##signal
#electron
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data signal barrel data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data signal barrel doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data signal barrel fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data signal barrel fakelepton medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data signal endcap data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data signal endcap doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data signal endcap fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data signal endcap fakelepton medium T
#muon
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data signal barrel data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data signal barrel doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data signal barrel fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data signal barrel fakelepton medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data signal endcap data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data signal endcap doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data signal endcap fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data signal endcap fakelepton medium T
##control
#electron
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data control barrel data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data control barrel doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data control barrel fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data control barrel fakelepton medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data control endcap data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data control endcap doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data control endcap fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data control endcap fakelepton medium T
#muon
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data control barrel data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data control barrel doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data control barrel fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data control barrel fakelepton medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data control endcap data medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data control endcap doublefake medium T
./make_hist_ptlep filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data control endcap fakephoton medium T
./make_hist_ptlep filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data control endcap fakelepton medium T
##
##
###signal region
#electron barrel
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 electron mc signal barrel WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 electron mc signal barrel ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 electron mc signal barrel ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 electron mc signal barrel ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 electron mc signal barrel ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 electron mc signal barrel ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 electron mc signal barrel WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 electron mc signal barrel WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 electron mc signal barrel WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 electron mc signal barrel ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 electron mc signal barrel ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 electron mc signal barrel TTG medium T
#electron endcap
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 electron mc signal endcap WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 electron mc signal endcap ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 electron mc signal endcap ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 electron mc signal endcap ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 electron mc signal endcap ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 electron mc signal endcap ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 electron mc signal endcap WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 electron mc signal endcap WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 electron mc signal endcap WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 electron mc signal endcap ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 electron mc signal endcap ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 electron mc signal endcap TTG medium T
#muon barrel
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 muon mc signal barrel WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 muon mc signal barrel ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 muon mc signal barrel ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 muon mc signal barrel ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 muon mc signal barrel ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 muon mc signal barrel ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 muon mc signal barrel WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 muon mc signal barrel WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 muon mc signal barrel WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 muon mc signal barrel ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 muon mc signal barrel ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 muon mc signal barrel TTG medium T
#muon endcap
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 muon mc signal endcap WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 muon mc signal endcap ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 muon mc signal endcap ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 muon mc signal endcap ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 muon mc signal endcap ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 muon mc signal endcap ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 muon mc signal endcap WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 muon mc signal endcap WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 muon mc signal endcap WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 muon mc signal endcap ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 muon mc signal endcap ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 muon mc signal endcap TTG medium T
###control region
#electron barrel
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 electron mc control barrel WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 electron mc control barrel ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 electron mc control barrel ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 electron mc control barrel ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 electron mc control barrel ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 electron mc control barrel ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 electron mc control barrel WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 electron mc control barrel WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 electron mc control barrel WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 electron mc control barrel ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 electron mc control barrel ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 electron mc control barrel TTG medium T
#electron endcap
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 electron mc control endcap WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 electron mc control endcap ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 electron mc control endcap ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 electron mc control endcap ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 electron mc control endcap ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 electron mc control endcap ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 electron mc control endcap WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 electron mc control endcap WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 electron mc control endcap WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 electron mc control endcap ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 electron mc control endcap ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 electron mc control endcap TTG medium T
#muon barrel
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 muon mc control barrel WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 muon mc control barrel ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 muon mc control barrel ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 muon mc control barrel ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 muon mc control barrel ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 muon mc control barrel ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 muon mc control barrel WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 muon mc control barrel WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 muon mc control barrel WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 muon mc control barrel ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 muon mc control barrel ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 muon mc control barrel TTG medium T
#muon endcap
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 muon mc control endcap WGJets medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 muon mc control endcap ST_s medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 muon mc control endcap ST_t medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 muon mc control endcap ST_tbar medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 muon mc control endcap ST_tW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 muon mc control endcap ST_tbarW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 muon mc control endcap WGJJ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 muon mc control endcap WW medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 muon mc control endcap WZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 muon mc control endcap ZZ medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 muon mc control endcap ZG medium T
./make_hist_ptlep_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 muon mc control endcap TTG medium T
