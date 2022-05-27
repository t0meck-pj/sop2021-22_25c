#!/bin/bash
if [[ ! -e zad1_1 ]]; then
        gcc -Wall --ansi --pedantic -o zad1_1 zad1_1.c
fi


if [[ ! -e zad1_2 ]]; then
        gcc -Wall --ansi --pedantic -o zad1_2 zad1_2.c
fi


if [[ ! -e zad1_3 ]]; then
        gcc -Wall --ansi --pedantic -o zad1_3 zad1_3.c
fi


if [[ ! -e zadIO ]]; then
        gcc -Wall --ansi --pedantic -o zadIO zadIO.c
fi


if [[ ! -e hexviewer ]]; then
        gcc -Wall --ansi --pedantic -o hexviewer hexviewer.c
fi


if [[ ! -e zad_ptr ]]; then
        gcc -Wall --ansi --pedantic -o zad_ptr zad_ptr.c
fi

