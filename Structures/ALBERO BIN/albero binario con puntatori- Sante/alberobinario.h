#ifndef ALBEROBINARIO_H_INCLUDED
#define ALBEROBINARIO_H_INCLUDED

#include<iostream>
#include"cella.h"
using namespace std;

template<class T>
class BinAlbero{
public:

    typedef T tipoelem;
    typedef Cella<T>*  Nodo; //puntatore ad una classe di tipo cella
    BinAlbero();//costruttore
    //~BinAlbero(); distruttore

    //operatori
    void creaBinAlbero();
    bool binAlberoVuoto();
    Nodo binRadice();//restituisce la radice dell'albero
    Nodo binPadre(Nodo);//restituisce il padre di Nodo
    Nodo figlioSinistro(Nodo);//restituisce il figlio sinistro di Nodo
    Nodo figlioDestro(Nodo);//restituisce il figlio destro di Nodo
    bool sinistroVuoto(Nodo);
    bool destroVuoto(Nodo);
    void cancSottoBinAlbero(Nodo); //cancella il sottoalbero con radice in Nodo
    tipoelem leggiNodo(Nodo); //restituisce l'elemento di Nodo
    void scriviNodo(Nodo,tipoelem);
    void insBinRadice(Nodo);
    void insFiglioSinistro(Nodo);
    void insFiglioDestro(Nodo);


private:
    int numeroElementi;
    Nodo radice;
};

template<class T>
BinAlbero<T>::BinAlbero(){
    creaBinAlbero();
}

template<class T>
void BinAlbero<T>::creaBinAlbero(){
    numeroElementi=0;
    radice=NULL;//L'albero è vuoto
}

template<class T>
bool BinAlbero<T>::binAlberoVuoto(){
    return(radice==NULL);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binRadice(){
    return (radice);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binPadre(Nodo n){
    if(n!=radice)
        return(n->getDAD());
    else
        return NULL;
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioSinistro(Nodo n){
    return(n->getSX());
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioDestro(Nodo n){
    return(n->getDX());
}

template<class T>
bool BinAlbero<T>::sinistroVuoto(Nodo n){
    return(n->getSX()==NULL);
}

template<class T>
bool BinAlbero<T>::destroVuoto(Nodo n){
    return(n->getDX()==NULL);
}

template<class T>
void BinAlbero<T>::insBinRadice(Nodo n){
    if(binAlberoVuoto()){
        radice=n;
    }
}

template<class T>
void BinAlbero<T>::insFiglioSinistro(Nodo n){
    if(sinistroVuoto(n)){
        n->setSX(new Cella<T>);
        n->getSX()->setDAD(n);
        n->getSX()->setSX(NULL); //il figlio sinistro di n appena inserito non ha figlio sinistro
        n->getSX()->setDX(NULL);
    }
}

template<class T>
void BinAlbero<T>::insFiglioDestro(Nodo n){
    if(destroVuoto(n)){
        n->setDX(new Cella<T>);
        n->getDX()->setDAD(n);
        n->getDX()->setSX(NULL);
        n->getDX()->setDX(NULL);
    }
}

template<class T>
typename BinAlbero<T>::tipoelem BinAlbero<T>::leggiNodo(Nodo n){
    if(n!=NULL)
        return(n->getElemento());
}

template<class T>
void BinAlbero<T>::scriviNodo(Nodo n,tipoelem a){
    if(n!=NULL){
        n->setElemento(a);
        numeroElementi++;
    }
}

template<class T>
void BinAlbero<T>::cancSottoBinAlbero(Nodo n){
    if(n!=NULL){
        if(!sinistroVuoto(n))
            cancSottoBinAlbero(figlioSinistro(n));
        if(!destroVuoto(n))
            cancSottoBinAlbero(figlioDestro(n));
        if(n!=radice){
            Nodo padre=binPadre(n);
            if(figlioSinistro(padre)==n)
                padre->setSX(NULL); //se il nodo da cancellare è il figlio sinistro
            else
                padre->setDX(NULL); //se il nodo da cancellare è il figlio destro
        }else{
            radice=NULL; //se il nodo da cancellare è radice
        }
        numeroElementi--;
    }
}



#endif // ALBEROBINARIO_H_INCLUDED
