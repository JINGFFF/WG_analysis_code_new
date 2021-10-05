#2_calculate_uncertainty.py $1 $2 $4 $3 signal muon barrel medium mjj unfolding off
2_calculate_uncertainty.py $1 $2 $4 $3 signal all barrel medium mjj unfolding off
#2_calculate_uncertainty.py $1 $2 $4 $3 signal muon endcap medium mjj unfolding off
2_calculate_uncertainty.py $1 $2 $4 $3 signal all endcap medium mjj unfolding off
#2_calculate_uncertainty.py $1 $2 $4 $3 control muon barrel medium mjj unfolding off
2_calculate_uncertainty.py $1 $2 $4 $3 control all barrel medium mjj unfolding off
#2_calculate_uncertainty.py $1 $2 $4 $3 control muon endcap medium mjj unfolding off
2_calculate_uncertainty.py $1 $2 $4 $3 control all endcap medium mjj unfolding off

#cat $2/signal_muon_barrel/*py     > $2/uncer_signal_muon_barrel.py
#cat $2/signal_muon_endcap/*py     > $2/uncer_signal_muon_endcap.py
cat $2/signal_all_barrel/*py     > $2/uncer_signal_all_barrel.py
cat $2/signal_all_endcap/*py     > $2/uncer_signal_all_endcap.py
#cat $2/control_muon_barrel/*py     > $2/uncer_control_muon_barrel.py
#cat $2/control_muon_endcap/*py     > $2/uncer_control_muon_endcap.py
cat $2/control_all_barrel/*py     > $2/uncer_control_all_barrel.py
cat $2/control_all_endcap/*py     > $2/uncer_control_all_endcap.py

#pdf_scale_uncer.py $4 $1 $2 muon signal barrel 1
#pdf_scale_uncer.py $4 $1 $2 muon signal endcap 1
pdf_scale_uncer.py $4 $1 $2 all signal barrel 1
pdf_scale_uncer.py $4 $1 $2 all signal endcap 1
#pdf_scale_uncer.py $4 $1 $2 muon control barrel 1
#pdf_scale_uncer.py $4 $1 $2 muon control endcap 1
pdf_scale_uncer.py $4 $1 $2 all control barrel 1
pdf_scale_uncer.py $4 $1 $2 all control endcap 1

#pdf_scale_uncer.py $4 $1 $2 muon signal barrel 1
#pdf_scale_uncer.py $4 $1 $2 muon signal endcap 1
pdf_scale_uncer.py $4 $1 $2 all signal barrel 0
pdf_scale_uncer.py $4 $1 $2 all signal endcap 0
#pdf_scale_uncer.py $4 $1 $2 muon control barrel 1
#pdf_scale_uncer.py $4 $1 $2 muon control endcap 1
pdf_scale_uncer.py $4 $1 $2 all control barrel 0
pdf_scale_uncer.py $4 $1 $2 all control endcap 0
