#!/bin/bash
x = $($ cat $1)
z=$(echo $x | sed 's/\<Jan\>/\\e[31mJan\\e[0m/g')
echo -e "$z"