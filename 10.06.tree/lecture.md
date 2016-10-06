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

-----------------------------------------------------

# Browse a tree


    $ root cernstaff.root
    ROOT [] .ls
    ROOT [] T->Show(1)
    ROOT [] T->Print()
    ROOT [] T->Scan("Cost:Age:Children")
    ROOT [] T->StartViewer()
    
