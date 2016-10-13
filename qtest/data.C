void data(){

// declare variables from our dat file
  Float_t    energy;
  Float_t    x;
  Float_t    y;
  Float_t    z;
// create the root file  
  TFile *f = new TFile("data.root","RECREATE");

  TTree *tree = new TTree("T","Energy Data");
  tree->Branch("energy",&energy,"energy/F");
  tree->Branch("x",&x,"x/F");
  tree->Branch("y",&y,"y/F");
  tree->Branch("z",&z,"z/F");


  tree->ReadFile("data.txt");

  tree->Print();
  tree->Write();
  
  TCanvas *c1 = new TCanvas("c1","Energy Spectrum",100,10,1000,750); 
  c1->Divide(2,2);
  
//create histogram

  T->Draw("energy>>henergy(50,620,700)","","goff");
  T->Draw("energy>>hspectrum(200,0,1500)","","goff");

  
  c1->cd(1);
  gPad->SetLogy();
  hspectrum->GetXaxis()->SetTitle("Energy [keV]");
  hspectrum->GetYaxis()->SetTitle("Events");
  hspectrum->GetXaxis()->CenterTitle();
  hspectrum->GetYaxis()->CenterTitle();
  hspectrum->Draw();

  c1->cd(2);
  TH1F *hCopy = henergy->DrawCopy("e1");
  hCopy->Sumw2();
  hCopy->Scale(1./24./60./3600.);
  hCopy->GetYaxis()->SetTitle("Rate [Hz]");

   
  TF1 *fc = new TF1("fc","[3]+gaus(0)",620,700);
  fc->SetParameters(.000000027.,657.,8.,1.);
  fc->SetLineColor(kBlue);
  hCopy->Fit("fc");
  hCopy->Draw();
   
  henergy->Write();  
  
  c1->cd(3);
  T->Draw("y:x","","colz");

}

