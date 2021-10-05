#2_calculate_uncertainty.py $1 $2 2018 $3 signal muon barrel medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 signal electron barrel medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 signal muon endcap medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 signal electron endcap medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 control muon barrel medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 control electron barrel medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 control muon endcap medium mjj
#2_calculate_uncertainty.py $1 $2 2018 $3 control electron endcap medium mjj

cat $2/signal_muon_barrel/*py     > $2/uncer_signal_muon_barrel.py
cat $2/signal_muon_endcap/*py     > $2/uncer_signal_muon_endcap.py
cat $2/signal_electron_barrel/*py     > $2/uncer_signal_electron_barrel.py
cat $2/signal_electron_endcap/*py     > $2/uncer_signal_electron_endcap.py
cat $2/control_muon_barrel/*py     > $2/uncer_control_muon_barrel.py
cat $2/control_muon_endcap/*py     > $2/uncer_control_muon_endcap.py
cat $2/control_electron_barrel/*py     > $2/uncer_control_electron_barrel.py
cat $2/control_electron_endcap/*py     > $2/uncer_control_electron_endcap.py

#cat $2/signal_muon_all/*py     > $2/uncer_aqgc_muon_all.py
#cat $2/signal_electron_all/*py > $2/uncer_aqgc_electron_all.py
#pdf_scale_uncer.py 2018 $1 $2 muon signal barrel 1
#pdf_scale_uncer.py 2018 $1 $2 muon signal endcap 1
#pdf_scale_uncer.py 2018 $1 $2 electron signal barrel 1
#pdf_scale_uncer.py 2018 $1 $2 electron signal endcap 1
#pdf_scale_uncer.py 2018 $1 $2 muon control barrel 1
#pdf_scale_uncer.py 2018 $1 $2 muon control endcap 1
#pdf_scale_uncer.py 2018 $1 $2 electron control barrel 1
#pdf_scale_uncer.py 2018 $1 $2 electron control endcap 1
