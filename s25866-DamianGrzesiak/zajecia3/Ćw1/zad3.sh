#! /bin/bash
filename=$0                                                                              

if [ "${filename##*.}" != "sh"  ]

     then                                                                                                    
        echo "brak takiegol pliku"                                                                                   
        mv $filename $filename.sh  

else
        echo 'plik ma rozszerzenie ".sh"'                                                                                                                    
fi