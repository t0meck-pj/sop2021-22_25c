#!/bin/bash

ls -p | grep -v / | while IFS= read line; 
do 
echo Patrzcie panstwo oto plik: $line;
done