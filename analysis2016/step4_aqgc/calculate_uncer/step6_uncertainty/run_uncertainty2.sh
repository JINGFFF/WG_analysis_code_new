2_calculate_uncertainty.py $1 $2 2018 $3 aqgc muon all medium mjj
2_calculate_uncertainty.py $1 $2 2018 $3 aqgc electron all medium mjj
cat $2/aqgc_muon_all/*py     > $2/uncer_aqgc_muon_all.py
cat $2/aqgc_electron_all/*py > $2/uncer_aqgc_electron_all.py
pdf_scale_uncer.py 2018 $1 $2 muon aqgc all 1
pdf_scale_uncer.py 2018 $1 $2 electron aqgc all 1
