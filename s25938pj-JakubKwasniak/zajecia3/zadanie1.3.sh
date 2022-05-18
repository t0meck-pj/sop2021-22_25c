#!/bin/bash

fileName="$(basename $0)"     
x=${#fileName}                                                                                                                                                        
rozszerzenie=${fileName:$((x-3)):3}

if [ "$enlargement" != ".sh" ]; #jeżeli kończy się na sh
then                                                                      
        echo "Rozszerzenie sh nie zostalo znalezione. Nastapila zmiana rozszerzenia"
        mv $0 ${0}.sh
else
        echo "Plik posiada roszerzenie sh"       
fi