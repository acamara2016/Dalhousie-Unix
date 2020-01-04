#!/bin/bash
for (( i=1; i<=4; ++i )) do
	echo $`echo ${i}`	
done
for arg in $@
do
	echo "$arg"
done

