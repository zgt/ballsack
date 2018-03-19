#!/bin/bash
#Matt Calayo mjc5gh averagetime.sh
read -p "Dictionary:" dict #reads in user input for name of dictionary file
read -p "Grid:" grid #reads in user input for name of grid file
r1=`./a.out $dict $grid | tail -1` #assigns variable r1 to the last line of output of a.out run with the dict and grid variables
r2=`./a.out $dict $grid | tail -1`
average=`expr "$r1" + "$r2"` #adds r1 and r2
r3=`./a.out $dict $grid | tail -1`
average2=`expr "$average" + "$r3"`
r4=`./a.out $dict $grid | tail -1`
average3=`expr "$average2" + "$r4"`
r5=`./a.out $dict $grid | tail -1`
average4=`expr "$average3" + "$r5"` #sum of all the runtimes
five=5
result=`expr "$average4" / "$five"` #divides the sum by five
echo $result #prints the result
