#!/bin/bash

# Możliwe jest wykorzystanie (co najmniej) dwóch komend do podzielenia zmiennej tekstowej na znaki:
#	1. | fold -w1
# 	2. | grep -o .
# Druga opcja jest zalecana, ponieważ pierwsza nie poradzi sobie z przetworzeniem znaków UNICODE.

#for i in $@; do
#	cat $i;
#	tac $i;
#	echo -e "\n";
#done
# ^ Powyższe pochodzi z "prostej" wersji skryptu.


for i in $@; do
	count=$(echo "$i" | grep -o .)
	echo $count
	for j in (1..$count-1); do
		arr[j-1]=$(echo "$i" | grep -o . | xargs sed "${j}q;d")
		done
	echo "arr[@]"
done

