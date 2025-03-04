#!/bin/bash
read -p "Enter a Number " orignal

armstrong() {

	local temp=$1
	local temp2=0
	local check=0
	local len=0
	local a=1
	while [ $temp -ne 0 ]; do
        	temp=$(($temp/10))
        	len=$(($len+1))
	done
	temp=$1
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
	if [ $check == $1 ]; then
        	echo "$1 is armstrong"
	else
        	echo "$1 is not armstrong"
	fi
}
armstrong $orignal
