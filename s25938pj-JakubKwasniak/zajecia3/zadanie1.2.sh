#!/bin/bash

if [ -e $currentPath/config.cfg ];#jeżeli istnieje  
then                                                                                                                             
        $currentPath/config.cfg                                                                                                                                                                  
elif [ $# != 0 ] && [ -e $currentPath/$1 ]; #jeżeli nie istnieje
then                                                                                                                                                                                                                                  
$currentPath/$1                                                                                                                                                        
ese #jeżeli żadne z powyższych 
        echo "Błąd"                                                                                                                                         
fi