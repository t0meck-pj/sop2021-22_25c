#!/bin/bash
echo witaj
for ((i=10; i>0;i--))
    do 
        if (($i%2 == 0))
        then  echo $i
    
        fi
done