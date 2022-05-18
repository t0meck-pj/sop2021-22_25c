x=${#1}                                

if [[ "$1" =~ ^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$ ]];#Pierwsza część maila jest dowolna, potem małpe, potem nazwę poczty (o2,wp,gmail)
then   
      echo "mail"                                                                                                                                                      

elif [[ "$1" =~ ^[0-9]{2}+-[0-9]{3}$ ]];#Wpierw {2} liczby, potem -, potem {3 liczby}
then                                  
        echo "kod pocztowy"

elif [[ "$1" =~ ^[A-ZŻŹĆĄŚĘŁÓ]{1}+[a-zżźćąśęłó]{1,"$x"}$ ]]; #Musi się zaczynać koniecznie dużą literą
then                                                                 
        echo "imie"
else
        echo "Błędnie wprowadzona wartość"
fi