#!/bin/bash

# To jest skrypt w wersji dość podstawowej: obsługuje 4-bitowe kolory ze słownika i nie wyświetla żadnego koloru jeśli nie ma go na liście.

function koloruj () {
    Red=$'\e[1;31m'
    Green=$'\e[1;32m'
    Blue=$'\e[1;34m'
    Black=$'\e[1;30m'
    Yellow=$'\e[1;33m'
    Magenta=$'\e[1;35m'
    Cyan=$'\e[1;36m'
    White=$'\e[1;37m'
    BrightBlack=$'\e[1;90m'
    BrightRed=$'\e[1;91m'
    BrightGreen=$'\e[1;92m'
    BrightYellow=$'\e[1;93m'
    BrightBlue=$'\e[1;94m'
    BrightMagenta=$'\e[1;95m'
    BrightCyan=$'\e[1;96m'
    BrightWhite=$'\e[1;97m'



    echo -e "${!2}$1 \033[0m"

}

echo $(koloruj $1 $2) 
