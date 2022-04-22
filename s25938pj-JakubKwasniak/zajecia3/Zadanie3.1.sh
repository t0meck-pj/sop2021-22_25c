#!/bin/bash                                                                                                                                                                                                                                   

                                                                                    
text=$1                                                                                        
kolor=$2                                                                                                                                                                                      

function kolor {                                                                                         
                                                                                
        if [[ $kolor == "Czarny" || $kolor == "czarny" || $kolor == "CZARNY" ]]; 
        then                                                  
                echo -e "\e[30m$text\e[0m"
        elif [[ $kolor == "Czerwony" || $kolor == "czerwony" || $kolor == "CZERWONY" ]]; 
        then                                 
                echo -e "\e[31m$text\e[0m"                                
        elif [[ $kolor == "Zielony" || $kolor == "zielony" || $kolor == "ZIELONY" ]]; 
        then
                echo -e "\e[32m$text\e[0m"a
        elif [[ $kolor == "Brazowy" || $kolor == "brazowy" || $kolor == "BRAZOWY" ]]; 
        then
                echo -e "\e[33m$text\e[0m"
        elif [[ $kolor == "Niebieski" || $kolor == "niebieski" || $kolor == "NIEBIESKI" ]]; then
                echo -e "\e[34m$text\e[0m"
        elif [[ $kolor == "Rozowy" || $kolor == "rozowy" || $kolor == "ROZOWY" ]]; 
        then
                echo -e "\e[35m$text\e[0m"
        elif [[ $kolor == "Cyan" || $kolor == "cyjanowy" || $kolor == "CYJANOWY" ]]; 
        then
                echo -e "\e[36m$text\e[0m"
        elif [[ $kolor == "JasnoSzary" || $kolor == "jasnoszary" || $kolor == "JASNOSZARY" ]];
        then
            echo -e "\e[37m$text\e[0m"
        elif [[ $kolor == "CiemnoSzary" || $kolor == "ciemnoszary" || $kolor == "CIEMNOSZARY" ]];
        then
            echo -e "\e[90m$text\e[0m"
        elif [[ $kolor == "JasnoCzerwony" || $kolor == "jasnoczerwony" || $kolor == "JASNOCZERWONY" ]];
        then
            echo -e "\e[91m$text\e[0m"
        elif [[ $kolor == "JasnoZielony" || $kolor == "jasnozielony" || $kolor == "JASNOZIELONY" ]];
        then
            echo -e "\e[92m$text\e[0m"
        elif [[ $kolor == "JasnoZolty" || $kolor == "jasnozolty" || $kolor == "JASNOZOLTY" ]];
        then
            echo -e "\e[93m$text\e[0m"
        elif [[ $kolor == "JasnoNiebieski" || $kolor == "jasnoniebieski" || $kolor == "JASNONIEBIESKI" ]];
        then
            echo -e "\e[94m$text\e[0m"
        elif [[ $kolor == "JasnoRozowy" || $kolor == "jasnorozowy" || $kolor == "JASNOROZOWY" ]];
        then
            echo -e "\e[95m$text\e[0m"   
        elif [[ $kolor == "JasnyCyjan" || $kolor == "jasnycyjan" || $kolor == "JASNYCYJAN" ]];
        then
            echo -e "\e[96m$text\e[0m"
            elif [[ $kolor == "Bialy" || $kolor == "bialy" || $kolor == "BIALY" ]];
        then
            echo -e "\e[97m$text\e[0m"                  
        else
                echo Blad
        fi
}
         
echo $1
kolor

