//#include "test.h"
vector<vector<double>> bins;
vector<double> Bins={150,400,600,800, 1000, 1500};

TString var = "";

TString hist_name[18] = {"nVtx", "ptlep1", "etalep1", "mtVlepJECnew", "ptVlepJEC", "photonet", "photoneta", "photonsceta", "jet1pt", "jet1eta", "jet2pt", "jet2eta", "Mjj", "zepp", "deltaeta", "MET_et", "Dphiwajj", "Mla"};
const int length = sizeof(hist_name)/sizeof(hist_name[0]);

TString uncertainty_jecr[4] = { "JEC_up", "JEC_down", "JER_up", "JER_down"};
TH1D * h[length];
TH1D * h_jecr[4];

TH1D * h_in[length];
TH1D * h_in_jecr[4];
TH1D * h_out[length];
TH1D * h_out_jecr[4];

TH1D * h_pdf[400];
char th2name[400];

void fill_hist(TString region,double fill_Mjj, double fill_deltaeta, TH1D* hist, double weight){
      if(region == "signal"){
         if(fill_Mjj>500   &&fill_Mjj<600   &&fill_deltaeta>=30  &&fill_deltaeta<80)  hist->Fill(0.5,weight);//0~1, 2.5~4.5 and 500~800
         if(fill_Mjj>=600  &&fill_Mjj<700   &&fill_deltaeta>=30  &&fill_deltaeta<80)  hist->Fill(1.5,weight);//1~2 2.5~4.5 and 800~1200
         if(fill_Mjj>=700  &&fill_Mjj<1000  &&fill_deltaeta>=30  &&fill_deltaeta<80)  hist->Fill(2.5,weight);//2~3 2.5~4.5 1200~2000
         if(fill_Mjj>=1000                  &&fill_deltaeta>=30  &&fill_deltaeta<80)  hist->Fill(3.5,weight);//5~6 6~infi 500~800

         if(fill_Mjj>=500  &&fill_Mjj<600   &&fill_deltaeta>=80  &&fill_deltaeta<130) hist->Fill(4.5,weight);//3~4 4.5~6 500~800 
         if(fill_Mjj>=600  &&fill_Mjj<700   &&fill_deltaeta>=80  &&fill_deltaeta<130) hist->Fill(5.5,weight);//4~5 4.5~6 800~1200
         if(fill_Mjj>=700  &&fill_Mjj<1000  &&fill_deltaeta>=80  &&fill_deltaeta<130) hist->Fill(6.5,weight);//4~5 4.5~6 800~1200
         if(fill_Mjj>=1000                  &&fill_deltaeta>=80  &&fill_deltaeta<130) hist->Fill(7.5,weight);//5~6 6~infi 500~800

         if(fill_Mjj>=500  &&fill_Mjj<600   &&fill_deltaeta>=130)                     hist->Fill(8.5,weight);//6~7 6~infi 800~1200
         if(fill_Mjj>=600  &&fill_Mjj<700   &&fill_deltaeta>=130)                     hist->Fill(9.5,weight);//7~8 6~infi800~1200
         if(fill_Mjj>=700  &&fill_Mjj<1000  &&fill_deltaeta>=130)                     hist->Fill(10.5,weight);//7~8 6~infi800~1200
         if(fill_Mjj>=1000                  &&fill_deltaeta>=130)                     hist->Fill(11.5,weight);//8~9 6~infi 800~1200

      }
      if(region == "control"){
         if(fill_Mjj>200&&fill_Mjj<300)hist->Fill(0.5,weight);//0~1, 2.5~4.5 and 500~800
         if(fill_Mjj>=300&&fill_Mjj<400)hist->Fill(1.5,weight);//1~2 2.5~4.5 and 800~1200
         if(fill_Mjj>=400&&fill_Mjj<500)hist->Fill(2.5,weight);//3~4 4.5~6 500~800 

      }
}


void creat_hist(TString region){
   bins.push_back(Bins);
   int i = 0;
   const int BINS_size = bins[i].size();
   double BINS[BINS_size];

   int bin_num = BINS_size - 1;
   for(int xx = 0; xx < BINS_size; xx++) {

      BINS[xx] = bins[i][xx];
   }

   h[0] = new TH1D("nVtx", "nVtx", 25, 0, 50);
   h[1] = new TH1D("ptlep1", "ptlep1", 25, 0.0, 200.0);
   h[2] = new TH1D("etalep1", "etalep1", 25, -2.4, 2.4);
   h[3] = new TH1D("mtVlepJECnew", "mtVlepJECnew", 25, 30.0, 150.0);
   h[4] = new TH1D("ptVlepJEC", "ptVlepJEC", 25, 0.0, 200.0);
   h[5] = new TH1D("photonet", "photonet", 25, 30.0, 200.0);
   h[6] = new TH1D("photoneta", "photoneta", 25, -2.5, 2.5);
   h[7] = new TH1D("photonsceta", "photonsceta", 25, -2.5, 2.5);
   h[8] = new TH1D("jet1pt", "jet1pt", 25, 40.0, 300.0);
   h[9] = new TH1D("jet1eta", "jet1eta", 25, -5.0, 5.0);
   h[10] = new TH1D("jet2pt", "jet2pt", 25, 30.0, 200.0);
   h[11] = new TH1D("jet2eta", "jet2eta", 25, -5.0, 5.0);
   //h[12] = new TH1D("Mjj", "Mjj", 25, 200., 500.);
   h[13] = new TH1D("zepp", "zepp", 25, 0.0, 5.0);
   h[14] = new TH1D("deltaeta", "deltaeta", 25, 0.5, 5.0);
   h[15] = new TH1D("MET_et", "MET_et", 25, 50.0, 200.0);
   h[16] = new TH1D("Dphiwajj", "Dphiwajj", 25, 0.0, 3.2);
   h[17] = new TH1D("Mla", "Mla", 25, 0.0, 200);

   if(region == "signal") {
      h[12] = new TH1D("Mjj", "Mjj", 25, 500., 1200.);

   }


   if(region == "control") {
      h[12] = new TH1D("Mjj", "Mjj", 25, 200., 500.);
   }

}

void hist_Sumw2()
{
/*cout<<"ok"<<endl;

      for(int j = 0; j<19; j++){
h[j]->Print();
cout<<"ok1"<<endl;
   
         h[j]->Sumw2();
cout<<"ok2"<<endl;

      }
cout<<"ok"<<endl;
      for(int j2 = 0; j2<4; j2++){
         h_jecr[j2]->Sumw2();
      }

      for(int k2 = 0; k2<400; k2++){
         h_pdf[k2]->Sumw2();
      }


*/

}

void savefile(TFile* fout, TString m_dataset) {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();

   for(int j = 0; j<length; j++){
      h[j]->Write();
   }  

   fout->Close();
   delete fout;
}

void hist_Scale(TString m_type, double p_event, double n_event)
{
cout<<p_event<<" "<<n_event<<endl;
   if(m_type == "mc"){
         for(int j = 0; j<length; j++){
            h[j]->Scale(1/(p_event - n_event));

         }


   }

}


