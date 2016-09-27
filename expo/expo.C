void expo()
{
   TCanvas *can = new TCanvas; 


   
  TF1 *fe = new TF1("fe","pol1+expo(2)",0,20);
//  We call the pol1 function first which has two parameters followed by expo which also 
//  has two. In the set parameters function we need to set parameters for the pol1 function first followed by those for expo. 
  fe->SetParameters(100000,0,10,-.5); 
  fe->SetTitle(); 
  fe->GetXaxis()->SetTitle("x"); 
  fe->GetXaxis()->CenterTitle(); 
  fe->GetYaxis()->SetTitle("F(x)"); 
  fe->GetYaxis()->CenterTitle(); 
  fe->GetYaxis()->SetTitleOffset(1.3); 
  fe->SetLineColor(kRed);
  fe->Draw();

  TF1 *fl = new TF1("fl","pol1",0,20);
  fl->SetParameters(100000,0);
  fl->SetLineColor(kBlue);
  fl->Draw("same");

  TLegend *le = new TLegend(0.2,0.8,0.45,0.95); 
  le->AddEntry(fe,"f(x)=2^-x","l");
  le->AddEntry(fl,"limit","l");
  le->Draw(); 

   can->Print("expo.png"); 
}
