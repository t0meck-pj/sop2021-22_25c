#!/bin/bash                                                                                                                                                                                                                                   

                                                                                    
a=$1                                                                                        
b=$2                                                                                                                                                                                      

function colors {                                                                                         
                                                                                
        if [[ $b == "Czarny" || $b == "czarny" || $b == "CZARNY" ]]; 
        then                                                  
            echo -e "\e[30m$a\e[0m"
        elif [[ $b == "Czerwony" || $b == "czerwony" || $b == "CZERWONY" ]]; 
        then                                 
            echo -e "\e[31m$a\e[0m"                                
        elif [[ $b == "Zielony" || $b == "zielony" || $b == "ZIELONY" ]]; 
        then
            echo -e "\e[32m$a\e[0m"
        elif [[ $b == "Brazowy" || $b == "brazowy" || $b == "BRAZOWY" ]]; 
        then
            echo -e "\e[33m$a\e[0m"
        elif [[ $b == "Niebieski" || $b == "niebieski" || $b == "NIEBIESKI" ]]; 
        then
            echo -e "\e[34m$a\e[0m"
        elif [[ $b == "Rozowy" || $b == "rozowy" || $b == "ROZOWY" ]]; 
        then
            echo -e "\e[35m$a\e[0m"
        elif [[ $b == "Cyan" || $b == "cyjanowy" || $b == "CYJANOWY" ]]; 
        then
            echo -e "\e[36m$a\e[0m"
        elif [[ $b == "JasnoSzary" || $b == "jasnoszary" || $b == "JASNOSZARY" ]];
        then
            echo -e "\e[37m$a\e[0m"
        elif [[ $b == "CiemnoSzary" || $b == "ciemnoszary" || $b == "CIEMNOSZARY" ]];
        then
            echo -e "\e[90m$a\e[0m"
        elif [[ $b == "JasnoCzerwony" || $b == "jasnoczerwony" || $b == "JASNOCZERWONY" ]];
        then
            echo -e "\e[91m$a\e[0m"
        elif [[ $b == "JasnoZielony" || $b == "jasnozielony" || $b == "JASNOZIELONY" ]];
        then
            echo -e "\e[92m$a\e[0m"
        elif [[ $b == "JasnoZolty" || $b == "jasnozolty" || $b == "JASNOZOLTY" ]];
        then
            echo -e "\e[93m$a\e[0m"
        elif [[ $b == "JasnoNiebieski" || $b == "jasnoniebieski" || $b == "JASNONIEBIESKI" ]];
        then
            echo -e "\e[94m$a\e[0m"
        elif [[ $b == "JasnoRozowy" || $b == "jasnorozowy" || $b == "JASNOROZOWY" ]];
        then
            echo -e "\e[95m$a\e[0m"   
        elif [[ $b == "JasnyCyjan" || $b == "jasnycyjan" || $b == "JASNYCYJAN" ]];
        then
            echo -e "\e[96m$a\e[0m"
            elif [[ $b == "Bialy" || $b == "bialy" || $b == "BIALY" ]];
        then
            echo -e "\e[97m$a\e[0m"                  
        else
                echo Blad
        fi
}
         
echo "Tekst ktory wpisales do pokolorowania przed kolorowaniem: "                                                                                                                                                     
echo $1
echo "A to twoj tekst juz po kolorowaniu: "
colors

