#ifndef ALBERO_BINARIO_H_INCLUDED
#define ALBERO_BINARIO_H_INCLUDED

// LE FUNZIONI SEGUENTI SONO DA TESTARE. PREGHEREI DI CONTROLLARLE E TESTARLE, PERI PASSO

#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class AlberoBinario;

/**
Il mio nodo ha due puntatori a nodo (figlio sx e figlio dx) e il valore DATO
*/
template<class T>
class Nodo
{
public:
    typedef T tipoelem;
    typedef Nodo<T>* posizione;

    tipoelem leggiDato();//
    AlberoBinario<T> leggiFiglioSX();//
    AlberoBinario<T> leggiFiglioDX();//
    void settaDato(tipoelem);//
    void settaFiglioSX(AlberoBinario<T>);//
    void settaFiglioDX(AlberoBinario<T>);//

private:
    tipoelem DATO;
    AlberoBinario<T> DX;
    AlberoBinario<T> SX;
};

template<class T>
void Nodo<T>::settaDato(tipoelem e)
{
    DATO=e;
}

template<class T>
void Nodo<T>::settaFiglioSX(AlberoBinario<T> p)
{
    SX=p;
}

template<class T>
void Nodo<T>::settaFiglioDX(AlberoBinario<T> p)
{
    DX=p;
}

template<class T>
AlberoBinario<T> Nodo<T>::leggiFiglioDX()
{
    return DX;
}

template<class T>
AlberoBinario<T> Nodo<T>::leggiFiglioSX()
{
    return SX;
}

template<class T>
T Nodo<T>:: leggiDato()
{
    return DATO;
}

/**
Definisco il puntatore a nodo "Albero".
Poiché La ricorsione fa da padrona, l'albero minimo è rad,sx,dx e compone un albero più grande
*/
template<class T>
class AlberoBinario
{
public:

    typedef T tipoelem;
    typedef Nodo<T>* posizione;
    typedef posizione albero;

    bool alberoBinVuoto();//
    void settaAlberoBinVuoto();//
    tipoelem leggiRadice();//
    AlberoBinario<T> sottoAlberoBinSX();//
    AlberoBinario<T> sottoAlberoBinDX();//
    void costruisciAlberoBin(tipoelem,AlberoBinario<T>,AlberoBinario<T>);//
    void stampaSimmetrica();//
    void stampaInPreOrdine();//
    void stampaInPostOrdine();//
    int contaNodi();//
    int ContaFoglie();//
    bool perfettamenteBilanciato();//
    bool ricerca(tipoelem);
    int altezza();//
    void inserimentoBilanciato(tipoelem);//
    bool ricercaBinaria(tipoelem);
    //void settaRadice(tipoelem e);
    //void settaSXRadice(albero);
    //void settaDXRadice(albero);

private:
albero radice;
};

/**
Restituisco il nodo destro di una radice
*/
template<class T>
AlberoBinario<T> AlberoBinario<T>::sottoAlberoBinDX()
{
    AlberoBinario<T> V;
    V.settaAlberoBinVuoto();

    if(alberoBinVuoto()) return V;
    else return radice->leggiFiglioDX();
}

/**
Restituisco il nodo sinistro di una radice
*/
template<class T>
AlberoBinario<T> AlberoBinario<T>::sottoAlberoBinSX()
{
    AlberoBinario<T> V;
    V.settaAlberoBinVuoto();

    if(alberoBinVuoto()) return V;
    else return radice->leggiFiglioSX();
}

/**
Albero settato Vuoto
*/
template<class T>
void AlberoBinario<T>::settaAlberoBinVuoto()
{
    radice=nullptr;
}
/**
Verifica che l'albero sia o meno vuoto
*/
template<class T>
bool AlberoBinario<T>::alberoBinVuoto()
{
    return radice==nullptr;
}
/**
Restituisco l'etichetta del nodo considerato
*/
template<class T>
T AlberoBinario<T>:: leggiRadice()
{
    return radice->leggiDato();
}

/**
Restituisco un Albero dato da altri e due. l'etichetta in input è quella della radice dell'albero in output.
mentre sx è S e dx è D. I miei due alberi
*/
template<class T>
void AlberoBinario<T>::costruisciAlberoBin(tipoelem e,AlberoBinario<T> S,AlberoBinario<T> D)
{
    radice= new Nodo<T>;
    radice->settaDato(e);
    radice->settaFiglioSX(S);
    radice->settaFiglioDX(D);
}

/**
-VISITA SIMMETRICA: RICHIEDE PRIMA LA VISITA DEL
SOTTOALBERO SINISTRO (EFFETTUATA SEMPRE CON LO STESSO
METODO), POI L’ANALISI DELLA RADICE, E POI LA VISITA DEL
SOTTOALBERO DESTRO
*/
template<class T>
void AlberoBinario<T>::stampaSimmetrica()
{
    if(!alberoBinVuoto())
    {
        sottoAlberoBinSX().stampaSimmetrica();
        cout<<radice->leggiDato()<<" ";
        sottoAlberoBinDX().stampaSimmetrica();
    }
}
/**
STAMPA
-VISITA IN PRE-ORDINE: SI APPLICA AD UN ALBERO NON VUOTO E
RICHIEDE DAPPRIMA L’ANALISI DELLA RADICE DELL’ALBERO E,
POI, LA VISITA, EFFETTUATA CON LO STESSO METODO, DEI DUE
SOTTOALBERI, PRIMA IL SINISTRO, POI IL DESTRO*/
template<class T>
void AlberoBinario<T>::stampaInPreOrdine()
{
     if(!alberoBinVuoto())
    {
        cout<<radice->leggiDato()<<" ";
        sottoAlberoBinSX().stampaInPreOrdine();
         sottoAlberoBinDX().stampaInPreOrdine();
    }
}
/**STAMPA
-VISITA IN POST-ORDINE: SI APPLICA AD UN ALBERO NON VUOTO E
RICHIEDE DAPPRIMA LA VISITA, EFFETTUATA CON LO STESSO
METODO, DEI SOTTOALBERI, PRIMA IL SINISTRO E POI IL DESTRO,
E, IN SEGUITO, L’ANALISI DELLA RADICE DELL’ALBERO*/
template<class T>
void AlberoBinario<T>::stampaInPostOrdine()
{
    if(!alberoBinVuoto())
    {
        sottoAlberoBinSX().stampaInPostOrdine();
        sottoAlberoBinDX().stampaInPostOrdine();
        cout<<radice->leggiDato()<<" ";
    }
}

/**
restituisce il numero dei nodi dell'albero contando ricorsivamente i nodi dell'albero sx e dx più uno ogni volta
la radice dell'albero che si considera
*/
template<class T>
int AlberoBinario<T>::contaNodi()
{
    AlberoBinario<T> S;
    S=sottoAlberoBinSX();
    AlberoBinario<T> D;
    D=sottoAlberoBinDX();
    if(alberoBinVuoto()) return 0;
    else return (  1+ D.contaNodi() + S.contaNodi()  );
}

/**
restituisce il numero dei nodi dell'albero foglia. Se c'è solo la radice==foglia e restituisce 1.
Altrimenti continua il conteggio ricorsivo dei due sotto alberi sommandoli
*/
template<class T>
int AlberoBinario<T>::ContaFoglie()    //restituisce il numero delle foglie dell'albero
{
    AlberoBinario<T> D;
    AlberoBinario<T> S;
    D=sottoAlberoBinDX();
    S=sottoAlberoBinSX();
    if(alberoBinVuoto()) return 0;
    else
    {
        if(S.alberoBinVuoto()==true && D.alberoBinVuoto()==true)
            return 1;
       else return (  D.ContaFoglie() + S.ContaFoglie()  );
    }
}

/**
Un albero è perfettamente bilanciato se i nodi dei sottoalberi sono ben distribuiti (se dispari falso)
*/
template<class T>
bool AlberoBinario<T>::perfettamenteBilanciato()
{
    AlberoBinario<T> D;
    AlberoBinario<T> S;
    D=sottoAlberoBinDX();
    S=sottoAlberoBinSX();
    //Restituisce TRUE se l'albero è perfettamente bilanciato
    if( alberoBinVuoto()) return true;  	//Oppure ERROR, secondo la definizione
    else
    {
        if(S.alberoBinVuoto() && D.alberoBinVuoto()) //Praticamente: se il nodo è una foglia..
            return true;
        else
        {
             if(!S.alberoBinVuoto() && !D.alberoBinVuoto()) //Se il nodo ha tutti e due i figli..
                return (S.perfettamenteBilanciato() && D.perfettamenteBilanciato());
            else return false;
        }
    }
}

/**
Verifica che il valore X da ricerca sia presente nell'albero controllando il valore OR sul sottoalbero sx e dx
*/
template<class T>
bool AlberoBinario<T>::ricerca(tipoelem X)
{
    AlberoBinario<T> D;
    AlberoBinario<T> S;
    D=sottoAlberoBinDX();
    S=sottoAlberoBinSX();

    if(alberoBinVuoto())
        return false;
    else
    {
        if(X==leggiRadice())
            return true;
        else
            return (S.ricerca(X) || D.ricerca(X));
    }
}
/**
Restituisce altezza dell'albero
*/
template<class T>
int AlberoBinario<T>::altezza() //Restituisce l'altezza di un nodo (vedere definizione di altezza)
{
    AlberoBinario<T> D;
    AlberoBinario<T> S;
    D=sottoAlberoBinDX();
    S=sottoAlberoBinSX();

     int ALTD=0,ALTS=0;
     if(alberoBinVuoto())   return -1;
     else
     {
         ALTS= S.altezza();
         ALTD= D.altezza();
         if(ALTS>ALTD)  return(ALTS+1);
         else return (ALTD+1);
     }
}

/**
Restituisce un Albero perfettamente bilanciato, dopo aver inserito un valore E
*/
template<class T>
void AlberoBinario<T>::inserimentoBilanciato(tipoelem e)    //Costruisce un albero binario di ricerca (un albero "ordinato")
{
    AlberoBinario<T> V;
    V.settaAlberoBinVuoto();

    AlberoBinario<T> D;
    AlberoBinario<T> S;
    D=sottoAlberoBinDX();
    S=sottoAlberoBinSX();

    if(alberoBinVuoto())
    {
        radice=new Nodo<T>;      //chiede l'indirizzo di una cella di memoria libera
        radice->settaDato(e);
        radice->settaFiglioSX(V);
        radice->settaFiglioDX(V);
    }
    else
    {
        if(e<radice->leggiDato())
        {
            S.inserimentoBilanciato(e);
            radice->settaFiglioSX(S);
        }
        else
        {
            D.inserimentoBilanciato(e);
            radice->settaFiglioDX(D);
        }
    }
}

/**
Ricerca in log base 2 di un elemento nell'albero.
Verifica se un valore è maggiore di un altro. Se minore ricerca a sinistra. Altrimenti a destra
*/
template<class T>
bool AlberoBinario<T>::ricercaBinaria(tipoelem X)   //Ricerca dicotomica (o binaria) per alberi binari di ricerca (ordinati)
{
    if(alberoBinVuoto())    return false;
    else
    {
        if(X==radice->leggiDato())   return true;
        else
        {       AlberoBinario<T> D;
                AlberoBinario<T> S;
                D=sottoAlberoBinDX();
                S=sottoAlberoBinSX();
            if(X<radice->leggiDato())
                return ( S.ricercaBinaria(X) );
            else
                return ( D.ricercaBinaria(X) );
        }
    }
}


#endif // ALBERO_BINARIO_H_INCLUDED
