# Sysproject

Project of Embedded Software Enginnering, 2015 fall, Dept of Embdded Systems Engineering, Incheon National University

A system for the testing system stability using some tools

    Support Nyquist and Bode plot.

    Support Plant's OL Response, Plant's CL Response, Plant + Controller's OL Response, CL Response

Also For User, Output Plot(png), Data(dat)


## Requirement
If you use this program you must have gnuplot

Download Gnuplot from Official Website

http://www.gnuplot.info


    tar xzvf gnuplot-4.6.1.tar.gz
    
    cd gnuplot-4.6.1
    
    ./configure
    
    make
    
    make check
    
    make install


## Install
    $git clone https://github.com/oliviaYun/Sysproject.git

    $make

    $./Graph

## Author
    Lee Minho
    
      Calculate Complex Number, Close Loop, Open Loop, Plant, Controller ..
      
      minhoo3@naver.com
      
    Olivia Yun
    
      Linkage Gnuplot to C, GTK, Console UI, Algorithm intergration, Bug Fix ..
      
      ab8795@naver.com
