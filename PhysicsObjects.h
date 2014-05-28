/* Auto-generated header file */
#ifndef PhysicsObjects_h
#define PhysicsObjects_h
#include <math.h>
#include <set>

#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <list>
#include "TString.h"
#include <map>

namespace mini {

  unsigned const NMAX(512);
  unsigned const NGEN(1024);

  class photon {
  public:
    photon() : size(0) {}
    ~photon() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    float pt[NMAX];
    float eta[NMAX];
    float phi[NMAX];
    float px[NMAX];
    float py[NMAX];
    float pz[NMAX];
    float energy[NMAX];
    float hOverE[NMAX];
    float sigmaIetaIeta[NMAX];
    float sigmaIphiIphi[NMAX];
    float etaWidth[NMAX];
    float phiWidth[NMAX];
    float r9[NMAX];
    float r5[NMAX];
    float trackerIso[NMAX];
    float ecalIso[NMAX];
    float hcalIso[NMAX];
    float chargedHadronIso[NMAX];
    float neutralHadronIso[NMAX];
    float photonIso[NMAX];
    float caloX[NMAX];
    float caloY[NMAX];
    float caloZ[NMAX];
    short iSubdet[NMAX];
    short superClusterIndex[NMAX];
    unsigned char nPixelSeeds[NMAX];
    unsigned char nClusters[NMAX];
    bool hasMatchedElectron[NMAX];
    bool electronVetoBit[NMAX];
    bool looseElectronVetoBit[NMAX];
    bool isLoose[NMAX];
    bool isMedium[NMAX];
    bool isTight[NMAX];
    bool isLoosePix[NMAX];
    bool isMediumPix[NMAX];
    bool isTightPix[NMAX];
    bool isLooseLV[NMAX];
    bool isMediumLV[NMAX];
    bool isTightLV[NMAX];
  };

  class electron {
  public:
    electron() : size(0) {}
    ~electron() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    float pt[NMAX];
    float eta[NMAX];
    float phi[NMAX];
    float px[NMAX];
    float py[NMAX];
    float pz[NMAX];
    float energy[NMAX];
    float combRelSubdetIso[NMAX];
    float combRelIso[NMAX];
    float deltaEta[NMAX];
    float deltaPhi[NMAX];
    float sigmaIetaIeta[NMAX];
    float sigmaIphiIphi[NMAX];
    float r9[NMAX];
    float r5[NMAX];
    float etaWidth[NMAX];
    float phiWidth[NMAX];
    float hOverE[NMAX];
    float d0[NMAX];
    float dz[NMAX];
    float epDiff[NMAX];
    float vtxFitProb[NMAX];
    float dCot[NMAX];
    float dist[NMAX];
    float caloX[NMAX];
    float caloY[NMAX];
    float caloZ[NMAX];
    short iSubdet[NMAX];
    short superClusterIndex[NMAX];
    unsigned char nClusters[NMAX];
    unsigned char nPixelHits[NMAX];
    unsigned char nMissingHits[NMAX];
    bool passConversionVeto[NMAX];
    bool isVeto[NMAX];
    bool isLoose[NMAX];
    bool isMedium[NMAX];
    bool isTight[NMAX];
  };

  class muon {
  public:
    muon() : size(0) {}
    ~muon() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    float pt[NMAX];
    float eta[NMAX];
    float phi[NMAX];
    float px[NMAX];
    float py[NMAX];
    float pz[NMAX];
    float energy[NMAX];
    float normChi2[NMAX];
    float dxy[NMAX];
    float dz[NMAX];
    float combRelSubdetIso[NMAX];
    float combRelIso[NMAX];
    short iSubdet[NMAX];
    unsigned char nMatchedStations[NMAX];
    unsigned char nLayersWithMmt[NMAX];
    unsigned char nValidMuonHits[NMAX];
    unsigned char nValidPixelHits[NMAX];
    bool isGlobalMuon[NMAX];
    bool isPFMuon[NMAX];
    bool hasInnerTrack[NMAX];
    bool hasGlobalTrack[NMAX];
    bool hasBestTrack[NMAX];
    bool isLoose[NMAX];
    bool isTight[NMAX];
  };

  class jet {
  public:
    jet() : size(0) {}
    ~jet() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    float pt[NMAX];
    float eta[NMAX];
    float phi[NMAX];
    float px[NMAX];
    float py[NMAX];
    float pz[NMAX];
    float energy[NMAX];
    float jecScale[NMAX];
    float chFraction[NMAX];
    float nhFraction[NMAX];
    float ceFraction[NMAX];
    float neFraction[NMAX];
    short iSubdet[NMAX];
    unsigned char nConstituents[NMAX];
    unsigned char nCharged[NMAX];
    bool passPUJetIdLoose[NMAX];
    bool isLoose[NMAX];
  };

  class vertex {
  public:
    vertex() : size(0) {}
    ~vertex() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    float x[NMAX];
    float y[NMAX];
    float z[NMAX];
    float rho[NMAX];
    float sumPt2[NMAX];
    float chi2[NMAX];
    float ndof[NMAX];
    unsigned short nTracks[NMAX];
    bool isGood[NMAX];
  };

  class genparticle {
  public:
    genparticle() : size(0) {}
    ~genparticle() {}
    void setAddress(TTree&);
    void clear() { size = 0; }

    unsigned size;
    unsigned short status[NGEN];
    short charge[NGEN];
    short motherIndex[NGEN];
    int pdgId[NGEN];
    float vx[NGEN];
    float vy[NGEN];
    float vz[NGEN];
    float pt[NGEN];
    float eta[NGEN];
    float phi[NGEN];
    float px[NGEN];
    float py[NGEN];
    float pz[NGEN];
    float energy[NGEN];
  };



  void
  photon::setAddress(TTree& _tree)
  {
    _tree.SetBranchAddress("photon.size", &size);
    if(_tree.GetBranch("photon.pt")) _tree.SetBranchAddress("photon.pt", pt);
    if(_tree.GetBranch("photon.eta")) _tree.SetBranchAddress("photon.eta", eta);
    if(_tree.GetBranch("photon.phi")) _tree.SetBranchAddress("photon.phi", phi);
    if(_tree.GetBranch("photon.px")) _tree.SetBranchAddress("photon.px", px);
    if(_tree.GetBranch("photon.py")) _tree.SetBranchAddress("photon.py", py);
    if(_tree.GetBranch("photon.pz")) _tree.SetBranchAddress("photon.pz", pz);
    if(_tree.GetBranch("photon.energy")) _tree.SetBranchAddress("photon.energy", energy);
    if(_tree.GetBranch("photon.hOverE")) _tree.SetBranchAddress("photon.hOverE", hOverE);
    if(_tree.GetBranch("photon.sigmaIetaIeta")) _tree.SetBranchAddress("photon.sigmaIetaIeta", sigmaIetaIeta);
    if(_tree.GetBranch("photon.sigmaIphiIphi")) _tree.SetBranchAddress("photon.sigmaIphiIphi", sigmaIphiIphi);
    if(_tree.GetBranch("photon.etaWidth")) _tree.SetBranchAddress("photon.etaWidth", etaWidth);
    if(_tree.GetBranch("photon.phiWidth")) _tree.SetBranchAddress("photon.phiWidth", phiWidth);
    if(_tree.GetBranch("photon.r9")) _tree.SetBranchAddress("photon.r9", r9);
    if(_tree.GetBranch("photon.r5")) _tree.SetBranchAddress("photon.r5", r5);
    if(_tree.GetBranch("photon.trackerIso")) _tree.SetBranchAddress("photon.trackerIso", trackerIso);
    if(_tree.GetBranch("photon.ecalIso")) _tree.SetBranchAddress("photon.ecalIso", ecalIso);
    if(_tree.GetBranch("photon.hcalIso")) _tree.SetBranchAddress("photon.hcalIso", hcalIso);
    if(_tree.GetBranch("photon.chargedHadronIso")) _tree.SetBranchAddress("photon.chargedHadronIso", chargedHadronIso);
    if(_tree.GetBranch("photon.neutralHadronIso")) _tree.SetBranchAddress("photon.neutralHadronIso", neutralHadronIso);
    if(_tree.GetBranch("photon.photonIso")) _tree.SetBranchAddress("photon.photonIso", photonIso);
    if(_tree.GetBranch("photon.caloX")) _tree.SetBranchAddress("photon.caloX", caloX);
    if(_tree.GetBranch("photon.caloY")) _tree.SetBranchAddress("photon.caloY", caloY);
    if(_tree.GetBranch("photon.caloZ")) _tree.SetBranchAddress("photon.caloZ", caloZ);
    if(_tree.GetBranch("photon.iSubdet")) _tree.SetBranchAddress("photon.iSubdet", iSubdet);
    if(_tree.GetBranch("photon.superClusterIndex")) _tree.SetBranchAddress("photon.superClusterIndex", superClusterIndex);
    if(_tree.GetBranch("photon.nPixelSeeds")) _tree.SetBranchAddress("photon.nPixelSeeds", nPixelSeeds);
    if(_tree.GetBranch("photon.nClusters")) _tree.SetBranchAddress("photon.nClusters", nClusters);
    if(_tree.GetBranch("photon.hasMatchedElectron")) _tree.SetBranchAddress("photon.hasMatchedElectron", hasMatchedElectron);
    if(_tree.GetBranch("photon.electronVetoBit")) _tree.SetBranchAddress("photon.electronVetoBit", electronVetoBit);
    if(_tree.GetBranch("photon.looseElectronVetoBit")) _tree.SetBranchAddress("photon.looseElectronVetoBit", looseElectronVetoBit);
    if(_tree.GetBranch("photon.isLoose")) _tree.SetBranchAddress("photon.isLoose", isLoose);
    if(_tree.GetBranch("photon.isMedium")) _tree.SetBranchAddress("photon.isMedium", isMedium);
    if(_tree.GetBranch("photon.isTight")) _tree.SetBranchAddress("photon.isTight", isTight);
    if(_tree.GetBranch("photon.isLoosePix")) _tree.SetBranchAddress("photon.isLoosePix", isLoosePix);
    if(_tree.GetBranch("photon.isMediumPix")) _tree.SetBranchAddress("photon.isMediumPix", isMediumPix);
    if(_tree.GetBranch("photon.isTightPix")) _tree.SetBranchAddress("photon.isTightPix", isTightPix);
    if(_tree.GetBranch("photon.isLooseLV")) _tree.SetBranchAddress("photon.isLooseLV", isLooseLV);
    if(_tree.GetBranch("photon.isMediumLV")) _tree.SetBranchAddress("photon.isMediumLV", isMediumLV);
    if(_tree.GetBranch("photon.isTightLV")) _tree.SetBranchAddress("photon.isTightLV", isTightLV);
  }

   void
   electron::setAddress(TTree& _tree)
   {
     _tree.SetBranchAddress("electron.size", &size);
     if(_tree.GetBranch("electron.pt")) _tree.SetBranchAddress("electron.pt", pt);
     if(_tree.GetBranch("electron.eta")) _tree.SetBranchAddress("electron.eta", eta);
     if(_tree.GetBranch("electron.phi")) _tree.SetBranchAddress("electron.phi", phi);
     if(_tree.GetBranch("electron.px")) _tree.SetBranchAddress("electron.px", px);
     if(_tree.GetBranch("electron.py")) _tree.SetBranchAddress("electron.py", py);
     if(_tree.GetBranch("electron.pz")) _tree.SetBranchAddress("electron.pz", pz);
     if(_tree.GetBranch("electron.energy")) _tree.SetBranchAddress("electron.energy", energy);
     if(_tree.GetBranch("electron.combRelSubdetIso")) _tree.SetBranchAddress("electron.combRelSubdetIso", combRelSubdetIso);
     if(_tree.GetBranch("electron.combRelIso")) _tree.SetBranchAddress("electron.combRelIso", combRelIso);
     if(_tree.GetBranch("electron.deltaEta")) _tree.SetBranchAddress("electron.deltaEta", deltaEta);
     if(_tree.GetBranch("electron.deltaPhi")) _tree.SetBranchAddress("electron.deltaPhi", deltaPhi);
     if(_tree.GetBranch("electron.sigmaIetaIeta")) _tree.SetBranchAddress("electron.sigmaIetaIeta", sigmaIetaIeta);
     if(_tree.GetBranch("electron.sigmaIphiIphi")) _tree.SetBranchAddress("electron.sigmaIphiIphi", sigmaIphiIphi);
     if(_tree.GetBranch("electron.r9")) _tree.SetBranchAddress("electron.r9", r9);
     if(_tree.GetBranch("electron.r5")) _tree.SetBranchAddress("electron.r5", r5);
     if(_tree.GetBranch("electron.etaWidth")) _tree.SetBranchAddress("electron.etaWidth", etaWidth);
     if(_tree.GetBranch("electron.phiWidth")) _tree.SetBranchAddress("electron.phiWidth", phiWidth);
     if(_tree.GetBranch("electron.hOverE")) _tree.SetBranchAddress("electron.hOverE", hOverE);
     if(_tree.GetBranch("electron.d0")) _tree.SetBranchAddress("electron.d0", d0);
     if(_tree.GetBranch("electron.dz")) _tree.SetBranchAddress("electron.dz", dz);
     if(_tree.GetBranch("electron.epDiff")) _tree.SetBranchAddress("electron.epDiff", epDiff);
     if(_tree.GetBranch("electron.vtxFitProb")) _tree.SetBranchAddress("electron.vtxFitProb", vtxFitProb);
     if(_tree.GetBranch("electron.dCot")) _tree.SetBranchAddress("electron.dCot", dCot);
     if(_tree.GetBranch("electron.dist")) _tree.SetBranchAddress("electron.dist", dist);
     if(_tree.GetBranch("electron.caloX")) _tree.SetBranchAddress("electron.caloX", caloX);
     if(_tree.GetBranch("electron.caloY")) _tree.SetBranchAddress("electron.caloY", caloY);
     if(_tree.GetBranch("electron.caloZ")) _tree.SetBranchAddress("electron.caloZ", caloZ);
     if(_tree.GetBranch("electron.iSubdet")) _tree.SetBranchAddress("electron.iSubdet", iSubdet);
     if(_tree.GetBranch("electron.superClusterIndex")) _tree.SetBranchAddress("electron.superClusterIndex", superClusterIndex);
     if(_tree.GetBranch("electron.nClusters")) _tree.SetBranchAddress("electron.nClusters", nClusters);
     if(_tree.GetBranch("electron.nPixelHits")) _tree.SetBranchAddress("electron.nPixelHits", nPixelHits);
     if(_tree.GetBranch("electron.nMissingHits")) _tree.SetBranchAddress("electron.nMissingHits", nMissingHits);
     if(_tree.GetBranch("electron.passConversionVeto")) _tree.SetBranchAddress("electron.passConversionVeto", passConversionVeto);
     if(_tree.GetBranch("electron.isVeto")) _tree.SetBranchAddress("electron.isVeto", isVeto);
     if(_tree.GetBranch("electron.isLoose")) _tree.SetBranchAddress("electron.isLoose", isLoose);
     if(_tree.GetBranch("electron.isMedium")) _tree.SetBranchAddress("electron.isMedium", isMedium);
     if(_tree.GetBranch("electron.isTight")) _tree.SetBranchAddress("electron.isTight", isTight);
   }
   
  void
  muon::setAddress(TTree& _tree)
  {
    _tree.SetBranchAddress("muon.size", &size);
    if(_tree.GetBranch("muon.pt")) _tree.SetBranchAddress("muon.pt", pt);
    if(_tree.GetBranch("muon.eta")) _tree.SetBranchAddress("muon.eta", eta);
    if(_tree.GetBranch("muon.phi")) _tree.SetBranchAddress("muon.phi", phi);
    if(_tree.GetBranch("muon.px")) _tree.SetBranchAddress("muon.px", px);
    if(_tree.GetBranch("muon.py")) _tree.SetBranchAddress("muon.py", py);
    if(_tree.GetBranch("muon.pz")) _tree.SetBranchAddress("muon.pz", pz);
    if(_tree.GetBranch("muon.energy")) _tree.SetBranchAddress("muon.energy", energy);
    if(_tree.GetBranch("muon.normChi2")) _tree.SetBranchAddress("muon.normChi2", normChi2);
    if(_tree.GetBranch("muon.dxy")) _tree.SetBranchAddress("muon.dxy", dxy);
    if(_tree.GetBranch("muon.dz")) _tree.SetBranchAddress("muon.dz", dz);
    if(_tree.GetBranch("muon.combRelSubdetIso")) _tree.SetBranchAddress("muon.combRelSubdetIso", combRelSubdetIso);
    if(_tree.GetBranch("muon.combRelIso")) _tree.SetBranchAddress("muon.combRelIso", combRelIso);
    if(_tree.GetBranch("muon.iSubdet")) _tree.SetBranchAddress("muon.iSubdet", iSubdet);
    if(_tree.GetBranch("muon.nMatchedStations")) _tree.SetBranchAddress("muon.nMatchedStations", nMatchedStations);
    if(_tree.GetBranch("muon.nLayersWithMmt")) _tree.SetBranchAddress("muon.nLayersWithMmt", nLayersWithMmt);
    if(_tree.GetBranch("muon.nValidMuonHits")) _tree.SetBranchAddress("muon.nValidMuonHits", nValidMuonHits);
    if(_tree.GetBranch("muon.nValidPixelHits")) _tree.SetBranchAddress("muon.nValidPixelHits", nValidPixelHits);
    if(_tree.GetBranch("muon.isGlobalMuon")) _tree.SetBranchAddress("muon.isGlobalMuon", isGlobalMuon);
    if(_tree.GetBranch("muon.isPFMuon")) _tree.SetBranchAddress("muon.isPFMuon", isPFMuon);
    if(_tree.GetBranch("muon.hasInnerTrack")) _tree.SetBranchAddress("muon.hasInnerTrack", hasInnerTrack);
    if(_tree.GetBranch("muon.hasGlobalTrack")) _tree.SetBranchAddress("muon.hasGlobalTrack", hasGlobalTrack);
    if(_tree.GetBranch("muon.hasBestTrack")) _tree.SetBranchAddress("muon.hasBestTrack", hasBestTrack);
    if(_tree.GetBranch("muon.isLoose")) _tree.SetBranchAddress("muon.isLoose", isLoose);
    if(_tree.GetBranch("muon.isTight")) _tree.SetBranchAddress("muon.isTight", isTight);
  }
  
  void
  jet::setAddress(TTree& _tree)
  {
    _tree.SetBranchAddress("jet.size", &size);
    if(_tree.GetBranch("jet.pt")) _tree.SetBranchAddress("jet.pt", pt);
    if(_tree.GetBranch("jet.eta")) _tree.SetBranchAddress("jet.eta", eta);
    if(_tree.GetBranch("jet.phi")) _tree.SetBranchAddress("jet.phi", phi);
    if(_tree.GetBranch("jet.px")) _tree.SetBranchAddress("jet.px", px);
    if(_tree.GetBranch("jet.py")) _tree.SetBranchAddress("jet.py", py);
    if(_tree.GetBranch("jet.pz")) _tree.SetBranchAddress("jet.pz", pz);
    if(_tree.GetBranch("jet.energy")) _tree.SetBranchAddress("jet.energy", energy);
    if(_tree.GetBranch("jet.jecScale")) _tree.SetBranchAddress("jet.jecScale", jecScale);
    if(_tree.GetBranch("jet.chFraction")) _tree.SetBranchAddress("jet.chFraction", chFraction);
    if(_tree.GetBranch("jet.nhFraction")) _tree.SetBranchAddress("jet.nhFraction", nhFraction);
    if(_tree.GetBranch("jet.ceFraction")) _tree.SetBranchAddress("jet.ceFraction", ceFraction);
    if(_tree.GetBranch("jet.neFraction")) _tree.SetBranchAddress("jet.neFraction", neFraction);
    if(_tree.GetBranch("jet.iSubdet")) _tree.SetBranchAddress("jet.iSubdet", iSubdet);
    if(_tree.GetBranch("jet.nConstituents")) _tree.SetBranchAddress("jet.nConstituents", nConstituents);
    if(_tree.GetBranch("jet.nCharged")) _tree.SetBranchAddress("jet.nCharged", nCharged);
    if(_tree.GetBranch("jet.passPUJetIdLoose")) _tree.SetBranchAddress("jet.passPUJetIdLoose", passPUJetIdLoose);
    if(_tree.GetBranch("jet.isLoose")) _tree.SetBranchAddress("jet.isLoose", isLoose);
  }  
  
  void
  vertex::setAddress(TTree& _tree)
  {
    _tree.SetBranchAddress("vertex.size", &size);
    if(_tree.GetBranch("vertex.x")) _tree.SetBranchAddress("vertex.x", x);
    if(_tree.GetBranch("vertex.y")) _tree.SetBranchAddress("vertex.y", y);
    if(_tree.GetBranch("vertex.z")) _tree.SetBranchAddress("vertex.z", z);
    if(_tree.GetBranch("vertex.rho")) _tree.SetBranchAddress("vertex.rho", rho);
    if(_tree.GetBranch("vertex.sumPt2")) _tree.SetBranchAddress("vertex.sumPt2", sumPt2);
    if(_tree.GetBranch("vertex.chi2")) _tree.SetBranchAddress("vertex.chi2", chi2);
    if(_tree.GetBranch("vertex.ndof")) _tree.SetBranchAddress("vertex.ndof", ndof);
    if(_tree.GetBranch("vertex.nTracks")) _tree.SetBranchAddress("vertex.nTracks", nTracks);
    if(_tree.GetBranch("vertex.isGood")) _tree.SetBranchAddress("vertex.isGood", isGood);
  }  

  void
  genparticle::setAddress(TTree& _tree)
  {
    _tree.SetBranchAddress("gen.size", &size);
    if(_tree.GetBranch("gen.status")) _tree.SetBranchAddress("gen.status", status);
    if(_tree.GetBranch("gen.charge")) _tree.SetBranchAddress("gen.charge", charge);
    if(_tree.GetBranch("gen.motherIndex")) _tree.SetBranchAddress("gen.motherIndex", motherIndex);
    if(_tree.GetBranch("gen.pdgId")) _tree.SetBranchAddress("gen.pdgId", pdgId);
    if(_tree.GetBranch("gen.vx")) _tree.SetBranchAddress("gen.vx", vx);
    if(_tree.GetBranch("gen.vy")) _tree.SetBranchAddress("gen.vy", vy);
    if(_tree.GetBranch("gen.vz")) _tree.SetBranchAddress("gen.vz", vz);
    if(_tree.GetBranch("gen.pt")) _tree.SetBranchAddress("gen.pt", pt);
    if(_tree.GetBranch("gen.eta")) _tree.SetBranchAddress("gen.eta", eta);
    if(_tree.GetBranch("gen.phi")) _tree.SetBranchAddress("gen.phi", phi);
    if(_tree.GetBranch("gen.px")) _tree.SetBranchAddress("gen.px", px);
    if(_tree.GetBranch("gen.py")) _tree.SetBranchAddress("gen.py", py);
    if(_tree.GetBranch("gen.pz")) _tree.SetBranchAddress("gen.pz", pz);
    if(_tree.GetBranch("gen.energy")) _tree.SetBranchAddress("gen.energy", energy);
  }


}

#endif
