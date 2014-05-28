//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May 25 01:33:57 2014 by ROOT version 5.34/18
// from TTree tree/treelibrated tree
// found on file: trial.root
//////////////////////////////////////////////////////////

#ifndef e2g_h
#define e2g_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TObject.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class e2g {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //Event           *event;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Float_t         p_pt;
   Float_t         e_pt;
   Float_t         dr;
   Float_t         ht;
   Float_t         met;
   Float_t         mt;

   // List of branches
   TBranch        *b_event_fUniqueID;   //!
   TBranch        *b_event_fBits;   //!
   TBranch        *b_event_p_pt;   //!
   TBranch        *b_event_e_pt;   //!
   TBranch        *b_event_dr;   //!
   TBranch        *b_event_ht;   //!
   TBranch        *b_event_met;   //!
   TBranch        *b_event_mt;   //!

   e2g(TTree *tree=0);
   virtual ~e2g();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef e2g_cxx
e2g::e2g(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("e2gNEW.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("e2gNEW.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

e2g::~e2g()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t e2g::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t e2g::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void e2g::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_event_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_event_fBits);
   fChain->SetBranchAddress("p_pt", &p_pt, &b_event_p_pt);
   fChain->SetBranchAddress("e_pt", &e_pt, &b_event_e_pt);
   fChain->SetBranchAddress("dr", &dr, &b_event_dr);
   fChain->SetBranchAddress("ht", &ht, &b_event_ht);
   fChain->SetBranchAddress("met", &met, &b_event_met);
   fChain->SetBranchAddress("mt", &mt, &b_event_mt);
   Notify();
}

Bool_t e2g::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void e2g::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t e2g::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef e2g_cxx
