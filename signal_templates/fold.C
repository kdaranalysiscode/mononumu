#include "TAxis.h"
#include "TFile.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TRandom3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
#include "TH2F.h"
#include "TMarker.h"
#include "TPoint.h"
#include "TStyle.h"
#include "TLine.h"
#include "TLatex.h"
#include "TGaxis.h"
#include "TMatrixD.h"

using namespace std;

TH1F *transformedHist(TH1 *inpt,TH2 *corr);

TH1F *transformedHist_iter(TH1 *inpt,TH2 *corr,int n_iter);

int whichDist = 1;

void fold(){

  TString fileName = "muon_Tmu_nuance_kappa.root";

  TFile *file1=new TFile(fileName.Data());
  TFile *file_tmu_my_bins=new TFile("muon_Tmu_nuance_kappa_newbinning.root");

  const int nModels = 23;
  const int nModels_jg = 21;//careful!  indices <--> kappa map different between nModels and nModels_jg!

  TH1D *tru_tmu[nModels];
  TH1D *tru_tmu_my_bins[nModels];
  
  for (int i=0; i<nModels; i++){
    if (i<11) file1->GetObject(Form("kappa_0%d",978+2*i),tru_tmu[i]);
    else file1->GetObject(Form("kappa_%d",978+2*i),tru_tmu[i]);
  }

  for (int i=0; i<nModels; i++){
    if (i<11) file_tmu_my_bins->GetObject(Form("kappa_0%d",978+2*i),tru_tmu_my_bins[i]);
    else file_tmu_my_bins->GetObject(Form("kappa_%d",978+2*i),tru_tmu_my_bins[i]);
  }

  TH2F *tru_tmu_tank_hit_fold[nModels_jg];
  TH2F *tru_tmu_tank_hit_unfold[nModels_jg];
  TH1F *tank_hit_eff[nModels_jg];
  TH1F *tmu_eff[nModels_jg];

  TString fileName2;
  if (whichDist==0) fileName2 = "unfoldFile_fullmcstats_testfoldunfold_2.root";
  if (whichDist==1) fileName2 = "unfoldFile_fullmcstats_stfull.root";
  //TString fileName2 = "unfoldFile_fullmcstats_testfoldunfold.root";
  //TString fileName2 = "unfoldFile_fullmcstats.root";
  //TString fileName2 = "unfoldFile.root";

  TFile *file3 = new TFile(fileName2.Data());

  TH1F *thits_recoMC_fold;
  TH1F *tmu_truMC_fold;
  TH2F *thits_tmuCorr_toy_fold;
  TH2F *thits_tmuCorr_toy_unfold;
  file3->GetObject("thits_recoMC_fold",thits_recoMC_fold);
  file3->GetObject("thits_tmuCorr_toy_fold",thits_tmuCorr_toy_fold);
  file3->GetObject("thits_tmuCorr_toy_unfold",thits_tmuCorr_toy_unfold);
  file3->GetObject("tmu_truMC_fold",tmu_truMC_fold);

  for (int i=0; i<nModels_jg; i++){
  	file3->GetObject(Form("tru_tmu_tank_hit_fold_%d",i),tru_tmu_tank_hit_fold[i]);
  	file3->GetObject(Form("tru_tmu_tank_hit_unfold_%d",i),tru_tmu_tank_hit_unfold[i]);
  	file3->GetObject(Form("tHit1_eff_%d",i),tank_hit_eff[i]);
  	file3->GetObject(Form("tmu_eff_%d",i),tmu_eff[i]);
  }

  for (int i=0; i<nModels; i++) tru_tmu[i]->SetLineColor(i+1);

  TLegend *leg = new TLegend(0.777, 0.285, 0.99, 0.996);
  for (int i=0; i<nModels; i++){
    leg->AddEntry(tru_tmu[i],Form("nuance #kappa = %1.3f",1e-3*(978+2*i)),"l");
  }
  leg->SetFillColor(0);
  leg->SetLineColor(1);
  leg->SetTextSize(0.03);

  tru_tmu[0]->SetMaximum(tru_tmu[nModels-1]->GetMaximum()*1.1);
  tru_tmu[0]->SetTitle(";T_{#mu} (MeV)");

//   for (int i=0; i<nModels; i++){
//     //efficiency correct generated tmu?
//     for (int j=1; j<=tru_tmu[i]->GetNbinsX(); j++) tru_tmu[i]->SetBinContent(j,tru_tmu[i]->GetBinContent(j)*tmu_eff[11]->GetBinContent(j));
//   }

  TCanvas *trutmuC = new TCanvas();
  tru_tmu[0]->Draw();
  for (int i=0; i<nModels; i++) 
  	tru_tmu[i]->Draw("same");
  leg->Draw();
  trutmuC->Print("tru_tmu_spread_nuance.eps");

  TFile *file=new TFile("nuance_hists.root", "RECREATE");
  for (int i=0; i<nModels; i++) tru_tmu[i]->Write(Form("tru_tmu_%d",i));
  file->Close();   

  for (int i=0; i<nModels_jg; i++){
  	if (whichDist==0) tru_tmu_tank_hit_fold[i]->GetXaxis()->SetTitle("tank hits");
  	if (whichDist==1) tru_tmu_tank_hit_fold[i]->GetXaxis()->SetTitle("stfull fitter energy (MeV)");
  	tru_tmu_tank_hit_fold[i]->GetYaxis()->SetTitle("T_{#mu} (MeV)");
  }

  TH1F *sig_events_in_sideband = new TH1F("sig_events_in_sideband","",tru_tmu_tank_hit_fold[2]->GetNbinsY(),0.,120.);

  float total = 0.;
  float above_150 = 0.;

  for (int j=1; j<=tru_tmu_tank_hit_fold[2]->GetNbinsY(); j++){
    
    total = 0.;
    above_150 = 0.;
    
    for (int i=1; i<=tru_tmu_tank_hit_fold[2]->GetNbinsX(); i++){
    
      total += tru_tmu_tank_hit_fold[2]->GetBinContent(i,j);
      if (i>15) above_150 += tru_tmu_tank_hit_fold[2]->GetBinContent(i,j);
  
    }
    cout<<" for "<<j-1<<"-"<<j<<" MeV: event frac above 150 tank hits: "<<above_150/total<<endl;
    sig_events_in_sideband->SetBinContent(j,above_150/total);
  }
  
  sig_events_in_sideband->SetTitle("signal events in sideband region; T_{#mu} (MeV); fraction of events with tank hits > 150");
  
  gStyle->SetOptStat(0000);
  
  TCanvas *sigC = new TCanvas();
  sig_events_in_sideband->Draw();
  sigC->Print("sig_sideband.eps");

  tru_tmu_tank_hit_fold[0]->SetTitle("#kappa = 1.022");
  tru_tmu_tank_hit_fold[1]->SetTitle("#kappa = 1.000");
  tru_tmu_tank_hit_fold[2]->SetTitle("#kappa = 1.002");
  tru_tmu_tank_hit_fold[3]->SetTitle("#kappa = 1.004");
  tru_tmu_tank_hit_fold[4]->SetTitle("#kappa = 1.006");
  tru_tmu_tank_hit_fold[5]->SetTitle("#kappa = 1.008");
  tru_tmu_tank_hit_fold[6]->SetTitle("#kappa = 1.010");
  tru_tmu_tank_hit_fold[7]->SetTitle("#kappa = 1.012");
  tru_tmu_tank_hit_fold[8]->SetTitle("#kappa = 1.014");
  tru_tmu_tank_hit_fold[9]->SetTitle("#kappa = 1.016");
  tru_tmu_tank_hit_fold[10]->SetTitle("#kappa = 1.018");
  tru_tmu_tank_hit_fold[11]->SetTitle("#kappa = 0.978");
  tru_tmu_tank_hit_fold[12]->SetTitle("#kappa = 0.982");
  tru_tmu_tank_hit_fold[13]->SetTitle("#kappa = 0.984");
  tru_tmu_tank_hit_fold[14]->SetTitle("#kappa = 0.986");
  tru_tmu_tank_hit_fold[15]->SetTitle("#kappa = 0.988");
  tru_tmu_tank_hit_fold[16]->SetTitle("#kappa = 0.990");
  tru_tmu_tank_hit_fold[17]->SetTitle("#kappa = 0.992");
  tru_tmu_tank_hit_fold[18]->SetTitle("#kappa = 0.994");
  tru_tmu_tank_hit_fold[19]->SetTitle("#kappa = 0.996");
  tru_tmu_tank_hit_fold[20]->SetTitle("#kappa = 0.998");

  TCanvas *matrixC = new TCanvas();
  for (int i=0; i<nModels_jg; i++){
    tru_tmu_tank_hit_fold[i]->Draw("colz");
    if (i==0) matrixC->Print("matrix_kappas.ps(");
    if (i>0&&i<nModels_jg-1) matrixC->Print("matrix_kappas.ps");
    if (i==nModels_jg-1) matrixC->Print("matrix_kappas.ps)");
  }

  TH1F *toyMCtest_fold = transformedHist(tmu_truMC_fold,thits_tmuCorr_toy_fold);
  TH1F *toyMCtest_fold_unfold = transformedHist(toyMCtest_fold,thits_tmuCorr_toy_unfold);

  //return;

  toyMCtest_fold->SetLineWidth(2);
  toyMCtest_fold->SetLineColor(kBlue);
  thits_recoMC_fold->SetLineWidth(2);
  thits_recoMC_fold->SetLineColor(kRed);
  thits_recoMC_fold->SetLineStyle(2);

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  toyMCtest_fold->SetTitle("fold test;tank hits");

  toyMCtest_fold_unfold->SetLineWidth(4);
  toyMCtest_fold_unfold->SetLineColor(kBlack);
  toyMCtest_fold_unfold->SetLineStyle(2);

  TCanvas *testTest = new TCanvas();
  toyMCtest_fold->Draw();
  thits_recoMC_fold->Draw("same");
  testTest->Print("foldValidation_fold.eps");
  
  tmu_truMC_fold->SetTitle("blue: generated true dist black dashed: folded then unfolded;T_{#mu} (MeV)");
  tmu_truMC_fold->SetLineWidth(2);
  tmu_truMC_fold->SetLineColor(kBlue);
  
  TCanvas *c33 = new TCanvas();
  tmu_truMC_fold->Draw();
  toyMCtest_fold_unfold->Draw("same");
  if (whichDist==0) c33->Print("fold_unfold_smooth_thits.eps");
  if (whichDist==1) c33->Print("fold_unfold_smooth_stfull.eps");
    
  TH1F *thit[nModels];
  TH1F *backwards_check[nModels];

  TH1F *tmu_clones[nModels];
  
  for (int i=0; i<nModels; i++){

    //efficiency correct generated tmu
    for (int j=1; j<=tru_tmu[i]->GetNbinsX(); j++) tru_tmu[i]->SetBinContent(j,tru_tmu[i]->GetBinContent(j)*tmu_eff[11]->GetBinContent(j));

    //cout<<" model "<<i<<endl;

    //check backwards folding returns same object - important to do this AFTER efficiency correction
    tmu_clones[i] = (TH1F*)tru_tmu[i]->Clone(Form("tmu_clones_%d",i));

    thit[i] = transformedHist(tru_tmu[i],tru_tmu_tank_hit_fold[11]);
 
    backwards_check[i] = transformedHist(thit[i],tru_tmu_tank_hit_unfold[11]);
 
    //efficiency correct tank hits?
    //for (int j=1; j<=thit[i]->GetNbinsX(); j++) thit[i]->SetBinContent(j,thit[i]->GetBinContent(j)*tank_hit_eff[11]->GetBinContent(j));
  }  

  tmu_clones[0]->SetMaximum(tmu_clones[1]->GetMaximum());  
    
  TCanvas *testfuf = new TCanvas();
  for (int i=0; i<nModels; i++){
    
    tmu_clones[i]->SetLineColor(kRed);
    tmu_clones[i]->SetLineWidth(2);
    backwards_check[i]->SetLineStyle(2);
    backwards_check[i]->SetLineWidth(2);

    tmu_clones[i]->SetTitle(Form("Bayes' approach: model %d red: generated black dashed: folded to tank hits and then unfolded back; T_{#mu} (MeV)",i));
    tmu_clones[i]->Draw();
    backwards_check[i]->Draw("same");
    if (whichDist==0){
      if (i==0) testfuf->Print("fold_unfold_test_thits.ps(");
      if (i>0&&i<nModels-1) testfuf->Print("fold_unfold_test_thits.ps");
      if (i==nModels-1) testfuf->Print("fold_unfold_test_thits.ps)");
    }
    if (whichDist==1){
      if (i==0) testfuf->Print("fold_unfold_test_stfull.ps(");
      if (i>0&&i<nModels-1) testfuf->Print("fold_unfold_test_stfull.ps");
      if (i==nModels-1) testfuf->Print("fold_unfold_test_stfull.ps)");
    }
  }
 
  TH1F *thit_itercheck = transformedHist_iter(tru_tmu[3],tru_tmu_tank_hit_fold[11],1);

  thit_itercheck->SetLineStyle(2);
  thit_itercheck->SetLineColor(kRed);

  new TCanvas();
  thit[3]->Draw(); 
  thit_itercheck->Draw("same");

  int n_tests = 20;

  TH1F *thit_cv_iter[n_tests];
  for (int i=0; i<n_tests; i++){
  	thit_cv_iter[i] = transformedHist_iter(tru_tmu[9],tru_tmu_tank_hit_fold[11],i+1);
    thit_cv_iter[i]->SetLineWidth(2);
    thit_cv_iter[i]->SetLineColor(1+i);
  }

  thit_cv_iter[9]->SetLineColor(28);

  thit_cv_iter[0]->SetTitle("iteration check for CV kappa; tank hits");

  TLegend *leg33 = new TLegend(0.777, 0.285, 0.99, 0.996);
  for (int i=0; i<n_tests; i++){
    leg33->AddEntry(thit_cv_iter[i],Form("iter %d",i+1),"l");
  }

  thit_cv_iter[0]->SetMaximum(60000);

  TCanvas *cc3 = new TCanvas();
  thit_cv_iter[0]->Draw();
  for (int i=1; i<n_tests; i++)
    thit_cv_iter[i]->Draw("same");
  leg33->Draw();
  cc3->Print("cv_iter.png");	

  TCanvas *cc34 = new TCanvas();
  thit_cv_iter[n_tests-1]->Draw();
  leg33->Draw();
  cc34->Print("cv_iter_19.png");	
 
  TFile dump("iteration_to_confirm.root","RECREATE");
  for (int i=0; i<nModels; i++)  
    tru_tmu[i]->Write(tru_tmu[i]->GetName());
  tru_tmu_tank_hit_fold[11]->Write(tru_tmu_tank_hit_fold[11]->GetName());  
  for (int i=0; i<n_tests; i++) 
  	thit_cv_iter[i]->Write(Form("myres_iter_%d",i));
  dump.Close();
  
  TCanvas *resC[nModels];

  for (int i=0; i<nModels; i++){
    resC[i] = new TCanvas();
    thit[i]->Draw();
    resC[i]->Print(Form("thit_fold_model_%d_dist%d.eps",i,whichDist));
  }

  for (int i=0; i<nModels; i++){
    if (i<11) thit[i]->SetName(Form("kappa_0%d",978+2*i));
    else thit[i]->SetName(Form("kappa_%d",978+2*i)); 
  }

  tru_tmu_tank_hit_fold[0]->SetTitle("#kappa=1.022;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[1]->SetTitle("#kappa=1.000;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[2]->SetTitle("#kappa=1.002;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[3]->SetTitle("#kappa=1.004;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[4]->SetTitle("#kappa=1.006;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[5]->SetTitle("#kappa=1.008;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[6]->SetTitle("#kappa=1.010;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[7]->SetTitle("#kappa=1.012;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[8]->SetTitle("#kappa=1.014;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[9]->SetTitle("#kappa=1.016;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[10]->SetTitle("#kappa=1.018;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[11]->SetTitle("#kappa=0.978;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[12]->SetTitle("#kappa=0.982;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[13]->SetTitle("#kappa=0.984;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[14]->SetTitle("#kappa=0.986;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[15]->SetTitle("#kappa=0.988;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[16]->SetTitle("#kappa=0.990;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[17]->SetTitle("#kappa=0.992;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[18]->SetTitle("#kappa=0.994;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[19]->SetTitle("#kappa=0.996;tank hits; T_{#mu} (MeV)");
  tru_tmu_tank_hit_fold[20]->SetTitle("#kappa=0.998;tank hits; T_{#mu} (MeV)");

  TCanvas *mapz = new TCanvas();
  for (int i=0; i<nModels_jg; i++){
    tru_tmu_tank_hit_fold[i]->Draw("colz");
    if (i==0) mapz->Print("tmu_tank_hits_model_dep.ps(");
    if (i>0&&i<nModels_jg-1) mapz->Print("tmu_tank_hits_model_dep.ps");
    if (i==nModels_jg-1) mapz->Print("tmu_tank_hits_model_dep.ps)");
  }

  for (int i=0; i<nModels_jg; i++) tmu_eff[i]->SetLineColor(i+1);
  for (int i=0; i<nModels_jg; i++) tmu_eff[i]->SetLineWidth(2);
  //for (int i=0; i<nModels_jg; i++) tmu_eff[i]->SetTitle(Form("nuance kappa model %d",i));

  TCanvas *tmueffc = new TCanvas();
  tmu_eff[0]->Draw();
  for (int i=1; i<nModels_jg; i++) tmu_eff[i]->Draw("same");
  tmueffc->Print("tmu_eff.eps");

  for (int i=0; i<nModels; i++) thit[i]->SetLineColor(i+1);
  for (int i=0; i<nModels; i++) thit[i]->SetLineWidth(2);

  if (whichDist==0) thit[0]->SetMaximum(80000.);
  if (whichDist==1) thit[0]->SetMaximum(100000.);
  if (whichDist==0) thit[0]->SetTitle("236 MeV numu T_{#mu} translated to tank hits; tank hits");
  if (whichDist==1) thit[0]->SetTitle("236 MeV numu T_{#mu} translated to stfull energy; fitter energy (MeV)");

  TCanvas *thitspr = new TCanvas();
  thit[0]->Draw();
  for (int i=0; i<nModels; i++) 
  	thit[i]->Draw("same");
  leg->Draw();
  if (whichDist==0) thitspr->Print("tank_hits_models.eps");
  if (whichDist==1) thitspr->Print("stfull_models.eps");
  
  TString sig_name;
  if (whichDist==0) sig_name = "signal_templates_thits.root";
  if (whichDist==1) sig_name = "signal_templates_stfull.root";
  
  TFile writeFile(sig_name.Data(),"RECREATE");
  for (int i=0; i<nModels; i++) thit[i]->Write(thit[i]->GetName());
  writeFile.Close();
  
  ofstream myfile[nModels];

  for (int i=0; i<nModels; i++){

    if (whichDist==0){
      if (i<11) myfile[i].open (Form("signal_template_thits_kappa_0%d.txt",978+2*i));
      else myfile[i].open (Form("signal_template_thits_kappa_%d.txt",978+2*i));
    }
    if (whichDist==1){
      if (i<11) myfile[i].open (Form("signal_template_stfull_kappa_0%d.txt",978+2*i));
      else myfile[i].open (Form("signal_template_stfull_kappa_%d.txt",978+2*i));
    }
    
    for (int j=1; j<=thit[i]->GetNbinsX(); j++){
      
      myfile[i] << j;
      myfile[i] << "\t";
      myfile[i] << thit[i]->GetBinContent(j);
      myfile[i] << "\n";

    }

    myfile[i].close();
  }

  ofstream myfile_tmu[nModels];

  for (int i=0; i<nModels; i++){

    if (i<11) myfile_tmu[i].open (Form("tmu_kappa_0%d.txt",978+2*i));
    else myfile_tmu[i].open (Form("tmu_kappa_%d.txt",978+2*i));
    
    for (int j=1; j<=tru_tmu_my_bins[i]->GetNbinsX(); j++){
      
      myfile_tmu[i] << j;
      myfile_tmu[i] << "\t";
      myfile_tmu[i] << tru_tmu_my_bins[i]->GetBinContent(j);
      myfile_tmu[i] << "\n";

    }

    myfile_tmu[i].close();
  }
  
}


TH1F *transformedHist(TH1 *inpt,TH2 *corr){

  int nBinsX = corr->GetNbinsX();
  int nBinsY = corr->GetNbinsY();

  cout<<" nBinsX "<<nBinsX<<endl;
  cout<<" nBinsY "<<nBinsY<<endl;

  TH1F *result = new TH1F(inpt->GetName(),"",nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax());
  TH2F *normMatrix = new TH2F(corr->GetName(),"",nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax(),nBinsY,corr->GetYaxis()->GetXmin(),corr->GetYaxis()->GetXmax());

  TMatrixD smearing(nBinsX,nBinsY);
  TMatrixD smearedData(nBinsY,1);
  TMatrixD unsmearedData(nBinsX,1);

  double normScale[nBinsY];
  for (int i=1; i<=nBinsY; i++) normScale[i-1] = 0;

  //smearing.Print();
  
  for (int i=1; i<=nBinsY; i++)
    smearedData(i-1,0) = 0;

  for (int j=1; j<=nBinsX; j++)
    unsmearedData(j-1,0) = 0;

  for (int i=1; i<=nBinsX; i++){
    for (int j=1; j<=nBinsY; j++){

      //cout<<"i: "<<i<<" out of "<<nBinsX<<" j: "<<j<<" out of "<<nBinsY<<endl;
      smearing(i-1,j-1) = 0.;
      normMatrix->SetBinContent(i,j,0.);
    }
  }

  for (int i=1; i<=nBinsY; i++){
    smearedData(i-1,0) = inpt->GetBinContent(i);
    //cout<<" entry "<<i-1<<" smeared content "<<smearedData(i-1,0)<<endl;
  }

  for (int i=0; i<nBinsX; i++){
    for (int k=0; k<nBinsY; k++){

      //smearing(i,k) = corr->GetBinContent(k+1,i+1);
      smearing(i,k) = corr->GetBinContent(i+1,k+1);
      
    }//bins k
  }//bins i

  for (int i=0; i<nBinsX; i++){
    for (int k=0; k<nBinsY; k++){

    normScale[k] += smearing(i,k);

    }
  }
  
   //TH1F *probSlice[nBinsY];
   //for (int i=0; i<nBinsY; i++)  probSlice[i] = new TH1F(Form("probSlice_%d",i),Form("Prob slice for T_{#mu} #in (%2.0f,%2.0f) MeV (bin %d); tank hits; probability",corr->GetYaxis()->GetBinLowEdge(i+1),corr->GetYaxis()->GetBinUpEdge(i+1),i+1),nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax());
   
  for (int i=0; i<nBinsX; i++){
    for (int k=0; k<nBinsY; k++){

      if (normScale[k]!=0) smearing(i,k) = smearing(i,k) * (1/normScale[k]);
      else smearing(i,k) = 0.;//ignore?
      //cout<<" i "<<i<<" k "<<k<<" content "<<smearing(i,k)<<endl;

      if (smearing(i,k)==1.) smearing(i,k) = 0.; 

      //if (smearing(i,k)>0.3&&i!=0&&k!=0&&smearing(i-1,k)==0&&smearing(i,k-1)==0) smearing(i,k) = 0.;

      normMatrix->SetBinContent(i+1,k+1,smearing(i,k));

      //probSlice[k]->SetBinContent(i+1,smearing(i,k));

    }
  }

  double lost_events = 0.;

//   TCanvas *probSliceC = new TCanvas();
// 
//    for (int i=0; i<nBinsY; i++){
//     probSlice[i]->Draw();
//     if (i==0) probSliceC->Print("prob_slices.ps(");
//     if (i>0&&i<nBinsY-1) probSliceC->Print("prob_slices.ps");
//     if (i==nBinsY-1) probSliceC->Print("prob_slices.ps)");
//     //cout<<"slice "<<i<<" prob integral is "<<probSlice[i]->Integral()<<" data events is "<<inpt->GetBinContent(i+1)<<endl;
//     if (probSlice[i]->Integral()==0)  lost_events += inpt->GetBinContent(i+1);
//   }
  
  //cout<<"smearing matrix is "<<endl;
  //smearing.Print();

  unsmearedData = smearing * smearedData;

  for (int i=1; i<=nBinsX; i++){
    result->SetBinContent(i,unsmearedData(i-1,0));
    //cout<<" entry "<<i-1<<" unsmeared content "<<unsmearedData(i-1,0)<<" bin content "<<result->GetBinContent(i)<<endl;
  }

  //new TCanvas();
  //normMatrix->Draw("colz");

  cout<<"\n input hist integral = "<<inpt->Integral()<<" \n"<<endl;
  cout<<"\n resultant hist integral = "<<result->Integral()<<" \n"<<endl;
  cout<<"\n lost events = "<<lost_events<<" \n"<<endl;

  return result;

}

TH1F *transformedHist_iter(TH1 *inpt,TH2 *corr, int n_iter){

  int nBinsX = corr->GetNbinsX();
  int nBinsY = corr->GetNbinsY();

  cout<<" nBinsX "<<nBinsX<<endl;
  cout<<" nBinsY "<<nBinsY<<endl;

  TH1F *result[n_iter];
  TH2F *normMatrix[n_iter];
  TH1D *true_dist = corr->ProjectionX();//from MC of course.  use to iterate
  
//   new TCanvas();
//   true_dist->Draw();
// 
//   new TCanvas();
//   corr->Draw("colz");
  
  cout<<"1"<<endl;
  
  for (int i=0; i<n_iter; i++){
    result[i] = new TH1F(Form("res_iter_%d",i),"",nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax());
    normMatrix[i] = new TH2F(Form("norm_mat_iter_%d",i),"",nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax(),nBinsY,corr->GetYaxis()->GetXmin(),corr->GetYaxis()->GetXmax());
  }

  cout<<"2"<<endl;

  TMatrixD smearing(nBinsX,nBinsY);
  TMatrixD smearedData(nBinsY,1);
  TMatrixD unsmearedData(nBinsX,1);

  double normScale[nBinsY];

  double it_wght[nBinsX];
  for (int i=0; i<nBinsX; i++) it_wght[i] = 0.;
  double lost_events = 0.;

  cout<<"3"<<endl;

  //smearing.Print();
  
  for (int p=0; p<n_iter; p++){

    lost_events = 0.;

    for (int i=1; i<=nBinsY; i++) 
      normScale[i-1] = 0;
  
    for (int i=1; i<=nBinsY; i++)
      smearedData(i-1,0) = 0;

    for (int j=1; j<=nBinsX; j++)
      unsmearedData(j-1,0) = 0;

    for (int i=1; i<=nBinsX; i++){
      for (int j=1; j<=nBinsY; j++){

        //cout<<"i: "<<i<<" out of "<<nBinsX<<" j: "<<j<<" out of "<<nBinsY<<endl;
        smearing(i-1,j-1) = 0.;
        normMatrix[p]->SetBinContent(i,j,0.);

      }
    }

    for (int i=1; i<=nBinsY; i++){
      smearedData(i-1,0) = inpt->GetBinContent(i);
      //cout<<" entry "<<i-1<<" smeared content "<<smearedData(i-1,0)<<endl;
    }

    for (int i=0; i<nBinsX; i++){
      for (int k=0; k<nBinsY; k++){

      //smearing(i,k) = corr->GetBinContent(k+1,i+1);
      smearing(i,k) = 0.;
      smearing(i,k) = corr->GetBinContent(i+1,k+1);
      
      }//bins k
    }//bins i

    if (p>0){//iterate
      for (int i=0; i<nBinsX; i++){
        
        it_wght[i] = 1.;
        
        if (true_dist->GetBinContent(i)!=0)
        	it_wght[i] = result[p-1]->GetBinContent(i) / true_dist->GetBinContent(i);
        
        cout<<"true bin "<<i<<" true dist "<<true_dist->GetBinContent(i)<<" prev res "<<result[p-1]->GetBinContent(i)<<" it_wght = "<<it_wght[i]<<endl;
        
      }
    
      for (int k=0; k<nBinsY; k++){
        
        for (int i=0; i<nBinsX; i++){
          //cout<<" i,k "<<i<<","<<k<<" wght "<<it_wght[k]<<endl;   
          smearing(i,k) = smearing(i,k) * it_wght[i];
        }
      }
    }
    
    //smearing.Print();

    for (int i=0; i<nBinsX; i++){
      for (int k=0; k<nBinsY; k++){

      normScale[k] += smearing(i,k);

      }
    }
  
    TH1F *probSlice[nBinsY];
    for (int i=0; i<nBinsY; i++)  probSlice[i] = new TH1F(Form("probSlice_%d",i),Form("Prob slice for T_{#mu} #in (%2.0f,%2.0f) MeV (bin %d); tank hits; probability",corr->GetYaxis()->GetBinLowEdge(i+1),corr->GetYaxis()->GetBinUpEdge(i+1),i+1),nBinsX,corr->GetXaxis()->GetXmin(),corr->GetXaxis()->GetXmax());
   
    for (int i=0; i<nBinsX; i++){
      for (int k=0; k<nBinsY; k++){

        if (normScale[k]!=0) smearing(i,k) = smearing(i,k) * (1/normScale[k]);
        else smearing(i,k) = 0.;//ignore?
        //cout<<" i "<<i<<" k "<<k<<" content "<<smearing(i,k)<<endl;

        if (smearing(i,k)==1.) smearing(i,k) = 0.; 

        //if (smearing(i,k)>0.3&&i!=0&&k!=0&&smearing(i-1,k)==0&&smearing(i,k-1)==0) smearing(i,k) = 0.;

        normMatrix[p]->SetBinContent(i+1,k+1,smearing(i,k));

        probSlice[k]->SetBinContent(i+1,smearing(i,k));

      }
    }

/*
  TCanvas *probSliceC = new TCanvas();

   for (int i=0; i<nBinsY; i++){
    probSlice[i]->Draw();
    if (i==0) probSliceC->Print("prob_slices.ps(");
    if (i>0&&i<nBinsY-1) probSliceC->Print("prob_slices.ps");
    if (i==nBinsY-1) probSliceC->Print("prob_slices.ps)");
    //cout<<"slice "<<i<<" prob integral is "<<probSlice[i]->Integral()<<" data events is "<<inpt->GetBinContent(i+1)<<endl;
    if (probSlice[i]->Integral()==0)  lost_events += inpt->GetBinContent(i+1);
  }
*/  
  //cout<<"smearing matrix is "<<endl;
  //smearing.Print();

    unsmearedData = smearing * smearedData;

    for (int i=1; i<=nBinsX; i++){
      result[p]->SetBinContent(i,unsmearedData(i-1,0));
      //cout<<" entry "<<i-1<<" unsmeared content "<<unsmearedData(i-1,0)<<" bin content "<<result->GetBinContent(i)<<endl;
    }

    cout<<"\n current step is "<<p<<" \n"<<endl;
    cout<<"\n input hist integral = "<<inpt->Integral()<<" \n"<<endl;
    cout<<"\n resultant hist integral = "<<result[p]->Integral()<<" \n"<<endl;
    cout<<"\n lost events = "<<lost_events<<" \n"<<endl;

  }

  //new TCanvas();
  //normMatrix->Draw("colz");

  cout<<"end"<<endl;

  return result[n_iter-1];

}

