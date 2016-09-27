{
   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadTopMargin(0.1);
   gStyle->SetOptFit(0);

   TCanvas *can = new TCanvas("can","can",555,483);

   TGraph *column = new TGraph("force.txt");
   column->SetTitle("Force Deflection Data and curve fit;Delfection, #Delta_{x} (m);Force, #it{F}_{A}, (kN)");
   column->GetXaxis()->CenterTitle();
   column->GetYaxis()->CenterTitle();
   column->GetXaxis()->SetNdivisions(505);
   column->SetMarkerSize(1.5);
   column->Draw("a*");

   TGraph *beam = new TGraph("force.txt","%lg %*lg %lg");
   beam->SetMarkerStyle(kOpenSquare);
   beam->SetMarkerSize(1.5);
   beam->Draw("p");

   TF1 *fc = new TF1("fc","[0]*tanh(x/[1])",0,0.025);
   fc->SetParameters(300,0.02);
   fc->SetLineStyle(kDashed);
   column->Fit(fc);
   double p0 = fc->GetParameter(0);
   double p1 = fc->GetParameter(1);

   TF1 *fb = new TF1("fb","[0]*tanh(x/[1])",0,0.025);
   fb->SetParameters(300,0.02);
   fb->SetLineStyle(kDotted);
   beam->Fit(fb);
   double b0 = fb->GetParameter(0);
   double b1 = fb->GetParameter(1);

   TLegend *leg = new TLegend(0.3,0.2,0.96,0.5);
   leg->SetHeader("F(x) = A tanh (x/B)");
   leg->AddEntry(column, "Column data", "p");
   leg->AddEntry(beam, "Beam data", "p");
   leg->AddEntry(fc, Form("Column-fit:A=%.0f,B=%.5f",p0,p1), "l");
   leg->AddEntry(fb, Form("Beam-fit:A=%.0f,B=%.5f",b0,b1), "l");
   leg->Draw();

   TArrow *arrow = new TArrow(0.004, 270, 0.0032, 288, 0.02);
   arrow->Draw();

   TText *text = new TText(0.0043,260,"Yield Point");
   text->SetTextFont(22);
   text->SetTextSize(0.05);
   text->Draw();

   float xmax = column->GetXaxis()->GetXmax();
   float ymax = column->GetYaxis()->GetXmax();
   TGaxis *right = new TGaxis(xmax,0,xmax,ymax,0,300,506,"+U");
   right->Draw();
   TGaxis *top = new TGaxis(0,ymax,xmax,ymax,0,0.022,505,"-U");
   top->Draw();

   can->Print("force.eps");
}
