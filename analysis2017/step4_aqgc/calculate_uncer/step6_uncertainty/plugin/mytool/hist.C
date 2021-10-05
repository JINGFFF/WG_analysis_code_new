//#include "test.h"
vector<vector<double>> bins;
vector<double> Bins={150,400,600,800, 1000, 1500};

TString var = "";
TString uncertainty_hist_name[29] = {"", "pileup_up", "pileup_down", "L1_up", "L1_down", "photon_ID_up", "photon_ID_down", "electron_ID_up", "electron_ID_down", "electron_Reco_up", "electron_Reco_down", "electron_HLT_up", "electron_HLT_down", "muon_ID_up", "muon_ID_down", "muon_iso_up", "muon_iso_down", "muon_HLT_up", "muon_HLT_down", "fakephoton_up", "fakephoton_down", "btag_up", "btag_down", "pujet_up", "pujet_down", "pujet_mistag_up", "pujet_mistag_down", "fakelepton_up", "fakelepton_down"};
const int length = sizeof(uncertainty_hist_name)/sizeof(uncertainty_hist_name[0]);

TString uncertainty_jecr[4] = { "JEC_up", "JEC_down", "JER_up", "JER_down"};
TH1D * h[length];
TH1D * h_jecr[4];

TH1D * h_in[length];
TH1D * h_in_jecr[4];
TH1D * h_out[length];
TH1D * h_out_jecr[4];

TH1D * h_pdf[400];
char th2name[400];

void fill_hist(double fill_Mva, TH1D* hist, double weight){

         if(fill_Mva>150&&fill_Mva<400)hist->Fill(0.5,weight);//0~1, 2.5~4.5 and 500~800
         if(fill_Mva>=400&&fill_Mva<600)hist->Fill(1.5,weight);//1~2 2.5~4.5 and 800~1200
         if(fill_Mva>=600&&fill_Mva<800)hist->Fill(2.5,weight);//2~3 2.5~4.5 1200~2000
         if(fill_Mva>=800&&fill_Mva<1000)hist->Fill(3.5,weight);//3~4 4.5~6 500~800 
         if(fill_Mva>=1000)hist->Fill(4.5,weight);//4~5 4.5~6 800~1200


}


void creat_hist(){
   bins.push_back(Bins);
   int i = 0;
   const int BINS_size = bins[i].size();
   double BINS[BINS_size];

   int bin_num = BINS_size - 1;
   for(int xx = 0; xx < BINS_size; xx++) {

      BINS[xx] = bins[i][xx];
   }

   for(int j = 0; j<length; j++){
      h[j] = new TH1D("hist_"+uncertainty_hist_name[j],"hist_" +uncertainty_hist_name[j], 5, 0, 5);
   }

   for(int j2 = 0; j2<4; j2++){
      h_jecr[j2] = new TH1D("hist_"+uncertainty_jecr[j2],"hist_"+uncertainty_jecr[j2], 5, 0, 5);
   }


   for(int k2 = 0; k2<400; k2++){
      sprintf(th2name,"%d",k2+1);
      h_pdf[k2] = new TH1D("hist_pdf_" +var+ th2name,"hist_pdf_" +var+ th2name, 5, 0, 5);
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
         //h_in[j]->Write();
         //h_out[j]->Write();

      cout<<h[j]->GetName()<<endl;

      }
      for(int j2 = 0; j2<4; j2++){
         h_jecr[j2]->Write();
         //h_in_jecr[j2]->Write();
         //h_out_jecr[j2]->Write();

      }

      for(int k2 = 0; k2<400; k2++){
         h_pdf[k2]->Write();
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
            //h_in[j]->Scale(1/(p_event - n_event));
            //h_out[j]->Scale(1/(p_event - n_event));

         }

         for(int j2 = 0; j2<4; j2++){
            h_jecr[j2]->Scale(1/(p_event - n_event));
            //h_in_jecr[j2]->Scale(1/(p_event - n_event));
            //h_out_jecr[j2]->Scale(1/(p_event - n_event));

         }

         for(int k2 = 0; k2<400; k2++){
            h_pdf[k2]->Scale(1/(p_event - n_event));
         }


   }

}
/*
void Fill_H(bool cut1, bool cut2, bool cut3, bool cut4, bool cut5, TString m_region, 
double fill_Mjj, double fill_Mjj_JEC_up, double fill_Mjj_JEC_down, double fill_Mjj_JER_up, double fill_Mjj_JER_down,
double fill_Mla, double fill_Mla_JEC_up, double fill_Mla_JEC_down, double fill_Mla_JER_up, double fill_Mla_JER_down,
double pweight[703], double fill_weight[length], double fill_weight_jecr[4]){

   if(cut1){
      for(int k2 = 0; k2<400; k2++){
            fill_hist(m_region, fill_Mjj, fill_Mla, h_pdf[k2], fill_weight[0]*(pweight[k2]));
      }

      for(int j = 0; j<length; j++){
         fill_hist(m_region, fill_Mjj, fill_Mla, h[j], fill_weight[j]);
      }
   }

   if (cut2) {
      fill_hist(m_region, fill_Mjj_JEC_up, fill_Mla, h_jecr[0], fill_weight_jecr[0]);

   }
            
   if (cut3) {
      fill_hist(m_region, fill_Mjj_JEC_down, fill_Mla, h_jecr[1], fill_weight_jecr[1]);

   }
            
   if (cut4) {
      fill_hist(m_region, fill_Mjj_JER_up, fill_Mla, h_jecr[2], fill_weight_jecr[2]);

   }
            
   if (cut5) {
      fill_hist(m_region, fill_Mjj_JER_down, fill_Mla, h_jecr[3], fill_weight_jecr[3]);

   }

}
*/
