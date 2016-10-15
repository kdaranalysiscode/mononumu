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
#include <fstream>
#include "TH2F.h"
#include "TMarker.h"
#include "TPoint.h"
#include "TStyle.h"
#include "TLine.h"
#include "TLatex.h"
#include "TGaxis.h"

using namespace std;

void read(){

   FILE *fp = fopen("all_data_numi_runs_4_7.dat","r");

   int lines_to_skip = 1;
  
   TGraph *tstamp_vs_batches = new TGraph();
   TGraph *nsec_vs_batches = new TGraph();
  
   int yr = 0;
   int mo = 0;
   int dy = 0;
   int hr = 0;
   int mn = 0;
   int sc = 0;
   char prec[10];
   long int unix = 0;
   unsigned int nsec = 0;
   int rp = 0;
   float trt = 0.;
   int gd = 0;
   unsigned int fail = 0;
   float hn_cur = 0;
   int n_batch = 0;
   int n_total = 0;
   float intens[6];
   for (int i=0; i<6; i++) intens[i] = 0.;

   int ctr_0 = 0;
   int ctr_1 = 0;
   int ctr_2 = 0;
   int ctr_3 = 0;
   int ctr_4 = 0;
   int ctr_5 = 0;
   int ctr_6 = 0;   

   int fscfRet = 0;
   char buffer[100];
   int ctr = 0;
   
   int prev_tstamp = 0;
   
   TH1F *batch_hist = new TH1F("batch_hist","",7,0,7);
   TH1I *time_bet_spills = new TH1I("time_bet_spills","",10,0,10);
   
   ofstream myfile;
   myfile.open ("tstamp_batches_nsec.txt");
  
   while (!feof (fp)){

     for (int i=0; i<lines_to_skip; i++) fgets(buffer, 100, fp);
     
     ctr += 1;
     fscfRet = fscanf(fp,"%d-%d-%d %d:%d:%d.%s %lu %u %d %f %d %x %f %d/%d %f %f %f %f %f %f",&yr,&mo,&dy,&hr,&mn,&sc,prec,&unix,&nsec,&rp,&trt,&gd,&fail,&hn_cur,&n_batch,&n_total,&intens[0],&intens[1],&intens[2],&intens[3],&intens[4],&intens[5]);
     //fscfRet = fscanf(fp,"%d-%d-%d %d:%d:%d %lu %lu",&yr,&mo,&dy,&hr,&mn,&sc,&prec,&unix);
     
     //cout<<" yr "<<yr<<" mo "<<mo<<" dy "<<dy<<" hr "<<hr<<" mn "<<mn<<" sc "<<sc;
     //cout<<" prec "<<prec<<" unix "<<unix<<" nsec "<<nsec<<" rp "<<rp<<" trt "<<trt;
     //cout<<" gd "<<gd<<" fail "<<fail<<" hn_cur "<<hn_cur<<" n_batch "<<n_batch<<" n_total "<<n_total<<" int0 "<<intens[0]<<" int1 "<<intens[1]<<" int2 "<<intens[2]<<" int3 "<<intens[3]<<" int4 "<<intens[4]<<" int5 "<<intens[5]<<endl;;

     if (ctr%5000==0) cout<<" timestamp "<<unix<<" n_batches "<<n_batch<<" count "<<ctr<<endl;

     //if (nsec>5e8) unix += 1;

     tstamp_vs_batches->SetPoint(tstamp_vs_batches->GetN(),unix,n_batch);
     nsec_vs_batches->SetPoint(nsec_vs_batches->GetN(),nsec,n_batch);

     batch_hist->Fill(n_batch);

     if (n_batch==0) ctr_0 += 1;
     if (n_batch==1) ctr_1 += 1;
     if (n_batch==2) ctr_2 += 1;
     if (n_batch==3) ctr_3 += 1;
     if (n_batch==4) ctr_4 += 1;
     if (n_batch==5) ctr_5 += 1;
     if (n_batch==6) ctr_6 += 1;

     if (n_batch>0) time_bet_spills->Fill(unix - prev_tstamp);

     prev_tstamp = unix;

     myfile << unix;
     myfile << "\t";
     myfile << n_batch;
     myfile << "\t";
     myfile << nsec;
     myfile << "\n";

     //tree->Fill();

   }
   
   //tstamp_vs_batches->Draw("ap");
  
  //tstamp_vs_batches->SetMarkerStyle(20);
  tstamp_vs_batches->SetTitle(";time; no batches");
  tstamp_vs_batches->GetXaxis()->SetTimeDisplay(1);
  tstamp_vs_batches->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%Y} %F 1970-01-01 00:00:00");
  tstamp_vs_batches->GetXaxis()->SetLabelOffset(0.015);
  tstamp_vs_batches->GetXaxis()->SetTitleOffset(1.5);
  tstamp_vs_batches->GetXaxis()->SetLimits(1254070000,1316200000); 
   
  TFile writeFile("n_batches.root","RECREATE");
  tstamp_vs_batches->Write("tstamp_vs_batches");
  batch_hist->Write("batch_hist");
  writeFile.Close();
  
  cout<<"test pt should be 5: "<<tstamp_vs_batches->Eval(1260893371)<<endl;
  cout<<"test pt should be 0: "<<tstamp_vs_batches->Eval(1316071370)<<endl;
  cout<<"test pt should be 6: "<<tstamp_vs_batches->Eval(1293865045)<<endl;

  cout<<" counters: 0,1,2,3,4,5,6 "<<ctr_0<<","<<ctr_1<<","<<ctr_2<<","<<ctr_3<<","<<ctr_4<<","<<ctr_4<<","<<ctr_5<<","<<ctr_6<<endl;
  
  TCanvas *batchC = new TCanvas();
  tstamp_vs_batches->Draw("ap");
  batchC->Print("tstamp_vs_batches.png");

  time_bet_spills->SetTitle("numi acc; time between spills (sec)");

  TCanvas *euiop = new TCanvas();
  time_bet_spills->Draw();
  euiop->Print("numi_acc_time_bet_spills.eps");

}

