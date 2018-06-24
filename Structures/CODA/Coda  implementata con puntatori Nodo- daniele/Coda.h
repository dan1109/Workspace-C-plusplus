#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

//PERFETTAMENTE FUNZIONANTE PILA!!!
#include"Nodo.h"


//-------------------------------------------------INIZIO CLASSE LISTA
//LA LISTA E' STATA TUTTA IMPLEMENTATA. A FUNZIONARE FUNZIONA MA NON CAPISCO CHE ERRORE HO FATTO MA DI VOLTA IN VOLTA PERDO UN NODO.
/**
Classe Coda con l'uso di puntatori, simile alla lista e pila.
*/
template <class T>
class Coda
{
private:
    /**
Definisco il puntatore Nodo come una posizione della pila
*/
    typedef Nodo<T>* posizione;
    /**
Definisco un elemento generico  della pila
*/
    typedef T tipoelem;
    /**
Definisco la posizione iniziale della coda, elemento da eliminare FIFO
*/
    posizione testa;
    /**
Definisco la posizione iniziale della coda, elemento da aggiungere FIFO
*/
    posizione coda;
    /**
Un controllo sugli elementi totali della coda non guasta mai.
*/
    int numElem;
public:
    Coda();
    ~Coda();
    void creaCoda();                        //OK
    bool codaVuota()const;                  //OK
    tipoelem leggiCoda()const;     //OK
    void fuoriCoda();              //OK
    void inCoda(tipoelem e);                   //OK
    int leggiNumElem()const;                //OK
    void stampaCoda();                      //OK
    void eliminaCoda();                     //OK
};
//----------------------------------------------------
/**
 * Costruttore che richiama il metodo creaPila
 */
template<class T>
Coda<T>::Coda() {
    Coda<T>::creaCoda();
}

/**
 * Distruttore
 */
template<class T>
Coda<T>::~Coda() {
}

/**
 * Imposta tutti gli elementi di una pila vuota
 *
 *
 */
template<class T>
void Coda<T> ::creaCoda() {
    numElem = 0;

    testa   = new Nodo<T>;
    testa   = NULL;

    coda    = new Nodo<T>;
    coda    = NULL;
}

/**
 * Verifica se la pila è vuota
 *
 * @return
 */
template<class T>
bool Coda <T>::codaVuota() const {
    return numElem == 0;
}

/**
 * Legge il valore della testa della pila
 *
 * @return valore della pila
 */
template<class T>
T Coda<T>::leggiCoda() const {

    if(codaVuota()!=true) //precondizione
    {
        return coda->leggiElem();
    }

}

/**
 * Crea un elemento temporaneo, ci si imposta il suo valore e il puntatore
 * all'elemento precedente. Il valore temporaneo diventa la testa della pila e
 * il numero degli elementi viene aumentato di uno. Nella coda sia aggiunge alla coda
 *
 * @param e: elemento da inserire
 * @param p: posizione in cui inserire l'elemento
 */
template <class T>
void Coda<T>::inCoda(tipoelem e) {

  posizione temp = new Nodo<T>;
  temp->settaElem(e);
  temp->settaNodoSucc(NULL);
   //ESSENDO L'ULTIMO, NON HA NODI CHE LO SUCCEDONO, PUNTA A NULL
 if(testa == NULL) testa=temp;  // SE LA LISTA HA 0 NODI. TEMP SARA' IL PRIMO NODO TESTA
 if (coda != NULL) coda->settaNodoSucc(temp);  //ALTRIMENTI IL PROSSSIMO DELLA CODA SARA' TEMP(ASSEGNAMENTO PUNTATORI A NODO)

 coda = temp;
 numElem++;
}

/**
 * Associa il headPila ad un valore temporaneo. Successivamente headPila diventa
 * la cella precedente. Infine temp viene cancellato e il numero di elementi
 * della pila diminuisce di uno. Uguale ad una pila la cancellazione
 */
template <class T>
void Coda<T>::fuoriCoda() {

    if (!codaVuota()) { //precondizione
 posizione temp = new Nodo<T>;  // ALLOCAZIONE TEMPORANEO
 temp = testa->leggiNodoSucc();       // DIVENTA TEMP LA TESTA DELLA LISTA, PUNTA A TESTA
 delete testa;  //testa precedente eliminata
 if(testa == NULL) {            // SE NON CI SONO VALORI, TESTA E CODA SONO UGUALI(1 VALORE)
    cout<<"Coda già vuota \n";
    numElem=0;
 }
 testa = temp;  //nuova testa settat, vedi temp= testa->legginodoSucc
 numElem--;
    }
}

/**
 * Stampa tutta la pila dalla testa alla coda
 */
template <class T>
void Coda<T>::stampaCoda() {
  posizione walker = new Nodo<T>;
  walker=testa;
 cout<<"Inizio Stampa Coda:\n";
 while(walker != NULL){  //NULL INDICA FINE LISTA
 cout << "Elemento: "<<walker->leggiElem()<<endl;
 walker=walker->leggiNodoSucc();  //WALKER DIVENTA IL PROSSIMO NODO PUNTATO. ITERAZIONE IN AVANTI
 }
 cout << "Fine Stampa Coda\n\n";
}

/**
 * ???
 */
template <class T>
void Coda<T>::eliminaCoda() {

    while (!codaVuota()) { //precondizione: la pila non deve essere vuota
        fuoriCoda();
    }
}
template <class T>
int Coda<T>:: leggiNumElem() const{
return numElem;}

#endif // PILA_H_INCLUDED
