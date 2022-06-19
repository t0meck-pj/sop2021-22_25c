#!/bin/bash
read name       #czyta imię
output=$(sed 's:'"$name"':\\e[31m'"$name"'\\e[0m:g'<$1) #znajduje i koloruje imię $1 odpowiada za pobranie nazwy pliku
echo -e "$output" #Wyświetla plik i imię