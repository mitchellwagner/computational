// C file that builds a tree from Jing's oil.txt
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TCanvas.h"

void oil(){

  Char_t     date[11];
  Int_t      dd;
  Int_t      milage;
  Int_t      dm;
  Float_t    daily;

  
  TFile *f = new TFile("oil.root","RECREATE");

  FILE *fp = fopen("oil.dat","r");
  
  TTree *tree = new TTree("T","Jing's Oil data");
  tree->Branch("date",&date,"date/C");
  tree->Branch("dd",&dd,"dd/I");
  tree->Branch("milage",&milage,"milage/I");
  tree->Branch("dm",&dm,"dm/I");
  tree->Branch("daily",&daily,"daily/F");
  char line[40];
  while (fgets(&line,40,fp)) {
    sscanf(&line[0], "%s %d %d %d %g",&date,&dd,&milage,&dm,&daily);
    tree->Fill();
  }

  tree->Print();
  tree->Write();

  fclose(fp);

}

