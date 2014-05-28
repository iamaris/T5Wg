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

class Event : public TObject {
public:
  
  float p_pt; // say there are two detectors (a and b) in the experiment
  float e_pt;
  float dr;
  float ht;
  float met;
  float mt;
  ClassDef(Event,1)
};

ClassImp(Event)


void skimmer(TString const& _input,TString const& _out)
{
  std::cout<<_input<<std::endl;
  TChain eventVars("eventVars");//define eventVars tree
  eventVars.Add("../"+_input+".root/eventVars");

  TChain allObjects("allObjects");  //define eventVars tree
  allObjects.Add("../"+_input+".root/allObjects");

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

  TFile* hfile = new TFile(_out+".root","RECREATE","");
  // create a TTree   
  TTree *tree = new TTree("tree","treelibrated tree");
  Event *e = new Event;
  // create a branch  
  tree->Branch("event",&e);

  unsigned int nCnt[20] = {0};
  //loop over events
  long iEntry = 0;
  while(allObjects.GetEntry(iEntry++) != 0){
    nCnt[19]++;
    if(!hlt0 && !hlt1) continue;
    nCnt[0]++;

    std::set<unsigned> lp = LoosePhoton(rp,80.);
    std::set<unsigned> tE = TightElectron(re,10.);

    if(lp.size()==0) continue;
    if(tE.size()==0) continue;
    std::set<unsigned>::iterator ix = tE.begin();
    std::set<unsigned>::iterator ik = lp.begin();
    float dR = deltaR(rp.eta[*ik],rp.phi[*ik],re.eta[*ix],re.phi[*ix]);
    float ht = CalculateHT(rj);
    float mt_e = mt(met,metPhi,re.pt[*ix],re.phi[*ix]);
    e->p_pt=rp.pt[*ik];
    e->e_pt=re.pt[*ix];
    e->dr=dR;
    e->ht=ht;
    e->met=met;
    e->mt=mt_e;
    tree->Fill();

    if(dR<0.8) continue;
    if(ht<450.) continue;

    nCnt[1]++;

    if(mt_e>50.) nCnt[2]++;
    if(mt_e>100.) nCnt[3]++;
    if(mt_e>120.) nCnt[4]++;
    if(mt_e>140.) nCnt[5]++;

    if(met>80.) nCnt[6]++;
    if(met>100.) nCnt[7]++;
    if(met>120.) nCnt[8]++;
    if(met>140.) nCnt[9]++;
   
  }//while

hfile->Write();
hfile->Close();


std::cout<< "Total events                                 : "<< nCnt[19] <<std::endl;
std::cout<< "Total events (HLT passed)                    : "<< nCnt[0] <<std::endl;
std::cout<< "-----------------------------------------------"<<std::endl;
std::cout<< "loose photon > 70. + tight electron          : "<< nCnt[1] <<std::endl;
std::cout<< "mt > 50.0                                    : "<< nCnt[2] <<std::endl;
std::cout<< "mt > 100.0                                   : "<< nCnt[3] <<std::endl;
std::cout<< "mt > 120.0                                   : "<< nCnt[4] <<std::endl;
std::cout<< "mt > 140.0                                   : "<< nCnt[5] <<std::endl;
std::cout<< "met > 80.0                                   : "<< nCnt[6] <<std::endl;
std::cout<< "met > 100.0                                  : "<< nCnt[7] <<std::endl;
std::cout<< "met > 120.0                                  : "<< nCnt[8] <<std::endl;
std::cout<< "met > 140.0                                  : "<< nCnt[9] <<std::endl;



}

