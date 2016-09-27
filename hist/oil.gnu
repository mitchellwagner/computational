#!/usr/bin/gnuplot -persist
set size 1, 1
set terminal pdfcairo font "Times, 32" size 10,6 
set output 'oil.pdf'

set title "" offset 0.000000,0.000000  font ""
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1

set ylabel "mileage increased [miles]" offset 0.000000,0.000000  font ""
set xlabel "time increased [days]" offset 0.000000,0.000000  font ""
plot "oil.txt" every ::1 using 2:4 notitle

set ylabel "mileage [1,000 mile]" offset 0.000000,0.000000  font ""
set xlabel "" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set xdata time
set timefmt "%Y-%m-%d"
set format x "%Y\n%m/%d"
plot "oil.txt" every ::1 using 1:($3/1000) notitle with line

set output # important! close output file
