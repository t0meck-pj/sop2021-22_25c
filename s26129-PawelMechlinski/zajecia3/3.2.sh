#!/bin/bash

function Fibonacci () {
	if [[ $1 -lt 0 ]]; then return 0; fi
	case $1 in 

		--help) echo -e "Podaj w parametrze wartość n, a funkcja obliczy dla Ciebie Fₙ."
			;;

		0) echo 0; return 0
			;;
                1) echo 1; return 1
                        ;;
	esac
	index=$1
	indexOne=$(($1 - 1))
	indexTwo=$(($1 - 2))
#	echo $indexOne
#	echo $indexTwo
	fibOne=$(Fibonacci $indexOne)
	fibTwo=$(Fibonacci $indexTwo)
	result=$(expr $fibOne + $fibTwo)
	echo $result
        return $result
}

echo "$(Fibonacci $1)"



# Ograniczenie i "myk" z tym zadaniem polega na tym, że możliwe jest oczywiście zwracanie wyniku poprzez "return", ale jedyne, co w ten sposób osiągnie się, to użyje zmiennej numerycznej jako kodu błędu. Tym samym ograniczeniem drugiego poziomu jest zakres liczb od 0 do 255 - w przypadku fibonacciego oznacza to, że w przypadku czternastego elementu ciągu wynik po prostu w ogóle się nie zapiszę (przynajmniej na to by wskazywał test, który przeprowadziłem z przekierowaniem stderr). Tak czy siak, stderr nie jest wyjściem programu odbieranym przez konstrukcję $(..), a jest ona konieczna (chyba) do rekurencyjnego wzoru na fibonacciego. Dlatego potrzeba wykorzystać dodatkowo np. echo, które zapisuje na stdout i zapewnia ciągłość rekurencji. 
