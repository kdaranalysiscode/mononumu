//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jul  2 13:37:40 2016 by ROOT version 4.00/08
// from TChain outputTree/
//////////////////////////////////////////////////////////

#ifndef outputTree_h
#define outputTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
   const Int_t kMaxmyHeader = 2;
   const Int_t kMaxmyTankHeader = 2;
   const Int_t kMaxmyMCEvent = 1;
   const Int_t kMaxmyMCParticle = 109;
   const Int_t kMaxmyMCParent = 4;
   const Int_t kMaxmyMCEventWeight = 1;
   const Int_t kMaxmyMCXsecEventWeight = 1;
   const Int_t kMaxmyMCReweightCV = 1;
   const Int_t kMaxmyMCNuanceWeight = 1;
   const Int_t kMaxmyMCWeightDetails = 1;
   const Int_t kMaxmyWeightArray = 1;
   const Int_t kMaxmyCalE = 1;
   const Int_t kMaxmysplitEvent = 20;
   const Int_t kMaxmyYBoostOut = 20;
   const Int_t kMaxmyAll = 20;
   const Int_t kMaxmyRFast = 20;
   const Int_t kMaxmyRFull = 20;
   const Int_t kMaxmyRPi0 = 20;
   const Int_t kMaxmyRTrak = 20;
   const Int_t kMaxmyTransRFull = 20;
   const Int_t kMaxmyTransRPi0 = 20;
   const Int_t kMaxmyTransRTrak = 20;
   const Int_t kMaxmyRecoCon = 20;
   const Int_t kMaxmyRecoDisj = 20;
   const Int_t kMaxmyRecoOneTrk = 20;
   const Int_t kMaxmyRecoTwoTrk = 20;
   const Int_t kMaxmyRecoOneTrkMu = 20;
   const Int_t kMaxmyRecoTwoTrkFix = 20;
   const Int_t kMaxmyStFast = 20;
   const Int_t kMaxmyStFlux = 20;
   const Int_t kMaxmyStFull = 20;
   const Int_t kMaxmyStPi0 = 20;
   const Int_t kMaxmyStTrak = 20;
   const Int_t kMaxmyStVarsTwo = 20;

class outputTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           eventInfo_numCrate13;
   Int_t           eventInfo_numDaqBits;
   Int_t           eventInfo_numTA;
   Int_t           eventInfo_numHeader;
   Int_t           eventInfo_numTankHeader;
   Int_t           eventInfo_numMCEvt;
   Int_t           eventInfo_numMCPart;
   Int_t           eventInfo_numCalE;
   Int_t           eventInfo_numMichelVar;
   Int_t           eventInfo_numNuMu;
   Int_t           eventInfo_numNuMu2;
   Int_t           eventInfo_numRecPID;
   Int_t           eventInfo_numSE;
   Int_t           eventInfo_numMCEvtWeight;
   Int_t           eventInfo_numMCXsecEvtWeight;
   Int_t           eventInfo_numMCNuanWeight;
   Int_t           eventInfo_numMCWeightDet;
   Int_t           eventInfo_numMCReweightCV;
   Int_t           eventInfo_numMulti_tot;
   Int_t           eventInfo_numMulti_pip;
   Int_t           eventInfo_numMulti_pim;
   Int_t           eventInfo_numMulti_kp;
   Int_t           eventInfo_numMulti_k0;
   Int_t           eventInfo_numMulti_pi0;
   Int_t           eventInfo_numMulti_xsec;
   Int_t           eventInfo_numMulti_beam;
   Int_t           eventInfo_numMulti_dirt;
   Int_t           eventInfo_numMulti_km;
   Int_t           eventInfo_numMulti_ccpi;
   Int_t           eventInfo_numMulti_had;
   Int_t           eventInfo_numWArray;
   Int_t           eventInfo_numMakeTT;
   Int_t           myHeader_;
   UInt_t          myHeader_fUniqueID[kMaxmyHeader];   //[myHeader_]
   UInt_t          myHeader_fBits[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_DAQversion[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_RecordType[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_RecordOrigin[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_NumBytes[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_RunNumber[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_Secs[kMaxmyHeader];   //[myHeader_]
   Int_t           myHeader_MilliSecs[kMaxmyHeader];   //[myHeader_]
   Int_t           myTankHeader_;
   UInt_t          myTankHeader_fUniqueID[kMaxmyTankHeader];   //[myTankHeader_]
   UInt_t          myTankHeader_fBits[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_RunNumber[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_EventNumber[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_SubRunNumber[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_EventType[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_TrigEvNum[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_TrigFifo[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_nTSAFifo[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_GPSLower[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_GPSUpper[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_TrigEvType[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_nTSATrig[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myTankHeader_nBCastTrig[kMaxmyTankHeader];   //[myTankHeader_]
   Int_t           myMCEvent_;
   UInt_t          myMCEvent_fUniqueID[kMaxmyMCEvent];   //[myMCEvent_]
   UInt_t          myMCEvent_fBits[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_version[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_flags[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_eventNumber[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nuType[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nDecayPart[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nFinalState[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nProcTags[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_neutType[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nNeutAncest[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_beamWeight[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_nTankHits[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_random1[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_random2[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_weight[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_pNu_x[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_pNu_y[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_pNu_z[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_pNu_E[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_endpt_x[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_endpt_y[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_endpt_z[kMaxmyMCEvent];   //[myMCEvent_]
   Float_t         myMCEvent_endpt_mag[kMaxmyMCEvent];   //[myMCEvent_]
   Int_t           myMCEvent_proctag[kMaxmyMCEvent][63];   //[myMCEvent_]
   Int_t           myMCParticle_;
   UInt_t          myMCParticle_fUniqueID[kMaxmyMCParticle];   //[myMCParticle_]
   UInt_t          myMCParticle_fBits[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParticle_geantID[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParticle_nTankCer[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParticle_nTankScint[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParticle_nVetoCer[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParticle_nVetoScint[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_time[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_ver_x[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_ver_y[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_ver_z[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_ver_mag[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_p_x[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_p_y[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_p_z[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_p_E[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_dir_x[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_dir_y[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_dir_z[kMaxmyMCParticle];   //[myMCParticle_]
   Float_t         myMCParticle_dir_mag[kMaxmyMCParticle];   //[myMCParticle_]
   Int_t           myMCParent_;
   UInt_t          myMCParent_fUniqueID[kMaxmyMCParent];   //[myMCParent_]
   UInt_t          myMCParent_fBits[kMaxmyMCParent];   //[myMCParent_]
   Int_t           myMCParent_geantID[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_initialE[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_initialT[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_x[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_y[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_z[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_mag[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_px[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_py[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_pz[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_init_pE[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_px[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_py[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_pz[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_pE[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_polx[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_poly[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_polz[kMaxmyMCParent];   //[myMCParent_]
   Float_t         myMCParent_fin_polmag[kMaxmyMCParent];   //[myMCParent_]
   Int_t           myMCEventWeight_;
   UInt_t          myMCEventWeight_fUniqueID[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   UInt_t          myMCEventWeight_fBits[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_Enu[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_Beamwgt[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Int_t           myMCEventWeight_NuType[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Int_t           myMCEventWeight_IdImm[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Int_t           myMCEventWeight_IdProd[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_Pneu_x[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_Pneu_y[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_Pneu_z[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PImm_x[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PImm_y[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PImm_z[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PProd_x[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PProd_y[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_PProd_z[kMaxmyMCEventWeight];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_SWpip[kMaxmyMCEventWeight][10];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_SWpim[kMaxmyMCEventWeight][10];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_SWkp[kMaxmyMCEventWeight][10];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_SWkm[kMaxmyMCEventWeight][10];   //[myMCEventWeight_]
   Float_t         myMCEventWeight_SWk0[kMaxmyMCEventWeight][10];   //[myMCEventWeight_]
   Int_t           myMCXsecEventWeight_;
   UInt_t          myMCXsecEventWeight_fUniqueID[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   UInt_t          myMCXsecEventWeight_fBits[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Pneu_xsec_x[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Pneu_xsec_y[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Pneu_xsec_z[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Plep_xsec_x[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Plep_xsec_y[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Plep_xsec_z[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Int_t           myMCXsecEventWeight_NuCh_xsec[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Int_t           myMCXsecEventWeight_NuType_xsec[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Int_t           myMCXsecEventWeight_LepId_xsec[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2_xsec[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Enue_xsec[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuCCQE[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2CCQE[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuNCEL[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2NCEL[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuCC1pi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2CC1pi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuNC1pi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2NC1pi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuCCnpi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2CCnpi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuNCnpi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2NCnpi[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuCCDIS[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2CCDIS[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuNCDIS[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2NCDIS[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuCCCoh[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2CCCoh[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuNCCoh[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2NCCoh[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuUser1[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2User1[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_EnuUser2[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Float_t         myMCXsecEventWeight_Q2User2[kMaxmyMCXsecEventWeight];   //[myMCXsecEventWeight_]
   Int_t           myMCReweightCV_;
   UInt_t          myMCReweightCV_fUniqueID[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   UInt_t          myMCReweightCV_fBits[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Ppi0[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Enu[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_XsecWght[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_FluxWght[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Int_t           myMCReweightCV_NuType[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Int_t           myMCReweightCV_NuanceCh[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Int_t           myMCReweightCV_IdParent[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Rad_x[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Rad_y[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Rad_z[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_Rad_r[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_PParent_px[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_PParent_py[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_PParent_pz[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Float_t         myMCReweightCV_PParent_E[kMaxmyMCReweightCV];   //[myMCReweightCV_]
   Int_t           myMCNuanceWeight_;
   UInt_t          myMCNuanceWeight_fUniqueID[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   UInt_t          myMCNuanceWeight_fBits[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Weight[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Channel[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_E_neutrino[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_E_lepton[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_K_target[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Qsq[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_W[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_X[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Y[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Phi_cm[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Float_t         myMCNuanceWeight_Cos_fermi[kMaxmyMCNuanceWeight];   //[myMCNuanceWeight_]
   Int_t           myMCWeightDetails_;
   UInt_t          myMCWeightDetails_fUniqueID[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   UInt_t          myMCWeightDetails_fBits[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Resangle[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Dirt[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Pi0mom[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Deltamom[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Pi0coh[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Pi0res[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Nuance[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Pipflux[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Pimflux[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Kpflux[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Kmflux[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_K0flux[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Histo[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Npip[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Float_t         myMCWeightDetails_Totalweight[kMaxmyMCWeightDetails];   //[myMCWeightDetails_]
   Int_t           myWeightArray_;
   UInt_t          myWeightArray_fUniqueID[kMaxmyWeightArray];   //[myWeightArray_]
   UInt_t          myWeightArray_fBits[kMaxmyWeightArray];   //[myWeightArray_]
   Int_t           myWeightArray_Nemaqe[kMaxmyWeightArray];   //[myWeightArray_]
   Int_t           myWeightArray_Nelosf[kMaxmyWeightArray];   //[myWeightArray_]
   Double_t        myWeightArray_Emaqe[kMaxmyWeightArray][50];   //[myWeightArray_]
   Double_t        myWeightArray_Elosf[kMaxmyWeightArray][50];   //[myWeightArray_]
   Double_t        myWeightArray_Maelowt[kMaxmyWeightArray][50][50];   //[myWeightArray_]
   Int_t           myCalE_;
   UInt_t          myCalE_fUniqueID[kMaxmyCalE];   //[myCalE_]
   UInt_t          myCalE_fBits[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_Tlep_e[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_Tlep_m[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_Qsq_e[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_Qsq_m[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_EnuQE_e[kMaxmyCalE];   //[myCalE_]
   Float_t         myCalE_EnuQE_m[kMaxmyCalE];   //[myCalE_]
   Int_t           mysplitEvent_;
   UInt_t          mysplitEvent_fUniqueID[kMaxmysplitEvent];   //[mysplitEvent_]
   UInt_t          mysplitEvent_fBits[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nTankHits[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nVetoHits[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nHighChgTnk[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nHighChgVeto[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_qTot[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_tankqTot[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_vetoqTot[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_minTime[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_maxTime[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_aveTimeTank[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_peakTimeTank[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_rmsTimeTank[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_aveTimeVeto[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_peakTimeVeto[kMaxmysplitEvent];   //[mysplitEvent_]
   Float_t         mysplitEvent_rmsTimeVeto[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nMCparent[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nMCpart[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nPid[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRFast[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRFull[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTrak[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRPi0[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRFitters[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRFittersPi0[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRYangVars[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransFull[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransTrak[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransPi0[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransFitters[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransFittersPi0[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRTransYangVars[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSFast[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSFull[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSTrak[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSFlux[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSPi0[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nSVarsTwo[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoConst[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoDisjoint[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoOneTrk[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoOneTrkPred[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoPID[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoTwoTrk[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoTwoTrkPred[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoTwoTrkFix[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           mysplitEvent_nRecoTwoTrkFlt[kMaxmysplitEvent];   //[mysplitEvent_]
   Int_t           myYBoostOut_;
   UInt_t          myYBoostOut_fUniqueID[kMaxmyYBoostOut];   //[myYBoostOut_]
   UInt_t          myYBoostOut_fBits[kMaxmyYBoostOut];   //[myYBoostOut_]
   Float_t         myYBoostOut_CVBoost_V172[kMaxmyYBoostOut];   //[myYBoostOut_]
   Float_t         myYBoostOut_CVBoost_V175[kMaxmyYBoostOut];   //[myYBoostOut_]
   Float_t         myYBoostOut_MBoost_V172[kMaxmyYBoostOut];   //[myYBoostOut_]
   Int_t           myAll_;
   UInt_t          myAll_fUniqueID[kMaxmyAll];   //[myAll_]
   UInt_t          myAll_fBits[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_fthvl[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_fthvp[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_qlful[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_qtmr3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_qtmr4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_rawtavg[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_rawtsig[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_rslvl53[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_rslvl64[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_tlb24[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_tlb45[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_tlful[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_tlm22[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_tlsci[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EMu_trak[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_angle[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_dcbeam[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_dist1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_fcer[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_fmdiff[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_mass[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_qldiff[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_qtmr0[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_qtmr56[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_rslvl53[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_rslvl64[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_scratio[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_tlb245[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_tlcer[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_tldiff[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_EPi_trak[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_NTank[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_NVeto[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_abar[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_akurtmu[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_akurtout[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_asigma[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_askew[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_askewmu[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_avgtime[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_bigang[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_cerratio[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chia[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chiae[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chiphi[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chir[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chira5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chire[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chisqmich[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chisqst[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_cosg[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_costhc[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_covlengthg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_covlengthg2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_dtcb6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_dtcb9phit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_dtlb6to8phit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_dtlb8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_earlylit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_energy[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhitcb1p9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhitcb4p5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhitcb9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhittb3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhittb3p5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhittb3p8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fhittb6to9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fqcb1p2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fqlb2p3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fqtchicb4p9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracpmtg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracpmtg2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracq1q2to1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracq1to2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracq2to1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracqg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracqg2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracqhitleft[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracqpmteg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_fracqpmteg2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_ftchicb2p7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_g2cratio[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_geratio[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_latelit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_leftright[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_muenergy[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_nbing1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_nbing2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_nzbing1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_nzbing2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_pi0mass[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qcb1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qfrac0[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qfrac5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qfrac6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qfrac8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qfrac9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qg2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qlb1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qlb1phit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_qtchitb9pq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_rdist[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_rtowall[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_s2mis[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_sbar[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_scratio[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_sigbin[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_sigtime[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_skurt[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_ssigma[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_sskew[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tave[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tbar[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_timekurt[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tkurt[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tracklength[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_triple[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_trpkurt[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_trpsig[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tsigma[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tskew[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_tslope[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_uzg1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_xintmax[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_COS[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_E[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_R[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_W[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_X[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_Y[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_Z[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_abscerasy[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_cerfrdiff[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_chiqrec[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_chirsqrec[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_dist2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fcertflx[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ffast[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fflux[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ffulmffas[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fn010p16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fn014p16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fn018m14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fnh11t14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fnh1t5p1518[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk010p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk011p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk012p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk012p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk013p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk014p15[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk016p17[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlk08p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh11p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh11t14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh13p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh1p18[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh1t5p1518[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlkh9p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlt05[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqlt10[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec15t16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec15t18[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec15t20[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec1t10[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec6t10[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fqrec6t14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frcer1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frcer2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frchia10m4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhcos10m8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhcos8m7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhcos9m8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhnb8m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnhrsnb5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnqcer1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frnqcer1m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcer1mov[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos10m3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos10m8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos6m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos8m3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos8m4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos8m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqcos8m7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqlk02p16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqqcer1m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frqqov[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frrs6m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frrs7m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frrs8m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsn010p13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsn010p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsn011[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsn011p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsn013[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_frsq14p20[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fscitflx[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fthjl[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fthjp[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_fthvp[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit3m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit3p6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit4p10[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit4p5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit4p8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit4p9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftnhit9m3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ftq4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_nqovovthit[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_nqtmr16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_nqtmr17p18[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_nqtmr18p19[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01ql1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01ql2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01ql3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01ql4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01tl2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi01tl3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi02fthl[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi02ql3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi02ql4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi02tl3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_pi02tl4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qcer1ovqtot[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qcer2ovqtot[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ql0cos10[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ql0cos6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_ql0cos7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlkcos3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlkcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlph16m12[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlph16m8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlphcos7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlppmtcos5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlppmtcos6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlppmtcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qlppmtcos8m6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr0p5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr4m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr4p5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr5m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr5m3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr5m4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr6p7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr7m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr7m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr7m6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr8m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmr9m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrc2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos10m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos10m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos5m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos6m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos7m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos7m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos8m3[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos8m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos8m6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrcos8m7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrmm[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrpp[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_qtmrsnb7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rdr[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rslvl1p8ovq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rslvl3p9ovq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rslvl7m4ovq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rslvl8p9ovq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rslvl9m1ovq[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rsqtmr13[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rsqtmr14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_rsqtmr16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_srec1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_srec2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_stint[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlfwd[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph11p15[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph13p14[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph14p15[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph15p16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph15p17[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph16[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlph16p17[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos10m8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos10m9[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos4m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos5m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos6m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m4[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m5[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos8m7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos9m1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos9m2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos9m6[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_tlphcos9m7[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_trakove[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Stancu_walld[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chg_density_nue[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chg_density_g1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_chg_density_g2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_numlowt_nue[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_numlowt_g1[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_numlowt_g2[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_rtowall_backward[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_rtwbv[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_ur[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Roe_urdr[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_log_e[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_log_mu[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_log_pi[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_log_emu[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_log_epi[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_mpi[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_E[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_R[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_UR[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_UZ[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_URDR[kMaxmyAll];   //[myAll_]
   Float_t         myAll_All_Pfit_Rtwbc[kMaxmyAll];   //[myAll_]
   Int_t           myRFast_;
   UInt_t          myRFast_fUniqueID[kMaxmyRFast];   //[myRFast_]
   UInt_t          myRFast_fBits[kMaxmyRFast];   //[myRFast_]
   Int_t           myRFast_iter[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_likelihood[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_time[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_vertex_x[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_vertex_y[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_vertex_z[kMaxmyRFast];   //[myRFast_]
   Float_t         myRFast_vertex_mag[kMaxmyRFast];   //[myRFast_]
   Int_t           myRFull_;
   UInt_t          myRFull_fUniqueID[kMaxmyRFull];   //[myRFull_]
   UInt_t          myRFull_fBits[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_trkCent_x[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_trkCent_y[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_trkCent_z[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_trkCent_mag[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_trkCent_time[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_dir_x[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_dir_y[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_dir_z[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_dir_mag[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_length[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_vertex_x[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_vertex_y[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_vertex_z[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_vertex_mag[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_vertex_time[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chg_infit[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chg_wgt_infit[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chisq_a_infit[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chisq_r_infit[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_weight_tot[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chisq_avg[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_rtowall[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_energy[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_length_mu[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_energy_mu[kMaxmyRFull];   //[myRFull_]
   Int_t           myRFull_numhits_infit[kMaxmyRFull];   //[myRFull_]
   Float_t         myRFull_chglength_nue[kMaxmyRFull];   //[myRFull_]
   UChar_t         myRFull_amITransRoe[kMaxmyRFull];   //[myRFull_]
   Int_t           myRPi0_;
   UInt_t          myRPi0_fUniqueID[kMaxmyRPi0];   //[myRPi0_]
   UInt_t          myRPi0_fBits[kMaxmyRPi0];   //[myRPi0_]
   UChar_t         myRPi0_amITransRoe[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_vertex_x[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_vertex_y[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_vertex_z[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_vertex_mag[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_time[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_Shift_1[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_Shift_2[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir1_x[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir1_y[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir1_z[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir1_mag[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir2_x[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir2_y[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir2_z[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_dir2_mag[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_Chg_1[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_Chg_2[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_wChg_1[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_wChg_2[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_E_1[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_E_2[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_mass[kMaxmyRPi0];   //[myRPi0_]
   Float_t         myRPi0_CosAng_1[kMaxmyRPi0];   //[myRPi0_]
   Int_t           myRTrak_;
   UInt_t          myRTrak_fUniqueID[kMaxmyRTrak];   //[myRTrak_]
   UInt_t          myRTrak_fBits[kMaxmyRTrak];   //[myRTrak_]
   Int_t           myRTrak_iter[kMaxmyRTrak];   //[myRTrak_]
   Float_t         myRTrak_likelihood[kMaxmyRTrak];   //[myRTrak_]
   Float_t         myRTrak_trklength[kMaxmyRTrak];   //[myRTrak_]
   UChar_t         myRTrak_amITransRoe[kMaxmyRTrak];   //[myRTrak_]
   Int_t           myTransRFull_;
   UInt_t          myTransRFull_fUniqueID[kMaxmyTransRFull];   //[myTransRFull_]
   UInt_t          myTransRFull_fBits[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_trkCent_x[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_trkCent_y[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_trkCent_z[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_trkCent_mag[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_trkCent_time[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_dir_x[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_dir_y[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_dir_z[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_dir_mag[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_length[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_vertex_x[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_vertex_y[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_vertex_z[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_vertex_mag[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_vertex_time[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chg_infit[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chg_wgt_infit[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chisq_a_infit[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chisq_r_infit[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_weight_tot[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chisq_avg[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_rtowall[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_energy[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_length_mu[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_energy_mu[kMaxmyTransRFull];   //[myTransRFull_]
   Int_t           myTransRFull_trans_numhits_infit[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_chglength_nue[kMaxmyTransRFull];   //[myTransRFull_]
   Float_t         myTransRFull_trans_numlowt_nue[kMaxmyTransRFull][10];   //[myTransRFull_]
   Int_t           myTransRPi0_;
   UInt_t          myTransRPi0_fUniqueID[kMaxmyTransRPi0];   //[myTransRPi0_]
   UInt_t          myTransRPi0_fBits[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_vertex_x[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_vertex_y[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_vertex_z[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_vertex_mag[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_time[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_Shift_1[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_Shift_2[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir1_x[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir1_y[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir1_z[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir1_mag[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir2_x[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir2_y[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir2_z[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_dir2_mag[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_Chg_1[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_Chg_2[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_wChg_1[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_wChg_2[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_E_1[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_E_2[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_mass[kMaxmyTransRPi0];   //[myTransRPi0_]
   Float_t         myTransRPi0_trans_CosAng_1[kMaxmyTransRPi0];   //[myTransRPi0_]
   Int_t           myTransRTrak_;
   UInt_t          myTransRTrak_fUniqueID[kMaxmyTransRTrak];   //[myTransRTrak_]
   UInt_t          myTransRTrak_fBits[kMaxmyTransRTrak];   //[myTransRTrak_]
   Int_t           myTransRTrak_trans_iter[kMaxmyTransRTrak];   //[myTransRTrak_]
   Float_t         myTransRTrak_trans_likelihood[kMaxmyTransRTrak];   //[myTransRTrak_]
   Float_t         myTransRTrak_trans_trklength[kMaxmyTransRTrak];   //[myTransRTrak_]
   Int_t           myRecoCon_;
   UInt_t          myRecoCon_fUniqueID[kMaxmyRecoCon];   //[myRecoCon_]
   UInt_t          myRecoCon_fBits[kMaxmyRecoCon];   //[myRecoCon_]
   Int_t           myRecoCon_trkType[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_mass[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_x[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_y[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_z[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_ver_mag[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_ux[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_uy[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_uz[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_dir_mag[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_time[kMaxmyRecoCon];   //[myRecoCon_]
   Float_t         myRecoCon_energy[kMaxmyRecoCon];   //[myRecoCon_]
   Int_t           myRecoDisj_;
   UInt_t          myRecoDisj_fUniqueID[kMaxmyRecoDisj];   //[myRecoDisj_]
   UInt_t          myRecoDisj_fBits[kMaxmyRecoDisj];   //[myRecoDisj_]
   Int_t           myRecoDisj_iter[kMaxmyRecoDisj];   //[myRecoDisj_]
   Int_t           myRecoDisj_trkType[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_x[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_y[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_z[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_ver_mag[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_ux[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_uy[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_uz[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_dir_mag[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_time[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_energy[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_distMeanCer[kMaxmyRecoDisj][2];   //[myRecoDisj_]
   Float_t         myRecoDisj_fluxScale[kMaxmyRecoDisj];   //[myRecoDisj_]
   Float_t         myRecoDisj_relSci[kMaxmyRecoDisj];   //[myRecoDisj_]
   Float_t         myRecoDisj_likelihood[kMaxmyRecoDisj];   //[myRecoDisj_]
   Int_t           myRecoOneTrk_;
   UInt_t          myRecoOneTrk_fUniqueID[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   UInt_t          myRecoOneTrk_fBits[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Int_t           myRecoOneTrk_iter[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Int_t           myRecoOneTrk_trkType[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_x[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_y[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_z[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_ver_mag[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_ux[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_uy[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_uz[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_dir_mag[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_time[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_energy[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_distMean[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_fluxScale[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_relSci[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Float_t         myRecoOneTrk_likelihood[kMaxmyRecoOneTrk];   //[myRecoOneTrk_]
   Int_t           myRecoTwoTrk_;
   UInt_t          myRecoTwoTrk_fUniqueID[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   UInt_t          myRecoTwoTrk_fBits[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_trackType1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_trackType2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_x[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_y[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_z[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_ver_mag[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_ux1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_uy1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_uz1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_dir_mag1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_time[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_mass[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_cosOp[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_energy1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_distMeanCer1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_distMeanCer2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_convlen1[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_ux2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_uy2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_uz2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_dir_mag2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_energy2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_convlen2[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_fluxScale[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_relSci[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_Qlikelihood[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_Tlikelihood[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Float_t         myRecoTwoTrk_likelihood[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   UChar_t         myRecoTwoTrk_fixedMass[kMaxmyRecoTwoTrk];   //[myRecoTwoTrk_]
   Int_t           myRecoOneTrkMu_;
   UInt_t          myRecoOneTrkMu_fUniqueID[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   UInt_t          myRecoOneTrkMu_fBits[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Int_t           myRecoOneTrkMu_iter[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Int_t           myRecoOneTrkMu_trkType[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_x[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_y[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_z[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_ver_mag[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_ux[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_uy[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_uz[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_dir_mag[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_time[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_energy[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_distMean[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_fluxScale[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_relSci[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Float_t         myRecoOneTrkMu_likelihood[kMaxmyRecoOneTrkMu];   //[myRecoOneTrkMu_]
   Int_t           myRecoTwoTrkFix_;
   UInt_t          myRecoTwoTrkFix_fUniqueID[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   UInt_t          myRecoTwoTrkFix_fBits[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_trackType1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_trackType2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_x[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_y[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_z[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_ver_mag[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_ux1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_uy1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_uz1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_dir_mag1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_time[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_mass[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_cosOp[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_energy1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_distMeanCer1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_distMeanCer2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_convlen1[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_ux2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_uy2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_uz2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_dir_mag2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_energy2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_convlen2[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_fluxScale[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_relSci[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_Qlikelihood[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_Tlikelihood[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Float_t         myRecoTwoTrkFix_likelihood[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   UChar_t         myRecoTwoTrkFix_fixedMass[kMaxmyRecoTwoTrkFix];   //[myRecoTwoTrkFix_]
   Int_t           myStFast_;
   UInt_t          myStFast_fUniqueID[kMaxmyStFast];   //[myStFast_]
   UInt_t          myStFast_fBits[kMaxmyStFast];   //[myStFast_]
   Int_t           myStFast_iter[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_vertex_x[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_vertex_y[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_vertex_z[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_vertex_mag[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_dir_x[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_dir_y[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_dir_z[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_dir_mag[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_time[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_distance[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_energy[kMaxmyStFast];   //[myStFast_]
   Float_t         myStFast_likelihood[kMaxmyStFast];   //[myStFast_]
   Int_t           myStFlux_;
   UInt_t          myStFlux_fUniqueID[kMaxmyStFlux];   //[myStFlux_]
   UInt_t          myStFlux_fBits[kMaxmyStFlux];   //[myStFlux_]
   Int_t           myStFlux_iter[kMaxmyStFlux];   //[myStFlux_]
   Float_t         myStFlux_likelihood[kMaxmyStFlux];   //[myStFlux_]
   Float_t         myStFlux_cerenkov[kMaxmyStFlux];   //[myStFlux_]
   Float_t         myStFlux_scint[kMaxmyStFlux];   //[myStFlux_]
   Float_t         myStFlux_Ecer_el[kMaxmyStFlux];   //[myStFlux_]
   Float_t         myStFlux_Ecer_mu[kMaxmyStFlux];   //[myStFlux_]
   Int_t           myStFull_;
   UInt_t          myStFull_fUniqueID[kMaxmyStFull];   //[myStFull_]
   UInt_t          myStFull_fBits[kMaxmyStFull];   //[myStFull_]
   Int_t           myStFull_iter[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_vertex_x[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_vertex_y[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_vertex_z[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_vertex_mag[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_dir_x[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_dir_y[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_dir_z[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_dir_mag[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_time[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_distance[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_energy[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_energy_mu[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_likelihood[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_Stkint[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_RdR[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_fqlt05[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_fqlt10[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_realver_x[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_realver_y[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_realver_z[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_realver_mag[kMaxmyStFull];   //[myStFull_]
   Float_t         myStFull_realver_time[kMaxmyStFull];   //[myStFull_]
   Int_t           myStPi0_;
   UInt_t          myStPi0_fUniqueID[kMaxmyStPi0];   //[myStPi0_]
   UInt_t          myStPi0_fBits[kMaxmyStPi0];   //[myStPi0_]
   Int_t           myStPi0_iter[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_vertex_x[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_vertex_y[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_vertex_z[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_vertex_mag[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_time[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_likelihood[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_mass[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_darec[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_fcer[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_phi1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_teta1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_phi2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_teta2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_cer1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_sci1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_cer2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_sci2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_srec1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dist1[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_srec2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dist2[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir1_x[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir1_y[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir1_z[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir1_mag[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir2_x[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir2_y[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir2_z[kMaxmyStPi0];   //[myStPi0_]
   Float_t         myStPi0_dir2_mag[kMaxmyStPi0];   //[myStPi0_]
   Int_t           myStTrak_;
   UInt_t          myStTrak_fUniqueID[kMaxmyStTrak];   //[myStTrak_]
   UInt_t          myStTrak_fBits[kMaxmyStTrak];   //[myStTrak_]
   Int_t           myStTrak_iter[kMaxmyStTrak];   //[myStTrak_]
   Float_t         myStTrak_likelihood[kMaxmyStTrak];   //[myStTrak_]
   Float_t         myStTrak_trklength[kMaxmyStTrak];   //[myStTrak_]
   Int_t           myStVarsTwo_;
   UInt_t          myStVarsTwo_fUniqueID[kMaxmyStVarsTwo];   //[myStVarsTwo_]
   UInt_t          myStVarsTwo_fBits[kMaxmyStVarsTwo];   //[myStVarsTwo_]
   Int_t           myStVarsTwo_CTH_n000[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Int_t           myStVarsTwo_CTH_nhit[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Int_t           myStVarsTwo_RS_n000[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Int_t           myStVarsTwo_RS_nhit[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Int_t           myStVarsTwo_TIM_nhit[kMaxmyStVarsTwo][10];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_mu[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_qrec[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_chia[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_qllk000[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_qllkhit[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_CTH_tllk[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_RS_qrec[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_RS_mu[kMaxmyStVarsTwo][20];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_TIM_qrec[kMaxmyStVarsTwo][10];   //[myStVarsTwo_]
   Float_t         myStVarsTwo_TIM_mu[kMaxmyStVarsTwo][10];   //[myStVarsTwo_]

   // List of branches
   TBranch        *b_eventInfo;   //!
   TBranch        *b_myHeader_;   //!
   TBranch        *b_myHeader_fUniqueID;   //!
   TBranch        *b_myHeader_fBits;   //!
   TBranch        *b_myHeader_DAQversion;   //!
   TBranch        *b_myHeader_RecordType;   //!
   TBranch        *b_myHeader_RecordOrigin;   //!
   TBranch        *b_myHeader_NumBytes;   //!
   TBranch        *b_myHeader_RunNumber;   //!
   TBranch        *b_myHeader_Secs;   //!
   TBranch        *b_myHeader_MilliSecs;   //!
   TBranch        *b_myTankHeader_;   //!
   TBranch        *b_myTankHeader_fUniqueID;   //!
   TBranch        *b_myTankHeader_fBits;   //!
   TBranch        *b_myTankHeader_RunNumber;   //!
   TBranch        *b_myTankHeader_EventNumber;   //!
   TBranch        *b_myTankHeader_SubRunNumber;   //!
   TBranch        *b_myTankHeader_EventType;   //!
   TBranch        *b_myTankHeader_TrigEvNum;   //!
   TBranch        *b_myTankHeader_TrigFifo;   //!
   TBranch        *b_myTankHeader_nTSAFifo;   //!
   TBranch        *b_myTankHeader_GPSLower;   //!
   TBranch        *b_myTankHeader_GPSUpper;   //!
   TBranch        *b_myTankHeader_TrigEvType;   //!
   TBranch        *b_myTankHeader_nTSATrig;   //!
   TBranch        *b_myTankHeader_nBCastTrig;   //!
   TBranch        *b_myMCEvent_;   //!
   TBranch        *b_myMCEvent_fUniqueID;   //!
   TBranch        *b_myMCEvent_fBits;   //!
   TBranch        *b_myMCEvent_version;   //!
   TBranch        *b_myMCEvent_flags;   //!
   TBranch        *b_myMCEvent_eventNumber;   //!
   TBranch        *b_myMCEvent_nuType;   //!
   TBranch        *b_myMCEvent_nDecayPart;   //!
   TBranch        *b_myMCEvent_nFinalState;   //!
   TBranch        *b_myMCEvent_nProcTags;   //!
   TBranch        *b_myMCEvent_neutType;   //!
   TBranch        *b_myMCEvent_nNeutAncest;   //!
   TBranch        *b_myMCEvent_beamWeight;   //!
   TBranch        *b_myMCEvent_nTankHits;   //!
   TBranch        *b_myMCEvent_random1;   //!
   TBranch        *b_myMCEvent_random2;   //!
   TBranch        *b_myMCEvent_weight;   //!
   TBranch        *b_myMCEvent_pNu_x;   //!
   TBranch        *b_myMCEvent_pNu_y;   //!
   TBranch        *b_myMCEvent_pNu_z;   //!
   TBranch        *b_myMCEvent_pNu_E;   //!
   TBranch        *b_myMCEvent_endpt_x;   //!
   TBranch        *b_myMCEvent_endpt_y;   //!
   TBranch        *b_myMCEvent_endpt_z;   //!
   TBranch        *b_myMCEvent_endpt_mag;   //!
   TBranch        *b_myMCEvent_proctag;   //!
   TBranch        *b_myMCParticle_;   //!
   TBranch        *b_myMCParticle_fUniqueID;   //!
   TBranch        *b_myMCParticle_fBits;   //!
   TBranch        *b_myMCParticle_geantID;   //!
   TBranch        *b_myMCParticle_nTankCer;   //!
   TBranch        *b_myMCParticle_nTankScint;   //!
   TBranch        *b_myMCParticle_nVetoCer;   //!
   TBranch        *b_myMCParticle_nVetoScint;   //!
   TBranch        *b_myMCParticle_time;   //!
   TBranch        *b_myMCParticle_ver_x;   //!
   TBranch        *b_myMCParticle_ver_y;   //!
   TBranch        *b_myMCParticle_ver_z;   //!
   TBranch        *b_myMCParticle_ver_mag;   //!
   TBranch        *b_myMCParticle_p_x;   //!
   TBranch        *b_myMCParticle_p_y;   //!
   TBranch        *b_myMCParticle_p_z;   //!
   TBranch        *b_myMCParticle_p_E;   //!
   TBranch        *b_myMCParticle_dir_x;   //!
   TBranch        *b_myMCParticle_dir_y;   //!
   TBranch        *b_myMCParticle_dir_z;   //!
   TBranch        *b_myMCParticle_dir_mag;   //!
   TBranch        *b_myMCParent_;   //!
   TBranch        *b_myMCParent_fUniqueID;   //!
   TBranch        *b_myMCParent_fBits;   //!
   TBranch        *b_myMCParent_geantID;   //!
   TBranch        *b_myMCParent_initialE;   //!
   TBranch        *b_myMCParent_initialT;   //!
   TBranch        *b_myMCParent_init_x;   //!
   TBranch        *b_myMCParent_init_y;   //!
   TBranch        *b_myMCParent_init_z;   //!
   TBranch        *b_myMCParent_init_mag;   //!
   TBranch        *b_myMCParent_init_px;   //!
   TBranch        *b_myMCParent_init_py;   //!
   TBranch        *b_myMCParent_init_pz;   //!
   TBranch        *b_myMCParent_init_pE;   //!
   TBranch        *b_myMCParent_fin_px;   //!
   TBranch        *b_myMCParent_fin_py;   //!
   TBranch        *b_myMCParent_fin_pz;   //!
   TBranch        *b_myMCParent_fin_pE;   //!
   TBranch        *b_myMCParent_fin_polx;   //!
   TBranch        *b_myMCParent_fin_poly;   //!
   TBranch        *b_myMCParent_fin_polz;   //!
   TBranch        *b_myMCParent_fin_polmag;   //!
   TBranch        *b_myMCEventWeight_;   //!
   TBranch        *b_myMCEventWeight_fUniqueID;   //!
   TBranch        *b_myMCEventWeight_fBits;   //!
   TBranch        *b_myMCEventWeight_Enu;   //!
   TBranch        *b_myMCEventWeight_Beamwgt;   //!
   TBranch        *b_myMCEventWeight_NuType;   //!
   TBranch        *b_myMCEventWeight_IdImm;   //!
   TBranch        *b_myMCEventWeight_IdProd;   //!
   TBranch        *b_myMCEventWeight_Pneu_x;   //!
   TBranch        *b_myMCEventWeight_Pneu_y;   //!
   TBranch        *b_myMCEventWeight_Pneu_z;   //!
   TBranch        *b_myMCEventWeight_PImm_x;   //!
   TBranch        *b_myMCEventWeight_PImm_y;   //!
   TBranch        *b_myMCEventWeight_PImm_z;   //!
   TBranch        *b_myMCEventWeight_PProd_x;   //!
   TBranch        *b_myMCEventWeight_PProd_y;   //!
   TBranch        *b_myMCEventWeight_PProd_z;   //!
   TBranch        *b_myMCEventWeight_SWpip;   //!
   TBranch        *b_myMCEventWeight_SWpim;   //!
   TBranch        *b_myMCEventWeight_SWkp;   //!
   TBranch        *b_myMCEventWeight_SWkm;   //!
   TBranch        *b_myMCEventWeight_SWk0;   //!
   TBranch        *b_myMCXsecEventWeight_;   //!
   TBranch        *b_myMCXsecEventWeight_fUniqueID;   //!
   TBranch        *b_myMCXsecEventWeight_fBits;   //!
   TBranch        *b_myMCXsecEventWeight_Pneu_xsec_x;   //!
   TBranch        *b_myMCXsecEventWeight_Pneu_xsec_y;   //!
   TBranch        *b_myMCXsecEventWeight_Pneu_xsec_z;   //!
   TBranch        *b_myMCXsecEventWeight_Plep_xsec_x;   //!
   TBranch        *b_myMCXsecEventWeight_Plep_xsec_y;   //!
   TBranch        *b_myMCXsecEventWeight_Plep_xsec_z;   //!
   TBranch        *b_myMCXsecEventWeight_NuCh_xsec;   //!
   TBranch        *b_myMCXsecEventWeight_NuType_xsec;   //!
   TBranch        *b_myMCXsecEventWeight_LepId_xsec;   //!
   TBranch        *b_myMCXsecEventWeight_Q2_xsec;   //!
   TBranch        *b_myMCXsecEventWeight_Enue_xsec;   //!
   TBranch        *b_myMCXsecEventWeight_EnuCCQE;   //!
   TBranch        *b_myMCXsecEventWeight_Q2CCQE;   //!
   TBranch        *b_myMCXsecEventWeight_EnuNCEL;   //!
   TBranch        *b_myMCXsecEventWeight_Q2NCEL;   //!
   TBranch        *b_myMCXsecEventWeight_EnuCC1pi;   //!
   TBranch        *b_myMCXsecEventWeight_Q2CC1pi;   //!
   TBranch        *b_myMCXsecEventWeight_EnuNC1pi;   //!
   TBranch        *b_myMCXsecEventWeight_Q2NC1pi;   //!
   TBranch        *b_myMCXsecEventWeight_EnuCCnpi;   //!
   TBranch        *b_myMCXsecEventWeight_Q2CCnpi;   //!
   TBranch        *b_myMCXsecEventWeight_EnuNCnpi;   //!
   TBranch        *b_myMCXsecEventWeight_Q2NCnpi;   //!
   TBranch        *b_myMCXsecEventWeight_EnuCCDIS;   //!
   TBranch        *b_myMCXsecEventWeight_Q2CCDIS;   //!
   TBranch        *b_myMCXsecEventWeight_EnuNCDIS;   //!
   TBranch        *b_myMCXsecEventWeight_Q2NCDIS;   //!
   TBranch        *b_myMCXsecEventWeight_EnuCCCoh;   //!
   TBranch        *b_myMCXsecEventWeight_Q2CCCoh;   //!
   TBranch        *b_myMCXsecEventWeight_EnuNCCoh;   //!
   TBranch        *b_myMCXsecEventWeight_Q2NCCoh;   //!
   TBranch        *b_myMCXsecEventWeight_EnuUser1;   //!
   TBranch        *b_myMCXsecEventWeight_Q2User1;   //!
   TBranch        *b_myMCXsecEventWeight_EnuUser2;   //!
   TBranch        *b_myMCXsecEventWeight_Q2User2;   //!
   TBranch        *b_myMCReweightCV_;   //!
   TBranch        *b_myMCReweightCV_fUniqueID;   //!
   TBranch        *b_myMCReweightCV_fBits;   //!
   TBranch        *b_myMCReweightCV_Ppi0;   //!
   TBranch        *b_myMCReweightCV_Enu;   //!
   TBranch        *b_myMCReweightCV_XsecWght;   //!
   TBranch        *b_myMCReweightCV_FluxWght;   //!
   TBranch        *b_myMCReweightCV_NuType;   //!
   TBranch        *b_myMCReweightCV_NuanceCh;   //!
   TBranch        *b_myMCReweightCV_IdParent;   //!
   TBranch        *b_myMCReweightCV_Rad_x;   //!
   TBranch        *b_myMCReweightCV_Rad_y;   //!
   TBranch        *b_myMCReweightCV_Rad_z;   //!
   TBranch        *b_myMCReweightCV_Rad_r;   //!
   TBranch        *b_myMCReweightCV_PParent_px;   //!
   TBranch        *b_myMCReweightCV_PParent_py;   //!
   TBranch        *b_myMCReweightCV_PParent_pz;   //!
   TBranch        *b_myMCReweightCV_PParent_E;   //!
   TBranch        *b_myMCNuanceWeight_;   //!
   TBranch        *b_myMCNuanceWeight_fUniqueID;   //!
   TBranch        *b_myMCNuanceWeight_fBits;   //!
   TBranch        *b_myMCNuanceWeight_Weight;   //!
   TBranch        *b_myMCNuanceWeight_Channel;   //!
   TBranch        *b_myMCNuanceWeight_E_neutrino;   //!
   TBranch        *b_myMCNuanceWeight_E_lepton;   //!
   TBranch        *b_myMCNuanceWeight_K_target;   //!
   TBranch        *b_myMCNuanceWeight_Qsq;   //!
   TBranch        *b_myMCNuanceWeight_W;   //!
   TBranch        *b_myMCNuanceWeight_X;   //!
   TBranch        *b_myMCNuanceWeight_Y;   //!
   TBranch        *b_myMCNuanceWeight_Phi_cm;   //!
   TBranch        *b_myMCNuanceWeight_Cos_fermi;   //!
   TBranch        *b_myMCWeightDetails_;   //!
   TBranch        *b_myMCWeightDetails_fUniqueID;   //!
   TBranch        *b_myMCWeightDetails_fBits;   //!
   TBranch        *b_myMCWeightDetails_Resangle;   //!
   TBranch        *b_myMCWeightDetails_Dirt;   //!
   TBranch        *b_myMCWeightDetails_Pi0mom;   //!
   TBranch        *b_myMCWeightDetails_Deltamom;   //!
   TBranch        *b_myMCWeightDetails_Pi0coh;   //!
   TBranch        *b_myMCWeightDetails_Pi0res;   //!
   TBranch        *b_myMCWeightDetails_Nuance;   //!
   TBranch        *b_myMCWeightDetails_Pipflux;   //!
   TBranch        *b_myMCWeightDetails_Pimflux;   //!
   TBranch        *b_myMCWeightDetails_Kpflux;   //!
   TBranch        *b_myMCWeightDetails_Kmflux;   //!
   TBranch        *b_myMCWeightDetails_K0flux;   //!
   TBranch        *b_myMCWeightDetails_Histo;   //!
   TBranch        *b_myMCWeightDetails_Npip;   //!
   TBranch        *b_myMCWeightDetails_Totalweight;   //!
   TBranch        *b_myWeightArray_;   //!
   TBranch        *b_myWeightArray_fUniqueID;   //!
   TBranch        *b_myWeightArray_fBits;   //!
   TBranch        *b_myWeightArray_Nemaqe;   //!
   TBranch        *b_myWeightArray_Nelosf;   //!
   TBranch        *b_myWeightArray_Emaqe;   //!
   TBranch        *b_myWeightArray_Elosf;   //!
   TBranch        *b_myWeightArray_Maelowt;   //!
   TBranch        *b_myCalE_;   //!
   TBranch        *b_myCalE_fUniqueID;   //!
   TBranch        *b_myCalE_fBits;   //!
   TBranch        *b_myCalE_Tlep_e;   //!
   TBranch        *b_myCalE_Tlep_m;   //!
   TBranch        *b_myCalE_Qsq_e;   //!
   TBranch        *b_myCalE_Qsq_m;   //!
   TBranch        *b_myCalE_EnuQE_e;   //!
   TBranch        *b_myCalE_EnuQE_m;   //!
   TBranch        *b_mysplitEvent_;   //!
   TBranch        *b_mysplitEvent_fUniqueID;   //!
   TBranch        *b_mysplitEvent_fBits;   //!
   TBranch        *b_mysplitEvent_nTankHits;   //!
   TBranch        *b_mysplitEvent_nVetoHits;   //!
   TBranch        *b_mysplitEvent_nHighChgTnk;   //!
   TBranch        *b_mysplitEvent_nHighChgVeto;   //!
   TBranch        *b_mysplitEvent_qTot;   //!
   TBranch        *b_mysplitEvent_tankqTot;   //!
   TBranch        *b_mysplitEvent_vetoqTot;   //!
   TBranch        *b_mysplitEvent_minTime;   //!
   TBranch        *b_mysplitEvent_maxTime;   //!
   TBranch        *b_mysplitEvent_aveTimeTank;   //!
   TBranch        *b_mysplitEvent_peakTimeTank;   //!
   TBranch        *b_mysplitEvent_rmsTimeTank;   //!
   TBranch        *b_mysplitEvent_aveTimeVeto;   //!
   TBranch        *b_mysplitEvent_peakTimeVeto;   //!
   TBranch        *b_mysplitEvent_rmsTimeVeto;   //!
   TBranch        *b_mysplitEvent_nMCparent;   //!
   TBranch        *b_mysplitEvent_nMCpart;   //!
   TBranch        *b_mysplitEvent_nPid;   //!
   TBranch        *b_mysplitEvent_nRFast;   //!
   TBranch        *b_mysplitEvent_nRFull;   //!
   TBranch        *b_mysplitEvent_nRTrak;   //!
   TBranch        *b_mysplitEvent_nRPi0;   //!
   TBranch        *b_mysplitEvent_nRFitters;   //!
   TBranch        *b_mysplitEvent_nRFittersPi0;   //!
   TBranch        *b_mysplitEvent_nRYangVars;   //!
   TBranch        *b_mysplitEvent_nRTransFull;   //!
   TBranch        *b_mysplitEvent_nRTransTrak;   //!
   TBranch        *b_mysplitEvent_nRTransPi0;   //!
   TBranch        *b_mysplitEvent_nRTransFitters;   //!
   TBranch        *b_mysplitEvent_nRTransFittersPi0;   //!
   TBranch        *b_mysplitEvent_nRTransYangVars;   //!
   TBranch        *b_mysplitEvent_nSFast;   //!
   TBranch        *b_mysplitEvent_nSFull;   //!
   TBranch        *b_mysplitEvent_nSTrak;   //!
   TBranch        *b_mysplitEvent_nSFlux;   //!
   TBranch        *b_mysplitEvent_nSPi0;   //!
   TBranch        *b_mysplitEvent_nSVarsTwo;   //!
   TBranch        *b_mysplitEvent_nRecoConst;   //!
   TBranch        *b_mysplitEvent_nRecoDisjoint;   //!
   TBranch        *b_mysplitEvent_nRecoOneTrk;   //!
   TBranch        *b_mysplitEvent_nRecoOneTrkPred;   //!
   TBranch        *b_mysplitEvent_nRecoPID;   //!
   TBranch        *b_mysplitEvent_nRecoTwoTrk;   //!
   TBranch        *b_mysplitEvent_nRecoTwoTrkPred;   //!
   TBranch        *b_mysplitEvent_nRecoTwoTrkFix;   //!
   TBranch        *b_mysplitEvent_nRecoTwoTrkFlt;   //!
   TBranch        *b_myYBoostOut_;   //!
   TBranch        *b_myYBoostOut_fUniqueID;   //!
   TBranch        *b_myYBoostOut_fBits;   //!
   TBranch        *b_myYBoostOut_CVBoost_V172;   //!
   TBranch        *b_myYBoostOut_CVBoost_V175;   //!
   TBranch        *b_myYBoostOut_MBoost_V172;   //!
   TBranch        *b_myAll_;   //!
   TBranch        *b_myAll_fUniqueID;   //!
   TBranch        *b_myAll_fBits;   //!
   TBranch        *b_myAll_All_EMu_fthvl;   //!
   TBranch        *b_myAll_All_EMu_fthvp;   //!
   TBranch        *b_myAll_All_EMu_qlful;   //!
   TBranch        *b_myAll_All_EMu_qtmr3;   //!
   TBranch        *b_myAll_All_EMu_qtmr4;   //!
   TBranch        *b_myAll_All_EMu_rawtavg;   //!
   TBranch        *b_myAll_All_EMu_rawtsig;   //!
   TBranch        *b_myAll_All_EMu_rslvl53;   //!
   TBranch        *b_myAll_All_EMu_rslvl64;   //!
   TBranch        *b_myAll_All_EMu_tlb24;   //!
   TBranch        *b_myAll_All_EMu_tlb45;   //!
   TBranch        *b_myAll_All_EMu_tlful;   //!
   TBranch        *b_myAll_All_EMu_tlm22;   //!
   TBranch        *b_myAll_All_EMu_tlsci;   //!
   TBranch        *b_myAll_All_EMu_trak;   //!
   TBranch        *b_myAll_All_EPi_angle;   //!
   TBranch        *b_myAll_All_EPi_dcbeam;   //!
   TBranch        *b_myAll_All_EPi_dist1;   //!
   TBranch        *b_myAll_All_EPi_fcer;   //!
   TBranch        *b_myAll_All_EPi_fmdiff;   //!
   TBranch        *b_myAll_All_EPi_mass;   //!
   TBranch        *b_myAll_All_EPi_qldiff;   //!
   TBranch        *b_myAll_All_EPi_qtmr0;   //!
   TBranch        *b_myAll_All_EPi_qtmr56;   //!
   TBranch        *b_myAll_All_EPi_rslvl53;   //!
   TBranch        *b_myAll_All_EPi_rslvl64;   //!
   TBranch        *b_myAll_All_EPi_scratio;   //!
   TBranch        *b_myAll_All_EPi_tlb245;   //!
   TBranch        *b_myAll_All_EPi_tlcer;   //!
   TBranch        *b_myAll_All_EPi_tldiff;   //!
   TBranch        *b_myAll_All_EPi_trak;   //!
   TBranch        *b_myAll_All_NTank;   //!
   TBranch        *b_myAll_All_NVeto;   //!
   TBranch        *b_myAll_All_Roe_abar;   //!
   TBranch        *b_myAll_All_Roe_akurtmu;   //!
   TBranch        *b_myAll_All_Roe_akurtout;   //!
   TBranch        *b_myAll_All_Roe_asigma;   //!
   TBranch        *b_myAll_All_Roe_askew;   //!
   TBranch        *b_myAll_All_Roe_askewmu;   //!
   TBranch        *b_myAll_All_Roe_avgtime;   //!
   TBranch        *b_myAll_All_Roe_bigang;   //!
   TBranch        *b_myAll_All_Roe_cerratio;   //!
   TBranch        *b_myAll_All_Roe_chia;   //!
   TBranch        *b_myAll_All_Roe_chiae;   //!
   TBranch        *b_myAll_All_Roe_chiphi;   //!
   TBranch        *b_myAll_All_Roe_chir;   //!
   TBranch        *b_myAll_All_Roe_chira5;   //!
   TBranch        *b_myAll_All_Roe_chire;   //!
   TBranch        *b_myAll_All_Roe_chisqmich;   //!
   TBranch        *b_myAll_All_Roe_chisqst;   //!
   TBranch        *b_myAll_All_Roe_cosg;   //!
   TBranch        *b_myAll_All_Roe_costhc;   //!
   TBranch        *b_myAll_All_Roe_covlengthg1;   //!
   TBranch        *b_myAll_All_Roe_covlengthg2;   //!
   TBranch        *b_myAll_All_Roe_dtcb6;   //!
   TBranch        *b_myAll_All_Roe_dtcb9phit;   //!
   TBranch        *b_myAll_All_Roe_dtlb6to8phit;   //!
   TBranch        *b_myAll_All_Roe_dtlb8;   //!
   TBranch        *b_myAll_All_Roe_earlylit;   //!
   TBranch        *b_myAll_All_Roe_energy;   //!
   TBranch        *b_myAll_All_Roe_fhitcb1p9;   //!
   TBranch        *b_myAll_All_Roe_fhitcb4p5;   //!
   TBranch        *b_myAll_All_Roe_fhitcb9;   //!
   TBranch        *b_myAll_All_Roe_fhittb3;   //!
   TBranch        *b_myAll_All_Roe_fhittb3p5;   //!
   TBranch        *b_myAll_All_Roe_fhittb3p8;   //!
   TBranch        *b_myAll_All_Roe_fhittb6to9;   //!
   TBranch        *b_myAll_All_Roe_fqcb1p2;   //!
   TBranch        *b_myAll_All_Roe_fqlb2p3;   //!
   TBranch        *b_myAll_All_Roe_fqtchicb4p9;   //!
   TBranch        *b_myAll_All_Roe_fracpmtg1;   //!
   TBranch        *b_myAll_All_Roe_fracpmtg2;   //!
   TBranch        *b_myAll_All_Roe_fracq1q2to1;   //!
   TBranch        *b_myAll_All_Roe_fracq1to2;   //!
   TBranch        *b_myAll_All_Roe_fracq2to1;   //!
   TBranch        *b_myAll_All_Roe_fracqg1;   //!
   TBranch        *b_myAll_All_Roe_fracqg2;   //!
   TBranch        *b_myAll_All_Roe_fracqhitleft;   //!
   TBranch        *b_myAll_All_Roe_fracqpmteg1;   //!
   TBranch        *b_myAll_All_Roe_fracqpmteg2;   //!
   TBranch        *b_myAll_All_Roe_ftchicb2p7;   //!
   TBranch        *b_myAll_All_Roe_g2cratio;   //!
   TBranch        *b_myAll_All_Roe_geratio;   //!
   TBranch        *b_myAll_All_Roe_latelit;   //!
   TBranch        *b_myAll_All_Roe_leftright;   //!
   TBranch        *b_myAll_All_Roe_muenergy;   //!
   TBranch        *b_myAll_All_Roe_nbing1;   //!
   TBranch        *b_myAll_All_Roe_nbing2;   //!
   TBranch        *b_myAll_All_Roe_nzbing1;   //!
   TBranch        *b_myAll_All_Roe_nzbing2;   //!
   TBranch        *b_myAll_All_Roe_pi0mass;   //!
   TBranch        *b_myAll_All_Roe_qcb1;   //!
   TBranch        *b_myAll_All_Roe_qfrac0;   //!
   TBranch        *b_myAll_All_Roe_qfrac5;   //!
   TBranch        *b_myAll_All_Roe_qfrac6;   //!
   TBranch        *b_myAll_All_Roe_qfrac8;   //!
   TBranch        *b_myAll_All_Roe_qfrac9;   //!
   TBranch        *b_myAll_All_Roe_qg1;   //!
   TBranch        *b_myAll_All_Roe_qg2;   //!
   TBranch        *b_myAll_All_Roe_qlb1;   //!
   TBranch        *b_myAll_All_Roe_qlb1phit;   //!
   TBranch        *b_myAll_All_Roe_qtchitb9pq;   //!
   TBranch        *b_myAll_All_Roe_rdist;   //!
   TBranch        *b_myAll_All_Roe_rtowall;   //!
   TBranch        *b_myAll_All_Roe_s2mis;   //!
   TBranch        *b_myAll_All_Roe_sbar;   //!
   TBranch        *b_myAll_All_Roe_scratio;   //!
   TBranch        *b_myAll_All_Roe_sigbin;   //!
   TBranch        *b_myAll_All_Roe_sigtime;   //!
   TBranch        *b_myAll_All_Roe_skurt;   //!
   TBranch        *b_myAll_All_Roe_ssigma;   //!
   TBranch        *b_myAll_All_Roe_sskew;   //!
   TBranch        *b_myAll_All_Roe_tave;   //!
   TBranch        *b_myAll_All_Roe_tbar;   //!
   TBranch        *b_myAll_All_Roe_timekurt;   //!
   TBranch        *b_myAll_All_Roe_tkurt;   //!
   TBranch        *b_myAll_All_Roe_tracklength;   //!
   TBranch        *b_myAll_All_Roe_triple;   //!
   TBranch        *b_myAll_All_Roe_trpkurt;   //!
   TBranch        *b_myAll_All_Roe_trpsig;   //!
   TBranch        *b_myAll_All_Roe_tsigma;   //!
   TBranch        *b_myAll_All_Roe_tskew;   //!
   TBranch        *b_myAll_All_Roe_tslope;   //!
   TBranch        *b_myAll_All_Roe_uzg1;   //!
   TBranch        *b_myAll_All_Roe_xintmax;   //!
   TBranch        *b_myAll_All_Stancu_COS;   //!
   TBranch        *b_myAll_All_Stancu_E;   //!
   TBranch        *b_myAll_All_Stancu_R;   //!
   TBranch        *b_myAll_All_Stancu_W;   //!
   TBranch        *b_myAll_All_Stancu_X;   //!
   TBranch        *b_myAll_All_Stancu_Y;   //!
   TBranch        *b_myAll_All_Stancu_Z;   //!
   TBranch        *b_myAll_All_Stancu_abscerasy;   //!
   TBranch        *b_myAll_All_Stancu_cerfrdiff;   //!
   TBranch        *b_myAll_All_Stancu_chiqrec;   //!
   TBranch        *b_myAll_All_Stancu_chirsqrec;   //!
   TBranch        *b_myAll_All_Stancu_dist2;   //!
   TBranch        *b_myAll_All_Stancu_fcertflx;   //!
   TBranch        *b_myAll_All_Stancu_ffast;   //!
   TBranch        *b_myAll_All_Stancu_fflux;   //!
   TBranch        *b_myAll_All_Stancu_ffulmffas;   //!
   TBranch        *b_myAll_All_Stancu_fn010p16;   //!
   TBranch        *b_myAll_All_Stancu_fn014p16;   //!
   TBranch        *b_myAll_All_Stancu_fn018m14;   //!
   TBranch        *b_myAll_All_Stancu_fnh11t14;   //!
   TBranch        *b_myAll_All_Stancu_fnh1t5p1518;   //!
   TBranch        *b_myAll_All_Stancu_fqlk010p13;   //!
   TBranch        *b_myAll_All_Stancu_fqlk011p13;   //!
   TBranch        *b_myAll_All_Stancu_fqlk012p13;   //!
   TBranch        *b_myAll_All_Stancu_fqlk012p14;   //!
   TBranch        *b_myAll_All_Stancu_fqlk013p14;   //!
   TBranch        *b_myAll_All_Stancu_fqlk014p15;   //!
   TBranch        *b_myAll_All_Stancu_fqlk016p17;   //!
   TBranch        *b_myAll_All_Stancu_fqlk08p13;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh11p13;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh11t14;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh13p14;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh1p18;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh1t5p1518;   //!
   TBranch        *b_myAll_All_Stancu_fqlkh9p14;   //!
   TBranch        *b_myAll_All_Stancu_fqlt05;   //!
   TBranch        *b_myAll_All_Stancu_fqlt10;   //!
   TBranch        *b_myAll_All_Stancu_fqrec15t16;   //!
   TBranch        *b_myAll_All_Stancu_fqrec15t18;   //!
   TBranch        *b_myAll_All_Stancu_fqrec15t20;   //!
   TBranch        *b_myAll_All_Stancu_fqrec1t10;   //!
   TBranch        *b_myAll_All_Stancu_fqrec6t10;   //!
   TBranch        *b_myAll_All_Stancu_fqrec6t14;   //!
   TBranch        *b_myAll_All_Stancu_frcer1;   //!
   TBranch        *b_myAll_All_Stancu_frcer2;   //!
   TBranch        *b_myAll_All_Stancu_frchia10m4;   //!
   TBranch        *b_myAll_All_Stancu_frnhcos10m8;   //!
   TBranch        *b_myAll_All_Stancu_frnhcos8;   //!
   TBranch        *b_myAll_All_Stancu_frnhcos8m7;   //!
   TBranch        *b_myAll_All_Stancu_frnhcos9m8;   //!
   TBranch        *b_myAll_All_Stancu_frnhnb8m2;   //!
   TBranch        *b_myAll_All_Stancu_frnhrsnb5;   //!
   TBranch        *b_myAll_All_Stancu_frnqcer1;   //!
   TBranch        *b_myAll_All_Stancu_frnqcer1m2;   //!
   TBranch        *b_myAll_All_Stancu_frqcer1mov;   //!
   TBranch        *b_myAll_All_Stancu_frqcos10m3;   //!
   TBranch        *b_myAll_All_Stancu_frqcos10m8;   //!
   TBranch        *b_myAll_All_Stancu_frqcos6m1;   //!
   TBranch        *b_myAll_All_Stancu_frqcos8;   //!
   TBranch        *b_myAll_All_Stancu_frqcos8m3;   //!
   TBranch        *b_myAll_All_Stancu_frqcos8m4;   //!
   TBranch        *b_myAll_All_Stancu_frqcos8m5;   //!
   TBranch        *b_myAll_All_Stancu_frqcos8m7;   //!
   TBranch        *b_myAll_All_Stancu_frqlk02p16;   //!
   TBranch        *b_myAll_All_Stancu_frqqcer1m2;   //!
   TBranch        *b_myAll_All_Stancu_frqqov;   //!
   TBranch        *b_myAll_All_Stancu_frrs6m1;   //!
   TBranch        *b_myAll_All_Stancu_frrs7m1;   //!
   TBranch        *b_myAll_All_Stancu_frrs8m1;   //!
   TBranch        *b_myAll_All_Stancu_frsn010p13;   //!
   TBranch        *b_myAll_All_Stancu_frsn010p14;   //!
   TBranch        *b_myAll_All_Stancu_frsn011;   //!
   TBranch        *b_myAll_All_Stancu_frsn011p14;   //!
   TBranch        *b_myAll_All_Stancu_frsn013;   //!
   TBranch        *b_myAll_All_Stancu_frsq14p20;   //!
   TBranch        *b_myAll_All_Stancu_fscitflx;   //!
   TBranch        *b_myAll_All_Stancu_fthjl;   //!
   TBranch        *b_myAll_All_Stancu_fthjp;   //!
   TBranch        *b_myAll_All_Stancu_fthvp;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit3m2;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit3p6;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit4;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit4p10;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit4p5;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit4p8;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit4p9;   //!
   TBranch        *b_myAll_All_Stancu_ftnhit9m3;   //!
   TBranch        *b_myAll_All_Stancu_ftq4;   //!
   TBranch        *b_myAll_All_Stancu_nqovovthit;   //!
   TBranch        *b_myAll_All_Stancu_nqtmr16;   //!
   TBranch        *b_myAll_All_Stancu_nqtmr17p18;   //!
   TBranch        *b_myAll_All_Stancu_nqtmr18p19;   //!
   TBranch        *b_myAll_All_Stancu_pi01ql1;   //!
   TBranch        *b_myAll_All_Stancu_pi01ql2;   //!
   TBranch        *b_myAll_All_Stancu_pi01ql3;   //!
   TBranch        *b_myAll_All_Stancu_pi01ql4;   //!
   TBranch        *b_myAll_All_Stancu_pi01tl2;   //!
   TBranch        *b_myAll_All_Stancu_pi01tl3;   //!
   TBranch        *b_myAll_All_Stancu_pi02fthl;   //!
   TBranch        *b_myAll_All_Stancu_pi02ql3;   //!
   TBranch        *b_myAll_All_Stancu_pi02ql4;   //!
   TBranch        *b_myAll_All_Stancu_pi02tl3;   //!
   TBranch        *b_myAll_All_Stancu_pi02tl4;   //!
   TBranch        *b_myAll_All_Stancu_qcer1ovqtot;   //!
   TBranch        *b_myAll_All_Stancu_qcer2ovqtot;   //!
   TBranch        *b_myAll_All_Stancu_ql0cos10;   //!
   TBranch        *b_myAll_All_Stancu_ql0cos6;   //!
   TBranch        *b_myAll_All_Stancu_ql0cos7;   //!
   TBranch        *b_myAll_All_Stancu_qlkcos3;   //!
   TBranch        *b_myAll_All_Stancu_qlkcos8;   //!
   TBranch        *b_myAll_All_Stancu_qlph16m12;   //!
   TBranch        *b_myAll_All_Stancu_qlph16m8;   //!
   TBranch        *b_myAll_All_Stancu_qlphcos7;   //!
   TBranch        *b_myAll_All_Stancu_qlppmtcos5;   //!
   TBranch        *b_myAll_All_Stancu_qlppmtcos6;   //!
   TBranch        *b_myAll_All_Stancu_qlppmtcos8;   //!
   TBranch        *b_myAll_All_Stancu_qlppmtcos8m6;   //!
   TBranch        *b_myAll_All_Stancu_qtmr0p5;   //!
   TBranch        *b_myAll_All_Stancu_qtmr4m2;   //!
   TBranch        *b_myAll_All_Stancu_qtmr4p5;   //!
   TBranch        *b_myAll_All_Stancu_qtmr5;   //!
   TBranch        *b_myAll_All_Stancu_qtmr5m2;   //!
   TBranch        *b_myAll_All_Stancu_qtmr5m3;   //!
   TBranch        *b_myAll_All_Stancu_qtmr5m4;   //!
   TBranch        *b_myAll_All_Stancu_qtmr6p7;   //!
   TBranch        *b_myAll_All_Stancu_qtmr7m2;   //!
   TBranch        *b_myAll_All_Stancu_qtmr7m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmr7m6;   //!
   TBranch        *b_myAll_All_Stancu_qtmr8m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmr9m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmrc2;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos10m2;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos10m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos5m1;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos6;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos6m1;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos7;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos7m2;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos7m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos8;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos8m3;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos8m5;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos8m6;   //!
   TBranch        *b_myAll_All_Stancu_qtmrcos8m7;   //!
   TBranch        *b_myAll_All_Stancu_qtmrmm;   //!
   TBranch        *b_myAll_All_Stancu_qtmrpp;   //!
   TBranch        *b_myAll_All_Stancu_qtmrsnb7;   //!
   TBranch        *b_myAll_All_Stancu_rdr;   //!
   TBranch        *b_myAll_All_Stancu_rslvl1p8ovq;   //!
   TBranch        *b_myAll_All_Stancu_rslvl3p9ovq;   //!
   TBranch        *b_myAll_All_Stancu_rslvl7m4ovq;   //!
   TBranch        *b_myAll_All_Stancu_rslvl8p9ovq;   //!
   TBranch        *b_myAll_All_Stancu_rslvl9m1ovq;   //!
   TBranch        *b_myAll_All_Stancu_rsqtmr13;   //!
   TBranch        *b_myAll_All_Stancu_rsqtmr14;   //!
   TBranch        *b_myAll_All_Stancu_rsqtmr16;   //!
   TBranch        *b_myAll_All_Stancu_srec1;   //!
   TBranch        *b_myAll_All_Stancu_srec2;   //!
   TBranch        *b_myAll_All_Stancu_stint;   //!
   TBranch        *b_myAll_All_Stancu_tlfwd;   //!
   TBranch        *b_myAll_All_Stancu_tlph11p15;   //!
   TBranch        *b_myAll_All_Stancu_tlph13p14;   //!
   TBranch        *b_myAll_All_Stancu_tlph14p15;   //!
   TBranch        *b_myAll_All_Stancu_tlph15p16;   //!
   TBranch        *b_myAll_All_Stancu_tlph15p17;   //!
   TBranch        *b_myAll_All_Stancu_tlph16;   //!
   TBranch        *b_myAll_All_Stancu_tlph16p17;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos10m8;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos10m9;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos4m1;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos5;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos5m1;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos6m2;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos7;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m1;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m2;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m4;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m5;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m6;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos8m7;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos9m1;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos9m2;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos9m6;   //!
   TBranch        *b_myAll_All_Stancu_tlphcos9m7;   //!
   TBranch        *b_myAll_All_Stancu_trakove;   //!
   TBranch        *b_myAll_All_Stancu_walld;   //!
   TBranch        *b_myAll_All_Roe_chg_density_nue;   //!
   TBranch        *b_myAll_All_Roe_chg_density_g1;   //!
   TBranch        *b_myAll_All_Roe_chg_density_g2;   //!
   TBranch        *b_myAll_All_Roe_numlowt_nue;   //!
   TBranch        *b_myAll_All_Roe_numlowt_g1;   //!
   TBranch        *b_myAll_All_Roe_numlowt_g2;   //!
   TBranch        *b_myAll_All_Roe_rtowall_backward;   //!
   TBranch        *b_myAll_All_Roe_rtwbv;   //!
   TBranch        *b_myAll_All_Roe_ur;   //!
   TBranch        *b_myAll_All_Roe_urdr;   //!
   TBranch        *b_myAll_All_Pfit_log_e;   //!
   TBranch        *b_myAll_All_Pfit_log_mu;   //!
   TBranch        *b_myAll_All_Pfit_log_pi;   //!
   TBranch        *b_myAll_All_Pfit_log_emu;   //!
   TBranch        *b_myAll_All_Pfit_log_epi;   //!
   TBranch        *b_myAll_All_Pfit_mpi;   //!
   TBranch        *b_myAll_All_Pfit_E;   //!
   TBranch        *b_myAll_All_Pfit_R;   //!
   TBranch        *b_myAll_All_Pfit_UR;   //!
   TBranch        *b_myAll_All_Pfit_UZ;   //!
   TBranch        *b_myAll_All_Pfit_URDR;   //!
   TBranch        *b_myAll_All_Pfit_Rtwbc;   //!
   TBranch        *b_myRFast_;   //!
   TBranch        *b_myRFast_fUniqueID;   //!
   TBranch        *b_myRFast_fBits;   //!
   TBranch        *b_myRFast_iter;   //!
   TBranch        *b_myRFast_likelihood;   //!
   TBranch        *b_myRFast_time;   //!
   TBranch        *b_myRFast_vertex_x;   //!
   TBranch        *b_myRFast_vertex_y;   //!
   TBranch        *b_myRFast_vertex_z;   //!
   TBranch        *b_myRFast_vertex_mag;   //!
   TBranch        *b_myRFull_;   //!
   TBranch        *b_myRFull_fUniqueID;   //!
   TBranch        *b_myRFull_fBits;   //!
   TBranch        *b_myRFull_trkCent_x;   //!
   TBranch        *b_myRFull_trkCent_y;   //!
   TBranch        *b_myRFull_trkCent_z;   //!
   TBranch        *b_myRFull_trkCent_mag;   //!
   TBranch        *b_myRFull_trkCent_time;   //!
   TBranch        *b_myRFull_dir_x;   //!
   TBranch        *b_myRFull_dir_y;   //!
   TBranch        *b_myRFull_dir_z;   //!
   TBranch        *b_myRFull_dir_mag;   //!
   TBranch        *b_myRFull_length;   //!
   TBranch        *b_myRFull_vertex_x;   //!
   TBranch        *b_myRFull_vertex_y;   //!
   TBranch        *b_myRFull_vertex_z;   //!
   TBranch        *b_myRFull_vertex_mag;   //!
   TBranch        *b_myRFull_vertex_time;   //!
   TBranch        *b_myRFull_chg_infit;   //!
   TBranch        *b_myRFull_chg_wgt_infit;   //!
   TBranch        *b_myRFull_chisq_a_infit;   //!
   TBranch        *b_myRFull_chisq_r_infit;   //!
   TBranch        *b_myRFull_weight_tot;   //!
   TBranch        *b_myRFull_chisq_avg;   //!
   TBranch        *b_myRFull_rtowall;   //!
   TBranch        *b_myRFull_energy;   //!
   TBranch        *b_myRFull_length_mu;   //!
   TBranch        *b_myRFull_energy_mu;   //!
   TBranch        *b_myRFull_numhits_infit;   //!
   TBranch        *b_myRFull_chglength_nue;   //!
   TBranch        *b_myRFull_amITransRoe;   //!
   TBranch        *b_myRPi0_;   //!
   TBranch        *b_myRPi0_fUniqueID;   //!
   TBranch        *b_myRPi0_fBits;   //!
   TBranch        *b_myRPi0_amITransRoe;   //!
   TBranch        *b_myRPi0_vertex_x;   //!
   TBranch        *b_myRPi0_vertex_y;   //!
   TBranch        *b_myRPi0_vertex_z;   //!
   TBranch        *b_myRPi0_vertex_mag;   //!
   TBranch        *b_myRPi0_time;   //!
   TBranch        *b_myRPi0_Shift_1;   //!
   TBranch        *b_myRPi0_Shift_2;   //!
   TBranch        *b_myRPi0_dir1_x;   //!
   TBranch        *b_myRPi0_dir1_y;   //!
   TBranch        *b_myRPi0_dir1_z;   //!
   TBranch        *b_myRPi0_dir1_mag;   //!
   TBranch        *b_myRPi0_dir2_x;   //!
   TBranch        *b_myRPi0_dir2_y;   //!
   TBranch        *b_myRPi0_dir2_z;   //!
   TBranch        *b_myRPi0_dir2_mag;   //!
   TBranch        *b_myRPi0_Chg_1;   //!
   TBranch        *b_myRPi0_Chg_2;   //!
   TBranch        *b_myRPi0_wChg_1;   //!
   TBranch        *b_myRPi0_wChg_2;   //!
   TBranch        *b_myRPi0_E_1;   //!
   TBranch        *b_myRPi0_E_2;   //!
   TBranch        *b_myRPi0_mass;   //!
   TBranch        *b_myRPi0_CosAng_1;   //!
   TBranch        *b_myRTrak_;   //!
   TBranch        *b_myRTrak_fUniqueID;   //!
   TBranch        *b_myRTrak_fBits;   //!
   TBranch        *b_myRTrak_iter;   //!
   TBranch        *b_myRTrak_likelihood;   //!
   TBranch        *b_myRTrak_trklength;   //!
   TBranch        *b_myRTrak_amITransRoe;   //!
   TBranch        *b_myTransRFull_;   //!
   TBranch        *b_myTransRFull_fUniqueID;   //!
   TBranch        *b_myTransRFull_fBits;   //!
   TBranch        *b_myTransRFull_trans_trkCent_x;   //!
   TBranch        *b_myTransRFull_trans_trkCent_y;   //!
   TBranch        *b_myTransRFull_trans_trkCent_z;   //!
   TBranch        *b_myTransRFull_trans_trkCent_mag;   //!
   TBranch        *b_myTransRFull_trans_trkCent_time;   //!
   TBranch        *b_myTransRFull_trans_dir_x;   //!
   TBranch        *b_myTransRFull_trans_dir_y;   //!
   TBranch        *b_myTransRFull_trans_dir_z;   //!
   TBranch        *b_myTransRFull_trans_dir_mag;   //!
   TBranch        *b_myTransRFull_trans_length;   //!
   TBranch        *b_myTransRFull_trans_vertex_x;   //!
   TBranch        *b_myTransRFull_trans_vertex_y;   //!
   TBranch        *b_myTransRFull_trans_vertex_z;   //!
   TBranch        *b_myTransRFull_trans_vertex_mag;   //!
   TBranch        *b_myTransRFull_trans_vertex_time;   //!
   TBranch        *b_myTransRFull_trans_chg_infit;   //!
   TBranch        *b_myTransRFull_trans_chg_wgt_infit;   //!
   TBranch        *b_myTransRFull_trans_chisq_a_infit;   //!
   TBranch        *b_myTransRFull_trans_chisq_r_infit;   //!
   TBranch        *b_myTransRFull_trans_weight_tot;   //!
   TBranch        *b_myTransRFull_trans_chisq_avg;   //!
   TBranch        *b_myTransRFull_trans_rtowall;   //!
   TBranch        *b_myTransRFull_trans_energy;   //!
   TBranch        *b_myTransRFull_trans_length_mu;   //!
   TBranch        *b_myTransRFull_trans_energy_mu;   //!
   TBranch        *b_myTransRFull_trans_numhits_infit;   //!
   TBranch        *b_myTransRFull_trans_chglength_nue;   //!
   TBranch        *b_myTransRFull_trans_numlowt_nue;   //!
   TBranch        *b_myTransRPi0_;   //!
   TBranch        *b_myTransRPi0_fUniqueID;   //!
   TBranch        *b_myTransRPi0_fBits;   //!
   TBranch        *b_myTransRPi0_trans_vertex_x;   //!
   TBranch        *b_myTransRPi0_trans_vertex_y;   //!
   TBranch        *b_myTransRPi0_trans_vertex_z;   //!
   TBranch        *b_myTransRPi0_trans_vertex_mag;   //!
   TBranch        *b_myTransRPi0_trans_time;   //!
   TBranch        *b_myTransRPi0_trans_Shift_1;   //!
   TBranch        *b_myTransRPi0_trans_Shift_2;   //!
   TBranch        *b_myTransRPi0_trans_dir1_x;   //!
   TBranch        *b_myTransRPi0_trans_dir1_y;   //!
   TBranch        *b_myTransRPi0_trans_dir1_z;   //!
   TBranch        *b_myTransRPi0_trans_dir1_mag;   //!
   TBranch        *b_myTransRPi0_trans_dir2_x;   //!
   TBranch        *b_myTransRPi0_trans_dir2_y;   //!
   TBranch        *b_myTransRPi0_trans_dir2_z;   //!
   TBranch        *b_myTransRPi0_trans_dir2_mag;   //!
   TBranch        *b_myTransRPi0_trans_Chg_1;   //!
   TBranch        *b_myTransRPi0_trans_Chg_2;   //!
   TBranch        *b_myTransRPi0_trans_wChg_1;   //!
   TBranch        *b_myTransRPi0_trans_wChg_2;   //!
   TBranch        *b_myTransRPi0_trans_E_1;   //!
   TBranch        *b_myTransRPi0_trans_E_2;   //!
   TBranch        *b_myTransRPi0_trans_mass;   //!
   TBranch        *b_myTransRPi0_trans_CosAng_1;   //!
   TBranch        *b_myTransRTrak_;   //!
   TBranch        *b_myTransRTrak_fUniqueID;   //!
   TBranch        *b_myTransRTrak_fBits;   //!
   TBranch        *b_myTransRTrak_trans_iter;   //!
   TBranch        *b_myTransRTrak_trans_likelihood;   //!
   TBranch        *b_myTransRTrak_trans_trklength;   //!
   TBranch        *b_myRecoCon_;   //!
   TBranch        *b_myRecoCon_fUniqueID;   //!
   TBranch        *b_myRecoCon_fBits;   //!
   TBranch        *b_myRecoCon_trkType;   //!
   TBranch        *b_myRecoCon_mass;   //!
   TBranch        *b_myRecoCon_x;   //!
   TBranch        *b_myRecoCon_y;   //!
   TBranch        *b_myRecoCon_z;   //!
   TBranch        *b_myRecoCon_ver_mag;   //!
   TBranch        *b_myRecoCon_ux;   //!
   TBranch        *b_myRecoCon_uy;   //!
   TBranch        *b_myRecoCon_uz;   //!
   TBranch        *b_myRecoCon_dir_mag;   //!
   TBranch        *b_myRecoCon_time;   //!
   TBranch        *b_myRecoCon_energy;   //!
   TBranch        *b_myRecoDisj_;   //!
   TBranch        *b_myRecoDisj_fUniqueID;   //!
   TBranch        *b_myRecoDisj_fBits;   //!
   TBranch        *b_myRecoDisj_iter;   //!
   TBranch        *b_myRecoDisj_trkType;   //!
   TBranch        *b_myRecoDisj_x;   //!
   TBranch        *b_myRecoDisj_y;   //!
   TBranch        *b_myRecoDisj_z;   //!
   TBranch        *b_myRecoDisj_ver_mag;   //!
   TBranch        *b_myRecoDisj_ux;   //!
   TBranch        *b_myRecoDisj_uy;   //!
   TBranch        *b_myRecoDisj_uz;   //!
   TBranch        *b_myRecoDisj_dir_mag;   //!
   TBranch        *b_myRecoDisj_time;   //!
   TBranch        *b_myRecoDisj_energy;   //!
   TBranch        *b_myRecoDisj_distMeanCer;   //!
   TBranch        *b_myRecoDisj_fluxScale;   //!
   TBranch        *b_myRecoDisj_relSci;   //!
   TBranch        *b_myRecoDisj_likelihood;   //!
   TBranch        *b_myRecoOneTrk_;   //!
   TBranch        *b_myRecoOneTrk_fUniqueID;   //!
   TBranch        *b_myRecoOneTrk_fBits;   //!
   TBranch        *b_myRecoOneTrk_iter;   //!
   TBranch        *b_myRecoOneTrk_trkType;   //!
   TBranch        *b_myRecoOneTrk_x;   //!
   TBranch        *b_myRecoOneTrk_y;   //!
   TBranch        *b_myRecoOneTrk_z;   //!
   TBranch        *b_myRecoOneTrk_ver_mag;   //!
   TBranch        *b_myRecoOneTrk_ux;   //!
   TBranch        *b_myRecoOneTrk_uy;   //!
   TBranch        *b_myRecoOneTrk_uz;   //!
   TBranch        *b_myRecoOneTrk_dir_mag;   //!
   TBranch        *b_myRecoOneTrk_time;   //!
   TBranch        *b_myRecoOneTrk_energy;   //!
   TBranch        *b_myRecoOneTrk_distMean;   //!
   TBranch        *b_myRecoOneTrk_fluxScale;   //!
   TBranch        *b_myRecoOneTrk_relSci;   //!
   TBranch        *b_myRecoOneTrk_likelihood;   //!
   TBranch        *b_myRecoTwoTrk_;   //!
   TBranch        *b_myRecoTwoTrk_fUniqueID;   //!
   TBranch        *b_myRecoTwoTrk_fBits;   //!
   TBranch        *b_myRecoTwoTrk_trackType1;   //!
   TBranch        *b_myRecoTwoTrk_trackType2;   //!
   TBranch        *b_myRecoTwoTrk_x;   //!
   TBranch        *b_myRecoTwoTrk_y;   //!
   TBranch        *b_myRecoTwoTrk_z;   //!
   TBranch        *b_myRecoTwoTrk_ver_mag;   //!
   TBranch        *b_myRecoTwoTrk_ux1;   //!
   TBranch        *b_myRecoTwoTrk_uy1;   //!
   TBranch        *b_myRecoTwoTrk_uz1;   //!
   TBranch        *b_myRecoTwoTrk_dir_mag1;   //!
   TBranch        *b_myRecoTwoTrk_time;   //!
   TBranch        *b_myRecoTwoTrk_mass;   //!
   TBranch        *b_myRecoTwoTrk_cosOp;   //!
   TBranch        *b_myRecoTwoTrk_energy1;   //!
   TBranch        *b_myRecoTwoTrk_distMeanCer1;   //!
   TBranch        *b_myRecoTwoTrk_distMeanCer2;   //!
   TBranch        *b_myRecoTwoTrk_convlen1;   //!
   TBranch        *b_myRecoTwoTrk_ux2;   //!
   TBranch        *b_myRecoTwoTrk_uy2;   //!
   TBranch        *b_myRecoTwoTrk_uz2;   //!
   TBranch        *b_myRecoTwoTrk_dir_mag2;   //!
   TBranch        *b_myRecoTwoTrk_energy2;   //!
   TBranch        *b_myRecoTwoTrk_convlen2;   //!
   TBranch        *b_myRecoTwoTrk_fluxScale;   //!
   TBranch        *b_myRecoTwoTrk_relSci;   //!
   TBranch        *b_myRecoTwoTrk_Qlikelihood;   //!
   TBranch        *b_myRecoTwoTrk_Tlikelihood;   //!
   TBranch        *b_myRecoTwoTrk_likelihood;   //!
   TBranch        *b_myRecoTwoTrk_fixedMass;   //!
   TBranch        *b_myRecoOneTrkMu_;   //!
   TBranch        *b_myRecoOneTrkMu_fUniqueID;   //!
   TBranch        *b_myRecoOneTrkMu_fBits;   //!
   TBranch        *b_myRecoOneTrkMu_iter;   //!
   TBranch        *b_myRecoOneTrkMu_trkType;   //!
   TBranch        *b_myRecoOneTrkMu_x;   //!
   TBranch        *b_myRecoOneTrkMu_y;   //!
   TBranch        *b_myRecoOneTrkMu_z;   //!
   TBranch        *b_myRecoOneTrkMu_ver_mag;   //!
   TBranch        *b_myRecoOneTrkMu_ux;   //!
   TBranch        *b_myRecoOneTrkMu_uy;   //!
   TBranch        *b_myRecoOneTrkMu_uz;   //!
   TBranch        *b_myRecoOneTrkMu_dir_mag;   //!
   TBranch        *b_myRecoOneTrkMu_time;   //!
   TBranch        *b_myRecoOneTrkMu_energy;   //!
   TBranch        *b_myRecoOneTrkMu_distMean;   //!
   TBranch        *b_myRecoOneTrkMu_fluxScale;   //!
   TBranch        *b_myRecoOneTrkMu_relSci;   //!
   TBranch        *b_myRecoOneTrkMu_likelihood;   //!
   TBranch        *b_myRecoTwoTrkFix_;   //!
   TBranch        *b_myRecoTwoTrkFix_fUniqueID;   //!
   TBranch        *b_myRecoTwoTrkFix_fBits;   //!
   TBranch        *b_myRecoTwoTrkFix_trackType1;   //!
   TBranch        *b_myRecoTwoTrkFix_trackType2;   //!
   TBranch        *b_myRecoTwoTrkFix_x;   //!
   TBranch        *b_myRecoTwoTrkFix_y;   //!
   TBranch        *b_myRecoTwoTrkFix_z;   //!
   TBranch        *b_myRecoTwoTrkFix_ver_mag;   //!
   TBranch        *b_myRecoTwoTrkFix_ux1;   //!
   TBranch        *b_myRecoTwoTrkFix_uy1;   //!
   TBranch        *b_myRecoTwoTrkFix_uz1;   //!
   TBranch        *b_myRecoTwoTrkFix_dir_mag1;   //!
   TBranch        *b_myRecoTwoTrkFix_time;   //!
   TBranch        *b_myRecoTwoTrkFix_mass;   //!
   TBranch        *b_myRecoTwoTrkFix_cosOp;   //!
   TBranch        *b_myRecoTwoTrkFix_energy1;   //!
   TBranch        *b_myRecoTwoTrkFix_distMeanCer1;   //!
   TBranch        *b_myRecoTwoTrkFix_distMeanCer2;   //!
   TBranch        *b_myRecoTwoTrkFix_convlen1;   //!
   TBranch        *b_myRecoTwoTrkFix_ux2;   //!
   TBranch        *b_myRecoTwoTrkFix_uy2;   //!
   TBranch        *b_myRecoTwoTrkFix_uz2;   //!
   TBranch        *b_myRecoTwoTrkFix_dir_mag2;   //!
   TBranch        *b_myRecoTwoTrkFix_energy2;   //!
   TBranch        *b_myRecoTwoTrkFix_convlen2;   //!
   TBranch        *b_myRecoTwoTrkFix_fluxScale;   //!
   TBranch        *b_myRecoTwoTrkFix_relSci;   //!
   TBranch        *b_myRecoTwoTrkFix_Qlikelihood;   //!
   TBranch        *b_myRecoTwoTrkFix_Tlikelihood;   //!
   TBranch        *b_myRecoTwoTrkFix_likelihood;   //!
   TBranch        *b_myRecoTwoTrkFix_fixedMass;   //!
   TBranch        *b_myStFast_;   //!
   TBranch        *b_myStFast_fUniqueID;   //!
   TBranch        *b_myStFast_fBits;   //!
   TBranch        *b_myStFast_iter;   //!
   TBranch        *b_myStFast_vertex_x;   //!
   TBranch        *b_myStFast_vertex_y;   //!
   TBranch        *b_myStFast_vertex_z;   //!
   TBranch        *b_myStFast_vertex_mag;   //!
   TBranch        *b_myStFast_dir_x;   //!
   TBranch        *b_myStFast_dir_y;   //!
   TBranch        *b_myStFast_dir_z;   //!
   TBranch        *b_myStFast_dir_mag;   //!
   TBranch        *b_myStFast_time;   //!
   TBranch        *b_myStFast_distance;   //!
   TBranch        *b_myStFast_energy;   //!
   TBranch        *b_myStFast_likelihood;   //!
   TBranch        *b_myStFlux_;   //!
   TBranch        *b_myStFlux_fUniqueID;   //!
   TBranch        *b_myStFlux_fBits;   //!
   TBranch        *b_myStFlux_iter;   //!
   TBranch        *b_myStFlux_likelihood;   //!
   TBranch        *b_myStFlux_cerenkov;   //!
   TBranch        *b_myStFlux_scint;   //!
   TBranch        *b_myStFlux_Ecer_el;   //!
   TBranch        *b_myStFlux_Ecer_mu;   //!
   TBranch        *b_myStFull_;   //!
   TBranch        *b_myStFull_fUniqueID;   //!
   TBranch        *b_myStFull_fBits;   //!
   TBranch        *b_myStFull_iter;   //!
   TBranch        *b_myStFull_vertex_x;   //!
   TBranch        *b_myStFull_vertex_y;   //!
   TBranch        *b_myStFull_vertex_z;   //!
   TBranch        *b_myStFull_vertex_mag;   //!
   TBranch        *b_myStFull_dir_x;   //!
   TBranch        *b_myStFull_dir_y;   //!
   TBranch        *b_myStFull_dir_z;   //!
   TBranch        *b_myStFull_dir_mag;   //!
   TBranch        *b_myStFull_time;   //!
   TBranch        *b_myStFull_distance;   //!
   TBranch        *b_myStFull_energy;   //!
   TBranch        *b_myStFull_energy_mu;   //!
   TBranch        *b_myStFull_likelihood;   //!
   TBranch        *b_myStFull_Stkint;   //!
   TBranch        *b_myStFull_RdR;   //!
   TBranch        *b_myStFull_fqlt05;   //!
   TBranch        *b_myStFull_fqlt10;   //!
   TBranch        *b_myStFull_realver_x;   //!
   TBranch        *b_myStFull_realver_y;   //!
   TBranch        *b_myStFull_realver_z;   //!
   TBranch        *b_myStFull_realver_mag;   //!
   TBranch        *b_myStFull_realver_time;   //!
   TBranch        *b_myStPi0_;   //!
   TBranch        *b_myStPi0_fUniqueID;   //!
   TBranch        *b_myStPi0_fBits;   //!
   TBranch        *b_myStPi0_iter;   //!
   TBranch        *b_myStPi0_vertex_x;   //!
   TBranch        *b_myStPi0_vertex_y;   //!
   TBranch        *b_myStPi0_vertex_z;   //!
   TBranch        *b_myStPi0_vertex_mag;   //!
   TBranch        *b_myStPi0_time;   //!
   TBranch        *b_myStPi0_likelihood;   //!
   TBranch        *b_myStPi0_mass;   //!
   TBranch        *b_myStPi0_darec;   //!
   TBranch        *b_myStPi0_fcer;   //!
   TBranch        *b_myStPi0_phi1;   //!
   TBranch        *b_myStPi0_teta1;   //!
   TBranch        *b_myStPi0_phi2;   //!
   TBranch        *b_myStPi0_teta2;   //!
   TBranch        *b_myStPi0_cer1;   //!
   TBranch        *b_myStPi0_sci1;   //!
   TBranch        *b_myStPi0_cer2;   //!
   TBranch        *b_myStPi0_sci2;   //!
   TBranch        *b_myStPi0_srec1;   //!
   TBranch        *b_myStPi0_dist1;   //!
   TBranch        *b_myStPi0_srec2;   //!
   TBranch        *b_myStPi0_dist2;   //!
   TBranch        *b_myStPi0_dir1_x;   //!
   TBranch        *b_myStPi0_dir1_y;   //!
   TBranch        *b_myStPi0_dir1_z;   //!
   TBranch        *b_myStPi0_dir1_mag;   //!
   TBranch        *b_myStPi0_dir2_x;   //!
   TBranch        *b_myStPi0_dir2_y;   //!
   TBranch        *b_myStPi0_dir2_z;   //!
   TBranch        *b_myStPi0_dir2_mag;   //!
   TBranch        *b_myStTrak_;   //!
   TBranch        *b_myStTrak_fUniqueID;   //!
   TBranch        *b_myStTrak_fBits;   //!
   TBranch        *b_myStTrak_iter;   //!
   TBranch        *b_myStTrak_likelihood;   //!
   TBranch        *b_myStTrak_trklength;   //!
   TBranch        *b_myStVarsTwo_;   //!
   TBranch        *b_myStVarsTwo_fUniqueID;   //!
   TBranch        *b_myStVarsTwo_fBits;   //!
   TBranch        *b_myStVarsTwo_CTH_n000;   //!
   TBranch        *b_myStVarsTwo_CTH_nhit;   //!
   TBranch        *b_myStVarsTwo_RS_n000;   //!
   TBranch        *b_myStVarsTwo_RS_nhit;   //!
   TBranch        *b_myStVarsTwo_TIM_nhit;   //!
   TBranch        *b_myStVarsTwo_CTH_mu;   //!
   TBranch        *b_myStVarsTwo_CTH_qrec;   //!
   TBranch        *b_myStVarsTwo_CTH_chia;   //!
   TBranch        *b_myStVarsTwo_CTH_qllk000;   //!
   TBranch        *b_myStVarsTwo_CTH_qllkhit;   //!
   TBranch        *b_myStVarsTwo_CTH_tllk;   //!
   TBranch        *b_myStVarsTwo_RS_qrec;   //!
   TBranch        *b_myStVarsTwo_RS_mu;   //!
   TBranch        *b_myStVarsTwo_TIM_qrec;   //!
   TBranch        *b_myStVarsTwo_TIM_mu;   //!

   outputTree(TTree *tree=0);
   ~outputTree();
   Int_t  Cut(Int_t entry);
   Int_t  GetEntry(Int_t entry);
   Int_t  LoadTree(Int_t entry);
   void   Init(TTree *tree);
   void   Loop();
   Bool_t Notify();
   void   Show(Int_t entry = -1);
};

#endif

#ifdef outputTree_cxx
outputTree::outputTree(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f) {
         f = new TFile("Memory Directory");
         f->cd("Rint:/");
      }
      tree = (TTree*)gDirectory->Get("outputTree");

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("outputTree","");
      chain->Add("./numi_data_five_batches.root/outputTree");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

outputTree::~outputTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t outputTree::GetEntry(Int_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Int_t outputTree::LoadTree(Int_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Int_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->IsA() != TChain::Class()) return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void outputTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses of the tree
   // will be set. It is normaly not necessary to make changes to the
   // generated code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running with PROOF.

   // Set branch addresses
   if (tree == 0) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventInfo",&eventInfo_numCrate13);
   fChain->SetBranchAddress("myHeader",&myHeader_);
   fChain->SetBranchAddress("myHeader.fUniqueID",myHeader_fUniqueID);
   fChain->SetBranchAddress("myHeader.fBits",myHeader_fBits);
   fChain->SetBranchAddress("myHeader.DAQversion",myHeader_DAQversion);
   fChain->SetBranchAddress("myHeader.RecordType",myHeader_RecordType);
   fChain->SetBranchAddress("myHeader.RecordOrigin",myHeader_RecordOrigin);
   fChain->SetBranchAddress("myHeader.NumBytes",myHeader_NumBytes);
   fChain->SetBranchAddress("myHeader.RunNumber",myHeader_RunNumber);
   fChain->SetBranchAddress("myHeader.Secs",myHeader_Secs);
   fChain->SetBranchAddress("myHeader.MilliSecs",myHeader_MilliSecs);
   fChain->SetBranchAddress("myTankHeader",&myTankHeader_);
   fChain->SetBranchAddress("myTankHeader.fUniqueID",myTankHeader_fUniqueID);
   fChain->SetBranchAddress("myTankHeader.fBits",myTankHeader_fBits);
   fChain->SetBranchAddress("myTankHeader.RunNumber",myTankHeader_RunNumber);
   fChain->SetBranchAddress("myTankHeader.EventNumber",myTankHeader_EventNumber);
   fChain->SetBranchAddress("myTankHeader.SubRunNumber",myTankHeader_SubRunNumber);
   fChain->SetBranchAddress("myTankHeader.EventType",myTankHeader_EventType);
   fChain->SetBranchAddress("myTankHeader.TrigEvNum",myTankHeader_TrigEvNum);
   fChain->SetBranchAddress("myTankHeader.TrigFifo",myTankHeader_TrigFifo);
   fChain->SetBranchAddress("myTankHeader.nTSAFifo",myTankHeader_nTSAFifo);
   fChain->SetBranchAddress("myTankHeader.GPSLower",myTankHeader_GPSLower);
   fChain->SetBranchAddress("myTankHeader.GPSUpper",myTankHeader_GPSUpper);
   fChain->SetBranchAddress("myTankHeader.TrigEvType",myTankHeader_TrigEvType);
   fChain->SetBranchAddress("myTankHeader.nTSATrig",myTankHeader_nTSATrig);
   fChain->SetBranchAddress("myTankHeader.nBCastTrig",myTankHeader_nBCastTrig);
   fChain->SetBranchAddress("myMCEvent",&myMCEvent_);
   fChain->SetBranchAddress("myMCEvent.fUniqueID",myMCEvent_fUniqueID);
   fChain->SetBranchAddress("myMCEvent.fBits",myMCEvent_fBits);
   fChain->SetBranchAddress("myMCEvent.version",myMCEvent_version);
   fChain->SetBranchAddress("myMCEvent.flags",myMCEvent_flags);
   fChain->SetBranchAddress("myMCEvent.eventNumber",myMCEvent_eventNumber);
   fChain->SetBranchAddress("myMCEvent.nuType",myMCEvent_nuType);
   fChain->SetBranchAddress("myMCEvent.nDecayPart",myMCEvent_nDecayPart);
   fChain->SetBranchAddress("myMCEvent.nFinalState",myMCEvent_nFinalState);
   fChain->SetBranchAddress("myMCEvent.nProcTags",myMCEvent_nProcTags);
   fChain->SetBranchAddress("myMCEvent.neutType",myMCEvent_neutType);
   fChain->SetBranchAddress("myMCEvent.nNeutAncest",myMCEvent_nNeutAncest);
   fChain->SetBranchAddress("myMCEvent.beamWeight",myMCEvent_beamWeight);
   fChain->SetBranchAddress("myMCEvent.nTankHits",myMCEvent_nTankHits);
   fChain->SetBranchAddress("myMCEvent.random1",myMCEvent_random1);
   fChain->SetBranchAddress("myMCEvent.random2",myMCEvent_random2);
   fChain->SetBranchAddress("myMCEvent.weight",myMCEvent_weight);
   fChain->SetBranchAddress("myMCEvent.pNu_x",myMCEvent_pNu_x);
   fChain->SetBranchAddress("myMCEvent.pNu_y",myMCEvent_pNu_y);
   fChain->SetBranchAddress("myMCEvent.pNu_z",myMCEvent_pNu_z);
   fChain->SetBranchAddress("myMCEvent.pNu_E",myMCEvent_pNu_E);
   fChain->SetBranchAddress("myMCEvent.endpt_x",myMCEvent_endpt_x);
   fChain->SetBranchAddress("myMCEvent.endpt_y",myMCEvent_endpt_y);
   fChain->SetBranchAddress("myMCEvent.endpt_z",myMCEvent_endpt_z);
   fChain->SetBranchAddress("myMCEvent.endpt_mag",myMCEvent_endpt_mag);
   fChain->SetBranchAddress("myMCEvent.proctag[63]",myMCEvent_proctag);
   fChain->SetBranchAddress("myMCParticle",&myMCParticle_);
   fChain->SetBranchAddress("myMCParticle.fUniqueID",myMCParticle_fUniqueID);
   fChain->SetBranchAddress("myMCParticle.fBits",myMCParticle_fBits);
   fChain->SetBranchAddress("myMCParticle.geantID",myMCParticle_geantID);
   fChain->SetBranchAddress("myMCParticle.nTankCer",myMCParticle_nTankCer);
   fChain->SetBranchAddress("myMCParticle.nTankScint",myMCParticle_nTankScint);
   fChain->SetBranchAddress("myMCParticle.nVetoCer",myMCParticle_nVetoCer);
   fChain->SetBranchAddress("myMCParticle.nVetoScint",myMCParticle_nVetoScint);
   fChain->SetBranchAddress("myMCParticle.time",myMCParticle_time);
   fChain->SetBranchAddress("myMCParticle.ver_x",myMCParticle_ver_x);
   fChain->SetBranchAddress("myMCParticle.ver_y",myMCParticle_ver_y);
   fChain->SetBranchAddress("myMCParticle.ver_z",myMCParticle_ver_z);
   fChain->SetBranchAddress("myMCParticle.ver_mag",myMCParticle_ver_mag);
   fChain->SetBranchAddress("myMCParticle.p_x",myMCParticle_p_x);
   fChain->SetBranchAddress("myMCParticle.p_y",myMCParticle_p_y);
   fChain->SetBranchAddress("myMCParticle.p_z",myMCParticle_p_z);
   fChain->SetBranchAddress("myMCParticle.p_E",myMCParticle_p_E);
   fChain->SetBranchAddress("myMCParticle.dir_x",myMCParticle_dir_x);
   fChain->SetBranchAddress("myMCParticle.dir_y",myMCParticle_dir_y);
   fChain->SetBranchAddress("myMCParticle.dir_z",myMCParticle_dir_z);
   fChain->SetBranchAddress("myMCParticle.dir_mag",myMCParticle_dir_mag);
   fChain->SetBranchAddress("myMCParent",&myMCParent_);
   fChain->SetBranchAddress("myMCParent.fUniqueID",myMCParent_fUniqueID);
   fChain->SetBranchAddress("myMCParent.fBits",myMCParent_fBits);
   fChain->SetBranchAddress("myMCParent.geantID",myMCParent_geantID);
   fChain->SetBranchAddress("myMCParent.initialE",myMCParent_initialE);
   fChain->SetBranchAddress("myMCParent.initialT",myMCParent_initialT);
   fChain->SetBranchAddress("myMCParent.init_x",myMCParent_init_x);
   fChain->SetBranchAddress("myMCParent.init_y",myMCParent_init_y);
   fChain->SetBranchAddress("myMCParent.init_z",myMCParent_init_z);
   fChain->SetBranchAddress("myMCParent.init_mag",myMCParent_init_mag);
   fChain->SetBranchAddress("myMCParent.init_px",myMCParent_init_px);
   fChain->SetBranchAddress("myMCParent.init_py",myMCParent_init_py);
   fChain->SetBranchAddress("myMCParent.init_pz",myMCParent_init_pz);
   fChain->SetBranchAddress("myMCParent.init_pE",myMCParent_init_pE);
   fChain->SetBranchAddress("myMCParent.fin_px",myMCParent_fin_px);
   fChain->SetBranchAddress("myMCParent.fin_py",myMCParent_fin_py);
   fChain->SetBranchAddress("myMCParent.fin_pz",myMCParent_fin_pz);
   fChain->SetBranchAddress("myMCParent.fin_pE",myMCParent_fin_pE);
   fChain->SetBranchAddress("myMCParent.fin_polx",myMCParent_fin_polx);
   fChain->SetBranchAddress("myMCParent.fin_poly",myMCParent_fin_poly);
   fChain->SetBranchAddress("myMCParent.fin_polz",myMCParent_fin_polz);
   fChain->SetBranchAddress("myMCParent.fin_polmag",myMCParent_fin_polmag);
   fChain->SetBranchAddress("myMCEventWeight",&myMCEventWeight_);
   fChain->SetBranchAddress("myMCEventWeight.fUniqueID",&myMCEventWeight_fUniqueID);
   fChain->SetBranchAddress("myMCEventWeight.fBits",&myMCEventWeight_fBits);
   fChain->SetBranchAddress("myMCEventWeight.Enu",&myMCEventWeight_Enu);
   fChain->SetBranchAddress("myMCEventWeight.Beamwgt",&myMCEventWeight_Beamwgt);
   fChain->SetBranchAddress("myMCEventWeight.NuType",&myMCEventWeight_NuType);
   fChain->SetBranchAddress("myMCEventWeight.IdImm",&myMCEventWeight_IdImm);
   fChain->SetBranchAddress("myMCEventWeight.IdProd",&myMCEventWeight_IdProd);
   fChain->SetBranchAddress("myMCEventWeight.Pneu_x",&myMCEventWeight_Pneu_x);
   fChain->SetBranchAddress("myMCEventWeight.Pneu_y",&myMCEventWeight_Pneu_y);
   fChain->SetBranchAddress("myMCEventWeight.Pneu_z",&myMCEventWeight_Pneu_z);
   fChain->SetBranchAddress("myMCEventWeight.PImm_x",&myMCEventWeight_PImm_x);
   fChain->SetBranchAddress("myMCEventWeight.PImm_y",&myMCEventWeight_PImm_y);
   fChain->SetBranchAddress("myMCEventWeight.PImm_z",&myMCEventWeight_PImm_z);
   fChain->SetBranchAddress("myMCEventWeight.PProd_x",&myMCEventWeight_PProd_x);
   fChain->SetBranchAddress("myMCEventWeight.PProd_y",&myMCEventWeight_PProd_y);
   fChain->SetBranchAddress("myMCEventWeight.PProd_z",&myMCEventWeight_PProd_z);
   fChain->SetBranchAddress("myMCEventWeight.SWpip[10]",&myMCEventWeight_SWpip);
   fChain->SetBranchAddress("myMCEventWeight.SWpim[10]",&myMCEventWeight_SWpim);
   fChain->SetBranchAddress("myMCEventWeight.SWkp[10]",&myMCEventWeight_SWkp);
   fChain->SetBranchAddress("myMCEventWeight.SWkm[10]",&myMCEventWeight_SWkm);
   fChain->SetBranchAddress("myMCEventWeight.SWk0[10]",&myMCEventWeight_SWk0);
   fChain->SetBranchAddress("myMCXsecEventWeight",&myMCXsecEventWeight_);
   fChain->SetBranchAddress("myMCXsecEventWeight.fUniqueID",&myMCXsecEventWeight_fUniqueID);
   fChain->SetBranchAddress("myMCXsecEventWeight.fBits",&myMCXsecEventWeight_fBits);
   fChain->SetBranchAddress("myMCXsecEventWeight.Pneu_xsec_x",&myMCXsecEventWeight_Pneu_xsec_x);
   fChain->SetBranchAddress("myMCXsecEventWeight.Pneu_xsec_y",&myMCXsecEventWeight_Pneu_xsec_y);
   fChain->SetBranchAddress("myMCXsecEventWeight.Pneu_xsec_z",&myMCXsecEventWeight_Pneu_xsec_z);
   fChain->SetBranchAddress("myMCXsecEventWeight.Plep_xsec_x",&myMCXsecEventWeight_Plep_xsec_x);
   fChain->SetBranchAddress("myMCXsecEventWeight.Plep_xsec_y",&myMCXsecEventWeight_Plep_xsec_y);
   fChain->SetBranchAddress("myMCXsecEventWeight.Plep_xsec_z",&myMCXsecEventWeight_Plep_xsec_z);
   fChain->SetBranchAddress("myMCXsecEventWeight.NuCh_xsec",&myMCXsecEventWeight_NuCh_xsec);
   fChain->SetBranchAddress("myMCXsecEventWeight.NuType_xsec",&myMCXsecEventWeight_NuType_xsec);
   fChain->SetBranchAddress("myMCXsecEventWeight.LepId_xsec",&myMCXsecEventWeight_LepId_xsec);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2_xsec",&myMCXsecEventWeight_Q2_xsec);
   fChain->SetBranchAddress("myMCXsecEventWeight.Enue_xsec",&myMCXsecEventWeight_Enue_xsec);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuCCQE",&myMCXsecEventWeight_EnuCCQE);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2CCQE",&myMCXsecEventWeight_Q2CCQE);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuNCEL",&myMCXsecEventWeight_EnuNCEL);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2NCEL",&myMCXsecEventWeight_Q2NCEL);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuCC1pi",&myMCXsecEventWeight_EnuCC1pi);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2CC1pi",&myMCXsecEventWeight_Q2CC1pi);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuNC1pi",&myMCXsecEventWeight_EnuNC1pi);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2NC1pi",&myMCXsecEventWeight_Q2NC1pi);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuCCnpi",&myMCXsecEventWeight_EnuCCnpi);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2CCnpi",&myMCXsecEventWeight_Q2CCnpi);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuNCnpi",&myMCXsecEventWeight_EnuNCnpi);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2NCnpi",&myMCXsecEventWeight_Q2NCnpi);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuCCDIS",&myMCXsecEventWeight_EnuCCDIS);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2CCDIS",&myMCXsecEventWeight_Q2CCDIS);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuNCDIS",&myMCXsecEventWeight_EnuNCDIS);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2NCDIS",&myMCXsecEventWeight_Q2NCDIS);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuCCCoh",&myMCXsecEventWeight_EnuCCCoh);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2CCCoh",&myMCXsecEventWeight_Q2CCCoh);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuNCCoh",&myMCXsecEventWeight_EnuNCCoh);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2NCCoh",&myMCXsecEventWeight_Q2NCCoh);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuUser1",&myMCXsecEventWeight_EnuUser1);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2User1",&myMCXsecEventWeight_Q2User1);
   fChain->SetBranchAddress("myMCXsecEventWeight.EnuUser2",&myMCXsecEventWeight_EnuUser2);
   fChain->SetBranchAddress("myMCXsecEventWeight.Q2User2",&myMCXsecEventWeight_Q2User2);
   fChain->SetBranchAddress("myMCReweightCV",&myMCReweightCV_);
   fChain->SetBranchAddress("myMCReweightCV.fUniqueID",myMCReweightCV_fUniqueID);
   fChain->SetBranchAddress("myMCReweightCV.fBits",myMCReweightCV_fBits);
   fChain->SetBranchAddress("myMCReweightCV.Ppi0",myMCReweightCV_Ppi0);
   fChain->SetBranchAddress("myMCReweightCV.Enu",myMCReweightCV_Enu);
   fChain->SetBranchAddress("myMCReweightCV.XsecWght",myMCReweightCV_XsecWght);
   fChain->SetBranchAddress("myMCReweightCV.FluxWght",myMCReweightCV_FluxWght);
   fChain->SetBranchAddress("myMCReweightCV.NuType",myMCReweightCV_NuType);
   fChain->SetBranchAddress("myMCReweightCV.NuanceCh",myMCReweightCV_NuanceCh);
   fChain->SetBranchAddress("myMCReweightCV.IdParent",myMCReweightCV_IdParent);
   fChain->SetBranchAddress("myMCReweightCV.Rad_x",myMCReweightCV_Rad_x);
   fChain->SetBranchAddress("myMCReweightCV.Rad_y",myMCReweightCV_Rad_y);
   fChain->SetBranchAddress("myMCReweightCV.Rad_z",myMCReweightCV_Rad_z);
   fChain->SetBranchAddress("myMCReweightCV.Rad_r",myMCReweightCV_Rad_r);
   fChain->SetBranchAddress("myMCReweightCV.PParent_px",myMCReweightCV_PParent_px);
   fChain->SetBranchAddress("myMCReweightCV.PParent_py",myMCReweightCV_PParent_py);
   fChain->SetBranchAddress("myMCReweightCV.PParent_pz",myMCReweightCV_PParent_pz);
   fChain->SetBranchAddress("myMCReweightCV.PParent_E",myMCReweightCV_PParent_E);
   fChain->SetBranchAddress("myMCNuanceWeight",&myMCNuanceWeight_);
   fChain->SetBranchAddress("myMCNuanceWeight.fUniqueID",&myMCNuanceWeight_fUniqueID);
   fChain->SetBranchAddress("myMCNuanceWeight.fBits",&myMCNuanceWeight_fBits);
   fChain->SetBranchAddress("myMCNuanceWeight.Weight",&myMCNuanceWeight_Weight);
   fChain->SetBranchAddress("myMCNuanceWeight.Channel",&myMCNuanceWeight_Channel);
   fChain->SetBranchAddress("myMCNuanceWeight.E_neutrino",&myMCNuanceWeight_E_neutrino);
   fChain->SetBranchAddress("myMCNuanceWeight.E_lepton",&myMCNuanceWeight_E_lepton);
   fChain->SetBranchAddress("myMCNuanceWeight.K_target",&myMCNuanceWeight_K_target);
   fChain->SetBranchAddress("myMCNuanceWeight.Qsq",&myMCNuanceWeight_Qsq);
   fChain->SetBranchAddress("myMCNuanceWeight.W",&myMCNuanceWeight_W);
   fChain->SetBranchAddress("myMCNuanceWeight.X",&myMCNuanceWeight_X);
   fChain->SetBranchAddress("myMCNuanceWeight.Y",&myMCNuanceWeight_Y);
   fChain->SetBranchAddress("myMCNuanceWeight.Phi_cm",&myMCNuanceWeight_Phi_cm);
   fChain->SetBranchAddress("myMCNuanceWeight.Cos_fermi",&myMCNuanceWeight_Cos_fermi);
   fChain->SetBranchAddress("myMCWeightDetails",&myMCWeightDetails_);
   fChain->SetBranchAddress("myMCWeightDetails.fUniqueID",myMCWeightDetails_fUniqueID);
   fChain->SetBranchAddress("myMCWeightDetails.fBits",myMCWeightDetails_fBits);
   fChain->SetBranchAddress("myMCWeightDetails.Resangle",myMCWeightDetails_Resangle);
   fChain->SetBranchAddress("myMCWeightDetails.Dirt",myMCWeightDetails_Dirt);
   fChain->SetBranchAddress("myMCWeightDetails.Pi0mom",myMCWeightDetails_Pi0mom);
   fChain->SetBranchAddress("myMCWeightDetails.Deltamom",myMCWeightDetails_Deltamom);
   fChain->SetBranchAddress("myMCWeightDetails.Pi0coh",myMCWeightDetails_Pi0coh);
   fChain->SetBranchAddress("myMCWeightDetails.Pi0res",myMCWeightDetails_Pi0res);
   fChain->SetBranchAddress("myMCWeightDetails.Nuance",myMCWeightDetails_Nuance);
   fChain->SetBranchAddress("myMCWeightDetails.Pipflux",myMCWeightDetails_Pipflux);
   fChain->SetBranchAddress("myMCWeightDetails.Pimflux",myMCWeightDetails_Pimflux);
   fChain->SetBranchAddress("myMCWeightDetails.Kpflux",myMCWeightDetails_Kpflux);
   fChain->SetBranchAddress("myMCWeightDetails.Kmflux",myMCWeightDetails_Kmflux);
   fChain->SetBranchAddress("myMCWeightDetails.K0flux",myMCWeightDetails_K0flux);
   fChain->SetBranchAddress("myMCWeightDetails.Histo",myMCWeightDetails_Histo);
   fChain->SetBranchAddress("myMCWeightDetails.Npip",myMCWeightDetails_Npip);
   fChain->SetBranchAddress("myMCWeightDetails.Totalweight",myMCWeightDetails_Totalweight);
   fChain->SetBranchAddress("myWeightArray",&myWeightArray_);
   fChain->SetBranchAddress("myWeightArray.fUniqueID",&myWeightArray_fUniqueID);
   fChain->SetBranchAddress("myWeightArray.fBits",&myWeightArray_fBits);
   fChain->SetBranchAddress("myWeightArray.Nemaqe",&myWeightArray_Nemaqe);
   fChain->SetBranchAddress("myWeightArray.Nelosf",&myWeightArray_Nelosf);
   fChain->SetBranchAddress("myWeightArray.Emaqe[50]",&myWeightArray_Emaqe);
   fChain->SetBranchAddress("myWeightArray.Elosf[50]",&myWeightArray_Elosf);
   fChain->SetBranchAddress("myWeightArray.Maelowt[50][50]",&myWeightArray_Maelowt);
   fChain->SetBranchAddress("myCalE",&myCalE_);
   fChain->SetBranchAddress("myCalE.fUniqueID",myCalE_fUniqueID);
   fChain->SetBranchAddress("myCalE.fBits",myCalE_fBits);
   fChain->SetBranchAddress("myCalE.Tlep_e",myCalE_Tlep_e);
   fChain->SetBranchAddress("myCalE.Tlep_m",myCalE_Tlep_m);
   fChain->SetBranchAddress("myCalE.Qsq_e",myCalE_Qsq_e);
   fChain->SetBranchAddress("myCalE.Qsq_m",myCalE_Qsq_m);
   fChain->SetBranchAddress("myCalE.EnuQE_e",myCalE_EnuQE_e);
   fChain->SetBranchAddress("myCalE.EnuQE_m",myCalE_EnuQE_m);
   fChain->SetBranchAddress("mysplitEvent",&mysplitEvent_);
   fChain->SetBranchAddress("mysplitEvent.fUniqueID",mysplitEvent_fUniqueID);
   fChain->SetBranchAddress("mysplitEvent.fBits",mysplitEvent_fBits);
   fChain->SetBranchAddress("mysplitEvent.nTankHits",mysplitEvent_nTankHits);
   fChain->SetBranchAddress("mysplitEvent.nVetoHits",mysplitEvent_nVetoHits);
   fChain->SetBranchAddress("mysplitEvent.nHighChgTnk",mysplitEvent_nHighChgTnk);
   fChain->SetBranchAddress("mysplitEvent.nHighChgVeto",mysplitEvent_nHighChgVeto);
   fChain->SetBranchAddress("mysplitEvent.qTot",mysplitEvent_qTot);
   fChain->SetBranchAddress("mysplitEvent.tankqTot",mysplitEvent_tankqTot);
   fChain->SetBranchAddress("mysplitEvent.vetoqTot",mysplitEvent_vetoqTot);
   fChain->SetBranchAddress("mysplitEvent.minTime",mysplitEvent_minTime);
   fChain->SetBranchAddress("mysplitEvent.maxTime",mysplitEvent_maxTime);
   fChain->SetBranchAddress("mysplitEvent.aveTimeTank",mysplitEvent_aveTimeTank);
   fChain->SetBranchAddress("mysplitEvent.peakTimeTank",mysplitEvent_peakTimeTank);
   fChain->SetBranchAddress("mysplitEvent.rmsTimeTank",mysplitEvent_rmsTimeTank);
   fChain->SetBranchAddress("mysplitEvent.aveTimeVeto",mysplitEvent_aveTimeVeto);
   fChain->SetBranchAddress("mysplitEvent.peakTimeVeto",mysplitEvent_peakTimeVeto);
   fChain->SetBranchAddress("mysplitEvent.rmsTimeVeto",mysplitEvent_rmsTimeVeto);
   fChain->SetBranchAddress("mysplitEvent.nMCparent",mysplitEvent_nMCparent);
   fChain->SetBranchAddress("mysplitEvent.nMCpart",mysplitEvent_nMCpart);
   fChain->SetBranchAddress("mysplitEvent.nPid",mysplitEvent_nPid);
   fChain->SetBranchAddress("mysplitEvent.nRFast",mysplitEvent_nRFast);
   fChain->SetBranchAddress("mysplitEvent.nRFull",mysplitEvent_nRFull);
   fChain->SetBranchAddress("mysplitEvent.nRTrak",mysplitEvent_nRTrak);
   fChain->SetBranchAddress("mysplitEvent.nRPi0",mysplitEvent_nRPi0);
   fChain->SetBranchAddress("mysplitEvent.nRFitters",mysplitEvent_nRFitters);
   fChain->SetBranchAddress("mysplitEvent.nRFittersPi0",mysplitEvent_nRFittersPi0);
   fChain->SetBranchAddress("mysplitEvent.nRYangVars",mysplitEvent_nRYangVars);
   fChain->SetBranchAddress("mysplitEvent.nRTransFull",mysplitEvent_nRTransFull);
   fChain->SetBranchAddress("mysplitEvent.nRTransTrak",mysplitEvent_nRTransTrak);
   fChain->SetBranchAddress("mysplitEvent.nRTransPi0",mysplitEvent_nRTransPi0);
   fChain->SetBranchAddress("mysplitEvent.nRTransFitters",mysplitEvent_nRTransFitters);
   fChain->SetBranchAddress("mysplitEvent.nRTransFittersPi0",mysplitEvent_nRTransFittersPi0);
   fChain->SetBranchAddress("mysplitEvent.nRTransYangVars",mysplitEvent_nRTransYangVars);
   fChain->SetBranchAddress("mysplitEvent.nSFast",mysplitEvent_nSFast);
   fChain->SetBranchAddress("mysplitEvent.nSFull",mysplitEvent_nSFull);
   fChain->SetBranchAddress("mysplitEvent.nSTrak",mysplitEvent_nSTrak);
   fChain->SetBranchAddress("mysplitEvent.nSFlux",mysplitEvent_nSFlux);
   fChain->SetBranchAddress("mysplitEvent.nSPi0",mysplitEvent_nSPi0);
   fChain->SetBranchAddress("mysplitEvent.nSVarsTwo",mysplitEvent_nSVarsTwo);
   fChain->SetBranchAddress("mysplitEvent.nRecoConst",mysplitEvent_nRecoConst);
   fChain->SetBranchAddress("mysplitEvent.nRecoDisjoint",mysplitEvent_nRecoDisjoint);
   fChain->SetBranchAddress("mysplitEvent.nRecoOneTrk",mysplitEvent_nRecoOneTrk);
   fChain->SetBranchAddress("mysplitEvent.nRecoOneTrkPred",mysplitEvent_nRecoOneTrkPred);
   fChain->SetBranchAddress("mysplitEvent.nRecoPID",mysplitEvent_nRecoPID);
   fChain->SetBranchAddress("mysplitEvent.nRecoTwoTrk",mysplitEvent_nRecoTwoTrk);
   fChain->SetBranchAddress("mysplitEvent.nRecoTwoTrkPred",mysplitEvent_nRecoTwoTrkPred);
   fChain->SetBranchAddress("mysplitEvent.nRecoTwoTrkFix",mysplitEvent_nRecoTwoTrkFix);
   fChain->SetBranchAddress("mysplitEvent.nRecoTwoTrkFlt",mysplitEvent_nRecoTwoTrkFlt);
   fChain->SetBranchAddress("myYBoostOut",&myYBoostOut_);
   fChain->SetBranchAddress("myYBoostOut.fUniqueID",myYBoostOut_fUniqueID);
   fChain->SetBranchAddress("myYBoostOut.fBits",myYBoostOut_fBits);
   fChain->SetBranchAddress("myYBoostOut.CVBoost_V172",myYBoostOut_CVBoost_V172);
   fChain->SetBranchAddress("myYBoostOut.CVBoost_V175",myYBoostOut_CVBoost_V175);
   fChain->SetBranchAddress("myYBoostOut.MBoost_V172",myYBoostOut_MBoost_V172);
   fChain->SetBranchAddress("myAll",&myAll_);
   fChain->SetBranchAddress("myAll.fUniqueID",myAll_fUniqueID);
   fChain->SetBranchAddress("myAll.fBits",myAll_fBits);
   fChain->SetBranchAddress("myAll.All_EMu_fthvl",myAll_All_EMu_fthvl);
   fChain->SetBranchAddress("myAll.All_EMu_fthvp",myAll_All_EMu_fthvp);
   fChain->SetBranchAddress("myAll.All_EMu_qlful",myAll_All_EMu_qlful);
   fChain->SetBranchAddress("myAll.All_EMu_qtmr3",myAll_All_EMu_qtmr3);
   fChain->SetBranchAddress("myAll.All_EMu_qtmr4",myAll_All_EMu_qtmr4);
   fChain->SetBranchAddress("myAll.All_EMu_rawtavg",myAll_All_EMu_rawtavg);
   fChain->SetBranchAddress("myAll.All_EMu_rawtsig",myAll_All_EMu_rawtsig);
   fChain->SetBranchAddress("myAll.All_EMu_rslvl53",myAll_All_EMu_rslvl53);
   fChain->SetBranchAddress("myAll.All_EMu_rslvl64",myAll_All_EMu_rslvl64);
   fChain->SetBranchAddress("myAll.All_EMu_tlb24",myAll_All_EMu_tlb24);
   fChain->SetBranchAddress("myAll.All_EMu_tlb45",myAll_All_EMu_tlb45);
   fChain->SetBranchAddress("myAll.All_EMu_tlful",myAll_All_EMu_tlful);
   fChain->SetBranchAddress("myAll.All_EMu_tlm22",myAll_All_EMu_tlm22);
   fChain->SetBranchAddress("myAll.All_EMu_tlsci",myAll_All_EMu_tlsci);
   fChain->SetBranchAddress("myAll.All_EMu_trak",myAll_All_EMu_trak);
   fChain->SetBranchAddress("myAll.All_EPi_angle",myAll_All_EPi_angle);
   fChain->SetBranchAddress("myAll.All_EPi_dcbeam",myAll_All_EPi_dcbeam);
   fChain->SetBranchAddress("myAll.All_EPi_dist1",myAll_All_EPi_dist1);
   fChain->SetBranchAddress("myAll.All_EPi_fcer",myAll_All_EPi_fcer);
   fChain->SetBranchAddress("myAll.All_EPi_fmdiff",myAll_All_EPi_fmdiff);
   fChain->SetBranchAddress("myAll.All_EPi_mass",myAll_All_EPi_mass);
   fChain->SetBranchAddress("myAll.All_EPi_qldiff",myAll_All_EPi_qldiff);
   fChain->SetBranchAddress("myAll.All_EPi_qtmr0",myAll_All_EPi_qtmr0);
   fChain->SetBranchAddress("myAll.All_EPi_qtmr56",myAll_All_EPi_qtmr56);
   fChain->SetBranchAddress("myAll.All_EPi_rslvl53",myAll_All_EPi_rslvl53);
   fChain->SetBranchAddress("myAll.All_EPi_rslvl64",myAll_All_EPi_rslvl64);
   fChain->SetBranchAddress("myAll.All_EPi_scratio",myAll_All_EPi_scratio);
   fChain->SetBranchAddress("myAll.All_EPi_tlb245",myAll_All_EPi_tlb245);
   fChain->SetBranchAddress("myAll.All_EPi_tlcer",myAll_All_EPi_tlcer);
   fChain->SetBranchAddress("myAll.All_EPi_tldiff",myAll_All_EPi_tldiff);
   fChain->SetBranchAddress("myAll.All_EPi_trak",myAll_All_EPi_trak);
   fChain->SetBranchAddress("myAll.All_NTank",myAll_All_NTank);
   fChain->SetBranchAddress("myAll.All_NVeto",myAll_All_NVeto);
   fChain->SetBranchAddress("myAll.All_Roe_abar",myAll_All_Roe_abar);
   fChain->SetBranchAddress("myAll.All_Roe_akurtmu",myAll_All_Roe_akurtmu);
   fChain->SetBranchAddress("myAll.All_Roe_akurtout",myAll_All_Roe_akurtout);
   fChain->SetBranchAddress("myAll.All_Roe_asigma",myAll_All_Roe_asigma);
   fChain->SetBranchAddress("myAll.All_Roe_askew",myAll_All_Roe_askew);
   fChain->SetBranchAddress("myAll.All_Roe_askewmu",myAll_All_Roe_askewmu);
   fChain->SetBranchAddress("myAll.All_Roe_avgtime",myAll_All_Roe_avgtime);
   fChain->SetBranchAddress("myAll.All_Roe_bigang",myAll_All_Roe_bigang);
   fChain->SetBranchAddress("myAll.All_Roe_cerratio",myAll_All_Roe_cerratio);
   fChain->SetBranchAddress("myAll.All_Roe_chia",myAll_All_Roe_chia);
   fChain->SetBranchAddress("myAll.All_Roe_chiae",myAll_All_Roe_chiae);
   fChain->SetBranchAddress("myAll.All_Roe_chiphi",myAll_All_Roe_chiphi);
   fChain->SetBranchAddress("myAll.All_Roe_chir",myAll_All_Roe_chir);
   fChain->SetBranchAddress("myAll.All_Roe_chira5",myAll_All_Roe_chira5);
   fChain->SetBranchAddress("myAll.All_Roe_chire",myAll_All_Roe_chire);
   fChain->SetBranchAddress("myAll.All_Roe_chisqmich",myAll_All_Roe_chisqmich);
   fChain->SetBranchAddress("myAll.All_Roe_chisqst",myAll_All_Roe_chisqst);
   fChain->SetBranchAddress("myAll.All_Roe_cosg",myAll_All_Roe_cosg);
   fChain->SetBranchAddress("myAll.All_Roe_costhc",myAll_All_Roe_costhc);
   fChain->SetBranchAddress("myAll.All_Roe_covlengthg1",myAll_All_Roe_covlengthg1);
   fChain->SetBranchAddress("myAll.All_Roe_covlengthg2",myAll_All_Roe_covlengthg2);
   fChain->SetBranchAddress("myAll.All_Roe_dtcb6",myAll_All_Roe_dtcb6);
   fChain->SetBranchAddress("myAll.All_Roe_dtcb9phit",myAll_All_Roe_dtcb9phit);
   fChain->SetBranchAddress("myAll.All_Roe_dtlb6to8phit",myAll_All_Roe_dtlb6to8phit);
   fChain->SetBranchAddress("myAll.All_Roe_dtlb8",myAll_All_Roe_dtlb8);
   fChain->SetBranchAddress("myAll.All_Roe_earlylit",myAll_All_Roe_earlylit);
   fChain->SetBranchAddress("myAll.All_Roe_energy",myAll_All_Roe_energy);
   fChain->SetBranchAddress("myAll.All_Roe_fhitcb1p9",myAll_All_Roe_fhitcb1p9);
   fChain->SetBranchAddress("myAll.All_Roe_fhitcb4p5",myAll_All_Roe_fhitcb4p5);
   fChain->SetBranchAddress("myAll.All_Roe_fhitcb9",myAll_All_Roe_fhitcb9);
   fChain->SetBranchAddress("myAll.All_Roe_fhittb3",myAll_All_Roe_fhittb3);
   fChain->SetBranchAddress("myAll.All_Roe_fhittb3p5",myAll_All_Roe_fhittb3p5);
   fChain->SetBranchAddress("myAll.All_Roe_fhittb3p8",myAll_All_Roe_fhittb3p8);
   fChain->SetBranchAddress("myAll.All_Roe_fhittb6to9",myAll_All_Roe_fhittb6to9);
   fChain->SetBranchAddress("myAll.All_Roe_fqcb1p2",myAll_All_Roe_fqcb1p2);
   fChain->SetBranchAddress("myAll.All_Roe_fqlb2p3",myAll_All_Roe_fqlb2p3);
   fChain->SetBranchAddress("myAll.All_Roe_fqtchicb4p9",myAll_All_Roe_fqtchicb4p9);
   fChain->SetBranchAddress("myAll.All_Roe_fracpmtg1",myAll_All_Roe_fracpmtg1);
   fChain->SetBranchAddress("myAll.All_Roe_fracpmtg2",myAll_All_Roe_fracpmtg2);
   fChain->SetBranchAddress("myAll.All_Roe_fracq1q2to1",myAll_All_Roe_fracq1q2to1);
   fChain->SetBranchAddress("myAll.All_Roe_fracq1to2",myAll_All_Roe_fracq1to2);
   fChain->SetBranchAddress("myAll.All_Roe_fracq2to1",myAll_All_Roe_fracq2to1);
   fChain->SetBranchAddress("myAll.All_Roe_fracqg1",myAll_All_Roe_fracqg1);
   fChain->SetBranchAddress("myAll.All_Roe_fracqg2",myAll_All_Roe_fracqg2);
   fChain->SetBranchAddress("myAll.All_Roe_fracqhitleft",myAll_All_Roe_fracqhitleft);
   fChain->SetBranchAddress("myAll.All_Roe_fracqpmteg1",myAll_All_Roe_fracqpmteg1);
   fChain->SetBranchAddress("myAll.All_Roe_fracqpmteg2",myAll_All_Roe_fracqpmteg2);
   fChain->SetBranchAddress("myAll.All_Roe_ftchicb2p7",myAll_All_Roe_ftchicb2p7);
   fChain->SetBranchAddress("myAll.All_Roe_g2cratio",myAll_All_Roe_g2cratio);
   fChain->SetBranchAddress("myAll.All_Roe_geratio",myAll_All_Roe_geratio);
   fChain->SetBranchAddress("myAll.All_Roe_latelit",myAll_All_Roe_latelit);
   fChain->SetBranchAddress("myAll.All_Roe_leftright",myAll_All_Roe_leftright);
   fChain->SetBranchAddress("myAll.All_Roe_muenergy",myAll_All_Roe_muenergy);
   fChain->SetBranchAddress("myAll.All_Roe_nbing1",myAll_All_Roe_nbing1);
   fChain->SetBranchAddress("myAll.All_Roe_nbing2",myAll_All_Roe_nbing2);
   fChain->SetBranchAddress("myAll.All_Roe_nzbing1",myAll_All_Roe_nzbing1);
   fChain->SetBranchAddress("myAll.All_Roe_nzbing2",myAll_All_Roe_nzbing2);
   fChain->SetBranchAddress("myAll.All_Roe_pi0mass",myAll_All_Roe_pi0mass);
   fChain->SetBranchAddress("myAll.All_Roe_qcb1",myAll_All_Roe_qcb1);
   fChain->SetBranchAddress("myAll.All_Roe_qfrac0",myAll_All_Roe_qfrac0);
   fChain->SetBranchAddress("myAll.All_Roe_qfrac5",myAll_All_Roe_qfrac5);
   fChain->SetBranchAddress("myAll.All_Roe_qfrac6",myAll_All_Roe_qfrac6);
   fChain->SetBranchAddress("myAll.All_Roe_qfrac8",myAll_All_Roe_qfrac8);
   fChain->SetBranchAddress("myAll.All_Roe_qfrac9",myAll_All_Roe_qfrac9);
   fChain->SetBranchAddress("myAll.All_Roe_qg1",myAll_All_Roe_qg1);
   fChain->SetBranchAddress("myAll.All_Roe_qg2",myAll_All_Roe_qg2);
   fChain->SetBranchAddress("myAll.All_Roe_qlb1",myAll_All_Roe_qlb1);
   fChain->SetBranchAddress("myAll.All_Roe_qlb1phit",myAll_All_Roe_qlb1phit);
   fChain->SetBranchAddress("myAll.All_Roe_qtchitb9pq",myAll_All_Roe_qtchitb9pq);
   fChain->SetBranchAddress("myAll.All_Roe_rdist",myAll_All_Roe_rdist);
   fChain->SetBranchAddress("myAll.All_Roe_rtowall",myAll_All_Roe_rtowall);
   fChain->SetBranchAddress("myAll.All_Roe_s2mis",myAll_All_Roe_s2mis);
   fChain->SetBranchAddress("myAll.All_Roe_sbar",myAll_All_Roe_sbar);
   fChain->SetBranchAddress("myAll.All_Roe_scratio",myAll_All_Roe_scratio);
   fChain->SetBranchAddress("myAll.All_Roe_sigbin",myAll_All_Roe_sigbin);
   fChain->SetBranchAddress("myAll.All_Roe_sigtime",myAll_All_Roe_sigtime);
   fChain->SetBranchAddress("myAll.All_Roe_skurt",myAll_All_Roe_skurt);
   fChain->SetBranchAddress("myAll.All_Roe_ssigma",myAll_All_Roe_ssigma);
   fChain->SetBranchAddress("myAll.All_Roe_sskew",myAll_All_Roe_sskew);
   fChain->SetBranchAddress("myAll.All_Roe_tave",myAll_All_Roe_tave);
   fChain->SetBranchAddress("myAll.All_Roe_tbar",myAll_All_Roe_tbar);
   fChain->SetBranchAddress("myAll.All_Roe_timekurt",myAll_All_Roe_timekurt);
   fChain->SetBranchAddress("myAll.All_Roe_tkurt",myAll_All_Roe_tkurt);
   fChain->SetBranchAddress("myAll.All_Roe_tracklength",myAll_All_Roe_tracklength);
   fChain->SetBranchAddress("myAll.All_Roe_triple",myAll_All_Roe_triple);
   fChain->SetBranchAddress("myAll.All_Roe_trpkurt",myAll_All_Roe_trpkurt);
   fChain->SetBranchAddress("myAll.All_Roe_trpsig",myAll_All_Roe_trpsig);
   fChain->SetBranchAddress("myAll.All_Roe_tsigma",myAll_All_Roe_tsigma);
   fChain->SetBranchAddress("myAll.All_Roe_tskew",myAll_All_Roe_tskew);
   fChain->SetBranchAddress("myAll.All_Roe_tslope",myAll_All_Roe_tslope);
   fChain->SetBranchAddress("myAll.All_Roe_uzg1",myAll_All_Roe_uzg1);
   fChain->SetBranchAddress("myAll.All_Roe_xintmax",myAll_All_Roe_xintmax);
   fChain->SetBranchAddress("myAll.All_Stancu_COS",myAll_All_Stancu_COS);
   fChain->SetBranchAddress("myAll.All_Stancu_E",myAll_All_Stancu_E);
   fChain->SetBranchAddress("myAll.All_Stancu_R",myAll_All_Stancu_R);
   fChain->SetBranchAddress("myAll.All_Stancu_W",myAll_All_Stancu_W);
   fChain->SetBranchAddress("myAll.All_Stancu_X",myAll_All_Stancu_X);
   fChain->SetBranchAddress("myAll.All_Stancu_Y",myAll_All_Stancu_Y);
   fChain->SetBranchAddress("myAll.All_Stancu_Z",myAll_All_Stancu_Z);
   fChain->SetBranchAddress("myAll.All_Stancu_abscerasy",myAll_All_Stancu_abscerasy);
   fChain->SetBranchAddress("myAll.All_Stancu_cerfrdiff",myAll_All_Stancu_cerfrdiff);
   fChain->SetBranchAddress("myAll.All_Stancu_chiqrec",myAll_All_Stancu_chiqrec);
   fChain->SetBranchAddress("myAll.All_Stancu_chirsqrec",myAll_All_Stancu_chirsqrec);
   fChain->SetBranchAddress("myAll.All_Stancu_dist2",myAll_All_Stancu_dist2);
   fChain->SetBranchAddress("myAll.All_Stancu_fcertflx",myAll_All_Stancu_fcertflx);
   fChain->SetBranchAddress("myAll.All_Stancu_ffast",myAll_All_Stancu_ffast);
   fChain->SetBranchAddress("myAll.All_Stancu_fflux",myAll_All_Stancu_fflux);
   fChain->SetBranchAddress("myAll.All_Stancu_ffulmffas",myAll_All_Stancu_ffulmffas);
   fChain->SetBranchAddress("myAll.All_Stancu_fn010p16",myAll_All_Stancu_fn010p16);
   fChain->SetBranchAddress("myAll.All_Stancu_fn014p16",myAll_All_Stancu_fn014p16);
   fChain->SetBranchAddress("myAll.All_Stancu_fn018m14",myAll_All_Stancu_fn018m14);
   fChain->SetBranchAddress("myAll.All_Stancu_fnh11t14",myAll_All_Stancu_fnh11t14);
   fChain->SetBranchAddress("myAll.All_Stancu_fnh1t5p1518",myAll_All_Stancu_fnh1t5p1518);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk010p13",myAll_All_Stancu_fqlk010p13);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk011p13",myAll_All_Stancu_fqlk011p13);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk012p13",myAll_All_Stancu_fqlk012p13);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk012p14",myAll_All_Stancu_fqlk012p14);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk013p14",myAll_All_Stancu_fqlk013p14);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk014p15",myAll_All_Stancu_fqlk014p15);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk016p17",myAll_All_Stancu_fqlk016p17);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlk08p13",myAll_All_Stancu_fqlk08p13);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh11p13",myAll_All_Stancu_fqlkh11p13);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh11t14",myAll_All_Stancu_fqlkh11t14);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh13p14",myAll_All_Stancu_fqlkh13p14);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh1p18",myAll_All_Stancu_fqlkh1p18);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh1t5p1518",myAll_All_Stancu_fqlkh1t5p1518);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlkh9p14",myAll_All_Stancu_fqlkh9p14);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlt05",myAll_All_Stancu_fqlt05);
   fChain->SetBranchAddress("myAll.All_Stancu_fqlt10",myAll_All_Stancu_fqlt10);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec15t16",myAll_All_Stancu_fqrec15t16);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec15t18",myAll_All_Stancu_fqrec15t18);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec15t20",myAll_All_Stancu_fqrec15t20);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec1t10",myAll_All_Stancu_fqrec1t10);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec6t10",myAll_All_Stancu_fqrec6t10);
   fChain->SetBranchAddress("myAll.All_Stancu_fqrec6t14",myAll_All_Stancu_fqrec6t14);
   fChain->SetBranchAddress("myAll.All_Stancu_frcer1",myAll_All_Stancu_frcer1);
   fChain->SetBranchAddress("myAll.All_Stancu_frcer2",myAll_All_Stancu_frcer2);
   fChain->SetBranchAddress("myAll.All_Stancu_frchia10m4",myAll_All_Stancu_frchia10m4);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhcos10m8",myAll_All_Stancu_frnhcos10m8);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhcos8",myAll_All_Stancu_frnhcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhcos8m7",myAll_All_Stancu_frnhcos8m7);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhcos9m8",myAll_All_Stancu_frnhcos9m8);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhnb8m2",myAll_All_Stancu_frnhnb8m2);
   fChain->SetBranchAddress("myAll.All_Stancu_frnhrsnb5",myAll_All_Stancu_frnhrsnb5);
   fChain->SetBranchAddress("myAll.All_Stancu_frnqcer1",myAll_All_Stancu_frnqcer1);
   fChain->SetBranchAddress("myAll.All_Stancu_frnqcer1m2",myAll_All_Stancu_frnqcer1m2);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcer1mov",myAll_All_Stancu_frqcer1mov);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos10m3",myAll_All_Stancu_frqcos10m3);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos10m8",myAll_All_Stancu_frqcos10m8);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos6m1",myAll_All_Stancu_frqcos6m1);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos8",myAll_All_Stancu_frqcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos8m3",myAll_All_Stancu_frqcos8m3);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos8m4",myAll_All_Stancu_frqcos8m4);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos8m5",myAll_All_Stancu_frqcos8m5);
   fChain->SetBranchAddress("myAll.All_Stancu_frqcos8m7",myAll_All_Stancu_frqcos8m7);
   fChain->SetBranchAddress("myAll.All_Stancu_frqlk02p16",myAll_All_Stancu_frqlk02p16);
   fChain->SetBranchAddress("myAll.All_Stancu_frqqcer1m2",myAll_All_Stancu_frqqcer1m2);
   fChain->SetBranchAddress("myAll.All_Stancu_frqqov",myAll_All_Stancu_frqqov);
   fChain->SetBranchAddress("myAll.All_Stancu_frrs6m1",myAll_All_Stancu_frrs6m1);
   fChain->SetBranchAddress("myAll.All_Stancu_frrs7m1",myAll_All_Stancu_frrs7m1);
   fChain->SetBranchAddress("myAll.All_Stancu_frrs8m1",myAll_All_Stancu_frrs8m1);
   fChain->SetBranchAddress("myAll.All_Stancu_frsn010p13",myAll_All_Stancu_frsn010p13);
   fChain->SetBranchAddress("myAll.All_Stancu_frsn010p14",myAll_All_Stancu_frsn010p14);
   fChain->SetBranchAddress("myAll.All_Stancu_frsn011",myAll_All_Stancu_frsn011);
   fChain->SetBranchAddress("myAll.All_Stancu_frsn011p14",myAll_All_Stancu_frsn011p14);
   fChain->SetBranchAddress("myAll.All_Stancu_frsn013",myAll_All_Stancu_frsn013);
   fChain->SetBranchAddress("myAll.All_Stancu_frsq14p20",myAll_All_Stancu_frsq14p20);
   fChain->SetBranchAddress("myAll.All_Stancu_fscitflx",myAll_All_Stancu_fscitflx);
   fChain->SetBranchAddress("myAll.All_Stancu_fthjl",myAll_All_Stancu_fthjl);
   fChain->SetBranchAddress("myAll.All_Stancu_fthjp",myAll_All_Stancu_fthjp);
   fChain->SetBranchAddress("myAll.All_Stancu_fthvp",myAll_All_Stancu_fthvp);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit3m2",myAll_All_Stancu_ftnhit3m2);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit3p6",myAll_All_Stancu_ftnhit3p6);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit4",myAll_All_Stancu_ftnhit4);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit4p10",myAll_All_Stancu_ftnhit4p10);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit4p5",myAll_All_Stancu_ftnhit4p5);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit4p8",myAll_All_Stancu_ftnhit4p8);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit4p9",myAll_All_Stancu_ftnhit4p9);
   fChain->SetBranchAddress("myAll.All_Stancu_ftnhit9m3",myAll_All_Stancu_ftnhit9m3);
   fChain->SetBranchAddress("myAll.All_Stancu_ftq4",myAll_All_Stancu_ftq4);
   fChain->SetBranchAddress("myAll.All_Stancu_nqovovthit",myAll_All_Stancu_nqovovthit);
   fChain->SetBranchAddress("myAll.All_Stancu_nqtmr16",myAll_All_Stancu_nqtmr16);
   fChain->SetBranchAddress("myAll.All_Stancu_nqtmr17p18",myAll_All_Stancu_nqtmr17p18);
   fChain->SetBranchAddress("myAll.All_Stancu_nqtmr18p19",myAll_All_Stancu_nqtmr18p19);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01ql1",myAll_All_Stancu_pi01ql1);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01ql2",myAll_All_Stancu_pi01ql2);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01ql3",myAll_All_Stancu_pi01ql3);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01ql4",myAll_All_Stancu_pi01ql4);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01tl2",myAll_All_Stancu_pi01tl2);
   fChain->SetBranchAddress("myAll.All_Stancu_pi01tl3",myAll_All_Stancu_pi01tl3);
   fChain->SetBranchAddress("myAll.All_Stancu_pi02fthl",myAll_All_Stancu_pi02fthl);
   fChain->SetBranchAddress("myAll.All_Stancu_pi02ql3",myAll_All_Stancu_pi02ql3);
   fChain->SetBranchAddress("myAll.All_Stancu_pi02ql4",myAll_All_Stancu_pi02ql4);
   fChain->SetBranchAddress("myAll.All_Stancu_pi02tl3",myAll_All_Stancu_pi02tl3);
   fChain->SetBranchAddress("myAll.All_Stancu_pi02tl4",myAll_All_Stancu_pi02tl4);
   fChain->SetBranchAddress("myAll.All_Stancu_qcer1ovqtot",myAll_All_Stancu_qcer1ovqtot);
   fChain->SetBranchAddress("myAll.All_Stancu_qcer2ovqtot",myAll_All_Stancu_qcer2ovqtot);
   fChain->SetBranchAddress("myAll.All_Stancu_ql0cos10",myAll_All_Stancu_ql0cos10);
   fChain->SetBranchAddress("myAll.All_Stancu_ql0cos6",myAll_All_Stancu_ql0cos6);
   fChain->SetBranchAddress("myAll.All_Stancu_ql0cos7",myAll_All_Stancu_ql0cos7);
   fChain->SetBranchAddress("myAll.All_Stancu_qlkcos3",myAll_All_Stancu_qlkcos3);
   fChain->SetBranchAddress("myAll.All_Stancu_qlkcos8",myAll_All_Stancu_qlkcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_qlph16m12",myAll_All_Stancu_qlph16m12);
   fChain->SetBranchAddress("myAll.All_Stancu_qlph16m8",myAll_All_Stancu_qlph16m8);
   fChain->SetBranchAddress("myAll.All_Stancu_qlphcos7",myAll_All_Stancu_qlphcos7);
   fChain->SetBranchAddress("myAll.All_Stancu_qlppmtcos5",myAll_All_Stancu_qlppmtcos5);
   fChain->SetBranchAddress("myAll.All_Stancu_qlppmtcos6",myAll_All_Stancu_qlppmtcos6);
   fChain->SetBranchAddress("myAll.All_Stancu_qlppmtcos8",myAll_All_Stancu_qlppmtcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_qlppmtcos8m6",myAll_All_Stancu_qlppmtcos8m6);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr0p5",myAll_All_Stancu_qtmr0p5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr4m2",myAll_All_Stancu_qtmr4m2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr4p5",myAll_All_Stancu_qtmr4p5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr5",myAll_All_Stancu_qtmr5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr5m2",myAll_All_Stancu_qtmr5m2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr5m3",myAll_All_Stancu_qtmr5m3);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr5m4",myAll_All_Stancu_qtmr5m4);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr6p7",myAll_All_Stancu_qtmr6p7);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr7m2",myAll_All_Stancu_qtmr7m2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr7m5",myAll_All_Stancu_qtmr7m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr7m6",myAll_All_Stancu_qtmr7m6);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr8m5",myAll_All_Stancu_qtmr8m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmr9m5",myAll_All_Stancu_qtmr9m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrc2",myAll_All_Stancu_qtmrc2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos10m2",myAll_All_Stancu_qtmrcos10m2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos10m5",myAll_All_Stancu_qtmrcos10m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos5m1",myAll_All_Stancu_qtmrcos5m1);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos6",myAll_All_Stancu_qtmrcos6);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos6m1",myAll_All_Stancu_qtmrcos6m1);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos7",myAll_All_Stancu_qtmrcos7);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos7m2",myAll_All_Stancu_qtmrcos7m2);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos7m5",myAll_All_Stancu_qtmrcos7m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos8",myAll_All_Stancu_qtmrcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos8m3",myAll_All_Stancu_qtmrcos8m3);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos8m5",myAll_All_Stancu_qtmrcos8m5);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos8m6",myAll_All_Stancu_qtmrcos8m6);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrcos8m7",myAll_All_Stancu_qtmrcos8m7);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrmm",myAll_All_Stancu_qtmrmm);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrpp",myAll_All_Stancu_qtmrpp);
   fChain->SetBranchAddress("myAll.All_Stancu_qtmrsnb7",myAll_All_Stancu_qtmrsnb7);
   fChain->SetBranchAddress("myAll.All_Stancu_rdr",myAll_All_Stancu_rdr);
   fChain->SetBranchAddress("myAll.All_Stancu_rslvl1p8ovq",myAll_All_Stancu_rslvl1p8ovq);
   fChain->SetBranchAddress("myAll.All_Stancu_rslvl3p9ovq",myAll_All_Stancu_rslvl3p9ovq);
   fChain->SetBranchAddress("myAll.All_Stancu_rslvl7m4ovq",myAll_All_Stancu_rslvl7m4ovq);
   fChain->SetBranchAddress("myAll.All_Stancu_rslvl8p9ovq",myAll_All_Stancu_rslvl8p9ovq);
   fChain->SetBranchAddress("myAll.All_Stancu_rslvl9m1ovq",myAll_All_Stancu_rslvl9m1ovq);
   fChain->SetBranchAddress("myAll.All_Stancu_rsqtmr13",myAll_All_Stancu_rsqtmr13);
   fChain->SetBranchAddress("myAll.All_Stancu_rsqtmr14",myAll_All_Stancu_rsqtmr14);
   fChain->SetBranchAddress("myAll.All_Stancu_rsqtmr16",myAll_All_Stancu_rsqtmr16);
   fChain->SetBranchAddress("myAll.All_Stancu_srec1",myAll_All_Stancu_srec1);
   fChain->SetBranchAddress("myAll.All_Stancu_srec2",myAll_All_Stancu_srec2);
   fChain->SetBranchAddress("myAll.All_Stancu_stint",myAll_All_Stancu_stint);
   fChain->SetBranchAddress("myAll.All_Stancu_tlfwd",myAll_All_Stancu_tlfwd);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph11p15",myAll_All_Stancu_tlph11p15);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph13p14",myAll_All_Stancu_tlph13p14);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph14p15",myAll_All_Stancu_tlph14p15);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph15p16",myAll_All_Stancu_tlph15p16);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph15p17",myAll_All_Stancu_tlph15p17);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph16",myAll_All_Stancu_tlph16);
   fChain->SetBranchAddress("myAll.All_Stancu_tlph16p17",myAll_All_Stancu_tlph16p17);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos10m8",myAll_All_Stancu_tlphcos10m8);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos10m9",myAll_All_Stancu_tlphcos10m9);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos4m1",myAll_All_Stancu_tlphcos4m1);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos5",myAll_All_Stancu_tlphcos5);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos5m1",myAll_All_Stancu_tlphcos5m1);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos6m2",myAll_All_Stancu_tlphcos6m2);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos7",myAll_All_Stancu_tlphcos7);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8",myAll_All_Stancu_tlphcos8);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m1",myAll_All_Stancu_tlphcos8m1);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m2",myAll_All_Stancu_tlphcos8m2);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m4",myAll_All_Stancu_tlphcos8m4);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m5",myAll_All_Stancu_tlphcos8m5);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m6",myAll_All_Stancu_tlphcos8m6);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos8m7",myAll_All_Stancu_tlphcos8m7);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos9m1",myAll_All_Stancu_tlphcos9m1);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos9m2",myAll_All_Stancu_tlphcos9m2);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos9m6",myAll_All_Stancu_tlphcos9m6);
   fChain->SetBranchAddress("myAll.All_Stancu_tlphcos9m7",myAll_All_Stancu_tlphcos9m7);
   fChain->SetBranchAddress("myAll.All_Stancu_trakove",myAll_All_Stancu_trakove);
   fChain->SetBranchAddress("myAll.All_Stancu_walld",myAll_All_Stancu_walld);
   fChain->SetBranchAddress("myAll.All_Roe_chg_density_nue",myAll_All_Roe_chg_density_nue);
   fChain->SetBranchAddress("myAll.All_Roe_chg_density_g1",myAll_All_Roe_chg_density_g1);
   fChain->SetBranchAddress("myAll.All_Roe_chg_density_g2",myAll_All_Roe_chg_density_g2);
   fChain->SetBranchAddress("myAll.All_Roe_numlowt_nue",myAll_All_Roe_numlowt_nue);
   fChain->SetBranchAddress("myAll.All_Roe_numlowt_g1",myAll_All_Roe_numlowt_g1);
   fChain->SetBranchAddress("myAll.All_Roe_numlowt_g2",myAll_All_Roe_numlowt_g2);
   fChain->SetBranchAddress("myAll.All_Roe_rtowall_backward",myAll_All_Roe_rtowall_backward);
   fChain->SetBranchAddress("myAll.All_Roe_rtwbv",myAll_All_Roe_rtwbv);
   fChain->SetBranchAddress("myAll.All_Roe_ur",myAll_All_Roe_ur);
   fChain->SetBranchAddress("myAll.All_Roe_urdr",myAll_All_Roe_urdr);
   fChain->SetBranchAddress("myAll.All_Pfit_log_e",myAll_All_Pfit_log_e);
   fChain->SetBranchAddress("myAll.All_Pfit_log_mu",myAll_All_Pfit_log_mu);
   fChain->SetBranchAddress("myAll.All_Pfit_log_pi",myAll_All_Pfit_log_pi);
   fChain->SetBranchAddress("myAll.All_Pfit_log_emu",myAll_All_Pfit_log_emu);
   fChain->SetBranchAddress("myAll.All_Pfit_log_epi",myAll_All_Pfit_log_epi);
   fChain->SetBranchAddress("myAll.All_Pfit_mpi",myAll_All_Pfit_mpi);
   fChain->SetBranchAddress("myAll.All_Pfit_E",myAll_All_Pfit_E);
   fChain->SetBranchAddress("myAll.All_Pfit_R",myAll_All_Pfit_R);
   fChain->SetBranchAddress("myAll.All_Pfit_UR",myAll_All_Pfit_UR);
   fChain->SetBranchAddress("myAll.All_Pfit_UZ",myAll_All_Pfit_UZ);
   fChain->SetBranchAddress("myAll.All_Pfit_URDR",myAll_All_Pfit_URDR);
   fChain->SetBranchAddress("myAll.All_Pfit_Rtwbc",myAll_All_Pfit_Rtwbc);
   fChain->SetBranchAddress("myRFast",&myRFast_);
   fChain->SetBranchAddress("myRFast.fUniqueID",myRFast_fUniqueID);
   fChain->SetBranchAddress("myRFast.fBits",myRFast_fBits);
   fChain->SetBranchAddress("myRFast.iter",myRFast_iter);
   fChain->SetBranchAddress("myRFast.likelihood",myRFast_likelihood);
   fChain->SetBranchAddress("myRFast.time",myRFast_time);
   fChain->SetBranchAddress("myRFast.vertex_x",myRFast_vertex_x);
   fChain->SetBranchAddress("myRFast.vertex_y",myRFast_vertex_y);
   fChain->SetBranchAddress("myRFast.vertex_z",myRFast_vertex_z);
   fChain->SetBranchAddress("myRFast.vertex_mag",myRFast_vertex_mag);
   fChain->SetBranchAddress("myRFull",&myRFull_);
   fChain->SetBranchAddress("myRFull.fUniqueID",myRFull_fUniqueID);
   fChain->SetBranchAddress("myRFull.fBits",myRFull_fBits);
   fChain->SetBranchAddress("myRFull.trkCent_x",myRFull_trkCent_x);
   fChain->SetBranchAddress("myRFull.trkCent_y",myRFull_trkCent_y);
   fChain->SetBranchAddress("myRFull.trkCent_z",myRFull_trkCent_z);
   fChain->SetBranchAddress("myRFull.trkCent_mag",myRFull_trkCent_mag);
   fChain->SetBranchAddress("myRFull.trkCent_time",myRFull_trkCent_time);
   fChain->SetBranchAddress("myRFull.dir_x",myRFull_dir_x);
   fChain->SetBranchAddress("myRFull.dir_y",myRFull_dir_y);
   fChain->SetBranchAddress("myRFull.dir_z",myRFull_dir_z);
   fChain->SetBranchAddress("myRFull.dir_mag",myRFull_dir_mag);
   fChain->SetBranchAddress("myRFull.length",myRFull_length);
   fChain->SetBranchAddress("myRFull.vertex_x",myRFull_vertex_x);
   fChain->SetBranchAddress("myRFull.vertex_y",myRFull_vertex_y);
   fChain->SetBranchAddress("myRFull.vertex_z",myRFull_vertex_z);
   fChain->SetBranchAddress("myRFull.vertex_mag",myRFull_vertex_mag);
   fChain->SetBranchAddress("myRFull.vertex_time",myRFull_vertex_time);
   fChain->SetBranchAddress("myRFull.chg_infit",myRFull_chg_infit);
   fChain->SetBranchAddress("myRFull.chg_wgt_infit",myRFull_chg_wgt_infit);
   fChain->SetBranchAddress("myRFull.chisq_a_infit",myRFull_chisq_a_infit);
   fChain->SetBranchAddress("myRFull.chisq_r_infit",myRFull_chisq_r_infit);
   fChain->SetBranchAddress("myRFull.weight_tot",myRFull_weight_tot);
   fChain->SetBranchAddress("myRFull.chisq_avg",myRFull_chisq_avg);
   fChain->SetBranchAddress("myRFull.rtowall",myRFull_rtowall);
   fChain->SetBranchAddress("myRFull.energy",myRFull_energy);
   fChain->SetBranchAddress("myRFull.length_mu",myRFull_length_mu);
   fChain->SetBranchAddress("myRFull.energy_mu",myRFull_energy_mu);
   fChain->SetBranchAddress("myRFull.numhits_infit",myRFull_numhits_infit);
   fChain->SetBranchAddress("myRFull.chglength_nue",myRFull_chglength_nue);
   fChain->SetBranchAddress("myRFull.amITransRoe",myRFull_amITransRoe);
   fChain->SetBranchAddress("myRPi0",&myRPi0_);
   fChain->SetBranchAddress("myRPi0.fUniqueID",myRPi0_fUniqueID);
   fChain->SetBranchAddress("myRPi0.fBits",myRPi0_fBits);
   fChain->SetBranchAddress("myRPi0.amITransRoe",myRPi0_amITransRoe);
   fChain->SetBranchAddress("myRPi0.vertex_x",myRPi0_vertex_x);
   fChain->SetBranchAddress("myRPi0.vertex_y",myRPi0_vertex_y);
   fChain->SetBranchAddress("myRPi0.vertex_z",myRPi0_vertex_z);
   fChain->SetBranchAddress("myRPi0.vertex_mag",myRPi0_vertex_mag);
   fChain->SetBranchAddress("myRPi0.time",myRPi0_time);
   fChain->SetBranchAddress("myRPi0.Shift_1",myRPi0_Shift_1);
   fChain->SetBranchAddress("myRPi0.Shift_2",myRPi0_Shift_2);
   fChain->SetBranchAddress("myRPi0.dir1_x",myRPi0_dir1_x);
   fChain->SetBranchAddress("myRPi0.dir1_y",myRPi0_dir1_y);
   fChain->SetBranchAddress("myRPi0.dir1_z",myRPi0_dir1_z);
   fChain->SetBranchAddress("myRPi0.dir1_mag",myRPi0_dir1_mag);
   fChain->SetBranchAddress("myRPi0.dir2_x",myRPi0_dir2_x);
   fChain->SetBranchAddress("myRPi0.dir2_y",myRPi0_dir2_y);
   fChain->SetBranchAddress("myRPi0.dir2_z",myRPi0_dir2_z);
   fChain->SetBranchAddress("myRPi0.dir2_mag",myRPi0_dir2_mag);
   fChain->SetBranchAddress("myRPi0.Chg_1",myRPi0_Chg_1);
   fChain->SetBranchAddress("myRPi0.Chg_2",myRPi0_Chg_2);
   fChain->SetBranchAddress("myRPi0.wChg_1",myRPi0_wChg_1);
   fChain->SetBranchAddress("myRPi0.wChg_2",myRPi0_wChg_2);
   fChain->SetBranchAddress("myRPi0.E_1",myRPi0_E_1);
   fChain->SetBranchAddress("myRPi0.E_2",myRPi0_E_2);
   fChain->SetBranchAddress("myRPi0.mass",myRPi0_mass);
   fChain->SetBranchAddress("myRPi0.CosAng_1",myRPi0_CosAng_1);
   fChain->SetBranchAddress("myRTrak",&myRTrak_);
   fChain->SetBranchAddress("myRTrak.fUniqueID",myRTrak_fUniqueID);
   fChain->SetBranchAddress("myRTrak.fBits",myRTrak_fBits);
   fChain->SetBranchAddress("myRTrak.iter",myRTrak_iter);
   fChain->SetBranchAddress("myRTrak.likelihood",myRTrak_likelihood);
   fChain->SetBranchAddress("myRTrak.trklength",myRTrak_trklength);
   fChain->SetBranchAddress("myRTrak.amITransRoe",myRTrak_amITransRoe);
   fChain->SetBranchAddress("myTransRFull",&myTransRFull_);
   fChain->SetBranchAddress("myTransRFull.fUniqueID",myTransRFull_fUniqueID);
   fChain->SetBranchAddress("myTransRFull.fBits",myTransRFull_fBits);
   fChain->SetBranchAddress("myTransRFull.trans_trkCent_x",myTransRFull_trans_trkCent_x);
   fChain->SetBranchAddress("myTransRFull.trans_trkCent_y",myTransRFull_trans_trkCent_y);
   fChain->SetBranchAddress("myTransRFull.trans_trkCent_z",myTransRFull_trans_trkCent_z);
   fChain->SetBranchAddress("myTransRFull.trans_trkCent_mag",myTransRFull_trans_trkCent_mag);
   fChain->SetBranchAddress("myTransRFull.trans_trkCent_time",myTransRFull_trans_trkCent_time);
   fChain->SetBranchAddress("myTransRFull.trans_dir_x",myTransRFull_trans_dir_x);
   fChain->SetBranchAddress("myTransRFull.trans_dir_y",myTransRFull_trans_dir_y);
   fChain->SetBranchAddress("myTransRFull.trans_dir_z",myTransRFull_trans_dir_z);
   fChain->SetBranchAddress("myTransRFull.trans_dir_mag",myTransRFull_trans_dir_mag);
   fChain->SetBranchAddress("myTransRFull.trans_length",myTransRFull_trans_length);
   fChain->SetBranchAddress("myTransRFull.trans_vertex_x",myTransRFull_trans_vertex_x);
   fChain->SetBranchAddress("myTransRFull.trans_vertex_y",myTransRFull_trans_vertex_y);
   fChain->SetBranchAddress("myTransRFull.trans_vertex_z",myTransRFull_trans_vertex_z);
   fChain->SetBranchAddress("myTransRFull.trans_vertex_mag",myTransRFull_trans_vertex_mag);
   fChain->SetBranchAddress("myTransRFull.trans_vertex_time",myTransRFull_trans_vertex_time);
   fChain->SetBranchAddress("myTransRFull.trans_chg_infit",myTransRFull_trans_chg_infit);
   fChain->SetBranchAddress("myTransRFull.trans_chg_wgt_infit",myTransRFull_trans_chg_wgt_infit);
   fChain->SetBranchAddress("myTransRFull.trans_chisq_a_infit",myTransRFull_trans_chisq_a_infit);
   fChain->SetBranchAddress("myTransRFull.trans_chisq_r_infit",myTransRFull_trans_chisq_r_infit);
   fChain->SetBranchAddress("myTransRFull.trans_weight_tot",myTransRFull_trans_weight_tot);
   fChain->SetBranchAddress("myTransRFull.trans_chisq_avg",myTransRFull_trans_chisq_avg);
   fChain->SetBranchAddress("myTransRFull.trans_rtowall",myTransRFull_trans_rtowall);
   fChain->SetBranchAddress("myTransRFull.trans_energy",myTransRFull_trans_energy);
   fChain->SetBranchAddress("myTransRFull.trans_length_mu",myTransRFull_trans_length_mu);
   fChain->SetBranchAddress("myTransRFull.trans_energy_mu",myTransRFull_trans_energy_mu);
   fChain->SetBranchAddress("myTransRFull.trans_numhits_infit",myTransRFull_trans_numhits_infit);
   fChain->SetBranchAddress("myTransRFull.trans_chglength_nue",myTransRFull_trans_chglength_nue);
   fChain->SetBranchAddress("myTransRFull.trans_numlowt_nue[10]",myTransRFull_trans_numlowt_nue);
   fChain->SetBranchAddress("myTransRPi0",&myTransRPi0_);
   fChain->SetBranchAddress("myTransRPi0.fUniqueID",myTransRPi0_fUniqueID);
   fChain->SetBranchAddress("myTransRPi0.fBits",myTransRPi0_fBits);
   fChain->SetBranchAddress("myTransRPi0.trans_vertex_x",myTransRPi0_trans_vertex_x);
   fChain->SetBranchAddress("myTransRPi0.trans_vertex_y",myTransRPi0_trans_vertex_y);
   fChain->SetBranchAddress("myTransRPi0.trans_vertex_z",myTransRPi0_trans_vertex_z);
   fChain->SetBranchAddress("myTransRPi0.trans_vertex_mag",myTransRPi0_trans_vertex_mag);
   fChain->SetBranchAddress("myTransRPi0.trans_time",myTransRPi0_trans_time);
   fChain->SetBranchAddress("myTransRPi0.trans_Shift_1",myTransRPi0_trans_Shift_1);
   fChain->SetBranchAddress("myTransRPi0.trans_Shift_2",myTransRPi0_trans_Shift_2);
   fChain->SetBranchAddress("myTransRPi0.trans_dir1_x",myTransRPi0_trans_dir1_x);
   fChain->SetBranchAddress("myTransRPi0.trans_dir1_y",myTransRPi0_trans_dir1_y);
   fChain->SetBranchAddress("myTransRPi0.trans_dir1_z",myTransRPi0_trans_dir1_z);
   fChain->SetBranchAddress("myTransRPi0.trans_dir1_mag",myTransRPi0_trans_dir1_mag);
   fChain->SetBranchAddress("myTransRPi0.trans_dir2_x",myTransRPi0_trans_dir2_x);
   fChain->SetBranchAddress("myTransRPi0.trans_dir2_y",myTransRPi0_trans_dir2_y);
   fChain->SetBranchAddress("myTransRPi0.trans_dir2_z",myTransRPi0_trans_dir2_z);
   fChain->SetBranchAddress("myTransRPi0.trans_dir2_mag",myTransRPi0_trans_dir2_mag);
   fChain->SetBranchAddress("myTransRPi0.trans_Chg_1",myTransRPi0_trans_Chg_1);
   fChain->SetBranchAddress("myTransRPi0.trans_Chg_2",myTransRPi0_trans_Chg_2);
   fChain->SetBranchAddress("myTransRPi0.trans_wChg_1",myTransRPi0_trans_wChg_1);
   fChain->SetBranchAddress("myTransRPi0.trans_wChg_2",myTransRPi0_trans_wChg_2);
   fChain->SetBranchAddress("myTransRPi0.trans_E_1",myTransRPi0_trans_E_1);
   fChain->SetBranchAddress("myTransRPi0.trans_E_2",myTransRPi0_trans_E_2);
   fChain->SetBranchAddress("myTransRPi0.trans_mass",myTransRPi0_trans_mass);
   fChain->SetBranchAddress("myTransRPi0.trans_CosAng_1",myTransRPi0_trans_CosAng_1);
   fChain->SetBranchAddress("myTransRTrak",&myTransRTrak_);
   fChain->SetBranchAddress("myTransRTrak.fUniqueID",myTransRTrak_fUniqueID);
   fChain->SetBranchAddress("myTransRTrak.fBits",myTransRTrak_fBits);
   fChain->SetBranchAddress("myTransRTrak.trans_iter",myTransRTrak_trans_iter);
   fChain->SetBranchAddress("myTransRTrak.trans_likelihood",myTransRTrak_trans_likelihood);
   fChain->SetBranchAddress("myTransRTrak.trans_trklength",myTransRTrak_trans_trklength);
   fChain->SetBranchAddress("myRecoCon",&myRecoCon_);
   fChain->SetBranchAddress("myRecoCon.fUniqueID",myRecoCon_fUniqueID);
   fChain->SetBranchAddress("myRecoCon.fBits",myRecoCon_fBits);
   fChain->SetBranchAddress("myRecoCon.trkType",myRecoCon_trkType);
   fChain->SetBranchAddress("myRecoCon.mass",myRecoCon_mass);
   fChain->SetBranchAddress("myRecoCon.x",myRecoCon_x);
   fChain->SetBranchAddress("myRecoCon.y",myRecoCon_y);
   fChain->SetBranchAddress("myRecoCon.z",myRecoCon_z);
   fChain->SetBranchAddress("myRecoCon.ver_mag",myRecoCon_ver_mag);
   fChain->SetBranchAddress("myRecoCon.ux",myRecoCon_ux);
   fChain->SetBranchAddress("myRecoCon.uy",myRecoCon_uy);
   fChain->SetBranchAddress("myRecoCon.uz",myRecoCon_uz);
   fChain->SetBranchAddress("myRecoCon.dir_mag",myRecoCon_dir_mag);
   fChain->SetBranchAddress("myRecoCon.time",myRecoCon_time);
   fChain->SetBranchAddress("myRecoCon.energy",myRecoCon_energy);
   fChain->SetBranchAddress("myRecoDisj",&myRecoDisj_);
   fChain->SetBranchAddress("myRecoDisj.fUniqueID",myRecoDisj_fUniqueID);
   fChain->SetBranchAddress("myRecoDisj.fBits",myRecoDisj_fBits);
   fChain->SetBranchAddress("myRecoDisj.iter",myRecoDisj_iter);
   fChain->SetBranchAddress("myRecoDisj.trkType[2]",myRecoDisj_trkType);
   fChain->SetBranchAddress("myRecoDisj.x[2]",myRecoDisj_x);
   fChain->SetBranchAddress("myRecoDisj.y[2]",myRecoDisj_y);
   fChain->SetBranchAddress("myRecoDisj.z[2]",myRecoDisj_z);
   fChain->SetBranchAddress("myRecoDisj.ver_mag[2]",myRecoDisj_ver_mag);
   fChain->SetBranchAddress("myRecoDisj.ux[2]",myRecoDisj_ux);
   fChain->SetBranchAddress("myRecoDisj.uy[2]",myRecoDisj_uy);
   fChain->SetBranchAddress("myRecoDisj.uz[2]",myRecoDisj_uz);
   fChain->SetBranchAddress("myRecoDisj.dir_mag[2]",myRecoDisj_dir_mag);
   fChain->SetBranchAddress("myRecoDisj.time[2]",myRecoDisj_time);
   fChain->SetBranchAddress("myRecoDisj.energy[2]",myRecoDisj_energy);
   fChain->SetBranchAddress("myRecoDisj.distMeanCer[2]",myRecoDisj_distMeanCer);
   fChain->SetBranchAddress("myRecoDisj.fluxScale",myRecoDisj_fluxScale);
   fChain->SetBranchAddress("myRecoDisj.relSci",myRecoDisj_relSci);
   fChain->SetBranchAddress("myRecoDisj.likelihood",myRecoDisj_likelihood);
   fChain->SetBranchAddress("myRecoOneTrk",&myRecoOneTrk_);
   fChain->SetBranchAddress("myRecoOneTrk.fUniqueID",myRecoOneTrk_fUniqueID);
   fChain->SetBranchAddress("myRecoOneTrk.fBits",myRecoOneTrk_fBits);
   fChain->SetBranchAddress("myRecoOneTrk.iter",myRecoOneTrk_iter);
   fChain->SetBranchAddress("myRecoOneTrk.trkType",myRecoOneTrk_trkType);
   fChain->SetBranchAddress("myRecoOneTrk.x",myRecoOneTrk_x);
   fChain->SetBranchAddress("myRecoOneTrk.y",myRecoOneTrk_y);
   fChain->SetBranchAddress("myRecoOneTrk.z",myRecoOneTrk_z);
   fChain->SetBranchAddress("myRecoOneTrk.ver_mag",myRecoOneTrk_ver_mag);
   fChain->SetBranchAddress("myRecoOneTrk.ux",myRecoOneTrk_ux);
   fChain->SetBranchAddress("myRecoOneTrk.uy",myRecoOneTrk_uy);
   fChain->SetBranchAddress("myRecoOneTrk.uz",myRecoOneTrk_uz);
   fChain->SetBranchAddress("myRecoOneTrk.dir_mag",myRecoOneTrk_dir_mag);
   fChain->SetBranchAddress("myRecoOneTrk.time",myRecoOneTrk_time);
   fChain->SetBranchAddress("myRecoOneTrk.energy",myRecoOneTrk_energy);
   fChain->SetBranchAddress("myRecoOneTrk.distMean",myRecoOneTrk_distMean);
   fChain->SetBranchAddress("myRecoOneTrk.fluxScale",myRecoOneTrk_fluxScale);
   fChain->SetBranchAddress("myRecoOneTrk.relSci",myRecoOneTrk_relSci);
   fChain->SetBranchAddress("myRecoOneTrk.likelihood",myRecoOneTrk_likelihood);
   fChain->SetBranchAddress("myRecoTwoTrk",&myRecoTwoTrk_);
   fChain->SetBranchAddress("myRecoTwoTrk.fUniqueID",myRecoTwoTrk_fUniqueID);
   fChain->SetBranchAddress("myRecoTwoTrk.fBits",myRecoTwoTrk_fBits);
   fChain->SetBranchAddress("myRecoTwoTrk.trackType1",myRecoTwoTrk_trackType1);
   fChain->SetBranchAddress("myRecoTwoTrk.trackType2",myRecoTwoTrk_trackType2);
   fChain->SetBranchAddress("myRecoTwoTrk.x",myRecoTwoTrk_x);
   fChain->SetBranchAddress("myRecoTwoTrk.y",myRecoTwoTrk_y);
   fChain->SetBranchAddress("myRecoTwoTrk.z",myRecoTwoTrk_z);
   fChain->SetBranchAddress("myRecoTwoTrk.ver_mag",myRecoTwoTrk_ver_mag);
   fChain->SetBranchAddress("myRecoTwoTrk.ux1",myRecoTwoTrk_ux1);
   fChain->SetBranchAddress("myRecoTwoTrk.uy1",myRecoTwoTrk_uy1);
   fChain->SetBranchAddress("myRecoTwoTrk.uz1",myRecoTwoTrk_uz1);
   fChain->SetBranchAddress("myRecoTwoTrk.dir_mag1",myRecoTwoTrk_dir_mag1);
   fChain->SetBranchAddress("myRecoTwoTrk.time",myRecoTwoTrk_time);
   fChain->SetBranchAddress("myRecoTwoTrk.mass",myRecoTwoTrk_mass);
   fChain->SetBranchAddress("myRecoTwoTrk.cosOp",myRecoTwoTrk_cosOp);
   fChain->SetBranchAddress("myRecoTwoTrk.energy1",myRecoTwoTrk_energy1);
   fChain->SetBranchAddress("myRecoTwoTrk.distMeanCer1",myRecoTwoTrk_distMeanCer1);
   fChain->SetBranchAddress("myRecoTwoTrk.distMeanCer2",myRecoTwoTrk_distMeanCer2);
   fChain->SetBranchAddress("myRecoTwoTrk.convlen1",myRecoTwoTrk_convlen1);
   fChain->SetBranchAddress("myRecoTwoTrk.ux2",myRecoTwoTrk_ux2);
   fChain->SetBranchAddress("myRecoTwoTrk.uy2",myRecoTwoTrk_uy2);
   fChain->SetBranchAddress("myRecoTwoTrk.uz2",myRecoTwoTrk_uz2);
   fChain->SetBranchAddress("myRecoTwoTrk.dir_mag2",myRecoTwoTrk_dir_mag2);
   fChain->SetBranchAddress("myRecoTwoTrk.energy2",myRecoTwoTrk_energy2);
   fChain->SetBranchAddress("myRecoTwoTrk.convlen2",myRecoTwoTrk_convlen2);
   fChain->SetBranchAddress("myRecoTwoTrk.fluxScale",myRecoTwoTrk_fluxScale);
   fChain->SetBranchAddress("myRecoTwoTrk.relSci",myRecoTwoTrk_relSci);
   fChain->SetBranchAddress("myRecoTwoTrk.Qlikelihood",myRecoTwoTrk_Qlikelihood);
   fChain->SetBranchAddress("myRecoTwoTrk.Tlikelihood",myRecoTwoTrk_Tlikelihood);
   fChain->SetBranchAddress("myRecoTwoTrk.likelihood",myRecoTwoTrk_likelihood);
   fChain->SetBranchAddress("myRecoTwoTrk.fixedMass",myRecoTwoTrk_fixedMass);
   fChain->SetBranchAddress("myRecoOneTrkMu",&myRecoOneTrkMu_);
   fChain->SetBranchAddress("myRecoOneTrkMu.fUniqueID",myRecoOneTrkMu_fUniqueID);
   fChain->SetBranchAddress("myRecoOneTrkMu.fBits",myRecoOneTrkMu_fBits);
   fChain->SetBranchAddress("myRecoOneTrkMu.iter",myRecoOneTrkMu_iter);
   fChain->SetBranchAddress("myRecoOneTrkMu.trkType",myRecoOneTrkMu_trkType);
   fChain->SetBranchAddress("myRecoOneTrkMu.x",myRecoOneTrkMu_x);
   fChain->SetBranchAddress("myRecoOneTrkMu.y",myRecoOneTrkMu_y);
   fChain->SetBranchAddress("myRecoOneTrkMu.z",myRecoOneTrkMu_z);
   fChain->SetBranchAddress("myRecoOneTrkMu.ver_mag",myRecoOneTrkMu_ver_mag);
   fChain->SetBranchAddress("myRecoOneTrkMu.ux",myRecoOneTrkMu_ux);
   fChain->SetBranchAddress("myRecoOneTrkMu.uy",myRecoOneTrkMu_uy);
   fChain->SetBranchAddress("myRecoOneTrkMu.uz",myRecoOneTrkMu_uz);
   fChain->SetBranchAddress("myRecoOneTrkMu.dir_mag",myRecoOneTrkMu_dir_mag);
   fChain->SetBranchAddress("myRecoOneTrkMu.time",myRecoOneTrkMu_time);
   fChain->SetBranchAddress("myRecoOneTrkMu.energy",myRecoOneTrkMu_energy);
   fChain->SetBranchAddress("myRecoOneTrkMu.distMean",myRecoOneTrkMu_distMean);
   fChain->SetBranchAddress("myRecoOneTrkMu.fluxScale",myRecoOneTrkMu_fluxScale);
   fChain->SetBranchAddress("myRecoOneTrkMu.relSci",myRecoOneTrkMu_relSci);
   fChain->SetBranchAddress("myRecoOneTrkMu.likelihood",myRecoOneTrkMu_likelihood);
   fChain->SetBranchAddress("myRecoTwoTrkFix",&myRecoTwoTrkFix_);
   fChain->SetBranchAddress("myRecoTwoTrkFix.fUniqueID",myRecoTwoTrkFix_fUniqueID);
   fChain->SetBranchAddress("myRecoTwoTrkFix.fBits",myRecoTwoTrkFix_fBits);
   fChain->SetBranchAddress("myRecoTwoTrkFix.trackType1",myRecoTwoTrkFix_trackType1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.trackType2",myRecoTwoTrkFix_trackType2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.x",myRecoTwoTrkFix_x);
   fChain->SetBranchAddress("myRecoTwoTrkFix.y",myRecoTwoTrkFix_y);
   fChain->SetBranchAddress("myRecoTwoTrkFix.z",myRecoTwoTrkFix_z);
   fChain->SetBranchAddress("myRecoTwoTrkFix.ver_mag",myRecoTwoTrkFix_ver_mag);
   fChain->SetBranchAddress("myRecoTwoTrkFix.ux1",myRecoTwoTrkFix_ux1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.uy1",myRecoTwoTrkFix_uy1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.uz1",myRecoTwoTrkFix_uz1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.dir_mag1",myRecoTwoTrkFix_dir_mag1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.time",myRecoTwoTrkFix_time);
   fChain->SetBranchAddress("myRecoTwoTrkFix.mass",myRecoTwoTrkFix_mass);
   fChain->SetBranchAddress("myRecoTwoTrkFix.cosOp",myRecoTwoTrkFix_cosOp);
   fChain->SetBranchAddress("myRecoTwoTrkFix.energy1",myRecoTwoTrkFix_energy1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.distMeanCer1",myRecoTwoTrkFix_distMeanCer1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.distMeanCer2",myRecoTwoTrkFix_distMeanCer2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.convlen1",myRecoTwoTrkFix_convlen1);
   fChain->SetBranchAddress("myRecoTwoTrkFix.ux2",myRecoTwoTrkFix_ux2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.uy2",myRecoTwoTrkFix_uy2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.uz2",myRecoTwoTrkFix_uz2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.dir_mag2",myRecoTwoTrkFix_dir_mag2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.energy2",myRecoTwoTrkFix_energy2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.convlen2",myRecoTwoTrkFix_convlen2);
   fChain->SetBranchAddress("myRecoTwoTrkFix.fluxScale",myRecoTwoTrkFix_fluxScale);
   fChain->SetBranchAddress("myRecoTwoTrkFix.relSci",myRecoTwoTrkFix_relSci);
   fChain->SetBranchAddress("myRecoTwoTrkFix.Qlikelihood",myRecoTwoTrkFix_Qlikelihood);
   fChain->SetBranchAddress("myRecoTwoTrkFix.Tlikelihood",myRecoTwoTrkFix_Tlikelihood);
   fChain->SetBranchAddress("myRecoTwoTrkFix.likelihood",myRecoTwoTrkFix_likelihood);
   fChain->SetBranchAddress("myRecoTwoTrkFix.fixedMass",myRecoTwoTrkFix_fixedMass);
   fChain->SetBranchAddress("myStFast",&myStFast_);
   fChain->SetBranchAddress("myStFast.fUniqueID",myStFast_fUniqueID);
   fChain->SetBranchAddress("myStFast.fBits",myStFast_fBits);
   fChain->SetBranchAddress("myStFast.iter",myStFast_iter);
   fChain->SetBranchAddress("myStFast.vertex_x",myStFast_vertex_x);
   fChain->SetBranchAddress("myStFast.vertex_y",myStFast_vertex_y);
   fChain->SetBranchAddress("myStFast.vertex_z",myStFast_vertex_z);
   fChain->SetBranchAddress("myStFast.vertex_mag",myStFast_vertex_mag);
   fChain->SetBranchAddress("myStFast.dir_x",myStFast_dir_x);
   fChain->SetBranchAddress("myStFast.dir_y",myStFast_dir_y);
   fChain->SetBranchAddress("myStFast.dir_z",myStFast_dir_z);
   fChain->SetBranchAddress("myStFast.dir_mag",myStFast_dir_mag);
   fChain->SetBranchAddress("myStFast.time",myStFast_time);
   fChain->SetBranchAddress("myStFast.distance",myStFast_distance);
   fChain->SetBranchAddress("myStFast.energy",myStFast_energy);
   fChain->SetBranchAddress("myStFast.likelihood",myStFast_likelihood);
   fChain->SetBranchAddress("myStFlux",&myStFlux_);
   fChain->SetBranchAddress("myStFlux.fUniqueID",myStFlux_fUniqueID);
   fChain->SetBranchAddress("myStFlux.fBits",myStFlux_fBits);
   fChain->SetBranchAddress("myStFlux.iter",myStFlux_iter);
   fChain->SetBranchAddress("myStFlux.likelihood",myStFlux_likelihood);
   fChain->SetBranchAddress("myStFlux.cerenkov",myStFlux_cerenkov);
   fChain->SetBranchAddress("myStFlux.scint",myStFlux_scint);
   fChain->SetBranchAddress("myStFlux.Ecer_el",myStFlux_Ecer_el);
   fChain->SetBranchAddress("myStFlux.Ecer_mu",myStFlux_Ecer_mu);
   fChain->SetBranchAddress("myStFull",&myStFull_);
   fChain->SetBranchAddress("myStFull.fUniqueID",myStFull_fUniqueID);
   fChain->SetBranchAddress("myStFull.fBits",myStFull_fBits);
   fChain->SetBranchAddress("myStFull.iter",myStFull_iter);
   fChain->SetBranchAddress("myStFull.vertex_x",myStFull_vertex_x);
   fChain->SetBranchAddress("myStFull.vertex_y",myStFull_vertex_y);
   fChain->SetBranchAddress("myStFull.vertex_z",myStFull_vertex_z);
   fChain->SetBranchAddress("myStFull.vertex_mag",myStFull_vertex_mag);
   fChain->SetBranchAddress("myStFull.dir_x",myStFull_dir_x);
   fChain->SetBranchAddress("myStFull.dir_y",myStFull_dir_y);
   fChain->SetBranchAddress("myStFull.dir_z",myStFull_dir_z);
   fChain->SetBranchAddress("myStFull.dir_mag",myStFull_dir_mag);
   fChain->SetBranchAddress("myStFull.time",myStFull_time);
   fChain->SetBranchAddress("myStFull.distance",myStFull_distance);
   fChain->SetBranchAddress("myStFull.energy",myStFull_energy);
   fChain->SetBranchAddress("myStFull.energy_mu",myStFull_energy_mu);
   fChain->SetBranchAddress("myStFull.likelihood",myStFull_likelihood);
   fChain->SetBranchAddress("myStFull.Stkint",myStFull_Stkint);
   fChain->SetBranchAddress("myStFull.RdR",myStFull_RdR);
   fChain->SetBranchAddress("myStFull.fqlt05",myStFull_fqlt05);
   fChain->SetBranchAddress("myStFull.fqlt10",myStFull_fqlt10);
   fChain->SetBranchAddress("myStFull.realver_x",myStFull_realver_x);
   fChain->SetBranchAddress("myStFull.realver_y",myStFull_realver_y);
   fChain->SetBranchAddress("myStFull.realver_z",myStFull_realver_z);
   fChain->SetBranchAddress("myStFull.realver_mag",myStFull_realver_mag);
   fChain->SetBranchAddress("myStFull.realver_time",myStFull_realver_time);
   fChain->SetBranchAddress("myStPi0",&myStPi0_);
   fChain->SetBranchAddress("myStPi0.fUniqueID",myStPi0_fUniqueID);
   fChain->SetBranchAddress("myStPi0.fBits",myStPi0_fBits);
   fChain->SetBranchAddress("myStPi0.iter",myStPi0_iter);
   fChain->SetBranchAddress("myStPi0.vertex_x",myStPi0_vertex_x);
   fChain->SetBranchAddress("myStPi0.vertex_y",myStPi0_vertex_y);
   fChain->SetBranchAddress("myStPi0.vertex_z",myStPi0_vertex_z);
   fChain->SetBranchAddress("myStPi0.vertex_mag",myStPi0_vertex_mag);
   fChain->SetBranchAddress("myStPi0.time",myStPi0_time);
   fChain->SetBranchAddress("myStPi0.likelihood",myStPi0_likelihood);
   fChain->SetBranchAddress("myStPi0.mass",myStPi0_mass);
   fChain->SetBranchAddress("myStPi0.darec",myStPi0_darec);
   fChain->SetBranchAddress("myStPi0.fcer",myStPi0_fcer);
   fChain->SetBranchAddress("myStPi0.phi1",myStPi0_phi1);
   fChain->SetBranchAddress("myStPi0.teta1",myStPi0_teta1);
   fChain->SetBranchAddress("myStPi0.phi2",myStPi0_phi2);
   fChain->SetBranchAddress("myStPi0.teta2",myStPi0_teta2);
   fChain->SetBranchAddress("myStPi0.cer1",myStPi0_cer1);
   fChain->SetBranchAddress("myStPi0.sci1",myStPi0_sci1);
   fChain->SetBranchAddress("myStPi0.cer2",myStPi0_cer2);
   fChain->SetBranchAddress("myStPi0.sci2",myStPi0_sci2);
   fChain->SetBranchAddress("myStPi0.srec1",myStPi0_srec1);
   fChain->SetBranchAddress("myStPi0.dist1",myStPi0_dist1);
   fChain->SetBranchAddress("myStPi0.srec2",myStPi0_srec2);
   fChain->SetBranchAddress("myStPi0.dist2",myStPi0_dist2);
   fChain->SetBranchAddress("myStPi0.dir1_x",myStPi0_dir1_x);
   fChain->SetBranchAddress("myStPi0.dir1_y",myStPi0_dir1_y);
   fChain->SetBranchAddress("myStPi0.dir1_z",myStPi0_dir1_z);
   fChain->SetBranchAddress("myStPi0.dir1_mag",myStPi0_dir1_mag);
   fChain->SetBranchAddress("myStPi0.dir2_x",myStPi0_dir2_x);
   fChain->SetBranchAddress("myStPi0.dir2_y",myStPi0_dir2_y);
   fChain->SetBranchAddress("myStPi0.dir2_z",myStPi0_dir2_z);
   fChain->SetBranchAddress("myStPi0.dir2_mag",myStPi0_dir2_mag);
   fChain->SetBranchAddress("myStTrak",&myStTrak_);
   fChain->SetBranchAddress("myStTrak.fUniqueID",myStTrak_fUniqueID);
   fChain->SetBranchAddress("myStTrak.fBits",myStTrak_fBits);
   fChain->SetBranchAddress("myStTrak.iter",myStTrak_iter);
   fChain->SetBranchAddress("myStTrak.likelihood",myStTrak_likelihood);
   fChain->SetBranchAddress("myStTrak.trklength",myStTrak_trklength);
   fChain->SetBranchAddress("myStVarsTwo",&myStVarsTwo_);
   fChain->SetBranchAddress("myStVarsTwo.fUniqueID",myStVarsTwo_fUniqueID);
   fChain->SetBranchAddress("myStVarsTwo.fBits",myStVarsTwo_fBits);
   fChain->SetBranchAddress("myStVarsTwo.CTH_n000[20]",myStVarsTwo_CTH_n000);
   fChain->SetBranchAddress("myStVarsTwo.CTH_nhit[20]",myStVarsTwo_CTH_nhit);
   fChain->SetBranchAddress("myStVarsTwo.RS_n000[20]",myStVarsTwo_RS_n000);
   fChain->SetBranchAddress("myStVarsTwo.RS_nhit[20]",myStVarsTwo_RS_nhit);
   fChain->SetBranchAddress("myStVarsTwo.TIM_nhit[10]",myStVarsTwo_TIM_nhit);
   fChain->SetBranchAddress("myStVarsTwo.CTH_mu[20]",myStVarsTwo_CTH_mu);
   fChain->SetBranchAddress("myStVarsTwo.CTH_qrec[20]",myStVarsTwo_CTH_qrec);
   fChain->SetBranchAddress("myStVarsTwo.CTH_chia[20]",myStVarsTwo_CTH_chia);
   fChain->SetBranchAddress("myStVarsTwo.CTH_qllk000[20]",myStVarsTwo_CTH_qllk000);
   fChain->SetBranchAddress("myStVarsTwo.CTH_qllkhit[20]",myStVarsTwo_CTH_qllkhit);
   fChain->SetBranchAddress("myStVarsTwo.CTH_tllk[20]",myStVarsTwo_CTH_tllk);
   fChain->SetBranchAddress("myStVarsTwo.RS_qrec[20]",myStVarsTwo_RS_qrec);
   fChain->SetBranchAddress("myStVarsTwo.RS_mu[20]",myStVarsTwo_RS_mu);
   fChain->SetBranchAddress("myStVarsTwo.TIM_qrec[10]",myStVarsTwo_TIM_qrec);
   fChain->SetBranchAddress("myStVarsTwo.TIM_mu[10]",myStVarsTwo_TIM_mu);
   Notify();
}

Bool_t outputTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. Typically here the branch pointers
   // will be retrieved. It is normaly not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed.

   // Get branch pointers
   b_eventInfo = fChain->GetBranch("eventInfo");
   b_myHeader_ = fChain->GetBranch("myHeader");
   b_myHeader_fUniqueID = fChain->GetBranch("myHeader.fUniqueID");
   b_myHeader_fBits = fChain->GetBranch("myHeader.fBits");
   b_myHeader_DAQversion = fChain->GetBranch("myHeader.DAQversion");
   b_myHeader_RecordType = fChain->GetBranch("myHeader.RecordType");
   b_myHeader_RecordOrigin = fChain->GetBranch("myHeader.RecordOrigin");
   b_myHeader_NumBytes = fChain->GetBranch("myHeader.NumBytes");
   b_myHeader_RunNumber = fChain->GetBranch("myHeader.RunNumber");
   b_myHeader_Secs = fChain->GetBranch("myHeader.Secs");
   b_myHeader_MilliSecs = fChain->GetBranch("myHeader.MilliSecs");
   b_myTankHeader_ = fChain->GetBranch("myTankHeader");
   b_myTankHeader_fUniqueID = fChain->GetBranch("myTankHeader.fUniqueID");
   b_myTankHeader_fBits = fChain->GetBranch("myTankHeader.fBits");
   b_myTankHeader_RunNumber = fChain->GetBranch("myTankHeader.RunNumber");
   b_myTankHeader_EventNumber = fChain->GetBranch("myTankHeader.EventNumber");
   b_myTankHeader_SubRunNumber = fChain->GetBranch("myTankHeader.SubRunNumber");
   b_myTankHeader_EventType = fChain->GetBranch("myTankHeader.EventType");
   b_myTankHeader_TrigEvNum = fChain->GetBranch("myTankHeader.TrigEvNum");
   b_myTankHeader_TrigFifo = fChain->GetBranch("myTankHeader.TrigFifo");
   b_myTankHeader_nTSAFifo = fChain->GetBranch("myTankHeader.nTSAFifo");
   b_myTankHeader_GPSLower = fChain->GetBranch("myTankHeader.GPSLower");
   b_myTankHeader_GPSUpper = fChain->GetBranch("myTankHeader.GPSUpper");
   b_myTankHeader_TrigEvType = fChain->GetBranch("myTankHeader.TrigEvType");
   b_myTankHeader_nTSATrig = fChain->GetBranch("myTankHeader.nTSATrig");
   b_myTankHeader_nBCastTrig = fChain->GetBranch("myTankHeader.nBCastTrig");
   b_myMCEvent_ = fChain->GetBranch("myMCEvent");
   b_myMCEvent_fUniqueID = fChain->GetBranch("myMCEvent.fUniqueID");
   b_myMCEvent_fBits = fChain->GetBranch("myMCEvent.fBits");
   b_myMCEvent_version = fChain->GetBranch("myMCEvent.version");
   b_myMCEvent_flags = fChain->GetBranch("myMCEvent.flags");
   b_myMCEvent_eventNumber = fChain->GetBranch("myMCEvent.eventNumber");
   b_myMCEvent_nuType = fChain->GetBranch("myMCEvent.nuType");
   b_myMCEvent_nDecayPart = fChain->GetBranch("myMCEvent.nDecayPart");
   b_myMCEvent_nFinalState = fChain->GetBranch("myMCEvent.nFinalState");
   b_myMCEvent_nProcTags = fChain->GetBranch("myMCEvent.nProcTags");
   b_myMCEvent_neutType = fChain->GetBranch("myMCEvent.neutType");
   b_myMCEvent_nNeutAncest = fChain->GetBranch("myMCEvent.nNeutAncest");
   b_myMCEvent_beamWeight = fChain->GetBranch("myMCEvent.beamWeight");
   b_myMCEvent_nTankHits = fChain->GetBranch("myMCEvent.nTankHits");
   b_myMCEvent_random1 = fChain->GetBranch("myMCEvent.random1");
   b_myMCEvent_random2 = fChain->GetBranch("myMCEvent.random2");
   b_myMCEvent_weight = fChain->GetBranch("myMCEvent.weight");
   b_myMCEvent_pNu_x = fChain->GetBranch("myMCEvent.pNu_x");
   b_myMCEvent_pNu_y = fChain->GetBranch("myMCEvent.pNu_y");
   b_myMCEvent_pNu_z = fChain->GetBranch("myMCEvent.pNu_z");
   b_myMCEvent_pNu_E = fChain->GetBranch("myMCEvent.pNu_E");
   b_myMCEvent_endpt_x = fChain->GetBranch("myMCEvent.endpt_x");
   b_myMCEvent_endpt_y = fChain->GetBranch("myMCEvent.endpt_y");
   b_myMCEvent_endpt_z = fChain->GetBranch("myMCEvent.endpt_z");
   b_myMCEvent_endpt_mag = fChain->GetBranch("myMCEvent.endpt_mag");
   b_myMCEvent_proctag = fChain->GetBranch("myMCEvent.proctag[63]");
   b_myMCParticle_ = fChain->GetBranch("myMCParticle");
   b_myMCParticle_fUniqueID = fChain->GetBranch("myMCParticle.fUniqueID");
   b_myMCParticle_fBits = fChain->GetBranch("myMCParticle.fBits");
   b_myMCParticle_geantID = fChain->GetBranch("myMCParticle.geantID");
   b_myMCParticle_nTankCer = fChain->GetBranch("myMCParticle.nTankCer");
   b_myMCParticle_nTankScint = fChain->GetBranch("myMCParticle.nTankScint");
   b_myMCParticle_nVetoCer = fChain->GetBranch("myMCParticle.nVetoCer");
   b_myMCParticle_nVetoScint = fChain->GetBranch("myMCParticle.nVetoScint");
   b_myMCParticle_time = fChain->GetBranch("myMCParticle.time");
   b_myMCParticle_ver_x = fChain->GetBranch("myMCParticle.ver_x");
   b_myMCParticle_ver_y = fChain->GetBranch("myMCParticle.ver_y");
   b_myMCParticle_ver_z = fChain->GetBranch("myMCParticle.ver_z");
   b_myMCParticle_ver_mag = fChain->GetBranch("myMCParticle.ver_mag");
   b_myMCParticle_p_x = fChain->GetBranch("myMCParticle.p_x");
   b_myMCParticle_p_y = fChain->GetBranch("myMCParticle.p_y");
   b_myMCParticle_p_z = fChain->GetBranch("myMCParticle.p_z");
   b_myMCParticle_p_E = fChain->GetBranch("myMCParticle.p_E");
   b_myMCParticle_dir_x = fChain->GetBranch("myMCParticle.dir_x");
   b_myMCParticle_dir_y = fChain->GetBranch("myMCParticle.dir_y");
   b_myMCParticle_dir_z = fChain->GetBranch("myMCParticle.dir_z");
   b_myMCParticle_dir_mag = fChain->GetBranch("myMCParticle.dir_mag");
   b_myMCParent_ = fChain->GetBranch("myMCParent");
   b_myMCParent_fUniqueID = fChain->GetBranch("myMCParent.fUniqueID");
   b_myMCParent_fBits = fChain->GetBranch("myMCParent.fBits");
   b_myMCParent_geantID = fChain->GetBranch("myMCParent.geantID");
   b_myMCParent_initialE = fChain->GetBranch("myMCParent.initialE");
   b_myMCParent_initialT = fChain->GetBranch("myMCParent.initialT");
   b_myMCParent_init_x = fChain->GetBranch("myMCParent.init_x");
   b_myMCParent_init_y = fChain->GetBranch("myMCParent.init_y");
   b_myMCParent_init_z = fChain->GetBranch("myMCParent.init_z");
   b_myMCParent_init_mag = fChain->GetBranch("myMCParent.init_mag");
   b_myMCParent_init_px = fChain->GetBranch("myMCParent.init_px");
   b_myMCParent_init_py = fChain->GetBranch("myMCParent.init_py");
   b_myMCParent_init_pz = fChain->GetBranch("myMCParent.init_pz");
   b_myMCParent_init_pE = fChain->GetBranch("myMCParent.init_pE");
   b_myMCParent_fin_px = fChain->GetBranch("myMCParent.fin_px");
   b_myMCParent_fin_py = fChain->GetBranch("myMCParent.fin_py");
   b_myMCParent_fin_pz = fChain->GetBranch("myMCParent.fin_pz");
   b_myMCParent_fin_pE = fChain->GetBranch("myMCParent.fin_pE");
   b_myMCParent_fin_polx = fChain->GetBranch("myMCParent.fin_polx");
   b_myMCParent_fin_poly = fChain->GetBranch("myMCParent.fin_poly");
   b_myMCParent_fin_polz = fChain->GetBranch("myMCParent.fin_polz");
   b_myMCParent_fin_polmag = fChain->GetBranch("myMCParent.fin_polmag");
   b_myMCEventWeight_ = fChain->GetBranch("myMCEventWeight");
   b_myMCEventWeight_fUniqueID = fChain->GetBranch("myMCEventWeight.fUniqueID");
   b_myMCEventWeight_fBits = fChain->GetBranch("myMCEventWeight.fBits");
   b_myMCEventWeight_Enu = fChain->GetBranch("myMCEventWeight.Enu");
   b_myMCEventWeight_Beamwgt = fChain->GetBranch("myMCEventWeight.Beamwgt");
   b_myMCEventWeight_NuType = fChain->GetBranch("myMCEventWeight.NuType");
   b_myMCEventWeight_IdImm = fChain->GetBranch("myMCEventWeight.IdImm");
   b_myMCEventWeight_IdProd = fChain->GetBranch("myMCEventWeight.IdProd");
   b_myMCEventWeight_Pneu_x = fChain->GetBranch("myMCEventWeight.Pneu_x");
   b_myMCEventWeight_Pneu_y = fChain->GetBranch("myMCEventWeight.Pneu_y");
   b_myMCEventWeight_Pneu_z = fChain->GetBranch("myMCEventWeight.Pneu_z");
   b_myMCEventWeight_PImm_x = fChain->GetBranch("myMCEventWeight.PImm_x");
   b_myMCEventWeight_PImm_y = fChain->GetBranch("myMCEventWeight.PImm_y");
   b_myMCEventWeight_PImm_z = fChain->GetBranch("myMCEventWeight.PImm_z");
   b_myMCEventWeight_PProd_x = fChain->GetBranch("myMCEventWeight.PProd_x");
   b_myMCEventWeight_PProd_y = fChain->GetBranch("myMCEventWeight.PProd_y");
   b_myMCEventWeight_PProd_z = fChain->GetBranch("myMCEventWeight.PProd_z");
   b_myMCEventWeight_SWpip = fChain->GetBranch("myMCEventWeight.SWpip[10]");
   b_myMCEventWeight_SWpim = fChain->GetBranch("myMCEventWeight.SWpim[10]");
   b_myMCEventWeight_SWkp = fChain->GetBranch("myMCEventWeight.SWkp[10]");
   b_myMCEventWeight_SWkm = fChain->GetBranch("myMCEventWeight.SWkm[10]");
   b_myMCEventWeight_SWk0 = fChain->GetBranch("myMCEventWeight.SWk0[10]");
   b_myMCXsecEventWeight_ = fChain->GetBranch("myMCXsecEventWeight");
   b_myMCXsecEventWeight_fUniqueID = fChain->GetBranch("myMCXsecEventWeight.fUniqueID");
   b_myMCXsecEventWeight_fBits = fChain->GetBranch("myMCXsecEventWeight.fBits");
   b_myMCXsecEventWeight_Pneu_xsec_x = fChain->GetBranch("myMCXsecEventWeight.Pneu_xsec_x");
   b_myMCXsecEventWeight_Pneu_xsec_y = fChain->GetBranch("myMCXsecEventWeight.Pneu_xsec_y");
   b_myMCXsecEventWeight_Pneu_xsec_z = fChain->GetBranch("myMCXsecEventWeight.Pneu_xsec_z");
   b_myMCXsecEventWeight_Plep_xsec_x = fChain->GetBranch("myMCXsecEventWeight.Plep_xsec_x");
   b_myMCXsecEventWeight_Plep_xsec_y = fChain->GetBranch("myMCXsecEventWeight.Plep_xsec_y");
   b_myMCXsecEventWeight_Plep_xsec_z = fChain->GetBranch("myMCXsecEventWeight.Plep_xsec_z");
   b_myMCXsecEventWeight_NuCh_xsec = fChain->GetBranch("myMCXsecEventWeight.NuCh_xsec");
   b_myMCXsecEventWeight_NuType_xsec = fChain->GetBranch("myMCXsecEventWeight.NuType_xsec");
   b_myMCXsecEventWeight_LepId_xsec = fChain->GetBranch("myMCXsecEventWeight.LepId_xsec");
   b_myMCXsecEventWeight_Q2_xsec = fChain->GetBranch("myMCXsecEventWeight.Q2_xsec");
   b_myMCXsecEventWeight_Enue_xsec = fChain->GetBranch("myMCXsecEventWeight.Enue_xsec");
   b_myMCXsecEventWeight_EnuCCQE = fChain->GetBranch("myMCXsecEventWeight.EnuCCQE");
   b_myMCXsecEventWeight_Q2CCQE = fChain->GetBranch("myMCXsecEventWeight.Q2CCQE");
   b_myMCXsecEventWeight_EnuNCEL = fChain->GetBranch("myMCXsecEventWeight.EnuNCEL");
   b_myMCXsecEventWeight_Q2NCEL = fChain->GetBranch("myMCXsecEventWeight.Q2NCEL");
   b_myMCXsecEventWeight_EnuCC1pi = fChain->GetBranch("myMCXsecEventWeight.EnuCC1pi");
   b_myMCXsecEventWeight_Q2CC1pi = fChain->GetBranch("myMCXsecEventWeight.Q2CC1pi");
   b_myMCXsecEventWeight_EnuNC1pi = fChain->GetBranch("myMCXsecEventWeight.EnuNC1pi");
   b_myMCXsecEventWeight_Q2NC1pi = fChain->GetBranch("myMCXsecEventWeight.Q2NC1pi");
   b_myMCXsecEventWeight_EnuCCnpi = fChain->GetBranch("myMCXsecEventWeight.EnuCCnpi");
   b_myMCXsecEventWeight_Q2CCnpi = fChain->GetBranch("myMCXsecEventWeight.Q2CCnpi");
   b_myMCXsecEventWeight_EnuNCnpi = fChain->GetBranch("myMCXsecEventWeight.EnuNCnpi");
   b_myMCXsecEventWeight_Q2NCnpi = fChain->GetBranch("myMCXsecEventWeight.Q2NCnpi");
   b_myMCXsecEventWeight_EnuCCDIS = fChain->GetBranch("myMCXsecEventWeight.EnuCCDIS");
   b_myMCXsecEventWeight_Q2CCDIS = fChain->GetBranch("myMCXsecEventWeight.Q2CCDIS");
   b_myMCXsecEventWeight_EnuNCDIS = fChain->GetBranch("myMCXsecEventWeight.EnuNCDIS");
   b_myMCXsecEventWeight_Q2NCDIS = fChain->GetBranch("myMCXsecEventWeight.Q2NCDIS");
   b_myMCXsecEventWeight_EnuCCCoh = fChain->GetBranch("myMCXsecEventWeight.EnuCCCoh");
   b_myMCXsecEventWeight_Q2CCCoh = fChain->GetBranch("myMCXsecEventWeight.Q2CCCoh");
   b_myMCXsecEventWeight_EnuNCCoh = fChain->GetBranch("myMCXsecEventWeight.EnuNCCoh");
   b_myMCXsecEventWeight_Q2NCCoh = fChain->GetBranch("myMCXsecEventWeight.Q2NCCoh");
   b_myMCXsecEventWeight_EnuUser1 = fChain->GetBranch("myMCXsecEventWeight.EnuUser1");
   b_myMCXsecEventWeight_Q2User1 = fChain->GetBranch("myMCXsecEventWeight.Q2User1");
   b_myMCXsecEventWeight_EnuUser2 = fChain->GetBranch("myMCXsecEventWeight.EnuUser2");
   b_myMCXsecEventWeight_Q2User2 = fChain->GetBranch("myMCXsecEventWeight.Q2User2");
   b_myMCReweightCV_ = fChain->GetBranch("myMCReweightCV");
   b_myMCReweightCV_fUniqueID = fChain->GetBranch("myMCReweightCV.fUniqueID");
   b_myMCReweightCV_fBits = fChain->GetBranch("myMCReweightCV.fBits");
   b_myMCReweightCV_Ppi0 = fChain->GetBranch("myMCReweightCV.Ppi0");
   b_myMCReweightCV_Enu = fChain->GetBranch("myMCReweightCV.Enu");
   b_myMCReweightCV_XsecWght = fChain->GetBranch("myMCReweightCV.XsecWght");
   b_myMCReweightCV_FluxWght = fChain->GetBranch("myMCReweightCV.FluxWght");
   b_myMCReweightCV_NuType = fChain->GetBranch("myMCReweightCV.NuType");
   b_myMCReweightCV_NuanceCh = fChain->GetBranch("myMCReweightCV.NuanceCh");
   b_myMCReweightCV_IdParent = fChain->GetBranch("myMCReweightCV.IdParent");
   b_myMCReweightCV_Rad_x = fChain->GetBranch("myMCReweightCV.Rad_x");
   b_myMCReweightCV_Rad_y = fChain->GetBranch("myMCReweightCV.Rad_y");
   b_myMCReweightCV_Rad_z = fChain->GetBranch("myMCReweightCV.Rad_z");
   b_myMCReweightCV_Rad_r = fChain->GetBranch("myMCReweightCV.Rad_r");
   b_myMCReweightCV_PParent_px = fChain->GetBranch("myMCReweightCV.PParent_px");
   b_myMCReweightCV_PParent_py = fChain->GetBranch("myMCReweightCV.PParent_py");
   b_myMCReweightCV_PParent_pz = fChain->GetBranch("myMCReweightCV.PParent_pz");
   b_myMCReweightCV_PParent_E = fChain->GetBranch("myMCReweightCV.PParent_E");
   b_myMCNuanceWeight_ = fChain->GetBranch("myMCNuanceWeight");
   b_myMCNuanceWeight_fUniqueID = fChain->GetBranch("myMCNuanceWeight.fUniqueID");
   b_myMCNuanceWeight_fBits = fChain->GetBranch("myMCNuanceWeight.fBits");
   b_myMCNuanceWeight_Weight = fChain->GetBranch("myMCNuanceWeight.Weight");
   b_myMCNuanceWeight_Channel = fChain->GetBranch("myMCNuanceWeight.Channel");
   b_myMCNuanceWeight_E_neutrino = fChain->GetBranch("myMCNuanceWeight.E_neutrino");
   b_myMCNuanceWeight_E_lepton = fChain->GetBranch("myMCNuanceWeight.E_lepton");
   b_myMCNuanceWeight_K_target = fChain->GetBranch("myMCNuanceWeight.K_target");
   b_myMCNuanceWeight_Qsq = fChain->GetBranch("myMCNuanceWeight.Qsq");
   b_myMCNuanceWeight_W = fChain->GetBranch("myMCNuanceWeight.W");
   b_myMCNuanceWeight_X = fChain->GetBranch("myMCNuanceWeight.X");
   b_myMCNuanceWeight_Y = fChain->GetBranch("myMCNuanceWeight.Y");
   b_myMCNuanceWeight_Phi_cm = fChain->GetBranch("myMCNuanceWeight.Phi_cm");
   b_myMCNuanceWeight_Cos_fermi = fChain->GetBranch("myMCNuanceWeight.Cos_fermi");
   b_myMCWeightDetails_ = fChain->GetBranch("myMCWeightDetails");
   b_myMCWeightDetails_fUniqueID = fChain->GetBranch("myMCWeightDetails.fUniqueID");
   b_myMCWeightDetails_fBits = fChain->GetBranch("myMCWeightDetails.fBits");
   b_myMCWeightDetails_Resangle = fChain->GetBranch("myMCWeightDetails.Resangle");
   b_myMCWeightDetails_Dirt = fChain->GetBranch("myMCWeightDetails.Dirt");
   b_myMCWeightDetails_Pi0mom = fChain->GetBranch("myMCWeightDetails.Pi0mom");
   b_myMCWeightDetails_Deltamom = fChain->GetBranch("myMCWeightDetails.Deltamom");
   b_myMCWeightDetails_Pi0coh = fChain->GetBranch("myMCWeightDetails.Pi0coh");
   b_myMCWeightDetails_Pi0res = fChain->GetBranch("myMCWeightDetails.Pi0res");
   b_myMCWeightDetails_Nuance = fChain->GetBranch("myMCWeightDetails.Nuance");
   b_myMCWeightDetails_Pipflux = fChain->GetBranch("myMCWeightDetails.Pipflux");
   b_myMCWeightDetails_Pimflux = fChain->GetBranch("myMCWeightDetails.Pimflux");
   b_myMCWeightDetails_Kpflux = fChain->GetBranch("myMCWeightDetails.Kpflux");
   b_myMCWeightDetails_Kmflux = fChain->GetBranch("myMCWeightDetails.Kmflux");
   b_myMCWeightDetails_K0flux = fChain->GetBranch("myMCWeightDetails.K0flux");
   b_myMCWeightDetails_Histo = fChain->GetBranch("myMCWeightDetails.Histo");
   b_myMCWeightDetails_Npip = fChain->GetBranch("myMCWeightDetails.Npip");
   b_myMCWeightDetails_Totalweight = fChain->GetBranch("myMCWeightDetails.Totalweight");
   b_myWeightArray_ = fChain->GetBranch("myWeightArray");
   b_myWeightArray_fUniqueID = fChain->GetBranch("myWeightArray.fUniqueID");
   b_myWeightArray_fBits = fChain->GetBranch("myWeightArray.fBits");
   b_myWeightArray_Nemaqe = fChain->GetBranch("myWeightArray.Nemaqe");
   b_myWeightArray_Nelosf = fChain->GetBranch("myWeightArray.Nelosf");
   b_myWeightArray_Emaqe = fChain->GetBranch("myWeightArray.Emaqe[50]");
   b_myWeightArray_Elosf = fChain->GetBranch("myWeightArray.Elosf[50]");
   b_myWeightArray_Maelowt = fChain->GetBranch("myWeightArray.Maelowt[50][50]");
   b_myCalE_ = fChain->GetBranch("myCalE");
   b_myCalE_fUniqueID = fChain->GetBranch("myCalE.fUniqueID");
   b_myCalE_fBits = fChain->GetBranch("myCalE.fBits");
   b_myCalE_Tlep_e = fChain->GetBranch("myCalE.Tlep_e");
   b_myCalE_Tlep_m = fChain->GetBranch("myCalE.Tlep_m");
   b_myCalE_Qsq_e = fChain->GetBranch("myCalE.Qsq_e");
   b_myCalE_Qsq_m = fChain->GetBranch("myCalE.Qsq_m");
   b_myCalE_EnuQE_e = fChain->GetBranch("myCalE.EnuQE_e");
   b_myCalE_EnuQE_m = fChain->GetBranch("myCalE.EnuQE_m");
   b_mysplitEvent_ = fChain->GetBranch("mysplitEvent");
   b_mysplitEvent_fUniqueID = fChain->GetBranch("mysplitEvent.fUniqueID");
   b_mysplitEvent_fBits = fChain->GetBranch("mysplitEvent.fBits");
   b_mysplitEvent_nTankHits = fChain->GetBranch("mysplitEvent.nTankHits");
   b_mysplitEvent_nVetoHits = fChain->GetBranch("mysplitEvent.nVetoHits");
   b_mysplitEvent_nHighChgTnk = fChain->GetBranch("mysplitEvent.nHighChgTnk");
   b_mysplitEvent_nHighChgVeto = fChain->GetBranch("mysplitEvent.nHighChgVeto");
   b_mysplitEvent_qTot = fChain->GetBranch("mysplitEvent.qTot");
   b_mysplitEvent_tankqTot = fChain->GetBranch("mysplitEvent.tankqTot");
   b_mysplitEvent_vetoqTot = fChain->GetBranch("mysplitEvent.vetoqTot");
   b_mysplitEvent_minTime = fChain->GetBranch("mysplitEvent.minTime");
   b_mysplitEvent_maxTime = fChain->GetBranch("mysplitEvent.maxTime");
   b_mysplitEvent_aveTimeTank = fChain->GetBranch("mysplitEvent.aveTimeTank");
   b_mysplitEvent_peakTimeTank = fChain->GetBranch("mysplitEvent.peakTimeTank");
   b_mysplitEvent_rmsTimeTank = fChain->GetBranch("mysplitEvent.rmsTimeTank");
   b_mysplitEvent_aveTimeVeto = fChain->GetBranch("mysplitEvent.aveTimeVeto");
   b_mysplitEvent_peakTimeVeto = fChain->GetBranch("mysplitEvent.peakTimeVeto");
   b_mysplitEvent_rmsTimeVeto = fChain->GetBranch("mysplitEvent.rmsTimeVeto");
   b_mysplitEvent_nMCparent = fChain->GetBranch("mysplitEvent.nMCparent");
   b_mysplitEvent_nMCpart = fChain->GetBranch("mysplitEvent.nMCpart");
   b_mysplitEvent_nPid = fChain->GetBranch("mysplitEvent.nPid");
   b_mysplitEvent_nRFast = fChain->GetBranch("mysplitEvent.nRFast");
   b_mysplitEvent_nRFull = fChain->GetBranch("mysplitEvent.nRFull");
   b_mysplitEvent_nRTrak = fChain->GetBranch("mysplitEvent.nRTrak");
   b_mysplitEvent_nRPi0 = fChain->GetBranch("mysplitEvent.nRPi0");
   b_mysplitEvent_nRFitters = fChain->GetBranch("mysplitEvent.nRFitters");
   b_mysplitEvent_nRFittersPi0 = fChain->GetBranch("mysplitEvent.nRFittersPi0");
   b_mysplitEvent_nRYangVars = fChain->GetBranch("mysplitEvent.nRYangVars");
   b_mysplitEvent_nRTransFull = fChain->GetBranch("mysplitEvent.nRTransFull");
   b_mysplitEvent_nRTransTrak = fChain->GetBranch("mysplitEvent.nRTransTrak");
   b_mysplitEvent_nRTransPi0 = fChain->GetBranch("mysplitEvent.nRTransPi0");
   b_mysplitEvent_nRTransFitters = fChain->GetBranch("mysplitEvent.nRTransFitters");
   b_mysplitEvent_nRTransFittersPi0 = fChain->GetBranch("mysplitEvent.nRTransFittersPi0");
   b_mysplitEvent_nRTransYangVars = fChain->GetBranch("mysplitEvent.nRTransYangVars");
   b_mysplitEvent_nSFast = fChain->GetBranch("mysplitEvent.nSFast");
   b_mysplitEvent_nSFull = fChain->GetBranch("mysplitEvent.nSFull");
   b_mysplitEvent_nSTrak = fChain->GetBranch("mysplitEvent.nSTrak");
   b_mysplitEvent_nSFlux = fChain->GetBranch("mysplitEvent.nSFlux");
   b_mysplitEvent_nSPi0 = fChain->GetBranch("mysplitEvent.nSPi0");
   b_mysplitEvent_nSVarsTwo = fChain->GetBranch("mysplitEvent.nSVarsTwo");
   b_mysplitEvent_nRecoConst = fChain->GetBranch("mysplitEvent.nRecoConst");
   b_mysplitEvent_nRecoDisjoint = fChain->GetBranch("mysplitEvent.nRecoDisjoint");
   b_mysplitEvent_nRecoOneTrk = fChain->GetBranch("mysplitEvent.nRecoOneTrk");
   b_mysplitEvent_nRecoOneTrkPred = fChain->GetBranch("mysplitEvent.nRecoOneTrkPred");
   b_mysplitEvent_nRecoPID = fChain->GetBranch("mysplitEvent.nRecoPID");
   b_mysplitEvent_nRecoTwoTrk = fChain->GetBranch("mysplitEvent.nRecoTwoTrk");
   b_mysplitEvent_nRecoTwoTrkPred = fChain->GetBranch("mysplitEvent.nRecoTwoTrkPred");
   b_mysplitEvent_nRecoTwoTrkFix = fChain->GetBranch("mysplitEvent.nRecoTwoTrkFix");
   b_mysplitEvent_nRecoTwoTrkFlt = fChain->GetBranch("mysplitEvent.nRecoTwoTrkFlt");
   b_myYBoostOut_ = fChain->GetBranch("myYBoostOut");
   b_myYBoostOut_fUniqueID = fChain->GetBranch("myYBoostOut.fUniqueID");
   b_myYBoostOut_fBits = fChain->GetBranch("myYBoostOut.fBits");
   b_myYBoostOut_CVBoost_V172 = fChain->GetBranch("myYBoostOut.CVBoost_V172");
   b_myYBoostOut_CVBoost_V175 = fChain->GetBranch("myYBoostOut.CVBoost_V175");
   b_myYBoostOut_MBoost_V172 = fChain->GetBranch("myYBoostOut.MBoost_V172");
   b_myAll_ = fChain->GetBranch("myAll");
   b_myAll_fUniqueID = fChain->GetBranch("myAll.fUniqueID");
   b_myAll_fBits = fChain->GetBranch("myAll.fBits");
   b_myAll_All_EMu_fthvl = fChain->GetBranch("myAll.All_EMu_fthvl");
   b_myAll_All_EMu_fthvp = fChain->GetBranch("myAll.All_EMu_fthvp");
   b_myAll_All_EMu_qlful = fChain->GetBranch("myAll.All_EMu_qlful");
   b_myAll_All_EMu_qtmr3 = fChain->GetBranch("myAll.All_EMu_qtmr3");
   b_myAll_All_EMu_qtmr4 = fChain->GetBranch("myAll.All_EMu_qtmr4");
   b_myAll_All_EMu_rawtavg = fChain->GetBranch("myAll.All_EMu_rawtavg");
   b_myAll_All_EMu_rawtsig = fChain->GetBranch("myAll.All_EMu_rawtsig");
   b_myAll_All_EMu_rslvl53 = fChain->GetBranch("myAll.All_EMu_rslvl53");
   b_myAll_All_EMu_rslvl64 = fChain->GetBranch("myAll.All_EMu_rslvl64");
   b_myAll_All_EMu_tlb24 = fChain->GetBranch("myAll.All_EMu_tlb24");
   b_myAll_All_EMu_tlb45 = fChain->GetBranch("myAll.All_EMu_tlb45");
   b_myAll_All_EMu_tlful = fChain->GetBranch("myAll.All_EMu_tlful");
   b_myAll_All_EMu_tlm22 = fChain->GetBranch("myAll.All_EMu_tlm22");
   b_myAll_All_EMu_tlsci = fChain->GetBranch("myAll.All_EMu_tlsci");
   b_myAll_All_EMu_trak = fChain->GetBranch("myAll.All_EMu_trak");
   b_myAll_All_EPi_angle = fChain->GetBranch("myAll.All_EPi_angle");
   b_myAll_All_EPi_dcbeam = fChain->GetBranch("myAll.All_EPi_dcbeam");
   b_myAll_All_EPi_dist1 = fChain->GetBranch("myAll.All_EPi_dist1");
   b_myAll_All_EPi_fcer = fChain->GetBranch("myAll.All_EPi_fcer");
   b_myAll_All_EPi_fmdiff = fChain->GetBranch("myAll.All_EPi_fmdiff");
   b_myAll_All_EPi_mass = fChain->GetBranch("myAll.All_EPi_mass");
   b_myAll_All_EPi_qldiff = fChain->GetBranch("myAll.All_EPi_qldiff");
   b_myAll_All_EPi_qtmr0 = fChain->GetBranch("myAll.All_EPi_qtmr0");
   b_myAll_All_EPi_qtmr56 = fChain->GetBranch("myAll.All_EPi_qtmr56");
   b_myAll_All_EPi_rslvl53 = fChain->GetBranch("myAll.All_EPi_rslvl53");
   b_myAll_All_EPi_rslvl64 = fChain->GetBranch("myAll.All_EPi_rslvl64");
   b_myAll_All_EPi_scratio = fChain->GetBranch("myAll.All_EPi_scratio");
   b_myAll_All_EPi_tlb245 = fChain->GetBranch("myAll.All_EPi_tlb245");
   b_myAll_All_EPi_tlcer = fChain->GetBranch("myAll.All_EPi_tlcer");
   b_myAll_All_EPi_tldiff = fChain->GetBranch("myAll.All_EPi_tldiff");
   b_myAll_All_EPi_trak = fChain->GetBranch("myAll.All_EPi_trak");
   b_myAll_All_NTank = fChain->GetBranch("myAll.All_NTank");
   b_myAll_All_NVeto = fChain->GetBranch("myAll.All_NVeto");
   b_myAll_All_Roe_abar = fChain->GetBranch("myAll.All_Roe_abar");
   b_myAll_All_Roe_akurtmu = fChain->GetBranch("myAll.All_Roe_akurtmu");
   b_myAll_All_Roe_akurtout = fChain->GetBranch("myAll.All_Roe_akurtout");
   b_myAll_All_Roe_asigma = fChain->GetBranch("myAll.All_Roe_asigma");
   b_myAll_All_Roe_askew = fChain->GetBranch("myAll.All_Roe_askew");
   b_myAll_All_Roe_askewmu = fChain->GetBranch("myAll.All_Roe_askewmu");
   b_myAll_All_Roe_avgtime = fChain->GetBranch("myAll.All_Roe_avgtime");
   b_myAll_All_Roe_bigang = fChain->GetBranch("myAll.All_Roe_bigang");
   b_myAll_All_Roe_cerratio = fChain->GetBranch("myAll.All_Roe_cerratio");
   b_myAll_All_Roe_chia = fChain->GetBranch("myAll.All_Roe_chia");
   b_myAll_All_Roe_chiae = fChain->GetBranch("myAll.All_Roe_chiae");
   b_myAll_All_Roe_chiphi = fChain->GetBranch("myAll.All_Roe_chiphi");
   b_myAll_All_Roe_chir = fChain->GetBranch("myAll.All_Roe_chir");
   b_myAll_All_Roe_chira5 = fChain->GetBranch("myAll.All_Roe_chira5");
   b_myAll_All_Roe_chire = fChain->GetBranch("myAll.All_Roe_chire");
   b_myAll_All_Roe_chisqmich = fChain->GetBranch("myAll.All_Roe_chisqmich");
   b_myAll_All_Roe_chisqst = fChain->GetBranch("myAll.All_Roe_chisqst");
   b_myAll_All_Roe_cosg = fChain->GetBranch("myAll.All_Roe_cosg");
   b_myAll_All_Roe_costhc = fChain->GetBranch("myAll.All_Roe_costhc");
   b_myAll_All_Roe_covlengthg1 = fChain->GetBranch("myAll.All_Roe_covlengthg1");
   b_myAll_All_Roe_covlengthg2 = fChain->GetBranch("myAll.All_Roe_covlengthg2");
   b_myAll_All_Roe_dtcb6 = fChain->GetBranch("myAll.All_Roe_dtcb6");
   b_myAll_All_Roe_dtcb9phit = fChain->GetBranch("myAll.All_Roe_dtcb9phit");
   b_myAll_All_Roe_dtlb6to8phit = fChain->GetBranch("myAll.All_Roe_dtlb6to8phit");
   b_myAll_All_Roe_dtlb8 = fChain->GetBranch("myAll.All_Roe_dtlb8");
   b_myAll_All_Roe_earlylit = fChain->GetBranch("myAll.All_Roe_earlylit");
   b_myAll_All_Roe_energy = fChain->GetBranch("myAll.All_Roe_energy");
   b_myAll_All_Roe_fhitcb1p9 = fChain->GetBranch("myAll.All_Roe_fhitcb1p9");
   b_myAll_All_Roe_fhitcb4p5 = fChain->GetBranch("myAll.All_Roe_fhitcb4p5");
   b_myAll_All_Roe_fhitcb9 = fChain->GetBranch("myAll.All_Roe_fhitcb9");
   b_myAll_All_Roe_fhittb3 = fChain->GetBranch("myAll.All_Roe_fhittb3");
   b_myAll_All_Roe_fhittb3p5 = fChain->GetBranch("myAll.All_Roe_fhittb3p5");
   b_myAll_All_Roe_fhittb3p8 = fChain->GetBranch("myAll.All_Roe_fhittb3p8");
   b_myAll_All_Roe_fhittb6to9 = fChain->GetBranch("myAll.All_Roe_fhittb6to9");
   b_myAll_All_Roe_fqcb1p2 = fChain->GetBranch("myAll.All_Roe_fqcb1p2");
   b_myAll_All_Roe_fqlb2p3 = fChain->GetBranch("myAll.All_Roe_fqlb2p3");
   b_myAll_All_Roe_fqtchicb4p9 = fChain->GetBranch("myAll.All_Roe_fqtchicb4p9");
   b_myAll_All_Roe_fracpmtg1 = fChain->GetBranch("myAll.All_Roe_fracpmtg1");
   b_myAll_All_Roe_fracpmtg2 = fChain->GetBranch("myAll.All_Roe_fracpmtg2");
   b_myAll_All_Roe_fracq1q2to1 = fChain->GetBranch("myAll.All_Roe_fracq1q2to1");
   b_myAll_All_Roe_fracq1to2 = fChain->GetBranch("myAll.All_Roe_fracq1to2");
   b_myAll_All_Roe_fracq2to1 = fChain->GetBranch("myAll.All_Roe_fracq2to1");
   b_myAll_All_Roe_fracqg1 = fChain->GetBranch("myAll.All_Roe_fracqg1");
   b_myAll_All_Roe_fracqg2 = fChain->GetBranch("myAll.All_Roe_fracqg2");
   b_myAll_All_Roe_fracqhitleft = fChain->GetBranch("myAll.All_Roe_fracqhitleft");
   b_myAll_All_Roe_fracqpmteg1 = fChain->GetBranch("myAll.All_Roe_fracqpmteg1");
   b_myAll_All_Roe_fracqpmteg2 = fChain->GetBranch("myAll.All_Roe_fracqpmteg2");
   b_myAll_All_Roe_ftchicb2p7 = fChain->GetBranch("myAll.All_Roe_ftchicb2p7");
   b_myAll_All_Roe_g2cratio = fChain->GetBranch("myAll.All_Roe_g2cratio");
   b_myAll_All_Roe_geratio = fChain->GetBranch("myAll.All_Roe_geratio");
   b_myAll_All_Roe_latelit = fChain->GetBranch("myAll.All_Roe_latelit");
   b_myAll_All_Roe_leftright = fChain->GetBranch("myAll.All_Roe_leftright");
   b_myAll_All_Roe_muenergy = fChain->GetBranch("myAll.All_Roe_muenergy");
   b_myAll_All_Roe_nbing1 = fChain->GetBranch("myAll.All_Roe_nbing1");
   b_myAll_All_Roe_nbing2 = fChain->GetBranch("myAll.All_Roe_nbing2");
   b_myAll_All_Roe_nzbing1 = fChain->GetBranch("myAll.All_Roe_nzbing1");
   b_myAll_All_Roe_nzbing2 = fChain->GetBranch("myAll.All_Roe_nzbing2");
   b_myAll_All_Roe_pi0mass = fChain->GetBranch("myAll.All_Roe_pi0mass");
   b_myAll_All_Roe_qcb1 = fChain->GetBranch("myAll.All_Roe_qcb1");
   b_myAll_All_Roe_qfrac0 = fChain->GetBranch("myAll.All_Roe_qfrac0");
   b_myAll_All_Roe_qfrac5 = fChain->GetBranch("myAll.All_Roe_qfrac5");
   b_myAll_All_Roe_qfrac6 = fChain->GetBranch("myAll.All_Roe_qfrac6");
   b_myAll_All_Roe_qfrac8 = fChain->GetBranch("myAll.All_Roe_qfrac8");
   b_myAll_All_Roe_qfrac9 = fChain->GetBranch("myAll.All_Roe_qfrac9");
   b_myAll_All_Roe_qg1 = fChain->GetBranch("myAll.All_Roe_qg1");
   b_myAll_All_Roe_qg2 = fChain->GetBranch("myAll.All_Roe_qg2");
   b_myAll_All_Roe_qlb1 = fChain->GetBranch("myAll.All_Roe_qlb1");
   b_myAll_All_Roe_qlb1phit = fChain->GetBranch("myAll.All_Roe_qlb1phit");
   b_myAll_All_Roe_qtchitb9pq = fChain->GetBranch("myAll.All_Roe_qtchitb9pq");
   b_myAll_All_Roe_rdist = fChain->GetBranch("myAll.All_Roe_rdist");
   b_myAll_All_Roe_rtowall = fChain->GetBranch("myAll.All_Roe_rtowall");
   b_myAll_All_Roe_s2mis = fChain->GetBranch("myAll.All_Roe_s2mis");
   b_myAll_All_Roe_sbar = fChain->GetBranch("myAll.All_Roe_sbar");
   b_myAll_All_Roe_scratio = fChain->GetBranch("myAll.All_Roe_scratio");
   b_myAll_All_Roe_sigbin = fChain->GetBranch("myAll.All_Roe_sigbin");
   b_myAll_All_Roe_sigtime = fChain->GetBranch("myAll.All_Roe_sigtime");
   b_myAll_All_Roe_skurt = fChain->GetBranch("myAll.All_Roe_skurt");
   b_myAll_All_Roe_ssigma = fChain->GetBranch("myAll.All_Roe_ssigma");
   b_myAll_All_Roe_sskew = fChain->GetBranch("myAll.All_Roe_sskew");
   b_myAll_All_Roe_tave = fChain->GetBranch("myAll.All_Roe_tave");
   b_myAll_All_Roe_tbar = fChain->GetBranch("myAll.All_Roe_tbar");
   b_myAll_All_Roe_timekurt = fChain->GetBranch("myAll.All_Roe_timekurt");
   b_myAll_All_Roe_tkurt = fChain->GetBranch("myAll.All_Roe_tkurt");
   b_myAll_All_Roe_tracklength = fChain->GetBranch("myAll.All_Roe_tracklength");
   b_myAll_All_Roe_triple = fChain->GetBranch("myAll.All_Roe_triple");
   b_myAll_All_Roe_trpkurt = fChain->GetBranch("myAll.All_Roe_trpkurt");
   b_myAll_All_Roe_trpsig = fChain->GetBranch("myAll.All_Roe_trpsig");
   b_myAll_All_Roe_tsigma = fChain->GetBranch("myAll.All_Roe_tsigma");
   b_myAll_All_Roe_tskew = fChain->GetBranch("myAll.All_Roe_tskew");
   b_myAll_All_Roe_tslope = fChain->GetBranch("myAll.All_Roe_tslope");
   b_myAll_All_Roe_uzg1 = fChain->GetBranch("myAll.All_Roe_uzg1");
   b_myAll_All_Roe_xintmax = fChain->GetBranch("myAll.All_Roe_xintmax");
   b_myAll_All_Stancu_COS = fChain->GetBranch("myAll.All_Stancu_COS");
   b_myAll_All_Stancu_E = fChain->GetBranch("myAll.All_Stancu_E");
   b_myAll_All_Stancu_R = fChain->GetBranch("myAll.All_Stancu_R");
   b_myAll_All_Stancu_W = fChain->GetBranch("myAll.All_Stancu_W");
   b_myAll_All_Stancu_X = fChain->GetBranch("myAll.All_Stancu_X");
   b_myAll_All_Stancu_Y = fChain->GetBranch("myAll.All_Stancu_Y");
   b_myAll_All_Stancu_Z = fChain->GetBranch("myAll.All_Stancu_Z");
   b_myAll_All_Stancu_abscerasy = fChain->GetBranch("myAll.All_Stancu_abscerasy");
   b_myAll_All_Stancu_cerfrdiff = fChain->GetBranch("myAll.All_Stancu_cerfrdiff");
   b_myAll_All_Stancu_chiqrec = fChain->GetBranch("myAll.All_Stancu_chiqrec");
   b_myAll_All_Stancu_chirsqrec = fChain->GetBranch("myAll.All_Stancu_chirsqrec");
   b_myAll_All_Stancu_dist2 = fChain->GetBranch("myAll.All_Stancu_dist2");
   b_myAll_All_Stancu_fcertflx = fChain->GetBranch("myAll.All_Stancu_fcertflx");
   b_myAll_All_Stancu_ffast = fChain->GetBranch("myAll.All_Stancu_ffast");
   b_myAll_All_Stancu_fflux = fChain->GetBranch("myAll.All_Stancu_fflux");
   b_myAll_All_Stancu_ffulmffas = fChain->GetBranch("myAll.All_Stancu_ffulmffas");
   b_myAll_All_Stancu_fn010p16 = fChain->GetBranch("myAll.All_Stancu_fn010p16");
   b_myAll_All_Stancu_fn014p16 = fChain->GetBranch("myAll.All_Stancu_fn014p16");
   b_myAll_All_Stancu_fn018m14 = fChain->GetBranch("myAll.All_Stancu_fn018m14");
   b_myAll_All_Stancu_fnh11t14 = fChain->GetBranch("myAll.All_Stancu_fnh11t14");
   b_myAll_All_Stancu_fnh1t5p1518 = fChain->GetBranch("myAll.All_Stancu_fnh1t5p1518");
   b_myAll_All_Stancu_fqlk010p13 = fChain->GetBranch("myAll.All_Stancu_fqlk010p13");
   b_myAll_All_Stancu_fqlk011p13 = fChain->GetBranch("myAll.All_Stancu_fqlk011p13");
   b_myAll_All_Stancu_fqlk012p13 = fChain->GetBranch("myAll.All_Stancu_fqlk012p13");
   b_myAll_All_Stancu_fqlk012p14 = fChain->GetBranch("myAll.All_Stancu_fqlk012p14");
   b_myAll_All_Stancu_fqlk013p14 = fChain->GetBranch("myAll.All_Stancu_fqlk013p14");
   b_myAll_All_Stancu_fqlk014p15 = fChain->GetBranch("myAll.All_Stancu_fqlk014p15");
   b_myAll_All_Stancu_fqlk016p17 = fChain->GetBranch("myAll.All_Stancu_fqlk016p17");
   b_myAll_All_Stancu_fqlk08p13 = fChain->GetBranch("myAll.All_Stancu_fqlk08p13");
   b_myAll_All_Stancu_fqlkh11p13 = fChain->GetBranch("myAll.All_Stancu_fqlkh11p13");
   b_myAll_All_Stancu_fqlkh11t14 = fChain->GetBranch("myAll.All_Stancu_fqlkh11t14");
   b_myAll_All_Stancu_fqlkh13p14 = fChain->GetBranch("myAll.All_Stancu_fqlkh13p14");
   b_myAll_All_Stancu_fqlkh1p18 = fChain->GetBranch("myAll.All_Stancu_fqlkh1p18");
   b_myAll_All_Stancu_fqlkh1t5p1518 = fChain->GetBranch("myAll.All_Stancu_fqlkh1t5p1518");
   b_myAll_All_Stancu_fqlkh9p14 = fChain->GetBranch("myAll.All_Stancu_fqlkh9p14");
   b_myAll_All_Stancu_fqlt05 = fChain->GetBranch("myAll.All_Stancu_fqlt05");
   b_myAll_All_Stancu_fqlt10 = fChain->GetBranch("myAll.All_Stancu_fqlt10");
   b_myAll_All_Stancu_fqrec15t16 = fChain->GetBranch("myAll.All_Stancu_fqrec15t16");
   b_myAll_All_Stancu_fqrec15t18 = fChain->GetBranch("myAll.All_Stancu_fqrec15t18");
   b_myAll_All_Stancu_fqrec15t20 = fChain->GetBranch("myAll.All_Stancu_fqrec15t20");
   b_myAll_All_Stancu_fqrec1t10 = fChain->GetBranch("myAll.All_Stancu_fqrec1t10");
   b_myAll_All_Stancu_fqrec6t10 = fChain->GetBranch("myAll.All_Stancu_fqrec6t10");
   b_myAll_All_Stancu_fqrec6t14 = fChain->GetBranch("myAll.All_Stancu_fqrec6t14");
   b_myAll_All_Stancu_frcer1 = fChain->GetBranch("myAll.All_Stancu_frcer1");
   b_myAll_All_Stancu_frcer2 = fChain->GetBranch("myAll.All_Stancu_frcer2");
   b_myAll_All_Stancu_frchia10m4 = fChain->GetBranch("myAll.All_Stancu_frchia10m4");
   b_myAll_All_Stancu_frnhcos10m8 = fChain->GetBranch("myAll.All_Stancu_frnhcos10m8");
   b_myAll_All_Stancu_frnhcos8 = fChain->GetBranch("myAll.All_Stancu_frnhcos8");
   b_myAll_All_Stancu_frnhcos8m7 = fChain->GetBranch("myAll.All_Stancu_frnhcos8m7");
   b_myAll_All_Stancu_frnhcos9m8 = fChain->GetBranch("myAll.All_Stancu_frnhcos9m8");
   b_myAll_All_Stancu_frnhnb8m2 = fChain->GetBranch("myAll.All_Stancu_frnhnb8m2");
   b_myAll_All_Stancu_frnhrsnb5 = fChain->GetBranch("myAll.All_Stancu_frnhrsnb5");
   b_myAll_All_Stancu_frnqcer1 = fChain->GetBranch("myAll.All_Stancu_frnqcer1");
   b_myAll_All_Stancu_frnqcer1m2 = fChain->GetBranch("myAll.All_Stancu_frnqcer1m2");
   b_myAll_All_Stancu_frqcer1mov = fChain->GetBranch("myAll.All_Stancu_frqcer1mov");
   b_myAll_All_Stancu_frqcos10m3 = fChain->GetBranch("myAll.All_Stancu_frqcos10m3");
   b_myAll_All_Stancu_frqcos10m8 = fChain->GetBranch("myAll.All_Stancu_frqcos10m8");
   b_myAll_All_Stancu_frqcos6m1 = fChain->GetBranch("myAll.All_Stancu_frqcos6m1");
   b_myAll_All_Stancu_frqcos8 = fChain->GetBranch("myAll.All_Stancu_frqcos8");
   b_myAll_All_Stancu_frqcos8m3 = fChain->GetBranch("myAll.All_Stancu_frqcos8m3");
   b_myAll_All_Stancu_frqcos8m4 = fChain->GetBranch("myAll.All_Stancu_frqcos8m4");
   b_myAll_All_Stancu_frqcos8m5 = fChain->GetBranch("myAll.All_Stancu_frqcos8m5");
   b_myAll_All_Stancu_frqcos8m7 = fChain->GetBranch("myAll.All_Stancu_frqcos8m7");
   b_myAll_All_Stancu_frqlk02p16 = fChain->GetBranch("myAll.All_Stancu_frqlk02p16");
   b_myAll_All_Stancu_frqqcer1m2 = fChain->GetBranch("myAll.All_Stancu_frqqcer1m2");
   b_myAll_All_Stancu_frqqov = fChain->GetBranch("myAll.All_Stancu_frqqov");
   b_myAll_All_Stancu_frrs6m1 = fChain->GetBranch("myAll.All_Stancu_frrs6m1");
   b_myAll_All_Stancu_frrs7m1 = fChain->GetBranch("myAll.All_Stancu_frrs7m1");
   b_myAll_All_Stancu_frrs8m1 = fChain->GetBranch("myAll.All_Stancu_frrs8m1");
   b_myAll_All_Stancu_frsn010p13 = fChain->GetBranch("myAll.All_Stancu_frsn010p13");
   b_myAll_All_Stancu_frsn010p14 = fChain->GetBranch("myAll.All_Stancu_frsn010p14");
   b_myAll_All_Stancu_frsn011 = fChain->GetBranch("myAll.All_Stancu_frsn011");
   b_myAll_All_Stancu_frsn011p14 = fChain->GetBranch("myAll.All_Stancu_frsn011p14");
   b_myAll_All_Stancu_frsn013 = fChain->GetBranch("myAll.All_Stancu_frsn013");
   b_myAll_All_Stancu_frsq14p20 = fChain->GetBranch("myAll.All_Stancu_frsq14p20");
   b_myAll_All_Stancu_fscitflx = fChain->GetBranch("myAll.All_Stancu_fscitflx");
   b_myAll_All_Stancu_fthjl = fChain->GetBranch("myAll.All_Stancu_fthjl");
   b_myAll_All_Stancu_fthjp = fChain->GetBranch("myAll.All_Stancu_fthjp");
   b_myAll_All_Stancu_fthvp = fChain->GetBranch("myAll.All_Stancu_fthvp");
   b_myAll_All_Stancu_ftnhit3m2 = fChain->GetBranch("myAll.All_Stancu_ftnhit3m2");
   b_myAll_All_Stancu_ftnhit3p6 = fChain->GetBranch("myAll.All_Stancu_ftnhit3p6");
   b_myAll_All_Stancu_ftnhit4 = fChain->GetBranch("myAll.All_Stancu_ftnhit4");
   b_myAll_All_Stancu_ftnhit4p10 = fChain->GetBranch("myAll.All_Stancu_ftnhit4p10");
   b_myAll_All_Stancu_ftnhit4p5 = fChain->GetBranch("myAll.All_Stancu_ftnhit4p5");
   b_myAll_All_Stancu_ftnhit4p8 = fChain->GetBranch("myAll.All_Stancu_ftnhit4p8");
   b_myAll_All_Stancu_ftnhit4p9 = fChain->GetBranch("myAll.All_Stancu_ftnhit4p9");
   b_myAll_All_Stancu_ftnhit9m3 = fChain->GetBranch("myAll.All_Stancu_ftnhit9m3");
   b_myAll_All_Stancu_ftq4 = fChain->GetBranch("myAll.All_Stancu_ftq4");
   b_myAll_All_Stancu_nqovovthit = fChain->GetBranch("myAll.All_Stancu_nqovovthit");
   b_myAll_All_Stancu_nqtmr16 = fChain->GetBranch("myAll.All_Stancu_nqtmr16");
   b_myAll_All_Stancu_nqtmr17p18 = fChain->GetBranch("myAll.All_Stancu_nqtmr17p18");
   b_myAll_All_Stancu_nqtmr18p19 = fChain->GetBranch("myAll.All_Stancu_nqtmr18p19");
   b_myAll_All_Stancu_pi01ql1 = fChain->GetBranch("myAll.All_Stancu_pi01ql1");
   b_myAll_All_Stancu_pi01ql2 = fChain->GetBranch("myAll.All_Stancu_pi01ql2");
   b_myAll_All_Stancu_pi01ql3 = fChain->GetBranch("myAll.All_Stancu_pi01ql3");
   b_myAll_All_Stancu_pi01ql4 = fChain->GetBranch("myAll.All_Stancu_pi01ql4");
   b_myAll_All_Stancu_pi01tl2 = fChain->GetBranch("myAll.All_Stancu_pi01tl2");
   b_myAll_All_Stancu_pi01tl3 = fChain->GetBranch("myAll.All_Stancu_pi01tl3");
   b_myAll_All_Stancu_pi02fthl = fChain->GetBranch("myAll.All_Stancu_pi02fthl");
   b_myAll_All_Stancu_pi02ql3 = fChain->GetBranch("myAll.All_Stancu_pi02ql3");
   b_myAll_All_Stancu_pi02ql4 = fChain->GetBranch("myAll.All_Stancu_pi02ql4");
   b_myAll_All_Stancu_pi02tl3 = fChain->GetBranch("myAll.All_Stancu_pi02tl3");
   b_myAll_All_Stancu_pi02tl4 = fChain->GetBranch("myAll.All_Stancu_pi02tl4");
   b_myAll_All_Stancu_qcer1ovqtot = fChain->GetBranch("myAll.All_Stancu_qcer1ovqtot");
   b_myAll_All_Stancu_qcer2ovqtot = fChain->GetBranch("myAll.All_Stancu_qcer2ovqtot");
   b_myAll_All_Stancu_ql0cos10 = fChain->GetBranch("myAll.All_Stancu_ql0cos10");
   b_myAll_All_Stancu_ql0cos6 = fChain->GetBranch("myAll.All_Stancu_ql0cos6");
   b_myAll_All_Stancu_ql0cos7 = fChain->GetBranch("myAll.All_Stancu_ql0cos7");
   b_myAll_All_Stancu_qlkcos3 = fChain->GetBranch("myAll.All_Stancu_qlkcos3");
   b_myAll_All_Stancu_qlkcos8 = fChain->GetBranch("myAll.All_Stancu_qlkcos8");
   b_myAll_All_Stancu_qlph16m12 = fChain->GetBranch("myAll.All_Stancu_qlph16m12");
   b_myAll_All_Stancu_qlph16m8 = fChain->GetBranch("myAll.All_Stancu_qlph16m8");
   b_myAll_All_Stancu_qlphcos7 = fChain->GetBranch("myAll.All_Stancu_qlphcos7");
   b_myAll_All_Stancu_qlppmtcos5 = fChain->GetBranch("myAll.All_Stancu_qlppmtcos5");
   b_myAll_All_Stancu_qlppmtcos6 = fChain->GetBranch("myAll.All_Stancu_qlppmtcos6");
   b_myAll_All_Stancu_qlppmtcos8 = fChain->GetBranch("myAll.All_Stancu_qlppmtcos8");
   b_myAll_All_Stancu_qlppmtcos8m6 = fChain->GetBranch("myAll.All_Stancu_qlppmtcos8m6");
   b_myAll_All_Stancu_qtmr0p5 = fChain->GetBranch("myAll.All_Stancu_qtmr0p5");
   b_myAll_All_Stancu_qtmr4m2 = fChain->GetBranch("myAll.All_Stancu_qtmr4m2");
   b_myAll_All_Stancu_qtmr4p5 = fChain->GetBranch("myAll.All_Stancu_qtmr4p5");
   b_myAll_All_Stancu_qtmr5 = fChain->GetBranch("myAll.All_Stancu_qtmr5");
   b_myAll_All_Stancu_qtmr5m2 = fChain->GetBranch("myAll.All_Stancu_qtmr5m2");
   b_myAll_All_Stancu_qtmr5m3 = fChain->GetBranch("myAll.All_Stancu_qtmr5m3");
   b_myAll_All_Stancu_qtmr5m4 = fChain->GetBranch("myAll.All_Stancu_qtmr5m4");
   b_myAll_All_Stancu_qtmr6p7 = fChain->GetBranch("myAll.All_Stancu_qtmr6p7");
   b_myAll_All_Stancu_qtmr7m2 = fChain->GetBranch("myAll.All_Stancu_qtmr7m2");
   b_myAll_All_Stancu_qtmr7m5 = fChain->GetBranch("myAll.All_Stancu_qtmr7m5");
   b_myAll_All_Stancu_qtmr7m6 = fChain->GetBranch("myAll.All_Stancu_qtmr7m6");
   b_myAll_All_Stancu_qtmr8m5 = fChain->GetBranch("myAll.All_Stancu_qtmr8m5");
   b_myAll_All_Stancu_qtmr9m5 = fChain->GetBranch("myAll.All_Stancu_qtmr9m5");
   b_myAll_All_Stancu_qtmrc2 = fChain->GetBranch("myAll.All_Stancu_qtmrc2");
   b_myAll_All_Stancu_qtmrcos10m2 = fChain->GetBranch("myAll.All_Stancu_qtmrcos10m2");
   b_myAll_All_Stancu_qtmrcos10m5 = fChain->GetBranch("myAll.All_Stancu_qtmrcos10m5");
   b_myAll_All_Stancu_qtmrcos5m1 = fChain->GetBranch("myAll.All_Stancu_qtmrcos5m1");
   b_myAll_All_Stancu_qtmrcos6 = fChain->GetBranch("myAll.All_Stancu_qtmrcos6");
   b_myAll_All_Stancu_qtmrcos6m1 = fChain->GetBranch("myAll.All_Stancu_qtmrcos6m1");
   b_myAll_All_Stancu_qtmrcos7 = fChain->GetBranch("myAll.All_Stancu_qtmrcos7");
   b_myAll_All_Stancu_qtmrcos7m2 = fChain->GetBranch("myAll.All_Stancu_qtmrcos7m2");
   b_myAll_All_Stancu_qtmrcos7m5 = fChain->GetBranch("myAll.All_Stancu_qtmrcos7m5");
   b_myAll_All_Stancu_qtmrcos8 = fChain->GetBranch("myAll.All_Stancu_qtmrcos8");
   b_myAll_All_Stancu_qtmrcos8m3 = fChain->GetBranch("myAll.All_Stancu_qtmrcos8m3");
   b_myAll_All_Stancu_qtmrcos8m5 = fChain->GetBranch("myAll.All_Stancu_qtmrcos8m5");
   b_myAll_All_Stancu_qtmrcos8m6 = fChain->GetBranch("myAll.All_Stancu_qtmrcos8m6");
   b_myAll_All_Stancu_qtmrcos8m7 = fChain->GetBranch("myAll.All_Stancu_qtmrcos8m7");
   b_myAll_All_Stancu_qtmrmm = fChain->GetBranch("myAll.All_Stancu_qtmrmm");
   b_myAll_All_Stancu_qtmrpp = fChain->GetBranch("myAll.All_Stancu_qtmrpp");
   b_myAll_All_Stancu_qtmrsnb7 = fChain->GetBranch("myAll.All_Stancu_qtmrsnb7");
   b_myAll_All_Stancu_rdr = fChain->GetBranch("myAll.All_Stancu_rdr");
   b_myAll_All_Stancu_rslvl1p8ovq = fChain->GetBranch("myAll.All_Stancu_rslvl1p8ovq");
   b_myAll_All_Stancu_rslvl3p9ovq = fChain->GetBranch("myAll.All_Stancu_rslvl3p9ovq");
   b_myAll_All_Stancu_rslvl7m4ovq = fChain->GetBranch("myAll.All_Stancu_rslvl7m4ovq");
   b_myAll_All_Stancu_rslvl8p9ovq = fChain->GetBranch("myAll.All_Stancu_rslvl8p9ovq");
   b_myAll_All_Stancu_rslvl9m1ovq = fChain->GetBranch("myAll.All_Stancu_rslvl9m1ovq");
   b_myAll_All_Stancu_rsqtmr13 = fChain->GetBranch("myAll.All_Stancu_rsqtmr13");
   b_myAll_All_Stancu_rsqtmr14 = fChain->GetBranch("myAll.All_Stancu_rsqtmr14");
   b_myAll_All_Stancu_rsqtmr16 = fChain->GetBranch("myAll.All_Stancu_rsqtmr16");
   b_myAll_All_Stancu_srec1 = fChain->GetBranch("myAll.All_Stancu_srec1");
   b_myAll_All_Stancu_srec2 = fChain->GetBranch("myAll.All_Stancu_srec2");
   b_myAll_All_Stancu_stint = fChain->GetBranch("myAll.All_Stancu_stint");
   b_myAll_All_Stancu_tlfwd = fChain->GetBranch("myAll.All_Stancu_tlfwd");
   b_myAll_All_Stancu_tlph11p15 = fChain->GetBranch("myAll.All_Stancu_tlph11p15");
   b_myAll_All_Stancu_tlph13p14 = fChain->GetBranch("myAll.All_Stancu_tlph13p14");
   b_myAll_All_Stancu_tlph14p15 = fChain->GetBranch("myAll.All_Stancu_tlph14p15");
   b_myAll_All_Stancu_tlph15p16 = fChain->GetBranch("myAll.All_Stancu_tlph15p16");
   b_myAll_All_Stancu_tlph15p17 = fChain->GetBranch("myAll.All_Stancu_tlph15p17");
   b_myAll_All_Stancu_tlph16 = fChain->GetBranch("myAll.All_Stancu_tlph16");
   b_myAll_All_Stancu_tlph16p17 = fChain->GetBranch("myAll.All_Stancu_tlph16p17");
   b_myAll_All_Stancu_tlphcos10m8 = fChain->GetBranch("myAll.All_Stancu_tlphcos10m8");
   b_myAll_All_Stancu_tlphcos10m9 = fChain->GetBranch("myAll.All_Stancu_tlphcos10m9");
   b_myAll_All_Stancu_tlphcos4m1 = fChain->GetBranch("myAll.All_Stancu_tlphcos4m1");
   b_myAll_All_Stancu_tlphcos5 = fChain->GetBranch("myAll.All_Stancu_tlphcos5");
   b_myAll_All_Stancu_tlphcos5m1 = fChain->GetBranch("myAll.All_Stancu_tlphcos5m1");
   b_myAll_All_Stancu_tlphcos6m2 = fChain->GetBranch("myAll.All_Stancu_tlphcos6m2");
   b_myAll_All_Stancu_tlphcos7 = fChain->GetBranch("myAll.All_Stancu_tlphcos7");
   b_myAll_All_Stancu_tlphcos8 = fChain->GetBranch("myAll.All_Stancu_tlphcos8");
   b_myAll_All_Stancu_tlphcos8m1 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m1");
   b_myAll_All_Stancu_tlphcos8m2 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m2");
   b_myAll_All_Stancu_tlphcos8m4 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m4");
   b_myAll_All_Stancu_tlphcos8m5 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m5");
   b_myAll_All_Stancu_tlphcos8m6 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m6");
   b_myAll_All_Stancu_tlphcos8m7 = fChain->GetBranch("myAll.All_Stancu_tlphcos8m7");
   b_myAll_All_Stancu_tlphcos9m1 = fChain->GetBranch("myAll.All_Stancu_tlphcos9m1");
   b_myAll_All_Stancu_tlphcos9m2 = fChain->GetBranch("myAll.All_Stancu_tlphcos9m2");
   b_myAll_All_Stancu_tlphcos9m6 = fChain->GetBranch("myAll.All_Stancu_tlphcos9m6");
   b_myAll_All_Stancu_tlphcos9m7 = fChain->GetBranch("myAll.All_Stancu_tlphcos9m7");
   b_myAll_All_Stancu_trakove = fChain->GetBranch("myAll.All_Stancu_trakove");
   b_myAll_All_Stancu_walld = fChain->GetBranch("myAll.All_Stancu_walld");
   b_myAll_All_Roe_chg_density_nue = fChain->GetBranch("myAll.All_Roe_chg_density_nue");
   b_myAll_All_Roe_chg_density_g1 = fChain->GetBranch("myAll.All_Roe_chg_density_g1");
   b_myAll_All_Roe_chg_density_g2 = fChain->GetBranch("myAll.All_Roe_chg_density_g2");
   b_myAll_All_Roe_numlowt_nue = fChain->GetBranch("myAll.All_Roe_numlowt_nue");
   b_myAll_All_Roe_numlowt_g1 = fChain->GetBranch("myAll.All_Roe_numlowt_g1");
   b_myAll_All_Roe_numlowt_g2 = fChain->GetBranch("myAll.All_Roe_numlowt_g2");
   b_myAll_All_Roe_rtowall_backward = fChain->GetBranch("myAll.All_Roe_rtowall_backward");
   b_myAll_All_Roe_rtwbv = fChain->GetBranch("myAll.All_Roe_rtwbv");
   b_myAll_All_Roe_ur = fChain->GetBranch("myAll.All_Roe_ur");
   b_myAll_All_Roe_urdr = fChain->GetBranch("myAll.All_Roe_urdr");
   b_myAll_All_Pfit_log_e = fChain->GetBranch("myAll.All_Pfit_log_e");
   b_myAll_All_Pfit_log_mu = fChain->GetBranch("myAll.All_Pfit_log_mu");
   b_myAll_All_Pfit_log_pi = fChain->GetBranch("myAll.All_Pfit_log_pi");
   b_myAll_All_Pfit_log_emu = fChain->GetBranch("myAll.All_Pfit_log_emu");
   b_myAll_All_Pfit_log_epi = fChain->GetBranch("myAll.All_Pfit_log_epi");
   b_myAll_All_Pfit_mpi = fChain->GetBranch("myAll.All_Pfit_mpi");
   b_myAll_All_Pfit_E = fChain->GetBranch("myAll.All_Pfit_E");
   b_myAll_All_Pfit_R = fChain->GetBranch("myAll.All_Pfit_R");
   b_myAll_All_Pfit_UR = fChain->GetBranch("myAll.All_Pfit_UR");
   b_myAll_All_Pfit_UZ = fChain->GetBranch("myAll.All_Pfit_UZ");
   b_myAll_All_Pfit_URDR = fChain->GetBranch("myAll.All_Pfit_URDR");
   b_myAll_All_Pfit_Rtwbc = fChain->GetBranch("myAll.All_Pfit_Rtwbc");
   b_myRFast_ = fChain->GetBranch("myRFast");
   b_myRFast_fUniqueID = fChain->GetBranch("myRFast.fUniqueID");
   b_myRFast_fBits = fChain->GetBranch("myRFast.fBits");
   b_myRFast_iter = fChain->GetBranch("myRFast.iter");
   b_myRFast_likelihood = fChain->GetBranch("myRFast.likelihood");
   b_myRFast_time = fChain->GetBranch("myRFast.time");
   b_myRFast_vertex_x = fChain->GetBranch("myRFast.vertex_x");
   b_myRFast_vertex_y = fChain->GetBranch("myRFast.vertex_y");
   b_myRFast_vertex_z = fChain->GetBranch("myRFast.vertex_z");
   b_myRFast_vertex_mag = fChain->GetBranch("myRFast.vertex_mag");
   b_myRFull_ = fChain->GetBranch("myRFull");
   b_myRFull_fUniqueID = fChain->GetBranch("myRFull.fUniqueID");
   b_myRFull_fBits = fChain->GetBranch("myRFull.fBits");
   b_myRFull_trkCent_x = fChain->GetBranch("myRFull.trkCent_x");
   b_myRFull_trkCent_y = fChain->GetBranch("myRFull.trkCent_y");
   b_myRFull_trkCent_z = fChain->GetBranch("myRFull.trkCent_z");
   b_myRFull_trkCent_mag = fChain->GetBranch("myRFull.trkCent_mag");
   b_myRFull_trkCent_time = fChain->GetBranch("myRFull.trkCent_time");
   b_myRFull_dir_x = fChain->GetBranch("myRFull.dir_x");
   b_myRFull_dir_y = fChain->GetBranch("myRFull.dir_y");
   b_myRFull_dir_z = fChain->GetBranch("myRFull.dir_z");
   b_myRFull_dir_mag = fChain->GetBranch("myRFull.dir_mag");
   b_myRFull_length = fChain->GetBranch("myRFull.length");
   b_myRFull_vertex_x = fChain->GetBranch("myRFull.vertex_x");
   b_myRFull_vertex_y = fChain->GetBranch("myRFull.vertex_y");
   b_myRFull_vertex_z = fChain->GetBranch("myRFull.vertex_z");
   b_myRFull_vertex_mag = fChain->GetBranch("myRFull.vertex_mag");
   b_myRFull_vertex_time = fChain->GetBranch("myRFull.vertex_time");
   b_myRFull_chg_infit = fChain->GetBranch("myRFull.chg_infit");
   b_myRFull_chg_wgt_infit = fChain->GetBranch("myRFull.chg_wgt_infit");
   b_myRFull_chisq_a_infit = fChain->GetBranch("myRFull.chisq_a_infit");
   b_myRFull_chisq_r_infit = fChain->GetBranch("myRFull.chisq_r_infit");
   b_myRFull_weight_tot = fChain->GetBranch("myRFull.weight_tot");
   b_myRFull_chisq_avg = fChain->GetBranch("myRFull.chisq_avg");
   b_myRFull_rtowall = fChain->GetBranch("myRFull.rtowall");
   b_myRFull_energy = fChain->GetBranch("myRFull.energy");
   b_myRFull_length_mu = fChain->GetBranch("myRFull.length_mu");
   b_myRFull_energy_mu = fChain->GetBranch("myRFull.energy_mu");
   b_myRFull_numhits_infit = fChain->GetBranch("myRFull.numhits_infit");
   b_myRFull_chglength_nue = fChain->GetBranch("myRFull.chglength_nue");
   b_myRFull_amITransRoe = fChain->GetBranch("myRFull.amITransRoe");
   b_myRPi0_ = fChain->GetBranch("myRPi0");
   b_myRPi0_fUniqueID = fChain->GetBranch("myRPi0.fUniqueID");
   b_myRPi0_fBits = fChain->GetBranch("myRPi0.fBits");
   b_myRPi0_amITransRoe = fChain->GetBranch("myRPi0.amITransRoe");
   b_myRPi0_vertex_x = fChain->GetBranch("myRPi0.vertex_x");
   b_myRPi0_vertex_y = fChain->GetBranch("myRPi0.vertex_y");
   b_myRPi0_vertex_z = fChain->GetBranch("myRPi0.vertex_z");
   b_myRPi0_vertex_mag = fChain->GetBranch("myRPi0.vertex_mag");
   b_myRPi0_time = fChain->GetBranch("myRPi0.time");
   b_myRPi0_Shift_1 = fChain->GetBranch("myRPi0.Shift_1");
   b_myRPi0_Shift_2 = fChain->GetBranch("myRPi0.Shift_2");
   b_myRPi0_dir1_x = fChain->GetBranch("myRPi0.dir1_x");
   b_myRPi0_dir1_y = fChain->GetBranch("myRPi0.dir1_y");
   b_myRPi0_dir1_z = fChain->GetBranch("myRPi0.dir1_z");
   b_myRPi0_dir1_mag = fChain->GetBranch("myRPi0.dir1_mag");
   b_myRPi0_dir2_x = fChain->GetBranch("myRPi0.dir2_x");
   b_myRPi0_dir2_y = fChain->GetBranch("myRPi0.dir2_y");
   b_myRPi0_dir2_z = fChain->GetBranch("myRPi0.dir2_z");
   b_myRPi0_dir2_mag = fChain->GetBranch("myRPi0.dir2_mag");
   b_myRPi0_Chg_1 = fChain->GetBranch("myRPi0.Chg_1");
   b_myRPi0_Chg_2 = fChain->GetBranch("myRPi0.Chg_2");
   b_myRPi0_wChg_1 = fChain->GetBranch("myRPi0.wChg_1");
   b_myRPi0_wChg_2 = fChain->GetBranch("myRPi0.wChg_2");
   b_myRPi0_E_1 = fChain->GetBranch("myRPi0.E_1");
   b_myRPi0_E_2 = fChain->GetBranch("myRPi0.E_2");
   b_myRPi0_mass = fChain->GetBranch("myRPi0.mass");
   b_myRPi0_CosAng_1 = fChain->GetBranch("myRPi0.CosAng_1");
   b_myRTrak_ = fChain->GetBranch("myRTrak");
   b_myRTrak_fUniqueID = fChain->GetBranch("myRTrak.fUniqueID");
   b_myRTrak_fBits = fChain->GetBranch("myRTrak.fBits");
   b_myRTrak_iter = fChain->GetBranch("myRTrak.iter");
   b_myRTrak_likelihood = fChain->GetBranch("myRTrak.likelihood");
   b_myRTrak_trklength = fChain->GetBranch("myRTrak.trklength");
   b_myRTrak_amITransRoe = fChain->GetBranch("myRTrak.amITransRoe");
   b_myTransRFull_ = fChain->GetBranch("myTransRFull");
   b_myTransRFull_fUniqueID = fChain->GetBranch("myTransRFull.fUniqueID");
   b_myTransRFull_fBits = fChain->GetBranch("myTransRFull.fBits");
   b_myTransRFull_trans_trkCent_x = fChain->GetBranch("myTransRFull.trans_trkCent_x");
   b_myTransRFull_trans_trkCent_y = fChain->GetBranch("myTransRFull.trans_trkCent_y");
   b_myTransRFull_trans_trkCent_z = fChain->GetBranch("myTransRFull.trans_trkCent_z");
   b_myTransRFull_trans_trkCent_mag = fChain->GetBranch("myTransRFull.trans_trkCent_mag");
   b_myTransRFull_trans_trkCent_time = fChain->GetBranch("myTransRFull.trans_trkCent_time");
   b_myTransRFull_trans_dir_x = fChain->GetBranch("myTransRFull.trans_dir_x");
   b_myTransRFull_trans_dir_y = fChain->GetBranch("myTransRFull.trans_dir_y");
   b_myTransRFull_trans_dir_z = fChain->GetBranch("myTransRFull.trans_dir_z");
   b_myTransRFull_trans_dir_mag = fChain->GetBranch("myTransRFull.trans_dir_mag");
   b_myTransRFull_trans_length = fChain->GetBranch("myTransRFull.trans_length");
   b_myTransRFull_trans_vertex_x = fChain->GetBranch("myTransRFull.trans_vertex_x");
   b_myTransRFull_trans_vertex_y = fChain->GetBranch("myTransRFull.trans_vertex_y");
   b_myTransRFull_trans_vertex_z = fChain->GetBranch("myTransRFull.trans_vertex_z");
   b_myTransRFull_trans_vertex_mag = fChain->GetBranch("myTransRFull.trans_vertex_mag");
   b_myTransRFull_trans_vertex_time = fChain->GetBranch("myTransRFull.trans_vertex_time");
   b_myTransRFull_trans_chg_infit = fChain->GetBranch("myTransRFull.trans_chg_infit");
   b_myTransRFull_trans_chg_wgt_infit = fChain->GetBranch("myTransRFull.trans_chg_wgt_infit");
   b_myTransRFull_trans_chisq_a_infit = fChain->GetBranch("myTransRFull.trans_chisq_a_infit");
   b_myTransRFull_trans_chisq_r_infit = fChain->GetBranch("myTransRFull.trans_chisq_r_infit");
   b_myTransRFull_trans_weight_tot = fChain->GetBranch("myTransRFull.trans_weight_tot");
   b_myTransRFull_trans_chisq_avg = fChain->GetBranch("myTransRFull.trans_chisq_avg");
   b_myTransRFull_trans_rtowall = fChain->GetBranch("myTransRFull.trans_rtowall");
   b_myTransRFull_trans_energy = fChain->GetBranch("myTransRFull.trans_energy");
   b_myTransRFull_trans_length_mu = fChain->GetBranch("myTransRFull.trans_length_mu");
   b_myTransRFull_trans_energy_mu = fChain->GetBranch("myTransRFull.trans_energy_mu");
   b_myTransRFull_trans_numhits_infit = fChain->GetBranch("myTransRFull.trans_numhits_infit");
   b_myTransRFull_trans_chglength_nue = fChain->GetBranch("myTransRFull.trans_chglength_nue");
   b_myTransRFull_trans_numlowt_nue = fChain->GetBranch("myTransRFull.trans_numlowt_nue[10]");
   b_myTransRPi0_ = fChain->GetBranch("myTransRPi0");
   b_myTransRPi0_fUniqueID = fChain->GetBranch("myTransRPi0.fUniqueID");
   b_myTransRPi0_fBits = fChain->GetBranch("myTransRPi0.fBits");
   b_myTransRPi0_trans_vertex_x = fChain->GetBranch("myTransRPi0.trans_vertex_x");
   b_myTransRPi0_trans_vertex_y = fChain->GetBranch("myTransRPi0.trans_vertex_y");
   b_myTransRPi0_trans_vertex_z = fChain->GetBranch("myTransRPi0.trans_vertex_z");
   b_myTransRPi0_trans_vertex_mag = fChain->GetBranch("myTransRPi0.trans_vertex_mag");
   b_myTransRPi0_trans_time = fChain->GetBranch("myTransRPi0.trans_time");
   b_myTransRPi0_trans_Shift_1 = fChain->GetBranch("myTransRPi0.trans_Shift_1");
   b_myTransRPi0_trans_Shift_2 = fChain->GetBranch("myTransRPi0.trans_Shift_2");
   b_myTransRPi0_trans_dir1_x = fChain->GetBranch("myTransRPi0.trans_dir1_x");
   b_myTransRPi0_trans_dir1_y = fChain->GetBranch("myTransRPi0.trans_dir1_y");
   b_myTransRPi0_trans_dir1_z = fChain->GetBranch("myTransRPi0.trans_dir1_z");
   b_myTransRPi0_trans_dir1_mag = fChain->GetBranch("myTransRPi0.trans_dir1_mag");
   b_myTransRPi0_trans_dir2_x = fChain->GetBranch("myTransRPi0.trans_dir2_x");
   b_myTransRPi0_trans_dir2_y = fChain->GetBranch("myTransRPi0.trans_dir2_y");
   b_myTransRPi0_trans_dir2_z = fChain->GetBranch("myTransRPi0.trans_dir2_z");
   b_myTransRPi0_trans_dir2_mag = fChain->GetBranch("myTransRPi0.trans_dir2_mag");
   b_myTransRPi0_trans_Chg_1 = fChain->GetBranch("myTransRPi0.trans_Chg_1");
   b_myTransRPi0_trans_Chg_2 = fChain->GetBranch("myTransRPi0.trans_Chg_2");
   b_myTransRPi0_trans_wChg_1 = fChain->GetBranch("myTransRPi0.trans_wChg_1");
   b_myTransRPi0_trans_wChg_2 = fChain->GetBranch("myTransRPi0.trans_wChg_2");
   b_myTransRPi0_trans_E_1 = fChain->GetBranch("myTransRPi0.trans_E_1");
   b_myTransRPi0_trans_E_2 = fChain->GetBranch("myTransRPi0.trans_E_2");
   b_myTransRPi0_trans_mass = fChain->GetBranch("myTransRPi0.trans_mass");
   b_myTransRPi0_trans_CosAng_1 = fChain->GetBranch("myTransRPi0.trans_CosAng_1");
   b_myTransRTrak_ = fChain->GetBranch("myTransRTrak");
   b_myTransRTrak_fUniqueID = fChain->GetBranch("myTransRTrak.fUniqueID");
   b_myTransRTrak_fBits = fChain->GetBranch("myTransRTrak.fBits");
   b_myTransRTrak_trans_iter = fChain->GetBranch("myTransRTrak.trans_iter");
   b_myTransRTrak_trans_likelihood = fChain->GetBranch("myTransRTrak.trans_likelihood");
   b_myTransRTrak_trans_trklength = fChain->GetBranch("myTransRTrak.trans_trklength");
   b_myRecoCon_ = fChain->GetBranch("myRecoCon");
   b_myRecoCon_fUniqueID = fChain->GetBranch("myRecoCon.fUniqueID");
   b_myRecoCon_fBits = fChain->GetBranch("myRecoCon.fBits");
   b_myRecoCon_trkType = fChain->GetBranch("myRecoCon.trkType");
   b_myRecoCon_mass = fChain->GetBranch("myRecoCon.mass");
   b_myRecoCon_x = fChain->GetBranch("myRecoCon.x");
   b_myRecoCon_y = fChain->GetBranch("myRecoCon.y");
   b_myRecoCon_z = fChain->GetBranch("myRecoCon.z");
   b_myRecoCon_ver_mag = fChain->GetBranch("myRecoCon.ver_mag");
   b_myRecoCon_ux = fChain->GetBranch("myRecoCon.ux");
   b_myRecoCon_uy = fChain->GetBranch("myRecoCon.uy");
   b_myRecoCon_uz = fChain->GetBranch("myRecoCon.uz");
   b_myRecoCon_dir_mag = fChain->GetBranch("myRecoCon.dir_mag");
   b_myRecoCon_time = fChain->GetBranch("myRecoCon.time");
   b_myRecoCon_energy = fChain->GetBranch("myRecoCon.energy");
   b_myRecoDisj_ = fChain->GetBranch("myRecoDisj");
   b_myRecoDisj_fUniqueID = fChain->GetBranch("myRecoDisj.fUniqueID");
   b_myRecoDisj_fBits = fChain->GetBranch("myRecoDisj.fBits");
   b_myRecoDisj_iter = fChain->GetBranch("myRecoDisj.iter");
   b_myRecoDisj_trkType = fChain->GetBranch("myRecoDisj.trkType[2]");
   b_myRecoDisj_x = fChain->GetBranch("myRecoDisj.x[2]");
   b_myRecoDisj_y = fChain->GetBranch("myRecoDisj.y[2]");
   b_myRecoDisj_z = fChain->GetBranch("myRecoDisj.z[2]");
   b_myRecoDisj_ver_mag = fChain->GetBranch("myRecoDisj.ver_mag[2]");
   b_myRecoDisj_ux = fChain->GetBranch("myRecoDisj.ux[2]");
   b_myRecoDisj_uy = fChain->GetBranch("myRecoDisj.uy[2]");
   b_myRecoDisj_uz = fChain->GetBranch("myRecoDisj.uz[2]");
   b_myRecoDisj_dir_mag = fChain->GetBranch("myRecoDisj.dir_mag[2]");
   b_myRecoDisj_time = fChain->GetBranch("myRecoDisj.time[2]");
   b_myRecoDisj_energy = fChain->GetBranch("myRecoDisj.energy[2]");
   b_myRecoDisj_distMeanCer = fChain->GetBranch("myRecoDisj.distMeanCer[2]");
   b_myRecoDisj_fluxScale = fChain->GetBranch("myRecoDisj.fluxScale");
   b_myRecoDisj_relSci = fChain->GetBranch("myRecoDisj.relSci");
   b_myRecoDisj_likelihood = fChain->GetBranch("myRecoDisj.likelihood");
   b_myRecoOneTrk_ = fChain->GetBranch("myRecoOneTrk");
   b_myRecoOneTrk_fUniqueID = fChain->GetBranch("myRecoOneTrk.fUniqueID");
   b_myRecoOneTrk_fBits = fChain->GetBranch("myRecoOneTrk.fBits");
   b_myRecoOneTrk_iter = fChain->GetBranch("myRecoOneTrk.iter");
   b_myRecoOneTrk_trkType = fChain->GetBranch("myRecoOneTrk.trkType");
   b_myRecoOneTrk_x = fChain->GetBranch("myRecoOneTrk.x");
   b_myRecoOneTrk_y = fChain->GetBranch("myRecoOneTrk.y");
   b_myRecoOneTrk_z = fChain->GetBranch("myRecoOneTrk.z");
   b_myRecoOneTrk_ver_mag = fChain->GetBranch("myRecoOneTrk.ver_mag");
   b_myRecoOneTrk_ux = fChain->GetBranch("myRecoOneTrk.ux");
   b_myRecoOneTrk_uy = fChain->GetBranch("myRecoOneTrk.uy");
   b_myRecoOneTrk_uz = fChain->GetBranch("myRecoOneTrk.uz");
   b_myRecoOneTrk_dir_mag = fChain->GetBranch("myRecoOneTrk.dir_mag");
   b_myRecoOneTrk_time = fChain->GetBranch("myRecoOneTrk.time");
   b_myRecoOneTrk_energy = fChain->GetBranch("myRecoOneTrk.energy");
   b_myRecoOneTrk_distMean = fChain->GetBranch("myRecoOneTrk.distMean");
   b_myRecoOneTrk_fluxScale = fChain->GetBranch("myRecoOneTrk.fluxScale");
   b_myRecoOneTrk_relSci = fChain->GetBranch("myRecoOneTrk.relSci");
   b_myRecoOneTrk_likelihood = fChain->GetBranch("myRecoOneTrk.likelihood");
   b_myRecoTwoTrk_ = fChain->GetBranch("myRecoTwoTrk");
   b_myRecoTwoTrk_fUniqueID = fChain->GetBranch("myRecoTwoTrk.fUniqueID");
   b_myRecoTwoTrk_fBits = fChain->GetBranch("myRecoTwoTrk.fBits");
   b_myRecoTwoTrk_trackType1 = fChain->GetBranch("myRecoTwoTrk.trackType1");
   b_myRecoTwoTrk_trackType2 = fChain->GetBranch("myRecoTwoTrk.trackType2");
   b_myRecoTwoTrk_x = fChain->GetBranch("myRecoTwoTrk.x");
   b_myRecoTwoTrk_y = fChain->GetBranch("myRecoTwoTrk.y");
   b_myRecoTwoTrk_z = fChain->GetBranch("myRecoTwoTrk.z");
   b_myRecoTwoTrk_ver_mag = fChain->GetBranch("myRecoTwoTrk.ver_mag");
   b_myRecoTwoTrk_ux1 = fChain->GetBranch("myRecoTwoTrk.ux1");
   b_myRecoTwoTrk_uy1 = fChain->GetBranch("myRecoTwoTrk.uy1");
   b_myRecoTwoTrk_uz1 = fChain->GetBranch("myRecoTwoTrk.uz1");
   b_myRecoTwoTrk_dir_mag1 = fChain->GetBranch("myRecoTwoTrk.dir_mag1");
   b_myRecoTwoTrk_time = fChain->GetBranch("myRecoTwoTrk.time");
   b_myRecoTwoTrk_mass = fChain->GetBranch("myRecoTwoTrk.mass");
   b_myRecoTwoTrk_cosOp = fChain->GetBranch("myRecoTwoTrk.cosOp");
   b_myRecoTwoTrk_energy1 = fChain->GetBranch("myRecoTwoTrk.energy1");
   b_myRecoTwoTrk_distMeanCer1 = fChain->GetBranch("myRecoTwoTrk.distMeanCer1");
   b_myRecoTwoTrk_distMeanCer2 = fChain->GetBranch("myRecoTwoTrk.distMeanCer2");
   b_myRecoTwoTrk_convlen1 = fChain->GetBranch("myRecoTwoTrk.convlen1");
   b_myRecoTwoTrk_ux2 = fChain->GetBranch("myRecoTwoTrk.ux2");
   b_myRecoTwoTrk_uy2 = fChain->GetBranch("myRecoTwoTrk.uy2");
   b_myRecoTwoTrk_uz2 = fChain->GetBranch("myRecoTwoTrk.uz2");
   b_myRecoTwoTrk_dir_mag2 = fChain->GetBranch("myRecoTwoTrk.dir_mag2");
   b_myRecoTwoTrk_energy2 = fChain->GetBranch("myRecoTwoTrk.energy2");
   b_myRecoTwoTrk_convlen2 = fChain->GetBranch("myRecoTwoTrk.convlen2");
   b_myRecoTwoTrk_fluxScale = fChain->GetBranch("myRecoTwoTrk.fluxScale");
   b_myRecoTwoTrk_relSci = fChain->GetBranch("myRecoTwoTrk.relSci");
   b_myRecoTwoTrk_Qlikelihood = fChain->GetBranch("myRecoTwoTrk.Qlikelihood");
   b_myRecoTwoTrk_Tlikelihood = fChain->GetBranch("myRecoTwoTrk.Tlikelihood");
   b_myRecoTwoTrk_likelihood = fChain->GetBranch("myRecoTwoTrk.likelihood");
   b_myRecoTwoTrk_fixedMass = fChain->GetBranch("myRecoTwoTrk.fixedMass");
   b_myRecoOneTrkMu_ = fChain->GetBranch("myRecoOneTrkMu");
   b_myRecoOneTrkMu_fUniqueID = fChain->GetBranch("myRecoOneTrkMu.fUniqueID");
   b_myRecoOneTrkMu_fBits = fChain->GetBranch("myRecoOneTrkMu.fBits");
   b_myRecoOneTrkMu_iter = fChain->GetBranch("myRecoOneTrkMu.iter");
   b_myRecoOneTrkMu_trkType = fChain->GetBranch("myRecoOneTrkMu.trkType");
   b_myRecoOneTrkMu_x = fChain->GetBranch("myRecoOneTrkMu.x");
   b_myRecoOneTrkMu_y = fChain->GetBranch("myRecoOneTrkMu.y");
   b_myRecoOneTrkMu_z = fChain->GetBranch("myRecoOneTrkMu.z");
   b_myRecoOneTrkMu_ver_mag = fChain->GetBranch("myRecoOneTrkMu.ver_mag");
   b_myRecoOneTrkMu_ux = fChain->GetBranch("myRecoOneTrkMu.ux");
   b_myRecoOneTrkMu_uy = fChain->GetBranch("myRecoOneTrkMu.uy");
   b_myRecoOneTrkMu_uz = fChain->GetBranch("myRecoOneTrkMu.uz");
   b_myRecoOneTrkMu_dir_mag = fChain->GetBranch("myRecoOneTrkMu.dir_mag");
   b_myRecoOneTrkMu_time = fChain->GetBranch("myRecoOneTrkMu.time");
   b_myRecoOneTrkMu_energy = fChain->GetBranch("myRecoOneTrkMu.energy");
   b_myRecoOneTrkMu_distMean = fChain->GetBranch("myRecoOneTrkMu.distMean");
   b_myRecoOneTrkMu_fluxScale = fChain->GetBranch("myRecoOneTrkMu.fluxScale");
   b_myRecoOneTrkMu_relSci = fChain->GetBranch("myRecoOneTrkMu.relSci");
   b_myRecoOneTrkMu_likelihood = fChain->GetBranch("myRecoOneTrkMu.likelihood");
   b_myRecoTwoTrkFix_ = fChain->GetBranch("myRecoTwoTrkFix");
   b_myRecoTwoTrkFix_fUniqueID = fChain->GetBranch("myRecoTwoTrkFix.fUniqueID");
   b_myRecoTwoTrkFix_fBits = fChain->GetBranch("myRecoTwoTrkFix.fBits");
   b_myRecoTwoTrkFix_trackType1 = fChain->GetBranch("myRecoTwoTrkFix.trackType1");
   b_myRecoTwoTrkFix_trackType2 = fChain->GetBranch("myRecoTwoTrkFix.trackType2");
   b_myRecoTwoTrkFix_x = fChain->GetBranch("myRecoTwoTrkFix.x");
   b_myRecoTwoTrkFix_y = fChain->GetBranch("myRecoTwoTrkFix.y");
   b_myRecoTwoTrkFix_z = fChain->GetBranch("myRecoTwoTrkFix.z");
   b_myRecoTwoTrkFix_ver_mag = fChain->GetBranch("myRecoTwoTrkFix.ver_mag");
   b_myRecoTwoTrkFix_ux1 = fChain->GetBranch("myRecoTwoTrkFix.ux1");
   b_myRecoTwoTrkFix_uy1 = fChain->GetBranch("myRecoTwoTrkFix.uy1");
   b_myRecoTwoTrkFix_uz1 = fChain->GetBranch("myRecoTwoTrkFix.uz1");
   b_myRecoTwoTrkFix_dir_mag1 = fChain->GetBranch("myRecoTwoTrkFix.dir_mag1");
   b_myRecoTwoTrkFix_time = fChain->GetBranch("myRecoTwoTrkFix.time");
   b_myRecoTwoTrkFix_mass = fChain->GetBranch("myRecoTwoTrkFix.mass");
   b_myRecoTwoTrkFix_cosOp = fChain->GetBranch("myRecoTwoTrkFix.cosOp");
   b_myRecoTwoTrkFix_energy1 = fChain->GetBranch("myRecoTwoTrkFix.energy1");
   b_myRecoTwoTrkFix_distMeanCer1 = fChain->GetBranch("myRecoTwoTrkFix.distMeanCer1");
   b_myRecoTwoTrkFix_distMeanCer2 = fChain->GetBranch("myRecoTwoTrkFix.distMeanCer2");
   b_myRecoTwoTrkFix_convlen1 = fChain->GetBranch("myRecoTwoTrkFix.convlen1");
   b_myRecoTwoTrkFix_ux2 = fChain->GetBranch("myRecoTwoTrkFix.ux2");
   b_myRecoTwoTrkFix_uy2 = fChain->GetBranch("myRecoTwoTrkFix.uy2");
   b_myRecoTwoTrkFix_uz2 = fChain->GetBranch("myRecoTwoTrkFix.uz2");
   b_myRecoTwoTrkFix_dir_mag2 = fChain->GetBranch("myRecoTwoTrkFix.dir_mag2");
   b_myRecoTwoTrkFix_energy2 = fChain->GetBranch("myRecoTwoTrkFix.energy2");
   b_myRecoTwoTrkFix_convlen2 = fChain->GetBranch("myRecoTwoTrkFix.convlen2");
   b_myRecoTwoTrkFix_fluxScale = fChain->GetBranch("myRecoTwoTrkFix.fluxScale");
   b_myRecoTwoTrkFix_relSci = fChain->GetBranch("myRecoTwoTrkFix.relSci");
   b_myRecoTwoTrkFix_Qlikelihood = fChain->GetBranch("myRecoTwoTrkFix.Qlikelihood");
   b_myRecoTwoTrkFix_Tlikelihood = fChain->GetBranch("myRecoTwoTrkFix.Tlikelihood");
   b_myRecoTwoTrkFix_likelihood = fChain->GetBranch("myRecoTwoTrkFix.likelihood");
   b_myRecoTwoTrkFix_fixedMass = fChain->GetBranch("myRecoTwoTrkFix.fixedMass");
   b_myStFast_ = fChain->GetBranch("myStFast");
   b_myStFast_fUniqueID = fChain->GetBranch("myStFast.fUniqueID");
   b_myStFast_fBits = fChain->GetBranch("myStFast.fBits");
   b_myStFast_iter = fChain->GetBranch("myStFast.iter");
   b_myStFast_vertex_x = fChain->GetBranch("myStFast.vertex_x");
   b_myStFast_vertex_y = fChain->GetBranch("myStFast.vertex_y");
   b_myStFast_vertex_z = fChain->GetBranch("myStFast.vertex_z");
   b_myStFast_vertex_mag = fChain->GetBranch("myStFast.vertex_mag");
   b_myStFast_dir_x = fChain->GetBranch("myStFast.dir_x");
   b_myStFast_dir_y = fChain->GetBranch("myStFast.dir_y");
   b_myStFast_dir_z = fChain->GetBranch("myStFast.dir_z");
   b_myStFast_dir_mag = fChain->GetBranch("myStFast.dir_mag");
   b_myStFast_time = fChain->GetBranch("myStFast.time");
   b_myStFast_distance = fChain->GetBranch("myStFast.distance");
   b_myStFast_energy = fChain->GetBranch("myStFast.energy");
   b_myStFast_likelihood = fChain->GetBranch("myStFast.likelihood");
   b_myStFlux_ = fChain->GetBranch("myStFlux");
   b_myStFlux_fUniqueID = fChain->GetBranch("myStFlux.fUniqueID");
   b_myStFlux_fBits = fChain->GetBranch("myStFlux.fBits");
   b_myStFlux_iter = fChain->GetBranch("myStFlux.iter");
   b_myStFlux_likelihood = fChain->GetBranch("myStFlux.likelihood");
   b_myStFlux_cerenkov = fChain->GetBranch("myStFlux.cerenkov");
   b_myStFlux_scint = fChain->GetBranch("myStFlux.scint");
   b_myStFlux_Ecer_el = fChain->GetBranch("myStFlux.Ecer_el");
   b_myStFlux_Ecer_mu = fChain->GetBranch("myStFlux.Ecer_mu");
   b_myStFull_ = fChain->GetBranch("myStFull");
   b_myStFull_fUniqueID = fChain->GetBranch("myStFull.fUniqueID");
   b_myStFull_fBits = fChain->GetBranch("myStFull.fBits");
   b_myStFull_iter = fChain->GetBranch("myStFull.iter");
   b_myStFull_vertex_x = fChain->GetBranch("myStFull.vertex_x");
   b_myStFull_vertex_y = fChain->GetBranch("myStFull.vertex_y");
   b_myStFull_vertex_z = fChain->GetBranch("myStFull.vertex_z");
   b_myStFull_vertex_mag = fChain->GetBranch("myStFull.vertex_mag");
   b_myStFull_dir_x = fChain->GetBranch("myStFull.dir_x");
   b_myStFull_dir_y = fChain->GetBranch("myStFull.dir_y");
   b_myStFull_dir_z = fChain->GetBranch("myStFull.dir_z");
   b_myStFull_dir_mag = fChain->GetBranch("myStFull.dir_mag");
   b_myStFull_time = fChain->GetBranch("myStFull.time");
   b_myStFull_distance = fChain->GetBranch("myStFull.distance");
   b_myStFull_energy = fChain->GetBranch("myStFull.energy");
   b_myStFull_energy_mu = fChain->GetBranch("myStFull.energy_mu");
   b_myStFull_likelihood = fChain->GetBranch("myStFull.likelihood");
   b_myStFull_Stkint = fChain->GetBranch("myStFull.Stkint");
   b_myStFull_RdR = fChain->GetBranch("myStFull.RdR");
   b_myStFull_fqlt05 = fChain->GetBranch("myStFull.fqlt05");
   b_myStFull_fqlt10 = fChain->GetBranch("myStFull.fqlt10");
   b_myStFull_realver_x = fChain->GetBranch("myStFull.realver_x");
   b_myStFull_realver_y = fChain->GetBranch("myStFull.realver_y");
   b_myStFull_realver_z = fChain->GetBranch("myStFull.realver_z");
   b_myStFull_realver_mag = fChain->GetBranch("myStFull.realver_mag");
   b_myStFull_realver_time = fChain->GetBranch("myStFull.realver_time");
   b_myStPi0_ = fChain->GetBranch("myStPi0");
   b_myStPi0_fUniqueID = fChain->GetBranch("myStPi0.fUniqueID");
   b_myStPi0_fBits = fChain->GetBranch("myStPi0.fBits");
   b_myStPi0_iter = fChain->GetBranch("myStPi0.iter");
   b_myStPi0_vertex_x = fChain->GetBranch("myStPi0.vertex_x");
   b_myStPi0_vertex_y = fChain->GetBranch("myStPi0.vertex_y");
   b_myStPi0_vertex_z = fChain->GetBranch("myStPi0.vertex_z");
   b_myStPi0_vertex_mag = fChain->GetBranch("myStPi0.vertex_mag");
   b_myStPi0_time = fChain->GetBranch("myStPi0.time");
   b_myStPi0_likelihood = fChain->GetBranch("myStPi0.likelihood");
   b_myStPi0_mass = fChain->GetBranch("myStPi0.mass");
   b_myStPi0_darec = fChain->GetBranch("myStPi0.darec");
   b_myStPi0_fcer = fChain->GetBranch("myStPi0.fcer");
   b_myStPi0_phi1 = fChain->GetBranch("myStPi0.phi1");
   b_myStPi0_teta1 = fChain->GetBranch("myStPi0.teta1");
   b_myStPi0_phi2 = fChain->GetBranch("myStPi0.phi2");
   b_myStPi0_teta2 = fChain->GetBranch("myStPi0.teta2");
   b_myStPi0_cer1 = fChain->GetBranch("myStPi0.cer1");
   b_myStPi0_sci1 = fChain->GetBranch("myStPi0.sci1");
   b_myStPi0_cer2 = fChain->GetBranch("myStPi0.cer2");
   b_myStPi0_sci2 = fChain->GetBranch("myStPi0.sci2");
   b_myStPi0_srec1 = fChain->GetBranch("myStPi0.srec1");
   b_myStPi0_dist1 = fChain->GetBranch("myStPi0.dist1");
   b_myStPi0_srec2 = fChain->GetBranch("myStPi0.srec2");
   b_myStPi0_dist2 = fChain->GetBranch("myStPi0.dist2");
   b_myStPi0_dir1_x = fChain->GetBranch("myStPi0.dir1_x");
   b_myStPi0_dir1_y = fChain->GetBranch("myStPi0.dir1_y");
   b_myStPi0_dir1_z = fChain->GetBranch("myStPi0.dir1_z");
   b_myStPi0_dir1_mag = fChain->GetBranch("myStPi0.dir1_mag");
   b_myStPi0_dir2_x = fChain->GetBranch("myStPi0.dir2_x");
   b_myStPi0_dir2_y = fChain->GetBranch("myStPi0.dir2_y");
   b_myStPi0_dir2_z = fChain->GetBranch("myStPi0.dir2_z");
   b_myStPi0_dir2_mag = fChain->GetBranch("myStPi0.dir2_mag");
   b_myStTrak_ = fChain->GetBranch("myStTrak");
   b_myStTrak_fUniqueID = fChain->GetBranch("myStTrak.fUniqueID");
   b_myStTrak_fBits = fChain->GetBranch("myStTrak.fBits");
   b_myStTrak_iter = fChain->GetBranch("myStTrak.iter");
   b_myStTrak_likelihood = fChain->GetBranch("myStTrak.likelihood");
   b_myStTrak_trklength = fChain->GetBranch("myStTrak.trklength");
   b_myStVarsTwo_ = fChain->GetBranch("myStVarsTwo");
   b_myStVarsTwo_fUniqueID = fChain->GetBranch("myStVarsTwo.fUniqueID");
   b_myStVarsTwo_fBits = fChain->GetBranch("myStVarsTwo.fBits");
   b_myStVarsTwo_CTH_n000 = fChain->GetBranch("myStVarsTwo.CTH_n000[20]");
   b_myStVarsTwo_CTH_nhit = fChain->GetBranch("myStVarsTwo.CTH_nhit[20]");
   b_myStVarsTwo_RS_n000 = fChain->GetBranch("myStVarsTwo.RS_n000[20]");
   b_myStVarsTwo_RS_nhit = fChain->GetBranch("myStVarsTwo.RS_nhit[20]");
   b_myStVarsTwo_TIM_nhit = fChain->GetBranch("myStVarsTwo.TIM_nhit[10]");
   b_myStVarsTwo_CTH_mu = fChain->GetBranch("myStVarsTwo.CTH_mu[20]");
   b_myStVarsTwo_CTH_qrec = fChain->GetBranch("myStVarsTwo.CTH_qrec[20]");
   b_myStVarsTwo_CTH_chia = fChain->GetBranch("myStVarsTwo.CTH_chia[20]");
   b_myStVarsTwo_CTH_qllk000 = fChain->GetBranch("myStVarsTwo.CTH_qllk000[20]");
   b_myStVarsTwo_CTH_qllkhit = fChain->GetBranch("myStVarsTwo.CTH_qllkhit[20]");
   b_myStVarsTwo_CTH_tllk = fChain->GetBranch("myStVarsTwo.CTH_tllk[20]");
   b_myStVarsTwo_RS_qrec = fChain->GetBranch("myStVarsTwo.RS_qrec[20]");
   b_myStVarsTwo_RS_mu = fChain->GetBranch("myStVarsTwo.RS_mu[20]");
   b_myStVarsTwo_TIM_qrec = fChain->GetBranch("myStVarsTwo.TIM_qrec[10]");
   b_myStVarsTwo_TIM_mu = fChain->GetBranch("myStVarsTwo.TIM_mu[10]");

   return kTRUE;
}

void outputTree::Show(Int_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t outputTree::Cut(Int_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef outputTree_cxx
