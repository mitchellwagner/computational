void oil(){
	TCanvas *can = new TCanvas("can","can",555,483);
	
	TH1F *oil = new TH1F("oil2.txt","%*lg %*lg %*lg %lg",20,0,200);
       	oil->Fill();
	oil->SetTitle("Daily Mileage");
	oil->Draw();

	return can;
}
