#!/usr/bin/python
import sys
import os
import re

#print(os.system("ls >>de"))

n=0
#year = '2018'
#condor_file_dir = "condorfile"
dir1 = os.getcwd()
print dir1
#dir1 = '/data/pku/home/pengj/testvbs/workdir/ana2018/step7_significance/calculate_uncer/step6_uncertainty'
name = sys.argv[1]
inputname = sys.argv[2]
outputname = sys.argv[3]
condor_out_dir = sys.argv[4]

infile =open(inputname, 'r')
lines = infile.readlines()
os.system("mkdir -p " + condor_out_dir)
#out_file_name = year + '_'
#outfile = pen(out_file_name, 'w')
#for i in range(0, 2):
#for i in range(0,20000):
for i in range(0, len(lines)):
    x = lines[i].split('\n')
    if "#" in x[0] :
        continue
    out_file_name = condor_out_dir + '/' +name +"_"+str(i) + '_condor.sh'
    outfile = open(out_file_name, 'w')

    outfile.write('source /cvmfs/cms.cern.ch/cmsset_default.sh' + '\n')
    outfile.write('cmsrel CMSSW_9_3_4'+'\n')
    outfile.write('cd CMSSW_9_3_4/src'+'\n')
    outfile.write('cmsenv'+'\n')
    outfile.write('cd ../..'+'\n')
    outfile.write('cp -r ' + dir1 + '/scalef .'+'\n')
    #outfile.write('cp -r ' + dir1 + '/make_hist_control .'+'\n')
    outfile.write('cp -r ' + dir1 + '/make_hist* .'+'\n')
    outfile.write('cp -r ' + dir1 + '/filelist_dir* .'+'\n')
    outfile.write(x[0]+'\n')
    outfile.write('cp -r $1 ' + dir1 + '/'+condor_out_dir+'\n')

    print(n)
    n = n+1
    #print(len(lines))

    outfile.close()

    out_file_name2 = condor_out_dir + '/' +name+"_"+str(i) + '_condor.sub'
    outfile2 = open(out_file_name2, 'w')
    outfile2.write('+AcctGroup = "pku"'+'\n')
    outfile2.write('+AcctGroupUser  = "pengj"'+'\n')
    outfile2.write('executable   = ' + dir1 +'/' + out_file_name +'\n')
    outfile2.write('arguments    = ' + outputname + '\n')
    outfile2.write('output       = ' + dir1 + '/'+condor_out_dir+'/' + name+'_outputfile'+ str(i)+'\n')
    outfile2.write('error        = ' + dir1 + '/'+condor_out_dir+'/' + name+'_errorfile' + str(i) +'\n')
    outfile2.write('log          = ' + dir1 + '/'+condor_out_dir+'/' + name+'_myexe' + str(i) + '.log'+'\n')
    outfile2.write('request_cpus   = 1'+'\n')
    outfile2.write('request_memory = 1024'+'\n')
    outfile2.write('request_disk   = 1024'+'\n')
    outfile2.write('should_transfer_files = yes'+'\n')
    outfile2.write('queue'+'\n')
    outfile2.close()
    os.system("chmod 777 " + out_file_name)
    os.system("condor_submit " + out_file_name2)
    #os.system("condor_submit " + out_file_name2)
    #os.system("mkdir -p " + condor_file_dir)
    #os.system("mv " + "outputfile_"+ str(i) + " " + condor_file_dir)
    #os.system("mv " + "errorfile_"+ str(i) + " " + condor_file_dir)
    #os.system("mv " + "myexe_"+ str(i) + ".log " + condor_file_dir)
    #os.system("mv " + out_file_name + " " + condor_file_dir)
    #os.system("mv " + out_file_name2 + " " + condor_file_dir)


infile.close()
