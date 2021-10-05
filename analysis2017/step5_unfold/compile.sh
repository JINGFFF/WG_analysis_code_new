g++ -o make_hist_photonet_mc `root-config --cflags --glibs` 1_uncertainty_histgram_photonet_mc.C
g++ -o make_hist_photonet `root-config --cflags --glibs` 1_uncertainty_histgram_photonet_data.C
g++ -o make_hist_mla_mc `root-config --cflags --glibs` 1_uncertainty_histgram_mla_mc.C
g++ -o make_hist_mla `root-config --cflags --glibs` 1_uncertainty_histgram_mla_data.C
g++ -o make_hist_jet1pt_mc `root-config --cflags --glibs` 1_uncertainty_histgram_jet1pt_mc.C
g++ -o make_hist_jet1pt `root-config --cflags --glibs` 1_uncertainty_histgram_jet1pt_data.C
g++ -o make_hist_ptlep_mc `root-config --cflags --glibs` 1_uncertainty_histgram_ptlep_mc.C 
g++ -o make_hist_ptlep `root-config --cflags --glibs` 1_uncertainty_histgram_ptlep_data.C
