// C file that builds a tree from Jing's oil.txt
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TCanvas.h"

void oil(){

// declare variables from our dat file
  Char_t     date[11];
  Int_t      dd;
  Int_t      milage;
  Int_t      dm;
  Float_t    daily;

// create the root file  
  TFile *f = new TFile("oil.root","RECREATE");

//open text file  
  FILE *fp = fopen("oil.txt","r");
  
  TTree *tree = new TTree("T","Jing's Oil data");
  tree->Branch("date",&date,"date/C");
  tree->Branch("dd",&dd,"dd/I");
  tree->Branch("milage",&milage,"milage/I");
  tree->Branch("dm",&dm,"dm/I");
  tree->Branch("daily",&daily,"daily/F");

//Scan the text file and save it to the tree leaves
  char line[40];
  while (fgets(&line,40,fp)) {
    sscanf(&line[0], "%s %d %d %d %g",&date,&dd,&milage,&dm,&daily);
    tree->Fill();
  }

  tree->Print();
  tree->Write();

//fclose(fp);

  TCanvas *c1 = new TCanvas("c1","Oil Data",10,10,1000,750); 
  c1->SetFillColor(17);
  c1->Divide(1,2);
  
//create histogram

  TH1F *hdm  = new TH1F("hdm","dm distribution",10,0,8500);

//read all entries and fill the histograms
  Int_t nentries = (Int_t)T->GetEntries();
  for (Int_t i=0; i<nentries; i++) {
      T->GetEntry(i);
      hdm->Fill(dm);

   }
   
   c1->cd(1);
   hdm->Draw("e"); 
   hdm->Fit("gaus");
   
   c1->cd(2);
   
   T->Draw("dd:dm:daily","daily<100","colz");

   hdm->Write();
}

