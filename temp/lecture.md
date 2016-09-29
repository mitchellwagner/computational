%title: Histogram continued
%author: Jing Liu
%date: 2016-09-29

# Number of bins

- too few bins 
  - loss information
- too many bins
  - hide information
  - increase statistic error

## two ways to rebin a histogram

1. Canvas menu "View"
  - Editor
  - select the histogram by mouse
  - click "Binning" tab in the editor
2. Using C++ code:

    histogram->Rebin(10); // combine 10 bins to 1

*NOTE*: One can only reduce number of bins, not the other way around!

--------------------------------------------------

# Exercise

    $ cd ~/phys492
    $ cp ~Jing.Liu/phys492/09.29.histogram/Co60.txt .
    $ nano Co60.C

    {
       TH1F *hCo60 = new TH1F("hCo60",";Energy [keV];Number of entries",2000,0,2000);
       float energy;
       ifstream input("Co60.txt");
       while(input>>energy) { hCo60->Fill(energy); }
       input.close();
       hCo60->Draw();
    }

Try to use Editor to rebin the histogram and observe the changes

--------------------------------------------------

# Exercise

Add the following to Co60.C:

    TCanvas *can = new TCanvas;
    can->Divide(2,2);

    can->cd(2);
    TH1F *h200 = hCo60->Rebin(10,"h200");
    h200->Draw();

    can->cd(3);
    TH1F *h80 = hCo60->Rebin(25,"h80");
    h80->Draw();

    can->cd(4);
    TH1F *h10 = hCo60->Rebin(200,"h10");
    h10->Draw();

https://root.cern.ch/doc/master/classTH1.html#aff6520fdae026334bf34fa1800946790

--------------------------------------------------

# Error bar

## Binomial distribution

https://en.wikipedia.org/wiki/Binomial_distribution

> the binomial distribution with parameters n and p is the discrete probability
> distribution of the number of successes in a sequence of n independent yes/no
> experiments, each of which yields success with probability p.

In case of a histogram with *n* total entries and *ni* entries in bin i:

- p ~ ni/n
- variance = np(1-p) ~ n ni/n (1-ni/n) = ni/n (n-ni)

## Poisson approximation

> Poisson distribution with parameter λ = np can be used as an approximation to
> B(n, p) of the binomial distribution if n is sufficiently large and p is
> sufficiently small. According to two rules of thumb, this approximation is
> good if n ≥ 20 and p ≤ 0.05

- variance = sqrt(ni)
- relative variance = sqrt(ni)/ni = 1/sqrt(ni)
  - *when ni increases, relative uncertainty becomes small*

--------------------------------------------------

# Draw error bar

https://root.cern.ch/doc/master/classTH1.html#aa53a024a9e94d5ec91e3ef49e49563da

> Histograms are drawn via the THistPainter class.

https://root.cern.ch/doc/master/classTHistPainter.html#HP09

>Option                                     Description
>"E"    Default. Shows only the error bars, not a marker.
>"E1"   Small lines are drawn at the end of the error bars.
>"E0"   Draw also bins with null contents.

    histogram->Draw("e0"); // options are not case sensitive
    histogram->Draw("e1hist"); // draw both data points and histogram

--------------------------------------------------

# Get error value

https://root.cern.ch/doc/master/classTH1.html#aa53a024a9e94d5ec91e3ef49e49563da

> if the sum of squares of weights has been defined (via Sumw2), this function
> returns the sqrt(sum of w2). otherwise it returns the sqrt(contents) for this
> bin.

    histogram->GetBinError(49); // get error of bin 49

    histogram->GetBinContent(49); // get number of entries in bin 49

https://root.cern.ch/doc/master/classTH1.html#a59b44a2ba011024833124b93b4afbabf

## Convention for numbering bins

    TH1("name","title", nbins, xlow, xup);

- bin = 0; underflow bin
- bin = 1; first bin with low-edge xlow INCLUDED
- bin = nbins; last bin with upper-edge xup EXCLUDED
- bin = nbins+1; overflow bin

--------------------------------------------------

# Normalize a histogram

https://root.cern.ch/doc/master/classTH1.html#add929909dcb3745f6a52e9ae0860bfbd

    float live_time = 24*60*3600;
    histogram->Scale(1./live_time);
    histogram->GetYaxis()->SetTitle("Rate [Hz]");
    histogram->Draw("e"); // huge error bar!!! still sqrt(contents)

    histogram->Sumw2(); // save original error (sort of)
    histogram->Scale(1./live_time);
    histogram->Draw("e"); // error = orignal error / live_time

--------------------------------------------------

# Addition of histograms

    TH1F *hGaus = new TH1F("hGaus",";Energy [keV];",100,0,100);
    hGaus->FillRandom("exp(-0.5*((x-50)/10)**2)", 1000);

    TH1F *hPol0 = new TH1F("hPol0",";Energy [keV];",100,0,100);
    hPol0->FillRandom("pol0", 1000);

    hGaus->Add(hPol0);
    hGaus->Draw();


