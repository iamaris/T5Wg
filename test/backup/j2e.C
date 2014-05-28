#define j2e_cxx
#include "j2e.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


float fakerate(float _pt) {
   float x = 0.0;
   x = 0.0261+0.138*exp(-0.0616*_pt);
   return x;
}

float fakerateinv2(float _pt) {
   float x = fakerate(_pt)/(1.0 - fakerate(_pt));
   return x;
}


void j2e::Loop()
{
   if (fChain == 0) return;

   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->Sumw2();

   Long64_t nentries = fChain->GetEntriesFast();
   int Count(0);
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(dr<0.8) continue;
      if(ht<450.) continue;
      if(met>80.) continue;
      Count++;
      h_dr->Fill(dr,fakerateinv2(p_pt));//engk wrong should use e_pt
      //h_dr->Fill(dr);

   }

  std::cout<<Count<<std::endl;
  h_dr->Draw();
}
