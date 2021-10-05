2_calculate_uncertainty.py $1 $2 2018 $3 signal muon barrel medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 signal electron barrel medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 signal muon endcap medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 signal electron endcap medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 control muon barrel medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 control electron barrel medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 control muon endcap medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 control electron endcap medium mjj

#cat $2/signal_muon_all/*py     > $2/uncer_aqgc_muon_all.py
#cat $2/signal_electron_all/*py > $2/uncer_aqgc_electron_all.py
#pdf_scale_uncer.py 2018 $1 $2 muon aqgc all 1
#pdf_scale_uncer.py 2018 $1 $2 electron aqgc all 1
