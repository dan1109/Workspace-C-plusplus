#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include"Nodo.h"

//LISTA OTTIMIZZATA PER INSIEME E GENERALMENTE MIGLIORATA LA VISIBILITA'
//-------------------------------------------------INIZIO CLASSE LISTA
//LA LISTA E' STATA TUTTA IMPLEMENTATA. A FUNZIONARE FUNZIONA MA NON CAPISCO CHE ERRORE HO FATTO MA DI VOLTA IN VOLTA PERDO UN NODO.

/**
Classe Lista con l'uso di puntatori.
 */
template <class K, class T>
class Lista {
private:
    /**
Definisco il puntatore Nodo come una posizione della lista
     */
    typedef Nodo<K,T>* posizione;
    /**
Definisco un elemento generico  della lista
     */
    typedef T tipoelem;
    /**
Definisco la posizione iniziale della lista, unica cosa importante della lista stessa
     */
    posizione testa;

    posizione sentinella;
    /**
Un controllo sugli elementi totali della lista non guasta mai.
     */
    int numElem;
public:
    Lista(); // TESTATA
    ~Lista(); // TESTATA
    void stampaLista(); // TESTATA
    void deleteLista(); // TESTATA
    void cancLista(posizione); // FIXATO, SO ELIMINARE L'ULTIMO. FUNZIONA

    void insSuccLista(posizione, T,K); //TESTATA

    bool fineLista(posizione)const; // TESTATA FUNZIONA
    int leggiNumElem()const; //TESTATA
    void creaLista(); //TESTATA
    bool listaVuota()const; //TESTATA
    posizione primoLista()const; //TESTATA

    K leggiChiavLista(posizione)const; //
    T leggiValLista(posizione)const; //

    void scriviLista(tipoelem, posizione,K); //
    posizione succLista(posizione)const; //
    posizione precLista(posizione)const; //
};
//----------------------------------------------------

/**
 * Legge il valore della lista in posizione p
 *
 * @param p: posizione del valore da leggere
 * @return valore della lista in posizione p
 */
template <class K, class T>
T Lista<K,T>::leggiValLista(posizione p) const {
    T errore;
    if(!listaVuota())
    {
      return p->leggiValore();
    }
    else if (listaVuota())
    {
        cout<<"Restituisco 0 perché non puoi leggere una lista vuota,riempila!\n";
        return errore;
    }
}

/**
 * Legge il valore della lista in posizione p
 *
 * @param p: posizione del valore da leggere
 * @return valore della lista in posizione p
 */
template <class K, class T>
K Lista<K,T>::leggiChiavLista(posizione p) const {
    K errore;
    if(!listaVuota())
    {
      return p->leggiChiave();
    }
    else if (listaVuota())
    {
        cout<<"Restituisco 0 perché non puoi leggere una lista vuota,riempila!\n";
        return errore;
    }
}

/**
Usato da ~Lista, a sua volta usa ricorsivamente cancLista
 */
template <class K, class T>
void Lista<K,T>::deleteLista() {
    bool flag=false;
    posizione nuovoNodo = new Nodo<K,T>;
    nuovoNodo = testa;
    cout<<"\nCancella Tutto:\n";
    while (nuovoNodo!= NULL && listaVuota()==false)
        {
            Lista<K,T>::cancLista(nuovoNodo);
            nuovoNodo = succLista(nuovoNodo);
        }
    if(listaVuota())
    {
        cout<<"Non ci sono el.\n";
    }
    numElem = 0;
}

/**
Cancella il Nodo p se c'� in lista e diminuisce di 1 gli elementi tot.
 */
template <class K, class T>
void Lista<K,T>::cancLista(posizione p) {
   bool canc=false;
   if(listaVuota())
   {
       cout<<"Non ci sono el. da canc.\n";
   }
   if(!listaVuota())
   {    posizione temp = testa;
       while(succLista(temp)!=NULL && canc==false)
       {   if(p==testa)
            {   sentinella->settaNodoSucc(succLista(p));
                (succLista(p))->settaNodoPrec(sentinella);
                testa = succLista(p);
                delete p;
                numElem--;
                cout<<"Canc el.\t";
                canc=true;
            }
            else if(p==temp)
            {   precLista(p)->settaNodoSucc(succLista(p));
                succLista(p)->settaNodoPrec(precLista(p));
                numElem--;
                 delete p;
                cout<<"Canc el.\t";
                canc=true;
            }
        temp = succLista(temp); //incremento del while(FINO AL PENULTIMO ELEMENTO
       }
        if(temp==p)
        {
            precLista(p)->settaNodoSucc(NULL);
            numElem--;
             delete p;
            cout<<"Canc el.\t";
            canc=true;
        }
       if(canc==false)  //se temp!= p in tutta la lista evidentemente p non c'è
       {
           cout<<"Non ho eliminato nulla, pos NON era in lista.\n";
       }
   }
}//fine implementazione

/**
Distruttore di default usa deleteLista che usa ricorsivamente cancLista
 */
template <class K, class T>
Lista<K,T>::~Lista() {
    Lista<K,T>::deleteLista();
}

/**
Costruttore di default usa creaLista
 */
template <class K, class T>
Lista<K,T>::Lista() {
    Lista<K,T>::creaLista();
}

/**
verifica che il nodo p sia l'ultimo in lista, verificando se ha un nodo successivo o precedente.
 * @param Nodo p
 */
template <class K, class T>
bool Lista<K,T>::fineLista(posizione p) const {

posizione temp= new Nodo<K,T>;
temp=testa;
while(listaVuota()==false && temp->leggiNodoSucc()!=NULL)
    {
        temp= succLista(temp);
    }
// finito tutto il ciclo.
if(temp==p && listaVuota()==false)
    {
        return true;
    }
else
    {
        return false;
    }
}

template <class K, class T>
int Lista<K,T>::leggiNumElem() const {
    return numElem;
}

/**
Verifica se il numELem � >=0
 */
template <class K, class T>
bool Lista<K,T>::listaVuota() const {
    return numElem == 0;
}



/**
 * Scrive il valore e nella lista in posizione p
 *
 * @param e: valore da inserire nella lista
 * @param p: posizione in cui scrivere il valore e
 */
template <class K, class T>
void Lista<K,T>::scriviLista(tipoelem e, posizione p,K k) {
    if(!listaVuota())
    {
      p->settaChiave(k);
      p->settaValore(e);
    }
     else if (listaVuota())
    {
        cout<<"Non puoi modificare una lista vuota,riempila!\n";
    }
}

/**
 * Restituisce la posizione del valore sentinella della lista
 *
 * @return primoLista
 */
template <class K, class T>
Nodo<K,T>* Lista<K,T>::primoLista() const {
    return testa;
}

/**
 * Restituisce l'elemento successivo alla posizione dell'elemento p
 *
 * @param p: posizione dell'elemento di cui si vuole sapere il successivo
 * @return valore della posizione successiva
 */
template <class K, class T>
Nodo<K,T>* Lista<K,T>::succLista(posizione p) const {
    if (listaVuota())
    {
        //cout<<"Una lista vuota non ha successivo!\n";
        return 0;
    }
    if (!listaVuota())
    {
        return p->leggiNodoSucc();
    }

}

/**
 * Restituisce l'elemento precedente alla posizione dell'elemento p
 *
 * @param p: posizione dell'elemento di cui si vuole sapere il precedente
 * @return valore della posizione precedente
 */
template <class K, class T>
Nodo<K,T>* Lista<K,T>::precLista(posizione p) const {
    if(listaVuota())
    {
        //cout<<"Una lista vuota non ha precedente!\n";
        return p;
    }
    if(!listaVuota())
    {
        return p->leggiNodoPrec();
    }

}
//-----------------------------------------------------
/**
Crea una lista di 0 elementi e la testa non ha un successivo
 */
template <class K, class T>
void Lista<K,T>::creaLista() {
    sentinella=new Nodo<K,T>;
    testa= new Nodo<K,T>;
    numElem=0;
    sentinella->settaNodoPrec(NULL);
    sentinella->settaNodoSucc(testa);
    testa->settaNodoSucc(NULL);
    cout << "Lista creata\t";
}

//FINALMENTE E' STATO FIXATO

/**
Aggiunge alla fine della lista un nodo p
 *
 *@param nodo da inserire, e; elemento da inserire in p
 */
template <class K, class T>
void Lista<K,T>::insSuccLista(posizione p, T e, K k) {

   if(listaVuota()==true)
   {
       p=new Nodo<K,T>;
       p->settaValore(e);
       p->settaChiave(k);
       numElem++;   //incremento el.
       p->settaNodoSucc(NULL);
       p->settaNodoPrec(sentinella);
       testa=p; //p diventa testa della lista
   }
   else
    {
        posizione temp = testa;
        while(fineLista(temp)!=true)
        {
            temp = succLista(temp);
        }
        //arrivo a fine lista... e aggiungo p
            p=new Nodo<K,T>;
        p->settaValore(e);
        p->settaChiave(k);
            numElem++;   //incremento el.
            p->settaNodoSucc(NULL);

            p->settaNodoPrec(temp);
            temp->settaNodoSucc(p);
    }

}

//FIXATO MI ERO DIMENTICATO L'ULTIMA ASSEGNAZIONE CHE SCEMO. HO FIXATO ANCORA MEGLIO LE ISTRUZIONI DI STAMPA

/**
Stampa tutta la lista di Nodi, di preciso i suoi valori
 */
template <class K, class T>
void Lista<K,T>::stampaLista() {
    posizione nuovoNodo = new Nodo<K,T>;
    nuovoNodo = testa;
    cout<<"[";
    if (!listaVuota()) {
        while (succLista(nuovoNodo)!=NULL) {
            if (nuovoNodo == testa) {
                cout<<"Key: "<<nuovoNodo->leggiChiave()<<",Val: "<<nuovoNodo->leggiValore()<<",";
            } else {
               cout<<"Key: "<<nuovoNodo->leggiChiave()<<",Val: "<<nuovoNodo->leggiValore()<<",";
            }
            nuovoNodo = succLista(nuovoNodo);
            //fa 37 volte la stessa cosa?
        }//fine while.
        //se il while non è mai iniziato vuol dire che esiste un unico elemento, la testa!
        if (nuovoNodo == testa && numElem==1) {
            cout<<"Key: "<<nuovoNodo->leggiChiave()<<",Val: "<<nuovoNodo->leggiValore();
        } else if (nuovoNodo != testa &&  fineLista(nuovoNodo)==true) {
             cout<<"Key: "<<nuovoNodo->leggiChiave()<<",Val: "<<nuovoNodo->leggiValore();
        }
        //AGGIUNTA DI QUESTA ISTRUZIONE PER IL FIX
    } //fine primo se
    else if (listaVuota()){
        cout << "...Vuoto";
    }
    else if (numElem<0)
    {
        cout<<"Elementi negativi? Cosa cavolo hai combinato mo?? !"<<numElem<<"  elementi in lista!"<<endl;
    }
        cout<<"]\n";
}


#endif // LISTA_H_INCLUDED

