{
   TChain *t = new TChain("t");
   t->Add("/home/Jing.Liu/data/nice/000000/run_000067.000001.root");

   NICE::WFs *wfs = new NICE::WFs;

   t->SetBranchAddress("evt",&wfs);

   ofstream o("Co60.txt");
   int n = t->GetEntries();
   for (int i=1; i<n; i++) {
      if (i%1000==0) cout<<i<<" events processed"<<endl;

      t->GetEntry(i);

      if (wfs->At(0)->GetPulse(0)->npe/5.5/20.6>180)
         o<<wfs->At(0)->GetPulse(0)->npe/5.5/20.8<<endl;
   }
   o.close();
}

