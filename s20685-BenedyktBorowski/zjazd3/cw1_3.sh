#!/bin/bash

File="$(basename $0)"     
x=${#File}                                                                                                                                                        
extention=${File:$((x-3)):3}

if [ "$enlargement" != ".sh" ];
then                                                                      
        echo "Nie jest to skrypt, zostanie na niego zmieniony."
        mv $0 ${0}.sh
else
        echo "Jest to skrypt"       
fi