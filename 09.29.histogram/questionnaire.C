{
   TCanvas *can = new TCanvas;
   can->Divide(2,2);

   TGraph *gcl = new TGraph("questionnaire.txt");

   TGraph *ghw = new TGraph("questionnaire.txt","%*lg %*lg %lg %lg");

   TH1I *hhh = new TH1I("hhh",";hardness of homework", 6, 0, 6);
   
   int n = ghw->GetN();
   for (int i=0; i<n; i++) {
      hhh->Fill(ghw->GetX()[i]);
   }
   can->cd(1);
   hhh->Draw();

   TH1I *hth = new TH1I("hth",";time for homework", 6, 0, 6);
   
   int n = ghw->GetN();
   for (int i=0; i<n; i++) {
      hth->Fill(ghw->GetY()[i]);
   }
   can->cd(2);
   hth->Draw();

   TH1I *hhard = new TH1I("hhard",";hardness of class", 6, 0, 6);
   
   int n = gcl->GetN();
   for (int i=0; i<n; i++) {
      hhard->Fill(gcl->GetX()[i]);
   }
   can->cd(3);
   hhard->Draw();

   TH1I *hspeed = new TH1I("hspeed",";speed of class", 6, 0, 6);
   
   int n = gcl->GetN();
   for (int i=0; i<n; i++) {
      hspeed->Fill(gcl->GetY()[i]);
   }
   can->cd(4);
   hspeed->Draw();
}
