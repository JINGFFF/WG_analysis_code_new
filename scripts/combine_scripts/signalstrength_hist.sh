combineCards.py $2/$1_muon_signal_barrel_bin_* $2/$1_muon_signal_endcap_bin_* $2/$1_electron_signal_barrel_bin_* $2/$1_electron_signal_endcap_bin_* *control*.txt -S > datacard.txt
combine -M FitDiagnostics datacard.txt --saveShapes -t -1 --expectSignal=1 --saveWithUncertainties > resunt.txt
