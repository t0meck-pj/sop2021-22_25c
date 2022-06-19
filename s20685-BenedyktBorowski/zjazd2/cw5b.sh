#!/bin/bash

echo "Pierwszy znak argumentu to: ${1:0:1}"

Length=${#1}
Length=$(($Length-1))

echo "Ostatni znak argumentu to: ${1:$Length}"

output=$(echo $1 | sed 's/SOP/\\e[32mSOP\\e[0m/g')





echo -e $output