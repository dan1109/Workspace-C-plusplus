#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include"Nodo.h"

//LISTA OTTIMIZZATA PER INSIEME E GENERALMENTE MIGLIORATA LA VISIBILITA'
//-------------------------------------------------INIZIO CLASSE LISTA
//LA LISTA E' STATA TUTTA IMPLEMENTATA. A FUNZIONARE FUNZIONA MA NON CAPISCO CHE ERRORE HO FATTO MA DI VOLTA IN VOLTA PERDO UN NODO.

/**
Classe Lista con l'uso di puntatori.
 */
template <class T>
class Lista {
private:
    /**
Definisco il puntatore Nodo come una posizione della lista
     */
    typedef Nodo<T>* posizione;
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
    void insSuccLista(posizione, tipoelem); //TESTATA
    bool fineLista(posizione)const; // TESTATA FUNZIONA
    int leggiNumElem()const; //TESTATA
    void creaLista(); //TESTATA
    bool listaVuota()const; //TESTATA
    posizione primoLista()const; //TESTATA
    tipoelem leggiLista(posizione)const; //
    void scriviLista(tipoelem, posizione); //
    posizione succLista(posizione)const; //
    posizione precLista(posizione)const; //
};
//----------------------------------------------------

/**
Usato da ~Lista, a sua volta usa ricorsivamente cancLista
 */
template<class T>
void Lista<T>::deleteLista() {
    bool flag=false;
    posizione nuovoNodo = new Nodo<T>;
    nuovoNodo = testa;
    cout<<"\nCancella Tutto:\n";
    while (nuovoNodo!= NULL && listaVuota()==false)
        {
            Lista<T>::cancLista(nuovoNodo);
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
template<class T>
void Lista<T>::cancLista(posizione p) {
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
                numElem--;
                cout<<"Canc el.\t";
                delete p;
                canc=true;
            }
            else if(p==temp)
            {   precLista(p)->settaNodoSucc(succLista(p));
                succLista(p)->settaNodoPrec(precLista(p));
                numElem--;
                cout<<"Canc el.\t";
                delete p;
                canc=true;
            }
        temp = succLista(temp); //incremento del while(FINO AL PENULTIMO ELEMENTO
       }
        if(temp==p)
        {
            precLista(p)->settaNodoSucc(NULL);
            numElem--;
            cout<<"Canc el.\t";
            delete p;
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
template<class T>
Lista<T>::~Lista() {
    Lista<T>::deleteLista();
}

/**
Costruttore di default usa creaLista
 */
template<class T>
Lista<T>::Lista() {
    Lista<T>::creaLista();
}

/**
verifica che il nodo p sia l'ultimo in lista, verificando se ha un nodo successivo o precedente.
 * @param Nodo p
 */
template<class T>
bool Lista <T>::fineLista(posizione p) const {

posizione temp= new Nodo<T>;
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

template<class T>
int Lista <T>::leggiNumElem() const {
    return numElem;
}

/**
Verifica se il numELem � >=0
 */
template<class T>
bool Lista <T>::listaVuota() const {
    return numElem == 0;
}

/**
 * Legge il valore della lista in posizione p
 *
 * @param p: posizione del valore da leggere
 * @return valore della lista in posizione p
 */
template<class T>
T Lista<T>::leggiLista(posizione p) const {
    if(!listaVuota())
    {
      return p->leggiElem();
    }
    else if (listaVuota())
    {
        cout<<"Restituisco 0 perché non puoi leggere una lista vuota,riempila!\n";
        return 0;
    }
}

/**
 * Scrive il valore e nella lista in posizione p
 *
 * @param e: valore da inserire nella lista
 * @param p: posizione in cui scrivere il valore e
 */
template<class T>
void Lista<T>::scriviLista(tipoelem e, posizione p) {
    if(!listaVuota())
    {
      p->settaElem(e);
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
template<class T>
Nodo<T>* Lista<T>::primoLista() const {
    return testa;
}

/**
 * Restituisce l'elemento successivo alla posizione dell'elemento p
 *
 * @param p: posizione dell'elemento di cui si vuole sapere il successivo
 * @return valore della posizione successiva
 */
template <class T>
Nodo<T>* Lista<T>::succLista(posizione p) const {
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
template <class T>
Nodo<T>* Lista<T>::precLista(posizione p) const {
    if(listaVuota())
    {
        //cout<<"Una lista vuota non ha precedente!\n";
        return 0;
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
template <typename T>
void Lista<T>::creaLista() {
    sentinella=new Nodo<T>;
    testa= new Nodo<T>;
    numElem=0;
    sentinella->settaNodoPrec(NULL);
    sentinella->settaNodoSucc(testa);
    testa->settaNodoSucc(NULL);
    cout << "Lista creata\n";
}

//FINALMENTE E' STATO FIXATO

/**
Aggiunge alla fine della lista un nodo p
 *
 *@param nodo da inserire, e; elemento da inserire in p
 */
template <typename T>
void Lista<T>::insSuccLista(posizione p, tipoelem e) {

   if(listaVuota()==true)
   {
       p=new Nodo<T>;
       p->settaElem(e);
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
            p=new Nodo<T>;
            p->settaElem(e);
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
template <typename T>
void Lista<T>::stampaLista() {
    posizione nuovoNodo = new Nodo<T>;
    nuovoNodo = testa;
    cout<<"[";
    if (!listaVuota()) {
        while (succLista(nuovoNodo)!=NULL) {
            if (nuovoNodo == testa) {
                cout << leggiLista(nuovoNodo) << " ,";
            } else {
                cout <<leggiLista(nuovoNodo) << " ,";
            }
            nuovoNodo = succLista(nuovoNodo);
            //fa 37 volte la stessa cosa?
        }//fine while.
        //se il while non è mai iniziato vuol dire che esiste un unico elemento, la testa!
        if (nuovoNodo == testa && numElem==1) {
            cout << nuovoNodo->leggiElem();
        } else if (nuovoNodo != testa &&  fineLista(nuovoNodo)==true) {
            cout << nuovoNodo->leggiElem();
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
