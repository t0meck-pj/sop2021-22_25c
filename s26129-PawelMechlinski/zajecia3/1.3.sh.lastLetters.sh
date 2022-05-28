#!/bin/bash

echo "$0"
if [[ "${0: -3}" == ".sh" ]]
then
	echo -e "Script ends at .sh.\nWill do nothin'..."
else
	echo -e "Script doesn't end at .sh\nAddin' suffix..."
	NEWNAME="${0}.sh"
	mv $0 $NEWNAME
fi
