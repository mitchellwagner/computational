void stack()
{
   TF1 fg("fg","gausn(0)",-35,35);
   fg.Draw();
   TF1 fl("fl","pol1(0)",-35,35);
   fl.SetParameters(2.66,0.,0.,0.,0.,0.,0.,0.,0.,0.);
   fg.SetParameters(100.,10.,5.);
   fl.SetLineColorAlpha(kBlue, 0.35);
   fg.SetTitle("Gaussian Centered at 10");
   fl.Draw("same");
}