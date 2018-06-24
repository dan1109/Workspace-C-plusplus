#ifndef DIZIONARIO_H_INCLUDED
#define DIZIONARIO_H_INCLUDED

#include "Lista.h"

/**
Dizionario realizzato con un vettore di lista linkata non ordinata
*/
template< typename K, typename T >
class Dizionario{
public:

typedef T tipoelem;
typedef Nodo<K,T>* posizione;
    //DIM è la dimensione statica del vettore
    #define DIM 4

    typedef     T   valore;
    typedef     K   chiave;

Dizionario();          //INUTILE
void creaDizionario(); // TESTATA FUNZIONA
~Dizionario();         //INUTILE
bool dizionarioVuoto();    //TESTATA FUNZIONA
void deleteDizionario();   //TESTATA FUNZIONA
bool appartiene(K);  //TESTATA FUNZIONA
void inserisci(K,T);   //TESTATA FUNZIONA
void cancella(K);    //TESTATA FUNZIONA
void stampaDizionario();       //TESTATA FUNZIONA
int  cardinalita();         //TESTATA FUNZIONA
int Hash_string(K);         //FUNZIONA TESTATA

T recuperaValore(K);

private:
/**PUNTATORE A UNA LISTA CHE E' VUOTA E DA ALLOCARE per gli elementi di un insieme*/
Lista<K,T> lista [DIM];

};

template< typename K, typename T >
T Dizionario<K,T>::recuperaValore(K e)
{       T errore;
        int temp_hash=Hash_string(e);
        //IL RESTO DELLA DIVISIONE PER HASH DELLA CHIAVE DA LA POSIZIONE IN CUI DEVE STARE
        int ins = temp_hash%DIM;
    if(appartiene(e))
    {
        posizione temp = lista[ins].primoLista();
        while(lista[ins].fineLista(temp)==false)
        {
            if(lista[ins].leggiChiavLista(temp)==e)
            {
                return lista[ins].leggiValLista(temp);
            }
            temp = lista[ins].succLista(temp);
        }
        //ultimo elemento
         if(lista[ins].leggiChiavLista(temp)==e)
            {
                return lista[ins].leggiValLista(temp);
            }
    }
    else
    {
        cout<<"(Non c'è restituisco un valore a caso)\n";
        return errore;
    }
}

/**
Passaggio per referenza di una chiave(string) per il calcolo della funzione hash. Visto a Lezione
*/
template< typename K, typename T >
int  Dizionario<K,T>::Hash_string(K the_key)
{
    unsigned long hash_value = 0;
    int length = (int) the_key.length();
    for (int i=0; i<length; i++)
      hash_value = 5 * hash_value + the_key.at(i);
    return size_t(hash_value);
}


/**
restituisce il numero di elementi di un Insieme
*/
template <class K,class T>
int Dizionario<K,T>:: cardinalita()
{
    return DIM;
}


/**
Costruttore di Insieme, invoca creaInsieme
*/
template <class K,class T>
Dizionario<K,T>:: Dizionario(){
    cout<<endl<<"Diz. Appena creato"<<endl<<endl;
}


/**
Distruttore di Insieme, invoca deleteInsieme
*/
template <class K,class T>
Dizionario<K,T>:: ~Dizionario(){

}


/**
deleteInsieme dealloca la lista
*/
template <class K,class T>
void Dizionario<K,T>::deleteDizionario(){
    int i=0;
    while( i<cardinalita() )
    {
             lista[i].deleteLista();
             i++;
    }
         cout<<"Dizionario canc.\n";
}


/**
creaInsieme alloca lista. Quindi in automatico partirà il suo costruttore e poi distruttore
*/
template <class K,class T>
void Dizionario<K,T>::creaDizionario(){
    int i=0;
    cout<<"Creazione Diz:\n";
        while(i<cardinalita())
    {
             lista[i].creaLista();
             i++;
    }
    cout<<endl;
}


/**
InsiemeVuoto verifica se la lista è vuota
*/
template <class K,class T>
bool Dizionario<K,T>::dizionarioVuoto()
{
    int cont_vuoti=0;
    int i=0;
    bool flag=false;
while(i<cardinalita())
{
    if(lista[i].listaVuota()==true)
    {
        cont_vuoti++;
        flag=true;
    }
    else
    {
        return flag=false;
    }
    i++;
}
return flag;
}


/**
Si scandisce tutto l'insieme e si verifica se un elemento è già presente. In tal caso TRUE
*/
template <class K,class T>
bool Dizionario<K,T>::appartiene(K e)
{        bool flag=false;
        int temp_hash=Hash_string(e);
        //IL RESTO DELLA DIVISIONE PER HASH DELLA CHIAVE DA LA POSIZIONE IN CUI DEVE STARE
        int ins = temp_hash%DIM;
    if(lista[ins].listaVuota())
    {
        cout<<"el. non appartiene all'Insieme perché vuoto.\n";
    }
    else
    {   posizione temp = lista[ins].primoLista();
        while(lista[ins].fineLista(temp)==false && flag==false)
        {
            if(lista[ins].leggiChiavLista(temp)==e)
            {
                flag=true;
            }
            temp = lista[ins].succLista(temp);
        }
        //ultimo elemento
         if(lista[ins].leggiChiavLista(temp)==e)
            {
                flag=true;
            }
        if(flag==false)
        {
            temp = lista[ins].succLista(temp);
        }
    }
    return flag;
}


/**
Inserisce un elemento nell'Insieme se non è già presente
*/
template <class K,class T>
void Dizionario<K,T>::inserisci(K k, tipoelem e)
{   int temp_hash=Hash_string(k);
    //IL RESTO DELLA DIVISIONE PER HASH DELLA CHIAVE DA LA POSIZIONE IN CUI DEVE STARE
    int ins = temp_hash%DIM;
    posizione temp;
    if(lista[ins].listaVuota()==true)
    {
        lista[ins].insSuccLista(temp,e,k);

    }
    else
    {   if(appartiene(k))
        {   //elemento e appartiene via via stacca staccaaaa!!
            cout<<"Non posso inserire un elemento che appartiene gia' all'Insieme.\n";
        }
        else
        {
        lista[ins].insSuccLista(temp,e,k);
        }

    }
}


/**
Cancella un elemento da un Insieme se appartiene o se l'insieme contiene almeno un elemento.
*/
template <class K,class T>
void Dizionario<K,T>::cancella(K e)
{   int temp_hash=Hash_string(e);
    //IL RESTO DELLA DIVISIONE PER HASH DELLA CHIAVE DA LA POSIZIONE IN CUI DEVE STARE
    int ins = temp_hash%DIM;

    posizione temp;
    int scan_elm=1;
    bool cancellato=false;
    temp =  lista[ins].primoLista();
    if(lista[ins].listaVuota()==true)
    {
        cout<<"Insieme vuoto non puoi canc.\n";
    }//fine if
    else
    {
        while(lista[ins].leggiChiavLista(temp)!=NULL  &&  cancellato==false  &&  scan_elm <= lista[ins].leggiNumElem())
        {
            if(lista[ins].leggiChiavLista(temp) == e)
            {
                lista[ins].cancLista(temp);
                cancellato=true;
            }
            if(lista[ins].succLista(temp)!=NULL)    //incrementa temp solo se successivo diverso da null
            {
                temp = lista[ins].succLista(temp);  //incremento temp
            }
            scan_elm++;
        }//finw while
        if(cancellato==false)
        {
            cout<<"El. non faceva parte dell'Insieme non ho canc. nulla.\n";
        }//fine ultimo if di else
    }//fine else
}//fine implementazione


/**
Stampa elementi di un insieme
*/
template <class K,class T>
void Dizionario<K,T>::stampaDizionario()
{
    cout<<"\nSTAMPA Dizionario:";
    int i=0;
    while(i<cardinalita())
    {
             lista[i].stampaLista();
             i++;
    }
}

#endif // DIZIONARIO_H_INCLUDED
