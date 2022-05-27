#!/bin/sh

find ./ -maxdepth 1 -type f -name '*.c' | while read line ; do cc $line -o $(echo "$line" | rev | cut -c3- | rev) ; done

