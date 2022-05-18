#!/bin/bash

liczbaKatalogow=$(ls -lp | sed /^total/d | egrep -v /$ | wc -l)
if[["$liczbaKatalogow" > "5"]];
then
    echo "W bieżącym katalogu jest więcej niż 5 plików"
elif [["$liczbaKatalogow" < "5"]]
    echo "W bieżącym katalogu jest mniej niż 5 plików"
elif [["$liczbaKatalogow" ="5"]]
    echo "W bieżącym katalogu jest 5 plików"