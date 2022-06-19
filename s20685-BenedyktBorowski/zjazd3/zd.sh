#!/bin/bash

a=${#1}

if [[ $1 =~ ^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$ ]]; 
then
    echo "$1 jest adresem e-mail."
elif [[ $1 =~ ^[0-9]{2}+-[0-9]{3}$ ]];
then
    echo "$1 jestem kodem pocztowym."
elif [[ $1 =~ ^[A-ZĘÓĄŚŁŻŹĆŃ]{1}+[a-zęóąśłżźćń]{1,"$a"}$ ]];
then
    echo "$1 jest polskim imieniem"
else
    echo "$1 nie jest ani polskim imieniem, ani polskim kodem pocztowym, ani adresem e-mail ."
fi