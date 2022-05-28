#!/bin/bash

function imie () {
if [[ $1 =~ [0-9] ]]; then
	printf "$1 to nie imię!"
elif [[ $1 =~ [A-Z]{1}[A-Z]* ]]; then
	printf "$1 to może być imię!"
else printf "$1 to nie poprawnie zapisane imię!"
fi

return 0
}

function kodPocztowy () {
if [[ $1 =~ ^[0-9][0-9][\-][0-9][0-9][0-9]$ ]]; then
	printf "$1 to poprawny polski kod pocztowy"
else printf "$1 to nie jest poprawny polski kod pocztowy!"
fi

return 0
}

function adresEmail () {
if [[ $1 =~ ^[A-Za-z0-9].*[\@][A-Za-z0-9].*[\.][a-zA-Z0-9].*$ ]]; then
	printf "$ to poprawny adres email."
else printf "$1 to nie jest poprawny adres email"
fi

return 0
}


case $2 in
	"imie")
	imie $1
	;;
	"kod pocztowy")
	kodPocztowy $1
	;;
	"adres email")
	adresEmail $1
	;;
esac


