%title: ROOT IO
%author: Jing Liu
%date: 2016-10-04

# Standard way to save/load a histogram

    // save
    ofstream output("histogram.txt");
    for (int i=0; i<=h->GetNbinsX(); i++)
       output<<h->GetBinContent(i)<<endl;
    output.close();

    // load
    ifstream input("histogram.txt");
    int i=0; float content;
    while(input>>content) {
       h->SetBinContent(i,content);
       i++;
    }
    input.close();

-----------------------------------------------------

# Problems of the standard way

- loss information
  - titles of histogram
  - styles of histogram
- too much work to manually export every piece of information

## A preferred way

    ofstream output("histogram.dat");
    output<<h<<endl;
    output.close();

Unfortunately, `ofstream` does not provide such a nice thing

-----------------------------------------------------

# Why isn't it implemented in stanard C++?

*A reminder*: a `class` is a complicated `type`

- easy to allocate memory for simple types, easy to save them as well
- not so easy to do the same thing for a class
  - Hidden pointers
    - inheritance needs pointers to member functions
  - Explicit pointers
    - one can use `new` to create objects inside a class
  - pointers of derived classes with base class type
    - reflection: class can look back into itself
  - pointers are just memory addresses, not meant for disk storage

      Read C++ sub collection in zotero for background information

-----------------------------------------------------

# Persistence in C++

- A class object that can be saved to disk and loaded back to memory
  (memory <-> disk mapping) is called a *persistent* object.
- It is not implemented in the standard C++
- There are many third-party libraries to realize this.
- ROOT is one of them (lots of hidden work done by ROOT!)

-----------------------------------------------------

# The ROOT way

## Save

    TFile output("histogram.root","recreate");
    TH1F *h = new TH1F("h","",100,-5,5);
    h->FillRandom("gaus");
    h->Write();
    output.Close();

## Load

    TFile input("histogram.root");
    TH1F *h = (TH1F*) input.GetObjectChecked("h","TH1F");
    h->DrawCopy();
    input.Close();

-----------------------------------------------------

# The .root file

- compressed binary file (cannot be read in a text editor)
- contains class objects *(in disk instead of memory!)*
- contains directories (like file system instead of a normal file)
- contains version of class to read data saved in older format
- *highly optimized to access terabytes of data*
  - cannot be achieved in R or MATLAB 

-----------------------------------------------------

# Binary file and text file

- a text file is a binary file including only 
  - numbers (encoding) representing alphabets or characters
      - ASCII
      - UTF-8
  - new line codes: (LF, CR or their combination)
- anything more than that would be a binary file
  - it shows meaningless things in a text editor
- .root file is a binary file with complicated internal structure
  - it can only be read by ROOT

-----------------------------------------------------

# ROOT dictionary

https://root.cern.ch/root/Dictionary.html

- [full description of a class's member functions and data](https://root.cern.ch/doc/master/classTClass.html)
    - [reflection](https://root.cern.ch/root/htmldoc/guides/users-guide/AddingaClass.html)
- [created as C++ source codes and compiled into ROOT libraries](https://root.cern.ch/faq/how-generate-dictionary)

It is used for

- IO from/to a .root file
- context menus in ROOT GUI
- tab completion, Dump() in ROOT CLI

-----------------------------------------------------

# The .root file structure:

- physical structure: https://root.cern.ch/doc/master/classTDirectoryFile.html
- logical structure: https://root.cern.ch/doc/master/classTFile.html

# Terminology

- object: an object of a class in memory
- key: an object of a class in disk
    - cycle number: index of many objects of the same name in disk

-----------------------------------------------------

# Read objects of an old class definition

- structure of a class may evolve
  - add a data member
  - remove a data member
- objects of an old version of class need to be readable from disk

- for data members not existing any more
    - don't have to be read from disk any more
- for data members not existing before
    - need to be initialized with some default values

*Motivation* section of
https://root.cern.ch/root/htmldoc/guides/users-guide/AddingaClass.html

-----------------------------------------------------

# TFile constructor

    TFile (const char *fname, Option_t *option="",
           const char *ftitle="", Int_t compress=1)

[option:](https://root.cern.ch/doc/master/classTFile.html#aadd8e58e4d010c80b728bc909ac86760)
- _NEW_ or _CREATE_: Create a new file and open it for writing,
  - if the file already exists the file is not opened.
- _RECREATE_: Create a new file, if the file already exists it will be overwritten.
- _UPDATE_: Open an existing file for writing. If no file exists, it is created.
- _READ_: Open an existing file for reading (default).

compression:
- _0_: objects written to this file will not be compressed.
- _1_: minimal compression level but fast.
- ....
- _9_: maximal compression level but slower and might use more memory

-----------------------------------------------------

# gDirectory, .pwd and .ls

- memory & files managed by ROOT as file systems
  - it may contain directories and sub-directories
  - `gDirectory` holds pointer to the current directory

_Practice in ROOT:_

    .pwd // short cut for gDirectory->pwd()
    .ls // short cut for gDirectory->ls()
    TFile f("histogram.root");
    .pwd // current directory changed
    .ls // list name of object in disk that can be used
    h->Draw(); // directly use object listed above!

-----------------------------------------------------

# Objects in disk and in memory

    $ root histogram.root // automatically creates TFile
    root [0]
    Attaching file histogram.root as _file0...
    root [1] .ls // a short cut for _file0->ls()
    TFile**         histogram.root
     TFile*         histogram.root
      KEY: TH1F     h;1 <- object saved in disk
    root [2] h->Draw() // creates both histogram & canvas in memory!
    Info in <TCanvas::MakeDefCanvas>:  created default TCanvas with name c1
    root [3] .ls
    TFile**         histogram.root
     TFile*         histogram.root
      OBJ: TH1F     h        : 0 at: 0x1c8b7b40 (in memory!)
      KEY: TH1F     h;1 (in disk!)
    root [4] _file0->ls("-m") // list OBJ only
    root [5] _file0->ls("-d") // list KEY only

-----------------------------------------------------

# Objects automatically added to a directory

- histograms and trees (table of data in ROOT specific format)
- canvas is not one of them

    TFile output("histogram.root","recreate");
    TH1F *h = new TH1F("h","",100,-5,5);
    .ls // h should be listed already
    output.Write(); // useful if there are many histograms
    output.Close(); // delete all histograms in this directory

_This won't work! Why?_

    TH1F *h = new TH1F("h","",100,-5,5);
    TFile output("histogram.root","recreate");
    output.Write();
    output.Close();

-----------------------------------------------------

_This won't work! Why?_

   TFile input("histogram.root");
   TH1F *h = (TH1F*) input.GetObjectChecked("h","TH1F");
   h->Draw() // won't work! h->DrawCopy() works!
   input.Close();

`h->DrawCopy()` creates a copy of the original histogram 
that is not associated with any directory. 
It won't be deleted if the original file is closed.

-----------------------------------------------------

# Switch in between files

    TFile f1("histogram.root")
    .pwd
    TFile f2("h2.root","recreate")
    .pwd
    gROOT->GetListOfFiles()->ls()
    gDirectory->cd("histogram.root:/")
    .pwd
    TBrowser a // use GUI to facilitate the selection

-----------------------------------------------------

# Change directory of a histogram

    h->SetDirectory(0) // not associated with any directory
    h->SetDirectory(&f2) // associated with f2

or

    f2.cd() // swith directory
    h->Write() // save to current directory

-----------------------------------------------------

# Handling huge amount of data: TTree

https://root.cern.ch/trees-five-steps
