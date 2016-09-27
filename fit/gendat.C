{
   TF1 *f = new TF1("f", "gaus+pol1(3)",0,10);
   f->SetParameters(2,5,0.8,3,0.2);
   TF1 *c = new TF1(*f);

   ofstream o("gen.dat");
   const int n=41;
   float x[n], y[n];
   for (int i=0; i<n; i++) {
      x[i]=i/4.;
      y[i]=gRandom->Gaus(f->Eval(x[i]),0.2);
      o<<x[i]<<" \t "<<y[i]<<endl;
   }
   o.close();

   TGraph *g = new TGraph(n,x,y);
   g->Draw("ap");

   g->Fit(c);
   f->SetLineColor(kRed);
   f->Draw("same");
}
