#!/bin/bash
count=0
for i in $(seq 1 10000); 
do

	num=0;
	orignal=$i
	j=$i
	while [ $j -gt 0 ]; do
        	num=$(( $num * 10 + $j % 10 ))
        	j=$(( $j/10 ))
	done
	if [ $num -eq $i ]; then
		count=$(($count+1))
	fi
done
echo "no of palindrome is $count"
