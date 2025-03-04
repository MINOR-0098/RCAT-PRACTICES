#!/bin/bash

read -p "Enter the file name " file

if [ -e "$file" ]; then
  echo "'$file' exists."
else
  echo "'$file' does not exist."
fi
