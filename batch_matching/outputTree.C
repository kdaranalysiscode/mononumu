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

using namespace std;

void outputTree::Loop()
{

int success_ctr = 0;
int total_ctr = 0;
int det_tstamp = 0;
int leap_sec_offset = 15;
int n_batches = 0;

TGraph *tstamp_vs_batches = new TGraph("tstamp_batches_nsec.txt","%lf %lf");

//Create a new file + a clone of old tree in new file
TFile *newfile = new TFile("numi_data_five_batches_early_all_batches_late.root","recreate");
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
        }

        det_tstamp = 0;
        det_tstamp = myHeader_Secs[0];

        for (int i=0; i<tstamp_vs_batches->GetN(); i++){
        
          if (det_tstamp == tstamp_vs_batches->GetX()[i] + leap_sec_offset){ 
            success_ctr += 1;
            cout<<" match! event timestamp "<<det_tstamp<<" spill timestamp "<<(int)tstamp_vs_batches->GetX()[i]<<" pt number "<<i<<" jentry "<<jentry<<endl;
            
            n_batches = 0;
            n_batches = tstamp_vs_batches->GetY()[i];
            
          }
        
        }
        
        total_ctr += 1;
  
        cout<<" success counter "<<success_ctr<<" total counter "<<total_ctr<<" ratio "<<(float)success_ctr/total_ctr<<" detector time "<<det_tstamp<<" n_batches "<<n_batches<<endl;

         //if (n_batches==6) cout<<" outside n_batches "<<n_batches<<" time "<<mysplitEvent_aveTimeTank[0]<<endl;

         if ((n_batches==5&&mysplitEvent_aveTimeTank[0]<6000) || (mysplitEvent_aveTimeTank[0]>6000)){
           //if (n_batches==6) cout<<" n_batches "<<n_batches<<" time "<<mysplitEvent_aveTimeTank[0]<<endl;
           newtree->Fill();
         }

   }//jentry loop

newtree->Print();
newtree->AutoSave();
delete newfile;

}
