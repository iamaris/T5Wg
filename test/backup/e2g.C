#define e2g_cxx
#include "e2g.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void e2g::Loop()
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
      h_dr->Fill(dr,0.016);

   }

  std::cout<<Count<<std::endl;
  h_dr->Draw();
}
