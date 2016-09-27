f1(x) = a1*tanh(x/b1) # define the function to be fit
a1 = 300; b1 = 0.005; # initial guess for a1 and b1
fit f1(x) 'force.dat' using 1:2 via a1, b1

f2(x) = a2 * tanh(x/b2)
a2 = 300; b2 = 0.005;
fit f2(x) 'force.dat' using 1:3 via a2, b2

set key 0.018,150 title "F(x) = A tanh (x/B)"      # title to key!
set title "Force Deflection Data \n and curve fit" # note newline!
set xlabel 'Deflection, {/Symbol D}_x (m)'         # Greek symbols!
set ylabel 'Force, {/Times-Italic F}_A, (kN)'      # italics!
set xr [0.0:0.022] # autoscale not as smart as the one in ROOT
set yr [0:325]
set pointsize 1.5
set label "Yield Point" at 0.003,260
set arrow from 0.0028,250 to 0.003,280

plot    "force.dat" using 1:2 title 'Column data' with points 3, \
	  "force.dat" using 1:3 title 'Beam data'   with points 4, \
	  a1 * tanh( x / b1 ) title 'Column-fit: A=309, B=0.00227', \
	  a2 * tanh( x / b2 ) title 'Beam-fit: A=260, B=0.00415'

set size 1.0, 0.6
set terminal postscript portrait enhanced mono dashed lw 1 "Helvetica" 14 
set output "force.ps"
replot
