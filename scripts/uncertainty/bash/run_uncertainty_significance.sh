2_calculate_uncertainty.py $1 $2 $4 $3 signal all barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2 $4 $3 signal all endcap medium mjj significance $5
2_calculate_uncertainty.py $1 $2 $4 $3 control all barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2 $4 $3 control all endcap medium mjj significance $5

cat $2/signal_all_barrel/*py     > $2/uncer_signal_all_barrel.py
cat $2/signal_all_endcap/*py     > $2/uncer_signal_all_endcap.py
cat $2/control_all_barrel/*py     > $2/uncer_control_all_barrel.py
cat $2/control_all_endcap/*py     > $2/uncer_control_all_endcap.py

pdf_scale_uncer.py $4 $1 $2 all signal barrel 1
pdf_scale_uncer.py $4 $1 $2 all signal endcap 1
pdf_scale_uncer.py $4 $1 $2 all control barrel 1
pdf_scale_uncer.py $4 $1 $2 all control endcap 1

2_calculate_uncertainty.py $1 $2_4channel $4 $3 signal muon barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 signal muon endcap medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 control muon barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 control muon endcap medium mjj significance $5

cat $2_4channel/signal_muon_barrel/*py     > $2_4channel/uncer_signal_muon_barrel.py
cat $2_4channel/signal_muon_endcap/*py     > $2_4channel/uncer_signal_muon_endcap.py
cat $2_4channel/control_muon_barrel/*py     > $2_4channel/uncer_control_muon_barrel.py
cat $2_4channel/control_muon_endcap/*py     > $2_4channel/uncer_control_muon_endcap.py

pdf_scale_uncer.py $4 $1 $2_4channel muon signal barrel 1
pdf_scale_uncer.py $4 $1 $2_4channel muon signal endcap 1
pdf_scale_uncer.py $4 $1 $2_4channel muon control barrel 1
pdf_scale_uncer.py $4 $1 $2_4channel muon control endcap 1

2_calculate_uncertainty.py $1 $2_4channel $4 $3 signal electron barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 signal electron endcap medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 control electron barrel medium mjj significance $5
2_calculate_uncertainty.py $1 $2_4channel $4 $3 control electron endcap medium mjj significance $5

cat $2_4channel/signal_electron_barrel/*py     > $2_4channel/uncer_signal_electron_barrel.py
cat $2_4channel/signal_electron_endcap/*py     > $2_4channel/uncer_signal_electron_endcap.py
cat $2_4channel/control_electron_barrel/*py     > $2_4channel/uncer_control_electron_barrel.py
cat $2_4channel/control_electron_endcap/*py     > $2_4channel/uncer_control_electron_endcap.py

pdf_scale_uncer.py $4 $1 $2_4channel electron signal barrel 1
pdf_scale_uncer.py $4 $1 $2_4channel electron signal endcap 1
pdf_scale_uncer.py $4 $1 $2_4channel electron control barrel 1
pdf_scale_uncer.py $4 $1 $2_4channel electron control endcap 1
