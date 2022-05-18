#!/bin/bash

z1=$(ls -p | grep -v /)   
for z1 in *.c                                                                                                                     
do
    $(cc "$z1" -o "$z1 | sed 's/\.[^\.]*$//'") 
done