#!/bin/bash

# Możliwe jest wykorzystanie (co najmniej) dwóch komend do podzielenia zmiennej tekstowej na znaki:
#	1. | fold -w1
# 	2. | grep -o .
# Druga opcja jest zalecana, ponieważ pierwsza nie poradzi sobie z przetworzeniem znaków UNICODE.

for i in $@; do
	cat $i;
	tac $i;
	echo -e "\n";
done
