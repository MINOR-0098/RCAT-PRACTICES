#!/bin/bash
read -p "Enter size of your array: " size
arr=()
for (( i=0 ; i<size ; i++ ));
do
        read -p "Enter a element: " temp
        arr+=("$temp")
done

echo "Your array is: ${arr[@]} "

for ((i=0; i<size-1; i++)); do
    for ((j=0; j<size-i-1; j++)); do
      if [[ "${arr[j]}" -gt "${arr[j+1]}" ]]; then
        temp1="${arr[j]}"
        arr[j]="${arr[j+1]}"
        arr[j+1]="$temp1"
      fi
    done
done

echo "Smallest is: ${arr[0]}"                     
