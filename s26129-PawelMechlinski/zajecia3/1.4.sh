#!/bin/bash

COUNT="[ERROR]"

COUNT=$( find . -maxdepth 1 -type f | wc -l )

echo "Znaleziono $COUNT plików w bieżącym katalogu"



