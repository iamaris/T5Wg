#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include <THStack.h>
#include "TLorentzVector.h"
#include <iostream>
#include "PhysicsObjects.h"
#include "functions.h"
#include "TCanvas.h"
#include <math.h>       
#include <set>       
using namespace mini;
using namespace functions;
#include <TRandom.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <Riostream.h>

const double PI = 4.0*atan(1.0); 

void skimmerJG()
{
  TChain eventVars("eventVars");//define eventVars tree
  eventVars.Add("../photonhad/*.root/eventVars");

  TChain allObjects("allObjects");  //define eventVars tree
  allObjects.Add("../photonhad/*.root/allObjects");

  allObjects.AddFriend("eventVars");

  //define variables
  bool hlt0;
  bool hlt1;
  float MET;
  float metPhi;
  photon   rp;
  muon     rm;
  electron re;
  jet      rj; 

  //link the branches to the variables defined above
  //this is where you add variables relevant to your analysis
  eventVars.SetBranchAddress("met", &MET);
  eventVars.SetBranchAddress("metPhi", &metPhi);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFHT400", &hlt0);
  eventVars.SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400", &hlt1);

  rp.setAddress(allObjects);
  re.setAddress(allObjects);
  rm.setAddress(allObjects);
  rj.setAddress(allObjects);

  int event=0;
  float p_pt;
  float e_pt;
  float dr;
  float ht;
  float met;
  float mt;

  TFile* hfile = new TFile("j2g.root","RECREATE","");
  // create a TTree   
  TTree *tree = new TTree("tree","Reconstruction ntuple");
  // create a branch  
  tree->Branch("event",&event,"event/I");
  tree->Branch("p_pt",&p_pt,"p_pt/F");
  tree->Branch("e_pt",&e_pt,"e_pt/F");
  tree->Branch("dr",&dr,"dr/F");
  tree->Branch("ht",&ht,"ht/F");
  tree->Branch("met",&met,"met/F");
  tree->Branch("mt",&mt,"mt/F");

  unsigned int nCnt[3] = {0};
  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){
    event = iEntry;
    nCnt[0]++;
    if(!hlt0 && !hlt1) continue;
    nCnt[1]++;
   
    std::set<unsigned> lp = Jet2Gamma(rp,80.);
    std::set<unsigned> tE = TightElectron(re,10.);

    if(lp.size()==0) continue;
    if(tE.size()==0) continue;
    std::set<unsigned>::iterator ix = tE.begin();
    nCnt[2]++;

    float ht_e = CalculateHT(rj);
    float mt_e = functions::mt(MET,metPhi,re.pt[*ix],re.phi[*ix]);

    ht=ht_e;
    met=MET;
    mt=mt_e;
    e_pt=re.pt[*ix];

    float dR(0);
    for (std::set<unsigned>::iterator ik = lp.begin();ik!=lp.end();++ik) {
      dR = deltaR(rp.eta[*ik],rp.phi[*ik],re.eta[*ix],re.phi[*ix]);
      p_pt=rp.pt[*ik];
      dr=dR;
      tree->Fill();
    }


  }//while

hfile->Write();
hfile->Close();


std::cout<< "Total events                                 : "<< nCnt[0] <<std::endl;
std::cout<< "Total events (HLT passed)                    : "<< nCnt[1] <<std::endl;
std::cout<< "-----------------------------------------------"<<std::endl;
std::cout<< "loose photon > 70. + tight electron          : "<< nCnt[2] <<std::endl;

}

