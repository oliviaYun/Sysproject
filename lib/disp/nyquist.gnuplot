set term png
set output 'nyquist.png'
set title "Nyquist graph"
set xlabel "real"
set ylabel "imaginary"
set autoscale
set label "Nyquist pont" at -1,0
plot filename using 1:2 with lines


