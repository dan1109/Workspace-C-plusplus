#ifndef INSIEME_VETTORE_BOOL_H_INCLUDED
#define INSIEME_VETTORE_BOOL_H_INCLUDED

#include "Lista.h"

/**
Insieme realizzato con una lista linkata non ordinata
*/
template<class T>
class Insieme {
public:

typedef T tipoelem;
typedef Nodo<T>* posizione;

Insieme();          //TESTATA FUNZIONA
void creaInsieme(); // TESTATA FUNZIONA
~Insieme();         //TESTATA FUNZIONA
bool insiemeVuoto();    //TESTATA FUNZIONA
void deleteInsieme();   //TESTATA FUNZIONA
bool appartiene(tipoelem);  //TESTATA FUNZIONA
void inserisci(tipoelem);   //TESTATA FUNZIONA
void cancella(tipoelem);    //TESTATA FUNZIONA
void stampaInsieme();       //TESTATA FUNZIONA
int  cardinalita();         //TESTATA FUNZIONA

//MODIFICO UN OGGETTO C: C.UNIONE(A,B).
void unione(Insieme<T>* ,Insieme<T>* ); //TESTATA FUNZIONANTE
void intersezione(Insieme<T>* ,Insieme<T>*);  //TESTATA E FUNZIONANTE
void differenza(Insieme<T>* ,Insieme<T>*);

private:
/**PUNTATORE A UNA LISTA CHE E' VUOTA E DA ALLOCARE per gli elementi di un insieme*/
Lista<tipoelem>* lista;

};


/**
restituisce il numero di elementi di un Insieme
*/
template <typename T>
int Insieme<T>:: cardinalita()
{
    return lista->leggiNumElem();
}


/**
Costruttore di Insieme, invoca creaInsieme
*/
template <typename T>
Insieme<T>:: Insieme(){
    cout<<"Costruttore: ";
    Insieme<T>::creaInsieme();
}


/**
Distruttore di Insieme, invoca deleteInsieme
*/
template <typename T>
Insieme<T>::~Insieme(){
    cout<<"\nDistruttore: ";
    Insieme<T>::deleteInsieme();
}


/**
deleteInsieme dealloca la lista
*/
template <typename T>
void Insieme<T>:: deleteInsieme(){
    lista->deleteLista();
     cout<<"Insieme canc.\n";
}


/**
creaInsieme alloca lista. Quindi in automatico partirà il suo costruttore e poi distruttore
*/
template <typename T>
void Insieme<T>::creaInsieme(){
    cout<<"Insieme creato da una lista. ";
    //ora parte il costruttore di lista
    lista = new Lista<T>;
}


/**
InsiemeVuoto verifica se la lista è vuota
*/
template <typename T>
bool Insieme<T>::insiemeVuoto()
{
    // RICORDIAMOCI CHE HO USATO LISTA COME UN PUNTATORE
    if(lista->listaVuota()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/**
Si scandisce tutto l'insieme e si verifica se un elemento è già presente. In tal caso TRUE
*/
template <typename T>
bool Insieme<T>::appartiene(tipoelem e)
{   bool flag=false;
    if(lista->listaVuota()==true)
    {
        cout<<"el. non appartiene all'Insieme perché vuoto.\n";
    }
    else
    {   posizione temp = lista->primoLista();
        while(lista->fineLista(temp)==false && flag==false)
        {
            if(lista->leggiLista(temp)==e)
            {
                flag=true;
            }
            temp = lista->succLista(temp);
        }
        //ultimo elemento
         if(lista->leggiLista(temp)==e)
            {
                flag=true;
            }
        if(flag==false)
        {
            temp = lista->succLista(temp);
        }
    }
    return flag;
}


/**
Inserisce un elemento nell'Insieme se non è già presente
*/
template <typename T>
void Insieme<T>::inserisci(tipoelem e)
{    posizione temp;
    if(lista->listaVuota()==true)
    {
        lista->insSuccLista(temp,e);

    }
    else
    {   if(appartiene(e))
        {   //elemento e appartiene via via stacca staccaaaa!!
            cout<<"Non posso inserire un elemento che appartiene gia' all'Insieme.\n";
        }
        else
        {
            lista->insSuccLista(temp,e);
        }

    }
}


/**
Cancella un elemento da un Insieme se appartiene o se l'insieme contiene almeno un elemento.
*/
template <typename T>
void Insieme<T>::cancella(tipoelem e)
{   posizione temp;
    int scan_elm=1;
    bool cancellato=false;
    temp =  lista->primoLista();
    if(lista->listaVuota()==true)
    {
        cout<<"Insieme vuoto non puoi canc.\n";
    }//fine if
    else
    {
        while(lista->leggiLista(temp)!=NULL  &&  cancellato==false  &&  scan_elm <= lista->leggiNumElem())
        {
            if(lista->leggiLista(temp) == e)
            {
                lista->cancLista(temp);
                cancellato=true;
            }
            if(lista->succLista(temp)!=NULL)    //incrementa temp solo se successivo diverso da null
            {
                temp = lista->succLista(temp);  //incremento temp
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
template <typename T>
void Insieme<T>:: stampaInsieme()
{
    cout<<"\nSTAMPA INSIEME:";
    lista->stampaLista();
}


/**
Dato un oggetto Insieme, gli si aggiungono gli elementi di entrambi gli insiemi in modo non ripetuto. Due controlli.
Passaggio per valore di un puntatore(sembra strano ma è così passo la copia).  VENGONO DISTRUTTE LE COPIE NON GLI ORIGINALI
*/
template <typename T>
void Insieme<T>:: unione(Insieme<T>* x,Insieme<T>* y)
{   int i=1;
//Inserisco prima gli elementi di x
    posizione temp = x->lista->primoLista();
    while(i <= x->cardinalita())
    {
        inserisci(x->lista->leggiLista(temp));
        temp = x->lista->succLista(temp);
        i++;
    }
//poi stessa cosa di prima ma inserisco adesso gli elementi di y
    i=1;
    temp = y->lista->primoLista();
    while(i<= y->cardinalita())
    {
        inserisci( y->lista->leggiLista(temp));
        temp = y->lista->succLista(temp);
        i++;
    }
}//fine implementazione


/**
Dato un oggetto Insieme, gli si aggiungono gli elementi di un insieme che  appartengono a entrambi. Un controllo
Passaggio per valore di un puntatore(sembra strano ma è così passo la copia). VENGONO DISTRUTTE LE COPIE NON GLI ORIGINALI
*/
template <typename T>
void Insieme<T>:: intersezione(Insieme<T>* x,Insieme<T>* y){

    int i=1;
//Inserisco prima gli elementi di x
    posizione temp = x->lista->primoLista();
    while(i<=x->cardinalita())
    {
        if(  y->appartiene (( x->lista->leggiLista(temp) ))  )
        {
           inserisci(x->lista->leggiLista(temp));
        }
        temp = x->lista->succLista(temp);
        i++;
    }

}


/**
Dato un oggetto Insieme, gli si aggiungono gli elementi di un insieme che non appartengono all'altro. Due controlli
Passaggio per valore di un puntatore(sembra strano ma è così passo la copia). VENGONO DISTRUTTE LE COPIE NON GLI ORIGINALI
*/
template <typename T>
void Insieme<T>:: differenza(Insieme<T>* x,Insieme<T>* y)
{
     int i=1;
//Inserisco prima gli elementi di x
    posizione temp = x->lista->primoLista();
    while(i <= x->cardinalita())
    {
        if(  !y->appartiene (( x->lista->leggiLista(temp) ))  )
        {
           inserisci(x->lista->leggiLista(temp));
        }
        temp = x->lista->succLista(temp);
        i++;
    }
     i=1;
//Controllo l'altro insieme per la differenza
    temp = y->lista->primoLista();
    while(i<=y->cardinalita())
    {
        if(  !x->appartiene (( y->lista->leggiLista(temp) ))  )
        {
           inserisci(y->lista->leggiLista(temp));
        }
        temp = y->lista->succLista(temp);
        i++;
    }

}


#endif // INSIEME_VETTORE_BOOL_H_INCLUDED
