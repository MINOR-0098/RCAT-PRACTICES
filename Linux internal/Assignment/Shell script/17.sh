#!/bin/bash
read -p "Enter size of your array: " size
arr=()
for (( i=0 ; i<size ; i++ ));
do
        read -p "Enter a element: " temp
        arr+=("$temp")
done

echo "Your array is: ${arr[@]} "

read -p "Where to add a element " index
read -p "Enter the element " ele
arr1=()
for (( i=0 ; i<index ; i++ ));
do
	arr1+=("${arr[i]}")
done
arr1+=("$ele")
for (( i=$index ; i<size+1 ; 1++ ));
do
	arr1+=("${arr[i]}")
done
echo "New array is: ${arr1[@]}"                                 
