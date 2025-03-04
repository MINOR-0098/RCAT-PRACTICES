#!/bin/bash
count=0
for j in $(seq 1 10000);
do
	temp=$j
	temp2=0
	check=0
	len=0
	a=1

	while [ $temp -ne 0 ]; do
        	temp=$(($temp/10))
		len=$(($len+1))
	done
	temp=$j
	while [ $temp -ne 0 ]; do
        	temp2=$(($temp % 10))
        	temp=$(($temp/10))
        	a=1
        	for i in $(seq 1 $len);
        	do
                	a=$(($a*$temp2))
        	done
        	check=$(($check+$a))
	done
	if [ $check == $j ]; then
		count=$(($count+1)) 
	fi
done
echo "number of armstrong number is $count"
~    
