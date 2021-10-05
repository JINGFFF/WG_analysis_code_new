#!/usr/bin/python

import sys
import time
import os  
year = sys.argv[1] 
card = sys.argv[2]


outCSVfile = open("out_breakdown.csv", 'w')
uncer_group = ['Lumi']
#uncer_group = ['Lumi', 'L1pre', 'MC_Stat', 'Non-prompt_Stat', 'Nonprompt_method', 'photon', 'electron', 'muon', 'JECR', 'Pileup', 'Theory', 'Btag']
#if year == '2018' : 
#    uncer_group = ['Lumi', 'MC_Stat', 'Non-prompt_Stat', 'Nonprompt_method', 'photon', 'electron', 'muon', 'JECR', 'Pileup', 'Theory', 'Btag']
#    uncer_group = ['Lumi', 'Stat', 'photon', 'electron', 'muon', 'JECR', 'Pileup', 'Nonprompt', 'Theory']
#outCSVfile.write('Uncertainty name, Uncertaintry central [%], Uncertainty up [%], Uncertainty down [%] \n')
#os.system("mkdir -p " + outdir);
os.system("combineCards.py " + card + " -S > shape_" + card)
os.system("combine -M FitDiagnostics -t -1 --expectSignal 1 shape_" + card + ' > result_' + card)
os.system("combine -M FitDiagnostics -t -1 --expectSignal 1 --freezeParameters all shape_" + card + ' > result_freezeAll_' + card)
#uncer_group = ['Lumi', 'L1pre', 'Stat', 'photon', 'electron', 'muon', 'JECR', 'Pileup', 'Nonprompt', 'Theory']
#if year == '2018' : 
#    uncer_group = ['Lumi', 'Stat', 'photon', 'electron', 'muon', 'JECR', 'Pileup', 'Nonprompt', 'Theory']
for i in range(len(uncer_group)):
    os.system("combine -M FitDiagnostics --freezeNuisanceGroups " + uncer_group[i]+ " -t -1 --expectSignal 1 shape_" + card + " > result_"+ uncer_group[i] + "_"+ card)
def read(file_uncer):
    f = open(file_uncer, "r")
    lines = f.readlines()
    for i in range(0, len(lines)):
        if 'Best fit' in lines[i]:
            tl = lines[i].split('/+')
            print (tl)
            down = tl[0].split('-')[-1]
            up   = tl[1].split(' ')[0] 
            print(down,up)
    tmp_down, tmp_up = round(float(down), 6), round(float(up), 6 )
    print(tmp_down, tmp_up)
    return tmp_down, tmp_up
uncer_down, uncer_up = read('result_datacard.txt')
outCSVfile.write('Best Fit: , ' + '-' + str(round(uncer_down, 3))+ ', +' + str(round(uncer_up, 3)) + '\n')
outCSVfile.write('Uncertainty name, Uncertaintry central [%], Uncertainty up [%], Uncertainty down [%] \n')

uncer_group.append('freezeAll')
for i in range(len(uncer_group)):
    tmp_uncer_down, tmp_uncer_up = read('result_'+ uncer_group[i] + '_datacard.txt')
    sys      = abs(((uncer_down/2 + uncer_up/2)**2 - (tmp_uncer_down/2 + tmp_uncer_up/2)**2))**0.5
    sys_up   = abs((uncer_up**2 - tmp_uncer_up**2))**0.5
    sys_down = abs((uncer_down**2 - tmp_uncer_down**2))**0.5
    print(uncer_group[i], sys_up, sys_down, sys)
    outCSVfile.write(uncer_group[i] + ', ' + str(round(sys*100, 3)) + ', ' + str(round(sys_up*100,3)) + ', ' + str(round(sys_down*100,3)) + '\n' )

