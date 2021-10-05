##aqgc
#electron
./make_hist filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data aqgc all data medium T
./make_hist filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data aqgc all doublefake medium T
./make_hist filelist_dir3/tight_for_analysis_electron.txt $1 2016 electron data aqgc all fakephoton medium T
./make_hist filelist_dir3/loose_for_analysis_electron.txt $1 2016 electron data aqgc all fakelepton medium T
#muon
./make_hist filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data aqgc all data medium T
./make_hist filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data aqgc all doublefake medium T
./make_hist filelist_dir3/tight_for_analysis_muon.txt $1 2016 muon data aqgc all fakephoton medium T
./make_hist filelist_dir3/loose_for_analysis_muon.txt $1 2016 muon data aqgc all fakelepton medium T
###aqgc region
#electron all
./make_hist_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 electron mc aqgc all WGJets medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 electron mc aqgc all ST_s medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 electron mc aqgc all ST_t medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 electron mc aqgc all ST_tbar medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 electron mc aqgc all ST_tW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 electron mc aqgc all ST_tbarW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 electron mc aqgc all WGJJ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 electron mc aqgc all WW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 electron mc aqgc all WZ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 electron mc aqgc all ZZ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 electron mc aqgc all ZG medium T
./make_hist_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 electron mc aqgc all TTG medium T
#muon all
./make_hist_mc filelist_dir3/tight_for_analysis_WGJets.txt $1 2016 muon mc aqgc all WGJets medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_s.txt $1 2016 muon mc aqgc all ST_s medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_t.txt $1 2016 muon mc aqgc all ST_t medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tbar.txt $1 2016 muon mc aqgc all ST_tbar medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tW.txt $1 2016 muon mc aqgc all ST_tW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ST_tbarW.txt $1 2016 muon mc aqgc all ST_tbarW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WGJJ.txt $1 2016 muon mc aqgc all WGJJ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WW.txt $1 2016 muon mc aqgc all WW medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WZ.txt $1 2016 muon mc aqgc all WZ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ZZ.txt $1 2016 muon mc aqgc all ZZ medium T
./make_hist_mc filelist_dir3/tight_for_analysis_ZG.txt $1 2016 muon mc aqgc all ZG medium T
./make_hist_mc filelist_dir3/tight_for_analysis_TTG.txt $1 2016 muon mc aqgc all TTG medium T
###### interference
./make_hist_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2016 electron mc aqgc all WGJJ_interference medium T
./make_hist_mc filelist_dir3/tight_for_analysis_WGJJ_interference.txt $1 2016 muon mc aqgc all WGJJ_interference medium T
