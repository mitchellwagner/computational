{
   TH1F *hCo60 = new TH1F("hCo60",";Energy [keV];Number of entries",2000,0,2000);

   float energy;
   ifstream input("Co60.txt");
   while(input>>energy) { hCo60->Fill(energy); }
   input.close();

   //   hCo60->Draw();

   //   TCanvas *can = new TCanvas;
   //   can->Divide(1,2);


   //   hCo60->Draw();
   //   can->cd(1);
   TH1F *h200 = hCo60->Rebin(10,"h200");
   //   h200->Draw();
   
   //   can->cd(2);
   TH1F *h80 = hCo60->Rebin(25,"h80");
   //   h80->Draw();

   //   can->cd(4);
   //   TH1F *h10 = hCo60->Rebin(200,"h10");
   //   h10->Draw();


     
   //   TCanvas *c1 = new TCanvas;
   //   c1->Divide(2,2);

   //   h200->Draw("e"); 
   //   h200->Draw("e0"); //   c1->cd(2);
   //   c1->cd(3); h200->Draw("e1");
   //   c1->cd(1);  h200->Draw("e1hist"); //   c1->cd(4);

 
   TCanvas *c2 = new TCanvas;
   c2->Divide(1,2);

   c2->cd(1);
   cout<<"# of entries in bin 50: "<<h200->GetBinContent(50)
      <<" +- "<<h200->GetBinError(50)<<endl;
   TH1F *hOrigin = h200->DrawCopy("e1hist");

   //   c2->cd(2);
   //   h200->Scale(1./24./60./3600.);
   //   h200->GetYaxis()->SetTitle("Rate [Hz]");
   //   cout<<"# of entries in bin 50: "<<h200->GetBinContent(50)
   //      <<" +- "<<h200->GetBinError(50)<<endl;
   //   h200->DrawCopy("e");

   //   c2->cd(3);
   //   h200->GetYaxis()->SetRangeUser(0,8e-5);
   //   h200->Draw("e");

   c2->cd(2);
   TH1F *hCopy = hOrigin->DrawCopy("e1hist");
   hCopy->Sumw2();
   hCopy->Scale(1./24./60./3600.);
   hCopy->GetYaxis()->SetTitle("Rate [Hz]");
   hCopy->Draw("e1hist");
   cout<<"# of entries in bin 50: "<<hCopy->GetBinContent(50)
      <<" +- "<<hCopy->GetBinError(50)<<endl;
}
