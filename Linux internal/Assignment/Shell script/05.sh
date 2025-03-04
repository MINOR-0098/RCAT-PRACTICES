#!/bin/bash

read -p "Enter first number " num1
read -p "Enter operator(+,-,*,/) " op
read -p "Enter second number " num2

result=$(echo "$num1 $op $num2" | bc -l )
echo "$result"
