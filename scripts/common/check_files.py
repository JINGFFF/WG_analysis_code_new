#!/usr/bin/env python

import os, sys

indir    = sys.argv[2]
year     = sys.argv[1]
study    = sys.argv[3]
run_file = sys.argv[4]

data_type        = ['mc', 'data']
channel          = ['muon', 'electron']
region           = ['control', 'signal']
barrel_or_endcap = ['barrel', 'endcap']
if study == 'aqgc':
    region = ['aqgc']
    barrel_or_endcap = ['all']
data_sample      = ['data', 'fakephoton', 'doublefake', 'fakelepton']
mc_sample        = ['WGJJ', 'WGJets', 'WGJJ_interference', 'ST_s', 'ST_t', 'ST_tbar', 'ST_tW', 'ST_tbarW', 'TTG', 'ZG', 'WW', 'WZ', 'ZZ']

r_file = open(run_file, "r")
lines = r_file.readlines()
#for i in range(0, len(lines)):

n = 0

for i in range(len(data_type)):
    tmp_data_type = data_type[i]
    tmp_sample = None
    if tmp_data_type == 'data':
        tmp_sample = data_sample
    elif tmp_data_type == 'mc':
        tmp_sample = mc_sample
    for j in range(len(channel)):
        tmp_channel = channel[j]
        for k in range(len(region)):
            tmp_region = region[k]
            for x in range(len(barrel_or_endcap)):
                tmp_barrel_or_endcap = barrel_or_endcap[x]
                for s in range(len(tmp_sample)):
                    n = n + 1
                    #print(n)
                    file_name = year+'_'+tmp_channel+'_'+tmp_data_type+'_'+tmp_region+'_'+tmp_barrel_or_endcap+'_'+tmp_sample[s]+'.root'
                    tmp = os.path.exists(indir+'/'+file_name)
                    if tmp == False:
                        print("file" +str(n)+" '" + file_name + "' does not exists")
                        for z in range(0, len(lines)):
                            if (tmp_data_type in lines[z]) and (tmp_sample[s] in lines[z]) and (tmp_channel in lines[z]) and (tmp_region in lines[z]) and (tmp_barrel_or_endcap in lines[z]):
                                com = lines[z].replace('$1', indir)
                                print(com)
