#!/bin/bash
read -p "Enter number a " a
read -p "Enter number b " b

swap()
{
	c=$1
	d=$2
	echo "$d $c"
}
read a b <<< "$(echo "$a $b" | swap $a $b)"

echo "After swapping:"
echo "a: $a"
echo "b: $b"

	
