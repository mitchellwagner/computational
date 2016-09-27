int beam(){
    TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

    TGraph *gr1 = new TGraph("data2.txt","%lg %lg %*lg");
    gr1->SetLineColor(kRed);
    //   gr->SetMarkerColor(kBlue);
   
    TGraph *gr2 = new TGraph("data2.txt","%lg %*lg %lg");
    gr2->SetLineColor(kGreen);
    //   data2->SetMarkerColor(kGreen);

    TMultiGraph *mg = new TMultiGraph();
    mg->Add(gr1, "lp");
    mg->Add(gr2, "cp");
    mg->Draw("a");
    mg->GetXaxis()->SetTitle("Deflection");
    mg->GetXaxis()->CenterTitle();
    mg->GetYaxis()->CenterTitle();
    mg->GetYaxis()->SetTitle("Force");
    
    TLegend *le = new TLegend(0.6,0.85,0.8,0.95); 
    le->AddEntry(gr1,"Colum","l");
    le->AddEntry(gr2,"Beam","l");
    le->Draw();

    return c1;
}
