#!/bin/bash

DirCount=$(ls -lp | sed /^total/d | egrep -v /$ | wc -l)
if[["$DirCount" > "5"]];
then
    echo "W tym katalogu znajduję się więcej niż 5 plików"
elif [["$DirCount" < "5"]]
    echo "W tym katalogu znajduję się mniej niż 5 plików"
elif [["$DirCount" ="5"]]
    echo "W tym katalogu jest 5 katalogów"
    fi