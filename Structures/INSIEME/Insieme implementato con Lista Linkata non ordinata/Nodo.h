#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;
#include <cstdlib>
#include <iostream>
#include "stdlib.h"


/**
Implementazione della CLasse Nodo alias Cella, con tre elementi: due sono puntatori e un elemento generico
*/
template <class T>
class Nodo
{
private:
    typedef Nodo<T>* posizione;
    typedef T tipoelem;
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
    tipoelem elem;
public:
    tipoelem leggiElem();   //
    void settaElem(tipoelem);   //
    posizione leggiNodoSucc();  //
    void settaNodoSucc(posizione);  //
    posizione leggiNodoPrec();  //
    void settaNodoPrec(posizione);  //
};


//-------------------------------------------------
/**
Osserva e restituisce l'elemento della cella
*/
template <typename T>
T Nodo<T>::leggiElem()
{
    return elem;
}


/**
Modifica l'elemento della cella
*/
template <typename T>
void Nodo<T>::settaElem(tipoelem e)
{
    elem=e;
}


//-----------------------
/**
Osserva e restituisce la cella precedente a quella data
*/
template <typename T>
Nodo<T>* Nodo<T>::leggiNodoPrec()
{
    return prec;
}


/**
Stabilisce la cella precedente a quella data
*/
template <typename T>
void Nodo<T>::settaNodoPrec(posizione p)
{
    prec=p;
}


//--------------------------
/**
Osserva e restituisce la cella successiva a quella data
*/
template <typename T>
Nodo<T>* Nodo<T>::leggiNodoSucc()
{
    return suc;
}


/**
Stabilisce la cella successiva a quella data
*/
template <typename T>
void Nodo<T>::settaNodoSucc(posizione p)
{
    suc=p;
}

//-------------------------------------------------FINE IMPLEMENTAZIONE CLASSE NODO


#endif // NODO_H_INCLUDED
