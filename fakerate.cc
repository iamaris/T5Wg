#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include "PhysicsObjects.h"
#include "functions.h"
#include "TCanvas.h"
#include <math.h>       
#include <set>       
#include "TString.h"
#include "TSystem.h"
using namespace mini;
using namespace functions;
const double PI = 4.0*atan(1.0); 
#include "TH1.h"
#include "TH2.h"

void fakerate(TString const& _input)
{
  std::cout<<_input<<std::endl;
  TChain eventVars("eventVars");//define eventVars tree
  eventVars.Add("./"+_input+"/*.root/eventVars");

  TChain allObjects("allObjects");  //define eventVars tree
  allObjects.Add("./"+_input+"/*.root/allObjects");

  allObjects.AddFriend("eventVars");

  //define variables
  bool hlt0;
  bool hlt1;
  float met;
  float metPhi;
  photon   rp;
  muon     rm;
  electron re;
  jet      rj; 
  //link the branches to the variables defined above
  //this is where you add variables relevant to your analysis
  eventVars.SetBranchAddress("met", &met);
  eventVars.SetBranchAddress("metPhi", &metPhi);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFHT400", &hlt0);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400", &hlt1);

  rp.setAddress(allObjects);
  re.setAddress(allObjects);
  rm.setAddress(allObjects);
  rj.setAddress(allObjects);

  TH1F* h_lE_pt = new TH1F("h_lE_pt", "Loose e Pt", 10, 0., 200.);
  TH1F* h_tE_pt = new TH1F("h_tE_pt", "Tight e Pt", 10, 0., 200.);
  TH1F* h_fE_pt = new TH1F("h_fE_pt", "Fail Tight e Pt", 10, 0., 200.);
  h_lE_pt->Sumw2();
  h_tE_pt->Sumw2();
  h_fE_pt->Sumw2();

  TH1F* h_lE1_pt = new TH1F("h_lE1_pt", "Loose e Pt", 20, 0., 200.);
  TH1F* h_tE1_pt = new TH1F("h_tE1_pt", "Tight e Pt", 20, 0., 200.);
  TH1F* h_fE1_pt = new TH1F("h_fE1_pt", "Fail tight e Pt", 20, 0., 200.);
  h_lE1_pt->Sumw2();
  h_tE1_pt->Sumw2();
  h_fE1_pt->Sumw2();

  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){

    std::set<unsigned> lE=LooseElectronFR(re,10.);
    std::set<unsigned> tE=TightElectron(re,10.);
    std::set<unsigned>::iterator it;

    //consider event with only 1 loose electron
    if(lE.size()!=1) continue;
    it = lE.begin();
    h_lE_pt->Fill(re.pt[*it]);
    h_lE1_pt->Fill(re.pt[*it]);

    if(tE.size()==1) {
      h_tE_pt->Fill(re.pt[*it]);
      h_tE1_pt->Fill(re.pt[*it]);
    } else {//did not pass tight
      h_fE_pt->Fill(re.pt[*it]);
      h_fE1_pt->Fill(re.pt[*it]);
    }
    
    h_lE1_pt->Fill(re.pt[*it]);


  }//while

TCanvas *plots = new TCanvas("plots","fake rate plots",800,800);
plots->Divide(2,2);
plots->cd(1);
h_lE_pt->Draw();
h_tE_pt->Draw("same");
plots->cd(3);
TH1F *h3 = (TH1F*)h_tE_pt->Clone("h3");
h3->Divide(h_lE_pt);
h3->Draw("e");
plots->cd(2);
h_lE1_pt->Draw();
h_tE1_pt->Draw("same");
plots->cd(4);
TH1F *h4 = (TH1F*)h_tE1_pt->Clone("h4");
h4->Divide(h_lE1_pt);
h4->Draw("e");

TObjArray hlist(0);
hlist.Add(h_lE_pt);
hlist.Add(h_tE_pt);
hlist.Add(h_fE_pt);
hlist.Add(h_lE1_pt);
hlist.Add(h_tE1_pt);
hlist.Add(h_fE1_pt);


TFile fout(_input+"_fakerate.root", "recreate");
hlist.Write();
fout.Close();


}

