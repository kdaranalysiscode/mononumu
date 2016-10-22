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
#include "TGraphAsymmErrors.h"
#include "TH2F.h"
#include "TLine.h"
#include "TArrow.h"
#include "TROOT.h"

using namespace std;

// TH1F *bkgsubt(TH1F *total_data,TH1F *bkg_pred);

void outputTree::Loop()
{

double tank_rms_time = 0.;

float vHitz[10];
for (int i=0; i<=10; i++) vHitz[i] = 0;

bool passV = 0;
int numSE = 0;
int ndf;
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

int bins_time_ratio = 120;
double last_time_ratio = 13000.;
double start_time = 0.;

TH1F *time_in_5  = new TH1F("time_in_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_mid_5 = new TH1F("time_mid_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_out_5 = new TH1F("time_out_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_tot_5 = new TH1F("time_tot_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_in_ratio_5  = new TH1F("time_in_ratio_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_mid_ratio_5 = new TH1F("time_mid_ratio_5","",bins_time_ratio,start_time,last_time_ratio);
TH1F *time_out_ratio_5 = new TH1F("time_out_ratio_5","",bins_time_ratio,start_time,last_time_ratio);

TH1F *time = new TH1F("time","",130,0.,13000.);

const int nWindows = 2;
float windowBounds[nWindows+1];//unit is ns

//double start_rise = 11250.;

//int nWindows_rise = nWindows;

//windowBounds[1] = 11250.;//10500
//windowBounds[nWindows-1] = 11750.;

//float window_step = (windowBounds[nWindows-1] -  windowBounds[0])/((float)nWindows-1);
//float window_step = (windowBounds[nWindows-1] - start_rise)/((float)nWindows_rise-1);

//cout<<" window_step "<<window_step<<" start_rise "<<start_rise<<" upper bound "<<windowBounds[nWindows-1]<<endl;

//windowBounds[0] = windowBounds[nWindows-1] - (float) (nWindows-1) * window_step;

//cout<<" lower bound "<<windowBounds[0]<<endl;

//for (int i=1; i<nWindows; i++) windowBounds[i] = windowBounds[i-1] + window_step; 

//for (int i=0; i<nWindows; i++) cout<<" index "<<i<<" value "<<windowBounds[i]<<" diff from previous "<<windowBounds[i]-windowBounds[i-1]<<endl; 

//windowBounds[0] = 2500.;
//windowBounds[1] = 2700.;

windowBounds[0] = 2500.;
windowBounds[1] = 2700.;
windowBounds[2] = 11750.;

float first_lo = 2500.;
float first_up = 2736.;

float sec_lo = 11250.;
float sec_up = 11750.;


/*
windowBounds[1] = 1000.;
windowBounds[2] = 2500.;
windowBounds[3] = 3000.;
windowBounds[4] = 3500.;
windowBounds[5] = 4000.;
windowBounds[6] = 4500.;
windowBounds[7] = 5000.;
windowBounds[8] = 5500.;
windowBounds[9] = 6000.;
windowBounds[10] = 6500.;
windowBounds[11] = 7000.;
*/

//return;

int nModels = 21;


TH1F *thits_windows_slide_left[nWindows];
TH1F *thits_windows_slide_right[nWindows];
TH1F *thits_windows_excl[nWindows];

TH1F *thits_windows_excl_big[nWindows];
TH1F *thits_windows_excl_sb[nWindows];
TH1F *thits_windows_excl_sig[nWindows];

TH1F *thits_windows_slide_left_bkg_subt[nWindows];
TH1F *thits_windows_slide_right_bkg_subt[nWindows];
TH1F *thits_windows_excl_bkg_subt[nWindows][nModels];

int thitbins = 30;
double last = 300.;

for (int i=0; i<nWindows; i++){

  thits_windows_slide_left[i] = new TH1F(Form("thits_windows_slide_left_%d",i),"",thitbins,0.,last);
  thits_windows_slide_right[i] = new TH1F(Form("thits_windows_slide_right_%d",i),"",thitbins,0.,last);
  thits_windows_excl[i] = new TH1F(Form("thits_windows_excl_%d",i),"",thitbins,0.,last);
  thits_windows_excl_big[i] = new TH1F(Form("thits_windows_excl_big_%d",i),"",24,0.,1200);
  thits_windows_excl_sb[i] = new TH1F(Form("thits_windows_excl_sb_%d",i),"",15,150,300);
  thits_windows_excl_sig[i] = new TH1F(Form("thits_windows_excl_sig_%d",i),"",15,0,150);

  for (int j=0; j<nModels; j++)
  	thits_windows_excl_bkg_subt[i][j] = new TH1F(Form("thits_windows_excl_%d_%d",i,j),"",thitbins,0.,last);


}

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
 
        tHits_1SE = 0;
		tHits_1SE = mysplitEvent_nTankHits[0];

        tHits_2SE = 0;
        tHits_2SE = mysplitEvent_nTankHits[1];
	
        muX = 0;
        muX =  myTransRFull_trans_vertex_x[0];

        muY = 0;
        muY =  myTransRFull_trans_vertex_y[0];

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

        //----------------------------------------------------------
        //							CUTS
        //----------------------------------------------------------        
 
        //only cut that's missing is timing (no pre-cut imposed on this sample)
 		if (passV==0) continue;
	    if (numSE!=2) continue;
        if (tHits_2SE>200) continue;
        if (tHits_2SE<20) continue; 
        if (muR>500) continue;
        if (tHits_1SE<20) continue;
        if (tank_rms_time>50) continue;
        if (MichDist>100) continue;

		for (int i=0; i<nWindows; i++){
		
		  if (beamAveTime > windowBounds[0] && beamAveTime <= windowBounds[i]) 
		  	thits_windows_slide_right[i]->Fill(tHits_1SE);

		  if (beamAveTime < windowBounds[nWindows-1] && beamAveTime >= windowBounds[i]) 
		  	thits_windows_slide_left[i]->Fill(tHits_1SE);

		  //if (beamAveTime > windowBounds[i] && beamAveTime <= windowBounds[i+1]) 
		  	//thits_windows_excl[i]->Fill(tHits_1SE);
		
		}

          //hardcode two windows
		  if (beamAveTime > first_lo && beamAveTime <= first_up){ 
		  	thits_windows_excl[0]->Fill(tHits_1SE);
		  	thits_windows_excl_big[0]->Fill(tHits_1SE);
		  	thits_windows_excl_sb[0]->Fill(tHits_1SE);
		  	thits_windows_excl_sig[0]->Fill(tHits_1SE);
		  }

		  if (beamAveTime > sec_lo && beamAveTime <= sec_up){ 
		  	thits_windows_excl[1]->Fill(tHits_1SE);
		  	thits_windows_excl_big[1]->Fill(tHits_1SE);
		  	thits_windows_excl_sb[1]->Fill(tHits_1SE);
		  	thits_windows_excl_sig[1]->Fill(tHits_1SE);
		  }	

		if (tHits_1SE<150) time_in_5->Fill(beamAveTime);
		if (tHits_1SE>=300) time_out_5->Fill(beamAveTime);
		if (tHits_1SE>=150&&tHits_1SE<300) time_mid_5->Fill(beamAveTime);
		time_tot_5->Fill(beamAveTime);

        time->Fill(beamAveTime);


   }//jentry loop

cout<<"out of event loop!"<<endl;

//gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);

time_out_5->SetLineWidth(2);
time_in_5->SetLineWidth(2);
time_mid_5->SetLineWidth(2);
time_out_5->SetLineColor(kRed);
time_in_5->SetLineColor(kBlue);
time_mid_5->SetLineColor(kBlack);

for (int i=1; i<=time_out_ratio_5->GetNbinsX(); i++){

  if (time_tot_5->GetBinContent(i)<10) continue;
  time_out_ratio_5->SetBinContent(i,time_out_5->GetBinContent(i) / time_tot_5->GetBinContent(i));  
  time_in_ratio_5->SetBinContent(i,time_in_5->GetBinContent(i) / time_tot_5->GetBinContent(i));  
  time_mid_ratio_5->SetBinContent(i,time_mid_5->GetBinContent(i) / time_tot_5->GetBinContent(i));  

  time_out_ratio_5->SetBinError(i,sqrt(time_out_5->GetBinContent(i))/time_out_5->GetBinContent(i) * time_out_ratio_5->GetBinContent(i));
  time_in_ratio_5->SetBinError(i,sqrt(time_in_5->GetBinContent(i))/time_in_5->GetBinContent(i) * time_in_ratio_5->GetBinContent(i));
  time_mid_ratio_5->SetBinError(i,sqrt(time_mid_5->GetBinContent(i))/time_mid_5->GetBinContent(i) * time_mid_ratio_5->GetBinContent(i));

}

time_out_ratio_5->SetLineWidth(2);
time_in_ratio_5->SetLineWidth(2);
time_mid_ratio_5->SetLineWidth(2);
time_out_ratio_5->SetLineColor(kRed);
time_in_ratio_5->SetLineColor(kBlue);
time_mid_ratio_5->SetLineColor(kBlack);

TLegend *legTT = new TLegend(0.7,0.80,0.99,0.95);
legTT->SetTextSize(0.035);
legTT->SetTextColor(1);
legTT->AddEntry(time_in_ratio_5,"PMT hits < 150","l");
legTT->AddEntry(time_mid_ratio_5,"150 < PMT hits < 300","l");
legTT->AddEntry(time_out_ratio_5,"PMT hits > 300","l");
legTT->SetFillColor(0);
legTT->SetLineColor(1);
legTT->SetTextFont(22);

TCanvas *spitzChk_5 = new TCanvas();
time_out_5->Draw();
time_mid_5->Draw("same");
time_in_5->Draw("same");
legTT->Draw();
spitzChk_5->Print("timing_5_batches.eps");
spitzChk_5->SetLogy();
spitzChk_5->Print("timing_5_batches_log.eps");

time_out_ratio_5->SetTitle("5 batch data only min 10 total events; beam avg time (ns); ratio to total");

TCanvas *spitzChkR_5 = new TCanvas();
time_out_ratio_5->Draw();
time_mid_ratio_5->Draw("same");
time_in_ratio_5->Draw("same");
legTT->Draw();
spitzChkR_5->Print("timing_ratio_5_batches.eps");

time_in_ratio_5->SetTitle("tank hits < 150; event time (ns); ratio to total");

TCanvas *cc34 = new TCanvas();
time_in_ratio_5->Draw("e1p");
cc34->Print("sig_region_ratio_w_err.eps");

//int nModels = 21;
double xi2[nModels];

double gofmin,gof;
double GOF[nModels];
double kappa[nModels];
TH1F *bkg_templates[nModels];
TH1F *bkg_subt_model[nModels];
TH1F *signal_model[nModels];
TH1F *mich_eff[nModels];//need to apply since not generated with this cut

TFile *bkg_temps_file = new TFile("./bkg_templates_fullmcstats.root");
for (int i=0; i<nModels; i++){
	bkg_temps_file->GetObject(Form("thits_mc_%d",i),bkg_templates[i]);
	bkg_temps_file->GetObject(Form("thits_bkgsubt_%d",i),bkg_subt_model[i]);
	bkg_temps_file->GetObject(Form("tHit1_eff_incr_Mich_%d",i),mich_eff[i]);

    bkg_subt_model[i]->GetFunction("gaus")->SetBit(TF1::kNotDraw);
	bkg_subt_model[i]->SetLineWidth(2);

if(bkg_subt_model[i]->GetNbinsX()==300)
{
bkg_subt_model[i]->Rebin(10);
bkg_templates[i]->Rebin(10);
}

	//cout<<bkg_subt_model_orig[i]->Integral()<<endl;
}

TFile *model_file = new TFile("./signal_templates.root");

	model_file->GetObject("kappa_1022",signal_model[0]);
    model_file->GetObject("kappa_1000",signal_model[1]);
    model_file->GetObject("kappa_1002",signal_model[2]);
    model_file->GetObject("kappa_1004",signal_model[3]);
    model_file->GetObject("kappa_1006",signal_model[4]);
    model_file->GetObject("kappa_1008",signal_model[5]);
    model_file->GetObject("kappa_1010",signal_model[6]);
    model_file->GetObject("kappa_1012",signal_model[7]);
    model_file->GetObject("kappa_1014",signal_model[8]);
    model_file->GetObject("kappa_1016",signal_model[9]);
    model_file->GetObject("kappa_1018",signal_model[10]);
    model_file->GetObject("kappa_0978",signal_model[11]);
    model_file->GetObject("kappa_0982",signal_model[12]);
    model_file->GetObject("kappa_0984",signal_model[13]);
    model_file->GetObject("kappa_0986",signal_model[14]);
    model_file->GetObject("kappa_0988",signal_model[15]);
    model_file->GetObject("kappa_0990",signal_model[16]);
    model_file->GetObject("kappa_0992",signal_model[17]);
    model_file->GetObject("kappa_0994",signal_model[18]);
    model_file->GetObject("kappa_0996",signal_model[19]);
    model_file->GetObject("kappa_0998",signal_model[20]);

//add the michel distance eff shape effect
for (int i=0; i<nModels; i++){

  for (int j=1; j<=signal_model[i]->GetNbinsX(); j++)
  	signal_model[i]->SetBinContent(j,signal_model[i]->GetBinContent(j) * mich_eff[i]->GetBinContent(j));

}

//new TCanvas();
//signal_model[0]->Draw();


//data template: bkg_subt_model[i]
//background template: bkg_templates[i]

//int whichModel = 11;//kappa = 0.978

  ofstream myfile;
  myfile.open ("chi2.txt");
int bins;
//loop over model (whichmodel) here?
for (int whichModel=0; whichModel<=nModels-1; whichModel++){

double data_int = 0.;
double bkg_int = 0.;
double model_int = 0.;

TCanvas *slideLeftC = new TCanvas();

int bin_start = 3;//20-30 tank hits
int bin_stop  = 15;//140-150 tank hits 
int bin_start_bkg = 16;//150-160 tank hits
int bin_stop_bkg  = 30;//290-300 tank hits 

double data_total = 0.;
double bkg = 0.;
double sig = 0.;
double stb = 0.;
double stb_error = 0.;

Float_t x[1];
Float_t y[1];
Float_t exl[1];
Float_t eyl[1];
Float_t exh[1];
Float_t eyh[1];

TGraphAsymmErrors *stb_slide_left[nWindows];
TGraphAsymmErrors *stb_slide_right[nWindows];
TGraphAsymmErrors *stb_excl[nWindows];



double chi2=0;
double totalchi2=0;
int ndof=0;
int totalndof=0;
bins=0;
for (int i=0; i<nWindows; i++){

  	data_int = 0.;
  	bkg_int = 0.;

  	for (int j=bin_start; j<= bin_stop; j++){
    	data_int += thits_windows_excl[i]->GetBinContent(j);
  	}
  	  	for (int j=bin_start_bkg; j<= bin_stop_bkg; j++){
    	bkg_int += thits_windows_excl[i]->GetBinContent(j);
  	}

bkg_templates[whichModel]->Scale(bkg_int/bkg_templates[whichModel]->Integral(bin_start_bkg,bin_stop_bkg));

double bkg_events_in_signal_region=bkg_templates[whichModel]->Integral(bin_start,bin_stop);

signal_model[whichModel]->Scale( (data_int - bkg_events_in_signal_region) /signal_model[whichModel]->Integral());

cout<<" model "<<whichModel<<" S/B = "<<signal_model[whichModel]->Integral() / bkg_events_in_signal_region<<endl;

if (signal_model[whichModel]->Integral()<0.){
  cout<<" negative integral! model "<<whichModel<<endl;
  //return;
}
cout<<"Model: "<<whichModel<<" Window: "<<i<<" "<<data_int<<" "<<bkg_int<<endl;

// bkg_subt_model[whichModel]->Scale(data_int/bkg_subt_model[whichModel]->Integral());

TH1F *signal_and_background_template=(TH1F*)bkg_templates[whichModel]->Clone();
// signal_and_background_template->Add(bkg_subt_model[whichModel]);
if (signal_model[whichModel]->Integral()>0.) signal_and_background_template->Add(signal_model[whichModel]);

 TCanvas *exclC = new TCanvas();
  	thits_windows_excl[i]->SetFillStyle(0);
  	thits_windows_excl[i]->SetMarkerStyle(20);
  	thits_windows_excl[i]->SetMarkerSize(0.7);
  	thits_windows_excl[i]->SetLineColor(1);
  	thits_windows_excl[i]->SetMarkerColor(2);
  	thits_windows_excl[i]->SetBarWidth(4);
  	thits_windows_excl[i]->SetLineWidth(1);

  	thits_windows_excl_big[i]->SetFillStyle(0);
  	thits_windows_excl_big[i]->SetMarkerStyle(20);
  	thits_windows_excl_big[i]->SetMarkerSize(0.7);
  	thits_windows_excl_big[i]->SetLineColor(1);
  	thits_windows_excl_big[i]->SetMarkerColor(2);
  	thits_windows_excl_big[i]->SetBarWidth(4);
  	thits_windows_excl_big[i]->SetLineWidth(1);

  	thits_windows_excl_sb[i]->SetFillStyle(0);
  	thits_windows_excl_sb[i]->SetMarkerStyle(20);
  	thits_windows_excl_sb[i]->SetMarkerSize(0.7);
  	thits_windows_excl_sb[i]->SetLineColor(1);
  	thits_windows_excl_sb[i]->SetMarkerColor(2);
  	thits_windows_excl_sb[i]->SetBarWidth(4);
  	thits_windows_excl_sb[i]->SetLineWidth(1);

  	thits_windows_excl_sig[i]->SetFillStyle(0);
  	thits_windows_excl_sig[i]->SetMarkerStyle(20);
  	thits_windows_excl_sig[i]->SetMarkerSize(0.7);
  	thits_windows_excl_sig[i]->SetLineColor(1);
  	thits_windows_excl_sig[i]->SetMarkerColor(2);
  	thits_windows_excl_sig[i]->SetBarWidth(4);
  	thits_windows_excl_sig[i]->SetLineWidth(1);
//    signal_and_background_template->SetLineWidth(2);
//  
  // thits_windows_excl[i]->SetMaximum(thits_windows_excl[0]->GetMaximum()*1.1);
//  
//  
 int nbins = thits_windows_excl[i]->GetNbinsX();
 
  if (i==0){
    if (whichModel==0) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.022,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==1) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.000,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==2) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.002,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==3) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.004,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==4) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.006,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==5) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.008,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==6) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.010,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==7) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.012,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==8) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.014,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==9) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.016,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==10) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.018,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==11) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.978,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==12) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.982,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==13) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.984,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==14) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.986,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==15) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.988,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==16) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.990,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==17) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.992,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==18) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.994,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==19) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.996,first_lo,first_up,thits_windows_excl[i]->Integral()));
    if (whichModel==20) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.998,first_lo,first_up,thits_windows_excl[i]->Integral()));
  } 
  if (i==1){
    if (whichModel==0) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.022,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==1) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.000,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==2) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.002,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==3) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.004,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==4) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.006,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==5) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.008,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==6) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.010,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==7) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.012,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==8) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.014,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==9) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.016,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==10) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",1.018,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==11) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.978,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==12) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.982,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==13) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.984,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==14) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.986,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==15) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.988,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==16) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.990,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==17) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.992,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==18) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.994,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==19) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.996,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
    if (whichModel==20) thits_windows_excl[i]->SetTitle(Form("#kappa = %1.3f, window: %4.0f -  %4.0f ns, %1.0f events; tank hits",0.998,sec_lo,sec_up,thits_windows_excl[i]->Integral()));
  } 

 	  for(int ii=3;ii<=30;ii++)
  {

// if(thits_windows_excl[i]->GetBinError(ii) )
// {
// chi2+=pow(signal_and_background_template->GetBinContent(ii)-thits_windows_excl[i]->GetBinContent(ii),2)/pow(thits_windows_excl[i]->GetBinError(ii),2);


double expectation=signal_and_background_template->GetBinContent(ii);
int data=thits_windows_excl[i]->GetBinContent(ii);

//this is the correct chi2 to use, which is ok for low bin stats and empty bins
chi2+=expectation-(data*TMath::Log(expectation))+TMath::Log(TMath::Factorial(data));

gof+=pow((data-expectation),2)/expectation;
// cout<<expectation<<endl;

ndof++;
bins++;
//}
		
}

chi2=2*chi2; 
 
    //thits_windows_excl[i]->SetMaximum(signal_and_background_template->GetMaximum()*2.);
    //if (i==0) thits_windows_excl[i]->SetMaximum(12);
    //if (i==1) thits_windows_excl[i]->SetMaximum(12);
    //if (i==2) thits_windows_excl[i]->SetMaximum(12);
    //else thits_windows_excl[i]->SetMaximum(10);
    thits_windows_excl_bkg_subt[i][whichModel]->Add(thits_windows_excl[i]);
    thits_windows_excl_bkg_subt[i][whichModel]->Add(bkg_templates[whichModel],-1.);
    for (int z=0; z<thits_windows_excl[i]->GetNbinsX(); z++)
      thits_windows_excl_bkg_subt[i][whichModel]->SetBinError(z,thits_windows_excl[i]->GetBinError(z));

    thits_windows_excl_bkg_subt[i][whichModel]->SetTitle(thits_windows_excl[i]->GetTitle());

 	thits_windows_excl[i]->Draw("e1p");
 	signal_and_background_template->SetLineColor(1);
	signal_and_background_template->Draw("same hist");
	bkg_templates[whichModel]->SetLineColor(2);
bkg_templates[whichModel]->Draw("SAME hist");
// bkg_subt_model[whichModel]->SetLineColor(4);
// bkg_subt_model[whichModel]->Draw("SAME hist");
signal_model[whichModel]->SetLineColor(4);
signal_model[whichModel]->Draw("SAME hist");
		
	if (i==0) exclC->Print(Form("time_windows_excl_%d.ps(",whichModel));
	if (i>0&&i<nWindows-1) exclC->Print(Form("time_windows_excl_%d.ps",whichModel));
	if (i==nWindows-1) exclC->Print(Form("time_windows_excl_%d.ps)",whichModel));
	
myfile<<"Model "<<whichModel<<" window: "<<i<<" ...chi2= "<<chi2<<" ndof: "<<ndof<<" Data integral: "<<thits_windows_excl[i]->Integral()<<" Prediction integral: "<<signal_and_background_template->Integral()<<endl;
totalchi2+=chi2;
totalndof+=ndof;
chi2=0;
ndof=0;
	
}
myfile<<"Total chi2 "<<totalchi2<<" Total ndof: "<<totalndof<<endl;
myfile<<endl;
xi2[whichModel]=totalchi2;
GOF[whichModel]=gof;
ndf=totalndof;
totalchi2=0;
totalndof=0;
gof=0;


}

kappa[0]=1.022;
kappa[1]=1.000; 
kappa[2]=1.002;
kappa[3]=1.004;
kappa[4]=1.006;
kappa[5]=1.008;
kappa[6]=1.010;
kappa[7]=1.012;
kappa[8]=1.014;
kappa[9]=1.016;
kappa[10]=1.018;
kappa[11]=0.978; 
kappa[12]=0.982;
kappa[13]=0.984;
kappa[14]=0.986;
kappa[15]=0.988;
kappa[16]=0.990;
kappa[17]=0.992;
kappa[18]=0.994;
kappa[19]=0.996;
kappa[20]=0.998;


TH1D *hist_chi2=new TH1D("","",23,0.978,1.024);

double chi2min=100000.;
for(int i=1;i<=hist_chi2->GetNbinsX();i++)
{
hist_chi2->Fill(kappa[i-1],xi2[i-1]);
cout<<kappa[i-1]<<" "<<xi2[i-1]<<endl;

if(xi2[i-1]>0.01 && xi2[i-1]<chi2min)
{
chi2min=xi2[i-1];
gofmin=GOF[i-1];
}
}


new TCanvas;
hist_chi2->SetMaximum(chi2min+10);
hist_chi2->SetMinimum(chi2min-1);


hist_chi2->SetTitle(Form("Signal and background template study: #chi^{2}_{red}=%5.2f (at #chi^{2}_{Poisson,min})",gofmin/((double)bins-1.)));
hist_chi2->GetXaxis()->SetTitle("kappa");
hist_chi2->GetYaxis()->SetTitle("#chi^{2}_{Poisson}");
hist_chi2->Draw();
TLine l;
l.SetLineStyle(2);
l.DrawLine(.978,chi2min+1,1.024,chi2min+1);
gPad->GetCanvas()->Print("hist_chi2.pdf");

cout<<"chi2 at chi2_min: "<<gofmin<<" ndof-1: "<<bins-1<<endl;

time->SetTitle("5 bunch sample;event time (ns)");

TCanvas *timeC = new TCanvas();
timeC->SetGrid();
//timeC->SetGridY();
time->Draw();
timeC->Print("time.eps");

thits_windows_excl[1]->SetMarkerColor(kBlue);

thits_windows_excl[0]->SetMaximum(10);

float kstest = thits_windows_excl[0]->KolmogorovTest(thits_windows_excl[1]);

thits_windows_excl[0]->SetTitle(Form("red: early blue: late KS prob %1.3f",kstest));
thits_windows_excl[0]->SetLineColor(kRed);
thits_windows_excl[1]->SetLineColor(kBlue);

TCanvas *timeC44 = new TCanvas();
thits_windows_excl[0]->Draw("e1p");
thits_windows_excl[1]->Draw("e1p same");
timeC44->Print("comp_shapes.eps");

float kstest2 = thits_windows_excl_big[0]->KolmogorovTest(thits_windows_excl_big[1]);

thits_windows_excl_big[0]->SetTitle(Form("red: early blue: late KS prob %1.3f; tank hits",kstest2));
thits_windows_excl_big[1]->SetMarkerColor(kBlue);
thits_windows_excl_big[0]->SetMaximum(1.4*thits_windows_excl_big[1]->GetMaximum());
thits_windows_excl_big[0]->SetLineColor(kRed);
thits_windows_excl_big[1]->SetLineColor(kBlue);

TCanvas *timeC443 = new TCanvas();
thits_windows_excl_big[0]->Draw("e1p");
thits_windows_excl_big[1]->Draw("e1p same");
timeC443->Print("comp_shapes_rng.eps");

float kstest3 = thits_windows_excl_sb[0]->KolmogorovTest(thits_windows_excl_sb[1]);

thits_windows_excl_sb[0]->SetTitle(Form("red: early blue: late KS prob %1.3f; tank hits",kstest3));
thits_windows_excl_sb[1]->SetMarkerColor(kBlue);
thits_windows_excl_sb[0]->SetMaximum(2.0*thits_windows_excl_sb[1]->GetMaximum());
thits_windows_excl_sb[0]->SetLineColor(kRed);
thits_windows_excl_sb[1]->SetLineColor(kBlue);

TCanvas *timeC4435 = new TCanvas();
thits_windows_excl_sb[0]->Draw("e1p");
thits_windows_excl_sb[1]->Draw("e1p same");
timeC4435->Print("comp_shapes_sb.eps");

float kstest4 = thits_windows_excl_sig[0]->KolmogorovTest(thits_windows_excl_sig[1]);

thits_windows_excl_sig[0]->SetTitle(Form("red: early blue: late KS prob %1.3f; tank hits",kstest4));
thits_windows_excl_sig[1]->SetMarkerColor(kBlue);
thits_windows_excl_sig[0]->SetMaximum(1.9*thits_windows_excl_sig[1]->GetMaximum());
thits_windows_excl_sig[0]->SetLineColor(kRed);
thits_windows_excl_sig[1]->SetLineColor(kBlue);

TCanvas *timeC443545 = new TCanvas();
thits_windows_excl_sig[0]->Draw("e1p");
thits_windows_excl_sig[1]->Draw("e1p same");
timeC443545->Print("comp_shapes_sig.eps");

cout<<" kstest reduced rng "<<kstest<<endl;
cout<<" kstest full rng "<<kstest2<<endl;
cout<<" kstest sb "<<kstest3<<endl;
cout<<" kstest sig "<<kstest4<<endl;

return;

myfile.close();

for (int i=0; i<nWindows; i++){
  for (int j=0; j<nModels; j++){

  	thits_windows_excl_bkg_subt[i][j]->SetFillStyle(0);
  	thits_windows_excl_bkg_subt[i][j]->SetMarkerStyle(20);
  	thits_windows_excl_bkg_subt[i][j]->SetMarkerSize(0.7);
  	thits_windows_excl_bkg_subt[i][j]->SetLineColor(1);
  	thits_windows_excl_bkg_subt[i][j]->SetMarkerColor(kBlue);
  	thits_windows_excl_bkg_subt[i][j]->SetBarWidth(4);
  	thits_windows_excl_bkg_subt[i][j]->SetLineWidth(1);
    //thits_windows_excl_bkg_subt[i][j]->SetSumw2();
    thits_windows_excl_bkg_subt[i][j]->GetXaxis()->SetTitle("tank hits");
    thits_windows_excl_bkg_subt[i][j]->GetYaxis()->SetTitle("Normalized to unity");
    
  }
}  

TCanvas *bkgSC = new TCanvas();

for (int j=0; j<nModels; j++){
  for (int i=0; i<nWindows-1; i++){
    thits_windows_excl_bkg_subt[i][j]->DrawNormalized("e1p");
    bkg_subt_model[j]->DrawNormalized("e1p same");
    if (i==0&&j==0) bkgSC->Print("bkg_subt_shape_comp.ps(");
    if ((i==0&&j>0) || (i>0&&i<nWindows-2&&j>0&&j<nModels-1) || (i==nWindows-2&&j<nModels-1)) bkgSC->Print("bkg_subt_shape_comp.ps");
    if (i==nWindows-2&&j==nModels-1) bkgSC->Print("bkg_subt_shape_comp.ps)");
  }
}
}
