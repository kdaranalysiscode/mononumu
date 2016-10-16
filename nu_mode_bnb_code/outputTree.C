#define outputTree_cxx
#include "outputTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TF1.h"
#include "TH1F.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include "TLegend.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TPostScript.h"
#include "THistPainter.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "THStack.h"
#include "TGraph.h"
#include "TH2F.h"
#include "TLine.h"
#include "TArrow.h"
#include "TROOT.h"

using namespace std;

bool testst = 1;

void outputTree::Loop()
{

int nModels = 11;

TH1D *qsqRatios[nModels];
TFile *qsqRatiosFile = new TFile("./numode_bnb_qsqRatios.root");
for (int i=0; i<nModels; i++)
        qsqRatiosFile->GetObject(Form("ratio_qsq_%d",i),qsqRatios[i]);

TCanvas *qsqC = new TCanvas();
qsqRatios[0]->Draw();
for (int i=0; i<nModels; i++)
        qsqRatios[i]->Draw("same");
qsqC->Print("qsqRatios.eps");

int nbins_qsq = qsqRatios[0]->GetNbinsX();

// x-factor par0 is 0.436741 par1 is 4.70812 par2 is -10.7837 par3 is 10.523 par4 is -4.65804 par5 is 0.765292

float a[6];//1.08 x-factor (true Enu-dep)
float x[5];//PRD ccpi wting fcn
float MW[5];//MW ccpip wting
float c[5];//low stat flux sampling correction

for (int i=0; i<5; i++) x[i] = 0;

x[0] = 0.721998;
x[1] = 6.21904;
x[2] = -11.6201;
x[3] = 8.89313;
x[4] = -2.32006;

for (int i=0; i<6; i++) a[i] = 0;

a[0] = 0.436741;
a[1] = 4.70812;
a[2] = -10.7837;
a[3] = 10.523;
a[4] = -4.65804;
a[5] = 0.765292;

for (int i=0; i<5; i++) MW[i] = 0;

MW[0] = 0.746361;
MW[1] = 3.41205;
MW[2] = -5.27101;
MW[3] = 3.48269;
MW[4] = -0.953554;

for (int i=0; i<5; i++) c[i] = 0;

c[0] = 1.549;
c[1] = -2.475;
c[2] = 3.809;
c[3] = -2.375;
c[4] = 0.5036;

float fourSE_MC = 0;
float fourSE_data = 0;

float truEnu = 0;
float truEmu = 0;
float truTmu = 0;
float truEnu2 = 0;
float truMuPx = 0;
float truMuPy = 0;
float truMuPz = 0;
float truMuP  = 0;
float truUX = 0;
float truUY = 0;
float truUZ = 0;
float theta_Xtru = 0;
float theta_Ytru = 0;
float theta_Ztru = 0;
float recoTheta;
float truQsq = 0;
float Qsq = 0;
float EnuQE = 0;
float Tmu = 0;
float Pmu = 0;
float CosThetamu = 0.;
float recoUX = 0.;
float recoUY = 0.;
float recoUZ = 0.;
double wt[nModels];
for (int i=0; i<nModels; i++)
        wt[i] = 0.;
float threeMomDiff = 0.;

float thetaX = 0.;
float thetaY = 0.;
float thetaZ = 0.;

float Mmu = 0.1056583;
float Mn = 0.93956;
float Mp = 0.93827;
float BE = 0.030;//diff in mass of final nucleus bet nu CCQE, nubar CCQE (34 for nu)
float Emu = 0;
float muLk = 0;
float elLk = 0;
float muLk_2se = 0;
float elLk_2se = 0;
float deltaLk = 0;
float deltaLk_2se = 0;
float nuModeQExFactor = 0;
float ccpiRewt = 0;
float xsecWght = 0;
float fluxWght = 0;
float totalWght = 0;
float datacnt = 0;
float muX = 0;
float muY = 0;
float muZ = 0;
float muR = 0;
float muUX = 0;
float muUY = 0;
float muUZ = 0;
float elX = 0;
float elY = 0;
float elZ = 0;
float elUX = 0;
float elUY = 0;
float elUZ = 0;
float elR = 0;
float michE = 0;
float michE_muHyp = 0;
float Range = 0;
float adjRange = 0.;

float tHits_1SE = 0;
float tHits_2SE = 0;
float stVertx = 0;
float truEnuQE = 0.;

float truTmuUB = 0;
float truTmuOB = 0;
float truEnuUB = 0;
float truEnuOB = 0;

int  Channel = 0;
int  nuType = 0;
int  MCfileCount = 0;
bool CCQE = 0;
bool CCpi = 0;
float CCpi0cnt = 0;
bool obsCCpi = 0;
bool pip = 0;
bool mum = 0;
bool mu = 0;
bool RSorWS = 0;
bool pipParent = 0;
bool signal = 0;

int nfsp = 0;
int ndcy = 0;
bool obsCCpi0;
float obsCCpi0cnt = 0;
int pizCnt = 0;
int totPiCnt = 0;
int gID = 0;
int nuancePimCnt = 0;
int nuancePipCnt = 0;
int detmcPimCnt = 0;
int detmcPipCnt = 0;
int trueFSpiCnt = 0;
float totCCpim = 0;
float totCCpip = 0;
float passNucCCpim = 0;
float passNucCCpip = 0;
float passDetCCpim = 0;
float passDetCCpip = 0;

float highEnuCCpi = 0;
float highEnuTotalMC = 0;

float pT = 0;
float pZ = 0;
float pT_fin = 0;
float pZ_fin = 0;
float pX_fin = 0;
float pY_fin = 0;
float theta = 0;
float pTot = 0;
float total = 0;
float insideHarp = 0;

//-----------------------------------------------------------
//    WHICH CUTS DO YOU WANT I CAN MAKE THEM FOR YOU
//-----------------------------------------------------------

bool doTmuCut   = 1;
bool doFidCut   = 1;
bool doLkCut    = 1;
bool doReverseLkCut = 0;

bool doRngCut   = 1;
bool do100cmCut = 1;

bool doBeamWindow = 1;
bool doVhits      = 1;

bool doTwoSE   = 1;

bool doMichDist = 0;

bool doUZcut = 0;

bool doMuEndRcut = 0;

bool doDefCuts = 1;

bool doGenRcut = 1;

//--------------------------------------------------------------------------
//    WHICH WEIGHTING OPTIONS DO YOU WANT I CAN MAKE THEM FOR YOU
//--------------------------------------------------------------------------

bool tryQuadWS = 1;

bool doNpi = 1;
bool doTKCCpiPRDrewt = 1;
bool doWSqeWtToData = 1;

bool doCCpi0rewt = 1;
bool CCpi0 = 0;

bool doNewMCmodel = 1;

bool sigEqBoundP = 1;

bool doSamplCorr = 0;//controlled by doNewMCmodel!
bool doTwoDwt = 0;
bool doH2highEnuCorr = 0;

if (doNewMCmodel){

  doSamplCorr = 1;
  doTwoDwt = 1;
  doH2highEnuCorr = 1;
  
}

if (doNewMCmodel==0){

  doSamplCorr = 0;
  doTwoDwt = 0;
  doH2highEnuCorr = 0;

}

float TepXfact[41];//bin widths are 0.05 GeV, from email from Teppei 6/3/10
float truEnuBinz[41];

for (int i=0; i<=40; i++) TepXfact[i] = 0;
for (int i=0; i<=40; i++) truEnuBinz[i] = 0;
for (int i=0; i<=40; i++) truEnuBinz[i+1] = truEnuBinz[i] + 0.05;

//--------------------------------------------------------------------------

float jul07cnt = 0;
float sep09cnt = 0;
float mar10cnt = 0;
float oct10cnt = 0;
float may11cnt = 0;
float mar12cnt = 0;

float pipCnt = 0;
float WS = 0;
float thing = 0;

float MichDist = 0;
float muRange = 0;
float muRange_st = 0.;
float beamAveTime = 0;
double tDiff = 0;
float beamAveTimeOT = 0;
float vHit1 = 0;
float vHit2 = 0;
float vHit3 = 0;
float ZeroabsMCwSt = 0;
float eb = 1;
bool H2scat = 0;
float recoX = 0;
float recoY = 0;
float recoZ = 0;
float endMuX = 0;
float endMuY = 0;
float endMuZ = 0;

float stancuUZ = 0.;
float stancuTmu = 0.;

int recoTmuBin = 0;
int truTmuBin = 0;

float muEndCut = 400;

float nuUX = 0.;
float nuUY = 0.;
float nuUZ = 0.;

float truX = 0;
float truY = 0;
float truZ = 0;
float truR = 0;

double recoTwoD = 0;
double trueTwoD = 0;

bool passV = 0;
int numSE = 0;

int numMCfiles = 3;
int numStrobeFiles = 0;
int numDirtFiles = 0;
int numQtCorrFiles = 3;
int numDiscFiles = 3;

int parent = 0;
bool sig = 0;

TH1F *spitzVar_data = new TH1F("spitzVar_data","",40,0,0.25);
TH1F *spitzVar_mc[nModels];
TH1F *spitzVar_dirt_r[nModels];
TH1F *spitzVar_mc_largeRng[nModels];

double lastt = 200.;

if (testst) lastt = 300.;

TH1F *thits_data = new TH1F("thits_data","",100,0,lastt);
TH1F *thits_data_largeRng = new TH1F("thits_data_largeRng","",100,0,1000);
TH1F *thits_mc[nModels];
TH1F *thits_mc_largeRng[nModels];
TH1F *thits_pip[nModels];
TH1F *thits_pim[nModels];
TH1F *thits_kp[nModels];
TH1F *thits_dirt[nModels];
TH1F *thits_othr[nModels];

int tmu_bins_fold = 120;
double first_tmu = 0.;
double last_tmu = 120.;//MeV

TH1F *tmu_mc_cv = new TH1F("tmu_mc_cv","",tmu_bins_fold,first_tmu,last_tmu);
TH1F *tmu_mc_qtcorr = new TH1F("tmu_mc_qtcorr","",tmu_bins_fold,first_tmu,last_tmu);
TH1F *tmu_mc_disc = new TH1F("tmu_mc_disc","",tmu_bins_fold,first_tmu,last_tmu);
TH1F *tmu_mc_qtcorr_ratio = new TH1F("tmu_mc_qtcorr_ratio","",tmu_bins_fold,first_tmu,last_tmu);
TH1F *tmu_mc_disc_ratio = new TH1F("tmu_mc_disc_ratio","",tmu_bins_fold,first_tmu,last_tmu);


int thitbins = 30;
double last = 300.;

TH1F *thits_mc_cv = new TH1F("thits_mc_cv","",thitbins,0.,last);
TH1F *thits_mc_qtcorr = new TH1F("thits_mc_qtcorr","",thitbins,0.,last);
TH1F *thits_mc_disc = new TH1F("thits_mc_disc","",thitbins,0.,last);
TH1F *thits_mc_qtcorr_ratio = new TH1F("thits_mc_qtcorr_ratio","",thitbins,0.,last);
TH1F *thits_mc_disc_ratio = new TH1F("thits_mc_disc_ratio","",thitbins,0.,last);

TH1F *thits_dataRng = new TH1F("thits_dataRng","",100,0,1000);
TH1F *thits_mcRng = new TH1F("thits_mcRng","",100,0,1000);
TH1F *thits_pipRng = new TH1F("thits_pipRng","",100,0,1000);
TH1F *thits_pimRng = new TH1F("thits_pimRng","",100,0,1000);
TH1F *thits_kpRng = new TH1F("thits_kpRng","",100,0,1000);
TH1F *thits_dirtRng = new TH1F("thits_dirtRng","",100,0,1000);
TH1F *thits_strobeRng = new TH1F("thits_strobeRng","",100,0,1000);

TH1F *fqlt10_data = new TH1F("fqlt10_data","",50,0,1);
TH1F *fqlt10_mc = new TH1F("fqlt10_mc","",50,0,1);

for (int i=0; i<nModels; i++){
  spitzVar_mc[i] = new TH1F(Form("spitzVar_mc_%d",i),"",40,0,0.25);
  spitzVar_dirt_r[i] = new TH1F(Form("spitzVar_dirt_r_%d",i),"",40,0,0.25);
  spitzVar_mc_largeRng[i] = new TH1F(Form("spitzVar_mc_largeRng_%d",i),"",100,0,1.0);

  thits_mc[i] = new TH1F(Form("thits_mc_%d",i),"",100,0,lastt);
  thits_mc_largeRng[i] = new TH1F(Form("thits_mc_largeRng_%d",i),"",100,0,1000);
  thits_pip[i] = new TH1F(Form("thits_pip_%d",i),"",100,0,lastt);
  thits_pim[i] = new TH1F(Form("thits_pim_%d",i),"",100,0,lastt);
  thits_kp[i] = new TH1F(Form("thits_kp_%d",i),"",100,0,lastt);
  thits_dirt[i] = new TH1F(Form("thits_dirt_%d",i),"",100,0,lastt);
  thits_othr[i] = new TH1F(Form("thits_othr_%d",i),"",100,0,lastt);
}

TH1F *thits_strobe = new TH1F("thits_strobe","",100,0,lastt);

TH1F *spitzVar_data_largeRng = new TH1F("spitzVar_data_largeRng","",100,0,1.0);

TH1F *spitzVar_strobe_largeRng = new TH1F("spitzVar_strobe_largeRng","",100,0,1.0);
TH1F *spitzVar_strobe = new TH1F("spitzVar_strobe","",40,0,0.25);

TH1F *spitzVar_dirt_largeRng = new TH1F("spitzVar_dirt_largeRng","",100,0,1.0);
TH1F *spitzVar_dirt = new TH1F("spitzVar_dirt","",40,0,0.25);
TH1F *dirt_channels = new TH1F("dirt_channels","",100,0.5,100.5);

TH1F *dirt_secSE = new TH1F("dirt_secSE","",100,0,200);
TH1F *strobe_secSE = new TH1F("strobe_secSE","",100,0,200);
TH1F *data_inbmp = new TH1F("data_inbmp","",100,0,200);
TH1F *data_outbmp = new TH1F("data_outbmp","",100,0,200);

TH1F *mc_inbmp = new TH1F("mc_inbmp","",100,0,200);
TH1F *mc_outbmp = new TH1F("mc_outbmp","",100,0,200);

TH1F *dirt_qsq_ccqe = new TH1F("dirt_qsq_ccqe","",50,0.,2.);
TH1F *mc_qsq_ccqe = new TH1F("mc_qsq_ccqe","",50,0.,2.);

TH1F *time_tot = new TH1F("time_tot","",80,0,20000);
TH1F *time_data = new TH1F("time_data","",80,0,20000);
TH1F *time_strobe = new TH1F("time_strobe","",80,0,20000);

TH1F *truEnu_tot = new TH1F("truEnu_tot","",80,0,4);
TH1F *truEnu_kP = new TH1F("truEnu_kP","",80,0,4);
TH1F *truEnu_pM = new TH1F("truEnu_pM","",80,0,4);

TH1F *truEnu_sig = new TH1F("truEnu_sig","",80,0,4);
TH1F *truEnu_piP = new TH1F("truEnu_piP","",80,0,4);
TH1F *truEnu_kL = new TH1F("truEnu_kL","",80,0,4);

TH1F *truTmu_kP = new TH1F("truTmu_kP","",100,0,4);
TH1F *truTmu_piP = new TH1F("truTmu_piP","",100,0,4);
TH1F *truTmu_tot = new TH1F("truTmu_tot","",100,0,4);

TH1F *recTmu_kP = new TH1F("recTmu_kP","",80,0,0.2);
TH1F *recTmu_piP = new TH1F("recTmu_piP","",80,0,0.2);
TH1F *recTmu_tot = new TH1F("recTmu_tot","",80,0,0.2);
TH1F *recTmu_tot_nokdar = new TH1F("truTmu_rec_nokdar","",80,0,0.2);
TH1F *recTmu_sig = new TH1F("recTmu_sig","",80,0,0.2);
TH1F *recTmu_data = new TH1F("recTmu_data","",80,0,0.2);
TH1F *recTmu_strobe = new TH1F("recTmu_strobe","",80,0,0.2);

TH1F *truUZ_kP = new TH1F("truUZ_kP","",100,-1,1);
TH1F *truUZ_piP = new TH1F("truUZ_piP","",100,-1,1);
TH1F *truUZ_tot = new TH1F("truUZ_tot","",100,-1,1);

TH1F *recUZ_kP = new TH1F("recUZ_kP","",30,-1,1);
TH1F *recUZ_piP = new TH1F("recUZ_piP","",30,-1,1);
TH1F *recUZ_tot = new TH1F("recUZ_tot","",30,-1,1);
TH1F *recUZ_data = new TH1F("recUZ_data","",30,-1,1);

TH1F *thetaZ_kP = new TH1F("thetaZ_kP","",30,0,TMath::Pi());
TH1F *thetaZ_piP = new TH1F("thetaZ_piP","",30,0,TMath::Pi());
TH1F *thetaZ_tot = new TH1F("thetaZ_tot","",30,0,TMath::Pi());
TH1F *thetaZ_data = new TH1F("thetaZ_data","",30,0,TMath::Pi());

TH1F *truThetaZ_sig = new TH1F("truThetaZ_sig","",20,0,TMath::Pi());
TH1F *truThetaY_sig = new TH1F("truThetaY_sig","",20,0,TMath::Pi());
TH1F *truThetaX_sig = new TH1F("truThetaX_sig","",20,0,TMath::Pi());

TH2F *truMinKinZ_sig = new TH2F("truMinKinZ_sig","",20,0,TMath::Pi(),20,0,0.1);
TH2F *truMinKinY_sig = new TH2F("truMinKinY_sig","",20,0,TMath::Pi(),20,0,0.1);
TH2F *truMinKinX_sig = new TH2F("truMinKinX_sig","",20,0,TMath::Pi(),20,0,0.1);

TH2F *pipEnThit = new TH2F("pipEnThit","",50,0,400,20,0,5);
TH2F *pipEnuThit = new TH2F("pipEnuThit","",50,0,400,50,0,2);
TH1F *pipEnu = new TH1F("pipEnu","",50,0,2);

TH1F *tHit1_noCut = new TH1F("tHit1_noCut","",100,0,300);
TH1F *tHit1_eff = new TH1F("tHit1_eff","",100,0,300);
TH1F *tHit1_kP = new TH1F("tHit1_kP","",100,0,300);
TH1F *tHit1_nc1pi = new TH1F("tHit1_nc1pi","",100,0,300);
TH1F *tHit1_ccqe = new TH1F("tHit1_ccqe","",100,0,300);
TH1F *tHit1_piP = new TH1F("tHit1_piP","",100,0,300);
TH1F *tHit1_tot = new TH1F("tHit1_tot","",100,0,300);
TH1F *tHit1_tot_nokdar = new TH1F("tHit1_tot_nokdar","",100,0,300);
TH1F *tHit1_data = new TH1F("tHit1_data","",100,0,300);
TH1F *tHit1_strobe = new TH1F("tHit1_strobe","",100,0,300);
TH1F *tHit1_data_timeBins[6];
TH1F *tHit2_data_firstBump = new TH1F("tHit2_data_firstBump","",40,0,200);
TH1F *tHit2_data_secondBump = new TH1F("tHit2_data_secondBump","",40,0,200);
TH1F *tHit2_mc_firstBump = new TH1F("tHit2_mc_firstBump","",40,0,200);
TH1F *tHit2_mc_secondBump = new TH1F("tHit2_mc_secondBump","",40,0,200);

for (int i=0; i<6; i++) tHit1_data_timeBins[i] = new TH1F(Form("tHit1_data_timeBins_%d",i),Form("tHit1_data_timeBins_%d",i),100,0,200);

TH1D *tHit1_data_timeBin_0 = new TH1D("tHit1_data_timeBin_man_0","",20,0,200);
TH1D *tHit1_data_timeBin_1 = new TH1D("tHit1_data_timeBin_man_1","",20,0,200);
TH1D *tHit1_data_timeBin_2 = new TH1D("tHit1_data_timeBin_man_2","",20,0,200);
TH1D *tHit1_data_timeBin_3 = new TH1D("tHit1_data_timeBin_man_3","",20,0,200);
TH1D *tHit1_data_timeBin_4 = new TH1D("tHit1_data_timeBin_man_4","",20,0,200);
TH1D *tHit1_data_timeBin_5 = new TH1D("tHit1_data_timeBin_man_5","",20,0,200);
tHit1_data_timeBin_0->Sumw2();
tHit1_data_timeBin_1->Sumw2();
tHit1_data_timeBin_2->Sumw2();
tHit1_data_timeBin_3->Sumw2();
tHit1_data_timeBin_4->Sumw2();
tHit1_data_timeBin_5->Sumw2();

TH1F *bmp_ux_data 	= new TH1F("bmp_ux_data","",50,-1,1);
TH1F *bmp_ux_mc 	= new TH1F("bmp_ux_mc","",50,-1,1);
TH1F *bmp_uy_data 	= new TH1F("bmp_uy_data","",50,-1,1);
TH1F *bmp_uy_mc 	= new TH1F("bmp_uy_mc","",50,-1,1);
TH1F *bmp_uz_data 	= new TH1F("bmp_uz_data","",50,-1,1);
TH1F *bmp_uz_mc 	= new TH1F("bmp_uz_mc","",50,-1,1);

TH1F *bmp_x_data 	= new TH1F("bmp_x_data","",50,-500,500);
TH1F *bmp_x_mc 		= new TH1F("bmp_x_mc","",50,-500,500);
TH1F *bmp_y_data 	= new TH1F("bmp_y_data","",50,-500,500);
TH1F *bmp_y_mc 		= new TH1F("bmp_y_mc","",50,-500,500);
TH1F *bmp_z_data 	= new TH1F("bmp_z_data","",50,-500,500);
TH1F *bmp_z_mc 		= new TH1F("bmp_z_mc","",50,-500,500);
TH1F *bmp_r_data 	= new TH1F("bmp_r_data","",50,0,500);
TH1F *bmp_r_mc 		= new TH1F("bmp_r_mc","",50,0,500);
TH1F *bmp_t_data 	= new TH1F("bmp_t_data","",50,0,20000);
TH1F *bmp_t_mc 		= new TH1F("bmp_t_mc","",50,0,20000);
TH1F *bmp_th_data 	= new TH1F("bmp_th_data","",50,0,200);
TH1F *bmp_th_mc 	= new TH1F("bmp_th_mc","",50,0,200);

TH1F *tHit1_kPbig = new TH1F("tHit1_kPbig","",100,0,1500);
TH1F *tHit1_piPbig = new TH1F("tHit1_piPbig","",100,0,1500);
TH1F *tHit1_totBig = new TH1F("tHit1_totBig","",100,0,1500);
TH1F *tHit1_dataBig = new TH1F("tHit1_dataBig","",100,0,1500);

TH1F *truUY_kP = new TH1F("truUY_kP","",100,-1,1);
TH1F *truUY_piP = new TH1F("truUY_piP","",100,-1,1);
TH1F *truUY_tot = new TH1F("truUY_tot","",100,-1,1);

TH1F *recUY_kP = new TH1F("recUY_kP","",30,-1,1);
TH1F *recUY_piP = new TH1F("recUY_piP","",30,-1,1);
TH1F *recUY_tot = new TH1F("recUY_tot","",30,-1,1);
TH1F *recUY_data = new TH1F("recUY_data","",30,-1,1);
TH1F *recUY_strobe = new TH1F("recUY_strobe","",30,-1,1);

TH1F *thetaY_kP = new TH1F("thetaY_kP","",30,0,TMath::Pi());
TH1F *thetaY_piP = new TH1F("thetaY_piP","",30,0,TMath::Pi());
TH1F *thetaY_tot = new TH1F("thetaY_tot","",30,0,TMath::Pi());
TH1F *thetaY_data = new TH1F("thetaY_data","",30,0,TMath::Pi());

TH1F *truUX_kP = new TH1F("truUX_kP","",100,-1,1);
TH1F *truUX_piP = new TH1F("truUX_piP","",100,-1,1);
TH1F *truUX_tot = new TH1F("truUX_tot","",100,-1,1);

TH1F *recUX_kP = new TH1F("recUX_kP","",30,-1,1);
TH1F *recUX_piP = new TH1F("recUX_piP","",30,-1,1);
TH1F *recUX_tot = new TH1F("recUX_tot","",30,-1,1);
TH1F *recUX_data = new TH1F("recUX_data","",30,-1,1);

TH1F *thetaX_kP = new TH1F("thetaX_kP","",30,0,TMath::Pi());
TH1F *thetaX_piP = new TH1F("thetaX_piP","",30,0,TMath::Pi());
TH1F *thetaX_tot = new TH1F("thetaX_tot","",30,0,TMath::Pi());
TH1F *thetaX_data = new TH1F("thetaX_data","",30,0,TMath::Pi());

TH2F *thetaXY_kP = new TH2F("thetaXY_kP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXY_piP = new TH2F("thetaXY_piP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXY_tot = new TH2F("thetaXY_tot","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXY_data = new TH2F("thetaXY_data","",15,0,TMath::Pi(),15,0,TMath::Pi());

TH2F *thetaYZ_kP = new TH2F("thetaYZ_kP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaYZ_piP = new TH2F("thetaYZ_piP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaYZ_tot = new TH2F("thetaYZ_tot","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaYZ_data = new TH2F("thetaYZ_data","",15,0,TMath::Pi(),15,0,TMath::Pi());

TH2F *thetaXZ_kP = new TH2F("thetaXZ_kP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXZ_piP = new TH2F("thetaXZ_piP","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXZ_tot = new TH2F("thetaXZ_tot","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *thetaXZ_data = new TH2F("thetaXZ_data","",15,0,TMath::Pi(),15,0,TMath::Pi());

TH1F *truEnuQE_kP = new TH1F("truEnuQE_kP","",100,0,4);
TH1F *truEnuQE_piP = new TH1F("truEnuQE_piP","",100,0,4);
TH1F *truEnuQE_tot = new TH1F("truEnuQE_tot","",100,0,4);

TH1F *recEnuQE_kP = new TH1F("recEnuQE_kP","",40,0.1,1.0);
TH1F *recEnuQE_piP = new TH1F("recEnuQE_piP","",40,0.1,1.0);
TH1F *recEnuQE_tot = new TH1F("recEnuQE_tot","",40,0.1,1.0);
TH1F *recEnuQE_data = new TH1F("recEnuQE_data","",40,0.1,1.0);

TH1F *recEnuQE_kP_bigRng = new TH1F("recEnuQE_kP_bigRng","",40,0,3);
TH1F *recEnuQE_piP_bigRng = new TH1F("recEnuQE_piP_bigRng","",40,0,3);
TH1F *recEnuQE_tot_bigRng = new TH1F("recEnuQE_tot_bigRng","",40,0,3);
TH1F *recEnuQE_data_bigRng = new TH1F("recEnuQE_data_bigRng","",40,0,3);

TH1F *sig_tHit1big = new TH1F("sig_tHit1big","",100,0,1500);
TH1F *sig_tHit1 = new TH1F("sig_tHit1","",100,0,200);
TH1F *sig_truTmu = new TH1F("sig_truTmu","",100,0,4);
TH1F *sig_truUZ = new TH1F("sig_truUZ","",100,-1,1);
TH1F *sig_truUY = new TH1F("sig_truUY","",100,-1,1);
TH1F *sig_truUX = new TH1F("sig_truUX","",100,-1,1);
TH1F *sig_recUZ = new TH1F("sig_recUZ","",30,-1,1);
TH1F *sig_recUY = new TH1F("sig_recUY","",30,-1,1);
TH1F *sig_recUX = new TH1F("sig_recUX","",30,-1,1);

TH1F *sig_thetaZ = new TH1F("sig_thetaZ","",30,0,TMath::Pi());
TH1F *sig_thetaY = new TH1F("sig_thetaY","",30,0,TMath::Pi());
TH1F *sig_thetaX = new TH1F("sig_thetaX","",30,0,TMath::Pi());

TH2F *sig_thetaXZ = new TH2F("sig_thetaXZ","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *sig_thetaXY = new TH2F("sig_thetaXY","",15,0,TMath::Pi(),15,0,TMath::Pi());
TH2F *sig_thetaYZ = new TH2F("sig_thetaYZ","",15,0,TMath::Pi(),15,0,TMath::Pi());

TH1F *sig_truEnuQE = new TH1F("sig_truEnuQE","",100,0,4);
TH1F *sig_recEnuQE = new TH1F("sig_recEnuQE","",40,0.1,1.0);
TH1F *sig_nuBirthX = new TH1F("sig_nuBirthX","",100,-10000,10000);
TH1F *sig_nuBirthY = new TH1F("sig_nuBirthY","",100,-10000,10000);
TH1F *sig_nuBirthZ = new TH1F("sig_nuBirthZ","",100,-10000,10000);

TH1F *pipBirthX = new TH1F("pipBirthX","",100,-10000,10000);
TH1F *pipBirthY = new TH1F("pipBirthY","",100,-10000,10000);
TH1F *pipBirthZ = new TH1F("pipBirthZ","",100,-10000,10000);

TH1F *kpBirthX = new TH1F("kpBirthX","",100,-10000,10000);
TH1F *kpBirthY = new TH1F("kpBirthY","",100,-10000,10000);
TH1F *kpBirthZ = new TH1F("kpBirthZ","",100,-10000,10000);

TH1F *prBirthX = new TH1F("prBirthX","",100,-10000,10000);
TH1F *prBirthY = new TH1F("prBirthY","",100,-10000,10000);
TH1F *prBirthZ = new TH1F("prBirthZ","",100,-10000,10000);

TH1F *pipBirthPX = new TH1F("pipBirthPX","",100,-10,60);
TH1F *pipBirthPY = new TH1F("pipBirthPY","",100,-10,10);
TH1F *pipBirthPZ = new TH1F("pipBirthPZ","",100,-10,130);

TH1F *kpBirthPX = new TH1F("kpBirthPX","",100,-10,60);
TH1F *kpBirthPY = new TH1F("kpBirthPY","",100,-10,10);
TH1F *kpBirthPZ = new TH1F("kpBirthPZ","",100,-10,130);

TH1F *prBirthPX = new TH1F("prBirthPX","",100,-10,60);
TH1F *prBirthPY = new TH1F("prBirthPY","",100,-10,10);
TH1F *prBirthPZ = new TH1F("prBirthPZ","",100,-10,130);

TH2F *ptpz_piP = new TH2F("ptpz_piP","",50,0,15,50,0,8);
TH2F *ptpz_kP = new TH2F("ptpz_kP","",50,0,15,50,0,8);
TH2F *ptpz_piP_fin = new TH2F("ptpz_piP_fin","",50,0,15,50,0,8);
TH2F *ptpz_kP_fin = new TH2F("ptpz_kP_fin","",50,0,15,50,0,8);

TH1F *px_fin_piP = new TH1F("px_fin_piP","",50,-2,8);
TH1F *py_fin_piP = new TH1F("py_fin_piP","",50,-2,2);
TH1F *pz_fin_piP = new TH1F("pz_fin_piP","",50,-2,10);

TH1F *px_fin_kP = new TH1F("px_fin_kP","",50,-2,8);
TH1F *py_fin_kP = new TH1F("py_fin_kP","",50,-2,2);
TH1F *pz_fin_kP = new TH1F("pz_fin_kP","",50,-2,10);

TH1F *px_fin_tot = new TH1F("px_fin_tot","",50,-2,8);
TH1F *py_fin_tot = new TH1F("py_fin_tot","",50,-2,2);
TH1F *pz_fin_tot = new TH1F("pz_fin_tot","",50,-2,10);

TH1F *tDiff_tot = new TH1F("tDiff_tot","",100,0,5000);
TH1F *tDiff_data = new TH1F("tDiff_data","",100,0,5000);

TH1F *sig_rad = new TH1F("sig_rad","",100,0,40000);

TH1F *lk_2ndBump_tot = new TH1F("lk_2ndBump_tot","",40,-0.2,0.2);
TH1F *lk_2ndBump_data = new TH1F("lk_2ndBump_data","",40,-0.2,0.2);
TH1F *lk_2ndBump_ccqe = new TH1F("lk_2ndBump_ccqe","",40,-0.2,0.2);
TH1F *lk_2ndBump_ncpi = new TH1F("lk_2ndBump_ncpi","",40,-0.2,0.2);

TH1F *lk_tot_2se    = new TH1F("lk_tot_2se","",60,-0.2,2.0);
TH1F *lk_tot    = new TH1F("lk_tot","",40,-0.2,0.2);
TH1F *lk_strobe    = new TH1F("lk_strobe","",40,-0.2,0.2);
TH1F *lk_sig    = new TH1F("lk_sig","",40,-0.2,0.2);
TH1F *lk_piP   = new TH1F("lk_piP","",40,-0.2,0.2);
TH1F *lk_kP   = new TH1F("lk_kP","",40,-0.2,0.2);
TH1F *lk_data  = new TH1F("lk_data","",40,-0.2,0.2);
TH1F *elike_data_2se 	 = new TH1F("elike_data_2se","",60,0,1.5);
TH1F *elike_mc_2se 	 	= new TH1F("elike_mc_2se","",60,0,1.5);
TH1F *elike_data_2ndBmp  = new TH1F("elike_data_2ndBmp","",60,0,1.5);
TH1F *elike_mc_2ndBmp  = new TH1F("elike_mc_2ndBmp","",60,0,1.5);

TH1F *mulike_data_2ndBmp  = new TH1F("mulike_data_2ndBmp","",60,0,1.5);
TH1F *mulike_mc_2ndBmp  = new TH1F("mulike_mc_2ndBmp","",60,0,1.5);

TH1F *michEnergy_eHyp_data 	= new TH1F("michEnergy_eHyp_data","",50,0,0.1);
TH1F *michEnergy_eHyp_mc 	= new TH1F("michEnergy_eHyp_mc","",50,0,0.1);
TH1F *michEnergy_muHyp_data = new TH1F("michEnergy_muHyp_data","",50,0,0.1);
TH1F *michEnergy_muHyp_mc 	= new TH1F("michEnergy_muHyp_mc","",50,0,0.1);

TH2F *posDirCorrX = new TH2F("posDirCorrX","",50,-10000,40000,50,-1,1);
TH2F *posDirCorrY = new TH2F("posDirCorrY","",50,-10000,10000,50,-1,1);
TH2F *posDirCorrZ = new TH2F("posDirCorrZ","",50,-10000,80000,50,-1,1);

TH2F *truEnu_tHit1 = new TH2F("truEnu_tHit1","",40,0,1.0,50,0,400);

TH2F *tHit1_deltaLk_data = new TH2F("tHit1_deltaLk_data","",50,0,200,40,-0.2,0.2);
TH2F *tHit1_deltaLk_mc = new TH2F("tHit1_deltaLk_mc","",50,0,200,40,-0.2,0.2);

TH2F *truEnu_truTmu = new TH2F("truEnu_truTmu","",50,0,0.5,50,0,0.2);

TH1F *tHit1_cuts_data_0 = new TH1F("tHit1_cuts_data_0","",100,0,200);
TH1F *tHit1_cuts_data_1 = new TH1F("tHit1_cuts_data_1","",100,0,200);
TH1F *tHit1_cuts_data_2 = new TH1F("tHit1_cuts_data_2","",100,0,200);
TH1F *tHit1_cuts_data_3 = new TH1F("tHit1_cuts_data_3","",100,0,200);
TH1F *tHit1_cuts_data_4 = new TH1F("tHit1_cuts_data_4","",100,0,200);
TH1F *tHit1_cuts_data_5 = new TH1F("tHit1_cuts_data_5","",100,0,200);
TH1F *tHit1_cuts_data_6 = new TH1F("tHit1_cuts_data_6","",100,0,200);
TH1F *tHit1_cuts_data_7 = new TH1F("tHit1_cuts_data_7","",100,0,200);

TH1F *tHit1_cuts_mc_0 = new TH1F("tHit1_cuts_mc_0","",100,0,200);
TH1F *tHit1_cuts_mc_1 = new TH1F("tHit1_cuts_mc_1","",100,0,200);
TH1F *tHit1_cuts_mc_2 = new TH1F("tHit1_cuts_mc_2","",100,0,200);
TH1F *tHit1_cuts_mc_3 = new TH1F("tHit1_cuts_mc_3","",100,0,200);
TH1F *tHit1_cuts_mc_4 = new TH1F("tHit1_cuts_mc_4","",100,0,200);
TH1F *tHit1_cuts_mc_5 = new TH1F("tHit1_cuts_mc_5","",100,0,200);
TH1F *tHit1_cuts_mc_6 = new TH1F("tHit1_cuts_mc_6","",100,0,200);
TH1F *tHit1_cuts_mc_7 = new TH1F("tHit1_cuts_mc_7","",100,0,200);

TH1F *tmu_cuts_data_0 = new TH1F("tmu_cuts_data_0","",80,0,0.2);
TH1F *tmu_cuts_data_1 = new TH1F("tmu_cuts_data_1","",80,0,0.2);
TH1F *tmu_cuts_data_2 = new TH1F("tmu_cuts_data_2","",80,0,0.2);
TH1F *tmu_cuts_data_3 = new TH1F("tmu_cuts_data_3","",80,0,0.2);
TH1F *tmu_cuts_data_4 = new TH1F("tmu_cuts_data_4","",80,0,0.2);
TH1F *tmu_cuts_data_5 = new TH1F("tmu_cuts_data_5","",80,0,0.2);
TH1F *tmu_cuts_data_6 = new TH1F("tmu_cuts_data_6","",80,0,0.2);
TH1F *tmu_cuts_data_7 = new TH1F("tmu_cuts_data_7","",80,0,0.2);

TH1F *tmu_cuts_mc_0 = new TH1F("tmu_cuts_mc_0","",80,0,0.2);
TH1F *tmu_cuts_mc_1 = new TH1F("tmu_cuts_mc_1","",80,0,0.2);
TH1F *tmu_cuts_mc_2 = new TH1F("tmu_cuts_mc_2","",80,0,0.2);
TH1F *tmu_cuts_mc_3 = new TH1F("tmu_cuts_mc_3","",80,0,0.2);
TH1F *tmu_cuts_mc_4 = new TH1F("tmu_cuts_mc_4","",80,0,0.2);
TH1F *tmu_cuts_mc_5 = new TH1F("tmu_cuts_mc_5","",80,0,0.2);
TH1F *tmu_cuts_mc_6 = new TH1F("tmu_cuts_mc_6","",80,0,0.2);
TH1F *tmu_cuts_mc_7 = new TH1F("tmu_cuts_mc_7","",80,0,0.2);

TH1F *tmu_cuts_kdar_0 = new TH1F("tmu_cuts_kdar_0","",80,0,0.2);
TH1F *tmu_cuts_kdar_1 = new TH1F("tmu_cuts_kdar_1","",80,0,0.2);
TH1F *tmu_cuts_kdar_2 = new TH1F("tmu_cuts_kdar_2","",80,0,0.2);
TH1F *tmu_cuts_kdar_3 = new TH1F("tmu_cuts_kdar_3","",80,0,0.2);
TH1F *tmu_cuts_kdar_4 = new TH1F("tmu_cuts_kdar_4","",80,0,0.2);
TH1F *tmu_cuts_kdar_5 = new TH1F("tmu_cuts_kdar_5","",80,0,0.2);
TH1F *tmu_cuts_kdar_6 = new TH1F("tmu_cuts_kdar_6","",80,0,0.2);
TH1F *tmu_cuts_kdar_7 = new TH1F("tmu_cuts_kdar_7","",80,0,0.2);

TH1F *tmu_cuts_pip_0 = new TH1F("tmu_cuts_pip_0","",80,0,0.2);
TH1F *tmu_cuts_pip_1 = new TH1F("tmu_cuts_pip_1","",80,0,0.2);
TH1F *tmu_cuts_pip_2 = new TH1F("tmu_cuts_pip_2","",80,0,0.2);
TH1F *tmu_cuts_pip_3 = new TH1F("tmu_cuts_pip_3","",80,0,0.2);
TH1F *tmu_cuts_pip_4 = new TH1F("tmu_cuts_pip_4","",80,0,0.2);
TH1F *tmu_cuts_pip_5 = new TH1F("tmu_cuts_pip_5","",80,0,0.2);
TH1F *tmu_cuts_pip_6 = new TH1F("tmu_cuts_pip_6","",80,0,0.2);
TH1F *tmu_cuts_pip_7 = new TH1F("tmu_cuts_pip_7","",80,0,0.2);

TH1F *tmu_cuts_kp_0 = new TH1F("tmu_cuts_kp_0","",80,0,0.2);
TH1F *tmu_cuts_kp_1 = new TH1F("tmu_cuts_kp_1","",80,0,0.2);
TH1F *tmu_cuts_kp_2 = new TH1F("tmu_cuts_kp_2","",80,0,0.2);
TH1F *tmu_cuts_kp_3 = new TH1F("tmu_cuts_kp_3","",80,0,0.2);
TH1F *tmu_cuts_kp_4 = new TH1F("tmu_cuts_kp_4","",80,0,0.2);
TH1F *tmu_cuts_kp_5 = new TH1F("tmu_cuts_kp_5","",80,0,0.2);
TH1F *tmu_cuts_kp_6 = new TH1F("tmu_cuts_kp_6","",80,0,0.2);
TH1F *tmu_cuts_kp_7 = new TH1F("tmu_cuts_kp_7","",80,0,0.2);

TH1F *tHit1_cuts_kdar_0 = new TH1F("tHit1_cuts_kdar_0","",100,0,200);
TH1F *tHit1_cuts_kdar_1 = new TH1F("tHit1_cuts_kdar_1","",100,0,200);
TH1F *tHit1_cuts_kdar_2 = new TH1F("tHit1_cuts_kdar_2","",100,0,200);
TH1F *tHit1_cuts_kdar_3 = new TH1F("tHit1_cuts_kdar_3","",100,0,200);
TH1F *tHit1_cuts_kdar_4 = new TH1F("tHit1_cuts_kdar_4","",100,0,200);
TH1F *tHit1_cuts_kdar_5 = new TH1F("tHit1_cuts_kdar_5","",100,0,200);
TH1F *tHit1_cuts_kdar_6 = new TH1F("tHit1_cuts_kdar_6","",100,0,200);
TH1F *tHit1_cuts_kdar_7 = new TH1F("tHit1_cuts_kdar_7","",100,0,200);

TH1F *tHit1_cuts_strobe_0 = new TH1F("tHit1_cuts_strobe_0","",100,0,200);
TH1F *tHit1_cuts_strobe_1 = new TH1F("tHit1_cuts_strobe_1","",100,0,200);
TH1F *tHit1_cuts_strobe_2 = new TH1F("tHit1_cuts_strobe_2","",100,0,200);
TH1F *tHit1_cuts_strobe_3 = new TH1F("tHit1_cuts_strobe_3","",100,0,200);
TH1F *tHit1_cuts_strobe_4 = new TH1F("tHit1_cuts_strobe_4","",100,0,200);
TH1F *tHit1_cuts_strobe_5 = new TH1F("tHit1_cuts_strobe_5","",100,0,200);
TH1F *tHit1_cuts_strobe_6 = new TH1F("tHit1_cuts_strobe_6","",100,0,200);
TH1F *tHit1_cuts_strobe_7 = new TH1F("tHit1_cuts_strobe_7","",100,0,200);

TH1F *tHit1_cuts_pip_0 = new TH1F("tHit1_cuts_pip_0","",100,0,200);
TH1F *tHit1_cuts_pip_1 = new TH1F("tHit1_cuts_pip_1","",100,0,200);
TH1F *tHit1_cuts_pip_2 = new TH1F("tHit1_cuts_pip_2","",100,0,200);
TH1F *tHit1_cuts_pip_3 = new TH1F("tHit1_cuts_pip_3","",100,0,200);
TH1F *tHit1_cuts_pip_4 = new TH1F("tHit1_cuts_pip_4","",100,0,200);
TH1F *tHit1_cuts_pip_5 = new TH1F("tHit1_cuts_pip_5","",100,0,200);
TH1F *tHit1_cuts_pip_6 = new TH1F("tHit1_cuts_pip_6","",100,0,200);
TH1F *tHit1_cuts_pip_7 = new TH1F("tHit1_cuts_pip_7","",100,0,200);

TH1F *tHit1_cuts_kp_0 = new TH1F("tHit1_cuts_kp_0","",100,0,200);
TH1F *tHit1_cuts_kp_1 = new TH1F("tHit1_cuts_kp_1","",100,0,200);
TH1F *tHit1_cuts_kp_2 = new TH1F("tHit1_cuts_kp_2","",100,0,200);
TH1F *tHit1_cuts_kp_3 = new TH1F("tHit1_cuts_kp_3","",100,0,200);
TH1F *tHit1_cuts_kp_4 = new TH1F("tHit1_cuts_kp_4","",100,0,200);
TH1F *tHit1_cuts_kp_5 = new TH1F("tHit1_cuts_kp_5","",100,0,200);
TH1F *tHit1_cuts_kp_6 = new TH1F("tHit1_cuts_kp_6","",100,0,200);
TH1F *tHit1_cuts_kp_7 = new TH1F("tHit1_cuts_kp_7","",100,0,200);

TH1F *spitzVar_cuts_mc_0 = new TH1F("spitzVar_cuts_mc_0","",40,0,0.25);
TH1F *spitzVar_cuts_mc_1 = new TH1F("spitzVar_cuts_mc_1","",40,0,0.25);
TH1F *spitzVar_cuts_mc_2 = new TH1F("spitzVar_cuts_mc_2","",40,0,0.25);
TH1F *spitzVar_cuts_mc_3 = new TH1F("spitzVar_cuts_mc_3","",40,0,0.25);
TH1F *spitzVar_cuts_mc_4 = new TH1F("spitzVar_cuts_mc_4","",40,0,0.25);
TH1F *spitzVar_cuts_mc_5 = new TH1F("spitzVar_cuts_mc_5","",40,0,0.25);
TH1F *spitzVar_cuts_mc_6 = new TH1F("spitzVar_cuts_mc_6","",40,0,0.25);
TH1F *spitzVar_cuts_mc_7 = new TH1F("spitzVar_cuts_mc_7","",40,0,0.25);

TH1F *spitzVar_cuts_data_0 = new TH1F("spitzVar_cuts_data_0","",40,0,0.25);
TH1F *spitzVar_cuts_data_1 = new TH1F("spitzVar_cuts_data_1","",40,0,0.25);
TH1F *spitzVar_cuts_data_2 = new TH1F("spitzVar_cuts_data_2","",40,0,0.25);
TH1F *spitzVar_cuts_data_3 = new TH1F("spitzVar_cuts_data_3","",40,0,0.25);
TH1F *spitzVar_cuts_data_4 = new TH1F("spitzVar_cuts_data_4","",40,0,0.25);
TH1F *spitzVar_cuts_data_5 = new TH1F("spitzVar_cuts_data_5","",40,0,0.25);
TH1F *spitzVar_cuts_data_6 = new TH1F("spitzVar_cuts_data_6","",40,0,0.25);
TH1F *spitzVar_cuts_data_7 = new TH1F("spitzVar_cuts_data_7","",40,0,0.25);

TH1F *spitzVar_cuts_strobe_0 = new TH1F("spitzVar_cuts_strobe_0","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_1 = new TH1F("spitzVar_cuts_strobe_1","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_2 = new TH1F("spitzVar_cuts_strobe_2","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_3 = new TH1F("spitzVar_cuts_strobe_3","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_4 = new TH1F("spitzVar_cuts_strobe_4","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_5 = new TH1F("spitzVar_cuts_strobe_5","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_6 = new TH1F("spitzVar_cuts_strobe_6","",40,0,0.25);
TH1F *spitzVar_cuts_strobe_7 = new TH1F("spitzVar_cuts_strobe_7","",40,0,0.25);

TH1F *spitzVar_cuts_dirt_0 = new TH1F("spitzVar_cuts_dirt_0","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_1 = new TH1F("spitzVar_cuts_dirt_1","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_2 = new TH1F("spitzVar_cuts_dirt_2","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_3 = new TH1F("spitzVar_cuts_dirt_3","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_4 = new TH1F("spitzVar_cuts_dirt_4","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_5 = new TH1F("spitzVar_cuts_dirt_5","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_6 = new TH1F("spitzVar_cuts_dirt_6","",40,0,0.25);
TH1F *spitzVar_cuts_dirt_7 = new TH1F("spitzVar_cuts_dirt_7","",40,0,0.25);

TH1F *spitzVar_cuts_pip_0 = new TH1F("spitzVar_cuts_pip_0","",40,0,0.25);
TH1F *spitzVar_cuts_pip_1 = new TH1F("spitzVar_cuts_pip_1","",40,0,0.25);
TH1F *spitzVar_cuts_pip_2 = new TH1F("spitzVar_cuts_pip_2","",40,0,0.25);
TH1F *spitzVar_cuts_pip_3 = new TH1F("spitzVar_cuts_pip_3","",40,0,0.25);
TH1F *spitzVar_cuts_pip_4 = new TH1F("spitzVar_cuts_pip_4","",40,0,0.25);
TH1F *spitzVar_cuts_pip_5 = new TH1F("spitzVar_cuts_pip_5","",40,0,0.25);
TH1F *spitzVar_cuts_pip_6 = new TH1F("spitzVar_cuts_pip_6","",40,0,0.25);
TH1F *spitzVar_cuts_pip_7 = new TH1F("spitzVar_cuts_pip_7","",40,0,0.25);

TH1F *spitzVar_cuts_pim_0 = new TH1F("spitzVar_cuts_pim_0","",40,0,0.25);
TH1F *spitzVar_cuts_pim_1 = new TH1F("spitzVar_cuts_pim_1","",40,0,0.25);
TH1F *spitzVar_cuts_pim_2 = new TH1F("spitzVar_cuts_pim_2","",40,0,0.25);
TH1F *spitzVar_cuts_pim_3 = new TH1F("spitzVar_cuts_pim_3","",40,0,0.25);
TH1F *spitzVar_cuts_pim_4 = new TH1F("spitzVar_cuts_pim_4","",40,0,0.25);
TH1F *spitzVar_cuts_pim_5 = new TH1F("spitzVar_cuts_pim_5","",40,0,0.25);
TH1F *spitzVar_cuts_pim_6 = new TH1F("spitzVar_cuts_pim_6","",40,0,0.25);
TH1F *spitzVar_cuts_pim_7 = new TH1F("spitzVar_cuts_pim_7","",40,0,0.25);

TH1F *spitzVar_cuts_kp_0 = new TH1F("spitzVar_cuts_kp_0","",40,0,0.25);
TH1F *spitzVar_cuts_kp_1 = new TH1F("spitzVar_cuts_kp_1","",40,0,0.25);
TH1F *spitzVar_cuts_kp_2 = new TH1F("spitzVar_cuts_kp_2","",40,0,0.25);
TH1F *spitzVar_cuts_kp_3 = new TH1F("spitzVar_cuts_kp_3","",40,0,0.25);
TH1F *spitzVar_cuts_kp_4 = new TH1F("spitzVar_cuts_kp_4","",40,0,0.25);
TH1F *spitzVar_cuts_kp_5 = new TH1F("spitzVar_cuts_kp_5","",40,0,0.25);
TH1F *spitzVar_cuts_kp_6 = new TH1F("spitzVar_cuts_kp_6","",40,0,0.25);
TH1F *spitzVar_cuts_kp_7 = new TH1F("spitzVar_cuts_kp_7","",40,0,0.25);

TH1F *thetaPi = new TH1F("thetaPi","thetaPi",50,0,0.25);
TH2F *pip_phaseSp = new TH2F("pTpZ_pip","",32,0,8,40,0,0.3);

TH1F *chans = new TH1F("chans","",100,0.5,100.5);

bool doCCQE = 1;

int nTmuBins = 7;

TH1F *AdjRngTmuBns_tot[nTmuBins];
TH1F *AdjRngTmuBns_piP[nTmuBins];
TH1F *AdjRngTmuBns_kP[nTmuBins];
TH1F *AdjRngTmuBns_sig[nTmuBins];
TH1F *AdjRngTmuBns_data[nTmuBins];

for (int i=0; i<nTmuBins; i++){
  AdjRngTmuBns_tot[i]  = new TH1F(Form("AdjRngTmuBns_tot_%d",i),"",25,0,400);
  AdjRngTmuBns_piP[i]  = new TH1F(Form("AdjRngTmuBns_piP_%d",i),"",25,0,400);
  AdjRngTmuBns_kP[i]   = new TH1F(Form("AdjRngTmuBns_kP_%d",i),"",25,0,400);
  AdjRngTmuBns_sig[i]  = new TH1F(Form("AdjRngTmuBns_sig_%d",i),"",25,0,400);
  AdjRngTmuBns_data[i] = new TH1F(Form("AdjRngTmuBns_data_%d",i),"",25,0,400);
}

float TmuBound[nTmuBins * 2];

for (int i=0; i<(nTmuBins * 2); i++) TmuBound[i] = 0;

TmuBound[0] = 0.0;
TmuBound[1] = 0.05;
TmuBound[2] = 0.05;
TmuBound[3] = 0.10;
TmuBound[4] = 0.10;
TmuBound[5] = 0.15;
TmuBound[6] = 0.15;
TmuBound[7] = 0.20;
TmuBound[8] = 0.20;
TmuBound[9] = 0.25;
TmuBound[10] = 0.25;
TmuBound[11] = 0.30;
TmuBound[12] = 0.30;
TmuBound[13] = 0.35;

bool do2SE = 0;
bool doLk = 0;
bool doThit1 = 0;
bool doThit2 = 0;
bool doRad = 0;

if (doCCQE){

  do2SE = 1;
  doLk = 1;
  doThit1 = 1;
  doThit2 = 1;
  doRad = 1;

}

  FILE* file;
  char *fileName;
  bool pt0pt1 = 1;
  if (pt0pt1) fileName = "kappa_1.01.txt";
  else fileName = "kappa_1.00.txt";
  file = fopen(fileName,"r");

  float energy = 0;
  float val = 0.;

  int nTmuBins2 = 10;

  TH1F *truTmuDist = new TH1F("truTmuDist","",40,0,1);
  TH1F *ryanTmuDist = new TH1F("ryanTmuDist","",40,0,1);
  TH1F *stanTmuDist = new TH1F("ryanTmuDist","",40,0,1);

  TH1F *uzRes_tmuBinz_ryan_0 = new TH1F("uzRes_tmuBinz_ryan_0","",40,-1,1);
  TH1F *uzRes_tmuBinz_ryan_1 = new TH1F("uzRes_tmuBinz_ryan_1","",40,-1,1);
  TH1F *uzRes_tmuBinz_ryan_2 = new TH1F("uzRes_tmuBinz_ryan_2","",40,-1,1);
  TH1F *uzRes_tmuBinz_ryan_3 = new TH1F("uzRes_tmuBinz_ryan_3","",40,-1,1);
  TH1F *uzRes_tmuBinz_ryan_4 = new TH1F("uzRes_tmuBinz_ryan_4","",40,-1,1);
  TH1F *uzDist_tmuBinz_ryan_0 = new TH1F("uzDist_tmuBinz_ryan_0","",40,-1,1);
  TH1F *uzDist_tmuBinz_ryan_1 = new TH1F("uzDist_tmuBinz_ryan_1","",40,-1,1);
  TH1F *uzDist_tmuBinz_ryan_2 = new TH1F("uzDist_tmuBinz_ryan_2","",40,-1,1);
  TH1F *uzDist_tmuBinz_ryan_3 = new TH1F("uzDist_tmuBinz_ryan_3","",40,-1,1);
  TH1F *uzDist_tmuBinz_ryan_4 = new TH1F("uzDist_tmuBinz_ryan_4","",40,-1,1);
  TH1F *uzRes_tmuBinz_stancu_0 = new TH1F("uzRes_tmuBinz_stancu_0","",40,-1,1);
  TH1F *uzRes_tmuBinz_stancu_1 = new TH1F("uzRes_tmuBinz_stancu_1","",40,-1,1);
  TH1F *uzRes_tmuBinz_stancu_2 = new TH1F("uzRes_tmuBinz_stancu_2","",40,-1,1);
  TH1F *uzRes_tmuBinz_stancu_3 = new TH1F("uzRes_tmuBinz_stancu_3","",40,-1,1);
  TH1F *uzRes_tmuBinz_stancu_4 = new TH1F("uzRes_tmuBinz_stancu_4","",40,-1,1);
  TH1F *uzDist_tmuBinz_stancu_0 = new TH1F("uzDist_tmuBinz_stancu_0","",40,-1,1);
  TH1F *uzDist_tmuBinz_stancu_1 = new TH1F("uzDist_tmuBinz_stancu_1","",40,-1,1);
  TH1F *uzDist_tmuBinz_stancu_2 = new TH1F("uzDist_tmuBinz_stancu_2","",40,-1,1);
  TH1F *uzDist_tmuBinz_stancu_3 = new TH1F("uzDist_tmuBinz_stancu_3","",40,-1,1);
  TH1F *uzDist_tmuBinz_stancu_4 = new TH1F("uzDist_tmuBinz_stancu_4","",40,-1,1);

  bool useRewt = 1;

  double kRewt[10000];

  while (!feof(file)){

    fscanf (file, "%f %f", &energy, &val);
    //cout<<" energy "<<energy<<" val "<<val<<endl;
    kRewt[(int)energy-1] = val;

  }
//return;

kRewt[9999] = 1;

double pionMom = 0.;

/*
for (int i=0; i<10000; i++){
  cout<<" i "<<i<<" val "<<kRewt[i]<<endl;
}
*/

double pipKdarBinEvnts = 0.;
double sigCnt = 0.;
int dataCnt = 0;
int mcCnt = 0;
double sigWt = 4.919*2-5;// = 13371/2718 * 2
double mcWt = 1;// = 105988/2742 * 2

//int thitbins = 30;
//double last = 300.;

float genR = 0.;

TH2F *tru_tmu_tank_hits_fold = new TH2F("tru_tmu_tank_hit_fold","",thitbins,0,last,tmu_bins_fold,first_tmu,last_tmu);//keep tank hit bins like usual

float pionUZ = 0;

float vHitz[10];
for (int i=0; i<=10; i++) vHitz[i] = 0;

bool doWght = 1;
double wght = 0.;

TFile *newfile = new TFile("dirt_bump.root","recreate");
TTree *newtree = fChain->CloneTree(0);

   if (fChain == 0) return;

   Int_t nentries = Int_t(fChain->GetEntriesFast());

   Int_t nbytes = 0, nb = 0;
   for (Int_t jentry=0; jentry<nentries;jentry++) {
      Int_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

        if ( (jentry % 5000) == 0){
          cout << "Entry " << jentry << " file " << fCurrent << endl;
          //cout << "UZ unsmear int is "<<UZ_unSmear->Integral() << endl;
        }

        //if (myRecoOneTrkMu_trkType[0]!=2) continue;

        //if (myRecoOneTrkMu_trkType[0] < 1 || myRecoOneTrkMu_trkType[0] > 3) continue;
	
        numSE = 0;
        numSE = eventInfo_numSE;

        passV = 1;

        for (int i=1; i<=numSE; i++){

          vHitz[i-1] = 0;
          vHitz[i-1] = mysplitEvent_nVetoHits[i-1];
          

          if (vHitz[i-1] > 5) passV = 0;

        }

        //cout<<" veto hits 1 "<<vHitz[0]<<" 2 "<<vHitz[1]<<endl; 

        vHit1 = 0;
        vHit1 = mysplitEvent_nVetoHits[0];

        vHit2 = 0;
        vHit2 = mysplitEvent_nVetoHits[1];

        vHit3 = 0;
        vHit3 = mysplitEvent_nVetoHits[2];

        beamAveTime = 0;
        beamAveTime = mysplitEvent_aveTimeTank[0];

        tDiff = 0.;
        tDiff = mysplitEvent_aveTimeTank[1] - mysplitEvent_aveTimeTank[0];

        beamAveTimeOT = 0;
        beamAveTimeOT = myRecoOneTrkMu_time[0];
 
        tHits_1SE = 0;
		tHits_1SE = mysplitEvent_nTankHits[0];

        if (testst) tHits_1SE = myStFull_energy_mu[0]; 

        tHits_2SE = 0;
        tHits_2SE = mysplitEvent_nTankHits[1];
	
		stVertx = 0;
		stVertx = sqrt(pow(myStFull_vertex_x[0],2) + pow(myStFull_vertex_y[0],2) + pow(myStFull_vertex_z[0],2));

        truEnu = 0;
        truEnu = myMCEvent_pNu_E[0];


        /*if (fCurrent==0){//invert z <--> y
        
          recoUX = 0;
          recoUX = myRecoOneTrkMu_ux[0];

          CosThetamu = 0;
          CosThetamu = myRecoOneTrkMu_uy[0];

          recoUY = 0;
          recoUY = myRecoOneTrkMu_uz[0];
        
          truMuPx = 0;
          truMuPx = myMCParticle_p_x[0];//array [0] points to FS lepton - mu/e for CC, numu/nue for NC

          truMuPz = 0;
          truMuPz = myMCParticle_p_y[0];

          truMuPy = 0;
          truMuPy = myMCParticle_p_z[0];

          muX = 0;
          muX = myRecoOneTrkMu_x[0];

          muZ = 0;
          muZ = myRecoOneTrkMu_y[0];

          muY = 0;
          muY = myRecoOneTrkMu_z[0];

          muUX = 0;
          muUX = myRecoOneTrkMu_ux[0];

          muUZ = 0;
          muUZ = myRecoOneTrkMu_uy[0];

          muUY = 0;
          muUY = myRecoOneTrkMu_uz[0];

          recoUZ = 0.;
          recoUZ = myRecoOneTrkMu_uy[0];

          thetaX = 0.;
          thetaX = acos(myRecoOneTrkMu_ux[0]);

          thetaY = 0.;
          thetaY = acos(myRecoOneTrkMu_uz[0]);

          thetaZ = 0.;
          thetaZ = acos(myRecoOneTrkMu_uy[0]);

          muR = 0;
          muR = pow(pow(muX,2) + pow(muY,2) + pow(muZ,2),0.5);

          elX = 0;
          elX = myRecoOneTrk_x[1];

          elZ = 0;
          elZ = myRecoOneTrk_y[1];

          elY = 0;
          elY = myRecoOneTrk_z[1];

        }*/

        //else{
        
          truMuPx = 0;
          truMuPx = myMCParticle_p_x[0];//array [0] points to FS lepton - mu/e for CC, numu/nue for NC

          truMuPy = 0;
          truMuPy = myMCParticle_p_y[0];

          truMuPz = 0;
          truMuPz = myMCParticle_p_z[0];

          muX = 0;
          muX = myRecoOneTrkMu_x[0];

          muY = 0;
          muY = myRecoOneTrkMu_y[0];

          muZ = 0;
          muZ = myRecoOneTrkMu_z[0];

        genR = 0.;
        genR = myMCParticle_ver_mag[0];

          muUX = 0;
          muUX = myStFull_dir_x[0];

          muUY = 0;
          muUY = myStFull_dir_y[0];

          muUZ = 0;
          muUZ = myStFull_dir_z[0];

          muR = 0;
          muR = pow(pow(muX,2) + pow(muY,2) + pow(muZ,2),0.5);

          elX = 0;
          elX = myRecoOneTrk_x[1];

          elY = 0;
          elY = myRecoOneTrk_y[1];

          elZ = 0;
          elZ = myRecoOneTrk_z[1];

          recoUX = 0;
          //recoUX = acos(myRecoOneTrkMu_ux[0]);
          recoUX = myRecoOneTrkMu_ux[0];

          recoUY = 0;
          //recoUY = acos(myRecoOneTrkMu_uy[0]);
          recoUY = myRecoOneTrkMu_uy[0];

          CosThetamu = 0;
          //CosThetamu = acos(myRecoOneTrkMu_uz[0]);
          CosThetamu = myRecoOneTrkMu_uz[0];
          
          stancuUZ = 0.;
          stancuUZ = myStFull_dir_z[0];

          stancuTmu = 0.;
          stancuTmu = myStFull_energy_mu[0]/1000;
          
          thetaX = 0.;
          thetaX = acos(myRecoOneTrkMu_ux[0]);

          thetaY = 0.;
          thetaY = acos(myRecoOneTrkMu_uy[0]);

          thetaZ = 0.;
          thetaZ = acos(myRecoOneTrkMu_uz[0]);          
          
          recoUZ = 0.;
          recoUZ = myRecoOneTrkMu_uz[0];
        //}

        truMuP = 0;
        truMuP = sqrt(pow(truMuPx,2) + pow(truMuPy,2) + pow(truMuPz,2));

        parent = 0;
        parent = myMCParent_geantID[1];

        //if (fCurrent==0) parent = 11;

		if (useRewt) mcWt = 1 * kRewt[(int)(truEnu*1000)];
                else mcWt = 1;
        //cout<<" energy "<<(int)(truEnu*1000)<<" rewt "<<kRewt[(int)(truEnu*1000)]<<endl;

        //if (fCurrent==0) mcWt = sigWt;
        

        //cout<<" parent is "<<parent<<endl;

        truEmu = 0;
        truEmu = sqrt(pow(truMuP,2) + pow(Mmu,2));//don't use _p_E[0]! (energy truth info) - formed assuming massless particle! use instead 3-mom and mass 

        truTmu = 0;
        truTmu = truEmu - Mmu;

        Range = 0;
        Range = pow(pow(muX - elX,2) + pow(muY - elY,2) + pow(muZ - elZ,2),0.5);

        pionUZ = 0;
        pionUZ = acos(myMCParent_init_pz[1]/myMCParent_init_pE[1]);//in rad  

        muLk = 0;
        muLk = -myRecoOneTrkMu_likelihood[0];

        elLk = 0;
        elLk = -myRecoOneTrk_likelihood[0];

        muLk_2se = 0;
        muLk_2se = -myRecoOneTrkMu_likelihood[1];

        elLk_2se = 0;
        elLk_2se = -myRecoOneTrk_likelihood[1];

        //cout<<" e like "<<elLk_2se<<endl;

        deltaLk = 0;
        deltaLk = muLk - elLk;

        deltaLk_2se = 0;
        deltaLk_2se = muLk_2se - elLk_2se;

        Tmu = 0;
		Tmu = (myRecoOneTrkMu_energy[0]) / 1000;

        adjRange = 0;
        adjRange = Range - (500 * Tmu - 100);

        michE = 0;
        michE = (myRecoOneTrk_energy[1]) / 1000;

        michE_muHyp = 0;
        michE_muHyp = (myRecoOneTrkMu_energy[1]) / 1000;

        //cout<<" michE "<<michE<<endl;

        Emu = 0;
        Emu = (myRecoOneTrkMu_energy[0]) / 1000 + Mmu;

        Pmu = 0;
        Pmu = pow(pow(Emu,2) - pow(Mmu,2),0.5);

		Tmu = 0;
		Tmu = (myRecoOneTrkMu_energy[0]) / 1000;
	
		muRange = 0;
        muRange = 533.3 * Tmu;//from linear fit to boodb table

                muRange_st = 0;
        muRange_st = 533.3 * myStFull_energy_mu[0] / 1000.;//from linear fit to boodb table
	
		MichDist = 0;
        MichDist = pow(pow(myStFull_vertex_x[0] + muRange_st * muUX/2 - elX,2) + pow(myStFull_vertex_y[0] + muRange_st * muUY/2 - elY,2) + pow(myStFull_vertex_z[0] + muRange_st * muUZ/2 - elZ,2),0.5);

        truX = 0;
        truX = myMCParticle_ver_x[0];

        truY = 0;
        truY = myMCParticle_ver_y[0];

        truZ = 0;
        truZ = myMCParticle_ver_z[0];

        //cout<<"mu true vertex x, y, z "<<truX<<" "<<truY<<" "<<truZ<<endl;

        truUX = 0;
        truUX = truMuPx/truMuP;

        truUY = 0;
        truUY = truMuPy/truMuP;

        truUZ = 0;
        truUZ = truMuPz/truMuP;

        theta_Xtru = 0.;
        theta_Xtru = acos(truUX);

        theta_Ytru = 0.;
        theta_Ytru = acos(truUY);

        theta_Ztru = 0.;
        theta_Ztru = acos(truUZ);

        truR = 0;
        truR = sqrt(pow(truX,2) + pow(truY,2) + pow(truZ,2));

        recoX = 0;
        recoX = myRecoOneTrk_x[0];

        recoY = 0;
        recoY = myRecoOneTrk_y[0];

        recoZ = 0;
        recoZ = myRecoOneTrk_z[0];
	
        endMuX = 0;
        endMuX = recoX + muRange * muUX;

        endMuY = 0;
        endMuY = recoY + muRange * muUY;

        endMuZ = 0;
        endMuZ = recoZ + muRange * muUZ;

        //muEndR = 0;
 
        Channel = 0;
        Channel = myMCEvent_weight[0];

        nuType = 0;
        nuType = myMCEvent_nuType[0];

        CCQE = 0;
        if (Channel==1) CCQE = 1;

        CCpi = 0;
        if (Channel == 3 || Channel == 5 || Channel == 10 || Channel == 12 || Channel == 97) CCpi = 1;

        CCpi0 = 0;
        if (Channel == 4 || Channel == 11)  CCpi0 = 1;

        nfsp = 0;
        nfsp = myMCEvent_nFinalState[0];

        ndcy = 0;
        ndcy = myMCEvent_nDecayPart[0];

        EnuQE = 0;
        EnuQE = 0.5 * (2 * (Mp - BE) * Emu - (pow(Mp,2) - pow(Mn,2) - 2 * Mp * BE + pow(BE,2) + pow(Mmu,2))) / (Mp - BE - Emu + Pmu * CosThetamu);

        truEnuQE = 0.;
        truEnuQE = 0.5 * (2 * (Mp - BE) * truEmu - (pow(Mp,2) - pow(Mn,2) - 2 * Mp * BE + pow(BE,2) + pow(Mmu,2))) / (Mp - BE - Emu + truMuP * truUZ);

        Qsq = 0;
        Qsq = 2 * EnuQE * (Emu - Pmu * CosThetamu) - pow(Mmu,2);        

        pT = 0;
        pT = sqrt(pow(myMCParent_init_px[1],2) + pow(myMCParent_init_py[1],2));

        pT_fin = 0;
        pT_fin = sqrt(pow(myMCParent_fin_px[1],2) + pow(myMCParent_fin_py[1],2));

        nuUX = 0.;
        nuUX = myMCParent_init_px[0] / myMCParent_init_pE[0];

        nuUY = 0.;
        nuUY = myMCParent_init_py[0] / myMCParent_init_pE[0];

        nuUZ = 0.;
        nuUZ = myMCParent_init_pz[0] / myMCParent_init_pE[0];

        pZ = 0;
        pZ = myMCParent_init_pz[1];

        pionMom = 0;
        pionMom = myMCParent_init_pE[1];//

        pZ_fin = 0.;
        pZ_fin = myMCParent_fin_pz[1];

        pX_fin = 0.;
        pX_fin = myMCParent_fin_px[1];

        pY_fin = 0.;
        pY_fin = myMCParent_fin_py[1];

        pTot = 0.;
        pTot = myMCParent_init_pE[1];

        theta = acos(pZ / pTot);//

        threeMomDiff = 0.;
        threeMomDiff = pow(myMCParticle_p_x[0]-myMCEvent_pNu_x[0],2)+pow(myMCParticle_p_y[0]-myMCEvent_pNu_y[0],2)+pow(myMCParticle_p_z[0]-myMCEvent_pNu_z[0],2);

        truQsq = 0.;
        truQsq = -pow(truEmu - truEnu,2)+threeMomDiff;

        for (int i=0; i<nModels; i++) wt[i] = 1.;

        if (CCQE){
          for (int i=1; i<=nbins_qsq; i++){
           if (truQsq>qsqRatios[0]->GetXaxis()->GetBinLowEdge(i)&&truQsq<=qsqRatios[0]->GetXaxis()->GetBinUpEdge(i))
                for (int j=0; j<nModels; j++) wt[j] = qsqRatios[j]->GetBinContent(i);
          }
        }

        wght = 1.;
        if (doWght) wght = myMCReweightCV_XsecWght[0]*myMCReweightCV_FluxWght[0];

        //----------------------------------------------------------
        //							CUTS
        //----------------------------------------------------------        

        sig = 0;
		//if (fCurrent==0) sig = 1;

        //for eff
        if (fCurrent < numMCfiles){
          tHit1_noCut->Fill(tHits_1SE,mcWt);
          if (genR>550) continue;
          if (nuType==1&&CCQE&&truEnu<0.25){

            tru_tmu_tank_hits_fold->Fill(tHits_1SE,truTmu*1e3);

          }

        }


        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)&&truR<610.6) continue;

 		if (passV==0) continue;
	    if (numSE!=2) continue;
        //if (beamAveTime<4500) continue;//apparently this cut exists in beam-on data so might as well throw it here.  why did they do that?  fjdkjklafds

// CCQE cuts
/*
        if (tHits_1SE<200) continue;
        if (tHits_2SE>200) continue;
	    if (deltaLk<-0.02) continue;
        if (muR>500) continue;
        if (beamAveTime > 11500 || beamAveTime<1000) continue;
*/
           //if (MichDist > 100) continue;//not used

        //if (Range - (500 * Tmu - 100) < 0) continue;
        //if (Range < 100) continue;
// kdar cuts

        if (fCurrent < numMCfiles){
          tHit1_noCut->Fill(tHits_1SE,mcWt);
		  tHit1_cuts_mc_0->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_0->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_0->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_0->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_0->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_0->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_0->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_0->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==8) spitzVar_cuts_pip_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_0->Fill(tHits_1SE);
		    spitzVar_cuts_strobe_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_0->Fill(tHits_1SE);
          tmu_cuts_data_0->Fill(Tmu);
		  spitzVar_cuts_data_0->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (beamAveTime > 6200 || beamAveTime<4400) continue;
        //if (beamAveTime > 4000) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_1->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_1->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_1->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_1->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_1->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_1->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_1->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_1->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
                    if (parent==8) spitzVar_cuts_pip_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);

        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_1->Fill(tHits_1SE);          
		    spitzVar_cuts_strobe_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_1->Fill(tHits_1SE);
          tmu_cuts_data_1->Fill(Tmu);
		  spitzVar_cuts_data_1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        //if (tHits_1SE>60) continue;
        //if (tHits_1SE<60) continue;
        //if (tHits_1SE>120) continue;
        //if (tHits_1SE>200) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_2->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_2->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_2->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_2->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_2->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_2->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_2->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_2->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
                    if (parent==8) spitzVar_cuts_pip_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);

        }

        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_2->Fill(tHits_1SE);          
		    spitzVar_cuts_strobe_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_2->Fill(tHits_1SE);
          tmu_cuts_data_2->Fill(Tmu);
		  spitzVar_cuts_data_2->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }        
        
        // UNCOMMENT
        if (tHits_2SE>200) continue;
        if (tHits_2SE<20) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_3->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_3->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_3->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_3->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_3->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_3->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_3->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_3->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==8) spitzVar_cuts_pip_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
        }

        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_3->Fill(tHits_1SE);          
		    spitzVar_cuts_strobe_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_3->Fill(tHits_1SE);
          tmu_cuts_data_3->Fill(Tmu);
		  spitzVar_cuts_data_3->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }

        if (muR>500) continue;
        //if (muZ<0) continue;
        if (tHits_1SE<20) continue;
        //if (tHits_1SE>250) continue;
        if (mysplitEvent_rmsTimeTank[0]>50) continue;
        //cout<<" MichDist "<<MichDist<<endl;
        if (MichDist>100) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_4->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_4->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_4->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_4->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_4->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_4->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_4->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_4->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==8) spitzVar_cuts_pip_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          
        }

        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_4->Fill(tHits_1SE);          
		    spitzVar_cuts_strobe_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_4->Fill(tHits_1SE);
          tmu_cuts_data_4->Fill(Tmu);
		  spitzVar_cuts_data_4->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }

        //if (tHits_1SE*myStFull_fqlt10[0]/1000 > 0.15) continue;
        //if (tHits_1SE*myStFull_fqlt10[0]/1000==0) continue;

        if (tHits_1SE>50&&tHits_1SE<120&&deltaLk<-0.02) chans->Fill(Channel);

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_5->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_5->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_5->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_5->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_5->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_5->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_5->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_5->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==8) spitzVar_cuts_pip_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          
        }

        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_5->Fill(tHits_1SE);          
		    spitzVar_cuts_strobe_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_5->Fill(tHits_1SE);
          tmu_cuts_data_5->Fill(Tmu);
		  spitzVar_cuts_data_5->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }

        //if (deltaLk<-0.02) continue; // for high-stats CCQE sample
        //if (deltaLk>-0.01) continue;
        //hard deltalk cuts to get kdar
        //if (deltaLk<-0.01) continue;
        //if (deltaLk>0.02) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_6->Fill(tHits_1SE,mcWt);
		  tmu_cuts_mc_6->Fill(Tmu,mcWt);
		  if (parent==8){
		    tHit1_cuts_pip_6->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_6->Fill(Tmu,mcWt);
		  }
		  if (sig){
		    tHit1_cuts_kdar_6->Fill(tHits_1SE,sigWt);
		    tmu_cuts_kdar_6->Fill(Tmu,sigWt);
		  }  
		  if (parent==11){  
		    tHit1_cuts_kp_6->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_6->Fill(Tmu,mcWt);
          }
		  spitzVar_cuts_mc_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==8) spitzVar_cuts_pip_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==9) spitzVar_cuts_pim_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          if (parent==11) spitzVar_cuts_kp_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,mcWt);
          
        }

        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_6->Fill(tHits_1SE);  
			spitzVar_cuts_strobe_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);

        }
        
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    spitzVar_cuts_dirt_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  tHit1_cuts_data_6->Fill(tHits_1SE);
          tmu_cuts_data_6->Fill(Tmu);
		  spitzVar_cuts_data_6->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        }        //
        //if (Range - (500 * Tmu - 100) < 0) continue;
        //if (Range < 100) continue;

        //if (recoUY<0) continue;
        //if (recoUX>0) continue;
        //if (recoUZ>0) continue;
        //cout<<"recoUY "<<recoUY<<endl;

        //if (Tmu<0.03) cout<<"< 30 MeV reco mu: tank hits "<<tHits_1SE<<endl;

        //----------------------------------------------------------
        //							
        //----------------------------------------------------------        
        
        if (fCurrent < numMCfiles){

        if (CCQE){
          truTmuDist->Fill(truTmu);
          ryanTmuDist->Fill(Tmu);
          stanTmuDist->Fill(stancuTmu);
          if (tHits_1SE*myStFull_fqlt10[0]/1000<0.1) mc_qsq_ccqe->Fill(truQsq);
          if (truTmu<0.02){
            uzRes_tmuBinz_ryan_0->Fill(CosThetamu-truUZ);
            uzRes_tmuBinz_stancu_0->Fill(stancuUZ-truUZ);
            uzDist_tmuBinz_ryan_0->Fill(CosThetamu);
            uzDist_tmuBinz_stancu_0->Fill(stancuUZ);
          }
          if (truTmu>=0.02&&truTmu<0.04){
            uzRes_tmuBinz_ryan_1->Fill(CosThetamu-truUZ);
            uzRes_tmuBinz_stancu_1->Fill(stancuUZ-truUZ);
            uzDist_tmuBinz_ryan_1->Fill(CosThetamu);
            uzDist_tmuBinz_stancu_1->Fill(stancuUZ);
            
          }
          if (truTmu>=0.04&&truTmu<0.06){
            uzRes_tmuBinz_ryan_2->Fill(CosThetamu-truUZ);
            uzRes_tmuBinz_stancu_2->Fill(stancuUZ-truUZ);
            uzDist_tmuBinz_ryan_2->Fill(CosThetamu);
            uzDist_tmuBinz_stancu_2->Fill(stancuUZ);
          }
          if (truTmu>=0.06&&truTmu<0.08){
            uzRes_tmuBinz_ryan_3->Fill(CosThetamu-truUZ);
            uzRes_tmuBinz_stancu_3->Fill(stancuUZ-truUZ);
            uzDist_tmuBinz_ryan_3->Fill(CosThetamu);
            uzDist_tmuBinz_stancu_3->Fill(stancuUZ);
          }
          if (truTmu>=0.08&&truTmu<0.10){
            uzRes_tmuBinz_ryan_4->Fill(CosThetamu-truUZ);
            uzRes_tmuBinz_stancu_4->Fill(stancuUZ-truUZ);
            uzDist_tmuBinz_ryan_4->Fill(CosThetamu);
            uzDist_tmuBinz_stancu_4->Fill(stancuUZ);
          }
        }

        //chans->Fill(Channel);

        //cout<<" channel "<<Channel<<endl;

          //cout<<" nutype "<<nuType<<endl;
          //if (nuType!=1) continue;       
 
        
        /*if (parent==11){
          //if ((truEnu>0.230)&&(truEnu<0.240)){
            if (myMCParent_fin_px[1]==0&&myMCParent_fin_py[1]==0&&myMCParent_fin_pz[1]==0) sig = 1; 
          //}
        }*/

        sig = 0;
		//if (fCurrent==0) sig = 1;
        
        //-------------------------------------------------------------
        //              hists
        //-------------------------------------------------------------
        
        posDirCorrX->Fill(myMCParent_init_x[0],nuUX);
        posDirCorrY->Fill(myMCParent_init_y[0],nuUY);
        posDirCorrZ->Fill(myMCParent_init_z[0],nuUZ);
        
	//cout<<" proton init x, y, z "<<myMCParent_init_px[2]<<" "<<myMCParent_init_py[2]<<" "<<myMCParent_init_pz[2]<<endl;

        //if (fCurrent!=0) 
        mcCnt++;       
        //if (fCurrent==0) mcCnt += sigWt;       

        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05){
        
          bmp_ux_mc->Fill(muUX);
          bmp_uy_mc->Fill(muUY);
          bmp_uz_mc->Fill(muUZ);

          bmp_x_mc->Fill(muX);
          bmp_y_mc->Fill(muY);
          bmp_z_mc->Fill(muZ);
          bmp_r_mc->Fill(muR);
        
          bmp_t_mc->Fill(mysplitEvent_aveTimeTank[1]-mysplitEvent_aveTimeTank[0]);
          bmp_th_mc->Fill(tHits_1SE);
        
        }

        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05) mc_inbmp->Fill(tHits_2SE);
        else mc_outbmp->Fill(tHits_2SE);

        truEnu_tHit1->Fill(truEnu,tHits_1SE,mcWt);

        if (tHits_1SE>60&&tHits_1SE<120) 
        	elike_mc_2ndBmp->Fill(-elLk);

        if (tHits_2SE>60&&tHits_2SE<120) 
        	elike_mc_2se->Fill(-elLk_2se);

        //if (fCurrent>0) 
        time_tot->Fill(beamAveTime);
 
        if (tHits_1SE<60) tHit2_mc_firstBump->Fill(tHits_2SE,mcWt);//
        if (tHits_1SE>60&&tHits_1SE<120) tHit2_mc_secondBump->Fill(tHits_2SE,mcWt);

        tHit1_deltaLk_mc->Fill(tHits_1SE,deltaLk,mcWt);
        truEnu_truTmu->Fill(truEnu,truTmu,mcWt);

        tDiff_tot->Fill(tDiff,mcWt);
        truEnu_tot->Fill(truEnu,mcWt);
        truTmu_tot->Fill(truTmu,mcWt);
        truUZ_tot->Fill(truUZ,mcWt);
        truUY_tot->Fill(truUY,mcWt);
        truUX_tot->Fill(truUX,mcWt);
		lk_tot->Fill(deltaLk,mcWt); 
		lk_tot_2se->Fill(deltaLk_2se,mcWt); 
        if (tHits_1SE>120){
        //if (tHits_1SE<120&&tHits_1SE>60){
          lk_2ndBump_tot->Fill(deltaLk,mcWt);
          if (Channel==1) lk_2ndBump_ccqe->Fill(deltaLk,mcWt);
          if (Channel==7) lk_2ndBump_ncpi->Fill(deltaLk,mcWt);
          //if (Channel!=1) cout<<"chan "<<Channel<<endl;
        }

        recUZ_tot->Fill(recoUZ,mcWt);
        recUY_tot->Fill(recoUY,mcWt);
        recUX_tot->Fill(recoUX,mcWt);

        thetaZ_tot->Fill(thetaZ,mcWt);
        thetaY_tot->Fill(thetaY,mcWt);
        thetaX_tot->Fill(thetaX,mcWt);

        thetaXY_tot->Fill(thetaX,thetaY,mcWt);
        thetaXZ_tot->Fill(thetaX,thetaZ,mcWt);
        thetaYZ_tot->Fill(thetaY,thetaZ,mcWt);

        if (tHits_1SE>60&&tHits_1SE<120) 
        	mulike_mc_2ndBmp->Fill(-muLk);

        michEnergy_eHyp_mc->Fill(michE,mcWt);
        michEnergy_muHyp_mc->Fill(michE_muHyp,mcWt);

          thits_mcRng->Fill(tHits_1SE,wght);
          if (parent==8)  thits_pipRng->Fill(tHits_1SE,wght);
          if (parent==9)  thits_pimRng->Fill(tHits_1SE,wght);
          if (parent==11) thits_kpRng->Fill(tHits_1SE,wght);

          for (int j=0; j<nModels; j++){
            spitzVar_mc[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]*wght);
            spitzVar_mc_largeRng[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]*wght);

            thits_mc[j]->Fill(tHits_1SE,wt[j]*wght);
            thits_mc_largeRng[j]->Fill(tHits_1SE,wt[j]*wght);
            if (parent==8)  thits_pip[j]->Fill(tHits_1SE,wt[j]*wght);
            if (parent==9)  thits_pim[j]->Fill(tHits_1SE,wt[j]*wght);
            if (parent==11) thits_kp[j]->Fill(tHits_1SE,wt[j]*wght);
            if (parent!=8&&parent!=9&&parent!=11)
              thits_othr[j]->Fill(tHits_1SE,wt[j]*wght);
          }

        tmu_mc_cv->Fill(truTmu*1e3);
        thits_mc_cv->Fill(tHits_1SE);

        fqlt10_mc->Fill(myStFull_fqlt10[0]);

        //spitzVar_mc->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,myMCWeightDetails_Totalweight[0]);
        //spitzVar_mc_largeRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,myMCWeightDetails_Totalweight[0]);
        //cout<<" tot wt "<<myMCWeightDetails_Totalweight[0]<<endl;
        //cout<<" xsec wt "<<myMCReweightCV_XsecWght[0]<<" flux wt "<<myMCReweightCV_FluxWght[0]<<endl;
        
        truEnuQE_tot->Fill(truEnuQE);
        recEnuQE_tot->Fill(EnuQE,mcWt);
        recEnuQE_tot_bigRng->Fill(EnuQE,mcWt);
        tHit1_tot->Fill(tHits_1SE,mcWt);
        tHit1_totBig->Fill(tHits_1SE,mcWt);
        //if (fCurrent>0) tHit1_tot_nokdar->Fill(tHits_1SE,mcWt);

	    for (int i=0; i<nTmuBins; i++){
	      if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	        AdjRngTmuBns_tot[i]->Fill(adjRange,mcWt);
        }  

        recTmu_tot->Fill(Tmu,mcWt);
        //if (fCurrent>0)
          //recTmu_tot_nokdar->Fill(Tmu,mcWt);
        
        prBirthX->Fill(myMCParent_init_x[2]);
        prBirthY->Fill(myMCParent_init_y[2]);
        prBirthZ->Fill(myMCParent_init_z[2]);

        px_fin_tot->Fill(pX_fin);
        py_fin_tot->Fill(pY_fin);
        pz_fin_tot->Fill(pZ_fin);

        prBirthPX->Fill(myMCParent_init_px[2]);
        prBirthPY->Fill(myMCParent_init_py[2]);
        prBirthPZ->Fill(myMCParent_init_pz[2]);
        
        if (Channel==1) tHit1_ccqe->Fill(tHits_1SE,mcWt);
        if (Channel==7||Channel==8||Channel==9) 
          tHit1_nc1pi->Fill(tHits_1SE,mcWt);
        
        if (parent==10) truEnu_kL->Fill(truEnu);
        if (parent==9) truEnu_pM->Fill(truEnu);
        //if (parent==11){
        if (parent==11){

          //if ((truEnu>0.230)&&(truEnu<0.240)) cout<<" sig! at "<<truEnu<<endl; 

	      for (int i=0; i<nTmuBins; i++){
	        if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	          AdjRngTmuBns_kP[i]->Fill(adjRange);
          }  

		  lk_kP->Fill(deltaLk,mcWt);

          kpBirthPX->Fill(myMCParent_init_px[1]);
          kpBirthPY->Fill(myMCParent_init_py[1]);
          kpBirthPZ->Fill(myMCParent_init_pz[1]);
         
          px_fin_kP->Fill(pX_fin);
          py_fin_kP->Fill(pY_fin);
          pz_fin_kP->Fill(pZ_fin);
         
          tHit1_kP->Fill(tHits_1SE);
          tHit1_kPbig->Fill(tHits_1SE);
          truUZ_kP->Fill(truUZ);
          truUY_kP->Fill(truUY);
          truUX_kP->Fill(truUX);
          
          recUZ_kP->Fill(recoUZ);
          recUY_kP->Fill(recoUY);
          recUX_kP->Fill(recoUX);
          
          thetaZ_kP->Fill(thetaZ);
          thetaY_kP->Fill(thetaY);
          thetaX_kP->Fill(thetaX);
          
          truEnu_kP->Fill(truEnu,mcWt);
          truTmu_kP->Fill(truTmu);
          recTmu_kP->Fill(Tmu);
          truEnuQE_kP->Fill(truEnuQE);
          recEnuQE_kP->Fill(EnuQE);
          recEnuQE_kP_bigRng->Fill(EnuQE);
          ptpz_kP->Fill(pZ,pT);
          ptpz_kP_fin->Fill(pZ_fin,pT_fin);
          kpBirthX->Fill(myMCParent_init_x[1]);
          kpBirthY->Fill(myMCParent_init_y[1]);
          kpBirthZ->Fill(myMCParent_init_z[1]);
        }
        //if (parent==8){
        if (parent==8){

	      for (int i=0; i<nTmuBins; i++){
	        if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	          AdjRngTmuBns_piP[i]->Fill(adjRange,mcWt);
          }  

          thetaPi->Fill(pionUZ);
          pip_phaseSp->Fill(pionMom,pionUZ);


          pipEnThit->Fill(tHits_1SE,pTot);       
          pipEnuThit->Fill(tHits_1SE,truEnu);
          pipEnu->Fill(truEnu);
 
          if ((truEnu>0.20)&&(truEnu<=0.25)) pipKdarBinEvnts += 1.;
        
 	  lk_piP->Fill(deltaLk,mcWt);  
          pipBirthPX->Fill(myMCParent_init_px[1]);
          pipBirthPY->Fill(myMCParent_init_py[1]);
          pipBirthPZ->Fill(myMCParent_init_pz[1]);
        
          px_fin_piP->Fill(pX_fin);
          py_fin_piP->Fill(pY_fin);
          pz_fin_piP->Fill(pZ_fin);

          tHit1_piP->Fill(tHits_1SE);
          tHit1_piPbig->Fill(tHits_1SE);
          truEnu_piP->Fill(truEnu,mcWt);
          truUX_piP->Fill(truUX);
          truUZ_piP->Fill(truUZ);
          truUY_piP->Fill(truUY);

          recUX_piP->Fill(recoUX);
          recUZ_piP->Fill(recoUZ);
          recUY_piP->Fill(recoUY);

          thetaZ_piP->Fill(thetaZ);
          thetaY_piP->Fill(thetaY);
          thetaX_piP->Fill(thetaX);

          truTmu_piP->Fill(truTmu);
          recTmu_piP->Fill(Tmu);
          truEnuQE_piP->Fill(truEnuQE);
          recEnuQE_piP->Fill(EnuQE);
          recEnuQE_piP_bigRng->Fill(EnuQE);
          ptpz_piP->Fill(pZ,pT);
          ptpz_piP_fin->Fill(pZ_fin,pT_fin);
          pipBirthX->Fill(myMCParent_init_x[1]);
          pipBirthY->Fill(myMCParent_init_y[1]);
          pipBirthZ->Fill(myMCParent_init_z[1]);

          //cout<<" pip, nu birth x, y, z "<<myMCParent_init_x[0]<<" "<<myMCParent_init_y[0]<<" "<<myMCParent_init_z[0]<<endl;
        }	

        //cout<<" proton momentum x, y, z "<<myMCParent_init_px[2]<<" "<<myMCParent_init_py[2]<<" "<<myMCParent_init_pz[2]<<endl;
		//cout<<" initial proton, meson, nu time "<<myMCParent_initialT[2]<<" "<<myMCParent_initialT[1]<<" "<<myMCParent_initialT[0]<<endl;

        if (sig){
          //cout<<" sig, parent init pos x, y, z, energy "<<myMCParent_init_x[2]<<" "<<myMCParent_init_y[2]<<" "<<myMCParent_init_z[2]<<" "<<myMCParent_init_pE[2]<<endl;
          //cout<<"\t pt "<<pT<<" pz "<<pZ<<endl;
          //cout<<" \t signal parent E "<<myMCParent_init_pE[0]<<" nuUX "<<nuUX<<" nuUY "<<nuUY<<" nuUZ "<<nuUZ<<endl;
          //cout<<" \t signal kaon momentum x,y,z "<<myMCParent_fin_px[1]<<" "<<myMCParent_fin_py[1]<<" "<<myMCParent_fin_pz[1]<<endl;
          //cout<<" \t signal nu birth position x,y,z "<<myMCParent_init_x[0]<<" "<<myMCParent_init_y[0]<<" "<<myMCParent_init_z[0]<<endl;

	      for (int i=0; i<nTmuBins; i++){
	        if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	          AdjRngTmuBns_sig[i]->Fill(adjRange,sigWt);
          }  

          lk_sig->Fill(deltaLk,sigWt); 
          truEnu_sig->Fill(truEnu,sigWt);
          sigCnt += 1.;
          recTmu_sig->Fill(Tmu,sigWt);
          sig_truTmu->Fill(truTmu,sigWt);
          sig_truUZ->Fill(truUZ,sigWt);
          sig_truUY->Fill(truUY,sigWt);
          sig_truUX->Fill(truUX,sigWt);
          sig_recUZ->Fill(recoUZ,sigWt);
          sig_recUY->Fill(recoUY,sigWt);
          sig_recUX->Fill(recoUX,sigWt);

          sig_thetaZ->Fill(thetaZ,sigWt);
          sig_thetaY->Fill(thetaY,sigWt);
          sig_thetaX->Fill(thetaX,sigWt);
          sig_thetaXZ->Fill(thetaX,thetaZ,sigWt);
          sig_thetaXY->Fill(thetaX,thetaY,sigWt);
          sig_thetaYZ->Fill(thetaY,thetaZ,sigWt);

          sig_truEnuQE->Fill(truEnuQE,sigWt);
          sig_recEnuQE->Fill(EnuQE,sigWt);
          sig_tHit1->Fill(tHits_1SE,sigWt);
          sig_tHit1big->Fill(tHits_1SE,sigWt);
          sig_nuBirthX->Fill(myMCParent_init_x[0],sigWt);
          sig_nuBirthY->Fill(myMCParent_init_y[0],sigWt);
          sig_nuBirthZ->Fill(myMCParent_init_z[0],sigWt);
          truThetaX_sig->Fill(theta_Xtru,sigWt);
          truThetaY_sig->Fill(theta_Ytru,sigWt);
          truThetaZ_sig->Fill(theta_Ztru,sigWt);
          truMinKinX_sig->Fill(theta_Xtru,truTmu,sigWt);
          truMinKinY_sig->Fill(theta_Ytru,truTmu,sigWt);
          truMinKinZ_sig->Fill(theta_Ztru,truTmu,sigWt);
          //cout<<" sig nu birth x, y, z "<<myMCParent_init_x[0]<<" "<<myMCParent_init_y[0]<<" "<<myMCParent_init_z[0]<<endl;
          sig_rad->Fill(myMCParent_init_mag[0],sigWt);
        }

      //if (tHits_1SE<200) cout<<" < 200, ptot "<<pTot<<endl;
      //if (tHits_1SE>200) cout<<" > 200, ptot "<<pTot<<endl;

      }
      
      if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe

        if ( (jentry % 5000) == 0){
          cout << "Strobe!  Entry " << jentry << " file " << fCurrent << endl;
        }

        thits_strobeRng->Fill(tHits_1SE);

        strobe_secSE->Fill(tHits_2SE);

        spitzVar_strobe_largeRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        spitzVar_strobe->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);

        thits_strobe->Fill(tHits_1SE);

        lk_strobe->Fill(deltaLk);
        recUY_strobe->Fill(recoUY);
                recTmu_strobe->Fill(Tmu);
        tHit1_strobe->Fill(tHits_1SE);
        time_strobe->Fill(beamAveTime);

      }

      if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt

        if ( (jentry % 5000) == 0){
          cout << "Dirt!  Entry " << jentry << " file " << fCurrent << endl;
        }

        newtree->Fill();

        //cout << "Dirt!  Channel " << Channel << " qsq " << truQsq << endl;
        
        spitzVar_dirt_largeRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wght);
        spitzVar_dirt->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wght);
        dirt_channels->Fill(Channel);
        dirt_secSE->Fill(tHits_2SE);
        dirt_qsq_ccqe->Fill(truQsq);

          for (int i=0; i<nModels; i++) thits_dirt[i]->Fill(tHits_1SE,wt[i]);
          thits_dirtRng->Fill(tHits_1SE);

          for (int j=0; j<nModels; j++){
            spitzVar_dirt_r[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]*wght);
            //if (CCQE) cout<<"model "<<j<<" qsq "<<truQsq<<"wt "<<wt[j]<<endl;
          }

      }

      if ((fCurrent>=numMCfiles+numStrobeFiles+numDirtFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles+numQtCorrFiles)){ //qtcorr
     
        tmu_mc_qtcorr->Fill(truTmu*1e3);
        thits_mc_qtcorr->Fill(tHits_1SE);

      } 
     
      if ((fCurrent>=numMCfiles+numStrobeFiles+numDirtFiles+numQtCorrFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles+numQtCorrFiles+numDiscFiles)){ //disc

        tmu_mc_disc->Fill(truTmu*1e3);
        thits_mc_disc->Fill(tHits_1SE);

      }
 
      if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles+numQtCorrFiles+numDiscFiles)){//data 
    
        if ( (jentry % 500) == 0){
          cout << "Data!  Entry " << jentry << " file " << fCurrent << " beam time "<< beamAveTime <<endl;
        }
       
        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05){
        
          bmp_ux_data->Fill(muUX);
          bmp_uy_data->Fill(muUY);
          bmp_uz_data->Fill(muUZ);

          bmp_x_data->Fill(muX);
          bmp_y_data->Fill(muY);
          bmp_z_data->Fill(muZ);
          bmp_r_data->Fill(muR);

          bmp_t_data->Fill(mysplitEvent_aveTimeTank[1]-mysplitEvent_aveTimeTank[0]);
          bmp_th_data->Fill(tHits_1SE);
        
        }
       
        if (tHits_1SE>120){
        //if (tHits_1SE<120&&tHits_1SE>60){
          lk_2ndBump_data->Fill(deltaLk);
        }
 
        tHit1_deltaLk_data->Fill(tHits_1SE,deltaLk);
 
        if (tHits_1SE<60) tHit2_data_firstBump->Fill(tHits_2SE);
        if (tHits_1SE>60&&tHits_1SE<120) tHit2_data_secondBump->Fill(tHits_2SE);

        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05) data_inbmp->Fill(tHits_2SE);
        else data_outbmp->Fill(tHits_2SE);
 
        time_data->Fill(beamAveTime);
        tDiff_data->Fill(tDiff);

        if ((beamAveTime>1250)&&(beamAveTime<=2900)) tHit1_data_timeBin_0->Fill(tHits_1SE);
        if ((beamAveTime>2900)&&(beamAveTime<=4550)) tHit1_data_timeBin_1->Fill(tHits_1SE);
        if ((beamAveTime>4550)&&(beamAveTime<=6200)) tHit1_data_timeBin_2->Fill(tHits_1SE);
        if ((beamAveTime>6200)&&(beamAveTime<=7800)) tHit1_data_timeBin_3->Fill(tHits_1SE);
        if ((beamAveTime>7800)&&(beamAveTime<=9500)) tHit1_data_timeBin_4->Fill(tHits_1SE);
        if ((beamAveTime>9500)&&(beamAveTime<=11200)) tHit1_data_timeBin_5->Fill(tHits_1SE);

	    for (int i=0; i<nTmuBins; i++){
	      if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	        AdjRngTmuBns_data[i]->Fill(adjRange);
        }  
        
        tHit1_data->Fill(tHits_1SE);
        tHit1_dataBig->Fill(tHits_1SE);
        recEnuQE_data->Fill(EnuQE);
        recEnuQE_data_bigRng->Fill(EnuQE);
        dataCnt++;
		recTmu_data->Fill(Tmu);
        recUX_data->Fill(recoUX);
        recUY_data->Fill(recoUY);
        recUZ_data->Fill(recoUZ);

        spitzVar_data->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        spitzVar_data_largeRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);

        thits_data->Fill(tHits_1SE);
        thits_dataRng->Fill(tHits_1SE);

        fqlt10_data->Fill(myStFull_fqlt10[0]);

        thetaX_data->Fill(thetaX);
        thetaY_data->Fill(thetaY);
        thetaZ_data->Fill(thetaZ);

        thetaXY_data->Fill(thetaX,thetaY);
        thetaYZ_data->Fill(thetaY,thetaZ);
        thetaXZ_data->Fill(thetaX,thetaZ);

        lk_data->Fill(deltaLk);        
        if (tHits_2SE>60&&tHits_2SE<120) 
        	elike_data_2se->Fill(-elLk_2se);
        if (tHits_1SE>60&&tHits_1SE<120) 
        	elike_data_2ndBmp->Fill(-elLk);

        if (tHits_1SE>60&&tHits_1SE<120) 
        	mulike_data_2ndBmp->Fill(-muLk);

        michEnergy_eHyp_data->Fill(michE,mcWt);
        michEnergy_muHyp_data->Fill(michE_muHyp);
        
        //cout<<"data!"<<endl;
      
      }

   }//jentry loop

newtree->Print();
newtree->AutoSave();
delete newfile;

std::cout<<"made it out of event loop HEYO"<<std::endl;

float potPerFile = 1.371e18;
float dataPOT = 6.411e20;
float mcFiles = 500 * numMCfiles - 1;//500 files -> 1, and starts at 0001 instead of 0000
float mcPOT = potPerFile * mcFiles;
float scaleFactor = dataPOT/mcPOT;

float potPerFile_qtcorr = 1.371e18;
float potPerFile_disc = 1.370e18;
float mcFiles_qtcorr = 1000;//assuming all three files I readered are used
float mcFiles_disc = 1000;//assuming all three files I readered are used
float mcPOT_qtcorr = potPerFile_qtcorr * mcFiles_qtcorr;
float mcPOT_disc = potPerFile_disc * mcFiles_disc;
float scaleFactor_qtcorr = dataPOT/mcPOT_qtcorr;
float scaleFactor_disc = dataPOT/mcPOT_disc;

tmu_mc_cv->Scale(scaleFactor);
tmu_mc_qtcorr->Scale(scaleFactor_qtcorr);
tmu_mc_disc->Scale(scaleFactor_disc);

thits_mc_cv->Scale(scaleFactor);
thits_mc_qtcorr->Scale(scaleFactor_qtcorr);
thits_mc_disc->Scale(scaleFactor_disc);

tmu_mc_cv->SetLineWidth(2);
tmu_mc_qtcorr->SetLineWidth(2);
tmu_mc_disc->SetLineWidth(2);

thits_mc_cv->SetLineWidth(2);
thits_mc_qtcorr->SetLineWidth(2);
thits_mc_disc->SetLineWidth(2);

tmu_mc_qtcorr->SetLineColor(kBlue);
tmu_mc_disc->SetLineColor(kRed);

thits_mc_qtcorr->SetLineColor(kRed);
thits_mc_disc->SetLineColor(kBlue);

tmu_mc_cv->SetTitle("black=cv blue=disc red=qtcorr;T_{#mu} (MeV)");

TCanvas *c_d_qt = new TCanvas();
tmu_mc_cv->Draw();
tmu_mc_qtcorr->Draw("same");
tmu_mc_disc->Draw("same");
c_d_qt->Print("qtcorr_disc_effects.eps");

tmu_mc_cv->SetTitle("black=cv blue=disc red=qtcorr;T_{#mu} (MeV)");

thits_mc_cv->SetTitle("black=cv blue=disc red=qtcorr;tank hits");

gROOT->SetStyle("Plain");
gStyle->SetOptStat(0000);

TCanvas *c_dd_qt = new TCanvas();
thits_mc_cv->Draw();
thits_mc_qtcorr->Draw("same");
thits_mc_disc->Draw("same");
c_dd_qt->Print("qtcorr_disc_effects_tank_hits.eps");

tmu_mc_qtcorr_ratio->Divide(tmu_mc_qtcorr,tmu_mc_cv);
tmu_mc_disc_ratio->Divide(tmu_mc_disc,tmu_mc_cv);

thits_mc_qtcorr_ratio->Divide(thits_mc_qtcorr,thits_mc_cv);
thits_mc_disc_ratio->Divide(thits_mc_disc,thits_mc_cv);

TFile writeFileDet ("det_syst_nu_mode_src.root", "RECREATE");
tmu_mc_cv->Write(tmu_mc_cv->GetName());
tmu_mc_qtcorr->Write(tmu_mc_qtcorr->GetName());
tmu_mc_disc->Write(tmu_mc_disc->GetName());
tmu_mc_qtcorr_ratio->Write(tmu_mc_qtcorr_ratio->GetName());
tmu_mc_disc_ratio->Write(tmu_mc_disc_ratio->GetName());

thits_mc_cv->Write(thits_mc_cv->GetName());
thits_mc_qtcorr->Write(thits_mc_qtcorr->GetName());
thits_mc_disc->Write(thits_mc_disc->GetName());
thits_mc_qtcorr_ratio->Write(thits_mc_qtcorr_ratio->GetName());
thits_mc_disc_ratio->Write(thits_mc_disc_ratio->GetName());

writeFileDet.Close();

//return;

bool relScale = 0;

if (relScale) scaleFactor = (double)dataCnt/(double)mcCnt;

cout<<" mc pot "<<mcPOT<<" data pot "<<dataPOT<<" ratio "<<dataPOT/mcPOT<<endl;

cout<<" data events: "<<dataCnt<<" mc events "<<mcCnt*scaleFactor<<endl;

cout<<"\n\n\t\t pip events in kdar bin (200,250) MeV: "<<pipKdarBinEvnts<<"\n\n\t\t sigCnt "<<sigCnt<<"\n\n"<<endl;

cout<<"\t\t kdar bin pip events "<<truEnu_piP->GetBinContent(5)<<endl;
// data events: 16742 mc events 23522

//float xfactor = (double)23818/17330.9;//0.41207;  23818 mc events 17330.9
//float xfactor = 1.28721;

//scaleFactor *= xfactor;
scaleFactor *= 1.2;//veto sample study - large uncertainty
float strobefactor = 7.27;

fqlt10_mc->Scale(scaleFactor);

lk_strobe->Scale(strobefactor);
recUY_strobe->Scale(strobefactor);
recTmu_strobe->Scale(strobefactor);
tHit1_strobe->Scale(strobefactor);
time_strobe->Scale(strobefactor);

thits_strobe->Scale(strobefactor);

spitzVar_cuts_strobe_0->Scale(strobefactor);
spitzVar_cuts_strobe_1->Scale(strobefactor);
spitzVar_cuts_strobe_2->Scale(strobefactor);
spitzVar_cuts_strobe_3->Scale(strobefactor);
spitzVar_cuts_strobe_4->Scale(strobefactor);
spitzVar_cuts_strobe_5->Scale(strobefactor);
spitzVar_cuts_strobe_6->Scale(strobefactor);

tHit2_mc_firstBump->Scale(scaleFactor);
tHit2_mc_secondBump->Scale(scaleFactor);

tHit1_deltaLk_mc->Scale(scaleFactor);

double dirtfactor = dataPOT/(1000 * 2.589e17);//1000 = number of dirt files, 2.589e+17 = dirt pot/file
dirtfactor *= 0.75;//veto sample study, large uncertainty!

spitzVar_cuts_dirt_0->Scale(dirtfactor);
spitzVar_cuts_dirt_1->Scale(dirtfactor);
spitzVar_cuts_dirt_2->Scale(dirtfactor);
spitzVar_cuts_dirt_3->Scale(dirtfactor);
spitzVar_cuts_dirt_4->Scale(dirtfactor);
spitzVar_cuts_dirt_5->Scale(dirtfactor);
spitzVar_cuts_dirt_6->Scale(dirtfactor);

spitzVar_dirt_largeRng->Scale(dirtfactor);
spitzVar_dirt->Scale(dirtfactor);

spitzVar_strobe_largeRng->Scale(strobefactor);
spitzVar_strobe->Scale(strobefactor);

for (int i=0; i<nModels; i++){
  spitzVar_dirt_r[i]->Scale(dirtfactor);
  cout<<" dirt model "<<i<<" integral "<<spitzVar_dirt_r[i]->Integral()<<endl;
  spitzVar_dirt_r[i]->SetLineWidth(2);
  spitzVar_dirt_r[i]->SetLineColor(28);
  spitzVar_mc[i]->Scale(scaleFactor);
  spitzVar_mc[i]->SetLineWidth(2);
  spitzVar_mc[i]->Add(spitzVar_dirt_r[i]);
  spitzVar_mc[i]->Add(spitzVar_strobe);

  spitzVar_mc_largeRng[i]->Scale(scaleFactor);
  spitzVar_mc_largeRng[i]->SetLineWidth(2);
  spitzVar_mc_largeRng[i]->Add(spitzVar_dirt_largeRng);
  spitzVar_mc_largeRng[i]->Add(spitzVar_strobe_largeRng);

  thits_dirt[i]->Scale(dirtfactor);
  thits_mc[i]->Scale(scaleFactor);//x-factor from nu bnb data 1.22 including tank hit < 200 cut
  thits_mc[i]->SetLineWidth(2);
  thits_mc[i]->Add(thits_dirt[i]);
  thits_mc[i]->Add(thits_strobe);
  thits_mc_largeRng[i]->Scale(scaleFactor);//x-factor from nu bnb data 1.22 including tank hit < 200 cut
  thits_mc_largeRng[i]->SetLineWidth(2);
  thits_pip[i]->SetLineWidth(2);
  thits_pip[i]->SetLineColor(kMagenta);
  thits_pip[i]->Scale(scaleFactor);
  thits_pim[i]->SetLineWidth(2);
  thits_pim[i]->SetLineColor(kCyan);
  thits_pim[i]->Scale(scaleFactor);
  thits_kp[i]->SetLineWidth(2);
  thits_kp[i]->SetLineColor(kBlue);
  thits_kp[i]->Scale(scaleFactor);
  thits_othr[i]->SetLineWidth(2);
  thits_othr[i]->SetLineColor(8);
  thits_othr[i]->Scale(scaleFactor);

}

//spitzVar_mc_largeRng->Scale(scaleFactor);
//spitzVar_mc_largeRng->SetLineWidth(2);

spitzVar_cuts_mc_0->Scale(scaleFactor);
spitzVar_cuts_mc_1->Scale(scaleFactor);
spitzVar_cuts_mc_2->Scale(scaleFactor);
spitzVar_cuts_mc_3->Scale(scaleFactor);
spitzVar_cuts_mc_4->Scale(scaleFactor);
spitzVar_cuts_mc_5->Scale(scaleFactor);
spitzVar_cuts_mc_6->Scale(scaleFactor);

tHit1_cuts_mc_0->Scale(scaleFactor);
tHit1_cuts_mc_1->Scale(scaleFactor);
tHit1_cuts_mc_2->Scale(scaleFactor);
tHit1_cuts_mc_3->Scale(scaleFactor);
tHit1_cuts_mc_4->Scale(scaleFactor);
tHit1_cuts_mc_5->Scale(scaleFactor);
tHit1_cuts_mc_6->Scale(scaleFactor);
tmu_cuts_mc_0->Scale(scaleFactor);
tmu_cuts_mc_1->Scale(scaleFactor);
tmu_cuts_mc_2->Scale(scaleFactor);
tmu_cuts_mc_3->Scale(scaleFactor);
tmu_cuts_mc_4->Scale(scaleFactor);
tmu_cuts_mc_5->Scale(scaleFactor);
tmu_cuts_mc_6->Scale(scaleFactor);

michEnergy_eHyp_mc->Scale(scaleFactor);
michEnergy_muHyp_mc->Scale(scaleFactor);

lk_2ndBump_tot->Scale(scaleFactor);
lk_2ndBump_ccqe->Scale(scaleFactor);
lk_2ndBump_ncpi->Scale(scaleFactor);

tHit1_nc1pi->Scale(scaleFactor);
tHit1_ccqe->Scale(scaleFactor);

tHit1_cuts_pip_0->Scale(scaleFactor);
tHit1_cuts_pip_1->Scale(scaleFactor);
tHit1_cuts_pip_2->Scale(scaleFactor);
tHit1_cuts_pip_3->Scale(scaleFactor);
tHit1_cuts_pip_4->Scale(scaleFactor);
tHit1_cuts_pip_5->Scale(scaleFactor);
tHit1_cuts_pip_6->Scale(scaleFactor);
tmu_cuts_pip_0->Scale(scaleFactor);
tmu_cuts_pip_1->Scale(scaleFactor);
tmu_cuts_pip_2->Scale(scaleFactor);
tmu_cuts_pip_3->Scale(scaleFactor);
tmu_cuts_pip_4->Scale(scaleFactor);
tmu_cuts_pip_5->Scale(scaleFactor);
tmu_cuts_pip_6->Scale(scaleFactor);

tHit1_cuts_kdar_0->Scale(scaleFactor);
tHit1_cuts_kdar_1->Scale(scaleFactor);
tHit1_cuts_kdar_2->Scale(scaleFactor);
tHit1_cuts_kdar_3->Scale(scaleFactor);
tHit1_cuts_kdar_4->Scale(scaleFactor);
tHit1_cuts_kdar_5->Scale(scaleFactor);
tHit1_cuts_kdar_6->Scale(scaleFactor);
tmu_cuts_kdar_0->Scale(scaleFactor);
tmu_cuts_kdar_1->Scale(scaleFactor);
tmu_cuts_kdar_2->Scale(scaleFactor);
tmu_cuts_kdar_3->Scale(scaleFactor);
tmu_cuts_kdar_4->Scale(scaleFactor);
tmu_cuts_kdar_5->Scale(scaleFactor);
tmu_cuts_kdar_6->Scale(scaleFactor);

elike_mc_2ndBmp->Scale(scaleFactor);
elike_mc_2se->Scale(scaleFactor);

mulike_mc_2ndBmp->Scale(scaleFactor);
mulike_mc_2ndBmp->SetLineWidth(2);

spitzVar_cuts_kp_0->Scale(scaleFactor);
spitzVar_cuts_kp_1->Scale(scaleFactor);
spitzVar_cuts_kp_2->Scale(scaleFactor);
spitzVar_cuts_kp_3->Scale(scaleFactor);
spitzVar_cuts_kp_4->Scale(scaleFactor);
spitzVar_cuts_kp_5->Scale(scaleFactor);
spitzVar_cuts_kp_6->Scale(scaleFactor);

spitzVar_cuts_pip_0->Scale(scaleFactor);
spitzVar_cuts_pip_1->Scale(scaleFactor);
spitzVar_cuts_pip_2->Scale(scaleFactor);
spitzVar_cuts_pip_3->Scale(scaleFactor);
spitzVar_cuts_pip_4->Scale(scaleFactor);
spitzVar_cuts_pip_5->Scale(scaleFactor);
spitzVar_cuts_pip_6->Scale(scaleFactor);

spitzVar_cuts_pim_0->Scale(scaleFactor);
spitzVar_cuts_pim_1->Scale(scaleFactor);
spitzVar_cuts_pim_2->Scale(scaleFactor);
spitzVar_cuts_pim_3->Scale(scaleFactor);
spitzVar_cuts_pim_4->Scale(scaleFactor);
spitzVar_cuts_pim_5->Scale(scaleFactor);
spitzVar_cuts_pim_6->Scale(scaleFactor);

tHit1_cuts_kp_0->Scale(scaleFactor);
tHit1_cuts_kp_1->Scale(scaleFactor);
tHit1_cuts_kp_2->Scale(scaleFactor);
tHit1_cuts_kp_3->Scale(scaleFactor);
tHit1_cuts_kp_4->Scale(scaleFactor);
tHit1_cuts_kp_5->Scale(scaleFactor);
tHit1_cuts_kp_6->Scale(scaleFactor);
tmu_cuts_kp_0->Scale(scaleFactor);
tmu_cuts_kp_1->Scale(scaleFactor);
tmu_cuts_kp_2->Scale(scaleFactor);
tmu_cuts_kp_3->Scale(scaleFactor);
tmu_cuts_kp_4->Scale(scaleFactor);
tmu_cuts_kp_5->Scale(scaleFactor);
tmu_cuts_kp_6->Scale(scaleFactor);

/*
tHit1_cuts_strobe_0->Scale(strobefactor);
tHit1_cuts_strobe_1->Scale(strobefactor);
tHit1_cuts_strobe_2->Scale(strobefactor);
tHit1_cuts_strobe_3->Scale(strobefactor);
tHit1_cuts_strobe_4->Scale(strobefactor);
tHit1_cuts_strobe_5->Scale(strobefactor);
tHit1_cuts_strobe_6->Scale(strobefactor);
*/

tHit1_cuts_mc_0->SetLineWidth(2);
tHit1_cuts_mc_1->SetLineWidth(2);
tHit1_cuts_mc_2->SetLineWidth(2);
tHit1_cuts_mc_3->SetLineWidth(2);
tHit1_cuts_mc_4->SetLineWidth(2);
tHit1_cuts_mc_5->SetLineWidth(2);
tHit1_cuts_mc_6->SetLineWidth(2);
tmu_cuts_mc_0->SetLineWidth(2);
tmu_cuts_mc_1->SetLineWidth(2);
tmu_cuts_mc_2->SetLineWidth(2);
tmu_cuts_mc_3->SetLineWidth(2);
tmu_cuts_mc_4->SetLineWidth(2);
tmu_cuts_mc_5->SetLineWidth(2);
tmu_cuts_mc_6->SetLineWidth(2);

michEnergy_eHyp_mc->SetLineWidth(2);
michEnergy_muHyp_mc->SetLineWidth(2);

lk_2ndBump_tot->SetLineWidth(2);
lk_2ndBump_ccqe->SetLineWidth(2);
lk_2ndBump_ccqe->SetLineColor(kRed);
lk_2ndBump_ncpi->SetLineWidth(2);
lk_2ndBump_ncpi->SetLineColor(28);

tHit1_cuts_pip_0->SetLineWidth(2);
tHit1_cuts_pip_1->SetLineWidth(2);
tHit1_cuts_pip_2->SetLineWidth(2);
tHit1_cuts_pip_3->SetLineWidth(2);
tHit1_cuts_pip_4->SetLineWidth(2);
tHit1_cuts_pip_5->SetLineWidth(2);
tHit1_cuts_pip_6->SetLineWidth(2);
tmu_cuts_pip_0->SetLineWidth(2);
tmu_cuts_pip_1->SetLineWidth(2);
tmu_cuts_pip_2->SetLineWidth(2);
tmu_cuts_pip_3->SetLineWidth(2);
tmu_cuts_pip_4->SetLineWidth(2);
tmu_cuts_pip_5->SetLineWidth(2);
tmu_cuts_pip_6->SetLineWidth(2);

spitzVar_strobe_largeRng->SetLineWidth(2);
spitzVar_strobe->SetLineWidth(2);

spitzVar_strobe_largeRng->SetLineColor(95);
spitzVar_strobe->SetLineColor(95);

tHit1_cuts_kdar_0->SetLineWidth(2);
tHit1_cuts_kdar_1->SetLineWidth(2);
tHit1_cuts_kdar_2->SetLineWidth(2);
tHit1_cuts_kdar_3->SetLineWidth(2);
tHit1_cuts_kdar_4->SetLineWidth(2);
tHit1_cuts_kdar_5->SetLineWidth(2);
tHit1_cuts_kdar_6->SetLineWidth(2);
tmu_cuts_kdar_0->SetLineWidth(2);
tmu_cuts_kdar_1->SetLineWidth(2);
tmu_cuts_kdar_2->SetLineWidth(2);
tmu_cuts_kdar_3->SetLineWidth(2);
tmu_cuts_kdar_4->SetLineWidth(2);
tmu_cuts_kdar_5->SetLineWidth(2);
tmu_cuts_kdar_6->SetLineWidth(2);

tHit1_cuts_kp_0->SetLineWidth(2);
tHit1_cuts_kp_1->SetLineWidth(2);
tHit1_cuts_kp_2->SetLineWidth(2);
tHit1_cuts_kp_3->SetLineWidth(2);
tHit1_cuts_kp_4->SetLineWidth(2);
tHit1_cuts_kp_5->SetLineWidth(2);
tHit1_cuts_kp_6->SetLineWidth(2);
tmu_cuts_kp_0->SetLineWidth(2);
tmu_cuts_kp_1->SetLineWidth(2);
tmu_cuts_kp_2->SetLineWidth(2);
tmu_cuts_kp_3->SetLineWidth(2);
tmu_cuts_kp_4->SetLineWidth(2);
tmu_cuts_kp_5->SetLineWidth(2);
tmu_cuts_kp_6->SetLineWidth(2);

spitzVar_cuts_kp_0->SetLineWidth(2);
spitzVar_cuts_kp_1->SetLineWidth(2);
spitzVar_cuts_kp_2->SetLineWidth(2);
spitzVar_cuts_kp_3->SetLineWidth(2);
spitzVar_cuts_kp_4->SetLineWidth(2);
spitzVar_cuts_kp_5->SetLineWidth(2);
spitzVar_cuts_kp_6->SetLineWidth(2);

spitzVar_cuts_pip_0->SetLineWidth(2);
spitzVar_cuts_pip_1->SetLineWidth(2);
spitzVar_cuts_pip_2->SetLineWidth(2);
spitzVar_cuts_pip_3->SetLineWidth(2);
spitzVar_cuts_pip_4->SetLineWidth(2);
spitzVar_cuts_pip_5->SetLineWidth(2);
spitzVar_cuts_pip_6->SetLineWidth(2);

spitzVar_cuts_pim_0->SetLineWidth(2);
spitzVar_cuts_pim_1->SetLineWidth(2);
spitzVar_cuts_pim_2->SetLineWidth(2);
spitzVar_cuts_pim_3->SetLineWidth(2);
spitzVar_cuts_pim_4->SetLineWidth(2);
spitzVar_cuts_pim_5->SetLineWidth(2);
spitzVar_cuts_pim_6->SetLineWidth(2);


tHit1_cuts_strobe_0->SetLineWidth(2);
tHit1_cuts_strobe_1->SetLineWidth(2);
tHit1_cuts_strobe_2->SetLineWidth(2);
tHit1_cuts_strobe_3->SetLineWidth(2);
tHit1_cuts_strobe_4->SetLineWidth(2);
tHit1_cuts_strobe_5->SetLineWidth(2);
tHit1_cuts_strobe_6->SetLineWidth(2);

tHit1_cuts_strobe_0->SetLineColor(95);
tHit1_cuts_strobe_1->SetLineColor(95);
tHit1_cuts_strobe_2->SetLineColor(95);
tHit1_cuts_strobe_3->SetLineColor(95);
tHit1_cuts_strobe_4->SetLineColor(95);
tHit1_cuts_strobe_5->SetLineColor(95);
tHit1_cuts_strobe_6->SetLineColor(95);

tHit1_cuts_kp_0->SetLineColor(kBlue);
tHit1_cuts_kp_1->SetLineColor(kBlue);
tHit1_cuts_kp_2->SetLineColor(kBlue);
tHit1_cuts_kp_3->SetLineColor(kBlue);
tHit1_cuts_kp_4->SetLineColor(kBlue);
tHit1_cuts_kp_5->SetLineColor(kBlue);
tHit1_cuts_kp_6->SetLineColor(kBlue);
tmu_cuts_kp_0->SetLineColor(kBlue);
tmu_cuts_kp_1->SetLineColor(kBlue);
tmu_cuts_kp_2->SetLineColor(kBlue);
tmu_cuts_kp_3->SetLineColor(kBlue);
tmu_cuts_kp_4->SetLineColor(kBlue);
tmu_cuts_kp_5->SetLineColor(kBlue);
tmu_cuts_kp_6->SetLineColor(kBlue);

spitzVar_cuts_kp_0->SetLineColor(kBlue);
spitzVar_cuts_kp_1->SetLineColor(kBlue);
spitzVar_cuts_kp_2->SetLineColor(kBlue);
spitzVar_cuts_kp_3->SetLineColor(kBlue);
spitzVar_cuts_kp_4->SetLineColor(kBlue);
spitzVar_cuts_kp_5->SetLineColor(kBlue);
spitzVar_cuts_kp_6->SetLineColor(kBlue);

spitzVar_cuts_pip_0->SetLineColor(kMagenta);
spitzVar_cuts_pip_1->SetLineColor(kMagenta);
spitzVar_cuts_pip_2->SetLineColor(kMagenta);
spitzVar_cuts_pip_3->SetLineColor(kMagenta);
spitzVar_cuts_pip_4->SetLineColor(kMagenta);
spitzVar_cuts_pip_5->SetLineColor(kMagenta);
spitzVar_cuts_pip_6->SetLineColor(kMagenta);

spitzVar_cuts_pim_0->SetLineColor(kCyan);
spitzVar_cuts_pim_1->SetLineColor(kCyan);
spitzVar_cuts_pim_2->SetLineColor(kCyan);
spitzVar_cuts_pim_3->SetLineColor(kCyan);
spitzVar_cuts_pim_4->SetLineColor(kCyan);
spitzVar_cuts_pim_5->SetLineColor(kCyan);
spitzVar_cuts_pim_6->SetLineColor(kCyan);

tHit1_cuts_pip_0->SetLineColor(kMagenta);
tHit1_cuts_pip_1->SetLineColor(kMagenta);
tHit1_cuts_pip_2->SetLineColor(kMagenta);
tHit1_cuts_pip_3->SetLineColor(kMagenta);
tHit1_cuts_pip_4->SetLineColor(kMagenta);
tHit1_cuts_pip_5->SetLineColor(kMagenta);
tHit1_cuts_pip_6->SetLineColor(kMagenta);
tmu_cuts_pip_0->SetLineColor(kMagenta);
tmu_cuts_pip_1->SetLineColor(kMagenta);
tmu_cuts_pip_2->SetLineColor(kMagenta);
tmu_cuts_pip_3->SetLineColor(kMagenta);
tmu_cuts_pip_4->SetLineColor(kMagenta);
tmu_cuts_pip_5->SetLineColor(kMagenta);
tmu_cuts_pip_6->SetLineColor(kMagenta);

tHit1_cuts_kdar_0->SetLineColor(kGreen);
tHit1_cuts_kdar_1->SetLineColor(kGreen);
tHit1_cuts_kdar_2->SetLineColor(kGreen);
tHit1_cuts_kdar_3->SetLineColor(kGreen);
tHit1_cuts_kdar_4->SetLineColor(kGreen);
tHit1_cuts_kdar_5->SetLineColor(kGreen);
tHit1_cuts_kdar_6->SetLineColor(kGreen);
tmu_cuts_kdar_0->SetLineColor(kGreen);
tmu_cuts_kdar_1->SetLineColor(kGreen);
tmu_cuts_kdar_2->SetLineColor(kGreen);
tmu_cuts_kdar_3->SetLineColor(kGreen);
tmu_cuts_kdar_4->SetLineColor(kGreen);
tmu_cuts_kdar_5->SetLineColor(kGreen);
tmu_cuts_kdar_6->SetLineColor(kGreen);

tHit1_nc1pi->SetLineWidth(2);
tHit1_ccqe->SetLineWidth(2);
tHit1_nc1pi->SetLineColor(28);
tHit1_ccqe->SetLineColor(kRed);

thits_data->SetFillStyle(0);
thits_data->SetMarkerStyle(20);
thits_data->SetMarkerSize(0.7);
thits_data->SetLineColor(1);
thits_data->SetMarkerColor(2);
thits_data->SetBarWidth(4);
thits_data->SetLineWidth(1);

spitzVar_data->SetFillStyle(0);
spitzVar_data->SetMarkerStyle(20);
spitzVar_data->SetMarkerSize(0.7);
spitzVar_data->SetLineColor(1);
spitzVar_data->SetMarkerColor(2);
spitzVar_data->SetBarWidth(4);
spitzVar_data->SetLineWidth(1);

spitzVar_data_largeRng->SetFillStyle(0);
spitzVar_data_largeRng->SetMarkerStyle(20);
spitzVar_data_largeRng->SetMarkerSize(0.7);
spitzVar_data_largeRng->SetLineColor(1);
spitzVar_data_largeRng->SetMarkerColor(2);
spitzVar_data_largeRng->SetBarWidth(4);
spitzVar_data_largeRng->SetLineWidth(1);

michEnergy_muHyp_data->SetFillStyle(0);
michEnergy_muHyp_data->SetMarkerStyle(20);
michEnergy_muHyp_data->SetMarkerSize(0.7);
michEnergy_muHyp_data->SetLineColor(1);
michEnergy_muHyp_data->SetMarkerColor(2);
michEnergy_muHyp_data->SetBarWidth(4);
michEnergy_muHyp_data->SetLineWidth(1);

michEnergy_eHyp_data->SetFillStyle(0);
michEnergy_eHyp_data->SetMarkerStyle(20);
michEnergy_eHyp_data->SetMarkerSize(0.7);
michEnergy_eHyp_data->SetLineColor(1);
michEnergy_eHyp_data->SetMarkerColor(2);
michEnergy_eHyp_data->SetBarWidth(4);
michEnergy_eHyp_data->SetLineWidth(1);

lk_2ndBump_data->SetFillStyle(0);
lk_2ndBump_data->SetMarkerStyle(20);
lk_2ndBump_data->SetMarkerSize(0.7);
lk_2ndBump_data->SetLineColor(1);
lk_2ndBump_data->SetMarkerColor(2);
lk_2ndBump_data->SetBarWidth(4);
lk_2ndBump_data->SetLineWidth(1);

tHit1_cuts_data_0->SetFillStyle(0);
tHit1_cuts_data_0->SetMarkerStyle(20);
tHit1_cuts_data_0->SetMarkerSize(0.7);
tHit1_cuts_data_0->SetLineColor(1);
tHit1_cuts_data_0->SetMarkerColor(2);
tHit1_cuts_data_0->SetBarWidth(4);
tHit1_cuts_data_0->SetLineWidth(1);

tmu_cuts_data_0->SetFillStyle(0);
tmu_cuts_data_0->SetMarkerStyle(20);
tmu_cuts_data_0->SetMarkerSize(0.7);
tmu_cuts_data_0->SetLineColor(1);
tmu_cuts_data_0->SetMarkerColor(2);
tmu_cuts_data_0->SetBarWidth(4);
tmu_cuts_data_0->SetLineWidth(1);

tHit1_cuts_data_1->SetFillStyle(0);
tHit1_cuts_data_1->SetMarkerStyle(20);
tHit1_cuts_data_1->SetMarkerSize(0.7);
tHit1_cuts_data_1->SetLineColor(1);
tHit1_cuts_data_1->SetMarkerColor(2);
tHit1_cuts_data_1->SetBarWidth(4);
tHit1_cuts_data_1->SetLineWidth(1);

tmu_cuts_data_1->SetFillStyle(0);
tmu_cuts_data_1->SetMarkerStyle(20);
tmu_cuts_data_1->SetMarkerSize(0.7);
tmu_cuts_data_1->SetLineColor(1);
tmu_cuts_data_1->SetMarkerColor(2);
tmu_cuts_data_1->SetBarWidth(4);
tmu_cuts_data_1->SetLineWidth(1);

tHit1_cuts_data_2->SetFillStyle(0);
tHit1_cuts_data_2->SetMarkerStyle(20);
tHit1_cuts_data_2->SetMarkerSize(0.7);
tHit1_cuts_data_2->SetLineColor(1);
tHit1_cuts_data_2->SetMarkerColor(2);
tHit1_cuts_data_2->SetBarWidth(4);
tHit1_cuts_data_2->SetLineWidth(1);

tmu_cuts_data_2->SetFillStyle(0);
tmu_cuts_data_2->SetMarkerStyle(20);
tmu_cuts_data_2->SetMarkerSize(0.7);
tmu_cuts_data_2->SetLineColor(1);
tmu_cuts_data_2->SetMarkerColor(2);
tmu_cuts_data_2->SetBarWidth(4);
tmu_cuts_data_2->SetLineWidth(1);

tHit1_cuts_data_3->SetFillStyle(0);
tHit1_cuts_data_3->SetMarkerStyle(20);
tHit1_cuts_data_3->SetMarkerSize(0.7);
tHit1_cuts_data_3->SetLineColor(1);
tHit1_cuts_data_3->SetMarkerColor(2);
tHit1_cuts_data_3->SetBarWidth(4);
tHit1_cuts_data_3->SetLineWidth(1);

tmu_cuts_data_3->SetFillStyle(0);
tmu_cuts_data_3->SetMarkerStyle(20);
tmu_cuts_data_3->SetMarkerSize(0.7);
tmu_cuts_data_3->SetLineColor(1);
tmu_cuts_data_3->SetMarkerColor(2);
tmu_cuts_data_3->SetBarWidth(4);
tmu_cuts_data_3->SetLineWidth(1);

tHit1_cuts_data_4->SetFillStyle(0);
tHit1_cuts_data_4->SetMarkerStyle(20);
tHit1_cuts_data_4->SetMarkerSize(0.7);
tHit1_cuts_data_4->SetLineColor(1);
tHit1_cuts_data_4->SetMarkerColor(2);
tHit1_cuts_data_4->SetBarWidth(4);
tHit1_cuts_data_4->SetLineWidth(1);

tmu_cuts_data_4->SetFillStyle(0);
tmu_cuts_data_4->SetMarkerStyle(20);
tmu_cuts_data_4->SetMarkerSize(0.7);
tmu_cuts_data_4->SetLineColor(1);
tmu_cuts_data_4->SetMarkerColor(2);
tmu_cuts_data_4->SetBarWidth(4);
tmu_cuts_data_4->SetLineWidth(1);

tHit1_cuts_data_5->SetFillStyle(0);
tHit1_cuts_data_5->SetMarkerStyle(20);
tHit1_cuts_data_5->SetMarkerSize(0.7);
tHit1_cuts_data_5->SetLineColor(1);
tHit1_cuts_data_5->SetMarkerColor(2);
tHit1_cuts_data_5->SetBarWidth(4);
tHit1_cuts_data_5->SetLineWidth(1);

tmu_cuts_data_5->SetFillStyle(0);
tmu_cuts_data_5->SetMarkerStyle(20);
tmu_cuts_data_5->SetMarkerSize(0.7);
tmu_cuts_data_5->SetLineColor(1);
tmu_cuts_data_5->SetMarkerColor(2);
tmu_cuts_data_5->SetBarWidth(4);
tmu_cuts_data_5->SetLineWidth(1);

tHit1_cuts_data_6->SetFillStyle(0);
tHit1_cuts_data_6->SetMarkerStyle(20);
tHit1_cuts_data_6->SetMarkerSize(0.7);
tHit1_cuts_data_6->SetLineColor(1);
tHit1_cuts_data_6->SetMarkerColor(2);
tHit1_cuts_data_6->SetBarWidth(4);
tHit1_cuts_data_6->SetLineWidth(1);

spitzVar_cuts_data_0->SetFillStyle(0);
spitzVar_cuts_data_0->SetMarkerStyle(20);
spitzVar_cuts_data_0->SetMarkerSize(0.7);
spitzVar_cuts_data_0->SetLineColor(1);
spitzVar_cuts_data_0->SetMarkerColor(2);
spitzVar_cuts_data_0->SetBarWidth(4);
spitzVar_cuts_data_0->SetLineWidth(1);

spitzVar_cuts_data_1->SetFillStyle(0);
spitzVar_cuts_data_1->SetMarkerStyle(20);
spitzVar_cuts_data_1->SetMarkerSize(0.7);
spitzVar_cuts_data_1->SetLineColor(1);
spitzVar_cuts_data_1->SetMarkerColor(2);
spitzVar_cuts_data_1->SetBarWidth(4);
spitzVar_cuts_data_1->SetLineWidth(1);

spitzVar_cuts_data_2->SetFillStyle(0);
spitzVar_cuts_data_2->SetMarkerStyle(20);
spitzVar_cuts_data_2->SetMarkerSize(0.7);
spitzVar_cuts_data_2->SetLineColor(1);
spitzVar_cuts_data_2->SetMarkerColor(2);
spitzVar_cuts_data_2->SetBarWidth(4);
spitzVar_cuts_data_2->SetLineWidth(1);

spitzVar_cuts_data_3->SetFillStyle(0);
spitzVar_cuts_data_3->SetMarkerStyle(20);
spitzVar_cuts_data_3->SetMarkerSize(0.7);
spitzVar_cuts_data_3->SetLineColor(1);
spitzVar_cuts_data_3->SetMarkerColor(2);
spitzVar_cuts_data_3->SetBarWidth(4);
spitzVar_cuts_data_3->SetLineWidth(1);

spitzVar_cuts_data_4->SetFillStyle(0);
spitzVar_cuts_data_4->SetMarkerStyle(20);
spitzVar_cuts_data_4->SetMarkerSize(0.7);
spitzVar_cuts_data_4->SetLineColor(1);
spitzVar_cuts_data_4->SetMarkerColor(2);
spitzVar_cuts_data_4->SetBarWidth(4);
spitzVar_cuts_data_4->SetLineWidth(1);

spitzVar_cuts_data_5->SetFillStyle(0);
spitzVar_cuts_data_5->SetMarkerStyle(20);
spitzVar_cuts_data_5->SetMarkerSize(0.7);
spitzVar_cuts_data_5->SetLineColor(1);
spitzVar_cuts_data_5->SetMarkerColor(2);
spitzVar_cuts_data_5->SetBarWidth(4);
spitzVar_cuts_data_5->SetLineWidth(1);

spitzVar_cuts_data_6->SetFillStyle(0);
spitzVar_cuts_data_6->SetMarkerStyle(20);
spitzVar_cuts_data_6->SetMarkerSize(0.7);
spitzVar_cuts_data_6->SetLineColor(1);
spitzVar_cuts_data_6->SetMarkerColor(2);
spitzVar_cuts_data_6->SetBarWidth(4);
spitzVar_cuts_data_6->SetLineWidth(1);

tmu_cuts_data_6->SetFillStyle(0);
tmu_cuts_data_6->SetMarkerStyle(20);
tmu_cuts_data_6->SetMarkerSize(0.7);
tmu_cuts_data_6->SetLineColor(1);
tmu_cuts_data_6->SetMarkerColor(2);
tmu_cuts_data_6->SetBarWidth(4);
tmu_cuts_data_6->SetLineWidth(1);

for (int i=0; i<nTmuBins; i++){
  AdjRngTmuBns_tot[i]->Scale(scaleFactor);
  AdjRngTmuBns_kP[i]->Scale(scaleFactor);
  AdjRngTmuBns_piP[i]->Scale(scaleFactor);
  AdjRngTmuBns_sig[i]->Scale(scaleFactor);
}

for (int i=0; i<nTmuBins; i++){
  AdjRngTmuBns_tot[i]->SetLineWidth(2);
  AdjRngTmuBns_kP[i]->SetLineWidth(2);
  AdjRngTmuBns_piP[i]->SetLineWidth(2);
  AdjRngTmuBns_sig[i]->SetLineWidth(2);
}

for (int i=0; i<nTmuBins; i++){
  AdjRngTmuBns_tot[i]->SetLineColor(kBlack);
  AdjRngTmuBns_kP[i]->SetLineColor(kBlue);
  AdjRngTmuBns_piP[i]->SetLineColor(kMagenta);
  AdjRngTmuBns_sig[i]->SetLineColor(kGreen);
}

tHit2_mc_firstBump->SetLineWidth(2);
tHit2_mc_secondBump->SetLineWidth(2);

lk_sig->SetLineWidth(2);
lk_sig->SetLineColor(kGreen);
lk_tot->SetLineWidth(2);
lk_tot_2se->SetLineWidth(2);
lk_piP->SetLineWidth(2);
lk_kP->SetLineWidth(2);  
lk_data->SetFillStyle(0);
lk_data->SetMarkerStyle(20);
lk_data->SetMarkerSize(0.7);
lk_data->SetLineColor(1);
lk_data->SetMarkerColor(2);
lk_data->SetBarWidth(4);
lk_data->SetLineWidth(1);
elike_data_2se->SetFillStyle(0);
elike_data_2se->SetMarkerStyle(20);
elike_data_2se->SetMarkerSize(0.7);
elike_data_2se->SetLineColor(2);
elike_data_2se->SetMarkerColor(2);
elike_data_2se->SetBarWidth(4);
elike_data_2se->SetLineWidth(1);

elike_mc_2ndBmp->SetLineWidth(2);
elike_mc_2ndBmp->SetLineColor(kBlue);
elike_mc_2se->SetLineWidth(2);
elike_mc_2se->SetLineColor(kRed);

elike_data_2ndBmp->SetFillStyle(0);
elike_data_2ndBmp->SetMarkerStyle(20);
elike_data_2ndBmp->SetMarkerSize(0.7);
elike_data_2ndBmp->SetLineColor(kBlue);
elike_data_2ndBmp->SetMarkerColor(kBlue);
elike_data_2ndBmp->SetBarWidth(4);
elike_data_2ndBmp->SetLineWidth(1);

mulike_data_2ndBmp->SetFillStyle(0);
mulike_data_2ndBmp->SetMarkerStyle(20);
mulike_data_2ndBmp->SetMarkerSize(0.7);
mulike_data_2ndBmp->SetLineColor(1);
mulike_data_2ndBmp->SetMarkerColor(2);
mulike_data_2ndBmp->SetBarWidth(4);
mulike_data_2ndBmp->SetLineWidth(1);

lk_piP->SetLineColor(kMagenta);
lk_kP->SetLineColor(kBlue);

for (int i=0; i<nTmuBins; i++){
  AdjRngTmuBns_data[i]->SetFillStyle(0);
  AdjRngTmuBns_data[i]->SetMarkerStyle(20);
  AdjRngTmuBns_data[i]->SetMarkerSize(0.7);
  AdjRngTmuBns_data[i]->SetLineColor(1);
  AdjRngTmuBns_data[i]->SetMarkerColor(2);
  AdjRngTmuBns_data[i]->SetBarWidth(4);
  AdjRngTmuBns_data[i]->SetLineWidth(1);
}

lk_strobe->SetLineWidth(2);
lk_strobe->SetLineColor(95);
recTmu_strobe->SetLineWidth(2);
recTmu_strobe->SetLineColor(95);
tHit1_strobe->SetLineWidth(2);
tHit1_strobe->SetLineColor(95);

time_tot->SetLineWidth(2);

tHit2_data_firstBump->SetFillStyle(0);
tHit2_data_firstBump->SetMarkerStyle(20);
tHit2_data_firstBump->SetMarkerSize(0.7);
tHit2_data_firstBump->SetLineColor(1);
tHit2_data_firstBump->SetMarkerColor(2);
tHit2_data_firstBump->SetBarWidth(4);
tHit2_data_firstBump->SetLineWidth(1);

tHit2_data_secondBump->SetFillStyle(0);
tHit2_data_secondBump->SetMarkerStyle(20);
tHit2_data_secondBump->SetMarkerSize(0.7);
tHit2_data_secondBump->SetLineColor(1);
tHit2_data_secondBump->SetMarkerColor(2);
tHit2_data_secondBump->SetBarWidth(4);
tHit2_data_secondBump->SetLineWidth(1);

time_data->SetFillStyle(0);
time_data->SetMarkerStyle(20);
time_data->SetMarkerSize(0.7);
time_data->SetLineColor(1);
time_data->SetMarkerColor(2);
time_data->SetBarWidth(4);
time_data->SetLineWidth(1);

tDiff_data->SetFillStyle(0);
tDiff_data->SetMarkerStyle(20);
tDiff_data->SetMarkerSize(0.7);
tDiff_data->SetLineColor(1);
tDiff_data->SetMarkerColor(2);
tDiff_data->SetBarWidth(4);
tDiff_data->SetLineWidth(1);

tHit1_dataBig->SetFillStyle(0);
tHit1_dataBig->SetMarkerStyle(20);
tHit1_dataBig->SetMarkerSize(0.7);
tHit1_dataBig->SetLineColor(1);
tHit1_dataBig->SetMarkerColor(2);
tHit1_dataBig->SetBarWidth(4);
tHit1_dataBig->SetLineWidth(1);
tHit1_data->SetFillStyle(0);
tHit1_data->SetMarkerStyle(20);
tHit1_data->SetMarkerSize(0.7);
tHit1_data->SetLineColor(1);
tHit1_data->SetMarkerColor(2);
tHit1_data->SetBarWidth(4);
tHit1_data->SetLineWidth(1);
recEnuQE_data->SetFillStyle(0);
recEnuQE_data->SetMarkerStyle(20);
recEnuQE_data->SetMarkerSize(0.7);
recEnuQE_data->SetLineColor(1);
recEnuQE_data->SetMarkerColor(2);
recEnuQE_data->SetBarWidth(4);
recEnuQE_data->SetLineWidth(1);
recEnuQE_data_bigRng->SetFillStyle(0);
recEnuQE_data_bigRng->SetMarkerStyle(20);
recEnuQE_data_bigRng->SetMarkerSize(0.7);
recEnuQE_data_bigRng->SetLineColor(1);
recEnuQE_data_bigRng->SetMarkerColor(2);
recEnuQE_data_bigRng->SetBarWidth(4);
recEnuQE_data_bigRng->SetLineWidth(1);
recTmu_data->SetFillStyle(0);
recTmu_data->SetMarkerStyle(20);
recTmu_data->SetMarkerSize(0.7);
recTmu_data->SetLineColor(1);
recTmu_data->SetMarkerColor(2);
recTmu_data->SetBarWidth(4);
recTmu_data->SetLineWidth(1);

recUX_data->SetFillStyle(0);
recUX_data->SetMarkerStyle(20);
recUX_data->SetMarkerSize(0.7);
recUX_data->SetLineColor(1);
recUX_data->SetMarkerColor(2);
recUX_data->SetBarWidth(4);
recUX_data->SetLineWidth(1);

thetaX_data->SetFillStyle(0);
thetaX_data->SetMarkerStyle(20);
thetaX_data->SetMarkerSize(0.7);
thetaX_data->SetLineColor(1);
thetaX_data->SetMarkerColor(2);
thetaX_data->SetBarWidth(4);
thetaX_data->SetLineWidth(1);

thetaY_data->SetFillStyle(0);
thetaY_data->SetMarkerStyle(20);
thetaY_data->SetMarkerSize(0.7);
thetaY_data->SetLineColor(1);
thetaY_data->SetMarkerColor(2);
thetaY_data->SetBarWidth(4);
thetaY_data->SetLineWidth(1);

thetaZ_data->SetFillStyle(0);
thetaZ_data->SetMarkerStyle(20);
thetaZ_data->SetMarkerSize(0.7);
thetaZ_data->SetLineColor(1);
thetaZ_data->SetMarkerColor(2);
thetaZ_data->SetBarWidth(4);
thetaZ_data->SetLineWidth(1);

recUY_data->SetFillStyle(0);
recUY_data->SetMarkerStyle(20);
recUY_data->SetMarkerSize(0.7);
recUY_data->SetLineColor(1);
recUY_data->SetMarkerColor(2);
recUY_data->SetBarWidth(4);
recUY_data->SetLineWidth(1);

recUZ_data->SetFillStyle(0);
recUZ_data->SetMarkerStyle(20);
recUZ_data->SetMarkerSize(0.7);
recUZ_data->SetLineColor(1);
recUZ_data->SetMarkerColor(2);
recUZ_data->SetBarWidth(4);
recUZ_data->SetLineWidth(1);

tHit1_data_timeBin_0->SetFillStyle(0);
tHit1_data_timeBin_0->SetMarkerStyle(20);
tHit1_data_timeBin_0->SetMarkerSize(0.9);
tHit1_data_timeBin_0->SetLineColor(1);
tHit1_data_timeBin_0->SetMarkerColor(1);
tHit1_data_timeBin_0->SetBarWidth(4);
tHit1_data_timeBin_0->SetLineWidth(1);

tHit1_data_timeBin_1->SetFillStyle(0);
tHit1_data_timeBin_1->SetMarkerStyle(21);
tHit1_data_timeBin_1->SetMarkerSize(0.9);
tHit1_data_timeBin_1->SetLineColor(kRed);
tHit1_data_timeBin_1->SetMarkerColor(kRed);
tHit1_data_timeBin_1->SetBarWidth(4);
tHit1_data_timeBin_1->SetLineWidth(1);

tHit1_data_timeBin_2->SetFillStyle(0);
tHit1_data_timeBin_2->SetMarkerStyle(22);
tHit1_data_timeBin_2->SetMarkerSize(0.9);
tHit1_data_timeBin_2->SetLineColor(kBlue);
tHit1_data_timeBin_2->SetMarkerColor(kBlue);
tHit1_data_timeBin_2->SetBarWidth(4);
tHit1_data_timeBin_2->SetLineWidth(1);

tHit1_data_timeBin_3->SetFillStyle(0);
tHit1_data_timeBin_3->SetMarkerStyle(23);
tHit1_data_timeBin_3->SetMarkerSize(0.9);
tHit1_data_timeBin_3->SetLineColor(kMagenta);
tHit1_data_timeBin_3->SetMarkerColor(kMagenta);
tHit1_data_timeBin_3->SetBarWidth(4);
tHit1_data_timeBin_3->SetLineWidth(1);

tHit1_data_timeBin_4->SetFillStyle(0);
tHit1_data_timeBin_4->SetMarkerStyle(24);
tHit1_data_timeBin_4->SetMarkerSize(0.9);
tHit1_data_timeBin_4->SetLineColor(95);
tHit1_data_timeBin_4->SetMarkerColor(95);
tHit1_data_timeBin_4->SetBarWidth(4);
tHit1_data_timeBin_4->SetLineWidth(1);

tHit1_data_timeBin_5->SetFillStyle(0);
tHit1_data_timeBin_5->SetMarkerStyle(25);
tHit1_data_timeBin_5->SetMarkerSize(0.9);
tHit1_data_timeBin_5->SetLineColor(28);
tHit1_data_timeBin_5->SetMarkerColor(28);
tHit1_data_timeBin_5->SetBarWidth(4);
tHit1_data_timeBin_5->SetLineWidth(1);

/*
cout<<"2.5"<<endl;

for (int i=0; i<6; i++){
  cout<<" before i is "<<i<<endl;
  //tHit1_data_timeBins[i]->SetFillStyle(0);
  cout<<" 2 "<<endl;
  tHit1_data_timeBins[i]->SetMarkerSize(0.7);
  cout<<" 3 "<<endl;
  tHit1_data_timeBins[i]->SetBarWidth(4);
  cout<<" 4 "<<endl;
  tHit1_data_timeBins[i]->SetLineWidth(1);
  cout<<" 5 "<<endl;
}

cout<<"3"<<endl;

tHit1_data_timeBins[0]->SetMarkerStyle(20);
tHit1_data_timeBins[0]->SetMarkerColor(kRed);
tHit1_data_timeBins[0]->SetLineColor(kRed);

tHit1_data_timeBins[1]->SetMarkerStyle(21);
tHit1_data_timeBins[1]->SetMarkerColor(kBlue);
tHit1_data_timeBins[1]->SetLineColor(kBlue);

tHit1_data_timeBins[2]->SetMarkerStyle(22);
tHit1_data_timeBins[2]->SetMarkerColor(kGreen);
tHit1_data_timeBins[2]->SetLineColor(kGreen);

tHit1_data_timeBins[3]->SetMarkerStyle(23);
tHit1_data_timeBins[3]->SetMarkerColor(95);
tHit1_data_timeBins[3]->SetLineColor(95);

tHit1_data_timeBins[4]->SetMarkerStyle(24);
tHit1_data_timeBins[4]->SetMarkerColor(kMagenta);
tHit1_data_timeBins[4]->SetLineColor(kMagenta);

tHit1_data_timeBins[5]->SetMarkerStyle(25);
tHit1_data_timeBins[5]->SetMarkerColor(28);
tHit1_data_timeBins[5]->SetLineColor(28);

*/

lk_piP->Scale(scaleFactor);
lk_kP->Scale(scaleFactor);
lk_tot->Scale(scaleFactor);
lk_tot_2se->Scale(scaleFactor);
lk_sig->Scale(scaleFactor);
tDiff_tot->Scale(scaleFactor);

recEnuQE_tot->Scale(scaleFactor);
recEnuQE_kP->Scale(scaleFactor);
recEnuQE_piP->Scale(scaleFactor);
sig_recEnuQE->Scale(scaleFactor);
recEnuQE_tot_bigRng->Scale(scaleFactor);
recEnuQE_kP_bigRng->Scale(scaleFactor);
recEnuQE_piP_bigRng->Scale(scaleFactor);

tHit1_piP->Scale(scaleFactor);
tHit1_piPbig->Scale(scaleFactor);
tHit1_kP->Scale(scaleFactor);
tHit1_kPbig->Scale(scaleFactor);
tHit1_tot->Scale(scaleFactor);
tHit1_noCut->Scale(scaleFactor);
tHit1_totBig->Scale(scaleFactor);
tHit1_tot_nokdar->Scale(scaleFactor);
sig_tHit1->Scale(scaleFactor);
sig_tHit1big->Scale(scaleFactor);

recTmu_tot->Scale(scaleFactor);
recTmu_tot_nokdar->Scale(scaleFactor);
recTmu_sig->Scale(scaleFactor);
recTmu_kP->Scale(scaleFactor);
recTmu_piP->Scale(scaleFactor);

recUX_piP->Scale(scaleFactor);
recUX_kP->Scale(scaleFactor);
recUX_tot->Scale(scaleFactor);
recUY_piP->Scale(scaleFactor);
recUY_kP->Scale(scaleFactor);
recUY_tot->Scale(scaleFactor);
recUZ_piP->Scale(scaleFactor);
recUZ_kP->Scale(scaleFactor);
recUZ_tot->Scale(scaleFactor);
sig_recUX->Scale(scaleFactor);
sig_recUY->Scale(scaleFactor);
sig_recUZ->Scale(scaleFactor);

thetaX_piP->Scale(scaleFactor);
thetaX_kP->Scale(scaleFactor);
thetaX_tot->Scale(scaleFactor);
thetaY_piP->Scale(scaleFactor);
thetaY_kP->Scale(scaleFactor);
thetaY_tot->Scale(scaleFactor);
thetaZ_piP->Scale(scaleFactor);
thetaZ_kP->Scale(scaleFactor);
thetaZ_tot->Scale(scaleFactor);
sig_thetaX->Scale(scaleFactor);
sig_thetaY->Scale(scaleFactor);
sig_thetaZ->Scale(scaleFactor);

//for (int i=0; i<6; i++) tHit1_data_timeBins[i]->Scale(1/tHit1_data_timeBins[i]->Integral());

truEnu_tot->SetLineWidth(2);
truEnu_pM->SetLineWidth(2);
truEnu_kP->SetLineWidth(2);
truEnu_sig->SetLineWidth(2);
truEnu_sig->SetLineColor(kGreen);
truEnu_kL->SetLineWidth(2);
truEnu_piP->SetLineWidth(2);
truTmu_piP->SetLineWidth(2);
truTmu_kP->SetLineWidth(2);
recTmu_piP->SetLineWidth(2);
recTmu_kP->SetLineWidth(2);
truTmu_tot->SetLineWidth(2);
truEnuQE_piP->SetLineWidth(2);
truEnuQE_kP->SetLineWidth(2);
truEnuQE_tot->SetLineWidth(2);
recEnuQE_piP->SetLineWidth(2);
recEnuQE_kP->SetLineWidth(2);
recEnuQE_tot->SetLineWidth(2);
recEnuQE_piP_bigRng->SetLineWidth(2);
recEnuQE_kP_bigRng->SetLineWidth(2);
recEnuQE_tot_bigRng->SetLineWidth(2);
truUZ_piP->SetLineWidth(2);
truUZ_kP->SetLineWidth(2);
truUZ_tot->SetLineWidth(2);
truUY_piP->SetLineWidth(2);
truUY_kP->SetLineWidth(2);
truUY_tot->SetLineWidth(2);

recTmu_kP->SetLineColor(kBlue);
recTmu_piP->SetLineColor(kMagenta);

recUZ_piP->SetLineWidth(2);
recUZ_kP->SetLineWidth(2);
recUZ_tot->SetLineWidth(2);
recUY_piP->SetLineWidth(2);
recUY_kP->SetLineWidth(2);
recUY_tot->SetLineWidth(2);

thetaZ_piP->SetLineWidth(2);
thetaZ_kP->SetLineWidth(2);
thetaZ_tot->SetLineWidth(2);
thetaY_piP->SetLineWidth(2);
thetaY_kP->SetLineWidth(2);
thetaY_tot->SetLineWidth(2);

recTmu_tot_nokdar->SetLineWidth(2);
recTmu_tot_nokdar->SetLineColor(1);

tHit1_piP->SetLineWidth(2);
tHit1_piPbig->SetLineWidth(2);
tHit1_kP->SetLineWidth(2);
tHit1_kPbig->SetLineWidth(2);
tHit1_totBig->SetLineWidth(2);
tHit1_tot_nokdar->SetLineWidth(2);
tHit1_tot_nokdar->SetLineStyle(1);
truUX_piP->SetLineWidth(2);
truUX_kP->SetLineWidth(2);
truUX_tot->SetLineWidth(2);
recUX_piP->SetLineWidth(2);
recUX_kP->SetLineWidth(2);
recUX_tot->SetLineWidth(2);
thetaX_piP->SetLineWidth(2);
thetaX_kP->SetLineWidth(2);
thetaX_tot->SetLineWidth(2);
sig_truTmu->SetLineWidth(2);
sig_truUZ->SetLineWidth(2);
sig_truUY->SetLineWidth(2);
sig_truUX->SetLineWidth(2);
sig_recUZ->SetLineWidth(2);
sig_recUY->SetLineWidth(2);
sig_recUX->SetLineWidth(2);

sig_thetaZ->SetLineWidth(2);
sig_thetaY->SetLineWidth(2);
sig_thetaX->SetLineWidth(2);

sig_truEnuQE->SetLineWidth(2);
sig_tHit1->SetLineWidth(2);
sig_tHit1big->SetLineWidth(2);
sig_nuBirthX->SetLineWidth(2);
sig_nuBirthY->SetLineWidth(2);
sig_nuBirthZ->SetLineWidth(2);
px_fin_piP->SetLineWidth(2);
py_fin_piP->SetLineWidth(2);
pz_fin_piP->SetLineWidth(2);
px_fin_kP->SetLineWidth(2);
py_fin_kP->SetLineWidth(2);
pz_fin_kP->SetLineWidth(2);
px_fin_tot->SetLineWidth(2);
py_fin_tot->SetLineWidth(2);
pz_fin_tot->SetLineWidth(2);
prBirthPX->SetLineWidth(2);
prBirthPY->SetLineWidth(2);
prBirthPZ->SetLineWidth(2);
kpBirthPX->SetLineWidth(2);
kpBirthPY->SetLineWidth(2);
kpBirthPZ->SetLineWidth(2);
pipBirthPX->SetLineWidth(2);
pipBirthPY->SetLineWidth(2);
pipBirthPZ->SetLineWidth(2);

sig_truUX->SetLineColor(kGreen);
sig_truUZ->SetLineColor(kGreen);
sig_truUY->SetLineColor(kGreen);
sig_recUX->SetLineColor(kGreen);
sig_recUZ->SetLineColor(kGreen);
sig_recUY->SetLineColor(kGreen);

sig_thetaX->SetLineColor(kGreen);
sig_thetaZ->SetLineColor(kGreen);
sig_thetaY->SetLineColor(kGreen);

sig_truTmu->SetLineColor(kGreen);
sig_truEnuQE->SetLineColor(kGreen);
sig_recEnuQE->SetLineColor(kGreen);
sig_recEnuQE->SetLineWidth(2);
sig_tHit1->SetLineColor(kGreen);
sig_tHit1big->SetLineColor(kGreen);

cout<<"\n signal integrals: \n\n"<<endl;
cout<<" ux "<<sig_truUX->Integral()<<endl;
cout<<" tmu "<<sig_truTmu->Integral()<<endl;
cout<<" enuqe "<<sig_truEnuQE->Integral()<<endl;

kpBirthPX->SetLineColor(kBlue);
kpBirthPY->SetLineColor(kBlue);
kpBirthPZ->SetLineColor(kBlue);
pipBirthPX->SetLineColor(kMagenta);
pipBirthPY->SetLineColor(kMagenta);
pipBirthPZ->SetLineColor(kMagenta);
px_fin_piP->SetLineColor(kMagenta);
py_fin_piP->SetLineColor(kMagenta);
pz_fin_piP->SetLineColor(kMagenta);
px_fin_kP->SetLineColor(kBlue);
py_fin_kP->SetLineColor(kBlue);
pz_fin_kP->SetLineColor(kBlue);
tHit1_kP->SetLineColor(kBlue);
tHit1_kPbig->SetLineColor(kBlue);
tHit1_piP->SetLineColor(kMagenta);
tHit1_piPbig->SetLineColor(kMagenta);
truUZ_kP->SetLineColor(kBlue);
truUZ_piP->SetLineColor(kMagenta);
truUX_kP->SetLineColor(kBlue);
truUX_piP->SetLineColor(kMagenta);
truUY_kP->SetLineColor(kBlue);
truUY_piP->SetLineColor(kMagenta);

recUZ_kP->SetLineColor(kBlue);
recUZ_piP->SetLineColor(kMagenta);
recUX_kP->SetLineColor(kBlue);
recUX_piP->SetLineColor(kMagenta);
recUY_kP->SetLineColor(kBlue);
recUY_piP->SetLineColor(kMagenta);

thetaZ_kP->SetLineColor(kBlue);
thetaZ_piP->SetLineColor(kMagenta);
thetaX_kP->SetLineColor(kBlue);
thetaX_piP->SetLineColor(kMagenta);
thetaY_kP->SetLineColor(kBlue);
thetaY_piP->SetLineColor(kMagenta);

truEnuQE_kP->SetLineColor(kBlue);
truEnuQE_piP->SetLineColor(kMagenta);
recEnuQE_kP->SetLineColor(kBlue);
recEnuQE_piP->SetLineColor(kMagenta);

recEnuQE_kP_bigRng->SetLineColor(kBlue);
recEnuQE_piP_bigRng->SetLineColor(kMagenta);

truEnu_kL->SetLineColor(kRed);
truEnu_kP->SetLineColor(kBlue);
truEnu_pM->SetLineColor(95);
truTmu_kP->SetLineColor(kBlue);
truEnu_piP->SetLineColor(kMagenta);
truTmu_piP->SetLineColor(kMagenta);

gROOT->SetStyle("Plain");
gStyle->SetOptStat(1);
gStyle->SetPalette(1);

//truEnu_piP->SetMaximum(truEnu_kP->GetMaximum()*1.1);

truEnu_tot->GetXaxis()->SetTitle("Gen. E_{#nu} (GeV)");
truEnu_tot->GetXaxis()->CenterTitle(1);

truEnu_tot->GetYaxis()->SetTitle("Detector event rate (no cuts)");
truEnu_tot->GetYaxis()->CenterTitle(1);

truEnu_tot->SetMinimum(10);

TCanvas *parentC = new TCanvas();
parentC->SetLogy();
truEnu_tot->Draw();
truEnu_piP->Draw("same");
truEnu_kP->Draw("same");
truEnu_pM->Draw("same");
truEnu_kL->Draw("same");
truEnu_sig->Draw("same");
parentC->Print("truEnu.eps");

TCanvas *parentC2 = new TCanvas();
truEnu_tot->Draw();
truEnu_piP->Draw("same");
truEnu_kP->Draw("same");
truEnu_pM->Draw("same");
truEnu_kL->Draw("same");
truEnu_sig->Draw("same");
parentC2->Print("truEnuLin.eps");

new TCanvas();
pipEnThit->Draw("colz");

new TCanvas();
pipEnuThit->Draw("colz");

new TCanvas();
pipEnu->Draw();

new TCanvas();
truEnu_pM->Draw();

truEnuQE_tot->GetXaxis()->SetTitle("Gen. E_{#nu}^{QE} (GeV)");
truEnuQE_tot->GetXaxis()->CenterTitle(1);
truEnuQE_tot->SetMinimum(1);

TCanvas *enuqeC = new TCanvas();
//enuqeC->SetLogy();
truEnuQE_tot->Draw();
truEnuQE_piP->Draw("same");
truEnuQE_kP->Draw("same");
sig_truEnuQE->Draw("same");
enuqeC->Print("truEnuQE.eps");

recEnuQE_tot->GetXaxis()->SetTitle("E_{#nu}^{QE} (GeV)");
recEnuQE_tot->GetXaxis()->CenterTitle(1);

cout<<" xfactor from enuqe is "<<recEnuQE_data->Integral()/recEnuQE_tot->Integral()<<endl;

recEnuQE_tot->SetTitle("Assumes BNB #nu direction.  Tank hits > 60 && < 120");
recEnuQE_tot->SetMaximum(recEnuQE_data->GetMaximum()*1.15);

TCanvas *enuqeC2 = new TCanvas();
//enuqeC->SetLogy();
recEnuQE_tot->Draw();
recEnuQE_piP->Draw("same");
recEnuQE_kP->Draw("same");
sig_recEnuQE->Draw("same");
recEnuQE_data->Draw("ep same");
enuqeC2->Print("recEnuQE.eps");

recEnuQE_tot_bigRng->GetXaxis()->SetTitle("E_{#nu}^{QE} (GeV)");
recEnuQE_tot_bigRng->GetXaxis()->CenterTitle(1);

TCanvas *enuqeC3 = new TCanvas();
//enuqeC->SetLogy();
recEnuQE_tot_bigRng->Draw();
recEnuQE_piP_bigRng->Draw("same");
recEnuQE_kP_bigRng->Draw("same");
recEnuQE_data_bigRng->Draw("ep same");
enuqeC3->Print("recEnuQE_bigRng.eps");

cout<<" mc int "<<recEnuQE_tot->Integral()<<" data "<<recEnuQE_data->Integral()<<" x-factor "<<recEnuQE_data->Integral()/recEnuQE_tot->Integral()<<endl;

tHit1_tot->Add(tHit1_strobe);

if (tHit1_tot->GetMaximum() < tHit1_data->GetMaximum()) tHit1_tot->SetMaximum(tHit1_data->GetMaximum()*1.1);

tHit1_tot->GetXaxis()->SetTitle("tank hits");
tHit1_tot->GetXaxis()->CenterTitle(1);
tHit1_tot->SetLineWidth(2);

//tHit1_tot->SetMaximum(tHit1_data->GetMaximum()*1.15);

cout<<"\n\n\n kdar purity from tank hits "<<sig_tHit1->Integral()/tHit1_tot->Integral()<<"\n\n\n"<<endl;

TCanvas *thitC = new TCanvas();
tHit1_tot->Draw();
tHit1_piP->Draw("same");
tHit1_strobe->Draw("same");
tHit1_kP->Draw("same");
sig_tHit1->Draw("same");
tHit1_data->Draw("ep same");
thitC->Print("tHit1.eps");

tHit1_tot->Scale(tHit1_data->Integral()/tHit1_tot->Integral());

TCanvas *thitC22 = new TCanvas();
tHit1_tot->Draw();
tHit1_data->Draw("ep same");
thitC22->Print("tHit1_norm.eps");

//return;

//tHit1_cuts_mc_5->SetLineColor(kRed);

TCanvas *thitC4 = new TCanvas();
tHit1_tot->Draw();
tHit1_cuts_mc_5->Draw("same");
thitC4->Print("tHitEffChk.eps");

TCanvas *thitCv = new TCanvas();
tHit1_totBig->Draw();
tHit1_piPbig->Draw("same");
tHit1_kPbig->Draw("same");
sig_tHit1big->Draw("same");
tHit1_dataBig->Draw("ep same");
thitCv->Print("tHit1big.eps");

tHit1_tot_nokdar->SetLineColor(kBlue);

TCanvas *thitC2 = new TCanvas();
tHit1_tot->Draw();
tHit1_tot_nokdar->Draw("same");
tHit1_data->Draw("ep same");
thitC2->Print("tHit1_w_wout.eps");

recTmu_tot->GetXaxis()->SetTitle("rec T_{#mu} (GeV)");
recTmu_tot->GetXaxis()->CenterTitle(1);

recTmu_tot->SetLineWidth(2);
recTmu_sig->SetLineColor(kGreen);
recTmu_sig->SetLineWidth(2);

recTmu_tot->Add(recTmu_strobe);
if (recTmu_tot->GetMaximum() < recTmu_data->GetMaximum()) recTmu_tot->SetMaximum(recTmu_data->GetMaximum()*1.15);

recTmu_tot->SetMaximum(500);

TCanvas *tmuz = new TCanvas();
recTmu_tot->Draw();
recTmu_sig->Draw("same");
recTmu_kP->Draw("same");
recTmu_piP->Draw("same");
recTmu_strobe->Draw("same");
recTmu_data->Draw("e1 p same");
tmuz->Print("rectmu.eps");

recTmu_tot_nokdar->SetLineColor(kBlue);

TCanvas *tmuz2 = new TCanvas();
recTmu_tot->Draw();
recTmu_tot_nokdar->Draw("same");
recTmu_data->Draw("e1 p same");
tmuz2->Print("rectmu_w_wout.eps");

recUZ_tot->GetXaxis()->SetTitle("Gen. UZ");
recUZ_tot->GetXaxis()->CenterTitle(1);
//recUZ_tot->SetMinimum(1);

recUZ_tot->GetXaxis()->SetTitle("reco UZ");
recUY_tot->GetXaxis()->SetTitle("reco UY");
recUX_tot->GetXaxis()->SetTitle("reco UX");

recUZ_tot->SetMinimum(0);

recUX_tot->SetMinimum(0);
recUX_tot->SetMaximum(recUX_data->GetMaximum()*1.15);

recUY_tot->SetMinimum(0);
recUY_tot->SetMaximum(recUY_data->GetMaximum()*1.15);

recUZ_tot->SetMinimum(0);
recUZ_tot->SetMaximum(recUZ_data->GetMaximum()*1.15);

TCanvas *uzC2 = new TCanvas();
//uzC->SetLogy();
recUZ_tot->Draw();
recUZ_piP->Draw("same");
recUZ_kP->Draw("same");
sig_recUZ->Draw("same");
recUZ_data->Draw("e1 p same");
uzC2->Print("recUZ.eps");

thetaZ_tot->GetXaxis()->SetTitle("#theta_{Z} (rad)");
thetaZ_tot->GetXaxis()->CenterTitle(1);

thetaY_tot->SetMaximum(thetaY_data->GetMaximum()*1.15);
thetaZ_tot->SetMaximum(thetaZ_data->GetMaximum()*1.15);

TCanvas *uzC3 = new TCanvas();
//uzC->SetLogy();
thetaZ_tot->Draw();
thetaZ_piP->Draw("same");
thetaZ_kP->Draw("same");
sig_thetaZ->Draw("same");
thetaZ_data->Draw("e1 p same");
uzC3->Print("thetaZ.eps");

thetaY_tot->GetXaxis()->SetTitle("#theta_{Y} (rad)");
thetaY_tot->GetXaxis()->CenterTitle(1);

TCanvas *uzC4 = new TCanvas();
//uzC->SetLogy();
thetaY_tot->Draw();
thetaY_piP->Draw("same");
thetaY_kP->Draw("same");
sig_thetaY->Draw("same");
thetaY_data->Draw("e1 p same");
uzC4->Print("thetaY.eps");

thetaX_tot->GetXaxis()->SetTitle("#theta_{X} (rad)");
thetaX_tot->GetXaxis()->CenterTitle(1);
thetaX_tot->SetMinimum(0);
thetaY_tot->SetMinimum(0);
thetaZ_tot->SetMinimum(0);
thetaX_tot->SetMaximum(thetaX_data->GetMaximum()*1.15);

TCanvas *uzC5 = new TCanvas();
//uzC->SetLogy();
thetaX_tot->Draw();
thetaX_piP->Draw("same");
thetaX_kP->Draw("same");
sig_thetaX->Draw("same");
thetaX_data->Draw("e1 p same");
uzC5->Print("thetaX.eps");

TCanvas *thetaXYdata = new TCanvas();
thetaXY_data->Draw("colz");
thetaXYdata->Print("thetaXY_data.eps");

TCanvas *thetaXYmc = new TCanvas();
thetaXY_tot->Draw("colz");
thetaXYmc->Print("thetaXY_mc.eps");

TCanvas *thetaXZdata = new TCanvas();
thetaXZ_data->Draw("colz");
thetaXZdata->Print("thetaXZ_data.eps");

TCanvas *thetaXZmc = new TCanvas();
thetaXZ_tot->Draw("colz");
thetaXZmc->Print("thetaXZ_mc.eps");

TCanvas *thetaYZdata = new TCanvas();
thetaYZ_data->Draw("colz");
thetaYZdata->Print("thetaYZ_data.eps");

TCanvas *thetaYZmc = new TCanvas();
thetaYZ_tot->Draw("colz");
thetaYZmc->Print("thetaYZ_mc.eps");


recUY_tot->SetMinimum(0);

TCanvas *uyC2 = new TCanvas();
//uzC->SetLogy();
recUY_tot->Draw();
recUY_piP->Draw("same");
recUY_kP->Draw("same");
sig_recUY->Draw("same");
recUY_strobe->Draw("same");
recUY_data->Draw("e1 p same");
uyC2->Print("recUY.eps");

recUY_strobe->SetLineWidth(2);
recUY_strobe->SetLineColor(95);

recUY_strobe->GetXaxis()->SetTitle("UY");
recUY_strobe->GetXaxis()->CenterTitle(1);

TCanvas *strUY = new TCanvas();
recUY_strobe->Draw();
recUY_data->Draw("e1p same");
strUY->Print("uyComp.eps");

cout<<" \n\n data int "<<recUY_data->Integral()<<" strobe int "<<recUY_strobe->Integral()<<" ratio "<<recUY_data->Integral()/recUY_strobe->Integral()<<"\n\n"<<endl;

TCanvas *uxC2 = new TCanvas();
//uzC->SetLogy();
recUX_tot->Draw();
recUX_piP->Draw("same");
recUX_kP->Draw("same");
sig_recUX->Draw("same");
recUX_data->Draw("e1 p same");
uxC2->Print("recUX.eps");

lk_tot->Add(lk_strobe);

lk_tot->SetMaximum(lk_data->GetMaximum()*1.2);

TCanvas *lkP = new TCanvas();
lk_tot->Draw();
lk_piP->Draw("same");
lk_kP->Draw("same");
lk_sig->Draw("same");
lk_strobe->Draw("same");
lk_data->Draw("e1p same");
lkP->Print("deltaLk.eps");

TCanvas *rngC = new TCanvas();
rngC->Divide(2,3);

TLatex *b = new TLatex();
b->SetNDC();
b->SetTextSize(0.1);

TString txt[nTmuBins];
txt[0] = "T_{#mu} < 50 MeV";
txt[1] = "50 < T_{#mu} (MeV) < 100";
txt[2] = "100 < T_{#mu} (MeV) < 150";
txt[3] = "150 < T_{#mu} (MeV) < 200";
txt[4] = "200 < T_{#mu} (MeV) < 250";
txt[5] = "250 < T_{#mu} (MeV) < 300";

gStyle->SetOptStat(0000);

for (int i=0; i<nTmuBins-1; i++){

  AdjRngTmuBns_tot[i]->SetMaximum(AdjRngTmuBns_data[i]->GetMaximum()*1.35);
  AdjRngTmuBns_tot[i]->GetXaxis()->SetLabelSize(0.08);
  AdjRngTmuBns_tot[i]->GetYaxis()->SetLabelSize(0.08);

  rngC->cd(i+1);
  AdjRngTmuBns_tot[i]->Draw();
  AdjRngTmuBns_piP[i]->Draw("same");
  AdjRngTmuBns_kP[i]->Draw("same");
  AdjRngTmuBns_sig[i]->Draw("same");
  AdjRngTmuBns_data[i]->Draw("e1 p same");
  b->DrawLatex(0.48,0.8,txt[i]);

}

rngC->Print("range.eps");

truTmu_tot->GetXaxis()->SetTitle("Gen. T_{#mu} (GeV)");
truTmu_tot->GetXaxis()->CenterTitle(1);
truTmu_tot->SetMinimum(1);

TCanvas *tmuC = new TCanvas();
//tmuC->SetLogy();
truTmu_tot->Draw();
truTmu_piP->Draw("same");
truTmu_kP->Draw("same");
sig_truTmu->Draw("same");
tmuC->Print("truTmu.eps");

truUZ_tot->GetXaxis()->SetTitle("Gen. UZ");
truUZ_tot->GetXaxis()->CenterTitle(1);
truUZ_tot->SetMinimum(1);

TCanvas *uzC = new TCanvas();
//uzC->SetLogy();
truUZ_tot->Draw();
truUZ_piP->Draw("same");
truUZ_kP->Draw("same");
sig_truUZ->Draw("same");
uzC->Print("truUZ.eps");

truUY_tot->GetXaxis()->SetTitle("Gen. UY");
truUY_tot->GetXaxis()->CenterTitle(1);
truUY_tot->SetMinimum(1);

TCanvas *uyC = new TCanvas();
//uyC->SetLogy();
truUY_tot->Draw();
truUY_piP->Draw("same");
truUY_kP->Draw("same");
sig_truUY->Draw("same");
uyC->Print("truUY.eps");

//time_tot->Scale(time_data->Integral()/time_tot->Integral());
time_tot->GetXaxis()->SetTitle("ave hit time (ns)");
time_tot->GetXaxis()->CenterTitle(1);

time_data->GetXaxis()->SetTitle("ave hit time (ns)");
time_data->GetXaxis()->CenterTitle(1);

time_strobe->SetLineWidth(2);
time_strobe->SetLineColor(95);

time_tot->SetMaximum(time_data->GetMaximum()*1.15);

TCanvas *timeC = new TCanvas();
//time_tot->Draw("");
time_data->Draw("e1 p");
time_strobe->Draw("same");
timeC->Print("timeCompAbs.eps");
timeC->SetLogy();
timeC->Print("timeCompAbs_log.eps");

/*
TCanvas *tStab = new TCanvas();
tHit1_tot->Draw();
for (int i=0; i<6; i++)
  tHit1_data_timeBins[i]->Draw("e1p same");
tStab->Print("tStab.eps");

tHit1_data_timeBin_0->Scale(1/tHit1_data_timeBin_0->Integral());
tHit1_data_timeBin_1->Scale(1/tHit1_data_timeBin_1->Integral());
tHit1_data_timeBin_2->Scale(1/tHit1_data_timeBin_2->Integral());
tHit1_data_timeBin_3->Scale(1/tHit1_data_timeBin_3->Integral());
tHit1_data_timeBin_4->Scale(1/tHit1_data_timeBin_4->Integral());
tHit1_data_timeBin_5->Scale(1/tHit1_data_timeBin_5->Integral());
cout<<" 0 int "<<tHit1_data_timeBin_0->Integral()<<endl;
cout<<" 1 int "<<tHit1_data_timeBin_1->Integral()<<endl;
cout<<" 2 int "<<tHit1_data_timeBin_2->Integral()<<endl;
cout<<" 3 int "<<tHit1_data_timeBin_3->Integral()<<endl;
cout<<" 4 int "<<tHit1_data_timeBin_4->Integral()<<endl;
cout<<" 5 int "<<tHit1_data_timeBin_5->Integral()<<endl;

//tHit1_tot->Scale(1/tHit1_tot->Integral());

tHit1_data_timeBin_1->SetMaximum(0.10);
tHit1_data_timeBin_1->GetXaxis()->SetTitle("tank hits");
tHit1_data_timeBin_1->GetXaxis()->CenterTitle(1);

tHit1_data_timeBin_1->GetYaxis()->SetTitle("arbitrary");
tHit1_data_timeBin_1->GetYaxis()->CenterTitle(1);
tHit1_data_timeBin_1->SetTitle("scaled to unit area");

TLegend *leg22 = new TLegend(0.8, 0.769, 0.999, 0.996);
leg22->AddEntry(tHit1_data_timeBin_0,"1.3 < t (#us) <= 2.9", "lp");
leg22->AddEntry(tHit1_data_timeBin_1,"2.9 < t (#us) <= 4.6", "lp");
leg22->AddEntry(tHit1_data_timeBin_2,"4.6 < t (#us) <= 6.2", "lp");
leg22->AddEntry(tHit1_data_timeBin_3,"6.2 < t (#us) <= 7.8", "lp");
leg22->AddEntry(tHit1_data_timeBin_4,"7.8 < t (#us) <= 9.5", "lp");
leg22->AddEntry(tHit1_data_timeBin_5,"9.5 < t (#us) <= 11.2", "lp");
leg22->SetFillColor(0);
leg22->SetLineColor(1);
leg22->SetTextSize(0.03);


TCanvas *tStab = new TCanvas();
tHit1_data_timeBin_1->Draw("e1p");
tHit1_data_timeBin_0->Draw("e1p same");
tHit1_data_timeBin_2->Draw("e1p same");
tHit1_data_timeBin_3->Draw("e1p same");
tHit1_data_timeBin_4->Draw("e1p same");
tHit1_data_timeBin_5->Draw("e1p same");
tStab->Print("tStab.eps");
leg22->Draw();
tStab->Print("tStab_wLeg.eps");

*/

gStyle->SetOptStat(1);

tHit2_data_firstBump->SetTitle("2nd SE, 1st SE tank hits < 60");
tHit2_data_secondBump->SetTitle("2nd SE, 1st SE tank hits > 60 && < 120");

tHit2_data_firstBump->GetXaxis()->SetTitle("tank hits");
tHit2_data_firstBump->GetXaxis()->CenterTitle(1);

tHit2_data_secondBump->GetXaxis()->SetTitle("tank hits");
tHit2_data_secondBump->GetXaxis()->CenterTitle(1);

TCanvas *secondSEcheck1 = new TCanvas();
tHit2_data_firstBump->Draw("e1p");
tHit2_mc_firstBump->Draw("same");
secondSEcheck1->Print("firstBump2ndSE.eps");

TCanvas *secondSEcheck2 = new TCanvas();
tHit2_data_secondBump->Draw("e1p");
tHit2_mc_secondBump->Draw("same");
secondSEcheck2->Print("secondBump2ndSE.eps");

tDiff_tot->SetMaximum(tDiff_data->GetMaximum()*1.15);
tDiff_tot->GetXaxis()->SetTitle("SE time difference (ns)");
tDiff_tot->GetXaxis()->CenterTitle(1);
tDiff_tot->SetLineWidth(2);

TCanvas *timeC2 = new TCanvas();
tDiff_tot->Draw("");
tDiff_data->Draw("e1 p same");
timeC2->Print("timeComp.eps");

tHit1_eff->Divide(tHit1_tot,tHit1_noCut);

tHit1_eff->SetLineWidth(2);
tHit1_eff->GetXaxis()->SetTitle("tank hits");
tHit1_eff->GetXaxis()->CenterTitle(1);

tHit1_eff->GetYaxis()->SetTitle("efficiency");
tHit1_eff->GetYaxis()->CenterTitle(1);

TCanvas *thiteff = new TCanvas();
tHit1_eff->Draw();
thiteff->Print("tankHitEff.eps");

TCanvas *thiteff2 = new TCanvas();
tHit1_noCut->Draw();
thiteff2->Print("tankHitNoCut.eps");

truUX_tot->GetXaxis()->SetTitle("Gen. UX");
truUX_tot->GetXaxis()->CenterTitle(1);
truUX_tot->SetMinimum(1);

TCanvas *uxC = new TCanvas();
//uxC->SetLogy();
truUX_tot->Draw();
truUX_piP->Draw("same");
truUX_kP->Draw("same");
sig_truUX->Draw("same");
uxC->Print("truUX.eps");

truThetaX_sig->GetXaxis()->SetTitle("true #theta_{x} (rad)");
truThetaY_sig->GetXaxis()->SetTitle("true #theta_{y} (rad)");
truThetaZ_sig->GetXaxis()->SetTitle("true #theta_{z} (rad)");

TCanvas *truThX = new TCanvas();
truThetaX_sig->Draw();
truThX->Print("truThX.eps");

TCanvas *truThY = new TCanvas();
truThetaY_sig->Draw();
truThX->Print("truThY.eps");

TCanvas *truThZ = new TCanvas();
truThetaZ_sig->Draw();
truThX->Print("truThZ.eps");

truMinKinX_sig->GetXaxis()->SetTitle("true #theta_{x} (rad)");
truMinKinY_sig->GetXaxis()->SetTitle("true #theta_{y} (rad)");
truMinKinZ_sig->GetXaxis()->SetTitle("true #theta_{z} (rad)");
truMinKinX_sig->GetYaxis()->SetTitle("true T_{#mu} (GeV)");
truMinKinY_sig->GetYaxis()->SetTitle("true T_{#mu} (GeV)");
truMinKinZ_sig->GetYaxis()->SetTitle("true T_{#mu} (GeV)");

TCanvas *c232 = new TCanvas();
truMinKinX_sig->Draw("colz");
c232->Print("truMuKinSig_X.eps");

TCanvas *c234 = new TCanvas();
truMinKinY_sig->Draw("colz");
c234->Print("truMuKinSig_Y.eps");

TCanvas *c235 = new TCanvas();
truMinKinZ_sig->Draw("colz");
c235->Print("truMuKinSig_Z.eps");

tHit1_cuts_data_0->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_0->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_1->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_1->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_2->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_2->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_3->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_3->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_4->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_4->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_5->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_5->GetXaxis()->CenterTitle(1);
tHit1_cuts_data_6->GetXaxis()->SetTitle("tank hits");
tHit1_cuts_data_6->GetXaxis()->CenterTitle(1);
tmu_cuts_data_0->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_0->GetXaxis()->CenterTitle(1);
tmu_cuts_data_1->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_1->GetXaxis()->CenterTitle(1);
tmu_cuts_data_2->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_2->GetXaxis()->CenterTitle(1);
tmu_cuts_data_3->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_3->GetXaxis()->CenterTitle(1);
tmu_cuts_data_4->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_4->GetXaxis()->CenterTitle(1);
tmu_cuts_data_5->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_5->GetXaxis()->CenterTitle(1);
tmu_cuts_data_6->GetXaxis()->SetTitle("T_{#mu} (GeV)");
tmu_cuts_data_6->GetXaxis()->CenterTitle(1);

gStyle->SetOptStat(0000);

tHit1_cuts_data_0->SetTitle("2SE+veto hits + beam window > 4.5 #mus");
//tHit1_cuts_data_1->SetTitle("+ beam window (4 -> 6.5 #mus)");
tHit1_cuts_data_1->SetTitle("+ beam window (4.5 -> 6.5 #mus)");
tHit1_cuts_data_2->SetTitle("+ tank hits < 200 (1st SE)");
tHit1_cuts_data_3->SetTitle("+ tank hits < 200 (2nd SE)");
tHit1_cuts_data_4->SetTitle("+ reconstructed mu vertex radius < 500 cm");
tHit1_cuts_data_5->SetTitle("+ reconstructed T_{#mu} > 30 MeV");
tHit1_cuts_data_6->SetTitle("+ PID var > -0.01 && < +0.02");
//tHit1_cuts_data_6->SetTitle("+ PID var < -0.01");

tmu_cuts_data_0->SetTitle("2SE+veto hits");
tmu_cuts_data_1->SetTitle("+ beam window (4 -> 6.5 #mus)");
tmu_cuts_data_2->SetTitle("+ tank hits < 200 (1st SE)");
tmu_cuts_data_3->SetTitle("+ tank hits < 200 (2nd SE)");
tmu_cuts_data_4->SetTitle("+ reconstructed mu vertex radius < 500 cm");
tmu_cuts_data_5->SetTitle("+ reconstructed T_{#mu} > 30 MeV");
tmu_cuts_data_6->SetTitle("+ PID var > -0.01 && < +0.02");

spitzVar_cuts_data_0->SetTitle("2SE+veto hits;tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_1->SetTitle("+ beam window (4 -> 6.5 #mus);tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_2->SetTitle("+ nothing;tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_3->SetTitle("+ tank hits < 200 (2nd SE);tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_4->SetTitle("+ reconstructed mu vertex radius < 500 cm;tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_5->SetTitle("+ !=0;tHits_1SE*myStFull_fqlt10[0]/1000");
spitzVar_cuts_data_6->SetTitle("+ nothing;tHits_1SE*myStFull_fqlt10[0]/1000");

tHit1_cuts_mc_0->Add(tHit1_cuts_strobe_0);
tHit1_cuts_mc_1->Add(tHit1_cuts_strobe_1);
tHit1_cuts_mc_2->Add(tHit1_cuts_strobe_2);
tHit1_cuts_mc_3->Add(tHit1_cuts_strobe_3);
tHit1_cuts_mc_4->Add(tHit1_cuts_strobe_4);
tHit1_cuts_mc_5->Add(tHit1_cuts_strobe_5);
tHit1_cuts_mc_6->Add(tHit1_cuts_strobe_6);

spitzVar_cuts_mc_0->Add(spitzVar_cuts_strobe_0);
spitzVar_cuts_mc_1->Add(spitzVar_cuts_strobe_1);
spitzVar_cuts_mc_2->Add(spitzVar_cuts_strobe_2);
spitzVar_cuts_mc_3->Add(spitzVar_cuts_strobe_3);
spitzVar_cuts_mc_4->Add(spitzVar_cuts_strobe_4);
spitzVar_cuts_mc_5->Add(spitzVar_cuts_strobe_5);
spitzVar_cuts_mc_6->Add(spitzVar_cuts_strobe_6);

spitzVar_cuts_mc_0->Add(spitzVar_cuts_dirt_0);
spitzVar_cuts_mc_1->Add(spitzVar_cuts_dirt_1);
spitzVar_cuts_mc_2->Add(spitzVar_cuts_dirt_2);
spitzVar_cuts_mc_3->Add(spitzVar_cuts_dirt_3);
spitzVar_cuts_mc_4->Add(spitzVar_cuts_dirt_4);
spitzVar_cuts_mc_5->Add(spitzVar_cuts_dirt_5);
spitzVar_cuts_mc_6->Add(spitzVar_cuts_dirt_6);

spitzVar_cuts_mc_0->SetLineWidth(2);
spitzVar_cuts_mc_1->SetLineWidth(2);
spitzVar_cuts_mc_2->SetLineWidth(2);
spitzVar_cuts_mc_3->SetLineWidth(2);
spitzVar_cuts_mc_4->SetLineWidth(2);
spitzVar_cuts_mc_5->SetLineWidth(2);
spitzVar_cuts_mc_6->SetLineWidth(2);

spitzVar_cuts_strobe_0->SetLineWidth(2);
spitzVar_cuts_strobe_1->SetLineWidth(2);
spitzVar_cuts_strobe_2->SetLineWidth(2);
spitzVar_cuts_strobe_3->SetLineWidth(2);
spitzVar_cuts_strobe_4->SetLineWidth(2);
spitzVar_cuts_strobe_5->SetLineWidth(2);
spitzVar_cuts_strobe_6->SetLineWidth(2);

spitzVar_cuts_dirt_0->SetLineColor(28);
spitzVar_cuts_dirt_1->SetLineColor(28);
spitzVar_cuts_dirt_2->SetLineColor(28);
spitzVar_cuts_dirt_3->SetLineColor(28);
spitzVar_cuts_dirt_4->SetLineColor(28);
spitzVar_cuts_dirt_5->SetLineColor(28);
spitzVar_cuts_dirt_6->SetLineColor(28);

spitzVar_cuts_dirt_0->SetLineWidth(2);
spitzVar_cuts_dirt_1->SetLineWidth(2);
spitzVar_cuts_dirt_2->SetLineWidth(2);
spitzVar_cuts_dirt_3->SetLineWidth(2);
spitzVar_cuts_dirt_4->SetLineWidth(2);
spitzVar_cuts_dirt_5->SetLineWidth(2);
spitzVar_cuts_dirt_6->SetLineWidth(2);

spitzVar_cuts_strobe_0->SetLineColor(95);
spitzVar_cuts_strobe_1->SetLineColor(95);
spitzVar_cuts_strobe_2->SetLineColor(95);
spitzVar_cuts_strobe_3->SetLineColor(95);
spitzVar_cuts_strobe_4->SetLineColor(95);
spitzVar_cuts_strobe_5->SetLineColor(95);
spitzVar_cuts_strobe_6->SetLineColor(95);

TCanvas *thitCanv_0 = new TCanvas();
tHit1_cuts_data_0->Draw("e1 p");
tHit1_cuts_mc_0->Draw("same");
tHit1_cuts_pip_0->Draw("same");
tHit1_cuts_kp_0->Draw("same");
tHit1_cuts_kdar_0->Draw("same");
tHit1_cuts_strobe_0->Draw("same");
thitCanv_0->Print("tHit1_cuts_0.eps");

TCanvas *tmuCanv_0 = new TCanvas();
tmu_cuts_data_0->Draw("e1 p");
tmu_cuts_mc_0->Draw("same");
tmu_cuts_pip_0->Draw("same");
tmu_cuts_kp_0->Draw("same");
tmu_cuts_kdar_0->Draw("same");
tmuCanv_0->Print("tmu_cuts_0.eps");

TCanvas *thitCanv_1 = new TCanvas();
tHit1_cuts_data_1->Draw("e1 p");
tHit1_cuts_mc_1->Draw("same");
tHit1_cuts_pip_1->Draw("same");
tHit1_cuts_kp_1->Draw("same");
tHit1_cuts_kdar_1->Draw("same");
tHit1_cuts_strobe_1->Draw("same");
thitCanv_1->Print("tHit1_cuts_1.eps");

TCanvas *tmuCanv_1 = new TCanvas();
tmu_cuts_data_1->Draw("e1 p");
tmu_cuts_mc_1->Draw("same");
tmu_cuts_pip_1->Draw("same");
tmu_cuts_kp_1->Draw("same");
tmu_cuts_kdar_1->Draw("same");
tmuCanv_1->Print("tmu_cuts_1.eps");

TCanvas *thitCanv_2 = new TCanvas();
tHit1_cuts_data_2->Draw("e1 p");
tHit1_cuts_mc_2->Draw("same");
tHit1_cuts_pip_2->Draw("same");
tHit1_cuts_kp_2->Draw("same");
tHit1_cuts_kdar_2->Draw("same");
tHit1_cuts_strobe_2->Draw("same");
thitCanv_2->Print("tHit1_cuts_2.eps");

TCanvas *tmuCanv_2 = new TCanvas();
tmu_cuts_data_2->Draw("e1 p");
tmu_cuts_mc_2->Draw("same");
tmu_cuts_pip_2->Draw("same");
tmu_cuts_kp_2->Draw("same");
tmu_cuts_kdar_2->Draw("same");
tmuCanv_2->Print("tmu_cuts_2.eps");

TCanvas *thitCanv_3 = new TCanvas();
tHit1_cuts_data_3->Draw("e1 p");
tHit1_cuts_mc_3->Draw("same");
tHit1_cuts_pip_3->Draw("same");
tHit1_cuts_kp_3->Draw("same");
tHit1_cuts_kdar_3->Draw("same");
tHit1_cuts_strobe_3->Draw("same");
thitCanv_3->Print("tHit1_cuts_3.eps");

TCanvas *tmuCanv_3 = new TCanvas();
tmu_cuts_data_3->Draw("e1 p");
tmu_cuts_mc_3->Draw("same");
tmu_cuts_pip_3->Draw("same");
tmu_cuts_kp_3->Draw("same");
tmu_cuts_kdar_3->Draw("same");
tmuCanv_3->Print("tmu_cuts_3.eps");

TCanvas *thitCanv_4 = new TCanvas();
tHit1_cuts_data_4->Draw("e1 p");
tHit1_cuts_mc_4->Draw("same");
tHit1_cuts_pip_4->Draw("same");
tHit1_cuts_kp_4->Draw("same");
tHit1_cuts_kdar_4->Draw("same");
tHit1_cuts_strobe_4->Draw("same");
thitCanv_4->Print("tHit1_cuts_4.eps");

TCanvas *tmuCanv_4 = new TCanvas();
tmu_cuts_data_4->Draw("e1 p");
tmu_cuts_mc_4->Draw("same");
tmu_cuts_pip_4->Draw("same");
tmu_cuts_kp_4->Draw("same");
tmu_cuts_kdar_4->Draw("same");
tmuCanv_4->Print("tmu_cuts_4.eps");

TCanvas *thitCanv_5 = new TCanvas();
tHit1_cuts_data_5->Draw("e1 p");
tHit1_cuts_mc_5->Draw("same");
tHit1_cuts_pip_5->Draw("same");
tHit1_cuts_kp_5->Draw("same");
tHit1_cuts_kdar_5->Draw("same");
tHit1_cuts_strobe_5->Draw("same");
thitCanv_5->Print("tHit1_cuts_5.eps");

TCanvas *tmuCanv_5 = new TCanvas();
tmu_cuts_data_5->Draw("e1 p");
tmu_cuts_mc_5->Draw("same");
tmu_cuts_pip_5->Draw("same");
tmu_cuts_kp_5->Draw("same");
tmu_cuts_kdar_5->Draw("same");
tmuCanv_5->Print("tmu_cuts_5.eps");

TCanvas *thitCanv_6 = new TCanvas();
tHit1_cuts_data_6->Draw("e1 p");
tHit1_cuts_mc_6->Draw("same");
tHit1_cuts_pip_6->Draw("same");
tHit1_cuts_kp_6->Draw("same");
tHit1_cuts_kdar_6->Draw("same");
tHit1_cuts_strobe_6->Draw("same");
thitCanv_6->Print("tHit1_cuts_6.eps");

TCanvas *tmuCanv_6 = new TCanvas();
tmu_cuts_data_6->Draw("e1 p");
tmu_cuts_mc_6->Draw("same");
tmu_cuts_pip_6->Draw("same");
tmu_cuts_kp_6->Draw("same");
tmu_cuts_kdar_6->Draw("same");
tmuCanv_6->Print("tmu_cuts_6.eps");

TCanvas seqCuts("seqCuts");
tmu_cuts_data_0->Draw("e1 p");
tmu_cuts_mc_0->Draw("same");
tmu_cuts_pip_0->Draw("same");
tmu_cuts_kp_0->Draw("same");
tmu_cuts_kdar_0->Draw("same");
seqCuts.Print("tmuCuts.ps(");
tmu_cuts_data_1->Draw("e1 p");
tmu_cuts_mc_1->Draw("same");
tmu_cuts_pip_1->Draw("same");
tmu_cuts_kp_1->Draw("same");
tmu_cuts_kdar_1->Draw("same");
seqCuts.Print("tmuCuts.ps");
tmu_cuts_data_2->Draw("e1 p");
tmu_cuts_mc_2->Draw("same");
tmu_cuts_pip_2->Draw("same");
tmu_cuts_kp_2->Draw("same");
tmu_cuts_kdar_2->Draw("same");
seqCuts.Print("tmuCuts.ps");
tmu_cuts_data_3->Draw("e1 p");
tmu_cuts_mc_3->Draw("same");
tmu_cuts_pip_3->Draw("same");
tmu_cuts_kp_3->Draw("same");
tmu_cuts_kdar_3->Draw("same");
seqCuts.Print("tmuCuts.ps");
tmu_cuts_data_4->Draw("e1 p");
tmu_cuts_mc_4->Draw("same");
tmu_cuts_pip_4->Draw("same");
tmu_cuts_kp_4->Draw("same");
tmu_cuts_kdar_4->Draw("same");
seqCuts.Print("tmuCuts.ps");
tmu_cuts_data_5->Draw("e1 p");
tmu_cuts_mc_5->Draw("same");
tmu_cuts_pip_5->Draw("same");
tmu_cuts_kp_5->Draw("same");
tmu_cuts_kdar_5->Draw("same");
seqCuts.Print("tmuCuts.ps");
tmu_cuts_data_6->Draw("e1 p");
tmu_cuts_mc_6->Draw("same");
tmu_cuts_pip_6->Draw("same");
tmu_cuts_kp_6->Draw("same");
tmu_cuts_kdar_6->Draw("same");
seqCuts.Print("tmuCuts.ps)");

TCanvas seqCuts2("seqCuts2");
tHit1_cuts_data_0->Draw("e1 p");
tHit1_cuts_mc_0->Draw("same");
tHit1_cuts_pip_0->Draw("same");
tHit1_cuts_kp_0->Draw("same");
tHit1_cuts_strobe_0->Draw("same");
tHit1_cuts_kdar_0->Draw("same");
seqCuts2.Print("thitCuts.ps(");
tHit1_cuts_data_1->Draw("e1 p");
tHit1_cuts_mc_1->Draw("same");
tHit1_cuts_pip_1->Draw("same");
tHit1_cuts_strobe_1->Draw("same");
tHit1_cuts_kp_1->Draw("same");
tHit1_cuts_kdar_1->Draw("same");
seqCuts2.Print("thitCuts.ps");
tHit1_cuts_data_2->Draw("e1 p");
tHit1_cuts_mc_2->Draw("same");
tHit1_cuts_pip_2->Draw("same");
tHit1_cuts_kp_2->Draw("same");
tHit1_cuts_strobe_2->Draw("same");
tHit1_cuts_kdar_2->Draw("same");
seqCuts2.Print("thitCuts.ps");
tHit1_cuts_data_3->Draw("e1 p");
tHit1_cuts_mc_3->Draw("same");
tHit1_cuts_pip_3->Draw("same");
tHit1_cuts_kp_3->Draw("same");
tHit1_cuts_strobe_3->Draw("same");
tHit1_cuts_kdar_3->Draw("same");
seqCuts2.Print("thitCuts.ps");
tHit1_cuts_data_4->Draw("e1 p");
tHit1_cuts_mc_4->Draw("same");
tHit1_cuts_pip_4->Draw("same");
tHit1_cuts_kp_4->Draw("same");
tHit1_cuts_strobe_4->Draw("same");
tHit1_cuts_kdar_4->Draw("same");
seqCuts2.Print("thitCuts.ps");
tHit1_cuts_data_5->Draw("e1 p");
tHit1_cuts_mc_5->Draw("same");
tHit1_cuts_pip_5->Draw("same");
tHit1_cuts_kp_5->Draw("same");
tHit1_cuts_strobe_5->Draw("same");
tHit1_cuts_kdar_5->Draw("same");
seqCuts2.Print("thitCuts.ps");
tHit1_cuts_data_6->Draw("e1 p");
tHit1_cuts_mc_6->Draw("same");
tHit1_cuts_pip_6->Draw("same");
tHit1_cuts_kp_6->Draw("same");
tHit1_cuts_strobe_6->Draw("same");
tHit1_cuts_kdar_6->Draw("same");
seqCuts2.Print("thitCuts.ps)");

spitzVar_cuts_data_0->SetMinimum(0);
spitzVar_cuts_data_1->SetMinimum(0);
spitzVar_cuts_data_2->SetMinimum(0);
spitzVar_cuts_data_3->SetMinimum(0);
spitzVar_cuts_data_4->SetMinimum(0);
spitzVar_cuts_data_5->SetMinimum(0);
spitzVar_cuts_data_6->SetMinimum(0);

TCanvas seqCuts3("seqCuts3");
spitzVar_cuts_data_0->Draw("e1 p");
spitzVar_cuts_mc_0->Draw("same");
spitzVar_cuts_pip_0->Draw("same");
spitzVar_cuts_kp_0->Draw("same");
spitzVar_cuts_strobe_0->Draw("same");
spitzVar_cuts_dirt_0->Draw("same");
seqCuts3.Print("spitzVarCuts.ps(");
spitzVar_cuts_data_1->Draw("e1 p");
spitzVar_cuts_mc_1->Draw("same");
spitzVar_cuts_pip_1->Draw("same");
spitzVar_cuts_strobe_1->Draw("same");
spitzVar_cuts_dirt_1->Draw("same");
spitzVar_cuts_kp_1->Draw("same");
seqCuts3.Print("spitzVarCuts.ps");
spitzVar_cuts_data_2->Draw("e1 p");
spitzVar_cuts_mc_2->Draw("same");
spitzVar_cuts_pip_2->Draw("same");
spitzVar_cuts_kp_2->Draw("same");
spitzVar_cuts_strobe_2->Draw("same");
spitzVar_cuts_dirt_2->Draw("same");
seqCuts3.Print("spitzVarCuts.ps");
spitzVar_cuts_data_3->Draw("e1 p");
spitzVar_cuts_mc_3->Draw("same");
spitzVar_cuts_pip_3->Draw("same");
spitzVar_cuts_kp_3->Draw("same");
spitzVar_cuts_strobe_3->Draw("same");
spitzVar_cuts_dirt_3->Draw("same");
seqCuts3.Print("spitzVarCuts.ps");
spitzVar_cuts_data_4->Draw("e1 p");
spitzVar_cuts_mc_4->Draw("same");
spitzVar_cuts_pip_4->Draw("same");
spitzVar_cuts_kp_4->Draw("same");
spitzVar_cuts_strobe_4->Draw("same");
spitzVar_cuts_dirt_4->Draw("same");
seqCuts3.Print("spitzVarCuts.ps");
spitzVar_cuts_data_5->Draw("e1 p");
spitzVar_cuts_mc_5->Draw("same");
spitzVar_cuts_pip_5->Draw("same");
spitzVar_cuts_kp_5->Draw("same");
spitzVar_cuts_strobe_5->Draw("same");
spitzVar_cuts_dirt_5->Draw("same");
seqCuts3.Print("spitzVarCuts.ps");
spitzVar_cuts_data_6->Draw("e1 p");
spitzVar_cuts_mc_6->Draw("same");
spitzVar_cuts_pip_6->Draw("same");
spitzVar_cuts_kp_6->Draw("same");
spitzVar_cuts_strobe_6->Draw("same");
spitzVar_cuts_dirt_6->Draw("same");
seqCuts3.Print("spitzVarCuts.ps)");

tHit1_deltaLk_mc->SetTitle("MC");
tHit1_deltaLk_data->SetTitle("Data");

tHit1_deltaLk_mc->GetXaxis()->SetTitle("tank hits");
tHit1_deltaLk_mc->GetXaxis()->CenterTitle(1);
tHit1_deltaLk_mc->GetYaxis()->SetTitle("<-- e-like #mu-like -->");
tHit1_deltaLk_mc->GetYaxis()->CenterTitle(1);
tHit1_deltaLk_mc->GetYaxis()->SetTitleOffset(1.2);

tHit1_deltaLk_data->GetXaxis()->SetTitle("tank hits");
tHit1_deltaLk_data->GetXaxis()->CenterTitle(1);
tHit1_deltaLk_data->GetYaxis()->SetTitle("<-- e-like #mu-like -->");
tHit1_deltaLk_data->GetYaxis()->CenterTitle(1);
tHit1_deltaLk_data->GetYaxis()->SetTitleOffset(1.2);

TCanvas *twoDlkthitCdata = new TCanvas();
tHit1_deltaLk_data->Draw("colz");
twoDlkthitCdata->Print("twoD_tHit_deltaLk_data.eps");

tHit1_deltaLk_mc->SetMaximum(tHit1_deltaLk_data->GetMaximum());

TCanvas *twoDlkthitCmc = new TCanvas();
tHit1_deltaLk_mc->Draw("colz");
twoDlkthitCmc->Print("twoD_tHit_deltaLk_mc.eps");

chans->GetXaxis()->SetTitle("interaction channel");
chans->GetXaxis()->CenterTitle(1);

TCanvas *chanz = new TCanvas();
chans->Draw();
chanz->Print("channels.eps");

TCanvas *chanThit = new TCanvas();
tHit1_tot->Draw();
tHit1_data->Draw("e1p same");
tHit1_nc1pi->Draw("same");
tHit1_ccqe->Draw("same");
chanThit->Print("tHit_channels.eps");

lk_2ndBump_data->SetTitle("tank hits (1st SE) > 120 red: CCQE, brown: NC#pi^{+}");
//lk_2ndBump_data->SetTitle("tank hits (1st SE) > 60 && < 120 red: CCQE, brown: NC#pi^{+}");

lk_2ndBump_data->GetXaxis()->SetTitle("<-- e-like #mu-like -->");
lk_2ndBump_data->GetXaxis()->CenterTitle(1);

TCanvas *secBmp = new TCanvas();
lk_2ndBump_data->Draw("e1p");
lk_2ndBump_tot->Draw("same");
lk_2ndBump_ccqe->Draw("same");
lk_2ndBump_ncpi->Draw("same");
secBmp->Print("secBmp_lk.eps");
secBmp->Print("secBmp_lk.pdf");

truEnu_tHit1->GetXaxis()->SetTitle("true #nu energy (GeV)");
truEnu_tHit1->GetXaxis()->CenterTitle(1);

truEnu_tHit1->GetYaxis()->SetTitle("observed tank hits");
truEnu_tHit1->GetYaxis()->CenterTitle(1);

TCanvas *thitenucorr = new TCanvas();
truEnu_tHit1->Draw("colz");
thitenucorr->Print("tHit_enu_corr.eps");
thitenucorr->SetLogz();
thitenucorr->Print("tHit_enu_corr_log.eps");

//lk_tot_2se->GetXaxis()->SetTitle("<-- e-like #mu-like -->");
//lk_tot_2se->GetXaxis()->CenterTitle(1);

//lk_tot_2se->SetMaximum(elike_data_2se->GetMaximum()*1.15);

elike_data_2se->GetXaxis()->SetTitle("e-like score (arb.)");
elike_data_2se->GetXaxis()->CenterTitle(1);

elike_data_2se->SetTitle("Red: 2nd SE (Michels), blue: 1st SE.  Tank hits > 60 && < 120. Points: data, line: MC");

TCanvas *lkP2 = new TCanvas();
elike_data_2se->Draw("e1p");
elike_mc_2se->Draw("same");
elike_data_2ndBmp->Draw("e1p same");
elike_mc_2ndBmp->Draw("same");
lkP2->Print("eLike_comp.eps");

mulike_data_2ndBmp->GetXaxis()->SetTitle("#mu-like (arb.)");
mulike_data_2ndBmp->GetXaxis()->CenterTitle(1);
mulike_data_2ndBmp->SetTitle("tank hits > 60 && < 120");

TCanvas *lkP3 = new TCanvas();
mulike_data_2ndBmp->Draw("e1p");
mulike_mc_2ndBmp->Draw("same");
lkP3->Print("muLike_comp.eps");

michEnergy_eHyp_mc->SetTitle("2nd SE");
michEnergy_eHyp_mc->GetXaxis()->SetTitle("reco Michel energy, e hypothesis (GeV)");
michEnergy_eHyp_mc->GetXaxis()->CenterTitle(1);

michEnergy_eHyp_mc->SetMaximum(michEnergy_eHyp_data->GetMaximum()*1.15);

TCanvas *michEhyp = new TCanvas();
michEnergy_eHyp_mc->Draw();
michEnergy_eHyp_data->Draw("e1p same");
michEhyp->Print("michE_eHyp.eps");

michEnergy_muHyp_mc->SetTitle("2nd SE");
michEnergy_muHyp_mc->GetXaxis()->SetTitle("reco Michel energy, #mu hypothesis (GeV)");
michEnergy_muHyp_mc->GetXaxis()->CenterTitle(1);

michEnergy_muHyp_mc->SetMaximum(michEnergy_muHyp_data->GetMaximum()*1.15);

TCanvas *michMuhyp = new TCanvas();
michEnergy_muHyp_mc->Draw();
michEnergy_muHyp_data->Draw("e1p same");
michMuhyp->Print("michE_muHyp.eps");

TString fileName2;
if (useRewt){
  if (pt0pt1) fileName2 = "withkapparewt_1.01.root";
  else fileName2 = "withkapparewt_1.00.root";
}
else fileName2 = "withoutkapparewt.root";

TFile writeFile (fileName2.Data(), "RECREATE");
//TFile writeFile ("withoutkapparewt.root", "RECREATE");
tHit1_deltaLk_mc->Write(tHit1_deltaLk_mc->GetName());
truEnu_tot->Write(truEnu_tot->GetName());
tHit1_tot->Write(tHit1_tot->GetName());
writeFile.Close();

truEnu_truTmu->GetXaxis()->SetTitle("true E_{#nu} (GeV)");
truEnu_truTmu->GetXaxis()->CenterTitle(1);

truEnu_truTmu->GetYaxis()->SetTitle("true T_{#mu} (GeV)");
truEnu_truTmu->GetYaxis()->CenterTitle(1);

TCanvas *jfk = new TCanvas();
truEnu_truTmu->Draw("colz");
jfk->Print("truEnu_truTmuCorr.eps");

spitzVar_data->SetTitle("#nu mode BNB;tankhits * myStFull_fqlt10[0]/1000");
spitzVar_data_largeRng->SetTitle("#nu mode BNB;tankhits * myStFull_fqlt10[0]/1000");

//cout<<" \n\n\t\t\t x-factor is "<<spitzVar_data->Integral()/spitzVar_mc->Integral()<<" \n\n"<<endl;

//spitzVar_mc->Scale(spitzVar_data->Integral()/spitzVar_mc->Integral());
spitzVar_data->SetMaximum(spitzVar_data->GetMaximum()*1.15);

spitzVar_dirt_largeRng->SetLineWidth(2);
spitzVar_dirt->SetLineWidth(2);
spitzVar_dirt_largeRng->SetLineColor(28);
spitzVar_dirt->SetLineColor(28);

spitzVar_data->SetMinimum(0);

for (int j=0; j<nModels; j++){
  //spitzVar_dirt[j]->SetLineWidth(2);
  //spitzVar_dirt[j]->SetLineColor(28);
  thits_dirt[j]->SetLineWidth(2);
  thits_dirt[j]->SetLineColor(28);
}

thits_strobe->SetLineWidth(2);
thits_strobe->SetLineColor(95);

TCanvas *fdas = new TCanvas();

for (int j=0; j<nModels; j++){

  if (j==0) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.022));
  if (j==1) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.000));
  if (j==2) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.002));
  if (j==3) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.004));
  if (j==4) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.006));
  if (j==5) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.008));
  if (j==6) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.010));
  if (j==7) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.012));
  if (j==8) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.014));
  if (j==9) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.016));
  if (j==10) spitzVar_data->SetTitle(Form("bnb #kappa = %lf",1.018));
  spitzVar_data->Draw("e1p");
  spitzVar_mc[j]->Draw("same");
  spitzVar_dirt_r[j]->Draw("same");
  spitzVar_strobe->Draw("same");
  if (j==0) fdas->Print("kappaTests_nubnb.ps(");
  if (j>0&&j<nModels-1) fdas->Print("kappaTests_nubnb.ps");
  if (j==nModels-1) fdas->Print("kappaTests_nubnb.ps)");

//spitzVarPred_k1->Draw("same");
}

spitzVar_mc[1]->Scale(1.07);

TCanvas *forJ = new TCanvas();
spitzVar_data->Draw("e1p");
spitzVar_mc[1]->Draw("same");
forJ->Print("forJanet.eps");

spitzVar_data->Add(spitzVar_mc[1],-1);
spitzVar_data->SetTitle("MC subtracted");

TCanvas *forJ2 = new TCanvas();
spitzVar_data->Draw("e1p");
forJ2->Print("forJanet_subt.eps");

TCanvas *fdas20 = new TCanvas();

float modelsc = 0.;

for (int j=0; j<nModels; j++){

  modelsc = 0.;
  modelsc = thits_data->Integral() / thits_mc[j]->Integral();

  thits_mc[j]->Scale(modelsc);
  thits_kp[j]->Scale(modelsc);
  thits_pip[j]->Scale(modelsc);
  thits_pim[j]->Scale(modelsc);
  thits_othr[j]->Scale(modelsc);

  if (j==0) thits_data->SetTitle(Form("#kappa = %lf",1.022));
  if (j==1) thits_data->SetTitle(Form("#kappa = %lf",1.000));
  if (j==2) thits_data->SetTitle(Form("#kappa = %lf",1.002));
  if (j==3) thits_data->SetTitle(Form("#kappa = %lf",1.004));
  if (j==4) thits_data->SetTitle(Form("#kappa = %lf",1.006));
  if (j==5) thits_data->SetTitle(Form("#kappa = %lf",1.008));
  if (j==6) thits_data->SetTitle(Form("#kappa = %lf",1.010));
  if (j==7) thits_data->SetTitle(Form("#kappa = %lf",1.012));
  if (j==8) thits_data->SetTitle(Form("#kappa = %lf",1.014));
  if (j==9) thits_data->SetTitle(Form("#kappa = %lf",1.016));
  if (j==10) thits_data->SetTitle(Form("#kappa = %lf",1.018));

  if (testst==0) thits_data->GetXaxis()->SetTitle("tank hits");
  if (testst) thits_data->GetXaxis()->SetTitle("Stancu fitted energy (MeV)");

  thits_data->Draw("e1p");
  thits_dirt[j]->Draw("same");
  thits_strobe->Draw("same");
  thits_mc[j]->Draw("same");
  thits_kp[j]->Draw("same");
  thits_pip[j]->Draw("same");
  thits_pim[j]->Draw("same");
  thits_othr[j]->Draw("same");

  if (testst==0){
    if (j==0) fdas20->Print("kappaTests_thits_nubnb.ps(");
    if (j>0&&j<nModels-1) fdas20->Print("kappaTests_thits_nubnb.ps");
    if (j==nModels-1) fdas20->Print("kappaTests_thits_nubnb.ps)");
  }

  if (testst){
    if (j==0) fdas20->Print("kappaTests_stfull_nubnb.ps(");
    if (j>0&&j<nModels-1) fdas20->Print("kappaTests_stfull_nubnb.ps");
    if (j==nModels-1) fdas20->Print("kappaTests_stfull_nubnb.ps)");
  }

  cout<<" tank hits model "<<j<<" data - bkg "<<thits_data->Integral()-thits_mc[j]->Integral()<<endl;

//spitzVarPred_k1->Draw("same");
}


TCanvas *fdas2 = new TCanvas();

for (int j=0; j<nModels; j++){

  if (j==0) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.022));
  if (j==1) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.000));
  if (j==2) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.002));
  if (j==3) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.004));
  if (j==4) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.006));
  if (j==5) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.008));
  if (j==6) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.010));
  if (j==7) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.012));
  if (j==8) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.014));
  if (j==9) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.016));
  if (j==10) spitzVar_data_largeRng->SetTitle(Form("bnb #kappa = %lf",1.018));
  spitzVar_data_largeRng->Draw("e1p");
  spitzVar_mc_largeRng[j]->Draw("same");
  spitzVar_dirt_largeRng->Draw("same");
  spitzVar_strobe_largeRng->Draw("same");
  if (j==0) fdas2->Print("kappaTests_largerng_nubnb.ps(");
  if (j>0&&j<nModels-1) fdas2->Print("kappaTests_largerng_nubnb.ps");
  if (j==nModels-1) fdas2->Print("kappaTests_largerng_nubnb.ps)");

//spitzVarPred_k1->Draw("same");
}

thits_pimRng->SetLineWidth(2);
thits_pimRng->SetLineColor(kCyan);
thits_pipRng->SetLineWidth(2);
thits_pipRng->SetLineColor(kMagenta);
thits_mcRng->SetLineWidth(2);
thits_kpRng->SetLineWidth(2);
thits_kpRng->SetLineColor(kBlue);
thits_dirtRng->SetLineWidth(2);
thits_dirtRng->SetLineColor(28);
thits_strobeRng->SetLineWidth(2);
thits_strobeRng->SetLineColor(95);

thits_dataRng->SetMarkerColor(kRed);

thits_mcRng->Scale(scaleFactor);
thits_pimRng->Scale(scaleFactor);
thits_pipRng->Scale(scaleFactor);
thits_kpRng->Scale(scaleFactor);

TCanvas *fdasRng2 = new TCanvas();
thits_dataRng->Draw("e1p");
thits_mcRng->Draw("same");
thits_kpRng->Draw("same");
thits_pipRng->Draw("same");
thits_pimRng->Draw("same");
thits_dirtRng->Draw("same");
thits_strobeRng->Draw("same");
fdasRng2->Print("thits_nubnb_largeRng.eps");

/*
TCanvas *fdas = new TCanvas();
spitzVar_data->Draw("e1p");
spitzVar_mc->Draw("same");
fdas->Print("spitzVar_numode.eps");

TCanvas *fdas2 = new TCanvas();
spitzVar_data_largeRng->Draw("e1p");
spitzVar_mc_largeRng->Draw("same");
fdas2->Print("spitzVar_numode_largerng.eps");
*/
thetaPi->SetTitle("#pi^{+} parent prod angle; #theta_{#pi} (rad)");

thetaPi->SetLineWidth(2);

TLine *line = new TLine(0.03,0.0,0.03,thetaPi->GetMaximum() * 1.05);
TLine *line2 = new TLine(0.21,0.0,0.21,thetaPi->GetMaximum() * 1.05);

TCanvas *css = new TCanvas();
thetaPi->Draw();
line->Draw();
line2->Draw();
css->Print("thetaPi.eps");

pip_phaseSp->SetTitle("; p_{#pi} (GeV); #theta_{#pi} (rad)");

float lowerX = 0.8;
float upperX = 6.4;
float lowerY = 0.03;
float upperY = 0.21;

TLine *xLower = new TLine(lowerX,lowerY,lowerX,upperY);
TLine *xUpper = new TLine(upperX,lowerY,upperX,upperY);
TLine *yLower = new TLine(lowerX,lowerY,upperX,lowerY);
TLine *yUpper = new TLine(lowerX,upperY,upperX,upperY);
xLower->SetLineWidth(2);
xUpper->SetLineWidth(2);
yLower->SetLineWidth(2);
yUpper->SetLineWidth(2);

TLatex *h = new TLatex();
h->SetNDC();
h->SetTextSize(0.040);

TString HARPtxt = "HARP coverage";

TCanvas *css2 = new TCanvas();
pip_phaseSp->Draw("colz");
h->DrawLatex(0.61,0.85,HARPtxt);
xLower->Draw();
xUpper->Draw();
yLower->Draw();
yUpper->Draw();
css2->Print("pip_phaseSp.eps");

uzRes_tmuBinz_ryan_0->SetLineColor(kRed);
uzRes_tmuBinz_ryan_0->SetLineWidth(2);
uzRes_tmuBinz_stancu_0->SetLineWidth(2);

uzRes_tmuBinz_ryan_1->SetLineColor(kRed);
uzRes_tmuBinz_ryan_1->SetLineWidth(2);
uzRes_tmuBinz_stancu_1->SetLineWidth(2);

uzRes_tmuBinz_ryan_2->SetLineColor(kRed);
uzRes_tmuBinz_ryan_2->SetLineWidth(2);
uzRes_tmuBinz_stancu_2->SetLineWidth(2);

uzRes_tmuBinz_ryan_3->SetLineColor(kRed);
uzRes_tmuBinz_ryan_3->SetLineWidth(2);
uzRes_tmuBinz_stancu_3->SetLineWidth(2);

uzRes_tmuBinz_ryan_4->SetLineColor(kRed);
uzRes_tmuBinz_ryan_4->SetLineWidth(2);
uzRes_tmuBinz_stancu_4->SetLineWidth(2);

uzDist_tmuBinz_ryan_0->SetLineColor(kRed);
uzDist_tmuBinz_ryan_0->SetLineWidth(2);
uzDist_tmuBinz_stancu_0->SetLineWidth(2);

uzDist_tmuBinz_ryan_1->SetLineColor(kRed);
uzDist_tmuBinz_ryan_1->SetLineWidth(2);
uzDist_tmuBinz_stancu_1->SetLineWidth(2);

uzDist_tmuBinz_ryan_2->SetLineColor(kRed);
uzDist_tmuBinz_ryan_2->SetLineWidth(2);
uzDist_tmuBinz_stancu_2->SetLineWidth(2);

uzDist_tmuBinz_ryan_3->SetLineColor(kRed);
uzDist_tmuBinz_ryan_3->SetLineWidth(2);
uzDist_tmuBinz_stancu_3->SetLineWidth(2);

uzDist_tmuBinz_ryan_4->SetLineColor(kRed);
uzDist_tmuBinz_ryan_4->SetLineWidth(2);
uzDist_tmuBinz_stancu_4->SetLineWidth(2);

uzRes_tmuBinz_ryan_0->SetTitle("T_{#mu} < 100 MeV, red = OneTrack, black = Stancu; reco UZ - true UZ");
uzRes_tmuBinz_ryan_1->SetTitle("100 < T_{#mu} (MeV) < 200, red = OneTrack, black = Stancu; reco UZ - true UZ");
uzRes_tmuBinz_ryan_2->SetTitle("200 < T_{#mu} (MeV) < 300, red = OneTrack, black = Stancu; reco UZ - true UZ");
uzRes_tmuBinz_ryan_3->SetTitle("300 < T_{#mu} (MeV) < 400, red = OneTrack, black = Stancu; reco UZ - true UZ");
uzRes_tmuBinz_ryan_4->SetTitle("400 < T_{#mu} (MeV) < 500, red = OneTrack, black = Stancu; reco UZ - true UZ");

gStyle->SetOptStat(1111);

TCanvas *c30 = new TCanvas();
uzRes_tmuBinz_ryan_0->Draw();
uzRes_tmuBinz_stancu_0->Draw("same");
c30->Print("uzRes_bin0.eps");

TCanvas *c31 = new TCanvas();
uzRes_tmuBinz_ryan_1->Draw();
uzRes_tmuBinz_stancu_1->Draw("same");
c31->Print("uzRes_bin1.eps");

TCanvas *c32 = new TCanvas();
uzRes_tmuBinz_ryan_2->Draw();
uzRes_tmuBinz_stancu_2->Draw("same");
c32->Print("uzRes_bin2.eps");

TCanvas *c33 = new TCanvas();
uzRes_tmuBinz_ryan_3->Draw();
uzRes_tmuBinz_stancu_3->Draw("same");
c33->Print("uzRes_bin3.eps");

TCanvas *c34 = new TCanvas();
uzRes_tmuBinz_ryan_4->Draw();
uzRes_tmuBinz_stancu_4->Draw("same");
c34->Print("uzRes_bin4.eps");

TCanvas *c330 = new TCanvas();
uzDist_tmuBinz_ryan_0->Draw();
uzDist_tmuBinz_stancu_0->Draw("same");
c330->Print("uzDist_bin0.eps");

TCanvas *c331 = new TCanvas();
uzDist_tmuBinz_ryan_1->Draw();
uzDist_tmuBinz_stancu_1->Draw("same");
c331->Print("uzDist_bin1.eps");

TCanvas *c332 = new TCanvas();
uzDist_tmuBinz_ryan_2->Draw();
uzDist_tmuBinz_stancu_2->Draw("same");
c332->Print("uzDist_bin2.eps");

TCanvas *c333 = new TCanvas();
uzDist_tmuBinz_ryan_3->Draw();
uzDist_tmuBinz_stancu_3->Draw("same");
c333->Print("uzDist_bin3.eps");

TCanvas *c334 = new TCanvas();
uzDist_tmuBinz_ryan_4->Draw();
uzDist_tmuBinz_stancu_4->Draw("same");
c334->Print("uzDist_bin4.eps");

TCanvas *tst = new TCanvas();
truTmuDist->Draw();
tst->Print("tmuDist.eps");

ryanTmuDist->SetLineWidth(2);
ryanTmuDist->SetLineColor(kRed);
stanTmuDist->SetLineWidth(2);

TCanvas *comp = new TCanvas();
ryanTmuDist->Draw();
stanTmuDist->Draw("same");
comp->Print("tmuComp.eps");

TCanvas *strC1 = new TCanvas();
spitzVar_strobe_largeRng->Draw();
strC1->Print("spitzVar_strobe_largeRng.eps");

TCanvas *strC2 = new TCanvas();
spitzVar_strobe->Draw();
strC2->Print("spitzVar_strobe.eps");

TCanvas *dirtC2 = new TCanvas();
spitzVar_dirt->Draw();
dirtC2->Print("spitzVar_dirt.eps");

TCanvas *dirtC = new TCanvas();
spitzVar_dirt_largeRng->Draw();
dirtC->Print("spitzVar_dirt_largeRng.eps");

TCanvas *dirtC20 = new TCanvas();
dirt_channels->Draw();
dirtC20->Print("dirt_channels.eps");

TCanvas *dirtM = new TCanvas();
dirt_secSE->Draw();
dirtM->Print("dirt_secSE.eps");

TCanvas *dirtC220 = new TCanvas();
dirt_qsq_ccqe->Draw();
dirtC220->Print("dirt_qsq_ccqe.eps");

TCanvas *mcC220 = new TCanvas();
mc_qsq_ccqe->Draw();
mcC220->Print("mc_qsq_ccqe.eps");

fqlt10_mc->SetLineWidth(2);

fqlt10_data->SetFillStyle(0);
fqlt10_data->SetMarkerStyle(20);
fqlt10_data->SetMarkerSize(0.7);
fqlt10_data->SetLineColor(1);
fqlt10_data->SetMarkerColor(2);
fqlt10_data->SetBarWidth(4);
fqlt10_data->SetLineWidth(1);

fqlt10_data->SetTitle("nu mode bnb; fqlt10;");
fqlt10_data->SetMaximum(50000);

gStyle->SetOptStat(0);

TCanvas *fqC = new TCanvas();
fqlt10_data->Draw("e1p");
fqlt10_mc->Draw("same");
fqC->Print("fqlt10.eps");

data_inbmp->SetLineColor(kBlue);
data_outbmp->SetLineColor(kRed);
dirt_secSE->SetLineColor(28);
strobe_secSE->SetLineColor(95);

TFile bmpFile ("bmpFile_nubnb_500cm.root", "RECREATE");
data_inbmp->Write(data_inbmp->GetName());
data_outbmp->Write(data_outbmp->GetName());
strobe_secSE->Write(strobe_secSE->GetName());
dirt_secSE->Write(dirt_secSE->GetName());
bmpFile.Close();

mc_inbmp->Scale(scaleFactor);
mc_outbmp->Scale(scaleFactor);

bmp_ux_mc->Scale(scaleFactor);
bmp_uy_mc->Scale(scaleFactor);
bmp_uz_mc->Scale(scaleFactor);
bmp_x_mc->Scale(scaleFactor);
bmp_y_mc->Scale(scaleFactor);
bmp_z_mc->Scale(scaleFactor);
bmp_r_mc->Scale(scaleFactor);
bmp_t_mc->Scale(scaleFactor);
bmp_th_mc->Scale(scaleFactor);

bmp_ux_mc->SetLineWidth(2);
bmp_uy_mc->SetLineWidth(2);
bmp_uz_mc->SetLineWidth(2);
bmp_x_mc->SetLineWidth(2);
bmp_y_mc->SetLineWidth(2);
bmp_z_mc->SetLineWidth(2);
bmp_r_mc->SetLineWidth(2);
bmp_t_mc->SetLineWidth(2);
bmp_th_mc->SetLineWidth(2);

bmp_ux_data->SetMinimum(0);
bmp_ux_data->SetTitle("nu mode reco ux; reco ux");

TCanvas *bmpC_ux = new TCanvas();
bmp_ux_data->Draw("e1p");
bmp_ux_mc->Draw("same");
bmpC_ux->Print("bmp_ux.eps");

bmp_ux_data->Add(bmp_ux_mc,-1);

TCanvas *bmpC_ux_s = new TCanvas();
bmp_ux_data->Draw("e1p");
bmpC_ux_s->Print("bmp_ux_subt.eps");

bmp_uy_data->SetMinimum(0);
bmp_uy_data->SetTitle("nu mode reco uy; reco uy");

TCanvas *bmpC_uy = new TCanvas();
bmp_uy_data->Draw("e1p");
bmp_uy_mc->Draw("same");
bmpC_uy->Print("bmp_uy.eps");

bmp_uy_data->Add(bmp_uy_mc,-1);

TCanvas *bmpC_uy_s = new TCanvas();
bmp_uy_data->Draw("e1p");
bmpC_uy_s->Print("bmp_uy_subt.eps");

bmp_uz_data->SetMinimum(0);
bmp_uz_data->SetTitle("nu mode reco uz; reco uz");

TCanvas *bmpC_uz = new TCanvas();
bmp_uz_data->Draw("e1p");
bmp_uz_mc->Draw("same");
bmpC_uz->Print("bmp_uz.eps");

bmp_uz_data->Add(bmp_uz_mc,-1);

TCanvas *bmpC_uz_s = new TCanvas();
bmp_uz_data->Draw("e1p");
bmpC_uz_s->Print("bmp_uz_subt.eps");

bmp_x_data->SetMinimum(0);
bmp_x_data->SetTitle("nu mode reco x; reco x (cm)");

TCanvas *bmpC_x = new TCanvas();
bmp_x_data->Draw("e1p");
bmp_x_mc->Draw("same");
bmpC_x->Print("bmp_x.eps");

bmp_x_data->Add(bmp_x_mc,-1);

TCanvas *bmpC_x_s = new TCanvas();
bmp_x_data->Draw("e1p");
bmpC_x_s->Print("bmp_x_subt.eps");

bmp_y_data->SetMinimum(0);
bmp_y_data->SetTitle("nu mode reco y; reco y (cm)");

TCanvas *bmpC_y = new TCanvas();
bmp_y_data->Draw("e1p");
bmp_y_mc->Draw("same");
bmpC_y->Print("bmp_y.eps");

bmp_y_data->Add(bmp_y_mc,-1);

TCanvas *bmpC_y_s = new TCanvas();
bmp_y_data->Draw("e1p");
bmpC_y_s->Print("bmp_y_subt.eps");

bmp_z_data->SetMinimum(0);
bmp_z_data->SetTitle("nu mode reco z; reco z (cm)");

TCanvas *bmpC_z = new TCanvas();
bmp_z_data->Draw("e1p");
bmp_z_mc->Draw("same");
bmpC_z->Print("bmp_z.eps");

bmp_z_data->Add(bmp_z_mc,-1);

TCanvas *bmpC_z_s = new TCanvas();
bmp_z_data->Draw("e1p");
bmpC_z_s->Print("bmp_z_subt.eps");

bmp_r_data->SetMinimum(0);
bmp_r_data->SetTitle("nu mode reco r; reco r (cm)");

TCanvas *bmpC_r = new TCanvas();
bmp_r_data->Draw("e1p");
bmp_r_mc->Draw("same");
bmpC_r->Print("bmp_r.eps");

bmp_r_data->Add(bmp_r_mc,-1);

TCanvas *bmpC_r_s = new TCanvas();
bmp_r_data->Draw("e1p");
bmpC_r_s->Print("bmp_r_subt.eps");

bmp_t_data->SetMinimum(0);
bmp_t_data->SetTitle("nu mode SE diff; #delta t (ns)");

TCanvas *bmpC_t = new TCanvas();
bmp_t_data->Draw("e1p");
bmp_t_mc->Draw("same");
bmpC_t->Print("bmp_t.eps");

bmp_t_data->Add(bmp_t_mc,-1);

TCanvas *bmpC_t_s = new TCanvas();
bmp_t_data->Draw("e1p");
bmpC_t_s->Print("bmp_t_subt.eps");

bmp_th_data->SetMinimum(0);
bmp_th_data->SetTitle("nu mode tank hits; tank hits");

TCanvas *bmpC_th = new TCanvas();
bmp_th_data->Draw("e1p");
bmp_th_mc->Draw("same");
bmpC_th->Print("bmp_th.eps");

bmp_th_data->Add(bmp_th_mc,-1);

TCanvas *bmpC_th_s = new TCanvas();
bmp_th_data->Draw("e1p");
bmpC_th_s->Print("bmp_th_subt.eps");

TString filename = "unfoldFile_nubnb.root";

TFile unfoldFile(filename.Data(),"RECREATE");

tru_tmu_tank_hits_fold->Write(tru_tmu_tank_hits_fold->GetName());

unfoldFile.Close();

//return;

TFile bmpFile2 ("bmpFile_nubnb_mc_500cm.root", "RECREATE");
mc_inbmp->Write(mc_inbmp->GetName());
mc_outbmp->Write(mc_outbmp->GetName());
bmpFile2.Close();

dirt_secSE->SetTitle("blue: data around bmp, red: data outside bump, brown: dirt, orange: strobe; 2nd SE tank hits;");
data_outbmp->SetTitle("blue: data around bmp (x1), red: data outside bump (x1/15), brown: dirt (x10), orange: strobe (x15); 2nd SE tank hits;");

mc_inbmp->SetLineWidth(2);
mc_outbmp->SetLineWidth(2);

mc_inbmp->SetTitle("nu bnb tankhits*fqlt10<0.05;2nd SE tank hits");
mc_outbmp->SetTitle("nu bnb tankhits*fqlt10>=0.05;2nd SE tank hits");

mc_inbmp->SetMaximum(data_inbmp->GetMaximum()*1.15);
mc_outbmp->SetMaximum(data_outbmp->GetMaximum()*1.15);

TCanvas *bmpdat = new TCanvas();
mc_inbmp->Draw();
data_inbmp->Draw("e1p same");
bmpdat->Print("bmpDat.eps");

TCanvas *bmpdat2 = new TCanvas();
mc_outbmp->Draw();
data_outbmp->Draw("e1p same");
bmpdat2->Print("bmpDatOut.eps");

TCanvas *bmpbmp = new TCanvas();
dirt_secSE->DrawNormalized();
strobe_secSE->DrawNormalized("same");
data_inbmp->DrawNormalized("same");
data_outbmp->DrawNormalized("same");
bmpbmp->Print("bmpCheck.eps");

data_outbmp->Scale(0.06667);
//data_inbmp->Scale(15.);
strobe_secSE->Scale(15.);
dirt_secSE->Scale(10.);

TCanvas *bmpbmp2 = new TCanvas();
data_outbmp->Draw();
strobe_secSE->Draw("same");
data_inbmp->Draw("same");
dirt_secSE->Draw("same");
bmpbmp2->Print("bmpCheckNorm.eps");

//return;

truUX_tot->GetXaxis()->SetTitle("1st SE tank hits");
truUX_tot->GetXaxis()->CenterTitle(1);
truUX_tot->SetMinimum(1);

sig_nuBirthX->GetXaxis()->SetTitle("x (cm) generated nu birth position relative to detector center");
sig_nuBirthY->GetXaxis()->SetTitle("y (cm) generated nu birth position relative to detector center");
sig_nuBirthZ->GetXaxis()->SetTitle("z (cm) generated nu birth position relative to detector center");
sig_nuBirthX->GetXaxis()->CenterTitle(1);
sig_nuBirthX->GetYaxis()->CenterTitle(1);
sig_nuBirthX->GetZaxis()->CenterTitle(1);

TCanvas *xC = new TCanvas();
sig_nuBirthX->Draw();
xC->Print("sigInitX.eps");

TCanvas *yC = new TCanvas();
sig_nuBirthY->Draw();
yC->Print("sigInitY.eps");

TCanvas *zC = new TCanvas();
sig_nuBirthZ->Draw();
zC->Print("sigInitZ.eps");

TCanvas *phspPiC = new TCanvas();
ptpz_piP->Draw("colz");
phspPiC->Print("piKin.eps");

TCanvas *phspKC = new TCanvas();
ptpz_kP->Draw("colz");
phspKC->Print("kpKin.eps");

TCanvas *phspPiC_fin = new TCanvas();
ptpz_piP_fin->Draw("colz");
phspPiC_fin->Print("piKinFin.eps");

TCanvas *phspKC_fin = new TCanvas();
ptpz_kP_fin->Draw("colz");
phspKC_fin->Print("kpKinFin.eps");

sig_rad->GetXaxis()->SetTitle("generated nu creation radius (cm?)");
sig_rad->GetXaxis()->CenterTitle(1);

TCanvas *sigRadC = new TCanvas();
sig_rad->Draw();
sigRadC->Print("sig_rad.eps");

TCanvas *posDirC1 = new TCanvas();
posDirC1->SetLogz();
posDirCorrX->Draw("colz");
posDirC1->Print("posDir_X.eps");

TCanvas *posDirC2 = new TCanvas();
posDirC2->SetLogz();
posDirCorrY->Draw("colz");
posDirC2->Print("posDir_Y.eps");

TCanvas *posDirC3 = new TCanvas();
posDirC3->SetLogz();
posDirCorrZ->Draw("colz");
posDirC3->Print("posDir_Z.eps");

kpBirthX->GetXaxis()->SetTitle("x birth position (cm)");
kpBirthX->GetXaxis()->CenterTitle(1);
kpBirthY->GetXaxis()->SetTitle("y birth position (cm)");
kpBirthY->GetXaxis()->CenterTitle(1);
kpBirthZ->GetXaxis()->SetTitle("z birth position (cm)");
kpBirthZ->GetXaxis()->CenterTitle(1);

kpBirthX->SetLineWidth(2);
kpBirthY->SetLineWidth(2);
kpBirthZ->SetLineWidth(2);
pipBirthX->SetLineWidth(2);
pipBirthY->SetLineWidth(2);
pipBirthZ->SetLineWidth(2);
prBirthX->SetLineWidth(2);
prBirthY->SetLineWidth(2);
prBirthZ->SetLineWidth(2);
kpBirthX->SetLineColor(kBlue);
kpBirthY->SetLineColor(kBlue);
kpBirthZ->SetLineColor(kBlue);
pipBirthX->SetLineColor(kMagenta);
pipBirthY->SetLineColor(kMagenta);
pipBirthZ->SetLineColor(kMagenta);

TCanvas *parentX = new TCanvas();
kpBirthX->Draw();
pipBirthX->Draw("same");
prBirthX->Draw("same");
parentX->Print("parentX.eps");

TCanvas *parentY = new TCanvas();
kpBirthY->Draw();
pipBirthY->Draw("same");
prBirthY->Draw("same");
parentY->Print("parentY.eps");

TCanvas *parentZ = new TCanvas();
kpBirthZ->Draw();
pipBirthZ->Draw("same");
prBirthZ->Draw("same");
parentZ->Print("parentZ.eps");

px_fin_tot->GetXaxis()->SetTitle("post-focus px (GeV?)");
px_fin_tot->GetXaxis()->CenterTitle(1);
py_fin_tot->GetXaxis()->SetTitle("post-focus py (GeV?)");
py_fin_tot->GetXaxis()->CenterTitle(1);
pz_fin_tot->GetXaxis()->SetTitle("post-focus pz (GeV?)");
pz_fin_tot->GetXaxis()->CenterTitle(1);

TCanvas *px_finC = new TCanvas();
px_fin_tot->Draw();
px_fin_piP->Draw("same");
px_fin_kP->Draw("same");
px_finC->Print("parent_px_fin.eps");

TCanvas *py_finC = new TCanvas();
py_fin_tot->Draw();
py_fin_piP->Draw("same");
py_fin_kP->Draw("same");
py_finC->Print("parent_py_fin.eps");

TCanvas *pz_finC = new TCanvas();
pz_fin_tot->Draw();
pz_fin_piP->Draw("same");
pz_fin_kP->Draw("same");
pz_finC->Print("parent_pz_fin.eps");

prBirthPX->GetXaxis()->SetTitle("Momentum at birth X (GeV)");
prBirthPX->GetXaxis()->CenterTitle(1);

TCanvas *momBirthX = new TCanvas();
prBirthPX->Draw();
pipBirthPX->Draw("same");
kpBirthPX->Draw("same");
momBirthX->Print("parentMomAtBirth_x.eps");

prBirthPY->GetXaxis()->SetTitle("Momentum at birth Y (GeV)");
prBirthPY->GetXaxis()->CenterTitle(1);

TCanvas *momBirthY = new TCanvas();
prBirthPY->Draw();
pipBirthPY->Draw("same");
kpBirthPY->Draw("same");
momBirthY->Print("parentMomAtBirth_y.eps");

prBirthPZ->GetXaxis()->SetTitle("Momentum at birth Z (GeV)");
prBirthPZ->GetXaxis()->CenterTitle(1);

TCanvas *momBirthZ = new TCanvas();
prBirthPZ->Draw();
pipBirthPZ->Draw("same");
kpBirthPZ->Draw("same");
momBirthZ->Print("parentMomAtBirth_z.eps");

}
