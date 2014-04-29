#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLorentzVector.h"
#include <iostream>
#include "x.h"
#include "TCanvas.h"
#include <math.h>       
#include <set>       
#include "TString.h"
#include "TSystem.h"
using namespace mini;
const double PI = 4.0*atan(1.0); 
#include "TH1.h"
#include "TH2.h"

void fakerate(TString const& _input)
{
  std::cout<<_input<<std::endl;
  TChain eventVars("eventVars");//define eventVars tree
  eventVars.Add("./"+_input+".root/eventVars");

  TChain selectedObjects("selectedObjects");  //define eventVars tree	
  selectedObjects.Add("./"+_input+".root/selectedObjects");

  TChain allObjects("allObjects");  //define eventVars tree
  allObjects.Add("./"+_input+".root/allObjects");

  allObjects.AddFriend("selectedObjects");
  allObjects.AddFriend("eventVars");

  //define variables
  bool hlt0;
  bool hlt1;
  float met;
  float metPhi;
  photon   p, rp;
  muon     m, rm;
  electron e, re;
  jet      j, rj; 
  genparticle gp;
  //link the branches to the variables defined above
  //this is where you add variables relevant to your analysis
  eventVars.SetBranchAddress("met", &met);
  eventVars.SetBranchAddress("metPhi", &metPhi);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFHT400", &hlt0);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400", &hlt1);

  p.setAddress(selectedObjects);
  m.setAddress(selectedObjects);
  e.setAddress(selectedObjects);
  j.setAddress(selectedObjects);

  rp.setAddress(allObjects);
  re.setAddress(allObjects);
  rm.setAddress(allObjects);
  rj.setAddress(allObjects);
 
  gp.setAddress(eventVars);

  TH1F* h_N_tG = new TH1F("h_N_tG", "tight G Pt", 10, 0., 10.);
  TH1F* h_N_lE = new TH1F("h_N_lE", "Loose e Pt", 10, 0., 10.);
  TH1F* h_N_tE = new TH1F("h_N_tE", "Tight e Pt", 10, 0., 10.);
  TH1F* h_all_lE_pt = new TH1F("h_all_lE_pt", "Loose e Pt", 10, 0., 10.);
  TH1F* h_all_tE_pt = new TH1F("h_all_tE_pt", "Tight e Pt", 10, 0., 10.);
  TH1F* h_all_tG_pt = new TH1F("h_all_tG_pt", "Tight G Pt", 10, 0., 10.);
  TH1F* h_lE_pt = new TH1F("h_lE_pt", "Loose e Pt", 30, 0., 300.);
  TH1F* h_tE_pt = new TH1F("h_tE_pt", "Tight e Pt", 30, 0., 300.);
  TH1F* h_fE_pt = new TH1F("h_fE_pt", "Fail-tight e Pt", 30, 0., 300.);
  h_lE_pt->Sumw2();  
  h_tE_pt->Sumw2();  
  h_fE_pt->Sumw2(); 
  TH1F* h_lE1_pt = new TH1F("h_lE1_pt", "Loose e Pt", 30, 0., 300.);
  TH1F* h_tE1_pt = new TH1F("h_tE1_pt", "Tight e Pt", 30, 0., 300.);
  TH1F* h_fE1_pt = new TH1F("h_fE1_pt", "Fail-tight e Pt", 30, 0., 300.);
  h_lE1_pt->Sumw2();  
  h_tE1_pt->Sumw2();  
  h_fE1_pt->Sumw2(); 


  unsigned nCnt[20] = {0};
  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){

    nCnt[0]++;

    std::set<unsigned> lE;
    std::set<unsigned> tE;
    std::set<unsigned> lG;
    std::set<unsigned>::iterator it;

    for(unsigned k(0);k<re.size;k++) {
      if(re.iSubdet[k]!=0) continue;
      if(re.isLoose[k]) {
        lE.insert(k);
        h_all_lE_pt->Fill(re.pt[k]);
      }
      if(re.isTight[k]) {
        tE.insert(k);
        h_all_tE_pt->Fill(re.pt[k]);
      }
    }

    h_N_lE->Fill(lE.size());
    h_N_tE->Fill(tE.size());


    for(unsigned k(0);k<rp.size;k++) {    
      if (!p.isLoose[k]) continue;
      lG.insert(k);
      h_all_tG_pt->Fill(rp.pt[k]);
    }
    h_N_tG->Fill(lG.size());
 

    //consider event with only 1 loose electron
    if(lE.size()!=1) continue;
    it = lE.begin();
    ///remove electron close to a loose photon
    h_lE_pt->Fill(re.pt[*it]);

    if(tE.size()==1) {
      h_tE_pt->Fill(re.pt[*it]);
    } else {//did not pass tight
      h_fE_pt->Fill(re.pt[*it]);
    }
    
    int checkDR(0);
    for (std::set<unsigned int>::iterator ik=lG.begin(); ik!=lG.end(); ++ik) {
      if(deltaR(rp.eta[*ik],rp.phi[*ik],re.eta[*it],re.phi[*it])<0.1) {
          checkDR++;
      }
    }
    if(checkDR) continue;   
    
    float MT = mini::mt(met,metPhi,re.pt[*it],re.phi[*it]);
    //if(MT>25.) continue;

    h_lE1_pt->Fill(re.pt[*it]);

    if(tE.size()==1) {
      h_tE1_pt->Fill(re.pt[*it]);
    } else {//did not pass tight
      h_fE1_pt->Fill(re.pt[*it]);
    }


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

//h_lE_pt->Draw();
//h_tE_pt->Draw("same");
//save histograms inside sampleAnalysis.root
TObjArray hlist(0);
hlist.Add(h_lE_pt);
hlist.Add(h_tE_pt);
hlist.Add(h_fE_pt);
hlist.Add(h_lE1_pt);
hlist.Add(h_tE1_pt);
hlist.Add(h_fE1_pt);


TFile fout("fakerate.root", "recreate");
hlist.Write();
fout.Close();


}

