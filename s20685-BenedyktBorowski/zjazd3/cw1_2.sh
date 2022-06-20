#!/bin/bash 
FILE=$PWD
if test -f "$FILE/config.cfg";then
        $FILE/config.cfg
elif [$# != 0] && [-e $FILE/$1 ]; then
$FILE/$1
else
    echo "Error"
fi