// C file that builds a tree from Jing's oil.txt

void oil3(){

// declare variables from our dat file
  Char_t     date[11];
  Int_t      dd;
  Int_t      milage;
  Int_t      dm;
  Float_t    daily;

// create the root file  
  TFile *f = new TFile("oil3.root","RECREATE");

  TTree *tree = new TTree("T","Jing's Oil data");
  tree->Branch("date",&date,"date/C");
  tree->Branch("dd",&dd,"dd/I");
  tree->Branch("milage",&milage,"milage/I");
  tree->Branch("dm",&dm,"dm/I");
  tree->Branch("daily",&daily,"daily/F");

  tree->ReadFile("oil.txt","date[11]/C:dd/I:milage/I:dm/I:daily/F");

  tree->Print();
  tree->Write();

  TCanvas *c1 = new TCanvas("c1","Oil Data",10,10,1000,750); 
  c1->SetFillColor(17);
  c1->Divide(2,2);
  
//create histogram

T->Draw("dm>>hdm(10,0,8500)","","goff");

   c1->cd(1);
   hdm->DrawCopy();
   
   c1->cd(2);
   hdm->Draw("e"); 
   hdm->Fit("gaus");
   hdm->Write();
   
   c1->cd(3);
   T->Draw("dd:dm","daily<100","colz");


}

