#！/bin/bash
cd $1
rm $2_qcd_ewk.root
rm $2_WGJJ.root
hadd_unfold.sh $2
#cd -
