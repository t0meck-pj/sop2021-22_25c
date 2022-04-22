#!/bin/bash

z1=$(ls -p | grep -v /)                                                                                                                                            
x=$(ls -p | grep -cv /)                                                                                                                                        
tab=($z1)                       
for z1 in *                                                             
do
        echo $z1
done
for (( i=($x-1); i >= 0;i--)); 
do 
echo ${tab[i]}; 
done    