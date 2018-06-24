/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CODAPO_H_
#define _CODAP_H_

#include <iostream>
using namespace std;
#include "assert.h"

/**
Coda con priorità di un solo argomento template. E' un albero binario implementato come Heap
*/
template < class T > class CodaP {

public:
/**
Ridefinizione del tipo generico T come _tipoelem
*/
  typedef T _tipoelem;

  CodaP ();
  CodaP (int);
  ~CodaP ();
  void creaPrioriCoda ();
  void inserisci (_tipoelem);
  _tipoelem min ();     //Il minimo è anche la radice dell'albero
  void cancellaMin ();

  //Funzioni di servizio:
  void stampa();    //FUNZIONA
  int livello();    //FUNZIONA
  int altezza();    //FUNZIONA
  int foglie(); //FUNZIONA

private:
  int MAXLUNG;
  _tipoelem *heap;
/** Ultimo è il cursore dell'ultimo elemento in array*/
  int ultimo;

  void fixUp ();
  void fixDown (int, int);
};
/**
Contare le foglie significa vedere quanti nodi non hanno figli
*/
template < class T >
int CodaP<T>::foglie()
{
   int leafs=0;
   int flag=0;
   int i=0;
    while(i<ultimo) //Stampa solo i valori inseriti, non fino a maxlungh che possono essere vuoti
    {
//Le i sono messe in perfetto ordine
        if ( (i+1)*2-1<ultimo )
        {
            //NESSUNA ISTRUZIONE
        }
        else
        {
            flag++;
        }
        if((i+1)*2<ultimo)
        {
            //NESSUNA ISTRUZIONE
        }
        else
        {
            flag++;
        }
        if(flag%2==0 && flag>0)
        {
            leafs++;
        }
        flag=0; //RISETTO FLAG PER CONTROLLO FIGLI DEI NODI SUCC.
        i++;
    }
    return leafs;
}


template < class T >
int CodaP<T>::altezza()
{
    return livello()-1;
}

template < class T >
int CodaP<T>::livello()
{
    bool exit=false;
    int liv=0;
    int quoz=0;
    int i=ultimo;
    while(i>0 && exit==false)
    {
        quoz=i/2;
        liv++;
        if(quoz==1)
        {
            exit=true;
        }
        i=quoz;
    }
    return liv+1;
}

//--------------------------------------------------------------------------
/**
Stampa gli elementi dell'Albero in quest'ordine:
i-esimo elemento, figlio sx, figlio dx
*/
template < class T >
void CodaP<T>::stampa()
{
    cout<<"Stampa CodaP:[\n";
    int i=0;
    while(i<ultimo) //Stampa solo i valori inseriti, non fino a maxlungh che possono essere vuoti
    {
//Le i sono messe in perfetto ordine
        cout<<heap[i]<<",\t";               //STAMPA I-ESIMO ELEMENTO DELL'ALBERO
        if ( (i+1)*2-1<ultimo )
        {
            cout<<heap[(i+1)*2-1]<<"Sx,\t";     //STAMPA IL FIGLIO SX
        }
        else
        {
            cout<<"- Sx,\t";    //NON C'E'
        }
        if((i+1)*2<ultimo)
        {
            cout<<heap[(i+1)*2]<<"Dx;\n";       //STAMPA IL FIGLIO DX
        }
        else
        {
            cout<<"- Dx;\n";    //NON C'E'
        }
        i++;
    }
    cout<<"]\n";
}

/**
Costruttore: prende di default 100 elementi interi che sono la MAXLUNG della mia coda. Heap ,
puntatore di _tipoelem alloca un array in memoria di dimensione MAXLUNG e invoca creaPrioriCoda()
*/
template < class T > CodaP < T >::CodaP ():MAXLUNG (100) {
  heap = new _tipoelem[MAXLUNG];
  creaPrioriCoda ();
};

/**
Costruttore di copia con MAXLUNG variabile e non fissa a 100
*/
template < class T > CodaP < T >::CodaP (int maxN): MAXLUNG (maxN) {
  heap = new _tipoelem[MAXLUNG];
  creaPrioriCoda ();
};

/**
Dealloca il Distruttore l'array monodimensionale di tipo _tipoelem usato per l'inserimento.
*/
template < class T > CodaP < T >::~CodaP () {
  delete[]heap;
};

/**
Imposta ultimo a 0(cursore)
*/
template < class T > void CodaP < T >::creaPrioriCoda () {
  ultimo = 0;
};

/**
Se ultima posizione  è minore della capacità dell'array, Inserisci in posizione ultimo e , poi fixup
*/
template < class T > void CodaP < T >::inserisci (_tipoelem e) {
  assert (ultimo < MAXLUNG);
  heap[++ultimo - 1] = e;
  //cout<<"Posizione in cui inserito:"<<(++ultimo - 1)<<endl;
  fixUp ();
};

/**
Se ultimo non è la radice, restituisci heap in posizione 0
*/
template < class T > typename CodaP < T >::_tipoelem CodaP < T >::min () {
  assert (ultimo != 0);
  return (heap[0]);
};

/**
Se ultimo non è la radice, heap in  posizione radice  assume il valore di heap in posizione penultima.
decrementa ultimo di 1 e fa fixdown di ultimo di 1
*/
template < class T > void CodaP < T >::cancellaMin () {
  assert (ultimo != 0);

  heap[0] = heap[ultimo - 1];

  ultimo--;
  fixDown (1,ultimo);

};


/**Per ripristinare i vincoli dello heap quando la priorità di un nodo è      *
 * cresciuta, ci spostiamo nello heap verso l'alto, scambiando, se necessario,*
 * il nodo in posizione k con il suo nodo padre (in posizione k/2),           *
 * continuando fintanto che heap[k]<heap[k/2] oppure fino a quando            *
 * raggiungiamo la cima dello heap.                                           */

template < class T > void CodaP < T >::fixUp () {
  int k = ultimo;

  while (k > 1 && heap[k - 1] < heap[k / 2 - 1]) {
      _tipoelem tmp;
      tmp = heap[k - 1];
      heap[k - 1] = heap[k / 2 - 1];
      heap[k / 2 - 1] = tmp;
      k = k / 2;
    }

}

/** Per ripristinare i vincoli dello heap quando la priorità di un nodo si è  *
 * ridotta, ci spostiamo nello heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */

template < class T > void CodaP < T >::fixDown (int k, int N) {

  short int scambio = 1;

  while (k <= N / 2 && scambio) {
      int j = 2 * k;
      _tipoelem tmp;
      if (j < N && heap[j - 1] > heap[j])
				j++;
      if (scambio = (heap[j - 1] < heap[k - 1])) {
				tmp = heap[k - 1];
				heap[k - 1] = heap[j - 1];
				heap[j - 1] = tmp;
				k = j;
			}
  }
};


#endif /* _CODAP_H_ */
