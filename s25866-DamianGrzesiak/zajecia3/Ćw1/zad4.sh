#! /bin/bash
ilosc_plikow= ls | wc -l | echo -n
if [ $ilosc_plikow > "5" ]
    then
    echo "jest wiecej niz 5 plikow"

else
    echo "jest 5 lub mniej plikow"
fi