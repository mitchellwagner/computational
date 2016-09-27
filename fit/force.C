{
   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadTopMargin(0.1);
   gStyle->SetOptFit(0);

   TCanvas *can = new TCanvas("can","can",555,483);

   TGraph *column = new TGraph("gen.dat");
   column->SetTitle("Gaussian with background");
   column->GetXaxis()->CenterTitle();
   column->GetYaxis()->CenterTitle();
   column->GetXaxis()->SetNdivisions(505);
   column->SetMarkerSize(1.5);
   column->Draw("a*");

   TGraph *beam = new TGraph("gen.dat","%lg %lg");
   beam->SetMarkerStyle(kOpenSquare);
   beam->SetMarkerSize(1.5);
   beam->Draw("p");

   TF1 *fc = new TF1("fc","[3]+[4]*x+gaus(0)",0.,10.);
   fc->SetParameters(2.2,5,0.6,3.1,0.2);
   fc->SetLineStyle(kDashed);
   column->Fit(fc);
   double p0 = fc->GetParameter(0);
   double p1 = fc->GetParameter(1);

   TLegend *leg = new TLegend(0.3,0.2,0.96,0.5);
   leg->SetHeader("F(x) = A+B*x+gaus(0)");
   leg->AddEntry(column, "Column data", "p");
   leg->AddEntry(fc, Form("Column-fit:A=%.0f,B=%.5f",p0,p1), "l");
   leg->Draw();

   float xmax = column->GetXaxis()->GetXmax();
   float ymax = column->GetYaxis()->GetXmax();
   TGaxis *right = new TGaxis(xmax,0,xmax,ymax,0,300,506,"+U");
   right->Draw();
   TGaxis *top = new TGaxis(0,ymax,xmax,ymax,0,0.022,505,"-U");
   top->Draw();

   can->Print("gen.eps");
}
