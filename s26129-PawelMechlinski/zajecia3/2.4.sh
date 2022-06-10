#!/bin/bash

PLIKI=$(find . -maxdepth 1 -type f)
echo "Wszystkie pliki: $PLIKI"

for i in $PLIKI; do
	tmp=${i:(-2)}

	if [[ "$tmp" == ".c" ]] 
	then
		arrayC=(${arrayC[@]} "$i")
	fi; done

# echo "${arrayC[@]}"

for i in "${arrayC[@]}"
do
	cc $i -o ${i}c
	# echo ${i}c
done

