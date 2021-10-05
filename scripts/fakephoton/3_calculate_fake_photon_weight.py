#!/usr/bin/env python
import sys
import os
import re
#from uncertainty_unfold import *
import ROOT
from ROOT import gROOT, THStack, TH1D, TList, TFile, TH2D
from math import fabs, sqrt

data_pt_distribution = sys.argv[1]
fake_pt_distribution = sys.argv[2]
fake_fraction        = sys.argv[3]
sideband_uncer       = sys.argv[4]
closuretest_uncer    = sys.argv[5]
outputdir            = sys.argv[6]
os.system("mkdir -p " + outputdir)

f_in_data   = TFile.Open(data_pt_distribution)
f_in_fake   = TFile.Open(fake_pt_distribution)

f_in_1   = TFile.Open(fake_fraction)
f_in_2   = TFile.Open(sideband_uncer)
f_in_3   = TFile.Open(closuretest_uncer)

# photon pt distribution
data_barrel = f_in_data.Get("barrel_photonpt")
data_endcap = f_in_data.Get("endcap_photonpt")
fake_barrel = f_in_fake.Get("barrel_photonpt")
fake_endcap = f_in_fake.Get("endcap_photonpt")
data_barrel.Print("all")
fake_barrel.Print("all")


# fake photon fraction
hist_fraction_barrel = f_in_1.Get("barrel_fraction")
hist_fraction_endcap = f_in_1.Get("endcap_fraction")

# uncertainties : sys, closuretest, sideband
hist_fraction_barrel_err = f_in_1.Get("barrel_fraction_error")
hist_fraction_endcap_err = f_in_1.Get("endcap_fraction_error")

hist_sideband_barrel_uncer = f_in_2.Get("hist_barrel_uncer")
hist_sideband_endcap_uncer = f_in_2.Get("hist_endcap_uncer")

hist_closuretest_barrel_uncer = f_in_3.Get("hist_barrel_uncer")
hist_closuretest_endcap_uncer = f_in_3.Get("hist_endcap_uncer")


uncer_barrel = []
uncer_barrel_sys = []
uncer_barrel_closuretest = []
uncer_barrel_sideband = []

uncer_endcap = []
uncer_endcap_sys = []
uncer_endcap_closuretest = []
uncer_endcap_sideband = []

barrel_fake_photon_weight = data_barrel.Clone()
barrel_fake_photon_weight.SetName("barrel_fake_photon_weight")
barrel_fake_photon_weight.SetTitle("barrel_fake_photon_weight")

endcap_fake_photon_weight = data_endcap.Clone()
endcap_fake_photon_weight.SetName("endcap_fake_photon_weight")
endcap_fake_photon_weight.SetTitle("endcap_fake_photon_weight")

# up
barrel_fake_photon_weight_up = data_barrel.Clone()
barrel_fake_photon_weight_up.SetName("barrel_fake_photon_weight_up")
barrel_fake_photon_weight_up.SetTitle("barrel_fake_photon_weight_up")

endcap_fake_photon_weight_up = data_endcap.Clone()
endcap_fake_photon_weight_up.SetName("endcap_fake_photon_weight_up")
endcap_fake_photon_weight_up.SetTitle("endcap_fake_photon_weight_up")

# down
barrel_fake_photon_weight_down = data_barrel.Clone()
barrel_fake_photon_weight_down.SetName("barrel_fake_photon_weight_down")
barrel_fake_photon_weight_down.SetTitle("barrel_fake_photon_weight_down")

endcap_fake_photon_weight_down = data_endcap.Clone()
endcap_fake_photon_weight_down.SetName("endcap_fake_photon_weight_down")
endcap_fake_photon_weight_down.SetTitle("endcap_fake_photon_weight_down")

for i in range(barrel_fake_photon_weight.GetNbinsX()) :
    tmp_uncer_barrel_sys         = hist_fraction_barrel_err.GetBinContent(i+1)/hist_fraction_barrel.GetBinContent(i+1)
    tmp_uncer_barrel_closuretest = hist_closuretest_barrel_uncer.GetBinContent(i+1)
    tmp_uncer_barrel_sideband    = hist_sideband_barrel_uncer.GetBinContent(i+1)

    tmp_uncer_endcap_sys         = hist_fraction_endcap_err.GetBinContent(i+1)/hist_fraction_endcap.GetBinContent(i+1)
    tmp_uncer_endcap_closuretest = hist_closuretest_endcap_uncer.GetBinContent(i+1)
    tmp_uncer_endcap_sideband    = hist_sideband_endcap_uncer.GetBinContent(i+1)

    # total uncer
    tmp_uncer_barrel = ( (tmp_uncer_barrel_sys)**2 + (tmp_uncer_barrel_closuretest)**2 + (tmp_uncer_barrel_sideband)**2 )**0.5
    tmp_uncer_endcap = ( (tmp_uncer_endcap_sys)**2 + (tmp_uncer_endcap_closuretest)**2 + (tmp_uncer_endcap_sideband)**2 )**0.5

    uncer_barrel.append(tmp_uncer_barrel)
    uncer_barrel_sys.append(tmp_uncer_barrel_sys)
    uncer_barrel_closuretest.append(tmp_uncer_barrel_closuretest)
    uncer_barrel_sideband.append(tmp_uncer_barrel_sideband)

    uncer_endcap.append(tmp_uncer_endcap)
    uncer_endcap_sys.append(tmp_uncer_endcap_sys)
    uncer_endcap_closuretest.append(tmp_uncer_endcap_closuretest)
    uncer_endcap_sideband.append(tmp_uncer_endcap_sideband)

    # weight
    barrel_fake_photon_weight.SetBinContent(i+1, data_barrel.GetBinContent(i+1) * hist_fraction_barrel.GetBinContent(i+1) / fake_barrel.GetBinContent(i+1) )
    endcap_fake_photon_weight.SetBinContent(i+1, data_endcap.GetBinContent(i+1) * hist_fraction_endcap.GetBinContent(i+1) / fake_endcap.GetBinContent(i+1) )
    # weight up
    barrel_fake_photon_weight_up.SetBinContent(i+1, (1 + tmp_uncer_barrel) * data_barrel.GetBinContent(i+1) * \
                              hist_fraction_barrel.GetBinContent(i+1) / fake_barrel.GetBinContent(i+1) )
    endcap_fake_photon_weight_up.SetBinContent(i+1, (1 + tmp_uncer_barrel) * data_endcap.GetBinContent(i+1) * \
                              hist_fraction_endcap.GetBinContent(i+1) / fake_endcap.GetBinContent(i+1) )

    # weight down
    barrel_fake_photon_weight_down.SetBinContent(i+1, (1 - tmp_uncer_barrel) * data_barrel.GetBinContent(i+1) * \
                              hist_fraction_barrel.GetBinContent(i+1) / fake_barrel.GetBinContent(i+1) )
    endcap_fake_photon_weight_down.SetBinContent(i+1, (1 - tmp_uncer_barrel) * data_endcap.GetBinContent(i+1) * \
                              hist_fraction_endcap.GetBinContent(i+1) / fake_endcap.GetBinContent(i+1) )

barrel_fake_photon_weight.SetBinContent(0,0)
barrel_fake_photon_weight_up.SetBinContent(0,0)
barrel_fake_photon_weight_down.SetBinContent(0,0)
endcap_fake_photon_weight.SetBinContent(0,0)
endcap_fake_photon_weight_up.SetBinContent(0,0)
endcap_fake_photon_weight_down.SetBinContent(0,0)
# print uncertainties info
# barrel
# closuretest uncertainty
print 'barrel'
print 'uncertainty for closuretest ',
for i in range(len(uncer_barrel)):
    print ' & $\\pm' + str(format(float(uncer_barrel_closuretest[i])*100, '.2f')) +  '\%' , 
print '\\\\'

print 'uncertainty for chiso selection ',
for i in range(len(uncer_barrel)):
    print ' & $\\pm' + str(format(float(uncer_barrel_sideband[i])*100, '.2f')) +  '\%' ,
print '\\\\'

print 'uncertainty for template method ',
for i in range(len(uncer_barrel)):
    print ' & $\\pm' + str(format(float(uncer_barrel_sys[i])*100, '.2f')) +  '\%' ,
print '\\\\'

print 'total uncertainty ',
for i in range(len(uncer_barrel)):
    print ' & $\\pm' + str(format(float(uncer_barrel[i])*100, '.2f')) +  '\%' ,
print '\\\\'

print 'endcap'
print 'uncertainty for closuretest ',
for i in range(len(uncer_endcap)):
    print ' & $\\pm' + str(format(float(uncer_endcap_closuretest[i])*100, '.2f')) +  '\%' , 
print '\\\\'

print 'uncertainty for chiso selection ',
for i in range(len(uncer_endcap)):
    print ' & $\\pm' + str(format(float(uncer_endcap_sideband[i])*100, '.2f')) +  '\%' ,
print '\\\\'

print 'uncertainty for template method ',
for i in range(len(uncer_endcap)):
    print ' & $\\pm' + str(format(float(uncer_endcap_sys[i])*100, '.2f')) +  '\%' ,
print '\\\\'

print 'total uncertainty ',
for i in range(len(uncer_endcap)):
    print ' & $\\pm' + str(format(float(uncer_endcap[i])*100, '.2f')) +  '\%' ,
print '\\\\'

fout = TFile( outputdir + '/fake_photon_weight.root', 'RECREATE' )
fout.cd()
barrel_fake_photon_weight.Write()
endcap_fake_photon_weight.Write()
barrel_fake_photon_weight_up.Write()
endcap_fake_photon_weight_up.Write()
barrel_fake_photon_weight_down.Write()
endcap_fake_photon_weight_down.Write()

fout.Close()
f_in_data.Close()
f_in_fake.Close()
f_in_1.Close()
f_in_2.Close()
f_in_3.Close()
print(uncer_barrel)
print(uncer_endcap)
