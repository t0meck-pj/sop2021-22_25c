#!/bin/sh

find ./ -maxdepth 1 | sed 's/^.\{2\}/Patrzcie Państwo, oto plik: /' | tail -n +2