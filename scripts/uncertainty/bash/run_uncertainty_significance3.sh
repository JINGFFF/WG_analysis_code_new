3_calculate_uncertainty.py $1 $2 $4 $3 signal muon barrel medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 signal muon endcap medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 control muon barrel medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 control muon endcap medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 signal electron barrel medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 signal electron endcap medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 control electron barrel medium mjj significance $5
3_calculate_uncertainty.py $1 $2 $4 $3 control electron endcap medium mjj significance $5

#cat $2/signal_all_barrel/*py     > $2/uncer_signal_all_barrel.py
#cat $2/signal_all_endcap/*py     > $2/uncer_signal_all_endcap.py
#cat $2/control_all_barrel/*py     > $2/uncer_control_all_barrel.py
#cat $2/control_all_endcap/*py     > $2/uncer_control_all_endcap.py

#pdf_scale_uncer.py $4 $1 $2 all signal barrel 1
#pdf_scale_uncer.py $4 $1 $2 all signal endcap 1
#pdf_scale_uncer.py $4 $1 $2 all control barrel 1
#pdf_scale_uncer.py $4 $1 $2 all control endcap 1
