#!/bin/bash                                                                                                                                                                                                                                   

                                                       

function fibonacci {
        x=0                                                                                                                          
        y=1

        if [[ $n == 1 || $n == 0 ]]; then                                                                                                                                                   
        echo "$n"
        elif [ $n > 2 ]; then                                                                                   
                for (( i=2; i <= $n; i++ ))                                                                                                                                     
                do
                z=$[y+x]                                                                                                                                       
                x=$y                                                                                                                     
                y=$z                                                                                                                                                       
                done
                fi
        echo "$n wyraz ciagu Fibonacciego jest rowny $z"                                                                                                                 
}

echo Podaj liczbe n liczby ciagu Fibonacciego                                                     
read -s n                                                                                                                                         
fibonacci