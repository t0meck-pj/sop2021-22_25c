#!/bin/bash

FILE=./config.cfg
PATH="./"

if test -f "$FILE"; then
	./config.cfg
elif [ $# -ge 1 ]; then
	PATHcon="$PATH$1"
	echo "Uruchamiam $PATHcon"
	$PATHcon
else
	echo "BŁĄÐ!"
fi
