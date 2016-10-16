#define outputTree_joe_cxx
#include "outputTree_joe.h"
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
bool testst = 0;

void outputTree_joe::Loop()
{

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

TGraph *tstamp_vs_batches;

TFile *batchFile = new TFile("n_batches.root");
batchFile->GetObject("tstamp_vs_batches",tstamp_vs_batches);

TH1D *numu_weights;
TH1D *numubar_weights;

// TFile *rewtFile = new TFile("numubarmode_weights_root4.root");//default
//rewtFile->GetObject("numu_weights",numu_weights);//default
//rewtFile->GetObject("numubar_weights",numubar_weights);//default

TFile *rewtFile = new TFile("numode_to_nubarmode_flux_and_weights_leo.root");//Leo
rewtFile->GetObject("numu_weights_leo",numu_weights);
rewtFile->GetObject("numubar_weights_leo",numubar_weights);

TH1D *numu_weights_dirt;
TH1D *numubar_weights_dirt;

TFile *rewtFileD = new TFile("numubarmode_weights_dirt_root4.root");
rewtFileD->GetObject("numu_weights_dirt",numu_weights_dirt);
rewtFileD->GetObject("numubar_weights_dirt",numubar_weights_dirt);

//int nModels = 11;
int nModels = 21;

TH1D *qsqRatios[nModels];
//TFile *qsqRatiosFile = new TFile("./numi_qsqRatios.root");
TFile *qsqRatiosFile = new TFile("./numi_numu_qsqRatios_below1.root");
for (int i=0; i<nModels; i++)
	qsqRatiosFile->GetObject(Form("ratio_qsq_%d",i),qsqRatios[i]);

TCanvas *qsqC = new TCanvas();
qsqRatios[0]->Draw();
for (int i=0; i<nModels; i++)
	qsqRatios[i]->Draw("same");
qsqC->Print("qsqRatios.eps");

TH1D *qsqRatios_nub[nModels];
TFile *qsqRatiosFileNub = new TFile("./numi_nubar_qsqRatios_below1.root");
//TFile *qsqRatiosFileNub = new TFile("./numi_nubar_qsqRatios.root");
for (int i=0; i<nModels; i++)
	qsqRatiosFileNub->GetObject(Form("ratio_qsq_%d",i),qsqRatios_nub[i]);

qsqRatios_nub[0]->SetMaximum(1.9);

for (int i=1; i<nModels; i++)
	qsqRatios_nub[i]->SetLineColor(i+1);

qsqRatios_nub[nModels-2]->SetLineColor(28);

TLegend *leg1 = new TLegend(0.748, 0.3097, 0.999, 0.996);
leg1->AddEntry(qsqRatios_nub[0],"nuance #kappa = 1.022", "l");
leg1->AddEntry(qsqRatios_nub[1],"nuance #kappa = 1.000", "l");
leg1->AddEntry(qsqRatios_nub[2],"nuance #kappa = 1.002", "l");
leg1->AddEntry(qsqRatios_nub[3],"nuance #kappa = 1.004", "l");
leg1->AddEntry(qsqRatios_nub[4],"nuance #kappa = 1.006", "l");
leg1->AddEntry(qsqRatios_nub[5],"nuance #kappa = 1.008", "l");
leg1->AddEntry(qsqRatios_nub[6],"nuance #kappa = 1.010", "l");
leg1->AddEntry(qsqRatios_nub[7],"nuance #kappa = 1.012", "l");
leg1->AddEntry(qsqRatios_nub[8],"nuance #kappa = 1.014", "l");
leg1->AddEntry(qsqRatios_nub[9],"nuance #kappa = 1.016", "l");
leg1->AddEntry(qsqRatios_nub[10],"nuance #kappa = 1.018", "l");
leg1->AddEntry(qsqRatios_nub[11],"nuance #kappa = 0.978", "l");
leg1->AddEntry(qsqRatios_nub[12],"nuance #kappa = 0.982", "l");
leg1->AddEntry(qsqRatios_nub[13],"nuance #kappa = 0.984", "l");
leg1->AddEntry(qsqRatios_nub[14],"nuance #kappa = 0.986", "l");
leg1->AddEntry(qsqRatios_nub[15],"nuance #kappa = 0.988", "l");
leg1->AddEntry(qsqRatios_nub[16],"nuance #kappa = 0.990", "l");
leg1->AddEntry(qsqRatios_nub[17],"nuance #kappa = 0.992", "l");
leg1->AddEntry(qsqRatios_nub[18],"nuance #kappa = 0.994", "l");
leg1->AddEntry(qsqRatios_nub[19],"nuance #kappa = 0.996", "l");
leg1->AddEntry(qsqRatios_nub[20],"nuance #kappa = 0.998", "l");
leg1->SetFillColor(0);
leg1->SetLineColor(1);
leg1->SetTextSize(0.03);

TH1F *sig_enu = new TH1F("sig_enu","",40,0,1.);
TH1F *sb_enu = new TH1F("sb_enu","",40,0,1.);

TH1F *sig_qsq = new TH1F("sig_qsq","",40,0,1);
TH1F *sb_qsq = new TH1F("sb_qsq","",40,0,1);

//gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);

qsqRatios_nub[0]->SetTitle("nubar mode numi flux ratios");
qsqRatios_nub[0]->SetMaximum(3);

TCanvas *qsqCn = new TCanvas();
qsqRatios_nub[0]->Draw();
for (int i=0; i<nModels; i++)
	qsqRatios_nub[i]->Draw("same");
leg1->Draw();
qsqCn->Print("qsqRatios_nubar.eps");
//qsqCn->Print("qsqRatios_nubar.png");

   TH1D *ratio_qsq = new TH1D("ratio_qsq","",40,0,2.0);

//MA = 1.23 for num, denom, num = k=1.000 denom = k=1.022
ratio_qsq->SetBinContent(1,2.50469);
ratio_qsq->SetBinContent(2,1.51688);
ratio_qsq->SetBinContent(3,1.28289);
ratio_qsq->SetBinContent(4,1.13591);
ratio_qsq->SetBinContent(5,1.01264);
ratio_qsq->SetBinContent(6,0.998408);
ratio_qsq->SetBinContent(7,1.01747);
ratio_qsq->SetBinContent(8,1.00786);
ratio_qsq->SetBinContent(9,1.02319);
ratio_qsq->SetBinContent(10,0.995663);
ratio_qsq->SetBinContent(11,1.0124);
ratio_qsq->SetBinContent(12,1.00897);
ratio_qsq->SetBinContent(13,1.00551);
ratio_qsq->SetBinContent(14,1.00192);
ratio_qsq->SetBinContent(15,0.983112);
ratio_qsq->SetBinContent(16,1.01369);
ratio_qsq->SetBinContent(17,1.03459);
ratio_qsq->SetBinContent(18,0.974109);
ratio_qsq->SetBinContent(19,0.91512);
ratio_qsq->SetBinContent(20,0.982891);
ratio_qsq->SetBinContent(21,1.01611);
ratio_qsq->SetBinContent(22,1.02873);
ratio_qsq->SetBinContent(23,0.954474);
ratio_qsq->SetBinContent(24,0.996774);
ratio_qsq->SetBinContent(25,0.963706);
ratio_qsq->SetBinContent(26,0.980527);
ratio_qsq->SetBinContent(27,1.00807);
ratio_qsq->SetBinContent(28,1.01668);
ratio_qsq->SetBinContent(29,0.994301);
ratio_qsq->SetBinContent(30,0.977138);
ratio_qsq->SetBinContent(31,0.912467);
ratio_qsq->SetBinContent(32,1.00847);
ratio_qsq->SetBinContent(33,1.1059);
ratio_qsq->SetBinContent(34,0.989974);
ratio_qsq->SetBinContent(35,0.926463);
ratio_qsq->SetBinContent(36,0.954666);
ratio_qsq->SetBinContent(37,1.11351);
ratio_qsq->SetBinContent(38,1.01712);
ratio_qsq->SetBinContent(39,0.978843);
ratio_qsq->SetBinContent(40,0.981277);

int nbins_qsq = qsqRatios[0]->GetNbinsX();

float fourSE_MC = 0;
float fourSE_data = 0;

float truEnu = 0;
float truEmu = 0;
float truTmu = 0;
float truEnu2 = 0;
float truMuPx = 0;
float truMuPy = 0;
float truMuPz = 0;
float truMuPx_dmp = 0;
float truMuPy_dmp = 0;
float truMuPz_dmp = 0;
float truMuP  = 0;
float truUX = 0;
float truUY = 0;
float truUZ = 0;
float theta_Xtru = 0;
float theta_Ytru = 0;
float theta_Ztru = 0;
float recoTheta;
float truQsq = 0.;
float threeMomDiff = 0.;
double wt[nModels];
for (int i=0; i<nModels; i++)
	wt[i] = 0.;
float Qsq = 0;
float EnuQE = 0;
float EnuQE2 = 0;
float Tmu = 0;
float Tmu_st = 0;
float Pmu = 0;
float CosThetamu = 0.;
float thetaMu = 0.;
float recoUX = 0.;
float recoUY = 0.;
float recoUZ = 0.;

float thetaX = 0.;
float thetaY = 0.;
float thetaZ = 0.;

float Mmu = 0.1056583;
float Mn = 0.93956;
float Mp = 0.93827;
float BE = 0.030;//diff in mass of final nucleus bet nu CCQE, nubar CCQE (34 for nu)
float Emu = 0;
float Emu2 = 0;
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

float dump_x = 0.407340799473745; 
float dump_y = 0.892864152217557;     
float dump_z = 0.192008017459985; 
float dump_angle_true = 0.;
float dump_angle_reco = 0.;
float dump_cosangle_true = 0.;
float dump_cosangle_reco = 0.;

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

float genR = 0.;

float scint = 0.;

float MichDist = 0;
float muRange = 0;
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

int numMCfiles = 1;
int numStrobeFiles = 2;//2
int numDirtFiles = 1;//1

int parent = 0;
bool sig = 0;

int startVal = 1251846498;
int endVal = 1320113469; 

TH1I *data_time = new TH1I("data_time","",1000,startVal,endVal);
TH1I *data_time_zm = new TH1I("data_time_zm","",1000,1293e6,1300e6);

int tmubins = 25;
double lasttmu = 0.25;

TH1F *spitzVar_recoMC = new TH1F("spitzVar_recoMC","",50,0,0.15);
TH1F *spitzVar_truMC = new TH1F("spitzVar_truMC","",50,0,0.15);
TH2F *spitzVar_tmuCorr_toy = new TH2F("spitzVar_tmuCorr_toy","",50,0,0.15,50,0,0.15);

TH2F *spitzVar_enuCorr = new TH2F("spitzVar_enuCorr","",100,0,1,100,0,3);

int nBins_unfold = 25;

TH1F *michels_data = new TH1F("michels_data","",100,0,200);
TH1F *michels_mc = new TH1F("michels_mc","",100,0,200);
TH1F *michels_dirt = new TH1F("michels_dirt","",100,0,200);
TH1F *michels_strobe = new TH1F("michels_strobe","",100,0,200);

TH1F *spitzVar_data = new TH1F("spitzVar_data","",nBins_unfold,0,0.15);
TH1F *spitzVar_data_largeRng = new TH1F("spitzVar_data_largeRng","",100,0,1.0);
TH1F *spitzVar_mc[nModels];
TH1F *spitzVar_mc_largeRng[nModels];
TH1F *spitzVar_pip[nModels];
TH1F *spitzVar_pim[nModels];
TH1F *spitzVar_kp[nModels];
TH1F *spitzVar_dirt[nModels];
TH1F *spitzVar_othr[nModels];

bool dospitz = 0;
double last = 0.;
int thitbins = 30;
if (dospitz)    last = 1.0;
if (dospitz==0) last = 300;
if (testst){

  last = 180.;
  thitbins = 30;

}

int thitbins_large = 100;
double last_large = 1200.;

if (testst){

thitbins_large = 100;
last_large = 1000;

}

int enuqebins = 100;
double last_enuqe = 3.;

TGraph *sigal_template_gr[nModels];
TGraph *tmu_mybinning_gr[nModels];

sigal_template_gr[0] = new TGraph("signal_template_kappa_1022.txt");
sigal_template_gr[1] = new TGraph("signal_template_kappa_1000.txt");
sigal_template_gr[2] = new TGraph("signal_template_kappa_1002.txt");
sigal_template_gr[3] = new TGraph("signal_template_kappa_1004.txt");
sigal_template_gr[4] = new TGraph("signal_template_kappa_1006.txt");
sigal_template_gr[5] = new TGraph("signal_template_kappa_1008.txt");
sigal_template_gr[6] = new TGraph("signal_template_kappa_1010.txt");
sigal_template_gr[7] = new TGraph("signal_template_kappa_1012.txt");
sigal_template_gr[8] = new TGraph("signal_template_kappa_1014.txt");
sigal_template_gr[9] = new TGraph("signal_template_kappa_1016.txt");
sigal_template_gr[10] = new TGraph("signal_template_kappa_1018.txt");
sigal_template_gr[11] = new TGraph("signal_template_kappa_0978.txt");
sigal_template_gr[12] = new TGraph("signal_template_kappa_0982.txt");
sigal_template_gr[13] = new TGraph("signal_template_kappa_0984.txt");
sigal_template_gr[14] = new TGraph("signal_template_kappa_0986.txt");
sigal_template_gr[15] = new TGraph("signal_template_kappa_0988.txt");
sigal_template_gr[16] = new TGraph("signal_template_kappa_0990.txt");
sigal_template_gr[17] = new TGraph("signal_template_kappa_0992.txt");
sigal_template_gr[18] = new TGraph("signal_template_kappa_0994.txt");
sigal_template_gr[19] = new TGraph("signal_template_kappa_0996.txt");
sigal_template_gr[20] = new TGraph("signal_template_kappa_0998.txt");

tmu_mybinning_gr[0] = new TGraph("tmu_kappa_1022.txt");
tmu_mybinning_gr[1] = new TGraph("tmu_kappa_1000.txt");
tmu_mybinning_gr[2] = new TGraph("tmu_kappa_1002.txt");
tmu_mybinning_gr[3] = new TGraph("tmu_kappa_1004.txt");
tmu_mybinning_gr[4] = new TGraph("tmu_kappa_1006.txt");
tmu_mybinning_gr[5] = new TGraph("tmu_kappa_1008.txt");
tmu_mybinning_gr[6] = new TGraph("tmu_kappa_1010.txt");
tmu_mybinning_gr[7] = new TGraph("tmu_kappa_1012.txt");
tmu_mybinning_gr[8] = new TGraph("tmu_kappa_1014.txt");
tmu_mybinning_gr[9] = new TGraph("tmu_kappa_1016.txt");
tmu_mybinning_gr[10] = new TGraph("tmu_kappa_1018.txt");
tmu_mybinning_gr[11] = new TGraph("tmu_kappa_0978.txt");
tmu_mybinning_gr[12] = new TGraph("tmu_kappa_0982.txt");
tmu_mybinning_gr[13] = new TGraph("tmu_kappa_0984.txt");
tmu_mybinning_gr[14] = new TGraph("tmu_kappa_0986.txt");
tmu_mybinning_gr[15] = new TGraph("tmu_kappa_0988.txt");
tmu_mybinning_gr[16] = new TGraph("tmu_kappa_0990.txt");
tmu_mybinning_gr[17] = new TGraph("tmu_kappa_0992.txt");
tmu_mybinning_gr[18] = new TGraph("tmu_kappa_0994.txt");
tmu_mybinning_gr[19] = new TGraph("tmu_kappa_0996.txt");
tmu_mybinning_gr[20] = new TGraph("tmu_kappa_0998.txt");

TH1F *signal_template[nModels];
TH1F *signal_tmu[nModels];

for (int i=0; i<nModels; i++){
  signal_template[i] = new TH1F(Form("sig_template_model_%d",i),"",thitbins,0.,last);
  for (int j=1; j<=sigal_template_gr[i]->GetN(); j++)
  	signal_template[i]->SetBinContent(j,sigal_template_gr[i]->GetY()[j-1]);
}

for (int i=0; i<nModels; i++){
  signal_tmu[i] = new TH1F(Form("signal_tmu_model_%d",i),"",tmubins,0.,lasttmu);
  for (int j=1; j<=tmu_mybinning_gr[i]->GetN(); j++)
  	signal_tmu[i]->SetBinContent(j,tmu_mybinning_gr[i]->GetY()[j-1]);
}

int nbins_time = 10;
double time_bounds[nbins_time+1];
time_bounds[0] = 2500.;
time_bounds[1] = 2700.;
time_bounds[2] = 2900.;
time_bounds[3] = 3100.;
time_bounds[4] = 3300.;
time_bounds[5] = 3500.;
time_bounds[6] = 3700.;
time_bounds[7] = 3900.;
time_bounds[8] = 4100.;
time_bounds[9] = 4300.;
time_bounds[10] = 4500.;
TH1F *thits_data_bins[nbins_time];
TH1F *thits_data_bins_lg[nbins_time];
for (int i=0; i<nbins_time; i++)
	thits_data_bins[i] = new TH1F(Form("thits_data_time_%d",i),"",thitbins,0,last);
for (int i=0; i<nbins_time; i++)
	thits_data_bins_lg[i] = new TH1F(Form("thits_data_time_lg_%d",i),"",thitbins_large,0,last_large);
TH1F *thits_data = new TH1F("thits_data","",thitbins,0,last);
TH1F *thits_mc[nModels];
TH1F *thits_nu[nModels];
TH1F *thits_nub[nModels];

int michbins = 50;
double last_mich = 1200.;

TH1F *mich_dist_data = new TH1F("mich_dist_data","",michbins,0,last_mich);
TH1F *mich_dist_mc[nModels];
TH1F *mich_dist_qe[nModels];
TH1F *mich_dist_pi[nModels];
TH1F *mich_dist_dirt[nModels];

TH1F *tru_tmu_mc[nModels];
TH1F *tru_tmu_nu[nModels];
TH1F *tru_tmu_nub[nModels];
TH1F *tru_tmu_dirt[nModels];

TH1F *tru_tmu_strobe = new TH1F("tru_tmu_strobe","",tmubins,0.,lasttmu);

TH1F *recoR_data = new TH1F("recoR_data","",50,0,700);
TH1F *recoR_dirt = new TH1F("recoR_dirt","",50,0,700);
TH1F *recoR_strobe = new TH1F("recoR_strobe","",50,0,700);

TH1F *thits_bkgsubt[nModels];

TH1F *enuqe_data = new TH1F("enuqe_data","",enuqebins,0.,last_enuqe);
TH1F *enuqe_mc[nModels];
TH1F *enuqe_nu[nModels];
TH1F *enuqe_nub[nModels];

TH1F *thits_data_largerng = new TH1F("thits_data_largerng","",thitbins_large,0,last_large);
TH1F *thits_strobe_largerng = new TH1F("thits_strobe_largerng","",thitbins_large,0,last_large);
TH1F *thits_mc_largerng[nModels];
TH1F *thits_nu_largerng[nModels];
TH1F *thits_nub_largerng[nModels];
TH1F *thits_dirt_largerng[nModels];

TH1F *tmu_mc_largerng[nModels];
TH1F *tmu_nu_largerng[nModels];
TH1F *tmu_nub_largerng[nModels];
TH1F *tmu_dirt_largerng[nModels];

int tmubins_large = 100;
double last_tmu_large = 2.;

TH1F *tmu_data_largerng = new TH1F("tmu_data_largerng","",tmubins_large,0.,last_tmu_large);
TH1F *tmu_strobe_largerng = new TH1F("tmu_strobe_largerng","",tmubins_large,0.,last_tmu_large);

TH1F *thits_pip[nModels];
TH1F *thits_pim[nModels];
TH1F *thits_kp[nModels];
TH1F *thits_dirt[nModels];
TH1F *thits_othr[nModels];

TH2F *truTmu_tHit1[nModels]; 

int tmu_bins_fold = 120;
double first_tmu = 0.;
double last_tmu = 120.;//MeV

TH2F *tru_tmu_tank_hits_fold[nModels];
TH1F *lt_120_tmu_gt_150_thits = new TH1F("lt_120_tmu_gt_150_thits","",800,0,800);

TH1F *thits_recoMC = new TH1F("thits_recoMC","",thitbins,0.,last);
TH1F *tmu_truMC = new TH1F("tmu_truMC","",tmubins,0,lasttmu);
TH2F *thits_tmuCorr_toy = new TH2F("thits_tmuCorr_toy","",tmubins,0,lasttmu,thitbins,0.,last);

TH1F *thits_recoMC_fold = new TH1F("thits_recoMC_fold","",thitbins,0.,last);
TH1F *tmu_truMC_fold = new TH1F("tmu_truMC_fold","",tmu_bins_fold,0.,last_tmu);
TH2F *thits_tmuCorr_toy_fold = new TH2F("thits_tmuCorr_toy_fold","",thitbins,0.,last,tmu_bins_fold,first_tmu,last_tmu);

for (int i=0; i<nModels; i++){
  spitzVar_mc[i] = new TH1F(Form("spitzVar_mc_%d",i),"",nBins_unfold,0,0.15);
  spitzVar_mc_largeRng[i] = new TH1F(Form("spitzVar_mc_largeRng_%d",i),"",100,0,1.0);
  spitzVar_pip[i] = new TH1F(Form("spitzVar_pip_%d",i),"",nBins_unfold,0,0.15);
  spitzVar_pim[i] = new TH1F(Form("spitzVar_pim_%d",i),"",nBins_unfold,0,0.15);
  spitzVar_kp[i] = new TH1F(Form("spitzVar_kp_%d",i),"",nBins_unfold,0,0.15);
  spitzVar_dirt[i] = new TH1F(Form("spitzVar_dirt_%d",i),"",nBins_unfold,0,0.15);
  spitzVar_othr[i] = new TH1F(Form("spitzVar_othr_%d",i),"",nBins_unfold,0,0.15);

  thits_mc[i] = new TH1F(Form("thits_mc_%d",i),"",thitbins,0,last);
  thits_bkgsubt[i] = new TH1F(Form("thits_bkgsubt_%d",i),"",thitbins,0,last);
  thits_mc_largerng[i] = new TH1F(Form("thits_mc_largerng_%d",i),"",thitbins_large,0,last_large);
  thits_nu_largerng[i] = new TH1F(Form("thits_nu_largerng_%d",i),"",thitbins_large,0,last_large);
  thits_nub_largerng[i] = new TH1F(Form("thits_nub_largerng_%d",i),"",thitbins_large,0,last_large);
  thits_dirt_largerng[i] = new TH1F(Form("thits_dirt_largerng_%d",i),"",thitbins_large,0,last_large);

  mich_dist_mc[i] = new TH1F(Form("mich_dist_mc_%d",i),"",michbins,0,last_mich);
  mich_dist_qe[i] = new TH1F(Form("mich_dist_qe_%d",i),"",michbins,0,last_mich);
  mich_dist_pi[i] = new TH1F(Form("mich_dist_pi_%d",i),"",michbins,0,last_mich);
  mich_dist_dirt[i] = new TH1F(Form("mich_dist_dirt_%d",i),"",michbins,0,last_mich);

  tmu_mc_largerng[i] = new TH1F(Form("tmu_mc_largerng_%d",i),"",tmubins_large,0.,last_tmu_large);
  tmu_nu_largerng[i] = new TH1F(Form("tmu_nu_largerng_%d",i),"",tmubins_large,0.,last_tmu_large);
  tmu_nub_largerng[i] = new TH1F(Form("tmu_nub_largerng_%d",i),"",tmubins_large,0.,last_tmu_large);
  tmu_dirt_largerng[i] = new TH1F(Form("tmu_dirt_largerng_%d",i),"",tmubins_large,0.,last_tmu_large);

  thits_nu[i] = new TH1F(Form("thits_nu_%d",i),"",thitbins,0,last);
  thits_nub[i] = new TH1F(Form("thits_nub_%d",i),"",thitbins,0,last);
  thits_pip[i] = new TH1F(Form("thits_pip_%d",i),"",thitbins,0,last);
  thits_pim[i] = new TH1F(Form("thits_pim_%d",i),"",thitbins,0,last);
  thits_kp[i] = new TH1F(Form("thits_kp_%d",i),"",thitbins,0,last);
  thits_dirt[i] = new TH1F(Form("thits_dirt_%d",i),"",thitbins,0,last);
  thits_othr[i] = new TH1F(Form("thits_othr_%d",i),"",thitbins,0,last);

  tru_tmu_mc[i] = new TH1F(Form("tru_tmu_mc_%d",i),"",tmubins,0.,lasttmu);
  tru_tmu_nu[i] = new TH1F(Form("tru_tmu_nu_%d",i),"",tmubins,0.,lasttmu);
  tru_tmu_nub[i] = new TH1F(Form("tru_tmu_nub_%d",i),"",tmubins,0.,lasttmu);
  tru_tmu_dirt[i] = new TH1F(Form("tru_tmu_dirt_%d",i),"",tmubins,0.,lasttmu);

  enuqe_mc[i] = new TH1F(Form("enuqe_mc_%d",i),"",enuqebins,0.,last_enuqe);
  enuqe_nu[i] = new TH1F(Form("enuqe_nu_%d",i),"",enuqebins,0.,last_enuqe);
  enuqe_nub[i] = new TH1F(Form("enuqe_nub_%d",i),"",enuqebins,0.,last_enuqe);

  truTmu_tHit1[i] = new TH2F(Form("truTmu_tHit1_%d",i),"",tmubins,0,lasttmu,thitbins,0,last);
  tru_tmu_tank_hits_fold[i] = new TH2F(Form("tru_tmu_tank_hit_fold_%d",i),"",thitbins,0,last,tmu_bins_fold,first_tmu,last_tmu);//keep tank hit bins like usual

}

TH1F *thits_dirtRng = new TH1F("thits_dirtRng","",100,0,1000);
TH1F *thits_strobeRng = new TH1F("thits_strobeRng","",100,0,1000);

TH1F *spitzVar_strobe = new TH1F("spitzVar_strobe","",nBins_unfold,0,0.15);
TH1F *thits_strobe = new TH1F("thits_strobe","",thitbins,0,last);
TH1F *mich_dist_strobe = new TH1F("mich_dist_strobe","",michbins,0,last_mich);

TH1F *scintVar_ccqe = new TH1F("scintVar_ccqe","",nBins_unfold,0,0.15);
TH1F *scintVar_nonqe = new TH1F("scintVar_nonqe","",nBins_unfold,0,0.15);

TH1F *spitzVar_dataRng = new TH1F("spitzVar_dataRng","",100,0,1.0);
TH1F *spitzVar_mcRng = new TH1F("spitzVar_mcRng","",100,0,1.0);
TH1F *spitzVar_pipRng = new TH1F("spitzVar_pipRng","",100,0,1.0);
TH1F *spitzVar_pimRng = new TH1F("spitzVar_pimRng","",100,0,1.0);
TH1F *spitzVar_kpRng = new TH1F("spitzVar_kpRng","",100,0,1.0);

TH1F *dirt_secSE = new TH1F("dirt_secSE","",100,0,200);
TH1F *strobe_secSE = new TH1F("strobe_secSE","",100,0,200);
TH1F *data_inbmp = new TH1F("data_inbmp","",100,0,200);
TH1F *data_outbmp = new TH1F("data_outbmp","",100,0,200);

TH1F *mc_inbmp = new TH1F("mc_inbmp","",100,0,200);
TH1F *mc_outbmp = new TH1F("mc_outbmp","",100,0,200);

TH1F *thits_dataRng = new TH1F("thits_dataRng","",100,0,1000);
TH1F *thits_mcRng = new TH1F("thits_mcRng","",100,0,1000);
TH1F *thits_pipRng = new TH1F("thits_pipRng","",100,0,1000);
TH1F *thits_pimRng = new TH1F("thits_pimRng","",100,0,1000);
TH1F *thits_kpRng = new TH1F("thits_kpRng","",100,0,1000);

TH1F *spitzVar_subt = new TH1F("spitzVar_subt","",nBins_unfold,0,0.15);
TH2F *spitzVar_tmuCorr_k1 = new TH2F("spitzVar_tmuCorr_k1","",nBins_unfold,0,0.15,nBins_unfold,0,0.15);
TH2F *spitzVar_tmuCorr_k1022 = new TH2F("spitzVar_tmuCorr_k1022","",nBins_unfold,0,0.15,nBins_unfold,0,0.15);
TH2F *spitzVar_tmuCorr_genie = new TH2F("spitzVar_tmuCorr_genie","",nBins_unfold,0,0.15,nBins_unfold,0,0.15);
TH2F *spitzVar_tmuCorr_martini = new TH2F("spitzVar_tmuCorr_martini","",nBins_unfold,0,0.15,nBins_unfold,0,0.15);
TH2F *spitzVar_tmuCorr_nuwro = new TH2F("spitzVar_tmuCorr_nuwro","",nBins_unfold,0,0.15,nBins_unfold,0,0.15);

TH2F *recoKdarKin = new TH2F("recoKdarKin","",40,0,TMath::Pi(),40,0,0.2);
TH2F *truKdarKin = new TH2F("truKdarKin","",40,0,TMath::Pi(),40,0,0.2);

TH1F *dirt_genR = new TH1F("dirt_genR","",100,0,1500);
TH1F *mc_genR = new TH1F("mc_genR","",100,0,1500);

TH1F *time_tot = new TH1F("time_tot","",80,0,20000);
TH1F *time_data = new TH1F("time_data","",80,0,20000);
TH1F *time_strobe = new TH1F("time_strobe","",80,0,20000);
TH1F *time_dirt = new TH1F("time_dirt","",80,0,20000);

TH1F *time_data_0 = new TH1F("time_data_0","",80,0,12000);
TH1F *time_data_1 = new TH1F("time_data_1","",80,0,12000);
TH1F *time_data_2 = new TH1F("time_data_2","",80,0,12000);
TH1F *time_data_3 = new TH1F("time_data_3","",80,0,12000);
TH1F *time_data_4 = new TH1F("time_data_4","",80,0,12000);
TH1F *time_data_5 = new TH1F("time_data_5","",80,0,12000);
TH1F *time_data_6 = new TH1F("time_data_6","",80,0,12000);
TH1F *time_data_tot = new TH1F("time_data_tot","",80,0,12000);

int bins_time_ratio = 100;
double last_time_ratio = 12000.;
double start_time = 0.;

TH1F *spitztime_in  = new TH1F("spitztime_in","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_mid = new TH1F("spitztime_mid","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_out = new TH1F("spitztime_out","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_tot = new TH1F("spitztime_tot","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_in_ratio  = new TH1F("spitztime_in_ratio","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_mid_ratio = new TH1F("spitztime_mid_ratio","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_out_ratio = new TH1F("spitztime_out_ratio","",bins_time_ratio,start_time,last_time_ratio);


TH1F *spitztime_in_5  = new TH1F("spitztime_in_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_mid_5 = new TH1F("spitztime_mid_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_out_5 = new TH1F("spitztime_out_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_tot_5 = new TH1F("spitztime_tot_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_in_ratio_5  = new TH1F("spitztime_in_ratio_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_mid_ratio_5 = new TH1F("spitztime_mid_ratio_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *spitztime_out_ratio_5 = new TH1F("spitztime_out_ratio_5","",bins_time_ratio,start_time,last_time_ratio);

TH1F *thits_late  = new TH1F("thits_late","",thitbins,0,last);
TH1F *thits_normal  = new TH1F("thits_normal","",thitbins,0,last);

int ncuts = 7;

TH1F *enuqe_tot_cuts[ncuts];
TH1F *enuqe_data_cuts[ncuts];
TH1F *enuqe_nu_cuts[ncuts];
TH1F *enuqe_nub_cuts[ncuts];
TH1F *enuqe_dirt_cuts[ncuts];
TH1F *enuqe_strobe_cuts[ncuts];

TH1F *thits_tot_cuts[ncuts];
TH1F *thits_data_cuts[ncuts];
TH1F *thits_dirt_cuts[ncuts];
TH1F *thits_nu_cuts[ncuts];
TH1F *thits_nub_cuts[ncuts];
TH1F *thits_strobe_cuts[ncuts];

for (int i=0; i<ncuts; i++){
	enuqe_tot_cuts[i] 	= new TH1F(Form("enuqe_tot_cuts_%d",i),"",100,0,1.);
	enuqe_nu_cuts[i] 	= new TH1F(Form("enuqe_nu_cuts_%d",i),"",100,0,1.);
	enuqe_nub_cuts[i] 	= new TH1F(Form("enuqe_nub_cuts_%d",i),"",100,0,1.);
	enuqe_data_cuts[i] 	= new TH1F(Form("enuqe_data_cuts_%d",i),"",100,0,1.);
        enuqe_strobe_cuts[i]    = new TH1F(Form("enuqe_strobe_cuts_%d",i),"",100,0,1.);
        enuqe_dirt_cuts[i]      = new TH1F(Form("enuqe_dirt_cuts_%d",i),"",100,0,1.);

	thits_tot_cuts[i] 	= new TH1F(Form("thits_tot_cuts_%d",i),"",thitbins,0,last);
	thits_nu_cuts[i] 	= new TH1F(Form("thits_nu_cuts_%d",i),"",thitbins,0,last);
	thits_nub_cuts[i] 	= new TH1F(Form("thits_nub_cuts_%d",i),"",thitbins,0,last);
        thits_strobe_cuts[i]    = new TH1F(Form("thits_strobe_cuts_%d",i),"",thitbins,0,last);
	thits_data_cuts[i] 	= new TH1F(Form("thits_data_cuts_%d",i),"",thitbins,0,last);
	thits_dirt_cuts[i] 	= new TH1F(Form("thits_dirt_cuts_%d",i),"",thitbins,0,last);
}

double nubarmode_rewt_nu = 0.;
double nubarmode_rewt_nubar = 0.;

double nubarmode_rewt_nu_dirt = 0.;
double nubarmode_rewt_nubar_dirt = 0.;

int nbins = 300;

double low_edge = 0.;
double up_edge = 0.;

TH1F *truEnu_tot_norewt = new TH1F("truEnu_tot_norewt","",nbins,0,3);
TH1F *truEnu_tot_rewt = new TH1F("truEnu_tot_rewt","",nbins,0,3);
TH1F *truEnu_tot_ratio = new TH1F("truEnu_tot_ratio","",nbins,0,3);

TH1F *truEnu_nu_norewt = new TH1F("truEnu_nu_norewt","",nbins,0,3);
TH1F *truEnu_nubar_norewt = new TH1F("truEnu_nubar_norewt","",nbins,0,3);

TH1F *truEnu_nu_rewt = new TH1F("truEnu_nu_rewt","",nbins,0,3);
TH1F *truEnu_nubar_rewt = new TH1F("truEnu_nubar_rewt","",nbins,0,3);

TH1F *tHits_tot_norewt = new TH1F("tHits_tot_norewt","",thitbins,0,last);
TH1F *tHits_tot_rewt = new TH1F("tHits_tot_rewt","",thitbins,0,last);
TH1F *tHits_tot_ratio = new TH1F("tHits_tot_ratio","",thitbins,0,last);

TH1F *tHits_data = new TH1F("tHits_data","",thitbins,0,last);

TH1F *tHits_nu_norewt = new TH1F("tHits_nu_norewt","",thitbins,0,last);
TH1F *tHits_nubar_norewt = new TH1F("tHits_nubar_norewt","",thitbins,0,last);

TH1F *tHits_nu_rewt = new TH1F("tHits_nu_rewt","",thitbins,0,last);
TH1F *tHits_nubar_rewt = new TH1F("tHits_nubar_rewt","",thitbins,0,last);

TH1F *truEnu_tot = new TH1F("truEnu_tot","",80,0,3);
TH1F *truEnu_kP = new TH1F("truEnu_kP","",80,0,4);
TH1F *truEnu_pM = new TH1F("truEnu_pM","",80,0,4);

TH1F *truEnu_numu = new TH1F("truEnu_numu","",300,0,3);
TH1F *truEnu_numubar = new TH1F("truEnu_numubar","",300,0,3);

TH1F *truEnu_sig = new TH1F("truEnu_sig","",80,0,4);
TH1F *truEnu_piP = new TH1F("truEnu_piP","",80,0,4);
TH1F *truEnu_kL = new TH1F("truEnu_kL","",80,0,4);

TH1F *truTmu_kP = new TH1F("truTmu_kP","",100,0,0.1);
TH1F *truTmu_piP = new TH1F("truTmu_piP","",100,0,0.1);
TH1F *truTmu_tot = new TH1F("truTmu_tot","",100,0,0.2);

TH1F *recTmu_kP = new TH1F("recTmu_kP","",80,0,0.2);
TH1F *recTmu_piP = new TH1F("recTmu_piP","",80,0,0.2);
TH1F *recTmu_tot = new TH1F("recTmu_tot","",80,0,0.2);
TH1F *recTmu_tot_nokdar = new TH1F("truTmu_rec_nokdar","",80,0,0.2);
TH1F *recTmu_sig = new TH1F("recTmu_sig","",80,0,0.2);
TH1F *recTmu_data = new TH1F("recTmu_data","",80,0,0.2);
TH1F *recTmu_strobe = new TH1F("recTmu_strobe","",80,0,0.2);

TH1F *truUZ_kP = new TH1F("truUZ_kP","",40,-1,1);
TH1F *truUZ_piP = new TH1F("truUZ_piP","",40,-1,1);
TH1F *truUZ_tot = new TH1F("truUZ_tot","",40,-1,1);

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

TH1F *truEnu_highthit = new TH1F("truEnu_highthit","",50,0,0.5);

TH1F *tHit1_noCut[nModels];
TH1F *tHit1_befMich[nModels];
TH1F *tHit1_wCut[nModels];
TH1F *tHit1_eff[nModels];
TH1F *tHit1_eff_incr_Mich[nModels];
TH1F *tmu_noCut[nModels];
TH1F *tmu_noCut_unfold[nModels];
TH1F *tmu_wCut_unfold[nModels];
TH1F *tmu_wCut[nModels];
TH1F *tmu_eff[nModels];
TH1F *tmu_eff_unfold[nModels];
TH1F *tmu_eff_josh[nModels];
TH1F *tmu_noCut_josh[nModels];
TH1F *tmu_wCut_josh[nModels];

for (int i=0; i<nModels; i++){
  tHit1_noCut[i] = new TH1F(Form("tHit1_noCut_%d",i),"",thitbins,0.,last);
  tHit1_befMich[i] = new TH1F(Form("tHit1_befMich_%d",i),"",thitbins,0.,last);
  tHit1_wCut[i]  = new TH1F(Form("tHit1_wCut_%d",i),"",thitbins,0.,last);
  tHit1_eff[i]   = new TH1F(Form("tHit1_eff_%d",i),"",thitbins,0.,last);
  tHit1_eff_incr_Mich[i]   = new TH1F(Form("tHit1_eff_incr_Mich_%d",i),"",thitbins,0.,last);
  tmu_noCut[i]   = new TH1F(Form("tmu_noCut_%d",i),"",tmu_bins_fold,first_tmu,last_tmu);
  tmu_wCut[i]   = new TH1F(Form("tmu_wCut_%d",i),"",tmu_bins_fold,first_tmu,last_tmu);
  tmu_noCut_josh[i]   = new TH1F(Form("tmu_noCut_josh_%d",i),"",100,0.,0.25);
  tmu_wCut_josh[i]   = new TH1F(Form("tmu_wCut_josh_%d",i),"",100,0.,0.25);
  tmu_noCut_unfold[i]   = new TH1F(Form("tmu_noCut_unfold_%d",i),"",tmubins,0.,lasttmu);
  tmu_wCut_unfold[i]   = new TH1F(Form("tmu_wCut_unfold_%d",i),"",tmubins,0.,lasttmu);

  tmu_eff_josh[i]   = new TH1F(Form("tmu_eff_josh_%d",i),"",100,0.,0.25);
  tmu_eff[i]   = new TH1F(Form("tmu_eff_%d",i),"",tmu_bins_fold,first_tmu,last_tmu);
  tmu_eff_unfold[i]   = new TH1F(Form("tmu_eff_unfold_%d",i),"",tmubins,0.,lasttmu);
}

TH1F *tHit1_kP = new TH1F("tHit1_kP","",100,0,200);
TH1F *tHit1_nc1pi = new TH1F("tHit1_nc1pi","",100,0,200);
TH1F *tHit1_ccqe = new TH1F("tHit1_ccqe","",100,0,200);
TH1F *tHit1_piP = new TH1F("tHit1_piP","",100,0,200);

TH1F *tHit1_tot = new TH1F("tHit1_tot","",thitbins,0.,last);
TH1F *tHit1_dirt = new TH1F("tHit1_dirt","",thitbins,0.,last);
TH1F *tHit1_strobe = new TH1F("tHit1_strobe","",thitbins,0.,last);

TH1F *tHit1_tot_nokdar = new TH1F("tHit1_tot_nokdar","",100,0,200);
TH1F *tHit1_data = new TH1F("tHit1_data","",100,0,200);
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

TH1F *tHit1_kPbig = new TH1F("tHit1_kPbig","",100,0,1500);
TH1F *tHit1_piPbig = new TH1F("tHit1_piPbig","",100,0,1500);
TH1F *tHit1_totBig = new TH1F("tHit1_totBig","",100,0,1500);
TH1F *tHit1_dataBig = new TH1F("tHit1_dataBig","",100,0,1500);

TH1F *truUY_kP = new TH1F("truUY_kP","",40,-1,1);
TH1F *truUY_piP = new TH1F("truUY_piP","",40,-1,1);
TH1F *truUY_tot = new TH1F("truUY_tot","",40,-1,1);

TH1F *recUY_kP = new TH1F("recUY_kP","",30,-1,1);
TH1F *recUY_piP = new TH1F("recUY_piP","",30,-1,1);
TH1F *recUY_pim = new TH1F("recUY_pim","",30,-1,1);
TH1F *recUY_othr = new TH1F("recUY_othr","",30,-1,1);
TH1F *recUY_dirt = new TH1F("recUY_dirt","",30,-1,1);
TH1F *recUY_tot = new TH1F("recUY_tot","",30,-1,1);
TH1F *recUY_data = new TH1F("recUY_data","",30,-1,1);
TH1F *recUY_strobe = new TH1F("recUY_strobe","",30,-1,1);

TH1F *recDmpCos_kP = new TH1F("recDmpCos_kP","",30,-1,1);
TH1F *recDmpCos_piP = new TH1F("recDmpCos_piP","",30,-1,1);
TH1F *recDmpCos_pim = new TH1F("recDmpCos_pim","",30,-1,1);
TH1F *recDmpCos_othr = new TH1F("recDmpCos_othr","",30,-1,1);
TH1F *recDmpCos_dirt = new TH1F("recDmpCos_dirt","",30,-1,1);
TH1F *recDmpCos_tot = new TH1F("recDmpCos_tot","",30,-1,1);
TH1F *recDmpCos_data = new TH1F("recDmpCos_data","",30,-1,1);
TH1F *recDmpCos_strobe = new TH1F("recDmpCos_strobe","",30,-1,1);
TH1F *recDmpCos_subt = new TH1F("recDmpCos_subt","",30,-1,1);

TH1F *thetaY_kP = new TH1F("thetaY_kP","",30,0,TMath::Pi());
TH1F *thetaY_piP = new TH1F("thetaY_piP","",30,0,TMath::Pi());
TH1F *thetaY_tot = new TH1F("thetaY_tot","",30,0,TMath::Pi());
TH1F *thetaY_dirt = new TH1F("thetaY_dirt","",30,0,TMath::Pi());
TH1F *thetaY_pim = new TH1F("thetaY_pim","",30,0,TMath::Pi());
TH1F *thetaY_othr = new TH1F("thetaY_othr","",30,0,TMath::Pi());
TH1F *thetaY_data = new TH1F("thetaY_data","",30,0,TMath::Pi());

TH1F *truUX_kP = new TH1F("truUX_kP","",40,-1,1);
TH1F *truUX_piP = new TH1F("truUX_piP","",40,-1,1);
TH1F *truUX_tot = new TH1F("truUX_tot","",40,-1,1);

TH1F *recUX_kP = new TH1F("recUX_kP","",30,-1,1);
TH1F *recUX_piP = new TH1F("recUX_piP","",30,-1,1);
TH1F *recUX_tot = new TH1F("recUX_tot","",30,-1,1);
TH1F *recUX_data = new TH1F("recUX_data","",30,-1,1);

TH1F *thetaX_kP = new TH1F("thetaX_kP","",30,0,TMath::Pi());
TH1F *thetaX_piP = new TH1F("thetaX_piP","",30,0,TMath::Pi());
TH1F *thetaX_tot = new TH1F("thetaX_tot","",30,0,TMath::Pi());
TH1F *thetaX_data = new TH1F("thetaX_data","",30,0,TMath::Pi());

TH2F *recoXZ_tot = new TH2F("recoXZ_tot","",15,-600,600,15,-600,600);
TH2F *recoXZ_dirt = new TH2F("recoXZ_dirt","",15,-600,600,15,-600,600);
TH2F *recoXZ_data = new TH2F("recoXZ_data","",15,-600,600,15,-600,600);

TH2F *recoXY_tot  = new TH2F("recoXY_tot","",15,-600,600,15,-600,600);
TH2F *recoXY_dirt = new TH2F("recoXY_dirt","",15,-600,600,15,-600,600);
TH2F *recoXY_data = new TH2F("recoXY_data","",15,-600,600,15,-600,600);

TH2F *recoYZ_tot = new TH2F("recoYZ_tot","",15,-600,600,15,-600,600);
TH2F *recoYZ_dirt = new TH2F("recoYZ_dirt","",15,-600,600,15,-600,600);
TH2F *recoYZ_data = new TH2F("recoYZ_data","",15,-600,600,15,-600,600);

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
TH1F *sig_truTmu = new TH1F("sig_truTmu","",100,0,0.1);
TH1F *sig_truTmuRng = new TH1F("sig_truTmuRng","",100,0,0.3);
TH1F *sig_truUZ = new TH1F("sig_truUZ","",40,-1,1);
TH1F *sig_truUY = new TH1F("sig_truUY","",40,-1,1);
TH1F *sig_truUX = new TH1F("sig_truUX","",40,-1,1);
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

TH1F *tDiff_islandA_mc = new TH1F("tDiff_islandA_mc","",100,0,5000);
TH1F *tDiff_islandA_data = new TH1F("tDiff_islandA_data","",100,0,5000);

TH1F *tDiff_islandB_mc = new TH1F("tDiff_islandB_mc","",100,0,5000);
TH1F *tDiff_islandB_data = new TH1F("tDiff_islandB_data","",100,0,5000);

TH1F *sig_rad = new TH1F("sig_rad","",100,0,40000);

TH1F *lk_2ndBump_tot = new TH1F("lk_2ndBump_tot","",40,-0.2,0.2);
TH1F *lk_2ndBump_dirt = new TH1F("lk_2ndBump_dirt","",40,-0.2,0.2);
TH1F *lk_2ndBump_data = new TH1F("lk_2ndBump_data","",40,-0.2,0.2);
TH1F *lk_2ndBump_ccqe = new TH1F("lk_2ndBump_ccqe","",40,-0.2,0.2);
TH1F *lk_2ndBump_ncpi = new TH1F("lk_2ndBump_ncpi","",40,-0.2,0.2);

TH1F *muLk_tot    = new TH1F("muLk_tot","",40,0,2);
TH1F *muLk_piP    = new TH1F("muLk_piP","",40,0,2);
TH1F *muLk_kP    = new TH1F("muLk_kP","",40,0,2);
TH1F *muLk_sig    = new TH1F("muLk_sig","",40,0,2);
TH1F *muLk_data   = new TH1F("muLk_data","",40,0,2);
TH1F *eLk_tot     = new TH1F("eLk_tot","",40,0,2);
TH1F *eLk_tot_2se = new TH1F("eLk_tot_2se","",40,0,2);
TH1F *eLk_data_2se = new TH1F("eLk_data_2se","",40,0,2);
TH1F *eLk_piP    = new TH1F("eLk_piP","",40,0,2);
TH1F *eLk_kP    = new TH1F("eLk_kP","",40,0,2);
TH1F *eLk_sig    = new TH1F("eLk_sig","",40,0,2);
TH1F *eLk_data    = new TH1F("eLk_data","",40,0,2);

TH1F *lk_tot_2se    = new TH1F("lk_tot_2se","",60,-0.2,2.0);
TH1F *lk_tot    = new TH1F("lk_tot","",40,-0.2,0.2);
TH1F *lk_strobe    = new TH1F("lk_strobe","",40,-0.2,0.2);
TH1F *lk_dirt    = new TH1F("lk_dirt","",40,-0.2,0.2);
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

TH1F *tHit1_cuts_dirt_0 = new TH1F("tHit1_cuts_dirt_0","",100,0,200);
TH1F *tHit1_cuts_dirt_1 = new TH1F("tHit1_cuts_dirt_1","",100,0,200);
TH1F *tHit1_cuts_dirt_2 = new TH1F("tHit1_cuts_dirt_2","",100,0,200);
TH1F *tHit1_cuts_dirt_3 = new TH1F("tHit1_cuts_dirt_3","",100,0,200);
TH1F *tHit1_cuts_dirt_4 = new TH1F("tHit1_cuts_dirt_4","",100,0,200);
TH1F *tHit1_cuts_dirt_5 = new TH1F("tHit1_cuts_dirt_5","",100,0,200);
TH1F *tHit1_cuts_dirt_6 = new TH1F("tHit1_cuts_dirt_6","",100,0,200);
TH1F *tHit1_cuts_dirt_7 = new TH1F("tHit1_cuts_dirt_7","",100,0,200);

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

TH1F *tHit1_cuts_pim_6 = new TH1F("tHit1_cuts_pim_6","",100,0,200);

TH1F *tHit1_cuts_kp_0 = new TH1F("tHit1_cuts_kp_0","",100,0,200);
TH1F *tHit1_cuts_kp_1 = new TH1F("tHit1_cuts_kp_1","",100,0,200);
TH1F *tHit1_cuts_kp_2 = new TH1F("tHit1_cuts_kp_2","",100,0,200);
TH1F *tHit1_cuts_kp_3 = new TH1F("tHit1_cuts_kp_3","",100,0,200);
TH1F *tHit1_cuts_kp_4 = new TH1F("tHit1_cuts_kp_4","",100,0,200);
TH1F *tHit1_cuts_kp_5 = new TH1F("tHit1_cuts_kp_5","",100,0,200);
TH1F *tHit1_cuts_kp_6 = new TH1F("tHit1_cuts_kp_6","",100,0,200);
TH1F *tHit1_cuts_kp_7 = new TH1F("tHit1_cuts_kp_7","",100,0,200);

TH1F *scint_cuts_data_0 = new TH1F("scint_cuts_data_0","",100,0,400);
TH1F *scint_cuts_data_1 = new TH1F("scint_cuts_data_1","",100,0,400);
TH1F *scint_cuts_data_2 = new TH1F("scint_cuts_data_2","",100,0,400);
TH1F *scint_cuts_data_3 = new TH1F("scint_cuts_data_3","",100,0,400);
TH1F *scint_cuts_data_4 = new TH1F("scint_cuts_data_4","",100,0,400);
TH1F *scint_cuts_data_5 = new TH1F("scint_cuts_data_5","",100,0,400);
TH1F *scint_cuts_data_6 = new TH1F("scint_cuts_data_6","",100,0,400);
TH1F *scint_cuts_data_7 = new TH1F("scint_cuts_data_7","",100,0,400);

TH1F *scint_cuts_mc_0 = new TH1F("scint_cuts_mc_0","",100,0,400);
TH1F *scint_cuts_mc_1 = new TH1F("scint_cuts_mc_1","",100,0,400);
TH1F *scint_cuts_mc_2 = new TH1F("scint_cuts_mc_2","",100,0,400);
TH1F *scint_cuts_mc_3 = new TH1F("scint_cuts_mc_3","",100,0,400);
TH1F *scint_cuts_mc_4 = new TH1F("scint_cuts_mc_4","",100,0,400);
TH1F *scint_cuts_mc_5 = new TH1F("scint_cuts_mc_5","",100,0,400);
TH1F *scint_cuts_mc_6 = new TH1F("scint_cuts_mc_6","",100,0,400);
TH1F *scint_cuts_mc_7 = new TH1F("scint_cuts_mc_7","",100,0,400);

TH1F *scint_cuts_dirt_0 = new TH1F("scint_cuts_dirt_0","",100,0,400);
TH1F *scint_cuts_dirt_1 = new TH1F("scint_cuts_dirt_1","",100,0,400);
TH1F *scint_cuts_dirt_2 = new TH1F("scint_cuts_dirt_2","",100,0,400);
TH1F *scint_cuts_dirt_3 = new TH1F("scint_cuts_dirt_3","",100,0,400);
TH1F *scint_cuts_dirt_4 = new TH1F("scint_cuts_dirt_4","",100,0,400);
TH1F *scint_cuts_dirt_5 = new TH1F("scint_cuts_dirt_5","",100,0,400);
TH1F *scint_cuts_dirt_6 = new TH1F("scint_cuts_dirt_6","",100,0,400);
TH1F *scint_cuts_dirt_7 = new TH1F("scint_cuts_dirt_7","",100,0,400);

TH1F *scint_cuts_kp_0 = new TH1F("scint_cuts_kp_0","",100,0,400);
TH1F *scint_cuts_kp_1 = new TH1F("scint_cuts_kp_1","",100,0,400);
TH1F *scint_cuts_kp_2 = new TH1F("scint_cuts_kp_2","",100,0,400);
TH1F *scint_cuts_kp_3 = new TH1F("scint_cuts_kp_3","",100,0,400);
TH1F *scint_cuts_kp_4 = new TH1F("scint_cuts_kp_4","",100,0,400);
TH1F *scint_cuts_kp_5 = new TH1F("scint_cuts_kp_5","",100,0,400);
TH1F *scint_cuts_kp_6 = new TH1F("scint_cuts_kp_6","",100,0,400);
TH1F *scint_cuts_kp_7 = new TH1F("scint_cuts_kp_7","",100,0,400);

TH1F *scint_cuts_kdar_0 = new TH1F("scint_cuts_kdar_0","",100,0,400);
TH1F *scint_cuts_kdar_1 = new TH1F("scint_cuts_kdar_1","",100,0,400);
TH1F *scint_cuts_kdar_2 = new TH1F("scint_cuts_kdar_2","",100,0,400);
TH1F *scint_cuts_kdar_3 = new TH1F("scint_cuts_kdar_3","",100,0,400);
TH1F *scint_cuts_kdar_4 = new TH1F("scint_cuts_kdar_4","",100,0,400);
TH1F *scint_cuts_kdar_5 = new TH1F("scint_cuts_kdar_5","",100,0,400);
TH1F *scint_cuts_kdar_6 = new TH1F("scint_cuts_kdar_6","",100,0,400);
TH1F *scint_cuts_kdar_7 = new TH1F("scint_cuts_kdar_7","",100,0,400);

TH1F *scint_cuts_strobe_0 = new TH1F("scint_cuts_strobe_0","",100,0,400);
TH1F *scint_cuts_strobe_1 = new TH1F("scint_cuts_strobe_1","",100,0,400);
TH1F *scint_cuts_strobe_2 = new TH1F("scint_cuts_strobe_2","",100,0,400);
TH1F *scint_cuts_strobe_3 = new TH1F("scint_cuts_strobe_3","",100,0,400);
TH1F *scint_cuts_strobe_4 = new TH1F("scint_cuts_strobe_4","",100,0,400);
TH1F *scint_cuts_strobe_5 = new TH1F("scint_cuts_strobe_5","",100,0,400);
TH1F *scint_cuts_strobe_6 = new TH1F("scint_cuts_strobe_6","",100,0,400);
TH1F *scint_cuts_strobe_7 = new TH1F("scint_cuts_strobe_7","",100,0,400);

TH1F *enu_ccqeBkg = new TH1F("enu_ccqeBkg","",200,0,10.0);

TH1F *scint_cuts_pip_0 = new TH1F("scint_cuts_pip_0","",100,0,400);
TH1F *scint_cuts_pip_1 = new TH1F("scint_cuts_pip_1","",100,0,400);
TH1F *scint_cuts_pip_2 = new TH1F("scint_cuts_pip_2","",100,0,400);
TH1F *scint_cuts_pip_3 = new TH1F("scint_cuts_pip_3","",100,0,400);
TH1F *scint_cuts_pip_4 = new TH1F("scint_cuts_pip_4","",100,0,400);
TH1F *scint_cuts_pip_5 = new TH1F("scint_cuts_pip_5","",100,0,400);
TH1F *scint_cuts_pip_6 = new TH1F("scint_cuts_pip_6","",100,0,400);
TH1F *scint_cuts_pip_7 = new TH1F("scint_cuts_pip_7","",100,0,400);

TH1F *chans = new TH1F("chans","",100,0.5,100.5);
TH1F *chans_sig_nu = new TH1F("chans_sig_nu","",100,0.5,100.5);
TH1F *chans_sig_nub = new TH1F("chans_sig_nub","",100,0.5,100.5);
TH1F *chans_sig_dirt_nu = new TH1F("chans_sig_dirt_nu","",100,0.5,100.5);
TH1F *chans_sig_dirt_nub = new TH1F("chans_sig_dirt_nub","",100,0.5,100.5);

TH1F *nuEnrgy_tmuSpike = new TH1F("nuEnrgy_tmuSpike","",100,0,0.6);

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

  bool useRewt = 0;

  double kRewt[10000];

  while (!feof(file)){

    fscanf (file, "%f %f", &energy, &val);
    //cout<<" energy "<<energy<<" val "<<val<<endl;
    kRewt[(int)energy-1] = val;

  }
//return;

kRewt[9999] = 1;

double tmuRewt[10000];

  int binNo = 0;

  TH1F *newTmuModel_martini = new TH1F("newTmuModel_martini","",150,0,0.15);
  TH1F *newTmuModel_genie = new TH1F("newTmuModel_genie","",150,0,0.15);
  TH1F *newTmuModel_nuwro = new TH1F("newTmuModel_nuwro","",150,0,0.15);
  TH1F *newTmuModel_k1    = new TH1F("newTmuModel_k1","",150,0,0.15);
  TH1F *newTmuModel_k1022 = new TH1F("newTmuModel_k1022","",150,0,0.15);
  TH1F *defModel = new TH1F("defModel","",50,0,0.15);
  TH1F *defModel_k1 = new TH1F("defModel_k1","",50,0,0.15);
  TH1F *defModel_k1022 = new TH1F("defModel_k1022","",50,0,0.15);
  TH1F *defModel_martini = new TH1F("defModel_martini","",50,0,0.15);
  TH1F *defModel_genie = new TH1F("defModel_genie","",50,0,0.15);
  TH1F *defModel_nuwro = new TH1F("defModel_nuwro","",50,0,0.15);

  TH1F *recoSpitzVar = new TH1F("recoSpitzVar","",nBins_unfold,0,0.15);
  TH1F *recoSpitzVar_k1 = new TH1F("recoSpitzVar_k1","",nBins_unfold,0,0.15);
  TH1F *recoSpitzVar_k1022 = new TH1F("recoSpitzVar_k1022","",nBins_unfold,0,0.15);
  TH1F *recoSpitzVar_martini = new TH1F("recoSpitzVar_martini","",nBins_unfold,0,0.15);
  TH1F *recoSpitzVar_genie = new TH1F("recoSpitzVar_genie","",nBins_unfold,0,0.15);
  TH1F *recoSpitzVar_nuwro = new TH1F("recoSpitzVar_nuwro","",nBins_unfold,0,0.15);

  for (int i=1; i<150; i++){
    newTmuModel_k1->SetBinContent(i,0.);
    newTmuModel_k1022->SetBinContent(i,0.);
    newTmuModel_martini->SetBinContent(i,0.);
    newTmuModel_genie->SetBinContent(i,0.);
    newTmuModel_nuwro->SetBinContent(i,0.);
  }

  FILE* file2;
  char *fileName3;
  fileName3 = "tmu_k1000.txt";
  file2 = fopen(fileName3,"r");

  while (!feof(file2)){

    fscanf (file2, "%d %f", &binNo, &val);
    //cout<<" binNo "<<binNo<<" val "<<val<<endl;

    newTmuModel_k1->SetBinContent(binNo,val);

  }


  FILE* file3;
  char *fileName4;
  fileName4 = "tmu_k1022.txt";
  file3 = fopen(fileName4,"r");

  while (!feof(file3)){

    fscanf (file3, "%d %f", &binNo, &val);
    //cout<<" binNo "<<binNo<<" val "<<val<<endl;

    newTmuModel_k1022->SetBinContent(binNo,val);

  }

  FILE* file4;
  char *fileName5;
  fileName5 = "tmu_martini.txt";
  file4 = fopen(fileName5,"r");

  while (!feof(file4)){
    fscanf (file4, "%d %f", &binNo, &val);
    //cout<<" binNo "<<binNo<<" val "<<val<<endl;
    newTmuModel_martini->SetBinContent(binNo,val);
  }

  FILE* file5;
  char *fileName6;
  fileName6 = "tmu_genie.txt";
  file5 = fopen(fileName6,"r");

  while (!feof(file5)){
    fscanf (file5, "%d %f", &binNo, &val);
    //cout<<" binNo "<<binNo<<" val "<<val<<endl;
    newTmuModel_genie->SetBinContent(binNo,val);
  }

  FILE* file6;
  char *fileName7;
  fileName7 = "tmu_nuwro.txt";
  file6 = fopen(fileName7,"r");

  while (!feof(file6)){
    fscanf (file6, "%d %f", &binNo, &val);
    //cout<<" binNo "<<binNo<<" val "<<val<<endl;
    newTmuModel_nuwro->SetBinContent(binNo,val);
  }


newTmuModel_k1->Rebin(3);
newTmuModel_k1022->Rebin(3);
newTmuModel_martini->Rebin(3);
newTmuModel_genie->Rebin(3);
newTmuModel_nuwro->Rebin(3);

newTmuModel_k1->SetLineWidth(2);
newTmuModel_k1022->SetLineWidth(2);
newTmuModel_k1022->SetLineColor(kRed);
newTmuModel_martini->SetLineWidth(2);
newTmuModel_martini->SetLineColor(kBlue);
newTmuModel_genie->SetLineWidth(2);
newTmuModel_genie->SetLineColor(kCyan);
newTmuModel_nuwro->SetLineWidth(2);
newTmuModel_nuwro->SetLineColor(kGreen);

recoSpitzVar_k1->SetLineWidth(2);
recoSpitzVar_k1022->SetLineWidth(2);
recoSpitzVar_k1022->SetLineColor(kRed);
recoSpitzVar_martini->SetLineWidth(2);
recoSpitzVar_martini->SetLineColor(kBlue);
recoSpitzVar_genie->SetLineWidth(2);
recoSpitzVar_genie->SetLineColor(kCyan);
recoSpitzVar_nuwro->SetLineWidth(2);
recoSpitzVar_nuwro->SetLineColor(kGreen);

newTmuModel_k1->SetMaximum(newTmuModel_k1022->GetMaximum()*1.1);

newTmuModel_k1->SetTitle("model comparison; T_{#mu} (GeV); normalized to unity");

//gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);
gStyle->SetPalette(1);

TLegend *leg222 = new TLegend(0.748, 0.7097, 0.999, 0.996);
leg222->AddEntry(newTmuModel_k1,"nuance #kappa = 1.", "l");
leg222->AddEntry(newTmuModel_k1022,"nuance #kappa = 1.022", "l");
leg222->AddEntry(newTmuModel_genie,"genie", "l");
leg222->AddEntry(newTmuModel_martini,"Martini", "l");
leg222->AddEntry(newTmuModel_nuwro,"Nuwro", "l");
leg222->SetFillColor(0);
leg222->SetLineColor(0);
leg222->SetTextSize(0.03);

TCanvas *c22 = new TCanvas();
newTmuModel_k1->Draw();
newTmuModel_k1022->Draw("same");
newTmuModel_martini->Draw("same");
newTmuModel_genie->Draw("same");
newTmuModel_nuwro->Draw("same");
leg222->Draw();
c22->Print("modelComps.eps");

double pipKdarBinEvnts = 0.;
double sigCnt = 0.;
int dataCnt = 0;
int mcCnt = 0;
double sigWt = 4.919*2-5;// = 13371/2718 * 2
//double sigWt = 0;// = 13371/2718 * 2
double mcWt = 1;// = 105988/2742 * 2

TF1 *tmuRewtFit;

TFile *file1 = new TFile("rewtPol10.root");
file1->GetObject("rewtFit",tmuRewtFit);

TH1F *tmuRewtVals_k1;
TH1F *tmuRewtVals_k1022;
TH1F *tmuRewtVals_genie;
TH1F *tmuRewtVals_nuwro;
TH1F *tmuRewtVals_martini;
TFile *rewtFile2 = new TFile("tmuRewtHists.root");
rewtFile2->GetObject("tmuRewtHist_k1",tmuRewtVals_k1);
rewtFile2->GetObject("tmuRewtHist_k1022",tmuRewtVals_k1022);
rewtFile2->GetObject("tmuRewtHist_martini",tmuRewtVals_martini);
rewtFile2->GetObject("tmuRewtHist_genie",tmuRewtVals_genie);
rewtFile2->GetObject("tmuRewtHist_nuwro",tmuRewtVals_nuwro);

TH1F *spitzVarPred_k1;
TH1F *spitzVarPred_k1022;
TH1F *spitzVarPred_genie;
TH1F *spitzVarPred_martini;
TH1F *spitzVarPred_nuwro;

TFile *spitzVarModelz = new TFile("recoModelComps_unityScale.root");
spitzVarModelz->GetObject("recoSpitzVar_k1",spitzVarPred_k1);
spitzVarModelz->GetObject("recoSpitzVar_k1022",spitzVarPred_k1022);
spitzVarModelz->GetObject("recoSpitzVar_genie",spitzVarPred_genie);
spitzVarModelz->GetObject("recoSpitzVar_martini",spitzVarPred_martini);
spitzVarModelz->GetObject("recoSpitzVar_nuwro",spitzVarPred_nuwro);

tmuRewtVals_k1->SetLineWidth(2);
tmuRewtVals_k1022->SetLineWidth(2);
tmuRewtVals_martini->SetLineWidth(2);
tmuRewtVals_nuwro->SetLineWidth(2);
tmuRewtVals_genie->SetLineWidth(2);
tmuRewtVals_k1022->SetLineColor(kRed);
tmuRewtVals_genie->SetLineColor(kCyan);
tmuRewtVals_martini->SetLineColor(kBlue);
tmuRewtVals_nuwro->SetLineColor(kGreen);

tmuRewtVals_k1->SetTitle("; T_{#mu} (GeV); reweight value");
tmuRewtVals_k1->SetMaximum(tmuRewtVals_k1022->GetMaximum()*1.1);

TCanvas *c222 = new TCanvas();
tmuRewtVals_k1->Draw();
tmuRewtVals_k1022->Draw("same");
tmuRewtVals_martini->Draw("same");
tmuRewtVals_nuwro->Draw("same");
tmuRewtVals_genie->Draw("same");
leg222->Draw();
c222->Print("rewtDists.eps");

int nRewtBins = 50;

float rewtBins[nRewtBins + 1];
float rewtVal_k1[nRewtBins];
float rewtVal_k1022[nRewtBins];
float rewtVal_martini[nRewtBins];
float rewtVal_genie[nRewtBins];
float rewtVal_nuwro[nRewtBins];
float modelRewt_k1 = 0.;
float modelRewt_k1022 = 0.;
float modelRewt_martini = 0.;
float modelRewt_genie = 0.;
float modelRewt_nuwro = 0.;

int success_ctr = 0;
int total_ctr = 0;
int det_tstamp = 0;
int leap_sec_offset = 15;
int prev_det_tstamp = 0;
int n_batches = 0;

TH1I *time_bet_events = new TH1I("time_bet_events","",10,0,10);

double tank_rms_time = 0.;

for (int i=0; i<=nRewtBins; i++){
   rewtBins[i] = 0.;
   rewtBins[i] = 0.003 * i;
   //cout<<" i is "<<i<<" rewtBins[i] is "<<rewtBins[i]<<endl; 
}

for (int i=0; i<nRewtBins; i++){
  rewtVal_k1[i] = 0;
  rewtVal_k1022[i] = 0;
  rewtVal_martini[i] = 0;
  rewtVal_genie[i] = 0;
  rewtVal_nuwro[i] = 0;
}
for (int i=1; i<=nRewtBins; i++){
  rewtVal_k1[i-1] = tmuRewtVals_k1->GetBinContent(i);
  rewtVal_k1022[i-1] = tmuRewtVals_k1022->GetBinContent(i);
  rewtVal_martini[i-1] = tmuRewtVals_martini->GetBinContent(i);
  rewtVal_genie[i-1] = tmuRewtVals_genie->GetBinContent(i);
  rewtVal_nuwro[i-1] = tmuRewtVals_nuwro->GetBinContent(i);
}
float vHitz[10];
for (int i=0; i<=10; i++) vHitz[i] = 0;

int datactr = 0;

//TCanvas *gifC = new TCanvas();
TFile *newfile = new TFile("timing_study/numi_nubar_data_for_timing_five_batches_only.root","recreate");
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

        tank_rms_time = 0.;
        tank_rms_time = mysplitEvent_rmsTimeTank[0];

        tDiff = 0.;
        tDiff = mysplitEvent_aveTimeTank[1] - mysplitEvent_aveTimeTank[0];

        beamAveTimeOT = 0;
        beamAveTimeOT = myRecoOneTrkMu_time[0];
 
        tHits_1SE = 0;
		if (dospitz) 	tHits_1SE = (1.5*mysplitEvent_nTankHits[0]/1000.)+.17;
		if (dospitz==0) tHits_1SE = mysplitEvent_nTankHits[0];

        //hacky stancu fitter test
        if (testst) tHits_1SE = myStFull_energy[0];

        tHits_2SE = 0;
        tHits_2SE = mysplitEvent_nTankHits[1];
	
		stVertx = 0;
		stVertx = sqrt(pow(myStFull_vertex_x[0],2) + pow(myStFull_vertex_y[0],2) + pow(myStFull_vertex_z[0],2));

        truEnu = 0;
        truEnu = myMCEvent_pNu_E[0];

        truMuPx = 0;
        truMuPx = myMCParticle_p_x[0];//array [0] points to FS lepton - mu/e for CC, numu/nue for NC

        truMuPy = 0;
        truMuPy = myMCParticle_p_y[0];

        truMuPz = 0;
        truMuPz = myMCParticle_p_z[0];

        truMuPx_dmp = 0;
        truMuPx_dmp = myMCParticle_p_x[0]*dump_x;

        truMuPy_dmp = 0;
        truMuPy_dmp = myMCParticle_p_y[0]*dump_x;

        truMuPz_dmp = 0;
        truMuPz_dmp = myMCParticle_p_z[0]*dump_x;

        muX = 0;
        muX = myTransRFull_trans_vertex_x[0];

        muY = 0;
        muY = myTransRFull_trans_vertex_y[0];

        muZ = 0;
        muZ = myTransRFull_trans_vertex_z[0];

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

        dump_cosangle_reco = 0.;
        dump_cosangle_reco = myRecoOneTrkMu_ux[0]*dump_x+myRecoOneTrkMu_uy[0]*dump_y+myRecoOneTrkMu_uz[0]*dump_z;

        dump_angle_reco = 0.;
        dump_angle_reco = acos(dump_cosangle_reco);

        recoUY = 0;
        recoUY = myRecoOneTrkMu_uy[0];

        CosThetamu = 0;
        //CosThetamu = acos(myRecoOneTrkMu_uz[0]);
        CosThetamu = myRecoOneTrkMu_uz[0];
        
        thetaMu = 0.;
        thetaMu = acos(CosThetamu);

        thetaX = 0.;
        thetaX = acos(myRecoOneTrkMu_ux[0]);

        thetaY = 0.;
        thetaY = acos(myRecoOneTrkMu_uy[0]);

        thetaZ = 0.;
        thetaZ = acos(myRecoOneTrkMu_uz[0]);          
        
        recoUZ = 0.;
        recoUZ = myRecoOneTrkMu_uz[0];
        

        truMuP = 0;
        truMuP = sqrt(pow(truMuPx,2) + pow(truMuPy,2) + pow(truMuPz,2));

        parent = 0;
        parent = myMCParent_geantID[1];

        /*
        if (useRewt) mcWt = 1 * kRewt[(int)(truEnu*1000)];
        else mcWt = 1;

        if (fCurrent==0){
          if (useRewt) mcWt = sigWt * kRewt[(int)(truEnu*1000)];
          else mcWt = sigWt;
        }        
        */

        //if (fCurrent==0) mcWt = 0.;

        genR = 0.;
        genR = myMCParticle_ver_mag[0];

        //cout<<" parent is "<<parent<<endl;

        truEmu = 0;
        truEmu = sqrt(pow(truMuP,2) + pow(Mmu,2));//don't use _p_E[0]! (energy truth info) - formed assuming massless particle! use instead 3-mom and mass 

        truTmu = 0;
        truTmu = truEmu - Mmu;

        sigWt = 4.919*2-5;
        //if (truTmu>0.008) sigWt *= (float)tmuRewtFit->Eval(truTmu);
        //else sigWt = 0.;

        //if (truTmu>0.1) sigWt = 0.;

        //if (truTmu>0.008) 
        //cout<<"sigWt before is "<<sigWt<<endl;
        //sigWt *= (float)tmuRewtFit->Eval(truTmu);
        //cout<<"sigWt after is "<<sigWt<<endl;
        //else sigWt = 0.;

        modelRewt_k1 = 0.;
        modelRewt_k1022 = 0.;
        modelRewt_martini = 0.;
        modelRewt_nuwro = 0.;
        modelRewt_genie = 0.;
        for (int i=1; i<=nRewtBins; i++){
          if ((truTmu > rewtBins[i-1]) && (truTmu < rewtBins[i])){
             modelRewt_k1      = rewtVal_k1[i-1];
             modelRewt_k1022   = rewtVal_k1022[i-1];
             modelRewt_martini = rewtVal_martini[i-1];
             modelRewt_genie   = rewtVal_genie[i-1];
             modelRewt_nuwro   = rewtVal_nuwro[i-1];
          }
        }

		nubarmode_rewt_nu = 0.;
		for (int i=1; i<=numu_weights->GetNbinsX(); i++){
		    up_edge = 0.;
		    low_edge = numu_weights->GetXaxis()->GetBinLowEdge(i);

		    up_edge = 0.;
		    up_edge = numu_weights->GetXaxis()->GetBinUpEdge(i);
		    
			if (truEnu > low_edge && truEnu < up_edge) 
				nubarmode_rewt_nu = numu_weights->GetBinContent(i); 
		
		}

		nubarmode_rewt_nubar = 0.;
		
		for (int i=1; i<=numubar_weights->GetNbinsX(); i++){
		    low_edge = 0.;
		    low_edge = numubar_weights->GetXaxis()->GetBinLowEdge(i);
		    
		    up_edge = 0.;
		    up_edge = numubar_weights->GetXaxis()->GetBinUpEdge(i);
		    
			if (truEnu > low_edge && truEnu < up_edge) 
				nubarmode_rewt_nubar = numubar_weights->GetBinContent(i); 
		
		}


		nubarmode_rewt_nu_dirt = 0.;
		for (int i=1; i<=numu_weights_dirt->GetNbinsX(); i++){
		    up_edge = 0.;
		    low_edge = numu_weights_dirt->GetXaxis()->GetBinLowEdge(i);

		    up_edge = 0.;
		    up_edge = numu_weights_dirt->GetXaxis()->GetBinUpEdge(i);
		    
			if (truEnu > low_edge && truEnu < up_edge) 
				nubarmode_rewt_nu_dirt = numu_weights_dirt->GetBinContent(i); 
		
		}

		nubarmode_rewt_nubar_dirt = 0.;
		
		for (int i=1; i<=numubar_weights_dirt->GetNbinsX(); i++){
		    low_edge = 0.;
		    low_edge = numubar_weights_dirt->GetXaxis()->GetBinLowEdge(i);
		    
		    up_edge = 0.;
		    up_edge = numubar_weights_dirt->GetXaxis()->GetBinUpEdge(i);
		    
			if (truEnu > low_edge && truEnu < up_edge) 
				nubarmode_rewt_nubar_dirt = numubar_weights_dirt->GetBinContent(i); 
		
		}

        //cout<<" truEnu is "<<truEnu<<" nu wt is "<<nubarmode_rewt_nu<<" nubar wt is "<<nubarmode_rewt_nubar<<endl;

        //cout<<" truTmu is "<<truTmu<<" rewt is "<<modelRewt_k1<<endl;

        Range = 0;
        Range = pow(pow(muX - elX,2) + pow(muY - elY,2) + pow(muZ - elZ,2),0.5);

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

        Emu2 = 0;
        Emu2 = ((1.1*tHits_1SE) / 1000) + Mmu;

        Pmu = 0;
        Pmu = pow(pow(Emu,2) - pow(Mmu,2),0.5);

		Tmu = 0;
		Tmu = (myRecoOneTrkMu_energy[0]) / 1000;

		Tmu_st = 0;
		Tmu_st = myStFull_energy_mu[0] / 1000.;
	
		muRange = 0;
        muRange = 533.3 * Tmu_st;//from linear fit to boodb table
	
		MichDist = 0;
        MichDist = pow(pow(myStFull_vertex_x[0] + muRange * muUX/2 - elX,2) + pow(myStFull_vertex_y[0] + muRange * muUY/2 - elY,2) + pow(myStFull_vertex_z[0] + muRange * muUZ/2 - elZ,2),0.5);

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

        dump_cosangle_true = 0.;
        dump_cosangle_true = truMuPy_dmp/truMuP;

        dump_angle_true = 0.;
        dump_angle_true = acos(truMuPy_dmp/truMuP);

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

        EnuQE2 = 0;
        EnuQE2 = 0.5 * (2 * (Mp - BE) * Emu2 - (pow(Mp,2) - pow(Mn,2) - 2 * Mp * BE + pow(BE,2) + pow(Mmu,2))) / (Mp - BE - Emu + Pmu * CosThetamu);

        truEnuQE = 0.;
        truEnuQE = 0.5 * (2 * (Mp - BE) * truEmu - (pow(Mp,2) - pow(Mn,2) - 2 * Mp * BE + pow(BE,2) + pow(Mmu,2))) / (Mp - BE - Emu + truMuP * truUZ);

        Qsq = 0;
        Qsq = 2 * EnuQE * (Emu - Pmu * CosThetamu) - pow(Mmu,2);        

        threeMomDiff = 0.;
        threeMomDiff = pow(myMCParticle_p_x[0]-myMCEvent_pNu_x[0],2)+pow(myMCParticle_p_y[0]-myMCEvent_pNu_y[0],2)+pow(myMCParticle_p_z[0]-myMCEvent_pNu_z[0],2);

        truQsq = 0.;
        truQsq = -pow(truEmu - truEnu,2)+threeMomDiff;

        for (int i=0; i<nModels; i++) wt[i] = 1.;

        //numu kappa weights.  done for nu-mode flux!  (I think that's fine)
        if (fCurrent< numMCfiles){
          if (nuType==1&&CCQE){
            for (int i=1; i<=nbins_qsq; i++){
             if (truQsq>qsqRatios[0]->GetXaxis()->GetBinLowEdge(i)&&truQsq<=qsqRatios[0]->GetXaxis()->GetBinUpEdge(i)) 
         	  for (int j=0; j<nModels; j++) wt[j] = qsqRatios[j]->GetBinContent(i)*nubarmode_rewt_nu;
            }
          }

          if (nuType==2&&CCQE){
            for (int i=1; i<=nbins_qsq; i++){
          
            low_edge = 0.;
            low_edge = qsqRatios[0]->GetXaxis()->GetBinLowEdge(i);

            up_edge = 0.;
            up_edge = qsqRatios[0]->GetXaxis()->GetBinUpEdge(i);
          
              if (truQsq > low_edge && truQsq <= up_edge){ 
                for (int j=0; j<nModels; j++) 
                	wt[j] = qsqRatios_nub[j]->GetBinContent(i)*nubarmode_rewt_nubar;
              }
            }
          }
        }
        

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){//dirt
          if (nuType==1&&CCQE){
            for (int i=1; i<=nbins_qsq; i++){
             if (truQsq>qsqRatios[0]->GetXaxis()->GetBinLowEdge(i)&&truQsq<=qsqRatios[0]->GetXaxis()->GetBinUpEdge(i)) 
         	  for (int j=0; j<nModels; j++) wt[j] = qsqRatios[j]->GetBinContent(i)*nubarmode_rewt_nu_dirt;
            }
          }

          if (nuType==2&&CCQE){
            for (int i=1; i<=nbins_qsq; i++){
          
            low_edge = 0.;
            low_edge = qsqRatios[0]->GetXaxis()->GetBinLowEdge(i);

            up_edge = 0.;
            up_edge = qsqRatios[0]->GetXaxis()->GetBinUpEdge(i);
          
              if (truQsq > low_edge && truQsq <= up_edge){ 
                for (int j=0; j<nModels; j++) 
                	wt[j] = qsqRatios_nub[j]->GetBinContent(i)*nubarmode_rewt_nubar_dirt;
              }
            }
          }
        }        

    	//for (int j=0; j<nModels; j++)        
    	//	cout<<" CCQE is "<<CCQE<<" truqsq "<<truQsq<<" model "<<j<<" wt "<<wt[j]<<endl;

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

        scint = 0.;
        scint = mysplitEvent_tankqTot[0]*(1.-myStFull_fqlt05[0]);

        pZ = 0;
        pZ = myMCParent_init_pz[1];

        pZ_fin = 0.;
        pZ_fin = myMCParent_fin_pz[1];

        pX_fin = 0.;
        pX_fin = myMCParent_fin_px[1];

        pY_fin = 0.;
        pY_fin = myMCParent_fin_py[1];

        pTot = 0.;
        pTot = myMCParent_init_pE[1];

        theta = acos(pZ / pTot);//

        //----------------------------------------------------------
        //							CUTS
        //----------------------------------------------------------        

        //for eff, unfolding
        if (fCurrent < numMCfiles){
          // if (genR>500) continue;
          
    
          if (nuType==1&&CCQE&&genR<500){
            for (int j=0; j<nModels; j++){

              if (tHits_1SE>150) truEnu_highthit->Fill(truEnu);

          	  tHit1_noCut[j]->Fill(tHits_1SE,wt[j]);
          	  tmu_noCut[j]->Fill(truTmu*1e3,wt[j]);
                  tmu_noCut_unfold[j]->Fill(truTmu,wt[j]);
                  tmu_noCut_josh[j]->Fill(truTmu,wt[j]);
              //truTmu_tHit1[j]->Fill(truTmu,tHits_1SE,wt[j]);
              //fill translation matrix before cuts?
              //tru_tmu_tank_hits_fold[j]->Fill(tHits_1SE,truTmu*1e3,wt[j]);

            }
          }
        }

	//kill off strobey dirt events early so they're not in cut plots
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles) && (beamAveTime > 6200 || beamAveTime < 4600)) continue;//cut out strobey events for dirt

 		if (passV==0) continue;
	    if (numSE!=2) continue;

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_0->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_0->Fill(scint,mcWt);
		  tmu_cuts_mc_0->Fill(Tmu,mcWt);
		  
		  enuqe_tot_cuts[0]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[0]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[0]->Fill(EnuQE2,wt[1]);

		  thits_tot_cuts[0]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[0]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[0]->Fill(tHits_1SE,wt[1]);
		  
		  if (parent==8){
		    scint_cuts_pip_0->Fill(scint,mcWt);
		    tHit1_cuts_pip_0->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_0->Fill(Tmu,mcWt);
		  }  
		  if (parent==11){  
		    scint_cuts_kp_0->Fill(scint,mcWt);
		    tHit1_cuts_kp_0->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_0->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_0->Fill(tHits_1SE);          
		    scint_cuts_strobe_0->Fill(scint);          
                    thits_strobe_cuts[0]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[0]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_0->Fill(tHits_1SE);          
		      scint_cuts_dirt_0->Fill(scint);          
		      thits_dirt_cuts[0]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[0]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_0->Fill(scint);
		  tHit1_cuts_data_0->Fill(tHits_1SE);
          tmu_cuts_data_0->Fill(Tmu);
		  enuqe_data_cuts[0]->Fill(EnuQE2);
		  thits_data_cuts[0]->Fill(tHits_1SE);          
		  
        }
        
        //if (beamAveTime > 11750 || beamAveTime < 2800) continue;
        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles) && (beamAveTime > 6200 || beamAveTime < 4600)) continue;//cut out strobey events for dirt
        //if (beamAveTime < 11300) continue;//late timing cut?


        if (fCurrent < numMCfiles){

		  thits_tot_cuts[1]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[1]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[1]->Fill(tHits_1SE,wt[1]);

		  enuqe_tot_cuts[1]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[1]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[1]->Fill(EnuQE2,wt[1]);

		  tHit1_cuts_mc_1->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_1->Fill(scint,mcWt);
		  tmu_cuts_mc_1->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_1->Fill(scint,mcWt);
		    tHit1_cuts_pip_1->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_1->Fill(Tmu,mcWt);
		  }  
		  if (parent==11){  
		    scint_cuts_kp_1->Fill(scint,mcWt);
		    tHit1_cuts_kp_1->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_1->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_1->Fill(tHits_1SE);          
		    scint_cuts_strobe_1->Fill(scint);          
                    thits_strobe_cuts[1]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[1]->Fill(EnuQE2);

        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_1->Fill(tHits_1SE);          
		      scint_cuts_dirt_1->Fill(scint);          
		      thits_dirt_cuts[1]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[1]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_1->Fill(scint);
		  tHit1_cuts_data_1->Fill(tHits_1SE);
          tmu_cuts_data_1->Fill(Tmu);
		  enuqe_data_cuts[1]->Fill(EnuQE2);
		  thits_data_cuts[1]->Fill(tHits_1SE);
        }

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_2->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_2->Fill(scint,mcWt);
		  tmu_cuts_mc_2->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_2->Fill(scint,mcWt);
		    tHit1_cuts_pip_2->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_2->Fill(Tmu,mcWt);
		  }
		    
		  if (parent==11){  
		    scint_cuts_kp_2->Fill(scint,mcWt);
		    tHit1_cuts_kp_2->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_2->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_2->Fill(tHits_1SE);          
		    scint_cuts_strobe_2->Fill(scint);          
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_2->Fill(tHits_1SE);          
		      scint_cuts_dirt_2->Fill(scint);          
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_2->Fill(scint);
		  tHit1_cuts_data_2->Fill(tHits_1SE);
          tmu_cuts_data_2->Fill(Tmu);
        }        
        // UNCOMMENT
        if (tHits_2SE>200) continue;
        if (tHits_2SE<20) continue;
        //cout<<" Mich Dist "<<MichDist<<endl;

        if (fCurrent < numMCfiles){

		  thits_tot_cuts[2]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[2]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[2]->Fill(tHits_1SE,wt[1]);
        
		  enuqe_tot_cuts[2]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[2]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[2]->Fill(EnuQE2,wt[1]);
        
		  tHit1_cuts_mc_3->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_3->Fill(scint,mcWt);
		  tmu_cuts_mc_3->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_3->Fill(scint,mcWt);
		    tHit1_cuts_pip_3->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_3->Fill(Tmu,mcWt);
		  }
		  if (parent==11){  
		    scint_cuts_kp_3->Fill(scint,mcWt);
		    tHit1_cuts_kp_3->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_3->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_3->Fill(tHits_1SE);          
		    scint_cuts_strobe_3->Fill(scint);          
                    thits_strobe_cuts[2]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[2]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_3->Fill(tHits_1SE);          
		      scint_cuts_dirt_3->Fill(scint);          
		      thits_dirt_cuts[2]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[2]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_3->Fill(scint);
		  tHit1_cuts_data_3->Fill(tHits_1SE);
          tmu_cuts_data_3->Fill(Tmu);
		  enuqe_data_cuts[2]->Fill(EnuQE2);
		  thits_data_cuts[2]->Fill(tHits_1SE);
        }
        
        if (muR>500) continue;

        if (fCurrent < numMCfiles){

		  thits_tot_cuts[3]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[3]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[3]->Fill(tHits_1SE,wt[1]);
        
		  enuqe_tot_cuts[3]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[3]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[3]->Fill(EnuQE2,wt[1]);
        
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
                    thits_strobe_cuts[3]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[3]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      thits_dirt_cuts[3]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[3]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  enuqe_data_cuts[3]->Fill(EnuQE2);
		  thits_data_cuts[3]->Fill(tHits_1SE);
        }
        
        if (tHits_1SE<20) continue;

        if (fCurrent < numMCfiles){

		  thits_tot_cuts[4]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[4]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[4]->Fill(tHits_1SE,wt[1]);
        
		  enuqe_tot_cuts[4]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[4]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[4]->Fill(EnuQE2,wt[1]);
        
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
                    thits_strobe_cuts[4]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[4]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      thits_dirt_cuts[4]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[4]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  enuqe_data_cuts[4]->Fill(EnuQE2);
		  thits_data_cuts[4]->Fill(tHits_1SE);
        }

        //if (tHits_1SE>250) continue;
        if (tank_rms_time>50) continue;

        if (fCurrent < numMCfiles){

          if (nuType==1&&CCQE&&genR<500){
            for (int j=0; j<nModels; j++){
          	  tHit1_befMich[j]->Fill(tHits_1SE,wt[j]);
            }
          }  

		  thits_tot_cuts[5]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[5]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[5]->Fill(tHits_1SE,wt[1]);

		  enuqe_tot_cuts[5]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[5]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[5]->Fill(EnuQE2,wt[1]);

		  tHit1_cuts_mc_4->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_4->Fill(scint,mcWt);
		  tmu_cuts_mc_4->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_4->Fill(scint,mcWt);
		    tHit1_cuts_pip_4->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_4->Fill(Tmu,mcWt);
		  }
		  if (parent==11){  
		    scint_cuts_kp_4->Fill(scint,mcWt);
		    tHit1_cuts_kp_4->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_4->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_4->Fill(tHits_1SE);          
		    scint_cuts_strobe_4->Fill(scint);          
                    thits_strobe_cuts[5]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[5]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_4->Fill(tHits_1SE);          
		      scint_cuts_dirt_4->Fill(scint);          
		      thits_dirt_cuts[5]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[5]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_4->Fill(scint);
		  tHit1_cuts_data_4->Fill(tHits_1SE);
          tmu_cuts_data_4->Fill(Tmu);
		  enuqe_data_cuts[5]->Fill(EnuQE2);
		  thits_data_cuts[5]->Fill(tHits_1SE);
        }

        //cout<<"Mich Dist "<<MichDist<<endl;
        if (MichDist>100) continue;

        if (fCurrent < numMCfiles){

		  thits_tot_cuts[6]->Fill(tHits_1SE,wt[1]);
		  if (nuType==1) thits_nu_cuts[6]->Fill(tHits_1SE,wt[1]);
		  if (nuType==2) thits_nub_cuts[6]->Fill(tHits_1SE,wt[1]);

		  enuqe_tot_cuts[6]->Fill(EnuQE2,wt[1]);
		  if (nuType==1) enuqe_nu_cuts[6]->Fill(EnuQE2,wt[1]);
		  if (nuType==2) enuqe_nub_cuts[6]->Fill(EnuQE2,wt[1]);

        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
                    thits_strobe_cuts[6]->Fill(tHits_1SE);
                    enuqe_strobe_cuts[6]->Fill(EnuQE2);
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      thits_dirt_cuts[6]->Fill(tHits_1SE);
                      enuqe_dirt_cuts[6]->Fill(EnuQE2);
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 

		  enuqe_data_cuts[6]->Fill(EnuQE2);
		  thits_data_cuts[6]->Fill(tHits_1SE);
        }
        
	//if (Tmu<0.03) continue;
        //sideband cuts
        //if (tHits_1SE*myStFull_fqlt10[0]/1000 < 0.15) continue;
        //if (tHits_1SE*myStFull_fqlt10[0]/1000 > 0.25) continue;

        //signal cut
        //if (tHits_1SE*myStFull_fqlt10[0]/1000 > 0.15) continue;
        //if (tHits_1SE*myStFull_fqlt10[0]/1000==0) continue;

        //if (tHits_1SE>50&&tHits_1SE<120&&deltaLk<-0.02) chans->Fill(Channel);

        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_5->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_5->Fill(scint,mcWt);
		  tmu_cuts_mc_5->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_5->Fill(scint,mcWt);
		    tHit1_cuts_pip_5->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_5->Fill(Tmu,mcWt);
		  }
		  if (parent==11){  
		    scint_cuts_kp_5->Fill(scint,mcWt);
		    tHit1_cuts_kp_5->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_5->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_5->Fill(tHits_1SE);          
		    scint_cuts_strobe_5->Fill(scint);          
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_5->Fill(tHits_1SE);          
		      scint_cuts_dirt_5->Fill(scint);          
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_5->Fill(scint);
		  tHit1_cuts_data_5->Fill(tHits_1SE);
          tmu_cuts_data_5->Fill(Tmu);
        }

        //if (tHits_2SE<30) continue;      
 
        if (fCurrent < numMCfiles){
		  tHit1_cuts_mc_6->Fill(tHits_1SE,mcWt);
		  scint_cuts_mc_6->Fill(scint,mcWt);
		  tmu_cuts_mc_6->Fill(Tmu,mcWt);
		  if (parent==8){
		    scint_cuts_pip_6->Fill(scint,mcWt);
		    tHit1_cuts_pip_6->Fill(tHits_1SE,mcWt);
		    tmu_cuts_pip_6->Fill(Tmu,mcWt);
		  }
		  if (parent==11){  
		    scint_cuts_kp_6->Fill(scint,mcWt);
		    tHit1_cuts_kp_6->Fill(tHits_1SE,mcWt);
		    tmu_cuts_kp_6->Fill(Tmu,mcWt);
          }
        }
        
        if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe
		    tHit1_cuts_strobe_6->Fill(tHits_1SE);          
		    scint_cuts_strobe_6->Fill(scint);          
        }

        if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt
		    if (genR>610){
		      tHit1_cuts_dirt_6->Fill(tHits_1SE);          
		      scint_cuts_dirt_6->Fill(scint);          
            }
        }
        
        if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 
		  scint_cuts_data_6->Fill(scint);
		  tHit1_cuts_data_6->Fill(tHits_1SE);
          tmu_cuts_data_6->Fill(Tmu);
        }
        //if (Range - (500 * Tmu - 100) < 0) continue;
        //if (Range < 100) continue;

        //if (recoUY>0) continue;
        //if (recoUX>0) continue;
        //if (recoUZ>0) continue;
        //cout<<"recoUY "<<recoUY<<endl;

        //if (Tmu<0.03) cout<<"< 30 MeV reco mu: tank hits "<<tHits_1SE<<endl;

        //----------------------------------------------------------
        //							
        //----------------------------------------------------------        
        
        if (fCurrent < numMCfiles){

        if (tHits_1SE<150) chans->Fill(Channel);

        //if (Channel!=1&&tHits_1SE<150) cout<<" channel "<<Channel<<endl;

          //cout<<" nutype "<<nuType<<endl;
          //if (nuType!=1) continue;       
 
        
        /*if (parent==11){
          //if ((truEnu>0.230)&&(truEnu<0.240)){
            if (myMCParent_fin_px[1]==0&&myMCParent_fin_py[1]==0&&myMCParent_fin_pz[1]==0) sig = 1; 
          //}
        }*/

        
        //-------------------------------------------------------------
        //              hists
        //-------------------------------------------------------------
                

        michels_mc->Fill(tHits_2SE);

        posDirCorrX->Fill(myMCParent_init_x[0],nuUX);
        posDirCorrY->Fill(myMCParent_init_y[0],nuUY);
        posDirCorrZ->Fill(myMCParent_init_z[0],nuUZ);
        
	//cout<<" proton init x, y, z "<<myMCParent_init_px[2]<<" "<<myMCParent_init_py[2]<<" "<<myMCParent_init_pz[2]<<endl;

        mcCnt++;       


        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05) mc_inbmp->Fill(tHits_2SE);
        else mc_outbmp->Fill(tHits_2SE);

        recoXZ_tot->Fill(muX,muZ,mcWt);
        recoXY_tot->Fill(muX,muY,mcWt);
        recoYZ_tot->Fill(muY,muZ,mcWt);

        truEnu_tHit1->Fill(truEnu,tHits_1SE,mcWt);

        eLk_tot_2se->Fill(-elLk_2se,mcWt);
        eLk_tot->Fill(-elLk,mcWt);
        muLk_tot->Fill(-muLk,mcWt);

        if (tHits_1SE>60&&tHits_1SE<120) 
        	elike_mc_2ndBmp->Fill(-elLk);

        if (tHits_2SE>60&&tHits_2SE<120) 
        	elike_mc_2se->Fill(-elLk_2se);

        time_tot->Fill(beamAveTime);
 
        if (tHits_1SE<60) tHit2_mc_firstBump->Fill(tHits_2SE,mcWt);//
        if (tHits_1SE>60&&tHits_1SE<120) tHit2_mc_secondBump->Fill(tHits_2SE,mcWt);

        tHit1_deltaLk_mc->Fill(tHits_1SE,deltaLk,mcWt);

        mc_genR->Fill(genR,mcWt);

        tDiff_tot->Fill(tDiff,mcWt);
        truEnu_tot->Fill(truEnu,mcWt);

		truEnu_tot_norewt->Fill(truEnu);
        if (nuType==1) truEnu_nu_norewt->Fill(truEnu);
        if (nuType==2) truEnu_nubar_norewt->Fill(truEnu);

        if (nuType==1){
        	truEnu_nu_rewt->Fill(truEnu,nubarmode_rewt_nu);
			truEnu_tot_rewt->Fill(truEnu,nubarmode_rewt_nu);
        }
        
        if (nuType==2){
        	truEnu_nubar_rewt->Fill(truEnu,nubarmode_rewt_nubar);
			truEnu_tot_rewt->Fill(truEnu,nubarmode_rewt_nubar);
		}


		tHits_tot_norewt->Fill(tHits_1SE);
        if (nuType==1) tHits_nu_norewt->Fill(tHits_1SE);
        if (nuType==2) tHits_nubar_norewt->Fill(tHits_1SE);

        if (nuType==1){
        	tHits_nu_rewt->Fill(tHits_1SE,nubarmode_rewt_nu);
			tHits_tot_rewt->Fill(tHits_1SE,nubarmode_rewt_nu);
        }
        
        if (nuType==2){
        	tHits_nubar_rewt->Fill(tHits_1SE,nubarmode_rewt_nubar);
			tHits_tot_rewt->Fill(tHits_1SE,nubarmode_rewt_nubar);
		}

        if (nuType==1) truEnu_numu->Fill(truEnu);
        if (nuType==2) truEnu_numubar->Fill(truEnu);

        if (CCQE) truTmu_tot->Fill(truTmu,mcWt);
        truUZ_tot->Fill(truUZ,mcWt);
        truUY_tot->Fill(truUY,mcWt);
        truUX_tot->Fill(truUX,mcWt);
		lk_tot->Fill(deltaLk,mcWt); 
		lk_tot_2se->Fill(deltaLk_2se,mcWt); 
        //if (tHits_1SE>120){
        if (tHits_1SE<120&&tHits_1SE>60){
          lk_2ndBump_tot->Fill(deltaLk,mcWt);
          if (Channel==1) lk_2ndBump_ccqe->Fill(deltaLk,mcWt);
          if (Channel==7) lk_2ndBump_ncpi->Fill(deltaLk,mcWt);
          //if (Channel!=1) cout<<"chan "<<Channel<<endl;
        }

          spitzVar_mcRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
          spitzVar_enuCorr->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,truEnu);
          if (parent==8)  spitzVar_pipRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
          if (parent==9)  spitzVar_pimRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
          if (parent==11) spitzVar_kpRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);

          thits_mcRng->Fill(tHits_1SE);
          if (parent==8)  thits_pipRng->Fill(tHits_1SE);
          if (parent==9)  thits_pimRng->Fill(tHits_1SE);
          if (parent==11) thits_kpRng->Fill(tHits_1SE);

          tHit1_tot->Fill(tHits_1SE,wt[1]);

          if (tHits_1SE<150){
            if (nuType==1) chans_sig_nu->Fill(Channel,wt[1]);
            if (nuType==2) chans_sig_nub->Fill(Channel,wt[1]);
          }
          
          if (tHits_1SE<150){//18: 0.992 BF from sideband chisq
            sig_enu->Fill(truEnu,wt[18]);
            sig_qsq->Fill(truQsq,wt[18]);
          }

          if (tHits_1SE>150&&tHits_1SE<300){
            sb_enu->Fill(truEnu,wt[18]);
            sb_qsq->Fill(truQsq,wt[18]);
          }

          if (nuType==1&&CCQE&&genR<500){
            if (truTmu<0.120 && tHits_1SE>150) lt_120_tmu_gt_150_thits->Fill(truEnu*1000.);
          }

          for (int j=0; j<nModels; j++){

            spitzVar_mc[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);
            spitzVar_mc_largeRng[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);
            if (parent==8)  spitzVar_pip[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);
            if (parent==9)  spitzVar_pim[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);
            if (parent==11) spitzVar_kp[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);
            if (parent!=8&&parent!=9&&parent!=11)
              spitzVar_othr[j]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[j]);

            if (nuType==1&&CCQE&&genR<500){
          	  tHit1_wCut[j]->Fill(tHits_1SE,wt[j]);
          	  tmu_wCut[j]->Fill(truTmu*1e3,wt[j]);
                  tmu_wCut_unfold[j]->Fill(truTmu,wt[j]);
                  tmu_wCut_josh[j]->Fill(truTmu,wt[j]);

              //fill translation matrix after cuts?
              tru_tmu_tank_hits_fold[j]->Fill(tHits_1SE,truTmu*1e3,wt[j]);
              truTmu_tHit1[j]->Fill(truTmu,tHits_1SE,wt[j]);
            }

            thits_mc[j]->Fill(tHits_1SE,wt[j]);
            
            if (tHits_1SE<150&&beamAveTime<2500){
              mich_dist_mc[j]->Fill(MichDist,wt[j]);
              if (Channel==1) mich_dist_qe[j]->Fill(MichDist,wt[j]);
              if (Channel==3||Channel==5||Channel==7||Channel==10||Channel==12||Channel==14) mich_dist_pi[j]->Fill(MichDist,wt[j]);//kappa actually only applies to qe
              //cout<<" channel "<<Channel<<endl;
            }
            
            //cout<<tHits_1SE<<" "<<j<<" "<<wt[j]<<endl;
            
            if (nuType==1)  thits_nu[j]->Fill(tHits_1SE,wt[j]);
            if (nuType==2)  thits_nub[j]->Fill(tHits_1SE,wt[j]);

            tru_tmu_mc[j]->Fill(truTmu,wt[j]);
            if (nuType==1)  tru_tmu_nu[j]->Fill(truTmu,wt[j]);
            if (nuType==2)  tru_tmu_nub[j]->Fill(truTmu,wt[j]);

            enuqe_mc[j]->Fill(EnuQE,wt[j]);
            if (nuType==1)  enuqe_nu[j]->Fill(EnuQE,wt[j]);
            if (nuType==2)  enuqe_nub[j]->Fill(EnuQE,wt[j]);

            thits_mc_largerng[j]->Fill(tHits_1SE,wt[j]);
            if (nuType==1)  thits_nu_largerng[j]->Fill(tHits_1SE,wt[j]);
            if (nuType==2)  thits_nub_largerng[j]->Fill(tHits_1SE,wt[j]);

            tmu_mc_largerng[j]->Fill(Tmu,wt[j]);
            if (nuType==1)  tmu_nu_largerng[j]->Fill(Tmu,wt[j]);
            if (nuType==2)  tmu_nub_largerng[j]->Fill(Tmu,wt[j]);

            if (parent==8)  thits_pip[j]->Fill(tHits_1SE,wt[j]);
            if (parent==9)  thits_pim[j]->Fill(tHits_1SE,wt[j]);
            if (parent==11) thits_kp[j]->Fill(tHits_1SE,wt[j]);
            if (parent!=8&&parent!=9&&parent!=11)
              thits_othr[j]->Fill(tHits_1SE,wt[j]);

          }
          if (parent!=8&&parent!=9&&parent!=11){
            thetaY_othr->Fill(thetaY);
            recUY_othr->Fill(recoUY);
            recDmpCos_othr->Fill(dump_cosangle_reco);
          }
          if (CCQE)    scintVar_ccqe->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
          if (CCQE==0) scintVar_nonqe->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
          if (CCQE){
            if (truEnu < 0.2){//just a test to make sure unsmeared reco == true!
              spitzVar_recoMC->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
              spitzVar_tmuCorr_toy->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000);
              spitzVar_truMC->Fill(truTmu);

              thits_recoMC->Fill(tHits_1SE);
              thits_tmuCorr_toy->Fill(truTmu,tHits_1SE);
              tmu_truMC->Fill(truTmu);

              thits_recoMC_fold->Fill(tHits_1SE);
              thits_tmuCorr_toy_fold->Fill(tHits_1SE,truTmu*1e3);
              tmu_truMC_fold->Fill(truTmu*1e3);

            }
            spitzVar_tmuCorr_k1->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_k1);
            spitzVar_tmuCorr_k1022->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_k1022);
            spitzVar_tmuCorr_martini->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_martini);
            //if (modelRewt_martini!=0) cout<<" martini rewt val "<<modelRewt_martini<<endl;
            spitzVar_tmuCorr_genie->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_genie);
            spitzVar_tmuCorr_nuwro->Fill(truTmu,tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_nuwro);
            defModel_k1->Fill(truTmu,modelRewt_k1);
            defModel_k1022->Fill(truTmu,modelRewt_k1022);
            defModel_martini->Fill(truTmu,modelRewt_martini);
            defModel_genie->Fill(truTmu,modelRewt_genie);
            defModel_nuwro->Fill(truTmu,modelRewt_nuwro);
            recoSpitzVar_k1->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_k1);
            recoSpitzVar_k1022->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_k1022);
            recoSpitzVar_martini->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_martini);
            recoSpitzVar_genie->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_genie);
            recoSpitzVar_nuwro->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,modelRewt_nuwro);
            defModel->Fill(truTmu);
          } 
       

        recUZ_tot->Fill(recoUZ,mcWt);
        recUY_tot->Fill(recoUY,mcWt);
        recUX_tot->Fill(recoUX,mcWt);

        //if (dump_cosangle_reco==0) cout<<"0! parent "<<parent<<endl;
        recDmpCos_tot->Fill(dump_cosangle_reco,mcWt);

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
        
        truEnuQE_tot->Fill(truEnuQE);
        recEnuQE_tot->Fill(EnuQE,mcWt);
        recEnuQE_tot_bigRng->Fill(EnuQE,mcWt);
        tHit1_totBig->Fill(tHits_1SE,mcWt);
        tHit1_tot_nokdar->Fill(tHits_1SE,mcWt);
        if (truTmu<0.09&&truTmu>0.085){
          nuEnrgy_tmuSpike->Fill(truEnu);
          //cout<<" nu energy "<<truEnu<<endl;
        }

        if (tHits_1SE>60&&tHits_1SE<120){ 
        
          //island A
          if (deltaLk<-0.01){
            tDiff_islandA_mc->Fill(tDiff,mcWt);
          }
          
          //island B
          if (deltaLk>-0.01){
            tDiff_islandB_mc->Fill(tDiff,mcWt);
          }
        
        }

	    for (int i=0; i<nTmuBins; i++){
	      if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	        AdjRngTmuBns_tot[i]->Fill(adjRange,mcWt);
        }  

        recTmu_tot->Fill(Tmu,mcWt);
          recTmu_tot_nokdar->Fill(Tmu,mcWt);
        
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

          recDmpCos_kP->Fill(dump_cosangle_reco);
          
          thetaZ_kP->Fill(thetaZ);
          thetaY_kP->Fill(thetaY);
          thetaX_kP->Fill(thetaX);
          
          eLk_kP->Fill(-elLk,mcWt);
          muLk_kP->Fill(-muLk,mcWt);
          
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
        if (parent==9){
          thetaY_pim->Fill(thetaY);
          recUY_pim->Fill(recoUY);
          recDmpCos_pim->Fill(dump_cosangle_reco);
        }

        if (CCQE) enu_ccqeBkg->Fill(truEnu);

        //if (parent==8){
        if (parent==8){

	      for (int i=0; i<nTmuBins; i++){
	        if (Tmu > TmuBound[2*i] && Tmu < TmuBound[2*i+1])
	          AdjRngTmuBns_piP[i]->Fill(adjRange,mcWt);
          }  

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

          recDmpCos_piP->Fill(dump_cosangle_reco);

          thetaZ_piP->Fill(thetaZ);
          thetaY_piP->Fill(thetaY);
          thetaX_piP->Fill(thetaX);

          eLk_piP->Fill(-elLk,mcWt);
          muLk_piP->Fill(-muLk,mcWt);

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

      //if (tHits_1SE<200) cout<<" < 200, ptot "<<pTot<<endl;
      //if (tHits_1SE>200) cout<<" > 200, ptot "<<pTot<<endl;

      }
      
      if ((fCurrent>=numMCfiles)&&(fCurrent<numMCfiles+numStrobeFiles)){ //strobe

        if ( (jentry % 5000) == 0){
          cout << "Strobe!  Entry " << jentry << " file " << fCurrent << endl;
        }

        strobe_secSE->Fill(tHits_2SE);

        michels_strobe->Fill(tHits_2SE);

        spitzVar_strobe->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        thits_strobe->Fill(tHits_1SE);
        if (tHits_1SE<150&&beamAveTime<2500) mich_dist_strobe->Fill(MichDist);
        tru_tmu_strobe->Fill(truTmu);
        thits_strobe_largerng->Fill(tHits_1SE);
        tmu_strobe_largerng->Fill(Tmu);

          thits_strobeRng->Fill(tHits_1SE);

        recoR_strobe->Fill(muR);

        lk_strobe->Fill(deltaLk);
        recUY_strobe->Fill(recoUY);
                recTmu_strobe->Fill(Tmu);
        tHit1_strobe->Fill(tHits_1SE);
        time_strobe->Fill(beamAveTime);

      }
      
      if ((fCurrent>=numMCfiles+numStrobeFiles)&&(fCurrent<numMCfiles+numStrobeFiles+numDirtFiles)){ //dirt

        if ( (jentry % 5000) == 0){
          cout << "dirt!  Entry " << jentry << " file " << fCurrent << endl;
        }

        if (genR>610){

          dirt_secSE->Fill(tHits_2SE);

          michels_dirt->Fill(tHits_2SE);

          for (int i=0; i<nModels; i++) spitzVar_dirt[i]->Fill(tHits_1SE*myStFull_fqlt10[0]/1000,wt[i]);
          for (int i=0; i<nModels; i++) thits_dirt[i]->Fill(tHits_1SE,wt[i]);
          if (tHits_1SE<150&&beamAveTime<2500){
            for (int i=0; i<nModels; i++) mich_dist_dirt[i]->Fill(MichDist,wt[i]);
          }
          for (int i=0; i<nModels; i++) tru_tmu_dirt[i]->Fill(truTmu,wt[i]);
          for (int i=0; i<nModels; i++) thits_dirt_largerng[i]->Fill(tHits_1SE,wt[i]);
          for (int i=0; i<nModels; i++) tmu_dirt_largerng[i]->Fill(Tmu,wt[i]);

          thits_dirtRng->Fill(tHits_1SE);

          thetaY_dirt->Fill(thetaY);
          recUY_dirt->Fill(recoUY);
          recDmpCos_dirt->Fill(dump_cosangle_reco);
          recoXZ_dirt->Fill(muX,muZ);
          recoXY_dirt->Fill(muX,muY);
          recoYZ_dirt->Fill(muY,muZ);
          lk_dirt->Fill(deltaLk);
          tHit1_dirt->Fill(tHits_1SE,wt[1]);
          recoR_dirt->Fill(muR);
          if (tHits_1SE<120&&tHits_1SE>60) lk_2ndBump_dirt->Fill(deltaLk,mcWt);
          time_dirt->Fill(beamAveTime);
          //cout<<"dirt! channel "<<Channel<<endl;

          if (tHits_1SE<150){
            if (nuType==1) chans_sig_dirt_nu->Fill(Channel,wt[1]);
            if (nuType==2) chans_sig_dirt_nub->Fill(Channel,wt[1]);
          }
        }
        dirt_genR->Fill(genR);

      }
      
      if (fCurrent >= (numMCfiles+numStrobeFiles+numDirtFiles)){//data 

        data_time->Fill(myHeader_Secs[0]);
        data_time_zm->Fill(myHeader_Secs[0]);
        
        det_tstamp = 0;
        det_tstamp = myHeader_Secs[0];
        //if ((float)myHeader_MilliSecs[0]>=500-0.0025) //2500 ns = tof
        	//det_tstamp += 1;
        
        time_bet_events->Fill(det_tstamp - prev_det_tstamp);
        //cout<<" curr "<<det_tstamp<<" last "<<prev_det_tstamp<<" diff "<<det_tstamp - prev_det_tstamp<<endl;
        
        total_ctr += 1;
        
        /*
        for (int i=0; i<tstamp_vs_batches->GetN(); i++){
        
          //if ((myHeader_Secs[0] == tstamp_vs_batches->GetX()[i])||(myHeader_Secs[0] == tstamp_vs_batches->GetX()[i]-1)){ 
          //if ((det_tstamp == tstamp_vs_batches->GetX()[i])||(det_tstamp == tstamp_vs_batches->GetX()[i]+1)){ 
          if (det_tstamp == tstamp_vs_batches->GetX()[i] + leap_sec_offset){ 
          //if (myHeader_Secs[0] - tstamp_vs_batches->GetX()[i]<2){  //nope
            success_ctr += 1;
            cout<<" match! event timestamp "<<det_tstamp<<" spill timestamp "<<(int)tstamp_vs_batches->GetX()[i]<<" pt number "<<i<<" jentry "<<jentry<<endl;
            
            n_batches = 0;
            n_batches = tstamp_vs_batches->GetY()[i];
            
            if (n_batches==0) time_data_0->Fill(beamAveTime);
            if (n_batches==1) time_data_1->Fill(beamAveTime);
            if (n_batches==2) time_data_2->Fill(beamAveTime);
            if (n_batches==3) time_data_3->Fill(beamAveTime);
            if (n_batches==4) time_data_4->Fill(beamAveTime);
            if (n_batches==5) time_data_5->Fill(beamAveTime);
            if (n_batches==6) time_data_6->Fill(beamAveTime);
            time_data_tot->Fill(beamAveTime);
           
          }
        
        }
        
        cout<<" success counter "<<success_ctr<<" total counter "<<total_ctr<<" ratio "<<(float)success_ctr/total_ctr<<" detector time "<<det_tstamp<<" n_batches "<<n_batches<<endl;

		*/

        /*
        for (int i=0; i<tstamp_vs_batches->GetN(); i++){
        
          //if ((myHeader_Secs[0] == tstamp_vs_batches->GetX()[i])||(myHeader_Secs[0] == tstamp_vs_batches->GetX()[i]-1)){ 
          //if ((det_tstamp == tstamp_vs_batches->GetX()[i])||(det_tstamp == tstamp_vs_batches->GetX()[i]+1)){ 
          if (det_tstamp == tstamp_vs_batches->GetX()[i] + leap_sec_offset){ 
          //if (myHeader_Secs[0] - tstamp_vs_batches->GetX()[i]<2){  //nope
            success_ctr += 1;
            cout<<" match! event timestamp "<<det_tstamp<<" spill timestamp "<<(int)tstamp_vs_batches->GetX()[i]<<" pt number "<<i<<" jentry "<<jentry<<endl;
            
            n_batches = 0;
            n_batches = tstamp_vs_batches->GetY()[i];
            
            if (n_batches==0) time_data_0->Fill(beamAveTime);
            if (n_batches==1) time_data_1->Fill(beamAveTime);
            if (n_batches==2) time_data_2->Fill(beamAveTime);
            if (n_batches==3) time_data_3->Fill(beamAveTime);
            if (n_batches==4) time_data_4->Fill(beamAveTime);
            if (n_batches==5) time_data_5->Fill(beamAveTime);
            if (n_batches==6) time_data_6->Fill(beamAveTime);
            time_data_tot->Fill(beamAveTime);
           
          }
        
        }
        
        cout<<" success counter "<<success_ctr<<" total counter "<<total_ctr<<" ratio "<<(float)success_ctr/total_ctr<<" detector time "<<det_tstamp<<" n_batches "<<n_batches<<endl;

		*/

        /*
        n_batches = 0;
        n_batches = tstamp_vs_batches->Eval(det_tstamp - leap_sec_offset);

		if (n_batches==5){
              
			if (tHits_1SE<150) spitztime_in_5->Fill(beamAveTime);
			if (tHits_1SE>=300) spitztime_out_5->Fill(beamAveTime);
			if (tHits_1SE>=150&&tHits_1SE<300) spitztime_mid_5->Fill(beamAveTime);
			spitztime_tot_5->Fill(beamAveTime);

            //if (beamAveTime<2500&&tHits_1SE<300)
            //	cout<<" beamtime "<<beamAveTime<<" thits "<<tHits_1SE<<endl;

			for (int j=0; j<nbins_time; j++){
			  if (beamAveTime>time_bounds[j]&&beamAveTime<time_bounds[j+1]){
			  	thits_data_bins[j]->Fill(tHits_1SE);
			  	thits_data_bins_lg[j]->Fill(tHits_1SE);
			  }
			}
		    
		  	newtree->Fill();
			//cout<<" filling "<<endl;
        }
        
        if (n_batches==0) time_data_0->Fill(beamAveTime);
        if (n_batches==1) time_data_1->Fill(beamAveTime);
        if (n_batches==2) time_data_2->Fill(beamAveTime);
        if (n_batches==3) time_data_3->Fill(beamAveTime);
        if (n_batches==4) time_data_4->Fill(beamAveTime);
        if (n_batches==5) time_data_5->Fill(beamAveTime);
        if (n_batches==6) time_data_6->Fill(beamAveTime);
        time_data_tot->Fill(beamAveTime);
        //cout<<" secs: "<<myHeader_Secs[0]<<endl;  
        */
 
        if ( (jentry % 500) == 0){
          cout << "Data!  Entry " << jentry << " file " << fCurrent << " beam time "<< beamAveTime <<endl;
        }

        if (beamAveTime > 11300) thits_late->Fill(tHits_1SE);
        if (beamAveTime < 11500 && beamAveTime > 2800) thits_normal->Fill(tHits_1SE);

        if (tHits_1SE<150) spitztime_in->Fill(beamAveTime);
        if (tHits_1SE>=300) spitztime_out->Fill(beamAveTime);
        if (tHits_1SE>=150&&tHits_1SE<300) spitztime_mid->Fill(beamAveTime);
        spitztime_tot->Fill(beamAveTime);

        michels_data->Fill(tHits_2SE);      
 
        if (tHits_1SE>60&&tHits_1SE<120){ 
        
          //island A
          if (deltaLk<-0.01){
            tDiff_islandA_data->Fill(tDiff);
          }
          
          //island B
          if (deltaLk>-0.01){
            tDiff_islandB_data->Fill(tDiff);
          }
        
        }
       
        eLk_tot_2se->Fill(-elLk_2se,mcWt);
       
        //if (tHits_1SE>120){
        if (tHits_1SE<120&&tHits_1SE>60){
          lk_2ndBump_data->Fill(deltaLk);
        }
 
        if (tHits_1SE*myStFull_fqlt10[0]/1000<0.05) data_inbmp->Fill(tHits_2SE);
        else data_outbmp->Fill(tHits_2SE);
 
        tHit1_deltaLk_data->Fill(tHits_1SE,deltaLk);
 
        if (tHits_1SE<60) tHit2_data_firstBump->Fill(tHits_2SE);
        if (tHits_1SE>60&&tHits_1SE<120) tHit2_data_secondBump->Fill(tHits_2SE);
 
        eLk_data_2se->Fill(-elLk_2se);
        
        recoXZ_data->Fill(muX,muZ);
        recoXY_data->Fill(muX,muY);
        recoYZ_data->Fill(muY,muZ);

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
        
        tHits_data->Fill(tHits_1SE);

        tHit1_dataBig->Fill(tHits_1SE);
        recEnuQE_data->Fill(EnuQE);
        recEnuQE_data_bigRng->Fill(EnuQE);
        dataCnt++;
		recTmu_data->Fill(Tmu);
        recUX_data->Fill(recoUX);
        recUY_data->Fill(recoUY);
        recUZ_data->Fill(recoUZ);

        //-----------------------------------
        
        /*
        thits_mc[0]->SetLineWidth(2);
        thits_nu[0]->SetLineWidth(2);
        thits_nu[0]->SetLineColor(2);
        thits_nub[0]->SetLineWidth(2);
        thits_nub[0]->SetLineColor(kBlue);

        cout<<" before mc int "<<thits_mc[0]->Integral()<<endl;
        
        if (thits_data->Integral()>0){
          thits_mc[0]->Scale(thits_data->Integral()/thits_mc[0]->Integral()*0.7);
          thits_nu[0]->Scale(thits_data->Integral()/thits_mc[0]->Integral()*0.7);
          thits_nub[0]->Scale(thits_data->Integral()/thits_mc[0]->Integral()*0.7);
        }
        
        cout<<" data int "<<thits_data->Integral()<<" mc int "<<thits_mc[0]->Integral()<<endl;
        
        if (thits_data->Integral()>0){
          datactr += 1;

          thits_mc[0]->SetMaximum(thits_data->GetMaximum()*1.15);
          thits_mc[0]->Draw();
          thits_nu[0]->Draw("same");
          thits_nub[0]->Draw("same");
          thits_data->Draw("e1p same");
          if (datactr==1) gifC->Print("thits_anim.gif+10(");
          else gifC->Print("thits_anim.gif+");
		}
		*/
		//-----------------------------------        

        recDmpCos_data->Fill(dump_cosangle_reco);

        spitzVar_data->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);
        spitzVar_dataRng->Fill(tHits_1SE*myStFull_fqlt10[0]/1000);

        enuqe_data->Fill(EnuQE);
        thits_data->Fill(tHits_1SE);
        if (tHits_1SE<150&&beamAveTime<2500) mich_dist_data->Fill(MichDist);
        thits_data_largerng->Fill(tHits_1SE);
        tmu_data_largerng->Fill(Tmu);

        recoR_data->Fill(muR);
        
        thits_dataRng->Fill(tHits_1SE);

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

        eLk_data->Fill(-elLk);
        muLk_data->Fill(-muLk);

        if (tHits_1SE>60&&tHits_1SE<120) 
        	mulike_data_2ndBmp->Fill(-muLk);

        michEnergy_eHyp_data->Fill(michE,mcWt);
        michEnergy_muHyp_data->Fill(michE_muHyp);
        
        prev_det_tstamp = det_tstamp;
      
      }

   }//jentry loop

std::cout<<"made it out of event loop HEYO"<<std::endl;

newtree->Print();
newtree->AutoSave();
delete newfile;

TCanvas *dddss = new TCanvas();

for (int i=0; i<nbins_time; i++){

  thits_data_bins[i]->SetTitle(Form("window: %4.0f -  %4.0f ns, %1.0f events; tank hits",time_bounds[i],time_bounds[i+1],thits_data_bins[i]->Integral()));
  thits_data_bins[i]->SetFillStyle(0);
  thits_data_bins[i]->SetMarkerStyle(20);
  thits_data_bins[i]->SetMarkerSize(0.7);
  thits_data_bins[i]->SetLineColor(1);
  thits_data_bins[i]->SetMarkerColor(2);
  thits_data_bins[i]->SetBarWidth(4);
  thits_data_bins[i]->SetLineWidth(1);

  thits_data_bins[i]->Draw("e1p");

  if (i==0) dddss->Print("five_batches_thits_time.ps(");
  if (i>0&&i<nbins_time-1) dddss->Print("five_batches_thits_time.ps");
  if (i==nbins_time-1) dddss->Print("five_batches_thits_time.ps)");

}

TCanvas *dddsslg = new TCanvas();

for (int i=0; i<nbins_time; i++){

  thits_data_bins_lg[i]->SetTitle(Form("window: %4.0f -  %4.0f ns, %1.0f events; tank hits",time_bounds[i],time_bounds[i+1],thits_data_bins_lg[i]->Integral()));
  thits_data_bins_lg[i]->SetFillStyle(0);
  thits_data_bins_lg[i]->SetMarkerStyle(20);
  thits_data_bins_lg[i]->SetMarkerSize(0.7);
  thits_data_bins_lg[i]->SetLineColor(1);
  thits_data_bins_lg[i]->SetMarkerColor(2);
  thits_data_bins_lg[i]->SetBarWidth(4);
  thits_data_bins_lg[i]->SetLineWidth(1);

  thits_data_bins_lg[i]->Draw("e1p");

  if (i==0) dddsslg->Print("five_batches_thits_time_lg.ps(");
  if (i>0&&i<nbins_time-1) dddsslg->Print("five_batches_thits_time_lg.ps");
  if (i==nbins_time-1) dddsslg->Print("five_batches_thits_time_lg.ps)");

}

for (int i=0; i<nbins_time; i++){
  thits_data_bins[i]->SetLineWidth(2);	
  thits_data_bins[i]->SetLineColor(i+1);	
}

TLegend *legCC2 = new TLegend(0.50,0.75,0.85,0.95);
legCC2->SetTextSize(0.035);
legCC2->SetTextColor(1);
for (int i=0; i<nbins_time; i++)
	legCC2->AddEntry(thits_data_bins[i],Form("%4.0f - %4.0f ns",time_bounds[i],time_bounds[i+1]),"l");
legCC2->SetFillColor(0);
legCC2->SetLineColor(1);
legCC2->SetTextFont(22);

thits_data_bins[0]->SetTitle("; tank hits");

TCanvas *fdsa = new TCanvas();
thits_data_bins[0]->DrawNormalized();
for (int i=1; i<nbins_time; i++)
  thits_data_bins[i]->DrawNormalized("same");	
legCC2->Draw();
fdsa->Print("time_bins_5_batches.eps");

time_data_0->SetLineWidth(2);
time_data_1->SetLineWidth(2);
time_data_2->SetLineWidth(2);
time_data_3->SetLineWidth(2);
time_data_4->SetLineWidth(2);
time_data_5->SetLineWidth(2);
time_data_6->SetLineWidth(2);
time_data_tot->SetLineWidth(2);

time_data_0->SetLineColor(kGreen);
time_data_1->SetLineColor(28);
time_data_2->SetLineColor(kMagenta);
time_data_3->SetLineColor(kCyan);
time_data_4->SetLineColor(5);
time_data_5->SetLineColor(kBlue);
time_data_6->SetLineColor(kRed);
time_data_tot->SetLineColor(kBlack);

time_data_tot->SetTitle("red: 6 batches blue: 5 batches; event time (ns)");

TCanvas *c2223 = new TCanvas();
time_data_tot->Draw("");
time_data_0->Draw("same");
time_data_1->Draw("same");
time_data_2->Draw("same");
time_data_3->Draw("same");
time_data_4->Draw("same");
time_data_5->Draw("same");
time_data_6->Draw("same");
c2223->Print("time_by_batch.eps");
c2223->SetLogy();
c2223->Print("time_by_batch_log.eps");

time_bet_events->SetTitle(";time between events (sec)");

TCanvas *c33332 = new TCanvas();
time_bet_events->Draw();
c33332->Print("time_bet_events.eps");

TFile batchfile1("batches.root","RECREATE");
time_data_tot->Write("time_data_tot");
time_data_0->Write("time_data_0");
time_data_1->Write("time_data_1");
time_data_2->Write("time_data_2");
time_data_3->Write("time_data_3");
time_data_4->Write("time_data_4");
time_data_5->Write("time_data_5");
time_data_6->Write("time_data_6");
batchfile1.Close();

//gifC->Print("thits_anim.gif++)");

float potPerFile = 1.772e18;
float dataPOT = 2.706e20;
float dataPOT_nu = 1.42e20;
float mcFiles = 100 * numMCfiles - 1;//100 files -> 1, and starts at 0001 instead of 0000
float mcPOT = potPerFile * mcFiles;
float scaleFactor = dataPOT/mcPOT;
float scaleFactor_nu = dataPOT_nu/mcPOT;

float potPerFile_dirt = 1.247e17;
float dirtPOT = potPerFile_dirt*1000;
float dirtScale = dataPOT/dirtPOT;
dirtScale *= 1.2;//from nu mode veto sample dirt fits
dirtScale *= 0.5;//from nubar veto sample dirt files (multiplicative with nu mode)

for (int i=0; i<ncuts; i++){
  //enuqe_tot_cuts[i]->Scale(scaleFactor_nu);
  //enuqe_nu_cuts[i]->Scale(scaleFactor_nu);
  //enuqe_nub_cuts[i]->Scale(scaleFactor_nu);

  //enuqe_tot_cuts[i]->Scale(myscale);
  //enuqe_nu_cuts[i]->Scale(myscale);
  //enuqe_nub_cuts[i]->Scale(myscale);

  enuqe_tot_cuts[i]->SetLineWidth(2);
  enuqe_nu_cuts[i]->SetLineWidth(2);
  enuqe_nub_cuts[i]->SetLineWidth(2);

  enuqe_nu_cuts[i]->SetLineColor(kRed);
  enuqe_nub_cuts[i]->SetLineColor(kBlue);

  enuqe_data_cuts[i]->SetFillStyle(0);
  enuqe_data_cuts[i]->SetMarkerStyle(20);
  enuqe_data_cuts[i]->SetMarkerSize(0.7);
  enuqe_data_cuts[i]->SetLineColor(1);
  enuqe_data_cuts[i]->SetMarkerColor(2);
  enuqe_data_cuts[i]->SetBarWidth(4);
  enuqe_data_cuts[i]->SetLineWidth(1);

}

truEnu_tot_norewt->Scale(scaleFactor);
truEnu_tot_rewt->Scale(scaleFactor);

truEnu_nu_norewt->Scale(scaleFactor);
truEnu_nubar_norewt->Scale(scaleFactor);

truEnu_nu_rewt->Scale(scaleFactor);
truEnu_nubar_rewt->Scale(scaleFactor);

tHits_tot_norewt->Scale(scaleFactor);
tHits_tot_rewt->Scale(scaleFactor);

tHits_nu_norewt->Scale(scaleFactor);
tHits_nubar_norewt->Scale(scaleFactor);

tHits_nu_rewt->Scale(scaleFactor);
tHits_nubar_rewt->Scale(scaleFactor);

truEnu_nu_norewt->SetLineWidth(2);
truEnu_nubar_norewt->SetLineWidth(2);
truEnu_nu_norewt->SetLineStyle(2);
truEnu_nubar_norewt->SetLineStyle(2);
truEnu_nu_norewt->SetLineColor(kRed);
truEnu_nubar_norewt->SetLineColor(kBlue);
truEnu_tot_norewt->SetLineWidth(2);
truEnu_tot_norewt->SetLineStyle(2);

truEnu_nu_rewt->SetLineWidth(2);
truEnu_nubar_rewt->SetLineWidth(2);
truEnu_nu_rewt->SetLineColor(kRed);
truEnu_nubar_rewt->SetLineColor(kBlue);
truEnu_tot_rewt->SetLineWidth(2);

tHits_nu_norewt->SetLineWidth(2);
tHits_nubar_norewt->SetLineWidth(2);
tHits_nu_norewt->SetLineStyle(2);
tHits_nubar_norewt->SetLineStyle(2);
tHits_nu_norewt->SetLineColor(kRed);
tHits_nubar_norewt->SetLineColor(kBlue);
tHits_tot_norewt->SetLineWidth(2);
tHits_tot_norewt->SetLineStyle(2);

tHits_nu_rewt->SetLineWidth(2);
tHits_nubar_rewt->SetLineWidth(2);
tHits_nu_rewt->SetLineColor(kRed);
tHits_nubar_rewt->SetLineColor(kBlue);
tHits_tot_rewt->SetLineWidth(2);

//tHits_data->Scale(3.43/1.42);//POT nubar/nu

truEnu_tot_norewt->SetTitle("event rates for 3.43e20 POT nu (nubar) mode: dashed (solid) numu (numubar): red (blue);E_{#nu} (GeV)");
tHits_tot_norewt->SetTitle("event rates for 3.43e20 POT nu (nubar) mode: dashed (solid) numu (numubar): red (blue);tank hits");

tHits_data->SetFillStyle(0);
tHits_data->SetMarkerStyle(20);
tHits_data->SetMarkerSize(0.7);
tHits_data->SetLineColor(1);
tHits_data->SetMarkerColor(2);
tHits_data->SetBarWidth(4);
tHits_data->SetLineWidth(1);

TCanvas *rewt_truEnuC = new TCanvas();
truEnu_tot_norewt->Draw();
truEnu_tot_rewt->Draw("same");
truEnu_nu_norewt->Draw("same");
truEnu_nubar_norewt->Draw("same");
truEnu_nu_rewt->Draw("same");
truEnu_nubar_rewt->Draw("same");
rewt_truEnuC->Print("enu_modes.eps");

tHits_tot_norewt->SetMaximum(2000);

TCanvas *rewt_tHitsC = new TCanvas();
tHits_tot_norewt->Draw();
tHits_tot_rewt->Draw("same");
tHits_nu_norewt->Draw("same");
tHits_nubar_norewt->Draw("same");
tHits_nu_rewt->Draw("same");
tHits_nubar_rewt->Draw("same");
tHits_data->Draw("e1p same");
rewt_tHitsC->Print("thits_modes.eps");

cout<<" data int "<<tHits_data->Integral()<<endl;

truEnu_tot_ratio->Divide(truEnu_tot_rewt,truEnu_tot_norewt);
truEnu_tot_ratio->SetTitle("bkg ratio;E_{#nu} (GeV);nubar/nu mode DIF ratio");

TCanvas *stbC = new TCanvas();
truEnu_tot_ratio->Draw();
stbC->Print("enu_rate_ratio.eps");

tHits_tot_ratio->Divide(tHits_tot_rewt,tHits_tot_norewt);
tHits_tot_ratio->SetTitle("bkg ratio;tank hits;nubar/nu mode DIF ratio");

TCanvas *stbth = new TCanvas();
tHits_tot_ratio->Draw();
stbth->Print("thit_rate_ratio.eps");

enuqe_tot_cuts[3]->SetTitle(";E_{#nu}^{QE} (GeV);");
enuqe_tot_cuts[3]->SetMaximum(1.2*enuqe_data_cuts[3]->GetMaximum());

TCanvas *numodeenuC = new TCanvas();
enuqe_tot_cuts[3]->Draw();
enuqe_nu_cuts[3]->Draw("same");
enuqe_nub_cuts[3]->Draw("same");
enuqe_data_cuts[3]->Draw("e1p same");
numodeenuC->Print("nu_mode_enuqe.eps");

float relnorm = thits_data->Integral()/tHits_tot_rewt->Integral();

double strobefactor = 0.367765;// from results in /scratch/condor-tmp/grange/strobeNubarPlot

thits_strobe->Scale(strobefactor);
thits_strobe->SetLineWidth(2);
thits_strobe->SetLineColor(95);

mich_dist_strobe->Scale(strobefactor);
mich_dist_strobe->SetLineWidth(2);
mich_dist_strobe->SetLineColor(95);

tru_tmu_strobe->Scale(strobefactor);
tru_tmu_strobe->SetLineWidth(2);
tru_tmu_strobe->SetLineColor(95);

thits_strobe_largerng->Scale(strobefactor);
thits_strobe_largerng->SetLineWidth(2);
thits_strobe_largerng->SetLineColor(95);

tmu_strobe_largerng->Scale(strobefactor);
tmu_strobe_largerng->SetLineWidth(2);
tmu_strobe_largerng->SetLineColor(95);

time_strobe->Scale(strobefactor);
time_strobe->SetLineWidth(2);
time_strobe->SetLineColor(95);

time_dirt->Scale(dirtScale);
time_dirt->SetLineWidth(2);
time_dirt->SetLineColor(28);

recoR_strobe->Scale(strobefactor);
recoR_strobe->SetLineWidth(2);
recoR_strobe->SetLineColor(95);

tHits_tot_rewt->Scale(relnorm);
tHits_nu_rewt->Scale(relnorm);
tHits_nubar_rewt->Scale(relnorm);

cout<<" data int "<<tHits_data->Integral()<<endl;
//for (int i=1; i<=tHits_data->GetNbinsX(); i++) cout<<" bin "<<i<<" content "<<tHits_data->GetBinContent(i)<<endl;

if (dospitz) tHits_tot_rewt->GetXaxis()->SetTitle("scaled tank hits");
if (dospitz==0) tHits_tot_rewt->GetXaxis()->SetTitle("tank hits");

int rebin = 2;
if (dospitz==0){
  tHits_tot_rewt->Rebin(rebin);
  tHits_nu_rewt->Rebin(rebin);
  tHits_nubar_rewt->Rebin(rebin);
  tHits_data->Rebin(rebin);
}

tHits_tot_rewt->SetMaximum(tHits_data->GetMaximum()*1.1);

TCanvas *thitC = new TCanvas();
tHits_tot_rewt->Draw();
tHits_nu_rewt->Draw("same");
tHits_nubar_rewt->Draw("same");
tHits_data->Draw("e1p same");
thitC->Print("tank_hits.eps");

data_time->GetXaxis()->SetTimeDisplay(1);
data_time->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%Y} %F 1970-01-01 00:00:00");//already CST
data_time->GetXaxis()->SetLabelOffset(0.02);

data_time->SetTitle("nubar mode numi data event timestamps");
data_time->SetLineColor(kBlue);

data_time_zm->GetXaxis()->SetTimeDisplay(1);
data_time_zm->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%Y} %F 1970-01-01 00:00:00");//already CST
data_time_zm->GetXaxis()->SetLabelOffset(0.02);

data_time_zm->SetTitle("nubar mode numi data event timestamps");
data_time_zm->SetLineColor(kBlue);

TCanvas *timeC22 = new TCanvas();
//timeC22->SetLogy();
data_time->Draw();
timeC22->Print("data_time.eps");

TCanvas *tidmeC22 = new TCanvas();
tidmeC22->SetLogy();
data_time_zm->Draw();
tidmeC22->Print("data_time_zm.eps");

//cout<<"!!!!!!!!!!! "<<thits_data->Integral()<<" "<<thits_mc[0]->Integral()<<endl;

relnorm = thits_data->Integral() / thits_mc[0]->Integral() * 0.7;
cout<<relnorm<<" "<<scaleFactor<<endl;
double myscale = 0.;
bool relnormB = 0;
if (relnormB==1) myscale = relnorm;
else myscale = scaleFactor;
cout<<"scale is "<<myscale<<endl;

chans_sig_nu->Scale(myscale);
chans_sig_nub->Scale(myscale);
chans_sig_dirt_nu->Scale(dirtScale);
chans_sig_dirt_nub->Scale(dirtScale);

for (int j=0; j<nModels; j++){ 
  
  thits_dirt[j]->Scale(dirtScale);
  thits_dirt[j]->SetLineWidth(2);
  thits_dirt[j]->SetLineColor(28);

  mich_dist_dirt[j]->Scale(dirtScale);
  mich_dist_dirt[j]->SetLineWidth(2);
  mich_dist_dirt[j]->SetLineColor(28);

  tru_tmu_dirt[j]->Scale(dirtScale);
  tru_tmu_dirt[j]->SetLineWidth(2);
  tru_tmu_dirt[j]->SetLineColor(28);
 
  thits_dirt_largerng[j]->Scale(dirtScale);
  thits_dirt_largerng[j]->SetLineWidth(2);
  thits_dirt_largerng[j]->SetLineColor(28);

  tmu_dirt_largerng[j]->Scale(dirtScale);
  tmu_dirt_largerng[j]->SetLineWidth(2);
  tmu_dirt_largerng[j]->SetLineColor(28);
 
  thits_pip[j]->SetLineWidth(2);
  thits_pip[j]->SetLineColor(kRed);
  thits_pip[j]->Scale(myscale);
  thits_pim[j]->SetLineWidth(2);
  thits_pim[j]->SetLineColor(kBlue);
  thits_pim[j]->Scale(myscale);
  thits_kp[j]->SetLineWidth(2);
  thits_kp[j]->SetLineColor(kMagenta);
  thits_kp[j]->Scale(myscale);
  thits_othr[j]->SetLineWidth(2);
  thits_othr[j]->SetLineColor(8);
  thits_othr[j]->Scale(myscale);

  thits_mc[j]->Scale(myscale);
  thits_mc[j]->SetLineWidth(2);
  thits_mc[j]->Add(thits_dirt[j]);
  thits_mc[j]->Add(thits_strobe);

  mich_dist_mc[j]->Scale(myscale);
  mich_dist_mc[j]->SetLineWidth(2);
  mich_dist_mc[j]->SetLineColor(1);
  mich_dist_mc[j]->Add(mich_dist_dirt[j]);
  mich_dist_mc[j]->Add(mich_dist_strobe);

  mich_dist_qe[j]->Scale(myscale);
  mich_dist_qe[j]->SetLineWidth(2);
  mich_dist_qe[j]->SetLineColor(kMagenta);
  mich_dist_pi[j]->Scale(myscale);
  mich_dist_pi[j]->SetLineWidth(2);
  mich_dist_pi[j]->SetLineColor(kGreen);
  
  thits_nu[j]->SetLineWidth(2);
  thits_nu[j]->SetLineColor(2);
  thits_nu[j]->Scale(myscale);

  thits_nub[j]->SetLineWidth(2);
  thits_nub[j]->SetLineColor(kBlue);
  thits_nub[j]->Scale(myscale);

  tru_tmu_mc[j]->Scale(myscale);
  tru_tmu_mc[j]->SetLineWidth(2);
  tru_tmu_mc[j]->Add(tru_tmu_dirt[j]);
  tru_tmu_mc[j]->Add(tru_tmu_strobe);
  
  tru_tmu_nu[j]->SetLineWidth(2);
  tru_tmu_nu[j]->SetLineColor(2);
  tru_tmu_nu[j]->Scale(myscale);

  tru_tmu_nub[j]->SetLineWidth(2);
  tru_tmu_nub[j]->SetLineColor(kBlue);
  tru_tmu_nub[j]->Scale(myscale);

  enuqe_mc[j]->Scale(myscale);
  enuqe_mc[j]->SetLineWidth(2);
  //enuqe_mc[j]->Add(enuqe_dirt[j]);
  //enuqe_mc[j]->Add(enuqe_strobe);
  
  enuqe_nu[j]->SetLineWidth(2);
  enuqe_nu[j]->SetLineColor(2);
  enuqe_nu[j]->Scale(myscale);

  enuqe_nub[j]->SetLineWidth(2);
  enuqe_nub[j]->SetLineColor(kBlue);
  enuqe_nub[j]->Scale(myscale);

  thits_mc_largerng[j]->Scale(myscale);
  thits_mc_largerng[j]->SetLineWidth(2);
  thits_mc_largerng[j]->Add(thits_dirt_largerng[j]);
  thits_mc_largerng[j]->Add(thits_strobe_largerng);

  thits_nu_largerng[j]->SetLineWidth(2);
  thits_nu_largerng[j]->SetLineColor(2);
  thits_nu_largerng[j]->Scale(myscale);

  thits_nub_largerng[j]->SetLineWidth(2);
  thits_nub_largerng[j]->SetLineColor(kBlue);
  thits_nub_largerng[j]->Scale(myscale);

  tmu_mc_largerng[j]->Scale(myscale);
  tmu_mc_largerng[j]->SetLineWidth(2);
  tmu_mc_largerng[j]->Add(tmu_dirt_largerng[j]);
  tmu_mc_largerng[j]->Add(tmu_strobe_largerng);

  tmu_nu_largerng[j]->SetLineWidth(2);
  tmu_nu_largerng[j]->SetLineColor(2);
  tmu_nu_largerng[j]->Scale(myscale);

  tmu_nub_largerng[j]->SetLineWidth(2);
  tmu_nub_largerng[j]->SetLineColor(kBlue);
  tmu_nub_largerng[j]->Scale(myscale);
  
}

TCanvas *fdas20 = new TCanvas();

if (dospitz) thits_data->GetXaxis()->SetTitle("scaled tank hits");

thits_data->SetFillStyle(0);
thits_data->SetMarkerStyle(20);
thits_data->SetMarkerSize(0.7);
thits_data->SetLineColor(1);
thits_data->SetMarkerColor(2);
thits_data->SetBarWidth(4);
thits_data->SetLineWidth(1);

mich_dist_data->SetFillStyle(0);
mich_dist_data->SetMarkerStyle(20);
mich_dist_data->SetMarkerSize(0.7);
mich_dist_data->SetLineColor(1);
mich_dist_data->SetMarkerColor(2);
mich_dist_data->SetBarWidth(4);
mich_dist_data->SetLineWidth(1);

enuqe_data->SetFillStyle(0);
enuqe_data->SetMarkerStyle(20);
enuqe_data->SetMarkerSize(0.7);
enuqe_data->SetLineColor(1);
enuqe_data->SetMarkerColor(2);
enuqe_data->SetBarWidth(4);
enuqe_data->SetLineWidth(1);

thits_data_largerng->SetFillStyle(0);
thits_data_largerng->SetMarkerStyle(20);
thits_data_largerng->SetMarkerSize(0.7);
thits_data_largerng->SetLineColor(1);
thits_data_largerng->SetMarkerColor(2);
thits_data_largerng->SetBarWidth(4);
thits_data_largerng->SetLineWidth(1);

tmu_data_largerng->SetFillStyle(0);
tmu_data_largerng->SetMarkerStyle(20);
tmu_data_largerng->SetMarkerSize(0.7);
tmu_data_largerng->SetLineColor(1);
tmu_data_largerng->SetMarkerColor(2);
tmu_data_largerng->SetBarWidth(4);
tmu_data_largerng->SetLineWidth(1);

thits_data->GetXaxis()->SetTitle("tank hits");
if (testst) thits_data->GetXaxis()->SetTitle("Stancu fitter energy (MeV)");
//begin sideband constraint studies

double data_int = 0.;
double model_int = 0.;



int bin_start = 1+((int)thitbins/2);//low edge should be 150 tank hits
int bin_stop  = thitbins;//high edge should be 300 tank hits

for (int j=0; j<nModels; j++){

  data_int = 0.;
  model_int = 0.;

  for (int i=bin_start; i<= bin_stop; i++){
    data_int += thits_data->GetBinContent(i);
	model_int += thits_mc[j]->GetBinContent(i);
  }

  cout<<" model "<<j<<" scaling by "<<data_int/model_int<<endl;
  thits_mc[j]->Scale(data_int/model_int);//actually scaling dirt, strobe too.  i don't think it matters.
  mich_dist_mc[j]->Scale(data_int/model_int);//actually scaling dirt, strobe too.  i don't think it matters.
  mich_dist_qe[j]->Scale(data_int/model_int);//actually scaling dirt, strobe too.  i don't think it matters.
  mich_dist_pi[j]->Scale(data_int/model_int);//actually scaling dirt, strobe too.  i don't think it matters.
  thits_nu[j]->Scale(data_int/model_int);
  thits_nub[j]->Scale(data_int/model_int);
  thits_mc_largerng[j]->Scale(data_int/model_int);
  thits_nu_largerng[j]->Scale(data_int/model_int);
  thits_nub_largerng[j]->Scale(data_int/model_int);

  tmu_mc_largerng[j]->Scale(data_int/model_int);
  tmu_nu_largerng[j]->Scale(data_int/model_int);
  tmu_nub_largerng[j]->Scale(data_int/model_int);

  tru_tmu_mc[j]->Scale(data_int/model_int);
  tru_tmu_nu[j]->Scale(data_int/model_int);
  tru_tmu_nub[j]->Scale(data_int/model_int);

}

TFile sidebandFile("sidebandfile.root","RECREATE");
thits_data->Write(thits_data->GetName());
for (int j=0; j<nModels; j++) 
	thits_mc[j]->Write(thits_mc[j]->GetName());
sig_enu->Write(sig_enu->GetName());
sb_enu->Write(sb_enu->GetName());
sig_qsq->Write(sig_qsq->GetName());
sb_qsq->Write(sb_qsq->GetName());
sidebandFile.Close();

cout<<" constraint start,end "<<thits_data->GetXaxis()->GetBinLowEdge(bin_start)<<","<<thits_data->GetXaxis()->GetBinUpEdge(bin_stop)<<endl;

ofstream datafile2;
datafile2.open("chi2_model.txt");

for (int j=0; j<nModels; j++){
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
  if (j==11) thits_data->SetTitle(Form("#kappa = %lf",0.978));
  if (j==12) thits_data->SetTitle(Form("#kappa = %lf",0.982));
  if (j==13) thits_data->SetTitle(Form("#kappa = %lf",0.984));
  if (j==14) thits_data->SetTitle(Form("#kappa = %lf",0.986));
  if (j==15) thits_data->SetTitle(Form("#kappa = %lf",0.988));
  if (j==16) thits_data->SetTitle(Form("#kappa = %lf",0.990));
  if (j==17) thits_data->SetTitle(Form("#kappa = %lf",0.992));
  if (j==18) thits_data->SetTitle(Form("#kappa = %lf",0.994));
  if (j==19) thits_data->SetTitle(Form("#kappa = %lf",0.996));
  if (j==20) thits_data->SetTitle(Form("#kappa = %lf",0.998));
  thits_data->Draw("e1p");
  thits_dirt[j]->Draw("same");
  thits_strobe->Draw("same");
  thits_mc[j]->Draw("same");
  thits_nu[j]->Draw("same");
  thits_nub[j]->Draw("same");
  //thits_kp[j]->Draw("same");
  //thits_pip[j]->Draw("same");
  //thits_pim[j]->Draw("same");
  //thits_othr[j]->Draw("same");
  if (j==0) fdas20->Print("varyKappa_numi_nubar_thits.ps(");
  if (j>0&&j<nModels-1) fdas20->Print("varyKappa_numi_nubar_thits.ps");
  if (j==nModels-1) fdas20->Print("varyKappa_numi_nubar_thits.ps)");

  if (testst){ 
    if (j==0) fdas20->Print("varyKappa_numi_nubar_stfull.ps(");
    if (j>0&&j<nModels-1) fdas20->Print("varyKappa_numi_nubar_stfull.ps");
    if (j==nModels-1) fdas20->Print("varyKappa_numi_nubar_stfull.ps)");
  } 


TCanvas *c404 = new TCanvas();

for (int j=0; j<nModels; j++){
  if (j==0) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.022));
  if (j==1) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.000));
  if (j==2) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.002));
  if (j==3) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.004));
  if (j==4) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.006));
  if (j==5) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.008));
  if (j==6) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.010));
  if (j==7) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.012));
  if (j==8) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.014));
  if (j==9) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.016));
  if (j==10) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",1.018));
  if (j==11) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.978));
  if (j==12) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.982));
  if (j==13) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.984));
  if (j==14) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.986));
  if (j==15) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.988));
  if (j==16) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.990));
  if (j==17) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.992));
  if (j==18) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.994));
  if (j==19) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.996));
  if (j==20) mich_dist_data->SetTitle(Form("tank hits < 150 time < 2500 ns #kappa = %lf; Michel distance (cm)",0.998));
  mich_dist_data->Draw("e1p");
  mich_dist_dirt[j]->Draw("same");
  mich_dist_strobe->Draw("same");
  mich_dist_mc[j]->Draw("same");
  mich_dist_qe[j]->Draw("same");
  mich_dist_pi[j]->Draw("same");
  //mich_dist_kp[j]->Draw("same");
  //mich_dist_pip[j]->Draw("same");
  //mich_dist_pim[j]->Draw("same");
  //mich_dist_othr[j]->Draw("same");
  if (j==0) c404->Print("varyKappa_mich_dist.ps(");
  if (j>0&&j<nModels-1) c404->Print("varyKappa_mich_dist.ps");
  if (j==nModels-1) c404->Print("varyKappa_mich_dist.ps)"); 

  }


  cout<<" tank hits model "<<j<<" data - bkg "<<thits_data->Integral()-thits_mc[j]->Integral()<<endl;
  //spitzVarPred_k1->Draw("same");
  
     double chi2=0;
  
  for(int ii=bin_start;ii<=bin_stop;ii++)
  {
  chi2+=pow(thits_mc[j]->GetBinContent(ii)-thits_data->GetBinContent(ii),2)/pow(thits_data->GetBinError(ii),2);

  }
  cout<<"Model "<<j<<" ...chi2= "<<chi2<<endl;
  
  


datafile2<<"Model "<<j<<" ... chi2= "<<chi2<<endl;
 datafile2 << "\n"; 
}

ofstream datafile;
datafile.open("tank_hits_data_dump_joe.txt");// open input file


for (int i=1; i<=thits_data->GetNbinsX(); i++){
	datafile << thits_data->GetXaxis()->GetBinLowEdge(i);
    datafile << "\t";
	datafile << thits_data->GetXaxis()->GetBinUpEdge(i);
    datafile << "\t";
	datafile << thits_data->GetBinContent(i);
    datafile << "\n";
}

TCanvas *fdas202 = new TCanvas();

for (int j=0; j<nModels; j++){
  if (j==0) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.022));
  if (j==1) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.000));
  if (j==2) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.002));
  if (j==3) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.004));
  if (j==4) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.006));
  if (j==5) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.008));
  if (j==6) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.010));
  if (j==7) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.012));
  if (j==8) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.014));
  if (j==9) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.016));
  if (j==10) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",1.018));
  if (j==11) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.978));
  if (j==12) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.982));
  if (j==13) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.984));
  if (j==14) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.986));
  if (j==15) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.988));
  if (j==16) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.990));
  if (j==17) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.992));
  if (j==18) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.994));
  if (j==19) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.996));
  if (j==20) thits_data_largerng->SetTitle(Form("#kappa = %lf; tank hits",0.998));
  thits_data_largerng->Draw("e1p");
  //thits_dirt[j]->Draw("same");
  //thits_strobe->Draw("same");
  thits_mc_largerng[j]->Draw("same");
  thits_nu_largerng[j]->Draw("same");
  thits_nub_largerng[j]->Draw("same");
  thits_dirt_largerng[j]->Draw("same");
  thits_strobe_largerng->Draw("same");
  //legCC->Draw();

  if (j==0) fdas202->Print("varyKappa_numi_nubar_thits_fullrng.ps(");
  if (j>0&&j<nModels-1) fdas202->Print("varyKappa_numi_nubar_thits_fullrng.ps");
  if (j==nModels-1) fdas202->Print("varyKappa_numi_nubar_thits_fullrng.ps)");

  if (testst){
    if (j==0) fdas202->Print("varyKappa_numi_nubar_stfull_fullrng.ps(");
    if (j>0&&j<nModels-1) fdas202->Print("varyKappa_numi_nubar_stfull_fullrng.ps");
    if (j==nModels-1) fdas202->Print("varyKappa_numi_nubar_stfull_fullrng.ps)");
  }  

  //cout<<" tank hits model "<<j<<" data - bkg "<<thits_data_largerng->Integral()-thits_mc[j]->Integral()<<endl;
  //spitzVarPred_k1->Draw("same");
}



TCanvas *fdas2026 = new TCanvas();

for (int j=0; j<nModels; j++){
  if (j==0) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.022));
  if (j==1) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.000));
  if (j==2) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.002));
  if (j==3) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.004));
  if (j==4) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.006));
  if (j==5) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.008));
  if (j==6) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.010));
  if (j==7) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.012));
  if (j==8) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.014));
  if (j==9) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.016));
  if (j==10) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",1.018));
  if (j==11) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.978));
  if (j==12) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.982));
  if (j==13) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.984));
  if (j==14) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.986));
  if (j==15) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.988));
  if (j==16) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.990));
  if (j==17) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.992));
  if (j==18) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.994));
  if (j==19) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.996));
  if (j==20) tmu_data_largerng->SetTitle(Form("#kappa = %lf;reco T_{#mu} (GeV)",0.998));
  tmu_data_largerng->Draw("e1p");
  //tmu_dirt[j]->Draw("same");
  //tmu_strobe->Draw("same");
  tmu_mc_largerng[j]->Draw("same");
  tmu_nu_largerng[j]->Draw("same");
  tmu_nub_largerng[j]->Draw("same");
  tmu_dirt_largerng[j]->Draw("same");
  tmu_strobe_largerng->Draw("same");

  if (j==0) fdas2026->Print("varyKappa_numi_nubar_tmu_fullrng.ps(");
  if (j>0&&j<nModels-1) fdas2026->Print("varyKappa_numi_nubar_tmu_fullrng.ps");
  if (j==nModels-1) fdas2026->Print("varyKappa_numi_nubar_tmu_fullrng.ps)");
  
  //cout<<" tank hits model "<<j<<" data - bkg "<<thits_data_largerng->Integral()-thits_mc[j]->Integral()<<endl;
  //spitzVarPred_k1->Draw("same");
}


TCanvas *fdas2022 = new TCanvas();

enuqe_data->SetTitle("assumes bnb dir!;E_{#nu}^{QE} (GeV)");

for (int j=0; j<nModels; j++){
  if (j==0) enuqe_data->SetTitle(Form("#kappa = %lf",1.022));
  if (j==1) enuqe_data->SetTitle(Form("#kappa = %lf",1.000));
  if (j==2) enuqe_data->SetTitle(Form("#kappa = %lf",1.002));
  if (j==3) enuqe_data->SetTitle(Form("#kappa = %lf",1.004));
  if (j==4) enuqe_data->SetTitle(Form("#kappa = %lf",1.006));
  if (j==5) enuqe_data->SetTitle(Form("#kappa = %lf",1.008));
  if (j==6) enuqe_data->SetTitle(Form("#kappa = %lf",1.010));
  if (j==7) enuqe_data->SetTitle(Form("#kappa = %lf",1.012));
  if (j==8) enuqe_data->SetTitle(Form("#kappa = %lf",1.014));
  if (j==9) enuqe_data->SetTitle(Form("#kappa = %lf",1.016));
  if (j==10) enuqe_data->SetTitle(Form("#kappa = %lf",1.018));
  if (j==11) enuqe_data->SetTitle(Form("#kappa = %lf",0.978));
  if (j==12) enuqe_data->SetTitle(Form("#kappa = %lf",0.982));
  if (j==13) enuqe_data->SetTitle(Form("#kappa = %lf",0.984));
  if (j==14) enuqe_data->SetTitle(Form("#kappa = %lf",0.986));
  if (j==15) enuqe_data->SetTitle(Form("#kappa = %lf",0.988));
  if (j==16) enuqe_data->SetTitle(Form("#kappa = %lf",0.990));
  if (j==17) enuqe_data->SetTitle(Form("#kappa = %lf",0.992));
  if (j==18) enuqe_data->SetTitle(Form("#kappa = %lf",0.994));
  if (j==19) enuqe_data->SetTitle(Form("#kappa = %lf",0.996));
  if (j==20) enuqe_data->SetTitle(Form("#kappa = %lf",0.998));
  enuqe_data->Draw("e1p");
  enuqe_mc[j]->Draw("same");
  enuqe_nu[j]->Draw("same");
  enuqe_nub[j]->Draw("same");

  if (j==0) fdas2022->Print("varyKappa_numi_nubar_enuqe.ps(");
  if (j>0&&j<nModels-1) fdas2022->Print("varyKappa_numi_nubar_enuqe.ps");
  if (j==nModels-1) fdas2022->Print("varyKappa_numi_nubar_enuqe.ps)");
  
  //cout<<" tank hits model "<<j<<" data - bkg "<<enuqe_data_largerng->Integral()-enuqe_mc[j]->Integral()<<endl;
  //spitzVarPred_k1->Draw("same");
}



TCanvas *bkgC = new TCanvas();

for (int j=0; j<nModels; j++){// 
// 
  thits_bkgsubt[j]->Sumw2();
  thits_bkgsubt[j]->Add(thits_data,1);
  thits_bkgsubt[j]->Add(thits_mc[j],-1);
//   
   signal_template[j]->Scale(thits_bkgsubt[j]->Integral()/signal_template[j]->Integral());
//   signal_tmu[j]->Scale(thits_bkgsubt[j]->Integral()/signal_tmu[j]->Integral());
//   
  for (int i=1; i<=thits_bkgsubt[j]->GetNbinsX(); i++)
  	thits_bkgsubt[j]->SetBinError(i,sqrt(thits_data->GetBinContent(i)));
  if (dospitz) thits_bkgsubt[j]->GetXaxis()->SetTitle("scaled tank hits");
  if (dospitz==0) thits_bkgsubt[j]->GetXaxis()->SetTitle("tank hits");

  thits_bkgsubt[j]->SetFillStyle(0);
  thits_bkgsubt[j]->SetMarkerStyle(20);
  thits_bkgsubt[j]->SetMarkerSize(0.7);
  thits_bkgsubt[j]->SetLineColor(1);
  thits_bkgsubt[j]->SetMarkerColor(2);
  thits_bkgsubt[j]->SetBarWidth(4);
  thits_bkgsubt[j]->SetLineWidth(1);

  thits_bkgsubt[j]->Fit("gaus");
// 
//   if (j==0) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.022,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==1) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.000,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==2) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.002,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==3) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.004,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==4) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.006,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==5) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.008,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==6) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.010,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==7) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.012,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==8) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.014,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==9) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.016,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==10) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",1.018,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==11) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.978,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==12) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.982,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==13) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.984,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==14) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.986,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==15) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.988,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==16) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.990,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==17) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.992,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==18) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.994,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==19) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.996,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
//   if (j==20) thits_bkgsubt[j]->SetTitle(Form("#kappa = %2.3f, mean = %2.1f, sigma = %2.1f, strength = %2.1f, #chi^{2}/dof = %2.1f",0.998,thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(1),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(2),thits_bkgsubt[j]->GetFunction("gaus")->GetParameter(0),thits_bkgsubt[j]->GetFunction("gaus")->GetChisquare()/(thits_bkgsubt[j]->GetNbinsX()-3)));
// 
  thits_bkgsubt[j]->Draw("e1p");
  if (j==0) bkgC->Print("varyKappa_bkgsubt.ps(");
  if (j>0&&j<nModels-1) bkgC->Print("varyKappa_bkgsubt.ps");
  if (j==nModels-1) bkgC->Print("varyKappa_bkgsubt.ps)");
// 
}

TCanvas *cutsC = new TCanvas();

thits_data_cuts[0]->SetTitle("1. 2SE + veto hits");
thits_data_cuts[1]->SetTitle("2. + beam window (2.8 --> 17.5#mus)");
thits_data_cuts[2]->SetTitle("3. + 2nd SE tank hits > 20 && < 200");
thits_data_cuts[3]->SetTitle("4. + vertex radius < 500 cm (TransRFull)");
thits_data_cuts[4]->SetTitle("5. + 1st SE tank hits < 20");
thits_data_cuts[5]->SetTitle("6. + PMT hit time rms < 50 ns");
thits_data_cuts[6]->SetTitle("7. + Michel distance < 100 cm");

TLegend *legCC = new TLegend(0.50,0.75,0.85,0.95);
legCC->SetTextSize(0.035);
legCC->SetTextColor(1);
legCC->AddEntry(thits_data_cuts[0],"Data","elp");
legCC->AddEntry(thits_nu_cuts[0],"#nu_{#mu} DIF","l");
legCC->AddEntry(thits_nub_cuts[0],"#bar{#nu}_{#mu} DIF","l");
legCC->AddEntry(thits_strobe_cuts[0],"strobe","l");
legCC->AddEntry(thits_dirt_cuts[0],"dirt","l");
legCC->AddEntry(thits_tot_cuts[0],"MC + strobe (total pred)","l");
legCC->SetFillColor(0);
legCC->SetLineColor(1);
legCC->SetTextFont(22);

for (int i=0; i<ncuts; i++){

  thits_data_cuts[i]->GetXaxis()->SetTitle("tank hits");

  thits_data_cuts[i]->SetFillStyle(0);
  thits_data_cuts[i]->SetMarkerStyle(20);
  thits_data_cuts[i]->SetMarkerSize(0.7);
  thits_data_cuts[i]->SetLineColor(1);
  thits_data_cuts[i]->SetMarkerColor(2);
  thits_data_cuts[i]->SetBarWidth(4);
  thits_data_cuts[i]->SetLineWidth(1);

  thits_dirt_cuts[i]->SetLineWidth(2);
  thits_dirt_cuts[i]->SetLineColor(28);
  thits_dirt_cuts[i]->Scale(dirtScale);

  thits_tot_cuts[i]->SetLineWidth(2);
  thits_nu_cuts[i]->SetLineWidth(2);
  thits_nub_cuts[i]->SetLineWidth(2);

  thits_nu_cuts[i]->SetLineColor(2);
  thits_nub_cuts[i]->SetLineColor(kBlue);

  thits_tot_cuts[i]->Scale(myscale);
  thits_nu_cuts[i]->Scale(myscale);
  thits_nub_cuts[i]->Scale(myscale);

  thits_strobe_cuts[i]->SetLineWidth(2);
  thits_strobe_cuts[i]->SetLineColor(95);
  thits_strobe_cuts[i]->Scale(strobefactor);

  thits_tot_cuts[i]->Add(thits_strobe_cuts[i]);
  thits_tot_cuts[i]->Add(thits_dirt_cuts[i]);
  thits_tot_cuts[i]->SetMaximum(thits_data_cuts[i]->GetMaximum()*1.1);

  thits_data_cuts[i]->Draw("e1p");
  thits_tot_cuts[i]->Draw("same");
  thits_nu_cuts[i]->Draw("same");
  thits_nub_cuts[i]->Draw("same");
  thits_strobe_cuts[i]->Draw("same");
  thits_dirt_cuts[i]->Draw("same");
  thits_data_cuts[i]->Draw("e1p same");
  if (i==0) legCC->Draw();

  if (i==0) cutsC->Print("numi_nubar_thits_cuts.ps(");
  if (i>0&&i<ncuts-1) cutsC->Print("numi_nubar_thits_cuts.ps");
  if (i==ncuts-1) cutsC->Print("numi_nubar_thits_cuts.ps)");

  cutsC->Print(Form("thits_cuts_%d.eps",i+1));

}

enuqe_data_cuts[0]->SetTitle("2SE + veto hits");
enuqe_data_cuts[1]->SetTitle("beam window (2.8 --> 11.5#mus)");
enuqe_data_cuts[2]->SetTitle("2nd SE tank hits > 20 && < 200");
enuqe_data_cuts[3]->SetTitle("vertex radius < 500 cm (P-fitter) && 1st SE tank hits < 20 && 1st SE tank hits < 250 && tank rms time < 50 ns");

TCanvas *cutsC2 = new TCanvas();

for (int i=0; i<ncuts; i++){

  enuqe_data_cuts[i]->GetXaxis()->SetTitle("EnuQE (GeV) [assumes BNB dir]");

  enuqe_data_cuts[i]->SetFillStyle(0);
  enuqe_data_cuts[i]->SetMarkerStyle(20);
  enuqe_data_cuts[i]->SetMarkerSize(0.7);
  enuqe_data_cuts[i]->SetLineColor(1);
  enuqe_data_cuts[i]->SetMarkerColor(2);
  enuqe_data_cuts[i]->SetBarWidth(4);
  enuqe_data_cuts[i]->SetLineWidth(1);

  enuqe_dirt_cuts[i]->SetLineWidth(2);
  enuqe_dirt_cuts[i]->SetLineColor(28);
  enuqe_dirt_cuts[i]->Scale(dirtScale);

  enuqe_strobe_cuts[i]->SetLineWidth(2);
  enuqe_strobe_cuts[i]->SetLineColor(95);
  enuqe_strobe_cuts[i]->Scale(strobefactor);

  enuqe_tot_cuts[i]->SetLineWidth(2);
  enuqe_nu_cuts[i]->SetLineWidth(2);
  enuqe_nub_cuts[i]->SetLineWidth(2);

  enuqe_nu_cuts[i]->SetLineColor(2);
  enuqe_nub_cuts[i]->SetLineColor(kBlue);

  enuqe_tot_cuts[i]->Scale(myscale);
  enuqe_nu_cuts[i]->Scale(myscale);
  enuqe_nub_cuts[i]->Scale(myscale);

  enuqe_data_cuts[i]->Draw("e1p");
  enuqe_tot_cuts[i]->Draw("same");
  enuqe_nu_cuts[i]->Draw("same");
  enuqe_nub_cuts[i]->Draw("same");
  enuqe_strobe_cuts[i]->Draw("same");
  enuqe_dirt_cuts[i]->Draw("same");
  enuqe_data_cuts[i]->Draw("e1p same");

  if (i==0) cutsC2->Print("numi_nubar_enuqe_cuts.ps(");
  if (i>0&&i<ncuts-1) cutsC2->Print("numi_nubar_enuqe_cuts.ps");
  if (i==ncuts-1) cutsC2->Print("numi_nubar_enuqe_cuts.ps)");

}

time_data->SetFillStyle(0);
time_data->SetMarkerStyle(20);
time_data->SetMarkerSize(0.7);
time_data->SetLineColor(1);
time_data->SetMarkerColor(2);
time_data->SetBarWidth(4);
time_data->SetLineWidth(1);

time_data->SetTitle("all analysis cuts except beam time;event time (ns)");

TCanvas *winC = new TCanvas();
time_data->Draw("e1p");
// time_strobe->Draw("same");
// time_dirt->Draw("same");
winC->Print("beam_window.eps");
winC->SetLogy();
winC->Print("beam_window_log.eps");

recoR_dirt->Scale(dirtScale);
recoR_dirt->SetLineWidth(2);
recoR_dirt->SetLineColor(28);

recoR_data->SetFillStyle(0);
recoR_data->SetMarkerStyle(20);
recoR_data->SetMarkerSize(0.7);
recoR_data->SetLineColor(1);
recoR_data->SetMarkerColor(2);
recoR_data->SetBarWidth(4);
recoR_data->SetLineWidth(1);

recoR_data->SetTitle("; fitted radius (cm) [OneTrack]");

TCanvas *rC = new TCanvas();
recoR_data->Draw("e1p");
recoR_strobe->Draw("same");
recoR_dirt->Draw("same");
rC->Print("muR.eps");
rC->SetLogy();
rC->Print("muR_log.eps");

for (int i=0; i<nModels; i++){
  tHit1_eff[i]->Divide(tHit1_wCut[i],tHit1_noCut[i]);
  tHit1_eff[i]->SetLineWidth(2);
  tHit1_eff[i]->GetXaxis()->SetTitle("tank hits");
  tHit1_eff[i]->GetXaxis()->CenterTitle(1);

  tHit1_eff_incr_Mich[i]->Divide(tHit1_wCut[i],tHit1_befMich[i]);
  tHit1_eff_incr_Mich[i]->SetLineWidth(2);
  tHit1_eff_incr_Mich[i]->GetXaxis()->SetTitle("tank hits");
  tHit1_eff_incr_Mich[i]->GetXaxis()->CenterTitle(1);

  tHit1_eff[i]->GetYaxis()->SetTitle("efficiency");
  tHit1_eff[i]->GetYaxis()->CenterTitle(1);

  tHit1_eff_incr_Mich[i]->GetYaxis()->SetTitle("add'l efficiency due to Michel distance");
  tHit1_eff_incr_Mich[i]->GetYaxis()->CenterTitle(1);

  tmu_eff[i]->Divide(tmu_wCut[i],tmu_noCut[i]);
  tmu_eff[i]->SetLineWidth(2);
  tmu_eff[i]->GetXaxis()->SetTitle("gen T_{#mu} (MeV)");
  tmu_eff[i]->GetXaxis()->CenterTitle(1);

  tmu_eff[i]->GetYaxis()->SetTitle("efficiency");
  tmu_eff[i]->GetYaxis()->CenterTitle(1);

  tmu_eff_josh[i]->Divide(tmu_wCut_josh[i],tmu_noCut_josh[i]);

  tmu_eff_unfold[i]->Divide(tmu_wCut_unfold[i],tmu_noCut_unfold[i]);
  tmu_eff_unfold[i]->SetLineWidth(2);
  tmu_eff_unfold[i]->GetXaxis()->SetTitle("gen T_{#mu} (MeV)");
  tmu_eff_unfold[i]->GetXaxis()->CenterTitle(1);

  tmu_eff_unfold[i]->GetYaxis()->SetTitle("efficiency");
  tmu_eff_unfold[i]->GetYaxis()->CenterTitle(1);
}

for (int j=0; j<nModels; j++){

  for (int i=1; i<=signal_tmu[j]->GetNbinsX(); i++) 
  	signal_tmu[j]->SetBinContent(i,signal_tmu[j]->GetBinContent(i)*tmu_eff_unfold[j]->GetBinContent(i));

}

for (int j=0; j<nModels; j++){// 
   
  signal_tmu[j]->Scale(thits_bkgsubt[j]->Integral()/signal_tmu[j]->Integral());
  
}

TString filename = "unfoldFile.root";
if (numMCfiles==50) filename = "unfoldFile_fullmcstats.root";

TFile unfoldFile(filename.Data(),"RECREATE");

for (int i=0; i<nModels; i++){
  truTmu_tHit1[i]->Write(truTmu_tHit1[i]->GetName());
  thits_bkgsubt[i]->Write(thits_bkgsubt[i]->GetName());
  tru_tmu_tank_hits_fold[i]->Write(tru_tmu_tank_hits_fold[i]->GetName());
  tHit1_noCut[i]->Write(tHit1_noCut[i]->GetName());
  tHit1_wCut[i]->Write(tHit1_wCut[i]->GetName());
  tHit1_eff[i]->Write(tHit1_eff[i]->GetName());
  tHit1_eff_incr_Mich[i]->Write(tHit1_eff_incr_Mich[i]->GetName());
  tmu_noCut[i]->Write(tmu_noCut[i]->GetName());
  tmu_wCut[i]->Write(tmu_wCut[i]->GetName());
  tmu_eff[i]->Write(tmu_eff[i]->GetName());
  tmu_eff_unfold[i]->Write(tmu_eff_unfold[i]->GetName());
  tmu_eff_josh[i]->Write(tmu_eff_josh[i]->GetName());
  thits_dirt[i]->Write(thits_dirt[i]->GetName());
}

thits_data->Write(thits_data->GetName());

thits_strobe->Write(thits_strobe->GetName());

thits_recoMC->Write(thits_recoMC->GetName());
thits_tmuCorr_toy->Write(thits_tmuCorr_toy->GetName());
tmu_truMC->Write(tmu_truMC->GetName());

thits_recoMC_fold->Write(thits_recoMC_fold->GetName());
thits_tmuCorr_toy_fold->Write(thits_tmuCorr_toy_fold->GetName());
tmu_truMC_fold->Write(tmu_truMC_fold->GetName());

unfoldFile.Close();

tHit1_dirt->Scale(dirtScale);
tHit1_strobe->Scale(strobefactor);

//tHit1_tot->Add(tHit1_strobe);
//tHit1_tot->Add(tHit1_dirt);

TCanvas *thiteff = new TCanvas();
for (int i=0; i<nModels; i++){
  tHit1_eff[i]->Draw();
  if (i==0) thiteff->Print("tankHitEff.ps(");
  if (i>0&&i<nModels-1) thiteff->Print("tankHitEff.ps");
  if (i==nModels-1) thiteff->Print("tankHitEff.ps)");
}
spitztime_out->SetLineWidth(2);
spitztime_in->SetLineWidth(2);
spitztime_mid->SetLineWidth(2);
spitztime_out->SetLineColor(kRed);
spitztime_in->SetLineColor(kBlue);
spitztime_mid->SetLineColor(kBlack);

spitztime_out_5->SetLineWidth(2);
spitztime_in_5->SetLineWidth(2);
spitztime_mid_5->SetLineWidth(2);
spitztime_out_5->SetLineColor(kRed);
spitztime_in_5->SetLineColor(kBlue);
spitztime_mid_5->SetLineColor(kBlack);

spitztime_out->SetTitle("data only; beam avg time (ns)");

TLegend *legTT = new TLegend(0.7,0.80,0.99,0.95);
legTT->SetTextSize(0.035);
legTT->SetTextColor(1);
legTT->AddEntry(spitztime_in,"PMT hits < 150","l");
legTT->AddEntry(spitztime_mid,"150 < PMT hits < 300","l");
legTT->AddEntry(spitztime_out,"PMT hits > 300","l");
legTT->SetFillColor(0);
legTT->SetLineColor(1);
legTT->SetTextFont(22);

TLine *line12 = new TLine(11130,0,11130,550);
line12->SetLineStyle(2);
line12->SetLineWidth(2);

TLine *line22 = new TLine(11250,0,11250,550);
line22->SetLineStyle(2);
line22->SetLineWidth(2);

TLine *line32 = new TLine(11750,0,11750,550);
line32->SetLineStyle(2);
line32->SetLineWidth(2);

//TLine *line42 = new TLine(11750,0,11750,700);
//line42->SetLineStyle(2);
//line42->SetLineWidth(2);

TCanvas *spitzChk = new TCanvas();
spitztime_out->Draw();
spitztime_mid->Draw("same");
spitztime_in->Draw("same");
//line12->Draw();
//line22->Draw();
//line32->Draw();
legTT->Draw();
spitzChk->Print("timeChk.eps");

TCanvas *spitzChk_5 = new TCanvas();
spitztime_out_5->Draw();
spitztime_mid_5->Draw("same");
spitztime_in_5->Draw("same");
legTT->Draw();
spitzChk_5->Print("timeChk_5.eps");
spitzChk_5->SetLogy();
spitzChk_5->Print("timeChk_5_log.eps");

spitztime_out_ratio->Divide(spitztime_out,spitztime_tot);
spitztime_in_ratio->Divide(spitztime_in,spitztime_tot);
spitztime_mid_ratio->Divide(spitztime_mid,spitztime_tot);
spitztime_out_ratio->SetLineWidth(2);
spitztime_in_ratio->SetLineWidth(2);
spitztime_mid_ratio->SetLineWidth(2);
spitztime_out_ratio->SetLineColor(kRed);
spitztime_in_ratio->SetLineColor(kBlue);
spitztime_mid_ratio->SetLineColor(kBlack);

for (int i=1; i<=spitztime_out_ratio_5->GetNbinsX(); i++){

  if (spitztime_tot_5->GetBinContent(i)<10) continue;
  spitztime_out_ratio_5->SetBinContent(i,spitztime_out_5->GetBinContent(i) / spitztime_tot_5->GetBinContent(i));  
  spitztime_in_ratio_5->SetBinContent(i,spitztime_in_5->GetBinContent(i) / spitztime_tot_5->GetBinContent(i));  
  spitztime_mid_ratio_5->SetBinContent(i,spitztime_mid_5->GetBinContent(i) / spitztime_tot_5->GetBinContent(i));  

  spitztime_in_ratio_5->SetBinError(i,sqrt(spitztime_in_5->GetBinContent(i))/spitztime_in_5->GetBinContent(i) * spitztime_in_ratio_5->GetBinContent(i));

}
//spitztime_out_ratio_5->Divide(spitztime_out_5,spitztime_tot_5);
//spitztime_in_ratio_5->Divide(spitztime_in_5,spitztime_tot_5);
//spitztime_mid_ratio_5->Divide(spitztime_mid_5,spitztime_tot_5);

spitztime_out_ratio_5->SetLineWidth(2);
spitztime_in_ratio_5->SetLineWidth(2);
spitztime_mid_ratio_5->SetLineWidth(2);
spitztime_out_ratio_5->SetLineColor(kRed);
spitztime_in_ratio_5->SetLineColor(kBlue);
spitztime_mid_ratio_5->SetLineColor(kBlack);

spitztime_out_ratio->SetTitle("data only; beam avg time (ns); ratio to total");

spitztime_out_ratio_5->SetTitle("5 batch data only min 10 total events; beam avg time (ns); ratio to total");

spitztime_out_ratio->SetMaximum(1.);

TLine *line1 = new TLine(11130,0,11130,1);
line1->SetLineStyle(2);
line1->SetLineWidth(2);

TLine *line2 = new TLine(11250,0,11250,1);
line2->SetLineStyle(2);
line2->SetLineWidth(2);

TLine *line3 = new TLine(11750,0,11750,1);
line3->SetLineStyle(2);
line3->SetLineWidth(2);

TCanvas *spitzChkR = new TCanvas();
spitztime_out_ratio->Draw();
spitztime_mid_ratio->Draw("same");
spitztime_in_ratio->Draw("same");
//line1->Draw();
//line2->Draw();
//line3->Draw();
legTT->Draw();
spitzChkR->Print("timeChk_ratio.eps");
spitzChkR->SetLogy();
spitzChkR->Print("timeChk_ratio_log.eps");



TCanvas *spitzChkR_5 = new TCanvas();
spitztime_out_ratio_5->Draw();
spitztime_mid_ratio_5->Draw("same");
spitztime_in_ratio_5->Draw("same");
//line1->Draw();
//line2->Draw();
//line3->Draw();
legTT->Draw();
spitzChkR_5->Print("timeChk_ratio_5.eps");

TCanvas *cc34 = new TCanvas();
spitztime_in_ratio_5->Draw("e1p");
cc34->Print("sig_region_ratio_w_err.eps");

thits_late->SetLineWidth(2);
thits_late->SetLineColor(kBlue);
thits_normal->SetLineWidth(2);
thits_normal->SetLineColor(kRed);

thits_late->SetTitle("blue: avg time > 11.3 us red: normal time cut;tank hits");

TCanvas *llld = new TCanvas();
thits_late->DrawNormalized();
thits_normal->DrawNormalized("same");
llld->Print("thits_late_vs_normal.eps");

cout<<" mc scale is "<<myscale<<endl;

cout<<" sideband constraint start,end "<<thits_data->GetXaxis()->GetBinLowEdge(bin_start)<<","<<thits_data->GetXaxis()->GetBinUpEdge(bin_stop)<<endl;

TString filename2 = "./bkg_templates.root";
if (numMCfiles==50) filename2 = "./bkg_templates_fullmcstats.root";

TFile timingfile(filename2.Data(),"RECREATE");
for (int i=0; i<nModels; i++){
  thits_mc[i]->Write(thits_mc[i]->GetName());
  thits_bkgsubt[i]->Write(thits_bkgsubt[i]->GetName());
  tHit1_eff_incr_Mich[i]->Write(tHit1_eff_incr_Mich[i]->GetName());
}
timingfile.Close();

THStack *predStack_nuance[nModels];

thits_strobe->SetFillColor(8);
thits_strobe->SetLineColor(8);
thits_nu[0]->SetFillColor(kBlue);
thits_nu[0]->SetLineColor(kBlue);
thits_nub[0]->SetFillColor(5);
thits_nub[0]->SetLineColor(5);
thits_dirt[0]->SetFillColor(28);
thits_dirt[0]->SetLineColor(28);

THStack *predStack_nuance_tmu[nModels];

tru_tmu_strobe->SetFillColor(8);
tru_tmu_strobe->SetLineColor(8);
tru_tmu_nu[0]->SetFillColor(kBlue);
tru_tmu_nu[0]->SetLineColor(kBlue);
tru_tmu_nub[0]->SetFillColor(5);
tru_tmu_nub[0]->SetLineColor(5);
tru_tmu_dirt[0]->SetFillColor(28);
tru_tmu_dirt[0]->SetLineColor(28);

signal_template[0]->SetFillColor(kCyan);
signal_template[0]->SetLineColor(kCyan);

TLegend *legSt = new TLegend(0.50,0.58,0.85,0.877);
legSt->SetTextSize(0.035);
legSt->SetTextColor(1);
legSt->AddEntry(signal_template[0],"KDAR norm. to excess","F");
legSt->AddEntry(thits_nu[0],"#nu_{#mu}","F");
legSt->AddEntry(thits_nub[0],"#bar{#nu}_{#mu}","F");
legSt->AddEntry(thits_dirt[0],"dirt","F");
legSt->AddEntry(thits_strobe,"strobe","F");
legSt->AddEntry(thits_data,"data","lp");
legSt->SetFillColor(0);
legSt->SetLineColor(0);
legSt->SetTextFont(22);

TCanvas *cdd = new TCanvas();

for (int i=0; i<nModels; i++){
  predStack_nuance[i] = new THStack("","");
  signal_template[i]->SetFillColor(kCyan);
  signal_template[i]->SetLineColor(kCyan);
  thits_nu[i]->SetFillColor(kBlue);
  thits_nu[i]->SetLineColor(kBlue);
  thits_nub[i]->SetFillColor(5);
  thits_nub[i]->SetLineColor(5);
  thits_dirt[i]->SetFillColor(28);
  thits_dirt[i]->SetLineColor(28);
  predStack_nuance[i]->Add(thits_dirt[i]);
  predStack_nuance[i]->Add(thits_strobe);
  predStack_nuance[i]->Add(thits_nu[i]);
  predStack_nuance[i]->Add(thits_nub[i]);
  predStack_nuance[i]->Add(signal_template[i]);
  predStack_nuance[i]->SetMaximum(thits_data->GetMaximum()*1.15);
  predStack_nuance[i]->Draw();
  if (i==0)   predStack_nuance[i]->SetTitle("#kappa = 1.022 (sig+bkg);tank hits");
  if (i==1)   predStack_nuance[i]->SetTitle("#kappa = 1.000 (sig+bkg);tank hits");
  if (i==2)   predStack_nuance[i]->SetTitle("#kappa = 1.002 (sig+bkg);tank hits");
  if (i==3)   predStack_nuance[i]->SetTitle("#kappa = 1.004 (sig+bkg);tank hits");
  if (i==4)   predStack_nuance[i]->SetTitle("#kappa = 1.006 (sig+bkg);tank hits");
  if (i==5)   predStack_nuance[i]->SetTitle("#kappa = 1.008 (sig+bkg);tank hits");
  if (i==6)   predStack_nuance[i]->SetTitle("#kappa = 1.010 (sig+bkg);tank hits");
  if (i==7)   predStack_nuance[i]->SetTitle("#kappa = 1.012 (sig+bkg);tank hits");
  if (i==8)   predStack_nuance[i]->SetTitle("#kappa = 1.014 (sig+bkg);tank hits");
  if (i==9)   predStack_nuance[i]->SetTitle("#kappa = 1.016 (sig+bkg);tank hits");
  if (i==10)   predStack_nuance[i]->SetTitle("#kappa = 1.018 (sig+bkg);tank hits");
  if (i==11)   predStack_nuance[i]->SetTitle("#kappa = 0.978 (sig+bkg);tank hits");
  if (i==12)   predStack_nuance[i]->SetTitle("#kappa = 0.982 (sig+bkg);tank hits");
  if (i==13)   predStack_nuance[i]->SetTitle("#kappa = 0.984 (sig+bkg);tank hits");
  if (i==14)   predStack_nuance[i]->SetTitle("#kappa = 0.986 (sig+bkg);tank hits");
  if (i==15)   predStack_nuance[i]->SetTitle("#kappa = 0.988 (sig+bkg);tank hits");
  if (i==16)   predStack_nuance[i]->SetTitle("#kappa = 0.990 (sig+bkg);tank hits");
  if (i==17)   predStack_nuance[i]->SetTitle("#kappa = 0.992 (sig+bkg);tank hits");
  if (i==18)   predStack_nuance[i]->SetTitle("#kappa = 0.994 (sig+bkg);tank hits");
  if (i==19)   predStack_nuance[i]->SetTitle("#kappa = 0.996 (sig+bkg);tank hits");
  if (i==20)   predStack_nuance[i]->SetTitle("#kappa = 0.998 (sig+bkg);tank hits");
  thits_data->Draw("e1p same");
  legSt->Draw();
  if (i==0) cdd->Print("stack_thits.ps(");
  if (i>0&&i<nModels-1) cdd->Print("stack_thits.ps");
  if (i==nModels-1) cdd->Print("stack_thits.ps)");
  
}

TLegend *legSt2 = new TLegend(0.80,0.80,0.99,0.99);
legSt2->SetTextSize(0.035);
legSt2->SetTextColor(1);
legSt2->AddEntry(signal_tmu[0],"KDAR norm. to excess","F");
legSt2->AddEntry(thits_nu[0],"#nu_{#mu}","F");
legSt2->AddEntry(thits_nub[0],"#bar{#nu}_{#mu}","F");
legSt2->AddEntry(thits_dirt[0],"dirt","F");
legSt2->AddEntry(thits_strobe,"strobe","F");
//legSt2->AddEntry(thits_data,"data","lp");
legSt2->SetFillColor(0);
legSt2->SetLineColor(0);
legSt2->SetTextFont(22);

TCanvas *cdd_tmu = new TCanvas();

for (int i=0; i<nModels; i++){
  predStack_nuance_tmu[i] = new THStack("","");
  signal_tmu[i]->SetFillColor(kCyan);
  signal_tmu[i]->SetLineColor(kCyan);
  tru_tmu_nu[i]->SetFillColor(kBlue);
  tru_tmu_nu[i]->SetLineColor(kBlue);
  tru_tmu_nub[i]->SetFillColor(5);
  tru_tmu_nub[i]->SetLineColor(5);
  tru_tmu_dirt[i]->SetFillColor(28);
  tru_tmu_dirt[i]->SetLineColor(28);
  predStack_nuance_tmu[i]->Add(tru_tmu_dirt[i]);
  predStack_nuance_tmu[i]->Add(tru_tmu_strobe);
  predStack_nuance_tmu[i]->Add(tru_tmu_nu[i]);
  predStack_nuance_tmu[i]->Add(tru_tmu_nub[i]);
  predStack_nuance_tmu[i]->Add(signal_tmu[i]);
  predStack_nuance_tmu[i]->Draw();
  if (i==0)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.022 (sig+bkg);T_{#mu} (GeV)");
  if (i==1)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.000 (sig+bkg);T_{#mu} (GeV)");
  if (i==2)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.002 (sig+bkg);T_{#mu} (GeV)");
  if (i==3)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.004 (sig+bkg);T_{#mu} (GeV)");
  if (i==4)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.006 (sig+bkg);T_{#mu} (GeV)");
  if (i==5)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.008 (sig+bkg);T_{#mu} (GeV)");
  if (i==6)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.010 (sig+bkg);T_{#mu} (GeV)");
  if (i==7)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.012 (sig+bkg);T_{#mu} (GeV)");
  if (i==8)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.014 (sig+bkg);T_{#mu} (GeV)");
  if (i==9)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.016 (sig+bkg);T_{#mu} (GeV)");
  if (i==10)   predStack_nuance_tmu[i]->SetTitle("#kappa = 1.018 (sig+bkg);T_{#mu} (GeV)");
  if (i==11)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.978 (sig+bkg);T_{#mu} (GeV)");
  if (i==12)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.982 (sig+bkg);T_{#mu} (GeV)");
  if (i==13)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.984 (sig+bkg);T_{#mu} (GeV)");
  if (i==14)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.986 (sig+bkg);T_{#mu} (GeV)");
  if (i==15)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.988 (sig+bkg);T_{#mu} (GeV)");
  if (i==16)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.990 (sig+bkg);T_{#mu} (GeV)");
  if (i==17)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.992 (sig+bkg);T_{#mu} (GeV)");
  if (i==18)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.994 (sig+bkg);T_{#mu} (GeV)");
  if (i==19)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.996 (sig+bkg);T_{#mu} (GeV)");
  if (i==20)   predStack_nuance_tmu[i]->SetTitle("#kappa = 0.998 (sig+bkg);T_{#mu} (GeV)");
  legSt2->Draw();
  if (i==0) cdd_tmu->Print("stack_tmu.ps(");
  if (i>0&&i<nModels-1) cdd_tmu->Print("stack_tmu.ps");
  if (i==nModels-1) cdd_tmu->Print("stack_tmu.ps)");
  
}

TCanvas *c333s = new TCanvas();
signal_tmu[0]->Draw();
c333s->Print("tmu_test.eps");

TH1F *stat_error = (TH1F*)tru_tmu_nu[0]->Clone("stat_error");

float counts = 0.;

for (int i=1; i<=tru_tmu_nu[0]->GetNbinsX(); i++){

  counts = 0.;
  //counts = predStack_nuance_tmu->GetHistogram()->GetBinContent(i);
  counts = ((TH1*)(predStack_nuance_tmu[16]->GetStack()->Last()))->GetBinContent(i);

  stat_error->SetBinContent(i,sqrt(counts)/counts);

}

TFile tmu_file("stat_errors_tmu_stack_file.root","RECREATE");
for (int j=0; j<nModels; j++){
  ((TH1*)(predStack_nuance_tmu[j]->GetStack()->Last()))->Write(Form("predStack_tmu_%d",j));
  signal_tmu[j]->Write(signal_tmu[j]->GetName());
}
stat_error->Write(stat_error->GetName());

tmu_file.Close();

TCanvas *ccc = new TCanvas();
truEnu_highthit->Draw();
ccc->Print("true_enu_gt_150_thit.eps");

new TCanvas;
thits_mc[11]->Draw();

new TCanvas;
thits_bkgsubt[0]->Draw();
new TCanvas;
thits_data->Draw();
new TCanvas;
thits_mc[0]->Draw();

TCanvas *chanz = new TCanvas();
chans_sig_nu->Draw();
chans_sig_nub->Draw("same");
chanz->Print("sig_channels.eps");

for (int i=1; i<=chans_sig_nu->GetNbinsX(); i++){
  cout<<"nu: in tank channel "<<chans_sig_nu->GetXaxis()->GetBinCenter(i)<<" frac "<<chans_sig_nu->GetBinContent(i) / chans_sig_nu->Integral()<<endl;
}
for (int i=1; i<=chans_sig_nub->GetNbinsX(); i++){
  cout<<"nub: in tank channel "<<chans_sig_nub->GetXaxis()->GetBinCenter(i)<<" frac "<<chans_sig_nub->GetBinContent(i) / chans_sig_nub->Integral()<<endl;
}
cout<<" nu in-tank MC in sig region is "<<chans_sig_nu->Integral()<<endl;
cout<<" nub in-tank MC in sig region is "<<chans_sig_nub->Integral()<<endl;

TCanvas *chanzD = new TCanvas();
chans_sig_dirt_nu->Draw();
chans_sig_dirt_nub->Draw("same");
chanzD->Print("sig_channels_dirt.eps");

lt_120_tmu_gt_150_thits->SetTitle("Tmu < 120 MeV && tank hits > 150;E_{#nu} (MeV)");

TCanvas *check = new TCanvas();
lt_120_tmu_gt_150_thits->Draw();
check->Print("sig_region_enu_check.eps");

// for (int i=1; i<=chans_sig_dirt->GetNbinsX(); i++){
//   cout<<"dirt channel "<<chans_sig_dirt->GetXaxis()->GetBinCenter(i)<<" frac "<<chans_sig_dirt->GetBinContent(i) / chans_sig_dirt->Integral()<<endl;
// }
// cout<<" total dirt MC in sig region is "<<chans_sig_dirt->Integral()<<endl;

TCanvas *uiop = new TCanvas();

thits_mc[1]->SetLineColor(kBlack);
thits_nu[1]->SetLineColor(kRed);
thits_nu[1]->SetFillColor(0);
thits_nub[1]->SetLineColor(kBlue);
thits_nub[1]->SetFillColor(0);

//int rebin = 2;

for (int i=0; i<nbins_time; i++){

  data_int = 0.;
  model_int = 0.;

  for (int j=bin_start; j<= bin_stop; j++){
    data_int += thits_data_bins[i]->GetBinContent(j);
	model_int += thits_mc[1]->GetBinContent(j);//kappa = 1.000
  }
 
  if (data_int>0){
    thits_mc[1]->Scale(data_int/model_int);//actually scaling dirt, strobe too.  i don't think it matters.
    thits_nu[1]->Scale(data_int/model_int);
    thits_nub[1]->Scale(data_int/model_int);
  }

  thits_data_bins[i]->SetTitle(Form("window: %4.0f -  %4.0f ns, %1.0f events bkg: #kappa = 1.000 excess in sig region %4.1f; tank hits",time_bounds[i],time_bounds[i+1],thits_data_bins[i]->Integral(),thits_data_bins[i]->Integral(1,14) - thits_mc[1]->Integral(1,14)));
  thits_data_bins[i]->SetFillStyle(0);
  thits_data_bins[i]->SetMarkerStyle(20);
  thits_data_bins[i]->SetMarkerSize(0.7);
  thits_data_bins[i]->SetLineColor(1);
  thits_data_bins[i]->SetMarkerColor(2);
  thits_data_bins[i]->SetBarWidth(4);
  thits_data_bins[i]->SetLineWidth(1);


  thits_data_bins[i]->Draw("e1p");
  thits_mc[1]->Draw("hist same");
  thits_nu[1]->Draw("hist same");
  thits_nub[1]->Draw("hist same");
  thits_data_bins[i]->Draw("e1p same");

  if (i==0) uiop->Print("bkg_enh_five_batches_thits_time.ps(");
  if (i>0&&i<nbins_time-1) uiop->Print("bkg_enh_five_batches_thits_time.ps");
  if (i==nbins_time-1) uiop->Print("bkg_enh_five_batches_thits_time.ps)");

}

TCanvas *chanzCC = new TCanvas();
chans->Draw();
chanzCC->Print("channels_thits_lt_150.eps");

michels_data->SetTitle("Michels;tank hits");
michels_data->SetFillStyle(0);
michels_data->SetMarkerStyle(20);
michels_data->SetMarkerSize(0.7);
michels_data->SetLineColor(1);
michels_data->SetMarkerColor(2);
michels_data->SetBarWidth(4);
michels_data->SetLineWidth(1);

michels_mc->SetLineWidth(2);
michels_mc->SetLineColor(kBlack);
michels_mc->Scale(michels_data->Integral()/michels_mc->Integral());

TCanvas *michC = new TCanvas();
michels_data->Draw("e1p");
michels_mc->Draw("same");
michC->Print("michels.eps");

//for (int i=1; i<=spitztime_in_5->GetNbinsX(); i++)
//	cout<<" < 150 thits time bet: "<<spitztime_in_5->GetXaxis()->GetBinLowEdge(i)<<" - "<<spitztime_in_5->GetXaxis()->GetBinUpEdge(i)<<" has "<<spitztime_in_5->GetBinContent(i)<<endl;

}
