void heap()
{
   TF1 *fg = new TF1("fg","gausn(0)",-35,35);
   TF1 *fl = new TF1("fl","pol1(0)",-35,35);
   fl->SetParameters(2.66,0.,0.,0.,0.,0.,0.,0.,0.,0.);
   fg->SetParameters(100.,10.,5.);
   fl->SetLineColorAlpha(kBlue, 0.35);
   fg->Draw();
   fg->SetTitle("Gaussian Centered at 10");
   fl->Draw("same");
}