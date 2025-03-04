#!/bin/bash
read -p "ENTER a character " char

case "$char" in
	[aeiouAEIOU])
		echo "'$char' is vovel"
		;;
	[a-zA-Z])
		echo "'$char is consonant"
		;;
	*)
		echo "Invalid input"
		exit 1
		;;
esac

