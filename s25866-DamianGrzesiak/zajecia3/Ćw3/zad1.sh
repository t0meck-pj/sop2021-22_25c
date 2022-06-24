#!/bin/bash
napis=$1                                                                                    
kol=$2                                                                                                                                                                                
function kolor {                                                                                                        
        if [[ $kol == "Red" || $kol == "red" || $kol == "RED" ]]; then                                               
                echo -e "\e[31m$napis\e[0m"                                                                                                           
        elif [[ $kol == "Black" || $kol == "black" || $kol == "BLACK" ]]; then                                                       
                echo -e "\e[30m$napis\e[0m"
        elif [[ $kol == "Green" || $kol == "green" || $kol == "GREEN" ]]; then
                echo -e "\e[32m$napis\e[0m"
        elif [[ $kol == "Brown" || $kol == "brown" || $kol == "BROWN" ]]; then
                echo -e "\e[33m$napis\e[0m"
        elif [[ $kol == "Blue" || $kol == "blue" || $kol == "BLUE" ]]; then
                echo -e "\e[34m$napis\e[0m"
        elif [[ $kol == "Magneta" || $kol == "magneta" || $kol == "MAGNETA" ]]; then
                echo -e "\e[35m$napis\e[0m"
        elif [[ $kol == "Cyan" || $kol == "cyan" || $kol == "CYAN" ]]; then
                echo -e "\e[36m$napis\e[0m"
        elif [[ $kol == "White" || $kol == "white" || $kol == "WHITE" ]]; then
                echo -e "\e[37m$napis\e[0m"
        else
                echo Blad
        fi
}

kolor