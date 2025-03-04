#!/bin/bash
read -p "Enter a Number " orignal
temp=$orignal
temp2=0
check=0
len=0
a=1
while [ $temp -ne 0 ]; do
	temp=$(($temp/10))
	len=$(($len+1))
done
temp=$orignal
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
if [ $check == $orignal ]; then
	echo "$orignal is armstrong"
else
	echo "$orignal is not armstrong"
fi
