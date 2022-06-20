#!/bin/bash
a=$(ls -p | grep -v /)   
for a in *.c                                                                                                                     
do
    $(cc "$a" -o "$a | sed 's/\.[^\.]*$//'") 
done