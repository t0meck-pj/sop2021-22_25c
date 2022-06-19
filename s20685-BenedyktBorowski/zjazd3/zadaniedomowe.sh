#!/bin/bash                                                                                     

x=${#1}         
if [[ "$1" =~ ^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$ ]]; then                                     
        echo " to jest email"                                                                                                                                                                           

elif [[ "$1" =~ ^[0-9]{2}+-[0-9]{3}$ ]]; then                                  
        echo " to jest kod pocztowy"

elif [[ "$1" =~ ^[A-ZŻŹĆĄŚĘŁÓ]{1}+[a-zżźćąśęłó]{1,"$x"}$ ]]; then                                                     
                                                                                                                                                                                                                          
        echo " należy do polskich imion"
else
        echo "Błędnie wprowadzone dane"code 
fi
                                      
