#!/bin/bash

a=$(ls -p | grep -v /)                                                                                                                                            
b=$(ls -p | grep -cv /)                                                                                                                                        
tab=($a)                       
for a in *                                                             
do
        echo $a
done
for (( i=($b-1); i >= 0;i--)); 
do 
echo ${tab[i]}; 
done