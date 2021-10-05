cp 1_uncertainty_histgram_data.C 1_uncertainty_histgram_$1_data.C
cp 1_uncertainty_histgram_mc.C 1_uncertainty_histgram_$1_mc.C
sed -i "s/value/$1/g" 1_uncertainty_histgram_$1_mc.C
sed -i "s/value/$1/g" 1_uncertainty_histgram_$1_data.C
g++ -o make_hist_$1_mc `root-config --cflags --glibs` 1_uncertainty_histgram_$1_mc.C
g++ -o make_hist_$1 `root-config --cflags --glibs` 1_uncertainty_histgram_$1_data.C
cp 1_uncertainty_wgjj.sh 1_uncertainty_wgjj_$1.sh
sed -i "s/make_hist/make_hist_$1/g" 1_uncertainty_wgjj_$1.sh
submit_condor.py unfold 1_uncertainty_wgjj_$1.sh test_1 unfold_$1_$2
