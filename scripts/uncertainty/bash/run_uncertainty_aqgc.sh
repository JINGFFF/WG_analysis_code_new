2_calculate_uncertainty.py $1 $2 $4 $3 aqgc muon all medium mva aqgc $5
2_calculate_uncertainty.py $1 $2 $4 $3 aqgc electron all medium mva aqgc $5
cat $2/aqgc_muon_all/*py     > $2/uncer_aqgc_muon_all.py
cat $2/aqgc_electron_all/*py > $2/uncer_aqgc_electron_all.py
pdf_scale_uncer.py $4 $1 $2 muon aqgc all 1
pdf_scale_uncer.py $4 $1 $2 electron aqgc all 1
