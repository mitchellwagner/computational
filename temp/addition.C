{
   TCanvas *can = new TCanvas;
   can->Divide(2,2);

   can->cd(1);
   TF1 *fGaus = new TF1("fGaus","exp(-0.5*((x-50)/10)**2)",0,100);
   TH1F *hGaus = new TH1F("hGaus",";Energy [keV];",100,0,100);
   hGaus->FillRandom("fGaus", 1000);
   TH1F *hGC = hGaus->DrawCopy();

   can->cd(2);
   TF1 *fPol0 = new TF1("fPol0","1",0,100);
   TH1F *hPol0 = new TH1F("hPol0",";Energy [keV];",100,0,100);
   hPol0->FillRandom("fPol0", 10000);
   TH1F *hPC = hPol0->DrawCopy();

   can->cd(3);
   hGaus->Add(hPol0);
   hGaus->Draw("e");

   can->cd(4);
   hGC->Sumw2();
   hPC->Sumw2();
   hGC->Add(hPC);
   hGC->Draw("e");
}
