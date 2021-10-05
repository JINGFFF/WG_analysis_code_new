double Pi =3.1415926;
Bool_t LEPmu,LEPele,genmuon[6], genele[6], genjet[6], genphoton[6];
Bool_t photon, jet, dr, SignalRegion;
Bool_t GenLEPmu, GenLEPele, GenPhoton, GenJet, GenDr, GenSignalRegion;
Bool_t Reco, Gen, GenDrmu, GenDrele, Genmu, Genele;
int nxx = 0;
int n = 0, n1 = 0, n2 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0, s11 = 0;
double genyVlep;
double genphiVlep;
double genptVlep;
double genmassVlep;
double genWGmass;
double genmuon1pt, genmuon1phi, genmuon1eta;
double genele1pt, genele1phi, genele1eta;
double genlep1pt, genlep1eta, genlep1phi, gendrjj, drjj;
int    genlep;
double genjet1pt, genjet2pt, genjet1eta, genjet2eta, genjet1phi, genjet2phi;
double genjet1e, genjet2e;
double genphotonet, genphotoneta, genphotonphi;
double gendrj1m1, gendrj1m2, gendrj2m1, gendrj2m2;
double gendrj1e1, gendrj2e1;
double gendrj1a, gendrj2a, gendrj1l, gendrj2l;
double gendrma1, gendrma2;
double gendrea1, gendrea2;
double genMjj, gendetajj, genzepp;
double gendrla1;
double gendelta_phi, genZGmass;
double genMla, gen_Dphiwajj;
vector<double> vector_photon, vector_jet,vector_muon, vector_ele;
vector<double>::iterator biggest_photon, biggest_jet1, biggest_jet2, biggest_muon1, biggest_ele1;

int jet_index[2];
int jet1index, jet2index;
int pho1_index=0, jet1_index=0, muon1_index=0, ele1_index=0;
TLorentzVector for_gen_lep1p4;
TLorentzVector for_gen_photonp42;
TLorentzVector for_gen_vp4;

void ResetValue(){
   genMla = -10; 
   gen_Dphiwajj = -10; 
   genWGmass = -10;
   genlep1pt = -10; 
   genlep1eta = -10; 
   genlep1phi =-10;
   genjet1pt = -10;
   genjet2pt = -10;
   genjet1eta = -10;
   genjet2eta = -10;
   genjet1phi = -10;
   genjet2phi = -10;
   genjet1e = -10;
   genjet2e = -10;
   genphotonet = -10;
   genphotoneta = -10;
   genphotonphi = -10;
   gendrj1a = -10;
   gendrj2a = -10;
   gendrj1l = -10;
   gendrj2l = -10;
   gendrla1 = -10;
   genMjj = -10;
   gendetajj = -10;
   genzepp = -10;
   gendelta_phi = -10;
   genZGmass = -10;
   genmassVlep = -10;
   genyVlep = -10;
   genphiVlep = -10;
   genptVlep = -10;
   genlep = -10;
   gendrjj = -10;
   drjj = -10;
   genmuon1pt = -10;
   genmuon1eta = -10;
   genmuon1phi = -10;
   genele1pt = -10;
   genele1eta = -10;
   genele1phi = -10;
   GenDrmu = false;
   GenDrele = false;
   Genmu = false;
   Genele = false;
   for(int i=0;i<6;i++){
      genmuon[i] = false;
      genele[i] = false;
      genphoton[i] = false;
      genjet[i] = false;
   }
}

Double_t delta_R(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
        Double_t dp = phi1-phi2;
        if(fabs(dp) > Pi) dp = 2*Pi - fabs(dp);
        Double_t dr = sqrt((eta1-eta2)*(eta1-eta2)+dp*dp);
        return dr;
}

void init_gen(double genphoton_pt[6], double genphoton_eta[6], double genjet_pt[6], double genjet_eta[6], double genmuon_pt[6], double genmuon_eta[6], double genelectron_pt[6], double genelectron_eta[6]){
   for(int i=0;i<6;i++){
      genphoton[i] = genphoton_pt[i]>20 &&( (fabs(genphoton_eta[i])<1.4442) || ( fabs(genphoton_eta[i])<2.5 && fabs(genphoton_eta[i])>1.566 ) );
      genjet[i] = genjet_pt[i]>30 && fabs(genjet_eta[i])<4.7;
      genmuon[i] = genmuon_pt[i]>20 && fabs(genmuon_eta[i])<2.4;
      genele[i] = genelectron_pt[i]>25 && fabs(genelectron_eta[i])<2.5;

      if(genjet[i]) vector_jet.push_back(genjet_pt[i]);
      else vector_jet.push_back(-20);

      if(genphoton[i]) vector_photon.push_back(genphoton_pt[i]);
      else vector_photon.push_back(-20);

      if(genmuon[i]) vector_muon.push_back(genmuon_pt[i]);
      else vector_muon.push_back(-20);

      if(genele[i]) vector_ele.push_back(genelectron_pt[i]);
      else vector_ele.push_back(-20);

   }


}

void match_genlep(double genphoton_pt[6], double genphoton_eta[6], double genphoton_phi[6], double genjet_pt[6], double genjet_eta[6], double genjet_phi[6], double genmuon_pt[6], double genmuon_eta[6], double genmuon_phi[6], double genelectron_pt[6], double genelectron_eta[6], double genelectron_phi[6]){

   biggest_muon1 = max_element(begin(vector_muon), end(vector_muon));
   muon1_index = distance( begin(vector_muon), biggest_muon1);

   biggest_ele1 = max_element(begin(vector_ele), end(vector_ele));
   ele1_index = distance( begin(vector_ele), biggest_ele1);
   
   if(genmuon_pt[muon1_index] > genelectron_pt[ele1_index]){
      genlep = 13;
      genlep1pt  = genmuon_pt[muon1_index];
      genlep1eta = genmuon_eta[muon1_index];
      genlep1phi = genmuon_phi[muon1_index];
      for_gen_lep1p4.SetPtEtaPhiM(genlep1pt, genlep1eta, genlep1phi, 0.105666);

      for(int for_gen_iphoton=0; for_gen_iphoton<6; for_gen_iphoton++){
         TLorentzVector for_gen_photon_temp;
         for_gen_photon_temp.SetPtEtaPhiM(genphoton_pt[for_gen_iphoton], genphoton_eta[for_gen_iphoton], genphoton_phi[for_gen_iphoton], 0);
         if( for_gen_lep1p4.DeltaR(for_gen_photon_temp)<0.1) {
            for_gen_lep1p4 += for_gen_photon_temp;
            continue;
         }
      }
      genlep1pt  = for_gen_lep1p4.Pt();
      genlep1eta = for_gen_lep1p4.Eta();
      genlep1phi = for_gen_lep1p4.Phi();

   }

   else if(genmuon_pt[muon1_index]<=genelectron_pt[ele1_index]){
      genlep = 11;
      genlep1pt  = genelectron_pt[ele1_index];
      genlep1eta = genelectron_eta[ele1_index];
      genlep1phi = genelectron_phi[ele1_index];
      for_gen_lep1p4.SetPtEtaPhiM(genlep1pt, genlep1eta, genlep1phi, 0.00051);

      for(int for_gen_iphoton=0; for_gen_iphoton<6; for_gen_iphoton++){
         TLorentzVector for_gen_photon_temp;
         for_gen_photon_temp.SetPtEtaPhiM(genphoton_pt[for_gen_iphoton], genphoton_eta[for_gen_iphoton], genphoton_phi[for_gen_iphoton], 0);
         if( for_gen_lep1p4.DeltaR(for_gen_photon_temp)<0.1) {
            for_gen_lep1p4 += for_gen_photon_temp;
            continue;
         }
      }
      genlep1pt  = for_gen_lep1p4.Pt();
      genlep1eta = for_gen_lep1p4.Eta();
      genlep1phi = for_gen_lep1p4.Phi();

   }

   genyVlep  =(for_gen_lep1p4).Eta();
   genphiVlep=(for_gen_lep1p4).Phi();
   genptVlep =(for_gen_lep1p4).Pt();
   genmassVlep=(for_gen_lep1p4).M();
   for_gen_vp4.SetPtEtaPhiM(genptVlep, genyVlep, genphiVlep, genmassVlep);

}

void match_genphoton_genjet(double genphoton_pt[6], double genphoton_eta[6], double genphoton_phi[6], 
     double genjet_pt[6], double genjet_eta[6], double genjet_phi[6], double genjet_e[6], 
     double genmuon_pt[6], double genmuon_eta[6], double genmuon_phi[6], double genelectron_pt[6], double genelectron_eta[6], double genelectron_phi[6]){

   for(int gen_photon_index = 0; gen_photon_index<6; gen_photon_index++){
      if(delta_R(genphoton_eta[gen_photon_index], genphoton_phi[gen_photon_index], genlep1eta, genlep1phi) < 0.5){
         vector_photon[gen_photon_index] = 0;
      }
   }

   biggest_photon = max_element(begin(vector_photon), end(vector_photon));
   if(*biggest_photon >= 0){
      pho1_index = distance( begin(vector_photon), biggest_photon);
      genphotonet = genphoton_pt[pho1_index];
      genphotoneta = genphoton_eta[pho1_index];
      genphotonphi = genphoton_phi[pho1_index];
      for_gen_photonp42.SetPtEtaPhiM(genphotonet, genphotoneta, genphotonphi, 0);
      genWGmass = (for_gen_vp4 + for_gen_photonp42).M();
      gendrla1 = delta_R(genphotoneta, genphotonphi, genlep1eta, genlep1phi);

      Int_t jetindexphoton12[2] = {-1, -1};
      for(Int_t i = 0; i < 6; i++){
         if(genphotonet > 0){
            double drtmp1 = delta_R(genjet_eta[i], genjet_phi[i], genphotoneta, genphotonphi);
            double drjlep1 = delta_R(genjet_eta[i], genjet_phi[i], genlep1eta, genlep1phi);
            if(genjet_pt[i] > 0 && drtmp1 > 0.5 &&drjlep1 > 0.5  && jetindexphoton12[0] == -1 && jetindexphoton12[1] == -1) {
               jetindexphoton12[0] = i;
               continue;
            }
            if(genjet_pt[i] > 0 && drtmp1 > 0.5 && drjlep1 > 0.5  && jetindexphoton12[0] != -1 && jetindexphoton12[1] == -1) {
               if(delta_R(genjet_eta[i], genjet_phi[i], genjet_eta[jetindexphoton12[0]], genjet_phi[jetindexphoton12[0]]) > 0.5){
                  jetindexphoton12[1] = i;
                  continue;
               }
            }
         }
      }


      jet1index = jetindexphoton12[0];
      jet2index = jetindexphoton12[1];

      jet_index[0] = jetindexphoton12[0];
      jet_index[1] = jetindexphoton12[1];

      if(jetindexphoton12[0] > -1 && jetindexphoton12[1] > -1){
         genjet1pt  = genjet_pt[jetindexphoton12[0]];
         genjet1eta = genjet_eta[jetindexphoton12[0]];
         genjet1phi = genjet_phi[jetindexphoton12[0]];
         genjet1e   = genjet_e[jetindexphoton12[0]];
         genjet2pt  = genjet_pt[jetindexphoton12[1]];
         genjet2eta = genjet_eta[jetindexphoton12[1]];
         genjet2phi = genjet_phi[jetindexphoton12[1]];
         genjet2e   = genjet_e[jetindexphoton12[1]];

         gendrj1a = delta_R(genjet1eta, genjet1phi, genphotoneta, genphotonphi);
         gendrj2a = delta_R(genjet2eta, genjet2phi, genphotoneta, genphotonphi);
         gendrj1l = delta_R(genjet1eta, genjet1phi, genlep1eta, genlep1phi);
         gendrj2l = delta_R(genjet2eta, genjet2phi, genlep1eta, genlep1phi);
         TLorentzVector for_gen_j1p4;
         for_gen_j1p4.SetPtEtaPhiE(genjet1pt, genjet1eta, genjet1phi, genjet1e);

         TLorentzVector for_gen_j2p4;
         for_gen_j2p4.SetPtEtaPhiE(genjet2pt, genjet2eta, genjet2phi, genjet2e);
   
         TLorentzVector photonp4;
         photonp4.SetPtEtaPhiM(genphotonet, genphotoneta, genphotonphi, 0);


         genMla = (photonp4+for_gen_vp4).M();
         genMjj=(for_gen_j1p4 + for_gen_j2p4).M();
         genzepp = fabs((for_gen_vp4+photonp4).Rapidity() - (for_gen_j1p4.Rapidity() + for_gen_j2p4.Rapidity())/ 2.0);
         gendetajj = fabs(genjet1eta - genjet2eta);
         gendelta_phi = fabs((for_gen_vp4+photonp4).Phi()-(for_gen_j1p4+for_gen_j2p4).Phi());

         if (gendelta_phi > Pi) gendelta_phi = 2*Pi - gendelta_phi;
         if (fabs(genjet1phi - genjet2phi) > Pi) {
            gendrjj = sqrt((genjet1eta - genjet2eta)*(genjet1eta - genjet2eta) + (2*Pi - fabs(genjet1phi - genjet2phi))*(2*Pi - fabs(genjet1phi - genjet2phi)));
         }
         else gendrjj = sqrt((genjet1eta - genjet2eta)*(genjet1eta - genjet2eta)+(fabs(genjet1phi - genjet2phi))*(fabs(genjet1phi - genjet2phi)));

      }
   }
}

void gen_clear(){
   vector_photon.clear();
   vector_jet.clear();
   vector_muon.clear();
   vector_ele.clear();
}

