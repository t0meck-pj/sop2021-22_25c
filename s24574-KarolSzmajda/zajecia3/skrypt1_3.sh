#!/bin/sh

if [[ $0 == *.sh ]]; then
	echo "Plik kończy sie na .sh"
else
	echo "Plik nie konczy sie na .sh, nowa nazwa pliku to $0.sh"
	mv $0 "$0.sh"
fi