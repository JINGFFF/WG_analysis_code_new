from ROOT import *
from array import array
import sys
import time
from ROOT import TGraph
from ROOT import TLatex

#gStyle.SetFillStyle(0)
#gStyle.SetLegendBorderSize(0);
gROOT.ForceStyle()

deltaNLL_95=ROOT.Math.chisquared_quantile_c(1-0.95,1)

npts=1000

if (len(sys.argv) != 9 and len(sys.argv) != 8):
    print "format: python2.6 draw_1d_limit_plot.py output_file_name x_axis_label limit_label input_file_name label [input_file_name_2] [label_2]"
    print "exiting"
    sys.exit(0)

year = sys.argv[1]

#chann = sys.argv[2]
outdir = sys.argv[2]
operator=sys.argv[3]
x_axis_label = sys.argv[4]
limit_label=sys.argv[5]
f=TFile(sys.argv[6],"r")
label=sys.argv[7]

limit=f.Get("limit")
print year
print outdir
#print chann
deltaNLL=array("f",[0])
param=array("f",[0])
iToy=array("i",[0])

limit.SetBranchAddress("deltaNLL", deltaNLL)
limit.SetBranchAddress("param",param)
limit.SetBranchAddress("iToy",iToy)

graph=TGraph()


min_parval=None
max_parval=None
print "ok1"
first_time= True
y_max=0.0

for j in range(1,limit.GetEntries()-1):
    limit.GetEntry(j)
    if j==1:
	y_max = 2*deltaNLL[0]
    #the first param value is at the location of the minimum, so it is not on the grid, this can cause the fit to mess up
    print first_time
    #print min_parval
    print param[0]

    if first_time:
        first_time=False
        continue
    #print min_parval 
    if min_parval==None:
        min_parval = param[0]
    if max_parval==None:
        max_parval = param[0]
        
    if param[0] < min_parval:
        min_parval = param[0]
    if param[0] > max_parval:
        max_parval = param[0]
    graph.SetPoint(j-1,param[0],2*deltaNLL[0])
print "ok2"
print  min_parval
print sys.argv[1]
print y_max
if 'fT8' in sys.argv[1]:graph.SetMaximum(14)
if 'fT8' in sys.argv[1]:graph.SetMinimum(0)

print "ok3"

if (len(sys.argv) == 8):
    f_2=TFile(sys.argv[6],"r")

    limit_2=f_2.Get("limit")

    deltaNLL_2=array("f",[0])
    param_2=array("f",[0])
    iToy_2=array("i",[0])

    label_2=sys.argv[7]
    
    limit_2.SetBranchAddress("deltaNLL", deltaNLL_2)
    limit_2.SetBranchAddress("param",param_2)
    limit_2.SetBranchAddress("iToy",iToy_2)


    min_parval_2=None
    max_parval_2=None

    first_time_2=True

    graph_2=TGraph()

    for j in range(1,limit_2.GetEntries()-1):
        limit_2.GetEntry(j)

        #the first param value is at the location of the minimum, so it is not on the grid, this can cause the fit to mess up
        if first_time_2:
            first_time_2=False
            continue
    
        if min_parval_2==None:
            min_parval_2 = param_2[0]
        if max_parval_2==None:
            max_parval_2 = param_2[0]
        
        if param_2[0] < min_parval_2:
            min_parval_2 = param_2[0]
        if param_2[0] > max_parval_2:
            max_parval_2 = param_2[0]
        graph_2.SetPoint(j-1,param_2[0],2*deltaNLL_2[0])

print "ok4"
for i in range(0,npts):
    print min_parval
    #max_parval =1
    #npts =1
    print deltaNLL_95
    parval = min_parval + i*(max_parval-min_parval)/npts
    if deltaNLL_95 > graph.Eval(parval):
        param_95_neg=parval
        break

for i in range(0,npts):
    parval = min_parval + i*(max_parval-min_parval)/npts
    if deltaNLL_95 > graph.Eval(parval):
        param_95_pos=parval        

print "95% confidence limits of :"+operator
print "["+str(param_95_neg)+","+str(param_95_pos)+"]"
f = open(outdir + '/limit.txt','a')
f.write(operator + ", "+str(param_95_neg)+", "+str(param_95_pos)+"\n")
graph.GetXaxis().SetTitle(x_axis_label)
graph.GetXaxis().SetTitleOffset(1.05)
graph.GetXaxis().SetLabelSize(0.062)
graph.GetXaxis().SetTitleSize(0.062)
#graph.GetXaxis().SetTitle("F_{T8} / #Lambda^{4} (TeV^{-4})")
graph.GetYaxis().SetTitle("2#DeltaNLL")
graph.GetYaxis().SetTitleSize(0.065)
graph.GetYaxis().SetTitleOffset(0.8)
graph.GetYaxis().SetLabelSize(0.065)
graph.SetLineColor(kRed)
graph.SetMarkerStyle(8)
graph.SetMarkerColor(kRed)
graph.SetMarkerSize(0.7)
graph.Draw("AP")

#if (len(sys.argv) == 8):
#    graph_2.SetLineColor(kGreen+2)
#    graph_2.SetMarkerColor(kGreen+2)
#    graph_2.Draw("P")

gPad.Update()

l95_neg = TLine(param_95_neg,gPad.GetUymin(),param_95_neg,deltaNLL_95);
l95_neg.SetLineColor(kBlack)
l95_neg.SetLineWidth(3)
l95_neg.Draw();

l95_pos = TLine(param_95_pos,gPad.GetUymin(),param_95_pos,deltaNLL_95);
l95_pos.SetLineColor(kBlack)
l95_pos.SetLineWidth(3)
l95_pos.Draw();

print gPad.GetX1()
print gPad.GetX2()

horline = TLine(gPad.GetUxmin(),deltaNLL_95,gPad.GetUxmax(),deltaNLL_95);
horline.SetLineColor(kBlack)
horline.SetLineStyle(7)
horline.SetLineWidth(3)
horline.Draw();

latex = TLatex();
latex.SetNDC()
l = gPad.GetLeftMargin();
t = gPad.GetTopMargin();
r = gPad.GetRightMargin();
b = gPad.GetBottomMargin();
#CMS text
cmsText = "CMS";
cmsTextFont = 60;
cmsTextSize = 0.7;
cmsTextOffset = 0.1;

relPosX = 0.12;
relPosY = 0.035;

# extra 
#extraText = "  Preliminary";
extraText = "";
extraOverCmsTextSize = 0.76;
extraTextFont = 52


if year == '2016': 
    lumiText = "35.9  fb^{#minus1} (13 TeV)";
if year == '2017': 
    lumiText = "41.50  fb^{#minus1} (13 TeV)";
if year == '2018': 
    lumiText = "59.74  fb^{#minus1} (13 TeV)";
lumiTextSize = 0.55;
lumiTextOffset = 0.2;
relExtraDY = 1.2;


latex.SetTextAngle(0);
latex.SetTextColor(kBlack);
extraTextSize = extraOverCmsTextSize * cmsTextSize;
latex.SetTextFont(42);
latex.SetTextAlign(31);
latex.SetTextSize(lumiTextSize * t);

latex.SetTextFont(42);
latex.SetTextAlign(31);
latex.SetTextSize(lumiTextSize * t);
latex.DrawLatex(1 - r, 1 - t + lumiTextOffset * t, lumiText);

latex.SetTextFont(cmsTextFont);
latex.SetTextAlign(11);
latex.SetTextSize(cmsTextSize * t);
latex.DrawLatex(1.15*l, 1 - t + lumiTextOffset * t, cmsText);

posX_ = 0
posX_ = l + relPosX * (1 - l - r);
posY_ = 1 - t - relPosY * (1 - t - b);
posX_ = l + relPosX * (1 - l - r);
posY_ = 1 - t + lumiTextOffset * t;
alignX_ = 1;
alignY_ = 1;
align_ = 10 * alignX_ + alignY_;
latex.SetTextFont(extraTextFont);
latex.SetTextSize(extraTextSize * t);
latex.SetTextAlign(align_);
latex.DrawLatex(posX_, posY_, extraText);


leg=TLegend(0.25,0.6,0.75,0.85)
leg.SetBorderSize(0)

leg.AddEntry(graph,label,"l")
#if (len(sys.argv) == 8):
#    leg.AddEntry(graph_2,label_2,"l")
leg.AddEntry(l95_neg,limit_label,"l")
leg.SetTextSize(0.06)
leg.SetFillColor(0)

leg.Draw()

c1.SetBottomMargin(0.15)
c1.SetLeftMargin(0.12)
c1.SetRightMargin(0.12)
c1.Update()

#c1.SaveAs(output_file_name)
c1.SaveAs(outdir + '/'+ year + "_" + operator + '_observed.png')

#raw_input()

