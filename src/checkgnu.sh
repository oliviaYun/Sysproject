#!/bin/bash

string=`dpkg -l | grep gnuplot`

if [ $string ]; then
	echo "Have gnuplot"
else
	echo "No gnuplot"
	echo "Please Download and Install from http://gnuplot.info"
fi
