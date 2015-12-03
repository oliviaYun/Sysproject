set term png
set output 'bodeplot-mag.png'
set title "bodeplot-magnitude"
set xlabel "w"
set ylabel "magnitude"
set autoscale
set logscale x
plot filename using 1:2 with lines

