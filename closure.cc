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
using namespace mini;
const double PI = 4.0*atan(1.0); 
#include "TH1.h"
#include "TH2.h"

void closure(TString const& _input)
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

  TH1F* h_lE_N = new TH1F("h_lE_N", "# of loose e", 6, 0., 6.);

  TH1F* h_lE_pt = new TH1F("h_lE_pt", "Loose e Pt", 30, 0., 300.);
  TH1F* h_tE_pt = new TH1F("h_tE_pt", "Tight e Pt", 30, 0., 300.);
  TH1F* h_failtE_pt = new TH1F("h_failtE_pt", "fail tight e Pt", 30, 0., 300.);
  h_lE_pt->Sumw2();  
  h_tE_pt->Sumw2();
  h_failtE_pt->Sumw2();

  TH1F* h_trueE_pt = new TH1F("h_trueE_pt", "true e Pt", 30, 0., 300.);
  TH1F* h_fakeE_pt = new TH1F("h_fakeE_pt", "fake e Pt", 30, 0., 300.);
  h_trueE_pt->Sumw2();
  h_fakeE_pt->Sumw2();

  TH1F* h_fake = new TH1F("h_fake", "e_pt: pred fake", 30, 0., 300.);
  TH1F* h_true = new TH1F("h_true", "e_pt: pred true", 30, 0., 300.);
  h_true->Sumw2();
  h_fake->Sumw2();

  TH1F* h_mt_true   = new TH1F("h_mt_true", "MT:True", 50, 0., 500.);
  TH1F* h_mt_fake = new TH1F("h_mt_fake", "MT:Fake", 50, 0., 500.);
  TH1F* h_mt_ptrue   = new TH1F("h_mt_ptrue", "MT:pred True", 50, 0., 500.);
  TH1F* h_mt_pfake = new TH1F("h_mt_pfake", "MT:pred Fake", 50, 0., 500.);
  h_mt_true->Sumw2();
  h_mt_fake->Sumw2();
  h_mt_ptrue->Sumw2();
  h_mt_pfake->Sumw2();

  TH1F* h_met_true   = new TH1F("h_met_true", "MET:True", 50, 0., 500.);
  TH1F* h_met_fake = new TH1F("h_met_fake", "MET:Fake", 50, 0., 500.);
  TH1F* h_met_ptrue   = new TH1F("h_met_ptrue", "MET:pred True", 50, 0., 500.);
  TH1F* h_met_pfake = new TH1F("h_met_pfake", "MET:pred Fake", 50, 0., 500.);
  h_met_true->Sumw2();
  h_met_fake->Sumw2();
  h_met_ptrue->Sumw2();
  h_met_pfake->Sumw2();

  unsigned nCnt[20] = {0};
  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){
    //if(met>80.) continue;
    nCnt[0]++;

    //if(!hlt0 && !hlt1) continue;
    nCnt[1]++;
    vector<Particle> gen;
    for (int i(0);i<gp.size;i++) {
      //sanity check
      if (gp.motherIndex[i]==gp.size) {
        std::cout<<"motherIndex = "<<gp.motherIndex[i]<<" | "<<"size = "<<gp.size<<"   oh oh.. "<<std::endl; 
      }     
   
      Particle _temp = {
         gp.status[i],
         gp.charge[i],
         gp.motherIndex[i],
         gp.pdgId[i],
         gp.vx[i],
         gp.vy[i],
         gp.vz[i],
         gp.pt[i],
         gp.eta[i],
         gp.phi[i],
         gp.px[i],
         gp.py[i],
         gp.pz[i],
         gp.energy[i],
         sqrt(gp.energy[i]*gp.energy[i] - gp.px[i]*gp.px[i] - gp.py[i]*gp.py[i] - gp.pz[i]*gp.pz[i])
      };
      gen.push_back(_temp);
    }

    std::set<unsigned> lE;
    std::set<unsigned> lEfr = LooseElectronFR(re);
    std::set<unsigned> tE;
    std::set<unsigned>::iterator it;

    for(unsigned k(0);k<re.size;k++) {
      if(re.isLoose[k]) {
        lE.insert(k);
      }
      if(re.isTight[k]) {
        tE.insert(k);
      }
    }
 
    h_lE_N->Fill(lE.size());
    //consider event with only 1 loose electron
    if(lE.size()!=1) continue;
    it = lE.begin();
    //if(re.pt[*it]<40.) continue;
    h_lE_pt->Fill(re.pt[*it]);
  
    //loop over all gen particles
    unsigned TrueElectron = 0;
    for (unsigned i(0);i<gp.size;i++) {
       float dR = deltaR(re.eta[*it],re.phi[*it],gp.eta[i],gp.phi[i]);
       if (dR < 0.05) {
         if(fabs(gp.pdgId[i])==11) {
             short mindex = gp.motherIndex[i];
             short mindex2 = gp.motherIndex[mindex];
             //if(abs(gp.pdgId[mindex])==15&&(abs(gp.pdgId[mindex2])==24||gp.pdgId[mindex2]==23)) TrueElectron++;
             if(abs(gp.pdgId[mindex])==24||gp.pdgId[mindex]==23) TrueElectron++;
             //if(abs(gp.pdgId[mindex])==24) TrueElectron++;
         }
       }
    }

    //with true electron
    if(TrueElectron>0) {
       h_trueE_pt->Fill(re.pt[*it]);
       float mt_e = mt(met,metPhi,re.pt[*it],re.phi[*it]);
       h_mt_true->Fill(mt_e);
       h_met_true->Fill(met); 
       //viewGenTreeRA3(gen,2.,false);
    }
    
    //fake electron
    if(TrueElectron==0) {
       h_fakeE_pt->Fill(re.pt[*it]);
       float mt_e = mt(met,metPhi,re.pt[*it],re.phi[*it]);
       h_mt_fake->Fill(mt_e);
       h_met_fake->Fill(met); 
    }


    if(tE.size()==1) {
       h_tE_pt->Fill(re.pt[*it]);
       h_true->Fill(re.pt[*it]);
       float mt_e = mt(met,metPhi,re.pt[*it],re.phi[*it]);
       h_mt_ptrue->Fill(mt_e);
       h_met_ptrue->Fill(met);
    } else {
       h_failtE_pt->Fill(re.pt[*it]);//did not pass tight
       h_fake->Fill(re.pt[*it],fakerateinv(re.pt[*it]));
       h_true->Fill(re.pt[*it],fakerateinv2(re.pt[*it]));
       float mt_e = mt(met,metPhi,re.pt[*it],re.phi[*it]);
       h_mt_pfake->Fill(mt_e,fakerateinv(re.pt[*it]));
       h_mt_ptrue->Fill(mt_e,fakerateinv2(re.pt[*it]));
       h_met_pfake->Fill(met,fakerateinv(re.pt[*it]));
       h_met_ptrue->Fill(met,fakerateinv2(re.pt[*it]));
    }



  }//while

std::cout<< "Total events                                 : "<< nCnt[0] <<std::endl;
std::cout<< "HLT passed                                   : "<< nCnt[1] <<std::endl;
std::cout<< "-----------------------------------------------"<<std::endl;



TH1F* pred = new TH1F("pred", "predicted", 30, 0., 300.);
pred->Add(h_true);
TCanvas *plot = new TCanvas("plot","fake rate plots",1200,800);
plot->Divide(3,2);
plot->cd(1);
h_trueE_pt->Draw();
pred->Draw("same");
plot->cd(4);
TH1F* ratio = new TH1F("ratio", "% diff", 30, 0., 300.);
ratio->Add(h_trueE_pt);
ratio->Add(pred,-1);
ratio->Divide(h_trueE_pt);
ratio->Draw();
plot->cd(2);
h_mt_true->Draw();
h_mt_fake->Draw("same");
plot->cd(5);
h_mt_ptrue->Draw();
h_mt_true->Draw("same");
plot->cd(3);
h_met_true->Draw();
h_met_fake->Draw("same");
plot->cd(6);
h_met_ptrue->Draw();
h_met_true->Draw("same");


TCanvas *plots = new TCanvas("plots","fake rate plots",1200,800);
plots->Divide(3,2);	
plots->cd(1);
h_true->Draw();
h_trueE_pt->Draw("same");
plots->cd(4);
TH1F* ratio0 = new TH1F("ratio0", "pred/true", 30, 0., 300.);
ratio0->Add(h_true);
ratio0->Divide(h_trueE_pt);
ratio0->Draw();
plots->cd(2);
h_mt_ptrue->Draw();
h_mt_true->Draw("same");
plots->cd(5);
TH1F* ratio1 = new TH1F("ratio1", "pred/true", 50, 0., 500.);
ratio1->Add(h_mt_ptrue);
ratio1->Divide(h_mt_true);
ratio1->Draw();
plots->cd(3);
h_met_ptrue->Draw();
h_met_true->Draw("same");
plots->cd(6);
TH1F* ratio2 = new TH1F("ratio2", "pred/true", 50, 0., 500.);
ratio2->Add(h_met_ptrue);
ratio2->Divide(h_met_true);
ratio2->Draw();



//save histograms inside sampleAnalysis.root
TObjArray hlist(0);
hlist.Add(h_lE_pt);
hlist.Add(h_tE_pt);
hlist.Add(h_fake);
hlist.Add(h_true);
hlist.Add(h_fakeE_pt);
hlist.Add(h_trueE_pt);

TFile fout("_QCD_fakerate_closuretest.root", "recreate");
hlist.Write();
fout.Close();


}

