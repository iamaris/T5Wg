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

void closure()
{
  TChain eventVars("eventVars");//define eventVars tree
  //eventVars.Add("/export/cmss/acalamba/photonhad/*.root/eventVars");
  //eventVars.Add("/export/cmss/acalamba/ttbarjetgamma/*.root/eventVars");
  //eventVars.Add("/export/cmss/acalamba/QCD/*9.root/eventVars");
  //eventVars.Add("./QCD/QCD*1.root/eventVars");
  eventVars.Add("./ttbarjgamma/ttbar*.root/eventVars");
  //eventVars.Add("./Wg/*.root/eventVars");

  TChain selectedObjects("selectedObjects");  //define eventVars tree
  //selectedObjects.Add("/export/cmss/acalamba/photonhad/*.root/selectedObjects");
  //selectedObjects.Add("/export/cmss/acalamba/ttbarjetgamma/*.root/selectedObjects");
  //selectedObjects.Add("/export/cmss/acalamba/QCD/*9.root/selectedObjects");
  //selectedObjects.Add("./QCD/QCD*1.root/selectedObjects");
  selectedObjects.Add("./ttbarjgamma/ttbar*.root/selectedObjects");
  //selectedObjects.Add("./Wg/*.root/selectedObjects");

  TChain allObjects("allObjects");  //define eventVars tree
  //allObjects.Add("/export/cmss/acalamba/photonhad/*.root/allObjects");
  //allObjects.Add("/export/cmss/acalamba/ttbarjetgamma/*.root/allObjects");
  //allObjects.Add("/export/cmss/acalamba/QCD/*9.root/allObjects");
  //allObjects.Add("./QCD/QCD*1.root/allObjects");
  allObjects.Add("./ttbarjgamma/ttbar*.root/allObjects");
  //allObjects.Add("./Wg/*.root/allObjects");

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

  TH1F* h_fake = new TH1F("h_fake", "fake", 30, 0., 300.);
  TH1F* h_true = new TH1F("h_true", "true", 30, 0., 300.);
  h_true->Sumw2();
  h_fake->Sumw2();

  unsigned nCnt[20] = {0};
  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){
    //if(met>20.) continue;
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
 
    //consider event with only 1 loose electron
    if(lE.size()!=1) continue;
    it = lE.begin();

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
       //viewGenTreeRA3(gen,2.,false);
    }
    
    //fake electron
    if(TrueElectron==0) {
       h_fakeE_pt->Fill(re.pt[*it]);
    }


    if(tE.size()==1) {
        h_tE_pt->Fill(re.pt[*it]);
        h_true->Fill(re.pt[*it]);
    } else {
        h_failtE_pt->Fill(re.pt[*it]);//did not pass tight
        h_fake->Fill(re.pt[*it],fakerateinv(re.pt[*it]));
        h_true->Fill(re.pt[*it],fakerateinv2(re.pt[*it]));
    }



  }//while

std::cout<< "Total events                                 : "<< nCnt[0] <<std::endl;
std::cout<< "HLT passed                                   : "<< nCnt[1] <<std::endl;
std::cout<< "-----------------------------------------------"<<std::endl;



TH1F* pred = new TH1F("pred", "predicted", 30, 0., 300.);
pred->Add(h_true);
TCanvas *plot = new TCanvas("plot","fake rate plots",800,800);
plot->Divide(1,2);
plot->cd(1);
h_trueE_pt->Draw();
pred->Draw("same");
plot->cd(2);
TH1F* ratio = new TH1F("ratio", "% diff", 30, 0., 300.);
ratio->Add(h_trueE_pt);
ratio->Add(pred,-1);
ratio->Divide(h_trueE_pt);
ratio->Draw();


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

