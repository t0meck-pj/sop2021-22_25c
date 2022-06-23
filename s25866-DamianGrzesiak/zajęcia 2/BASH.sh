#!/bin/dash
#zad 1
#echo Witaj w terminalu
#najpierw trzeba było zmienić chmod na 764(uznałem że tak będzie najjlepiej) a przed nazwą pliku wpisać "sh"
#w konsoli wyświetla sie "Witaj w terminalu"

#zad2
#X=tekst
#echo $X
#bash
#echo $X
#wyświtla się najpierw " tekst" a następnie nic po chwili ładowania, komenda "bash" otworzyłą kolejną powłokę przez co zmiennej tam nie było

#X="Tekst dłuższy"
#echo $X
#pojawia się błąd dłuższy: not found, po dodaniu apostrofów wyswietla się cały tekst bez błędów, to samo się dzieje z cudzysłowiem

#X="Tekst 1"
#Y="Tekst:$X"
#echo "$Y"
#Y='Tekst:$X'
#echo "$Y"
#Y=Tekst:$X
#echo "$Y"
#w tekście napisanym w "" są rozróżniane zmienne, tekst zapisany w '' jest "zablokowany"- nie jest interpretowany, dzięki temu mozna zapisywac symbole takie jak "$"

#A=Ala
#echo "$A ma kota, kot ma ${A}ę"
#wypisuje się tekst w formie Ala ma kota, kot ma Alaę


#echo $@ #Wypisuje co się pojawi po echo 
#echo $* #nic nie pokazuje
#echo $0 #wypisuje ścieżkę do skryptu
#echo $1,$2 #wypisuje kolejne zmienne (ich ilość zalezy od ilości zmiennych w programie
#echo $# # wypisuje ilość zmiennych
#echo $? #wypisuje "exit status"-stan wyjścia
#echo $$ #wypisuje ID procesu
#echo $! #wypisuje ID ostatniego procesu działającego w tle

#zmienne wbudowane zapisujemy tak samo jak wszytkie inne z "$" na początku
#PATCH-służy do pokazywania ścieżek do komend- umożliwia dodanie skryptu do ścieżki z dowolnego miejsca export PATH(nazwa)=<ścieżka> 
 #RANDOM-generator losowych liczb-przy losowaniu jakimkoliwek
 #PWD-zmienna do używania w skryptach pokazuje ściezke w skrypcie

 #PS1- wartości konsoli
 #USER-nazwa linuxa
 #HOSTNAME- wypisuje nazwe hosta
 #OSTYPE-wypisuje wersje systemu
 
#zm=$(ls -la) 
#echo $zm 
#nie nie da nam wyniku ls-la, wywołanie zmiennej zm da nam natychmiastowo komendę ls z opcjami -la (wypisanie zawartości ściezki wraz z ukrytymi plikami oraz dodatkowymi informacjami takimi jak dostępy) warto zaznaczyć że nie wypisuje danych w kolejnych liniach tylko "jedym ciągiem"

#X=$(ls -l) 
#echo $X
#jak wyżej opisane

#echo $((((2+2))))
#X=5
#echo $((2*X))
#powłoka bash pozwala nam na wykonywanie okeślonych działań matematycznych dzięki użyciu podwójnych nawiasów. Pojedyńcze nawiasy nie dają nam żadnego wyniku, jedynie informację ze "not found". 3, 4 i więcej par nawiasów nie zmienia wyniku otwierając nam możliwość bardziej skomplikowanych zadań, możemy również używać zmiennych jako składników działań
#TEKST="$A ma kota a kot ma $Aę"
#A=Ala
#echo ${#TEKST}-wypisuje nam długość ciągu znaków (w tym wypadku 25)
#echo ${TEKST:1}-wypisuje tekst zaczynając od litery na pozycji opisanej po ":"
#echo ${TEKST:$x:$Y}-wypisuje tekst zaczynając od pozycji opisanej pierwszą liczbą i wypisuje tyle znaków ile opisuje druga liczba(można oczywiście zamiast liczby użyć zmiennej
#echo ${TEKST/${X1} /${Y1}}-podmienia pierwsze pasujące wyrażwenie do wartości pierwszej na wartość drugą
#echo ${TEKST//$X1/$Y1}
#przy tym zadaniu cały czas wyskakiwał mi komunikat "Bad substitution", w ten sposób dowiedziałem sie że Ubuntu zamiast bash-a używa dash-a. zmiana pierwszej komendy na "bash" zamiast "sh" pomogła i mogłem kontynuowac zadanie
#echo ${A} ma kota a kot ma ${A/a/ę}

#A=$1
#X=${#A}
#echo ${A} ma kota a kot ma ${A:0:(X-1)}ę
#Piszemy w konsoli bash BASH.sh Imię (np Magda)

#A=$1
#X=${#A}
#echo ${A:0:1}
#echo ${A:(X-1)}
#echo -e ${A/SOP/"\e[32mSOP\e[0m"}
#teskst jeśli jest "SOP" to wypisywany jest w zielonym kolorze

#echo Alicja | sed s/a$/ę/g | sed 's/\([^ę]\)$/\la/g'
#Pojawia "Alicję" po uruchamieniu w bashu 
