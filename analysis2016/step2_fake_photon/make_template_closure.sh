#./make_hist2 filelist_dir2/tight_for_fakephoton_for_fakephoton_WGJets.txt $1 2016 mc all true WGJets medium 4 10
./make_hist filelist_dir/tight_for_fakephoton_WGJets.txt $1 2016 mc all true WGJets medium 4 10
./make_hist filelist_dir/tight_for_fakephoton_WJets.txt $1 2016 mc all fake WJets medium 4 10
#./make_hist filelist_dir/tight_for_fakephoton_WJets_1j.txt $1 2018 mc all fake W1Jets medium 4 10
#./make_hist filelist_dir/tight_for_fakephoton_WJets_2j.txt $1 2018 mc all fake W2Jets medium 4 10
./make_hist filelist_dir/tight_for_fakephoton_WJets.txt $1 2016 mc all real_fake WJets medium 4 10
#./make_hist filelist_dir/tight_for_fakephoton_WJets_1j.txt $1 2018 mc all real_fake W1Jets medium 4 10
#./make_hist filelist_dir/tight_for_fakephoton_WJets_2j.txt $1 2018 mc all real_fake W2Jets medium 4 10
