%title: ROOT Tree
%author: Jing Liu
%date: 2016-10-06

# Why Tree

Consider R approach for histogramming:

    dat <- read.table("oil.txt")
    hist(dat$dm, breaks=seq(2000,9000,400))

Problems for reading:

- What if the size of oil.txt is more than the size of memory?
- Why do we have to read in the whole table while all we want to do 
  is to create a histogram from one column of data?

Problems for saving:

- What if we want to save class objects instead of simple types?
- What if we want to save disk space as well? (txt VS binary)

-----------------------------------------------------

# TTree approach for reading

- a tree can have 1 or more branches
- a branch can have 1 or more leaves
- TLeaf: a column of a spreadsheet
- TBranch: a set of columns constantly used together
- a branch can be read from disk independently from other branches

-----------------------------------------------------

# TTree approach for saving

- many rows of data accumulating in a buffer (space in memory)
- they are compressed before written to disk when buffer is full
- structure of objects only needs to be saved once

-----------------------------------------------------

# TTree in ROOT users' guide

https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html

## examples

    cd $ROOTSYS/tutorials/tree/
    ls
    cp cern* basic* tree* ~/phys492/
    cd <Alt-.>

-----------------------------------------------------

# Create a tree

    nano cernbuild.C

Refer to users' guide to understand it. You basically need to

- create a tree after opening a TFile 
- create branches related to columns
- loop over rolls one by one and fill the tree
- write tree to file

A easier way to create a tree from a text file:

    nano basic2.C

_Notice the ReadFile function!_

-----------------------------------------------------

# Browse a tree

    $ root cernbuild.C # create&save tree in cernstaff.root
    ROOT [] .q
    $ root cernstaff.root
    ROOT [] .ls // show tree name
    ROOT [] T->Show(0) // show all collumns in first row
    ROOT [] T->Print() // show info of tree
    ROOT [] T->Scan("Cost:Age:Children") // show 3 collumn
    ROOT [] T->StartViewer() // check users' guide for usage
    ROOT [] TBrowser a // double click a leaf to draw it

-----------------------------------------------------

# Draw histograms

    $ root basic2.C # convert basic.dat to a tree
    ROOT [] .ls // list things in memory
    ROOT [] ntuple->Draw("y:x","","colz") // THistPainter
    ROOT [] ntuple->Draw("z:y","abs(x)<0.1") // apply cut
    ROOT [] ntuple->Draw("x>>hx(40,-4,4)") // save histogram
    ROOT [] hx->Draw("e") // now you can use histogram
    ROOT [] hx->Fit("gaus") // even for fitting
