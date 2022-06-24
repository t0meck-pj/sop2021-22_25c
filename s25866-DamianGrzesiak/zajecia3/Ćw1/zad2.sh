#!/bin/bash
#2

patch=$pwd
if [ -e $patch/config.cfg]
	then
		touch $patch/config.cfg

elif [$# > 0] && [$patch/$1]
	then
		$patch/$1

else
	echo "error"
fi