void save()
{
   TFile output("hist10.root","recreate");
   TH1F *h1 = new TH1F("h1","",100,-5,5);
   h1->FillRandom("gaus");
   //   h1->Write(); // or output.Write();

   TH1F *h2 = new TH1F("h2","",100,-5,5);
   h2->FillRandom("gaus");
   //   h2->Write(); // or output.Write();

   TH1F *h3 = new TH1F("h3","",100,-5,5);
   h3->FillRandom("gaus");
   //   h3->Write(); // or output.Write();

   TH1F *h4 = new TH1F("h4","",100,-5,5);
   h4->FillRandom("gaus");
   //   h4->Write(); // or output.Write();

   TH1F *h5 = new TH1F("h5","",100,-5,5);
   h5->FillRandom("gaus");
   //   h5->Write(); // or output.Write();

   TH1F *h6 = new TH1F("h6","",100,-5,5);
   h6->FillRandom("gaus");
   //   h6->Write(); // or output.Write();
   
   TH1F *h7 = new TH1F("h7","",100,-5,5);
   h7->FillRandom("gaus");
   //   h7->Write(); // or output.Write();

   TH1F *h8 = new TH1F("h8","",100,-5,5);
   h8->FillRandom("gaus");
   //   h8->Write(); // or output.Write();

   TH1F *h9 = new TH1F("h9","",100,-5,5);
   h9->FillRandom("gaus");
   //   h9->Write(); // or output.Write();

   TH1F *h10 = new TH1F("h10","",100,-5,5);
   h10->FillRandom("gaus");
   //   h10->Write(); // or output.Write();

   output.Write();
   
   output.Close();
}

void load()
{
   TFile input("hist10.root");
   
   TH1F *h1 = (TH1F*) input.GetObjectChecked("h1","TH1F");
   h1->DrawCopy(); // h->Draw() won't work

   TH1F *h2 = (TH1F*) input.GetObjectChecked("h2","TH1F");
   h2->DrawCopy(); // h->Draw() won't work

   TH1F *h3 = (TH1F*) input.GetObjectChecked("h3","TH1F");
   h3->DrawCopy(); // h->Draw() won't work

   TH1F *h4 = (TH1F*) input.GetObjectChecked("h4","TH1F");
   h4->DrawCopy(); // h->Draw() won't work

   TH1F *h5 = (TH1F*) input.GetObjectChecked("h5","TH1F");
   h5->DrawCopy(); // h->Draw() won't work

   TH1F *h6 = (TH1F*) input.GetObjectChecked("h6","TH1F");
   h6->DrawCopy(); // h->Draw() won't work

   TH1F *h7 = (TH1F*) input.GetObjectChecked("h7","TH1F");
   h7->DrawCopy(); // h->Draw() won't work

   TH1F *h8 = (TH1F*) input.GetObjectChecked("h8","TH1F");
   h8->DrawCopy(); // h->Draw() won't work

   TH1F *h9 = (TH1F*) input.GetObjectChecked("h9","TH1F");
   h9->DrawCopy(); // h->Draw() won't work

   TH1F *h10 = (TH1F*) input.GetObjectChecked("h10","TH1F");
   h10->DrawCopy(); // h->Draw() won't work
   
   input.Close();
}

