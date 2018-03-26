#!/bin/bash
#Matt Calayo mjc5gh averagetime.sh
read -p "Enter the exponent for counter.cpp: " iter

if [ "$iter" == "quit" ]
then
    exit 0
fi

av=0
sum=0
time=0
for((i=1;i<6;i++)); do
    echo "Running iteration $i ..."
    time=`./a.out $iter`
    echo "time taken: $time ms"
    sum=`expr $sum + $time`
done
echo "5 iterations took $total ms"
av=`expr $sum / 5`
echo "Average time was $av ms"
