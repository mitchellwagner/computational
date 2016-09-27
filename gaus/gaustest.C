void gaustest()
{
   TCanvas *can = new TCanvas;

   TF1 *fg = new TF1("fg","pol1+gausn(2)",2,8);
   fg->SetParameters(10000,1000,10004,5,0.4);
   fg->SetTitle();
   fg->GetXaxis()->SetTitle("Energy [keV]");
   fg->GetXaxis()->CenterTitle();
   fg->GetYaxis()->SetTitle("Entries/(0.1 keV)");
   fg->GetYaxis()->SetTitleOffset(1.3);
   fg->GetYaxis()->CenterTitle();
   fg->SetLineColor(kRed);
   fg->Draw();

   TF1 *fl = new TF1("fl","pol1",2,8);
   fl->SetParameters(10000,1000);
   fl->SetLineColorAlpha(kBlue, 0.35);
   fl->Draw("same");


   TLegend *le = new TLegend(0.2,0.8,0.45,0.95);
   le->AddEntry(fg,"signal","l");
   le->AddEntry(fl,"backgroung","l");
   le->Draw();

   can->Print("heap.png");
}