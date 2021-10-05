#！/bin/bash
cd $1
rm *qcd*.root
rm *other*.root
rm *all*.root
hadd_file.sh $2
#cd -
