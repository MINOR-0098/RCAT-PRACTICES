#!/bin/bash
pass="itworks?"
read -p "Enter the password " try
if [[ "$pass" == "$try" ]] ; then
	echo "Welcome"
else
	echo "wrong!!!"
fi
