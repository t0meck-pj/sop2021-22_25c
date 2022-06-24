#!/bin/bash
#X=$(ls -p |wc -l)
for X in *.c; do
#echo $X
x1=$X| sed "s/\...*$//"

echo $x1
#cc "$X" -o "$x1"

done