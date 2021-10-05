cp 1_uncertainty_jet1pt_all.sh 1_uncertainty_ptlep_all.sh
sed -i 's/make_hist_jet1pt_mc/make_hist_ptlep_mc/g' 1_uncertainty_ptlep_all.sh
cp 1_uncertainty_jet1pt_all.sh 1_uncertainty_photonet_all.sh
sed -i 's/make_hist_jet1pt_mc/make_hist_photonet_mc/g' 1_uncertainty_photonet_all.sh
cp 1_uncertainty_jet1pt_all.sh 1_uncertainty_mla_all.sh
sed -i 's/make_hist_jet1pt_mc/make_hist_mla_mc/g' 1_uncertainty_mla_all.sh
