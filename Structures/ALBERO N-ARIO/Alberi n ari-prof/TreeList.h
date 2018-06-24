/***************************************************************************
 *   Copyright (C) 2012 by Nicola Di Mauro (edit by Daniele Bufalo         *
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

#ifndef TREELIST_H
#define TREELIST_H

#include "list_vector.h"
#include "Tree.h"


#define MAXNODES 100    //NUMERO MASSIMO DI NODI DELL'ALBERO N ARIO
#define ESITO_NEG -1    //esito negativo di una funzione int
/**
Il seguente albero n-ario è stato realizzato con array monodimensionale di Record(di nodi)
Ogni nodo contiene informazioni relative a : livello,settaggio a vuoto/occupato,lista di cursori ai figli... del nodo.
*/
template<class I>
class TreeList : public Tree<I, int> {
 public:

 /** sarebbe l'etichetta di template, di un certo valore*/
	typedef I item;
/** cursore intero al nodo nella lista*/
	typedef int node;

	// Costruttori e distruttore
	TreeList(){
		create();
	};

	virtual void create () ;                //crea albero
	virtual bool empty () const ;           //L'albero è vuoto in questa posizione?
	virtual void insRoot (node) ;           //inserisci un intero come radice
	virtual node root () const ;            //La posizione della radice
	virtual node parent (node) const ;      //La posizione del padre
	virtual bool leaf (node) const ;        //posizione di un nodo foglia?
	virtual node firstChild (node) const ;  //primo figlio
	virtual bool lastSibling (node) const ; //il nodo considerato è l'ultimo fratello?
	virtual node nextSibling (node) const ; // chi è il prossimo fratello di nodo?
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, TreeList &) ;
	//	virtual void insSubTree (node, TreeList &) ;
	virtual void removeSubTree (node) ;     //rimuovi sottoalbero

	void insFirst(node, item);  //inserisci primo nodo e item in una pos
	void ins(node, item);          //uguale a sopra

	virtual void writeNode (node, item) ;   //setta nodo
	virtual item readNode (node) const ;    //leggi nodo item

	void print() const;
	void printChilds( List_vector<int> L);
    int leggiNumNodes()const;
    int leggiNumLeafs()const;
    bool hasParent(node n)const;
    int nodes_level(int lv);
    int level();
    int higth();
    void ins_autom();
 private:
         /** lista di posizioni intere*/
	typedef List_vector<int>::position position_list;
	/**elemento Template, booleano usato, LISTA DI CURSORI*/
	struct Record {
	    /**contenuto della etichetta del nodo*/
		item e;                     //elemento
		/**livello del nodo*/
		int lv_e;                   //livello su cui è annidato e
		/**nodo vuoto o usato*/
		bool used;                  //nodo effettivamente usato
        /** lista di posizioni intere di figli dello stesso array nodes, che dichiareremo dopo*/
		List_vector<int> childs;    //ecco il fattore ricorsivo
	};

	/**array monodimensionale di record. */
	Record nodes[MAXNODES];
	/**riferimento cursore alla radice*/
	node _root;
	/**nodi(quantità) effettivamente usati/inseriti rispetto a MAXNODES*/
	int numNodes;
};

/**inserimento automatico nell'albero*/
template <class I>
void TreeList<I>::ins_autom()
{
    TreeList<char>::node n;
	insRoot(n);
	writeNode(root(),'a');

	insFirst(root(), 'b');
	insFirst(root(), 'c');

	n = root();
	n = firstChild(n);

	ins(n, 'd');

	n = root();
	n = firstChild(n);
	insFirst(n, 'e');
	insFirst(n, 'f');

}

/**calcola l'altezza dell'albero*/
template <class I>
int TreeList<I>::higth()
{
    return this->level();
}

/**calcola il livello dell'albero*/
template <class I>
int TreeList<I>::level()
{
    int max=nodes[0].lv_e;  //parto dalla radice
    int i=0;
    while(i<MAXNODES)
    {
        if(nodes[i].used)
        {
            if(nodes[i].lv_e>max)
            {
                max=nodes[i].lv_e;
            }
        }
        i++;
    }
    return max;
}

/**Somma tutti i valori con iterazione da 0 se l'iesimo nodo è sul livello k.*/
template <class I>
int TreeList<I>::nodes_level(int lv)
{
    //int media=MAXNODES/2;
    int iter_min=0;
    //int iter_max=MAXNODES;
    int sum_nodes_lv=0;
    while(iter_min<MAXNODES)
    {
        if(nodes[iter_min].used && nodes[iter_min].lv_e==lv)
        {
            sum_nodes_lv++;
        }
        iter_min++;
    }
    return sum_nodes_lv;
}

template <class I>
bool TreeList<I>::hasParent(node n)const
{   if(n>=0 && n<MAXNODES)
    {
    int flag=parent(n);
    cout<<"parent in pos: "<<flag<<endl;
    if(flag>=0 && flag<MAXNODES)    //se il nodo ha padre...ok
    {
        return true;
    }
    else
    {
        return false;
    }
    }
    else
    {
        return false;
    }
}

template <class I>
int TreeList<I>::leggiNumLeafs()const
{   int ch=0;
    int i=0;
    while(i<MAXNODES)
    {
        if(leaf(i))
        {
            ch++;
        }
        i++;
    }
    return ch;
}

template <class I>
int TreeList<I>::leggiNumNodes() const
{
    return numNodes;
}

/**
Legge l'iesimo nodo dell'array e poi se l'iesimo non è foglia, stampa i figli successivi, ricorsivamente
*/
template <class I>
void TreeList<I>::print() const{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i)){
				position_list child = nodes[i].childs.begin();
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " ";
					child = nodes[i].childs.next(child);
				}
			}
		}
	}
	cout << "\n}\n";
}
/**
Non ci sono nodi, e sono tutti settati a non usati. Così per i figli
*/
template <class I>
void TreeList<I>::create(){
	numNodes = 0;
	for (int i=0; i< MAXNODES;i++){
		nodes[i].used = false;
		nodes[i].lv_e = 0;
		nodes[i].childs.create();
	}
}

/**
L'albero è vuoto se non ha nodi
*/
template <class I>
bool TreeList<I>::empty() const{
	return(numNodes == 0);
}

/**
Inserisce la radice di un albero vuoto con cursore 0, il primo elemento dell'array e quindi è un nodo usato
si può incrementare il numero dei nodi
*/
template <class I>
void TreeList<I>::insRoot (node n){
	if (empty()){
		_root = 0;
		nodes[0].lv_e=0;    //la radice è sul primo livello , ossia 0
		nodes[0].used = true;
		numNodes++;
	}
}

/**
Restituisce il cursore (sarà sicuramente 0) della radice
*/
template <class I>
typename TreeList<I>::node TreeList<I>::root () const{
	return _root;
}

/**
Restituisce il cursore al --padre-- del nodo dato in input.
se l'array ha figli (non empty) allora la list<int> child assume il valore della lista dei figli di nodes.
settato trovato a falso. Mentre ci sono ancora figli nell'array nodes da cercare se si trova il cursore
all'iesimo figlio che COINCIDE CON n, allora esci dal ciclo while e restituisce l'iesimo cursore dell'array
altro non è che il padre di n. Altrimenti scansiona tutto il while.
*/
template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const{
	if(n<0 && n>=MAXNODES) //la radice NON HA PADRE ESSENDO IN POS 0
    {
        return ESITO_NEG;  //restituisco un esito negativo
    }
    else
    {
        position_list child;
        int p;
        int i;
        for (i=0; i < MAXNODES; i++){
            if (!nodes[i].childs.empty()){
                child = nodes[i].childs.begin();
                bool found = false;
                while (!nodes[i].childs.end(child) && !found){
                    if (nodes[i].childs.read(child) == n){
                        found = true;
                        p = i;
                    }//fine secondo if del for
                    child = nodes[i].childs.next(child);    //incrementa per la scansione
                }//fine while
                if (found)
                    return(i);
                else
                    return ESITO_NEG;
            }//fine primo if del for
        }//fine for
        //if(found==false && i==MAXNODES-1)   //ho setacciato tutto
        //{
        //    return ESITO_NEG;  //restituisco un esito negativo
        //}
    }
}
/**
Verifico che l'ennesimo nodo sia presente oppure no . Poichè cerco la foglia, verifico che l'ennesimo nodo
abbia una lista vuota di figli
*/
template <class I>
bool TreeList<I>::leaf(node n) const{
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
	return(nodes[n].childs.empty());
}


/**
Se l'ennesimo nodo non è foglia, restituisce il primo(begin) cursore al figlio n-esimo dell' n-esimo array di nodi(complicato eh?)
*/
template <class I>
typename TreeList<I>::node TreeList<I>::firstChild (node n) const{
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
        if (!leaf(n)){
		return(nodes[n].childs.read(nodes[n].childs.begin()));
	}
    }
}

/**
Restituisce l'ultimo cursore al fratello del nodo n. Si verifica che n (di cui ci siamo calcolati il padre) sia effettivamente l'ultimo
della lista dei figli successivi (bool)
*/
template <class I>
bool TreeList<I>::lastSibling (node n) const {
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
        	position_list c;
	node p = parent(n);
	c = nodes[p].childs.begin();
	while (!nodes[p].childs.end(c))
		c = nodes[p].childs.next(c);
	return (n == nodes[p].childs.read(c));
    }
}


/**
Se il cursore n non è già l'ultimo fratello (vedi funzione sopra) scorre tutta la lista dei figli dell'ennesimo padre dell'array
mentre ci sono figli, se l'iesimo figlio coincide con nodo n, restituisci il successivo cursore da leggere. Altrimenti continua
*/
template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const{
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
        	if (!lastSibling(n)){
		position_list c;
		node p = parent(n);
		c = nodes[p].childs.begin();
		while (!nodes[p].childs.end(c)){
			if (nodes[p].childs.read(c) == n)
				return (nodes[p].childs.read(nodes[p].childs.next(c)));
			c = nodes[p].childs.next(c);
		}
	}
    }
}

/**
INSERISCE el COME PRIMO FIGLIO di n
C'è il vero inserimento dell'elemento template con relativo cursore.
Ovviamente nei limiti di celle libere.
come filgio n-esimo di nodes(padri) nella lista di cursori figli
*/
// inserisce un node come firstChild di n
template <class I>
void TreeList<I>::insFirst(node n, item el){
	// cerca una posizione libera
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
       	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[k].lv_e=nodes[n].lv_e+1;

		nodes[n].childs.insert(k, nodes[n].childs.begin());
	}
    }
}

/**
INSERISCE el in posizione n come FRATELLO
(vedi sopra) stesso ragionamento di sopra nella metà del for, però scorre la lista dei figli finchè non sono finiti
Trovato l'enneismo nodo, si aggiunge il k-esimo come successivo (ovviamente
*/
// inserisce un node come fratello di n
template <class I>
void TreeList<I>::ins(node n, item el){
	// cerca una posizione libera
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
       	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
        nodes[k].lv_e=nodes[n].lv_e;    //essendo fratelli n e k sono sullo stesso livello

		node p = parent(n);
		position_list child = nodes[p].childs.begin();
		bool found = false;
		while (!nodes[p].childs.end(child) && !found){
			if (nodes[p].childs.read(child) == n)
					{
					    found = true;
                    }
			child = nodes[p].childs.next(child);
		}
		nodes[p].childs.insert(k, child);
	}
    }

}


/**
se l'ennesimo nodo non è foglia, ed ha ancora figli, rimuovi ricorsivamente i figli dal primo in poi.
Se ci imbattiamo in una foglia iniziamo a eliminare e settare come non usati, tutti i successivi fratelli
*/
template <class I>
void TreeList<I>::removeSubTree (node n){
    if(n>=0 && n<MAXNODES && nodes[n].used==true)
    {
        position_list c;
        if (!leaf(n)){
            while (!nodes[n].childs.empty()){
                removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));
            }
        }
        node p = parent(n);
        c = nodes[p].childs.begin();
        while(nodes[p].childs.read(c) != n)
            c = nodes[p].childs.next(c);
        nodes[p].childs.erase(c);
        nodes[n].used = false;
    }
}

/**
Modifica l'ennesimo padre dell'array con un elemento in input (set)
*/
template <class I>
void TreeList<I>::writeNode (node n, item el){
    if(n>=0 && n<MAXNODES && nodes[n].used==true)
	nodes[n].e = el;
}

/**
Restituisce il valore e del nodo n-esimo dell'array (template) iò valore dato il cursore n
*/
template <class I>
typename TreeList<I>::item TreeList<I>::readNode (node n) const{
	if(n>=0 && n<MAXNODES && nodes[n].used==true)
	return(nodes[n].e);

}

//---------------------------------------------------------------

template <class I>
void TreeList<I>::printChilds( List_vector<int> L)
{
    int i=0;
    int p=L.begin();
    cout<<" ";
    while(i<L.legginumElem())
    {
        if(nodes[p].used)
        cout<<nodes[p].e<<" ";

        p=L.next(p);
        i++;
    }
}

#endif
