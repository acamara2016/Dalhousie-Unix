#!/bin/bash
#View.sh, Adama Camara (B00757321) (acamara)
for arg in $@	#a for loop that will go through the command line arguments
do
gunzip -c $arg>error.txt 2>/dev/null	#this line test if the current file is compressed or not, and redirect error to error.txt
num=$?	#assign the result of the previous command to num
if (( $num == 0 )); then	#if the file is compressed
	gunzip -c $arg		#decompress the file and display the content without deleting the .gz file
else	#if the file is not compressed
	cat $arg	#display the content of the non-compressed file
fi
done
