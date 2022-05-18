#!/bin/bash

imie="Paweł"
text=$(sed 's:'"$imie"':\\e[31m'"$imie"'\\e[0m:g' < $1)
echo -e "$text"

