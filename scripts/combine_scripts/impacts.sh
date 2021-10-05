text2workspace.py $1 -m 125
combineTool.py -M Impacts --expectSignal=1 -t -1 -d datacard.root -m 125 --doInitialFit
combineTool.py -M Impacts --expectSignal=1 -t -1 -d datacard.root -m 125 --doFits --parallel 4
combineTool.py -M Impacts --expectSignal=1 -t -1 -d datacard.root -m 125 -o impacts.json
plotImpacts.py -i impacts.json -o impacts
