/* Auto-generated header file */
#ifndef functions_h
#define functions_h
#include <math.h>
#include <set>
#include "PhysicsObjects.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iostream>
#include <list>
#include "TString.h"
#include <map>
using namespace mini;

namespace functions {

  float 
  CalculateHT(jet& _j) {
    float ht(0);
    for(unsigned k(0);k<_j.size;k++) 
      if(_j.pt[k]>40.&&fabs(_j.eta[k])<3.)
        ht = ht + _j.pt[k];
    return ht;
  }

  float
  deltaR(float _eta1, float _phi1, float _eta2, float _phi2)
  {
    float dEta(_eta1 - _eta2);
    float dPhi(TVector2::Phi_mpi_pi(_phi1 - _phi2));
    return sqrt(dEta * dEta + dPhi * dPhi);
  }

  float 
  mt(float _met,float _metPhi,float _lPt,float _lPhi)
  {
    return sqrt(2.*_met*_lPt*(1-cos(_metPhi-_lPhi)));
  }

  std::set<unsigned> 
  LoosePhoton(photon& _p, float _pt) {
    std::set<unsigned> loose;
    for(unsigned i=0;i<_p.size;i++) {
      if(_p.pt[i]<_pt) continue;
      if(fabs(_p.eta[i])>1.4442) continue;     
      if(_p.nPixelSeeds[i] > 0) continue;
      if(_p.hOverE[i] > 0.05) continue;
      if(_p.sigmaIetaIeta[i] > 0.012) continue;
      if(_p.chargedHadronIso[i] > 2.6) continue;
      if(_p.neutralHadronIso[i] > 3.5) continue;
      if(_p.photonIso[i] > 1.3) continue;
      loose.insert(i);
    }
    return loose;
  }

  bool 
  CheckLoosePhoton(photon& _p, unsigned i) {
      if(_p.nPixelSeeds[i] > 0) return false;
      if(_p.hOverE[i] > 0.05) return false;
      if(_p.sigmaIetaIeta[i] > 0.012) return false;
      if(_p.chargedHadronIso[i] > 2.6) return false;
      if(_p.neutralHadronIso[i] > 3.5) return false;
      if(_p.photonIso[i] > 1.3) return false;
    return true;
  }


  std::set<unsigned> 
  ElectronFakePhoton(photon& _p,float _pt) {
    std::set<unsigned> fake;
    for(unsigned i=0;i<_p.size;i++) {
      if(_p.pt[i] < _pt) continue;
      if(fabs(_p.eta[i])>1.4442) continue;     
      if(_p.nPixelSeeds[i] == 0) continue;
      if(_p.hOverE[i] > 0.05) continue;
      if(_p.sigmaIetaIeta[i] > 0.012) continue;
      if(_p.chargedHadronIso[i] > 2.6) continue;  
      if(_p.neutralHadronIso[i] > 3.5) continue;
      if(_p.photonIso[i] > 1.3) continue;
      fake.insert(i);
    }
    return fake; 
  }

  std::set<unsigned> 
  Jet2Gamma(photon& _p, float _pt) {
    std::set<unsigned> loose;
    for(unsigned i=0;i<_p.size;i++) {
      if(_p.pt[i]<_pt) continue;
      if(fabs(_p.eta[i])>1.4442) continue;    
      if(_p.nPixelSeeds[i] > 0) continue;
      if(_p.hOverE[i] > 0.05) continue;
      if(_p.neutralHadronIso[i] > 3.5) continue;
      if(_p.photonIso[i] > 1.3) continue;
      if((_p.sigmaIetaIeta[i] > 0.012) || ((_p.chargedHadronIso[i] > 2.6)&&(_p.chargedHadronIso[i] <15.))) {
        loose.insert(i);
      }
    }
    return loose;
  }

  std::set<unsigned>
  LooseElectronFR(electron& _e, float _pt) {
    std::set<unsigned> loose;
    for (unsigned i=0;i<_e.size;i++) {
      if(fabs(_e.eta[i])>1.4442) continue; 
      if(_e.pt[i] < _pt) continue;
      if(_e.deltaEta[i] > 0.007) continue;
      if(_e.deltaPhi[i] > 0.15) continue;
      if(_e.sigmaIetaIeta[i] > 0.01) continue;
      if(_e.hOverE[i] > 0.12) continue;
      //if(_e.d0[i] > 0.02) continue;
      if(_e.dz[i] > 0.2) continue;
      if(_e.epDiff[i] > 0.05) continue;
      //if(_e.combRelIso[i] > 0.15) continue;
      if(_e.combRelIso[i] > 0.6) continue;
      if(!_e.passConversionVeto[i]) continue;
      if(_e.vtxFitProb[i] > 0.000001) continue;
      if(_e.nMissingHits[i] > 1) continue;
      loose.insert(i);
    }
    return loose;
  }

  bool 
  CheckLooseElectronFR(electron& _e, unsigned i) {
    if(_e.deltaEta[i] > 0.007) return false;
    if(_e.deltaPhi[i] > 0.15) return false;
    if(_e.sigmaIetaIeta[i] > 0.01) return false;
    if(_e.hOverE[i] > 0.12) return false;
    if(_e.dz[i] > 0.2) return false;
    if(_e.epDiff[i] > 0.05) return false;
    if(_e.combRelIso[i] > 0.6) return false;
    if(!_e.passConversionVeto[i]) return false;
    if(_e.vtxFitProb[i] > 0.000001) return false;
    if(_e.nMissingHits[i] > 1) return false;
    return true;
  }


  std::set<unsigned>
  TightElectron(electron& _e,float _pt) {
    std::set<unsigned> tight;

    for (unsigned i=0;i<_e.size;i++) {
      if(fabs(_e.eta[i]) > 1.4442) continue;
      if(_e.pt[i] < _pt) continue;
      if(_e.deltaEta[i] >= 0.004) continue;
      if(_e.deltaPhi[i] >= 0.03) continue;
      if(_e.sigmaIetaIeta[i] >= 0.01) continue;
      if(_e.hOverE[i] >= 0.12) continue;
      if(_e.d0[i] >= 0.02) continue;
      if(_e.dz[i] >= 0.1) continue;
      if(_e.epDiff[i] >= 0.05) continue;
      if(_e.combRelIso[i] >= 0.10) continue;
      if(!_e.passConversionVeto[i]) continue;
      if(_e.vtxFitProb[i] >= 0.000001) continue;
      if(((int)_e.nMissingHits[i]) > 0) continue;
      tight.insert(i);
    }
    return tight; 
  }

  bool 
  CheckTightElectron(electron& _e,unsigned i) {
    if(_e.deltaEta[i] >= 0.004) return false;
    if(_e.deltaPhi[i] >= 0.03) return false;
    if(_e.sigmaIetaIeta[i] >= 0.01) return false;
    if(_e.hOverE[i] >= 0.12) return false;
    if(_e.d0[i] >= 0.02) return false;
    if(_e.dz[i] >= 0.1) return false;
    if(_e.epDiff[i] >= 0.05) return false;
    if(_e.combRelIso[i] >= 0.10) return false;
    if(!_e.passConversionVeto[i]) return false;
    if(_e.vtxFitProb[i] >= 0.000001) return false;
    if(((int)_e.nMissingHits[i]) > 0) return false;
    return true;
  }


  std::set<unsigned>
  ProxyElectron(electron& _e,float _pt) {
    std::set<unsigned> tight;
    for (unsigned i=0;i<_e.size;i++) {
      if(fabs(_e.eta[i]) > 1.4442) continue;
      if(_e.pt[i] < _pt) continue;
      if(_e.sigmaIetaIeta[i] >= 0.01) continue;
      if(_e.hOverE[i] >= 0.12) continue;
      if(_e.d0[i] >= 0.02) continue;
      if(_e.dz[i] >= 0.1) continue;
      if(_e.epDiff[i] >= 0.05) continue;
      if(_e.combRelIso[i] > 10.) continue;
      if(!_e.passConversionVeto[i]) continue;
      if(_e.vtxFitProb[i] >= 0.000001) continue;
      if(((int)_e.nMissingHits[i]) > 0) continue;
      if(_e.deltaEta[i] < 0.004 && _e.deltaPhi[i] < 0.03) continue;
      tight.insert(i);
    }
    return tight;
  }

  void
  PrintPhoton(photon& _p, unsigned i) {
      std::cout <<
      (_p.nPixelSeeds[i]) <<","<<
      (_p.hOverE[i]) <<","<<
      (_p.sigmaIetaIeta[i]) <<","<<
      (_p.chargedHadronIso[i]) <<","<<
      (_p.neutralHadronIso[i]) <<","<<
      (_p.photonIso[i]) <<std::endl;
  }


  void
  PrintElectron(electron& re, unsigned i) {
      std::cout <<
      re.deltaEta[i]<<","<<
      re.deltaPhi[i]<<","<<
      re.sigmaIetaIeta[i]<<","<<
      re.hOverE[i]<<","<<
      re.d0[i]<<","<<
      re.dz[i]<<","<<
      re.epDiff[i]<<","<<
      re.combRelIso[i]<<","<<
      re.passConversionVeto[i]<<","<<
      re.vtxFitProb[i]<<","<<
      (int)re.nMissingHits[i]<<","<<
      re.isTight[i]<<std::endl;
  }



  std::set<unsigned>
  TightElectronTest(electron& _e,float _pt) {
    std::set<unsigned> tight;
    for (unsigned i=0;i<_e.size;i++) {
      if(fabs(_e.eta[i]) > 1.4442) continue;
      if(_e.pt[i] < _pt) continue;
      if(!_e.isTight[i]) continue;
      tight.insert(i);
    }
    return tight;
  }

  unsigned
  ShowSize(electron& _e,photon& _p) {
     return _e.size+_p.size;
  }


  std::set<unsigned>
  LooseFailTightElectron(electron& _e, float _pt) {
    std::set<unsigned> loose;
    for (unsigned i=0;i<_e.size;i++) {
      std::cout<<"CHECK ME, I'M WRONG!"<<std::endl;
      if(fabs(_e.eta[i])>1.4442) continue;
      if(_e.pt[i]<_pt) continue;
      if((_e.deltaEta[i] > 0.007) && (_e.deltaEta[i] < 0.004)) continue;
      if((_e.deltaPhi[i] > 0.15) && (_e.deltaPhi[i] < 0.03)) continue;
      if(_e.sigmaIetaIeta[i] > 0.01) continue;
      if(_e.hOverE[i] > 0.12) continue;
      if(_e.d0[i] < 0.02) continue;
      if((_e.dz[i] > 0.2)&&(_e.dz[i] < 0.1)) continue;
      if(_e.epDiff[i] > 0.05) continue;
      if((_e.combRelIso[i] > 0.6)&&(_e.combRelIso[i] < 0.1)) continue;
      if(!_e.passConversionVeto[i]) continue;
      if(_e.vtxFitProb[i] > 0.000001) continue;
      if((_e.nMissingHits[i] != 1)) continue;
      loose.insert(i);
    }
    return loose;
  }


  bool 
  CheckFailTight(electron const & _e, unsigned i) {
    if(_e.deltaEta[i] < 0.004) return false;
    if(_e.deltaPhi[i] < 0.03) return false;
    if(_e.d0[i] < 0.02) return false;
    if(_e.dz[i] < 0.1) return false;
    if(_e.combRelIso[i] < 0.1) return false;
    if(_e.nMissingHits[i] < 1) return false;
    return true;
  }

  float weight(float a) {   
     float x = 1.0;
     if(a<10.) x = 1.176473;
     else if (a<20) x=1.240672;
     else if (a<30) x=1.112673;
     else if (a<40) x=0.9577984;
     else if (a<50) x=0.8587648;
     else if (a<60) x=0.7821141;
     else if (a<70) x=0.7445199;
     else if (a<80) x=0.7205241;
     else if (a<90) x=0.6805645;
     else if (a<100) x=0.6540859;
     else if (a<110) x=0.6822752;
     else if (a<120) x=0.6578089;
     else if (a<130) x=0.5676219;
     else if (a<140) x=0.6529528;
     else if (a<150) x=0.6317016;
     else if (a<160) x=0.78001;
     else if (a<170) x=0.5193042;
     else if (a<180) x=0.6032466;
     else if (a<190) x=0.5682302;
     else if (a<200) x=0.5771073;
     else if (a<210) x=0.7014769;
     else if (a<220) x=0.5848857;
     else if (a<230) x=0.7435444;
     else if (a<240) x=0.702547;
     else if (a<250) x=0.6347489;
     else if (a<260) x=0.8357671;
     else if (a<270) x=0.7415775;
     else if (a<280) x=0.8746811;
     else if (a<290) x=0.9375126;
     else x=1.0;
     return 1.0/x;
  }

  float fr(float _pt) {   
     float x =(0.188508+0.319138*exp(-0.0202228*_pt));      
     return x;
  }

  float pfrinv(float _pt, float _p=.95) {     
     float x =1./(_p - fr(_pt));     
     return x;
  }

  float fr1(float _pt) {
       float x = (1.0 - fr(_pt));
       return x;
  }


  float fakerate(float _pt) {
       float x = 0.0;
       x = 0.0261+0.138*exp(-0.0616*_pt);
       return x;
  }

  float fakerateinv(float _pt) {
       float x = 1.0/(1.0 - fakerate(_pt));
       return x;
  }

  float fakerateinv2(float _pt) {
       float x = -fakerate(_pt)/(1.0 - fakerate(_pt));
       return x;
  }

  float jetfakerate(float _pt) {
       float x = 1.734*pow(_pt,-0.363);
       return x;
  }




}

#endif
