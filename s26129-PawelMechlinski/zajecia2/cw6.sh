#!/bin/bash


echo "$1 ma kota, a kot ma $(echo $1 | sed s/a$/ę/g | sed 's/\([^ę]\)$/\1a/g')"
