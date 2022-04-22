#!/bin/sh

if [[ -f ./config.cfg ]]; then
	echo "Uruchamiam plik config"
	./config.cfg
else
	echo "Plik config nie istnieje"
	
	if [[ $# > 0 ]]; then
		if [[ -f $1 ]]; then
			$1
		else
			echo "Plik $1 nie istnieje"
		fi
	else
		echo "Nie podano parametrów"
	fi
fi