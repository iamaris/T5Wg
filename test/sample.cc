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

  //define variables
  float p_pt;
  float e_pt;
  float dr;
  float ht;
  float mt;
  float met;

  tree->SetBranchAddress("p_pt", &p_pt);
  tree->SetBranchAddress("e_pt", &e_pt);
  tree->SetBranchAddress("dr", &dr);
  tree->SetBranchAddress("ht", &ht);
  tree->SetBranchAddress("met", &met);
  tree->SetBranchAddress("mt", &mt);

  TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
  h_dr->Sumw2() ;
  //loop over trees
  long nEntries = tree->GetEntriesFast();
  for (long i=0;i!=nEntries;++i) {
    tree->GetEntry(i); 
    if(dr<0.8) continue;
    if(ht<450.) continue;
    if(met>80.) continue;

    if (_input == "WgB") 
      h_dr->Fill(dr,0.0636);
    if (_input == "WgA") 
      h_dr->Fill(dr,0.0108);
    if (_input == "ttbar") 
      h_dr->Fill(dr,0.0158);
    if (_input == "e2g") 
      h_dr->Fill(dr,0.016);
    if (_input == "data") 
      h_dr->Fill(dr);
    if (_input == "j2g") 
      h_dr->Fill(dr,jetfakerate(p_pt));
    if (_input == "j2e") 
      h_dr->Fill(dr,-fakerateinv2(e_pt));

  }//while

h_dr->Draw();

}

