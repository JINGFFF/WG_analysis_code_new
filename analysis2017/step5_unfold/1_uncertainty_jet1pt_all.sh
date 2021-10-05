##signal
#all
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data signal barrel data medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data signal barrel doublefake medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data signal barrel fakephoton medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data signal barrel fakelepton medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data signal endcap data medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data signal endcap doublefake medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data signal endcap fakephoton medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data signal endcap fakelepton medium T
##control
#all
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data control barrel data medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data control barrel doublefake medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data control barrel fakephoton medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data control barrel fakelepton medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data control endcap data medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data control endcap doublefake medium T
./make_hist_jet1pt filelist_dir3/tight_for_analysis_all.txt $1 2017 all data control endcap fakephoton medium T
./make_hist_jet1pt filelist_dir3/loose_for_analysis_all.txt $1 2017 all data control endcap fakelepton medium T
##
##
###signal region
#all barrel
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJets_with_gen.txt $1 2017 all mc signal barrel WGJets medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2017 all mc signal barrel ST_s medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2017 all mc signal barrel ST_t medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2017 all mc signal barrel ST_tbar medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2017 all mc signal barrel ST_tW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2017 all mc signal barrel ST_tbarW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_d0.txt $1 2017 all mc signal barrel WGJJ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WW.txt $1 2017 all mc signal barrel WW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2017 all mc signal barrel WZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2017 all mc signal barrel ZZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2017 all mc signal barrel ZG medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2017 all mc signal barrel TTG medium T
#all endcap
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJets_with_gen.txt $1 2017 all mc signal endcap WGJets medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2017 all mc signal endcap ST_s medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2017 all mc signal endcap ST_t medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2017 all mc signal endcap ST_tbar medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2017 all mc signal endcap ST_tW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2017 all mc signal endcap ST_tbarW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_d0.txt $1 2017 all mc signal endcap WGJJ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WW.txt $1 2017 all mc signal endcap WW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2017 all mc signal endcap WZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2017 all mc signal endcap ZZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2017 all mc signal endcap ZG medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2017 all mc signal endcap TTG medium T
###control region
#all barrel
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJets_with_gen.txt $1 2017 all mc control barrel WGJets medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2017 all mc control barrel ST_s medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2017 all mc control barrel ST_t medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2017 all mc control barrel ST_tbar medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2017 all mc control barrel ST_tW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2017 all mc control barrel ST_tbarW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_d0.txt $1 2017 all mc control barrel WGJJ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WW.txt $1 2017 all mc control barrel WW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2017 all mc control barrel WZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2017 all mc control barrel ZZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2017 all mc control barrel ZG medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2017 all mc control barrel TTG medium T
#all endcap
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJets_with_gen.txt $1 2017 all mc control endcap WGJets medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2017 all mc control endcap ST_s medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2017 all mc control endcap ST_t medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2017 all mc control endcap ST_tbar medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2017 all mc control endcap ST_tW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2017 all mc control endcap ST_tbarW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_d0.txt $1 2017 all mc control endcap WGJJ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WW.txt $1 2017 all mc control endcap WW medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2017 all mc control endcap WZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2017 all mc control endcap ZZ medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2017 all mc control endcap ZG medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2017 all mc control endcap TTG medium T
#
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2017 all mc signal barrel WGJJ_interference medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2017 all mc signal endcap WGJJ_interference medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2017 all mc control barrel WGJJ_interference medium T
./make_hist_jet1pt_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2017 all mc control endcap WGJJ_interference medium T
