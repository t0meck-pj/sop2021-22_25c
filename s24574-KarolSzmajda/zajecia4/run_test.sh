#!/bin/bash
if [[ ! -e hexviewer ]]; then
	gcc -Wall --ansi --pedantic -o hexviewer hexviewer.c
fi

./hexviewer /etc/passwd
