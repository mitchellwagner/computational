Int_t test(){
   TCanvas *c1 = new TCanvas("c1","Thicknes vs radius",700,500);
   c1->SetGrid();
   
   TMultiGraph *mg = new TMultiGraph();
   
   
   //Detector with 3kg mass 
   Double_t x3[100], y3[100];
   Int_t n3 = 21;
   Int_t v3 = 563.55;
   for (Int_t i=4;i<n3;i++) {
     x3[i] = i*0.5;
     y3[i] = v3/(TMath::Pi()*TMath::Power((x3[i]),2));
   }
   gr3 = new TGraph(n3,x3,y3);
   gr3->SetLineColor(kRed);
   gr3->SetLineWidth(3);
   mg->Add(gr3);
   

   //Detector with 2kg mass
   Double_t x2[100], y2[100];
   Int_t n2 = 21;
   Int_t v2 = 375.7;
   for (Int_t i=4;i<n2;i++) {
     x2[i] = i*0.5;
     y2[i] = v2/(TMath::Pi()*TMath::Power((x2[i]),2));
   }
   gr2 = new TGraph(n2,x2,y2);
   gr2->SetLineColor(kGreen);
   gr2->SetLineWidth(3);
   mg->Add(gr2);
   

   //Detector with 1kg mass
   Double_t x1[100], y1[100];
   Int_t n1 = 21;
   Int_t v1 = 187.85;
   for (Int_t i=4;i<n1;i++) {
     x1[i] = i*0.5;
     y1[i] = v1/(TMath::Pi()*TMath::Power((x1[i]),2));
   }
   gr1 = new TGraph(n1,x1,y1);
   gr1->SetLineColor(kBlue);
   gr1->SetLineWidth(3);
   mg->Add(gr1);
   
   mg->Draw("AL");
   mg->GetXaxis()->SetTitle("Radius (cm)");
   mg->GetYaxis()->SetTitle("Thickness (cm)");
   gPad->SetTitle("Cylindrical PC Detector h vs r");
   
   TLegend *le = new TLegend(0.2,0.8,0.45,0.95);
   le->AddEntry(gr3,"3 kg mass","l");
   le->AddEntry(gr2,"2 kg mass","l");
   le->AddEntry(gr1,"1 kg mass","l");
   le->Draw();

   
   
   return c1;
}
