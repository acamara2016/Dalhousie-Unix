#!/bin/bash
file=("$@")
size=$1
if (( $# == 1 )); then
	if echo "$size" | egrep -q '[0-9]*[0-9]$'; then
		find `pwd` -type f ! -name "compressing.sh" -size "+$1c" -exec gzip {} \;
	else
		echo "Usage :....."
	fi
elif (( $# != 1 )); then
	for (( i=2; i<=$#; i++ )); do
		if [[ -d ${file[i]} ]]; then
			echo ${file[i]}
			find ${file[i]} -type f ! -name "compressing.sh" -size "+$1c" -exec gzip {} \;
		elif [[ ! -d ${file[i]} ]]; then
			echo ${file[i]} is not a directory 
		fi
	done
fi
