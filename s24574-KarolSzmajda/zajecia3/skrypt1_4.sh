#!/bin/sh

FC=$(ls -lp | sed /^total/d | egrep -v /$ | wc -l)
if [[ FC -gt 5 ]]; then
	echo "Jest wiecej niz 5 plikow"
else
	echo "Jest mniej niz 5 plikow"
fi
