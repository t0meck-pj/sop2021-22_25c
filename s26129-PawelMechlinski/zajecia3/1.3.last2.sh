#!/bin/bash

INPUT=${0:(-3)}


if [[ "$INPUT" == ".sh" ]]
then
	echo -e "Script ends at .sh.\nWill do nothin'..."
else
	echo -e "Script doesn't end at .sh\nAddin' suffix..."
	NEWNAME="${0}.sh"
	mv $0 $NEWNAME
fi
