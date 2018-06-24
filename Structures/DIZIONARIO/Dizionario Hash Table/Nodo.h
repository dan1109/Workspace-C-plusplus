#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;
#include <cstdlib>
#include <iostream>
#include "stdlib.h"

/**
Implementazione della CLasse Nodo alias Cella, con tre elementi: due sono puntatori e un elemento generico
*/
template <class K,class T>
class Nodo
{
    private:
    typedef Nodo<K,T>* posizione;
/**
Puntatore alla cella precedente
*/
    posizione prec;
/**
Puntatore alla cella successiva
*/
    posizione suc;
/**
Valore interno della cella attuale
*/
    T valore;
/**
chiave interno della cella attuale
*/
    K chiave;

    public:

    T leggiValore();
    K leggiChiave();
    void settaValore(T);
    void settaChiave(K);

    posizione leggiNodoSucc();  //
    void settaNodoSucc(posizione);  //
    posizione leggiNodoPrec();  //
    void settaNodoPrec(posizione);  //
};
//............................................................................................................................
//OSTREAM FUNZIONANTE E TESTATO
/**
Prototipo sovraccarico operatore<< per stampare un Buket chiave valore
*/
template <typename K,typename T>
ostream& operator<<(ostream&, Nodo<K,T>&);
/**
Stampa Bucket chiave valore
*/
template <typename K,typename T>
ostream& operator<<(ostream& os , Nodo<K,T>& a)
{
    os<<"Key: "<<a.leggiChiave()<<",Val: "<<a.leggiValore();
    return os;
}
//CONFRONTO == FUNZIONANTE
/**
Prototipo sovraccarico operatore== per confronto di due Bucket
*/
template <typename K,typename T>
bool operator==(Nodo<K,T>&, Nodo<K,T>&);
/**
Confronto di due Bucket (chiave==chiave2 e val==val2)
*/
template <typename K,typename T>
bool operator==(Nodo<K,T>& a, Nodo<K,T>& b)
{
    bool flag=false;
    if(a.leggiChiave()==b.leggiChiave() && a.leggiValore()==b.leggiValore() )
    {
        flag=true;
    }
    return flag;
}
//......................................................................................................................................
template <typename K,typename T>
K Nodo<K,T>::leggiChiave()
{
    return chiave;
}
template <typename K,typename T>
T Nodo<K,T>::leggiValore()
{
    return valore;
}
template <typename K,typename T>
void Nodo<K,T>::settaValore(T val)
{
    valore=val;
}
template <typename K,typename T>
void Nodo<K,T>::settaChiave(K key)
{
    chiave=key;
}


//-----------------------
/**
Osserva e restituisce la cella precedente a quella data
*/
template <typename K,typename T>
Nodo<K,T>* Nodo<K,T>::leggiNodoPrec()
{
    return prec;
}


/**
Stabilisce la cella precedente a quella data
*/
template <typename K,typename T>
void Nodo<K,T>::settaNodoPrec(posizione p)
{
    prec=p;
}


//--------------------------
/**
Osserva e restituisce la cella successiva a quella data
*/
template <typename K,typename T>
Nodo<K,T>* Nodo<K,T>::leggiNodoSucc()
{
    return suc;
}


/**
Stabilisce la cella successiva a quella data
*/
template <typename K,typename T>
void Nodo<K,T>::settaNodoSucc(posizione p)
{
    suc=p;
}

//-------------------------------------------------FINE IMPLEMENTAZIONE CLASSE NODO


#endif // NODO_H_INCLUDED

