%title: Recap & discussion
%author: Jing LIU
%date: 2016-10-13

# Create a tree

## universal method

    TTree *t = new TTree("t", "my data");
    double energy; int nhits;
    t->Branch("e", &energy, "e/D");
    t->Branch("n", &nhits, "n/I");
    ifstream in("data.txt");
    while(in>>energy>>nhits) t->Fill();
    in.close();

## quick but limited method

    TTree *t = new TTree("t", "my data");
    t->ReadFile("data.txt","e/D:n/I");
