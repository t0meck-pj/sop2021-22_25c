#!/bin/bash

echo "Pierwszy znak argumentu to: ${1:0:1}"

Length=${#1}
Length=$(($Length-1))

echo "Ostatni znak argumentu to: ${1:$Length}"

echo -e "\e[32m$1\e[0m"
