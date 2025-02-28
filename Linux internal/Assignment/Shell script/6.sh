#!/bin/bash
num=0;
read -p "Enter a number " number
orignal=$number
while [ $number -gt 0 ]; do
	num=$(( $num * 10 + $number % 10 ))
	number=$(( $number/10 ))
done
if [ $num -eq $orignal ]; then
	echo "$orignal is palindrome"
else
	echo "$orignal is not palindrome"
fi
