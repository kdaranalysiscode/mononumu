#include "TF1.h"
#include "TF2.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TGraph2DErrors.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TRandom3.h"
#include "TRandom.h"
#include <iostream>
#include "TBox.h"
#include <fstream>
#include "TH2F.h"
#include "TMarker.h"
#include "TPoint.h"
#include "TStyle.h"
#include "TLine.h"
#include "TLatex.h"
#include "TGaxis.h"

using namespace std;

void comp(){
 
gStyle->SetPadGridX(kTRUE);
gStyle->SetPadGridY(kTRUE);
 
  TH1D *thits;
  TFile *thitsf = new TFile("unfolded_thits.root");
  thitsf->GetObject("unfolded_cv",thits);

  TH1D *stfull;
  TFile *stfullf = new TFile("unfolded_stfull.root");
  stfullf->GetObject("unfolded_cv",stfull);

  TH1D *stflux;
  TFile *stfluxf = new TFile("unfolded_stflux.root");
  stfluxf->GetObject("unfolded_cv",stflux);

  thits->SetMarkerColor(kRed);
  stfull->SetMarkerColor(kBlue);
  stflux->SetMarkerColor(kBlack);
 
  thits->SetTitle("red: thits (20\% unc) blue: stfull_energy black: stflux_ecer_mu; T_{#mu} (GeV); unfolded events norm to unity");

  thits->GetYaxis()->SetTitleOffset(1.3);

  thits->SetMarkerStyle(20);
  stfull->SetMarkerStyle(20);
  stflux->SetMarkerStyle(20);

  gStyle->SetOptStat(0000);

  for (int i=1; i<=thits->GetNbinsX(); i++) thits->SetBinError(i,0.2 * thits->GetBinContent(i));
  for (int i=1; i<=stfull->GetNbinsX(); i++) stfull->SetBinError(i,0.);
  for (int i=1; i<=stflux->GetNbinsX(); i++) stflux->SetBinError(i,0.);

  TCanvas *c2 = new TCanvas();
  thits->DrawNormalized("p");
  stfull->DrawNormalized("p same");
  stflux->DrawNormalized("p same");
  c2->Print("comp_vars.eps");

}

