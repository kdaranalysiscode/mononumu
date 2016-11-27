
#if !(defined(__CINT__) || defined(__CLING__)) || defined(__ACLIC__)
#include <iostream>
using std::cout;
using std::endl;

#include "TRandom.h"
#include "TH1D.h"

#include "RooUnfoldResponse.h"
#include "RooUnfoldBayes.h"
//#include "RooUnfoldInvert.h"
#include "RooUnfoldSvd.h"
//#include "RooUnfoldTUnfold.h"
#endif

void unfold_systs()
{

  const int nOMs = 50;

  TH1F *cv;	
  TH1F *model; 
  TH1F *disc_abs; 
  TH1F *qtcorr_abs;	
  TH1F *dirt_abs; 	
  TH1F *strobe_abs; 	
  TH1F *oms_abs[nOMs]; 	

  bool stfull = 1;
  
  TFile *stfullcv = new TFile("./unfoldFile_fullmcstats_stfull.root");

  TFile *to_unfold_abs_norm = new TFile("./tank_hits_for_unfolding_abs_norm.root");

  if (stfull==0) to_unfold_abs_norm->GetObject("CV",cv);
  if (stfull) stfullcv->GetObject("thits_bkgsubt_7",cv);
  to_unfold_abs_norm->GetObject("model_dep_one_sigma",model);
  to_unfold_abs_norm->GetObject("alt_disc",disc_abs);
  to_unfold_abs_norm->GetObject("alt_qtcorr",qtcorr_abs);
  to_unfold_abs_norm->GetObject("thits_alt_dirt",dirt_abs);
  to_unfold_abs_norm->GetObject("thits_alt_strobe",strobe_abs);  
  for (int i=0; i<nOMs; i++)
  	to_unfold_abs_norm->GetObject(Form("alt_om_%d",i),oms_abs[i]);

  TH1F *disc_shape; 
  TH1F *qtcorr_shape;	
  TH1F *dirt_shape; 	
  TH1F *strobe_shape; 	
  TH1F *oms_shape[nOMs]; 	

  TFile *to_unfold_shape = new TFile("./tank_hits_for_unfolding_shape_only.root");

  //to_unfold_shape->GetObject("CV",cv);
  to_unfold_shape->GetObject("alt_disc",disc_shape);
  to_unfold_shape->GetObject("alt_qtcorr",qtcorr_shape);
  to_unfold_shape->GetObject("thits_alt_dirt",dirt_shape);
  to_unfold_shape->GetObject("thits_alt_strobe",strobe_shape);  
  for (int i=0; i<nOMs; i++)
  	to_unfold_shape->GetObject(Form("alt_om_%d",i),oms_shape[i]);


  cv->GetFunction("gaus")->SetBit(TF1::kNotDraw);

  //get unfolding matrix
  //TFile *ff=new TFile("./unfoldFile_fullmcstats_leo_10tankhit_bins_fixed_data_transr.root");
  TFile *ff=new TFile("./unfoldFile_fullmcstats.root");
  TH2D *matrix;
  if (stfull==0) matrix= (TH2D*)ff->Get("truTmu_tHit1_1");
  if (stfull) matrix = (TH2D*)stfullcv->Get("truTmu_tHit1_7");
  TH1D *hist_eff= (TH1D*)ff->Get("tmu_eff_unfold_1");
  //TH1D *hist_eff_lb= (TH1D*)ff->Get("tmu_eff_unfold_11");
  TH1D *hist_eff_ub= (TH1D*)ff->Get("tmu_eff_unfold_3");
  //TH2D *matrix_lb = (TH2D*)ff->Get("truTmu_tHit1_11");//lower bound kappa = 0.978
  TH2D *matrix_ub = (TH2D*)ff->Get("truTmu_tHit1_4");//upper bound kappa = 1.004

  TFile *ff2=new TFile("./muon_Tmu_nuance_kappa.root");
  TH1D *hist_test= (TH1D*)ff2->Get("kappa_1000");
  hist_test->Rebin(10);//need to rebin so that binning is consistent
  TH1D *hist_nuance=new TH1D("","",30,0,.3);//MeV->GeV
  TH2D *newmatrix=new TH2D("","",matrix->GetNbinsY(),matrix->GetYaxis()->GetBinLowEdge(1),matrix->GetYaxis()->GetBinUpEdge(matrix->GetNbinsY()),25,0,.25);//need this matrix to switch rows and columns of default matrix
  TH2D *newmatrix_ub = new TH2D("","",30,0.,300.,25,0,.25);//need this matrix to switch rows and columns of default matrix
  //TH2D *newmatrix_lb = new TH2D("","",30,0.,300.,25,0,.25);//need this matrix to switch rows and columns of default matrix

  for(int j=1;j<=hist_test->GetNbinsX();j++)//j is true index
    {
      hist_nuance->SetBinContent(j,hist_test->GetBinContent(j)*.001);//MeV->GeV
      hist_eff->SetBinError(j,0);//dividing out efficiency messes up error bars without this line
    }

  //need to switch rows and columns
  for (int i=1;i<=matrix->GetNbinsX();i++){
      for (int j=1;j<=matrix->GetNbinsY();j++){
      
	  newmatrix->SetBinContent(j,i,matrix->GetBinContent(i,j));         
          //newmatrix_lb->SetBinContent(j,i,matrix_lb->GetBinContent(i,j));
          newmatrix_ub->SetBinContent(j,i,matrix_ub->GetBinContent(i,j));
	
	}
  }

  float n_iterations = 2;//really means a single iteration following the initial unfolding 
 
  RooUnfoldResponse response (matrix->GetNbinsY(), matrix->GetYaxis()->GetBinLowEdge(1), matrix->GetYaxis()->GetBinUpEdge(matrix->GetNbinsY()), 25, 0., .25);
  response.Setup(0,0,newmatrix);
  RooUnfoldBayes   unfold (&response, cv,1);//1 iterations    
  TH1D* cv_one_it = (TH1D*) unfold.Hreco();

  RooUnfoldBayes   unfold2 (&response, cv, 2);//2 iterations   
  TH1D* cv_two_it = (TH1D*) unfold2.Hreco();
  TH1D* EReco2 = (TH1D*) unfold2.Ereco();//error matrix for 2 iterations

  RooUnfoldBayes   unfold_cv (&response, cv, n_iterations);
  TH1D* unfolded_cv = (TH1D*) unfold_cv.Hreco();
  //unfolded_cv->Divide(hist_eff);
  TH2D* cv_cov = (TH2D*) unfold_cv.Ereco();

  TCanvas *ddd = new TCanvas();
  cv->Draw();
  ddd->Print("test_cvs.eps");

  TString name;

  if (stfull)    name = "unfolded_stfull.root";
  if (stfull==0) name = "unfolded_thits.root";

TFile compfile(name.Data(),"RECREATE");
unfolded_cv->Write("unfolded_cv");
compfile.Close();
return;

  cout<<" int before "<<cv->Integral()<<endl;
  cout<<" int after "<<unfolded_cv->Integral()<<endl;

  RooUnfoldBayes   unfold3 (&response, cv, 3);   
  TH1D* cv_three_it = (TH1D*) unfold3.Hreco();
  cv_three_it->Divide(hist_eff);

  RooUnfoldBayes   unfold4 (&response, cv, 4);   
  TH1D* cv_four_it = (TH1D*) unfold4.Hreco();

  RooUnfoldBayes   unfold10 (&response, cv, 10);   
  TH1D* cv_ten_it = (TH1D*) unfold10.Hreco();

  unfolded_cv->SetTitle("stat and unfolding uncertainty estimate included;T_{#mu} (GeV); unfolded events");
  unfolded_cv->SetLineColor(kRed);
  cv_three_it->SetLineColor(kBlue);
  cv_one_it->SetLineColor(kBlack);

  unfolded_cv->SetMarkerStyle(20);
  cv_three_it->SetMarkerStyle(20);
  cv_one_it->SetMarkerStyle(20);

  unfolded_cv->SetMarkerColor(kRed);
  cv_three_it->SetMarkerColor(kBlue);
  cv_one_it->SetMarkerColor(kBlack);

  gStyle->SetOptStat(0000);
  unfolded_cv->SetMaximum(600);

  TLegend *leg35 = new TLegend(0.649,0.75,0.998,0.92);
  leg35->SetTextSize(0.035);
  leg35->SetTextColor(1);
  leg35->AddEntry(cv_one_it,"0 iterations","pl");
  leg35->AddEntry(unfolded_cv,"1 iteration (CV)","pl");
  leg35->AddEntry(cv_three_it,"2 iterations","pl");
  leg35->SetFillColor(0);
  leg35->SetLineColor(1);
  leg35->SetTextFont(22);

  if (stfull) unfolded_cv->SetTitle("reco var = stfull");
  //if (stfull) unfolded_cv->SetMaximum(200.);
  //if (stfull) unfolded_cv->SetMinimum(-50.);

  TCanvas *uuun = new TCanvas();
  unfolded_cv->Draw("e1p");
  cv_three_it->Draw("e1p same");
  cv_one_it->Draw("e1p same");
  leg35->Draw();
  if (stfull)    uuun->Print("unfold_comp_stfull.eps");
  if (stfull==0) uuun->Print("unfold_comp_thits.eps");

  //RooUnfoldResponse response_lb (30, 0.0, 300.0 , 25, 0., .25);
  //response_lb.Setup(0,0,newmatrix_lb);

  //RooUnfoldBayes   unfold_lb (&response_lb, cv, n_iterations);
  //TH1D* cv_w_lb = (TH1D*) unfold_lb.Hreco();

  RooUnfoldResponse response_ub (30, 0.0, 300.0 , 25, 0., .25);
  response_ub.Setup(0,0,newmatrix_ub);

  RooUnfoldBayes   unfold_ub (&response_ub, cv, n_iterations);
  TH1D* cv_w_ub = (TH1D*) unfold_ub.Hreco();

  cv_one_it->SetLineWidth(2);
  cv_one_it->SetLineColor(kRed);

  cv_two_it->SetLineWidth(2);
  cv_two_it->SetLineColor(kBlue);

  cv_three_it->SetLineWidth(2);
  //cv_three_it->SetLineStyle(2);
  cv_three_it->SetLineColor(kBlack);

  unfolded_cv->SetLineWidth(2);
  unfolded_cv->SetLineColor(kBlack);

  //cv_w_lb->SetLineWidth(2);
  //cv_w_lb->SetLineColor(kBlue);

  cv_w_ub->SetLineWidth(2);
  //cv_w_ub->SetLineStyle(2);
  cv_w_ub->SetLineColor(kRed);

  cv_four_it->SetLineWidth(2);
  //cv_four_it->SetLineStyle(2);
  cv_four_it->SetLineColor(28);

  cv_ten_it->SetLineWidth(2);
  cv_ten_it->SetLineColor(12);

  cv_one_it->SetMaximum(1200.);

  cv_three_it->SetTitle(" before eff corr;T_{#mu} (GeV)");

  TLegend *leg5 = new TLegend(0.649,0.824,0.998,0.988);
  leg5->SetTextSize(0.035);
  leg5->SetTextColor(1);
  leg5->AddEntry(cv_three_it,"CV unfold mat #kappa = 1.000","l");
  //leg5->AddEntry(cv_w_lb,"unfold matrix #kappa = 0.978","l");
  leg5->AddEntry(cv_w_ub,"unfold matrix #kappa = 1.006","l");
  leg5->SetFillColor(0);
  leg5->SetLineColor(1);
  leg5->SetTextFont(22);

  gStyle->SetOptStat(0000);

  TCanvas *sig_mdC = new TCanvas();
  cv_three_it->Draw("hist");
  //cv_w_lb->Draw("same hist");
  cv_w_ub->Draw("same hist");
  leg5->Draw();
  sig_mdC->Print("signal_model_unfold_bef_eff.eps");
  sig_mdC->Print("signal_model_unfold_bef_eff.png");

  float val = 0.;
  float eff = 0.;

  for (int i=1; i<=cv_one_it->GetNbinsX();i++){ 

  	val = 0.;
  	val = cv_one_it->GetBinContent(i);

  	eff = 0.;
  	eff = hist_eff->GetBinContent(i);

  	if (eff>0.) cv_one_it->SetBinContent(i,val/eff);

  	val = 0.;
  	val = cv_two_it->GetBinContent(i);

  	if (eff>0.) cv_two_it->SetBinContent(i,val/eff);

  	val = 0.;
  	val = cv_three_it->GetBinContent(i);

  	if (eff>0.) cv_three_it->SetBinContent(i,val/eff);

  	val = 0.;
  	val = cv_four_it->GetBinContent(i);

  	if (eff>0.) cv_four_it->SetBinContent(i,val/eff);

  }

  //cv_w_lb->Divide(hist_eff_lb); 
  cv_w_ub->Divide(hist_eff_ub);

  cv_three_it->SetTitle("after eff correction");

  TLegend *leg55 = new TLegend(0.649,0.824,0.998,0.988);
  leg55->SetTextSize(0.035);
  leg55->SetTextColor(1);
  leg55->AddEntry(cv_three_it,"CV mat+eff #kappa = 0.996","l");
  //leg55->AddEntry(cv_w_lb,"mat+eff #kappa = 0.978","l");
  leg55->AddEntry(cv_w_ub,"mat+eff #kappa = 1.004","l");
  leg55->SetFillColor(0);
  leg55->SetLineColor(1);
  leg55->SetTextFont(22);

  TCanvas *sig_md2C = new TCanvas();
  cv_three_it->Draw("hist");
  //cv_w_lb->Draw("same hist");
  cv_w_ub->Draw("same hist");
  leg55->Draw();
  sig_md2C->Print("signal_model_unfold_aft_eff.eps");
  sig_md2C->Print("signal_model_unfold_aft_eff.png");

  hist_nuance->Scale(cv_one_it->Integral()/hist_nuance->Integral());

  cout<<" one it norm "<<cv_one_it->Integral()<<endl;
  cout<<" two it norm "<<cv_two_it->Integral()<<endl;
  cout<<" nuance pred norm "<<hist_nuance->Integral()<<endl;

  gStyle->SetOptStat(0000);

  cv_one_it->SetTitle("red: one iter, blue: two iter, purple: three iter, brown: four iter, solid: nuance prediction; T_{#mu} (GeV); eff-corrected events");

  TCanvas *cc = new TCanvas();
  cv_one_it->Draw();
  cv_two_it->Draw("same");
  cv_three_it->Draw("same");
  cv_four_it->Draw("same");
  cv_ten_it->Draw("hist same");
  hist_nuance->Draw("same");
  cc->Print("iter_test.png");

  RooUnfoldBayes   unfold_model (&response, model, n_iterations);
  TH1D* model_tmu = (TH1D*) unfold_model.Hreco();
  model_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_disc (&response, disc_abs, n_iterations);
  TH1D* disc_abs_tmu = (TH1D*) unfold_disc.Hreco();
  disc_abs_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_qtcorr (&response, qtcorr_abs, n_iterations);   
  TH1D* qtcorr_abs_tmu = (TH1D*) unfold_qtcorr.Hreco();
  qtcorr_abs_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_dirt (&response, dirt_abs, n_iterations); 
  TH1D* dirt_abs_tmu = (TH1D*) unfold_dirt.Hreco();
  dirt_abs_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_strobe (&response, strobe_abs, n_iterations);   
  TH1D* strobe_abs_tmu = (TH1D*) unfold_strobe.Hreco();
  strobe_abs_tmu->Divide(hist_eff);

  TH1D *om_tmu[nOMs];
  RooUnfoldBayes  *unfold_om[nOMs]; 

  for (int i=0; i<nOMs; i++){
    unfold_om[i]  = new RooUnfoldBayes(&response, oms_abs[i], n_iterations);
    om_tmu[i] = (TH1D*) unfold_om[i].Hreco();
    om_tmu[i]->Divide(hist_eff);
  }

  RooUnfoldBayes   unfold_disc_sh (&response, disc_shape, n_iterations);
  TH1D* disc_shape_tmu = (TH1D*) unfold_disc_sh.Hreco();
  disc_shape_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_qtcorr_sh (&response, qtcorr_shape, n_iterations);   
  TH1D* qtcorr_shape_tmu = (TH1D*) unfold_qtcorr_sh.Hreco();
  qtcorr_shape_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_dirt_sh (&response, dirt_shape, n_iterations); 
  TH1D* dirt_shape_tmu = (TH1D*) unfold_dirt_sh.Hreco();
  dirt_shape_tmu->Divide(hist_eff);

  RooUnfoldBayes   unfold_strobe_sh (&response, strobe_shape, n_iterations);   
  TH1D* strobe_shape_tmu = (TH1D*) unfold_strobe_sh.Hreco();
  strobe_shape_tmu->Divide(hist_eff);

  TH1D *om_shape_tmu[nOMs];
  RooUnfoldBayes  *unfold_shape_om[nOMs]; 

  for (int i=0; i<nOMs; i++){
    unfold_shape_om[i]  = new RooUnfoldBayes(&response, oms_shape[i], n_iterations);
    om_shape_tmu[i] = (TH1D*) unfold_shape_om[i].Hreco();
    om_shape_tmu[i]->Divide(hist_eff);
  }
  
  model_tmu->SetLineWidth(2);
  model_tmu->SetLineColor(kBlue);

  disc_abs_tmu->SetLineWidth(2);
  disc_abs_tmu->SetLineColor(kMagenta);

  qtcorr_abs_tmu->SetLineWidth(2);
  qtcorr_abs_tmu->SetLineStyle(2);
  qtcorr_abs_tmu->SetLineColor(kViolet);

  dirt_abs_tmu->SetLineWidth(2);
  dirt_abs_tmu->SetLineStyle(2);
  dirt_abs_tmu->SetLineColor(28);

  strobe_abs_tmu->SetLineWidth(2);
  strobe_abs_tmu->SetLineColor(95);

  cv_three_it->SetLineStyle(1);
  cv_three_it->SetLineColor(kBlack);

  cv_three_it->SetMaximum(1100);

  cv_three_it->SetTitle("3 iterations;T_{#mu} (GeV)");

  TLegend *leg = new TLegend(0.649,0.824,0.998,0.988);
  leg->SetTextSize(0.035);
  leg->SetTextColor(1);
  leg->AddEntry(cv_three_it,"CV","l");
  leg->AddEntry(model_tmu,"model","l");
  leg->AddEntry(disc_abs_tmu,"det disc","l");
  leg->AddEntry(qtcorr_abs_tmu,"det qtcorr","l");
  leg->AddEntry(dirt_abs_tmu,"dirt","l");
  leg->AddEntry(strobe_abs_tmu,"strobe","l");
  leg->SetFillColor(0);
  leg->SetLineColor(1);
  leg->SetTextFont(22);

  TCanvas *unisims = new TCanvas();
  unfolded_cv->Draw("hist");
  //cv_three_it->Draw("hist");
  disc_abs_tmu->Draw("hist same");
  qtcorr_abs_tmu->Draw("hist same");
  model_tmu->Draw("hist same");
  dirt_abs_tmu->Draw("hist same");
  strobe_abs_tmu->Draw("hist same");
  leg->Draw();
  unisims->Print("tmu_unisims.eps");

  unfolded_cv->SetMaximum(1000);

  TCanvas *omC = new TCanvas();
  unfolded_cv->Draw("hist");
  for (int i=0; i<nOMs; i++)
  	om_tmu[i]->Draw("hist same");
  unfolded_cv->Draw("hist same");
  omC->Print("tmu_om.eps");

  TFile unfolded_file("unfolded.root","RECREATE");
  unfolded_cv->Write("CV");
  cv_three_it->Write("cv_three_it");
  cv_cov->Write("CV_cov");
  //cv_w_lb->Write("sig_model_lb");
  cv_w_ub->Write("sig_model_ub");
  model_tmu->Write("model_tmu");
  disc_abs_tmu->Write("disc_abs_tmu");
  qtcorr_abs_tmu->Write("qtcorr_abs_tmu");
  dirt_abs_tmu->Write("dirt_abs_tmu");
  strobe_abs_tmu->Write("strobe_abs_tmu");
  for (int k=0; k<nOMs; k++) om_tmu[k]->Write(Form("om_abs_tmu_%d",k));

  hist_nuance->Write("nuance_pred");

  disc_shape_tmu->Write("disc_shape_tmu");
  qtcorr_shape_tmu->Write("qtcorr_shape_tmu");
  dirt_shape_tmu->Write("dirt_shape_tmu");
  strobe_shape_tmu->Write("strobe_shape_tmu");
  for (int k=0; k<nOMs; k++) om_shape_tmu[k]->Write(Form("om_shape_tmu_%d",k));

  unfolded_file.Close();
  
  return;

  /*
  
  TFile *ff=new TFile("./unfoldFile_fullmcstats_leo_10tankhit_bins_fixed_data_transr.root");
  TH1D *hist= (TH1D*)ff->Get("thits_bkgsubt_19");
  TH2D *matrix= (TH2D*)ff->Get("truTmu_tHit1_19");
  TH1D *hist_eff= (TH1D*)ff->Get("tmu_eff_unfold_19");
  TH2D *newmatrix=new TH2D("","",30.,0.,300.,25,0,.25);//need this matrix to switch rows and columns of default matrix

  TFile *ff2=new TFile("./muon_Tmu_nuance_kappa.root");
  TH1D *hist_test= (TH1D*)ff2->Get("kappa_0996");
  hist_test->Rebin(10);//need to rebin so that binning is consistent
  TH1D *hist_nuance=new TH1D("","",30,0,.3);//MeV->GeV

  //need to switch rows and columns
  for(int i=1;i<=matrix->GetNbinsX();i++)
    {
      for(int j=1;j<=matrix->GetNbinsY();j++)
	{
	  newmatrix->SetBinContent(j,i,matrix->GetBinContent(i,j));         
	}
    }

  RooUnfoldResponse response (30, 0.0, 300.0 , 25, 0., .25);
  RooUnfoldResponse response3 (25, 0., .25,30, 0.0, 300.0);//matrix for re-folding 
  response.Setup(0,0,newmatrix);
  response3.Setup(0,0,matrix);//for re-folding the result
 
  RooUnfoldBayes   unfold (&response, hist,1);//1 iterations    
  TH1D* hReco= (TH1D*) unfold.Hreco();
  
  RooUnfoldBayes   unfold (&response, hist, 2);//2 iterations   
  TH1D* hReco2= (TH1D*) unfold.Hreco();
  TH1D* EReco2= (TH1D*) unfold.Ereco();//error matrix for 2 iterations
  
  RooUnfoldBayes   unfold (&response, hist, 3);//3 iterations
  TH1D* hReco3= (TH1D*) unfold.Hreco();
  
  RooUnfoldBayes   unfold (&response, hist, 4);//4 iterations
  TH1D* hReco4= (TH1D*) unfold.Hreco();
  
  RooUnfoldSvd   unfold2 (&response, hist, 10);//SVD unfolding with parameter=10
  TH1D* hReco_svd= (TH1D*) unfold2.Hreco();
  
  RooUnfoldBayes   unfold3 (&response3, hReco2, 2);//refolding (2 iterations) 
  TH1D* hReco_folded= (TH1D*) unfold3.Hreco();

  for(int j=1;j<=hist_test->GetNbinsX();j++)//j is true index
    {
      hist_nuance->SetBinContent(j,hist_test->GetBinContent(j)*.001);//MeV->GeV
      hist_eff->SetBinError(j,0);//dividing out efficiency messes up error bars without this line
    }
  
  gStyle->SetOptStat(kFALSE);
  hReco->Divide(hist_eff);
  hReco->SetLineColor(2);
  hist_nuance->SetTitle("Comparing unfolding techniques. Error bars include both unfolding and stat uncertainties");
  hist_nuance->SetXTitle("T_{#mu} (GeV)");
  hist_nuance->SetYTitle("Normalized");
  hist_nuance->DrawNormalized();
  hReco2->SetLineColor(4);
  hReco2->Divide(hist_eff);
  hReco2->DrawNormalized("SAME");
  hReco3->SetLineColor(6);
  hReco3->Divide(hist_eff);
  hReco3->DrawNormalized("SAME");
  hReco->DrawNormalized("SAME");
  //get unfolded result from Tikhonov (for reference)
  TFile *ff=new TFile("tunfold.root");
  TH1D *regularized= (TH1D*)ff->Get(";1");
  regularized->DrawNormalized("SAME");

  TLegend *legend = new TLegend(0.55,0.64,0.8,0.89);
  legend->SetTextSize(0.04);
  legend->AddEntry(regularized,"Tikhonov","l");
  legend->AddEntry(hReco,"Bayesian 1 iterations","l");
  legend->AddEntry(hReco2,"Bayesian 2 iterations","l");
  legend->AddEntry(hReco3,"Bayesian 3 iterations","l");
  legend->AddEntry(hist_nuance,"Nuance #kappa=0.996","l");
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->Draw("same");  
  
  new TCanvas;
  //error matrix!
  EReco2->Draw("COLZ");
  
  //calculate chi2 of folded result
  double chi2=0.;
  for(int ii=3;ii<=30;ii++)
    {
      chi2+=pow(hReco_folded->GetBinContent(ii)-hist->GetBinContent(ii),2)/pow(hist->GetBinError(ii),2);
    }
  cout<<"Chi2: "<<chi2<<" with ndf: "<<28<<endl;
  
  new TCanvas;
  hist.GetFunction("gaus")->SetBit(TF1::kNotDraw);
  hReco_folded->SetLineColor(2);
  hReco_folded->SetTitle(Form("Data compared to re-folded tank hits [#chi^{2} is%8.2f (ndf=28)]",chi2));
  hReco_folded->DrawNormalized();
  hist->SetMarkerColor(1);
  hist->DrawNormalized("SAME ");
  TLatex tex(0.5,0.5,"u");
  tex.SetTextFont(32);
  tex.SetTextAlign(22);
  tex.SetTextSize(0.14);
  TLegend *legend = new TLegend(0.4,0.64,0.8,0.89);
  legend->SetTextSize(0.04);
  legend->AddEntry(hist,"data","l");
  legend->AddEntry(hReco_folded,"Refolded w/ Bayesian (2 iterations)","l");
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->Draw("same");

  gPad->GetCanvas()->Print("folded_0996.pdf");

  */
}

#ifndef __CINT__
int main () { RooUnfoldExample(); return 0; }  // Main program when run stand-alone
#endif
