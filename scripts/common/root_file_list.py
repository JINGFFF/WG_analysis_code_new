#!/usr/bin/env python

import os
import re
import sys

indir                = sys.argv[1]
outdir               = sys.argv[2]
outfilename          = sys.argv[3]
os.system("mkdir -p " + outdir)
outfile = open(outdir + "/" + outfilename, 'w')

result =[]
def get_all(path):
    dir_list = os.listdir(path)
    #print dir_list
    for i in dir_list:
        sub_dir = os.path.join(path, i)
        if os.path.isdir(sub_dir):
            get_all(sub_dir)
        else:
            result.append(os.path.abspath(sub_dir))
            
   #print result

get_all(indir)
#print result
for k1 in range(len(result)):
    if "root" in str(result[k1]) :
        outfile.write( str(result[k1])+'\n')
