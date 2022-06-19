#!/bin/bash
X=Tekst  #Ustalamy zmienną X o trześci tekst
echo $x #chcemy wywołać zmienną 
bash #zmienna znika i nie jest dłużej zapisana w terminalu
echo $x #próbujemy wyświetlić zmienneą któej już nie ma

X=Tekst Dłuższy #tekst jest za długi i potrzebny jest cudzysłów przez polskie znaki
echo $X #Nie wyświetli się ponieważ zmienna nie zostałą utworzona


X="Tekst 1" #ustalamy zmienną X w poprawny sposób
Y="tekst:$X" #Ustalamy zmienną Y w poprawny sposób gdyż w cudzysłowiu zmienne są brane pod uwagę
echo "$Y" # Wywołujemy zmienna Y 
Y='tekst:$X' #ustalamy nowa zmienną natomiast jest ona utworzona błędnie ponieważ apostrofy nie
             #biorą pod uwagę zmiennych
echo "$Y"    #Zmienna nie jest utwożona więc nic się nie stanie
Y=tekst:$X   #Błędnę utowrzenie, brakuje ""
echo "$Y"    #Wywołujemy błędnie utworzoną zmienną. Nic się nie stanie. 
#Różnica między ' a ".  " = służy do utowrzenie zmiennej z wieloma słowami oraz z braniem pod uwagę
#innych zmiennych jak i polskich znaków. ' = służy do utworzenia zmiennej z dowolną ilości i w dowolnym
#ciągu znaków, niestety zmienne nie są już brane pod uwagę.

A=Ala   #Tworzymy zmienną w poprawny sposób (Jest to jedno słowo więc nie musi być "" ani '')
echo $A ma kota, a kot ma ${A}ę # wyślwietli się Ala ma kota, a kot ma Alaę. 
