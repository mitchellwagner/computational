void save()
{
   TFile output("histogram.root","recreate");
   TH1F *h = new TH1F("h","",100,-5,5);
   h->FillRandom("gaus");
   h->Write(); // or output.Write();
   output.Close();
}

void load()
{
   TFile input("histogram.root");
   TH1F *h = (TH1F*) input.GetObjectChecked("h","TH1F");
   h->DrawCopy(); // h->Draw() won't work
   input.Close();
}
