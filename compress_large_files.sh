#!/bin/bash
#compressed_large_files.sh, Adama Camara (B00757321) (acamara) 
	if (( $# == 1 )); then	#if the user only add one command line argument
		if echo "$1" | egrep -q '[0-9]*[0-9]$'; then	#check if the size is a number
			find `pwd` -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;	#find file that have size>=sizeInputted ($1)
		else	#when size is not a number, print error message
			echo "USAGE: compress_large_files.sh size [dir ...]"
		fi
	
	elif (( $# != 1 )); then	#if the command line argument is more than one
		if (( $# == 2 )); then	#if there are 2 command line argument
			if [ -d $2 ]; then	#check if the second argument is a directory
				find $2 -type f ! -name "compress_large_files.sh" -size "+1c" -exec gzip {} \;	#find and gzip file 
			else 
				echo $2 is not a directory	#redirect error message
		fi 	fi
		if (( $# == 3)); then	#if there are 3 argument
			if [[ -d $2 && -d $3 ]]; then	#
				echo $2 and $3 are directory
				find $2 -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;
				find $3 -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;
			else
				echo $3 is not a directory
			fi
		fi
		if (( $# == 4 )); then	#if there are 4 arguments
			if [[ -d $2 && -d $3 && -d $4 ]]; then
				find $2 -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;
				find $3 -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;
				find $4 -type f ! -name "compress_large_files.sh" -size "+$1c" -exec gzip {} \;
			else
				echo $4 is not a directory
			fi
		fi 
	fi 
