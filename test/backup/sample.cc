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

void sample(TString const& _input)
{
  TFile* file = new TFile(_input+".root");
  if (!file) std::cout << "Error: File not found!"<<std::endl;

  TTree* tree;
  file->GetObject("tree",tree);
  if(!tree) std::cout<< "Error: TTree no found!"<<std::endl;

  TBranch        *b_event_p_pt;   //!
  TBranch        *b_event_e_pt;   //!
  TBranch        *b_event_dr;   //!
  TBranch        *b_event_ht;   //!
  TBranch        *b_event_met;   //!
  TBranch        *b_event_mt;

  //define variables
  float p_pt;
  float e_pt;
  float dr;
  float ht;
  float mt;
  float met;

  //link the branches to the variables defined above
  //this is where you add variables relevant to your analysis
/*  tree.SetBranchAddress("p_pt", &p_pt);
  tree.SetBranchAddress("e_pt", &e_pt);
  tree.SetBranchAddress("dr", &dr);
  tree.SetBranchAddress("ht", &ht);
  tree.SetBranchAddress("met", &met);
  tree.SetBranchAddress("mt", &mt);
*/
   tree->SetBranchAddress("p_pt", &p_pt, &b_event_p_pt);
   tree->SetBranchAddress("e_pt", &e_pt, &b_event_e_pt);
   tree->SetBranchAddress("dr", &dr, &b_event_dr);
   tree->SetBranchAddress("ht", &ht, &b_event_ht);
   tree->SetBranchAddress("met", &met, &b_event_met);
   tree->SetBranchAddress("mt", &mt, &b_event_mt);

  TH1F* hmet = new TH1F("hmet","hmet",400,0,400);
  //loop over trees
  long nEntries = tree->GetEntriesFast();
  for (long i=0;i!=nEntries;++i) {
    tree->GetEntry(i); 

    hmet->Fill(met);  
  }//while

hmet->Draw();


}

