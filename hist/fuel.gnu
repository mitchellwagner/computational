#!/usr/bin/gnuplot -persist
set title "" offset 0.000000,0.000000  font ""
set xlabel "mileage [1,000 mile]" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set ylabel "efficiency [mile/gallon]" offset 0.000000,0.000000  font ""
set yrange [ 10 : 25 ] noreverse nowriteback
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1
set size 1, 1
set terminal pdfcairo font "Times, 32" size 10,6 
set output 'fuel.pdf'
plot "fuel.txt" every ::1 using ($2/1000):4 notitle with line

set title "" offset 0.000000,0.000000  font ""
set xlabel "" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set ylabel "efficiency [mile/gallon]" offset 0.000000,0.000000  font ""
set yrange [ 10 : 25 ] noreverse nowriteback
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1
set xdata time
set timefmt "%Y-%m-%d"
set format x "%Y\n%m/%d"
plot "fuel.txt" every ::1 using 1:4 notitle with line

set title "" offset 0.000000,0.000000  font ""
set xlabel "" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set ylabel "mileage [1,000 mile]" offset 0.000000,0.000000  font ""
set yrange [ * : * ] noreverse nowriteback
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1
plot "fuel.txt" every ::1 using 1:($2/1000) notitle with line

set title "" offset 0.000000,0.000000  font ""
set xlabel "" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set ylabel "unit price [$/Gallon]" offset 0.000000,0.000000  font ""
set yrange [ * : * ] noreverse nowriteback
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1
plot "fuel.txt" every ::1 using 1:5 notitle with line

set title "" offset 0.000000,0.000000  font ""
set xlabel "" offset 0.000000,0.000000  font ""
set xrange [ * : * ] noreverse nowriteback
set ylabel "total cost of fuel [$]" offset 0.000000,0.000000  font ""
set yrange [ * : * ] noreverse nowriteback
set lmargin -1
set bmargin -1
set rmargin -1
set tmargin -1
plot "fuel.txt" every ::1 using 1:7 notitle with line
set output # important! close output file
