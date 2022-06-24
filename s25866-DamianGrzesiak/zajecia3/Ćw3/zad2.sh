#!/bin/bash

f(){
if [ -z "$1" ]
then return 1

else 
return $(f($1-2)+f($1-1))
fi
}

f()