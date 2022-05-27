#!/bin/bash
if [[ ! -e clone ]]; then
        gcc -Wall --ansi --pedantic -o clone clone.c
fi

if [[ ! -e zad1 ]]; then
        gcc -Wall --ansi --pedantic -o zad1 zad1.c
fi

if [[ ! -e zad2 ]]; then
        gcc -Wall --ansi --pedantic -o zad2 zad2.c
fi

if [[ ! -e zad3 ]]; then
        gcc -Wall --ansi --pedantic -o zad3 zad3.c
fi

if [[ ! -e zad4 ]]; then
        gcc -Wall --ansi --pedantic -o zad4 zad4.c
fi

if [[ ! -e zad5 ]]; then
        gcc -Wall --ansi --pedantic -o zad5 zad5.c
fi

