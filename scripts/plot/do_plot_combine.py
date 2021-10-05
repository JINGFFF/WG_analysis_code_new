#!/usr/bin/env python
import sys
import os
import re
from array import array

indir2016                = sys.argv[1]
indir2017                = sys.argv[2]
indir2018                = sys.argv[3]

outdir               = sys.argv[4]
which_region         = sys.argv[5]
which_channel        = sys.argv[6]
barrel_or_endcap     = sys.argv[7]
expect_or_observe    = sys.argv[8]
#hist_name            = sys.argv[8]
#xtitle               = sys.argv[9]
name = [
['nVtx', 'nVtx'],
['ptlep1', "\'p_{T}^{lep1} [GeV]\'"],
['etalep1', "\'#eta^{lep1}\'"],
['mtVlepJECnew', "\'M(T)_{W} [GeV]\'"],
['ptVlepJEC', "\'p_{T}^{W,lep} [GeV]\'"],
['photonet', "\'p_{T}^{#gamma} [GeV]\'"],
['photoneta', "\'#eta^{#gamma}\'"],
['photoneta', "\'#eta_{super cluster}^{#gamma}\'"],
['jet1pt', "\'p_{T}^{j1} [GeV]\'"],
['jet1eta', "\'#eta^{j1}\'"],
['jet2pt', "\'p_{T}^{j2} [GeV]\'"],
['jet2eta', "\'#eta^{j2}\'"],
['Mjj', "\'M_{jj} [GeV]\'"],
['zepp', 'zepp'],
['deltaeta', "\'#Delta#eta_{jj}\'"],
['MET_et', "\'E_{T}^{miss} [GeV]\'"],
['Dphiwajj', "\'|#phi_{W#gamma}-#phi_{j1,j2}|\'"],
['Mla', "\'M_{l#gamma} [GeV]\'"],
]

#M_{l#gamma}
for i in range(len(name)):
    os.system('comparison_plot_combine.py ' + indir2016 + ' ' + indir2017 + ' ' + indir2018 + ' ' + outdir + ' ' + which_region + ' ' + which_channel + ' ' + barrel_or_endcap + ' ' + expect_or_observe + ' ' + name[i][0] + ' ' + name[i][1])
