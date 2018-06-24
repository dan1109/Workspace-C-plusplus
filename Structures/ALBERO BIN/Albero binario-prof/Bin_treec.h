#ifndef _Bin_treecC_H_
#define _Bin_treecC_H_

#include "Bin_tree.h"
#include "exceptions.h"
#include <array>

/**Albero binario con realizzazione con Heap. Nodo e Value sono generici ma in questa realizzazione
Nodo è il cursore all'array. Per cui Nodo è un intero*/
template <class T>
class Bin_treec : public Bin_tree<T, int>{

  public:
/**anzichè scrivere Bin_tree<T, int>::value_type , semplicemente   value_type */
	typedef typename Bin_tree<T, int>::value_type value_type;
/**anzichè scrivere Bin_tree<T, int>::Nodo , semplicemente   Nodo */
	typedef typename Bin_tree<T, int>::Nodo Nodo;

    /**NIL è un cursore ad un nodo dell'array per indicare che la posizione -1 non esiste*/
    static const int NIL = -1;

	/**la struttura _cella ha padre, figlio sx dx, e l'etichetta del nodo*/
    struct _cella{
        Nodo genitore;
        Nodo sinistro;
        Nodo destro;
        value_type valore;
    /**nodo ha un valore T inserito(write) oppure c'è il nodo, ma è vuoto?*/
        bool used;
    /**livello del nodo nell'albero binario*/
        int livello;
      };
/**rinominazione da _cella a Cella*/
    typedef struct _cella Cella;

    // costruttori e distruttori
    Bin_treec();
    Bin_treec(int);
    ~Bin_treec();

    // operatori
    void create();
    bool empty() const;

    Nodo root() const;
    Nodo parent(Nodo) const;
    Nodo sx(Nodo) const;
    Nodo dx(Nodo) const;
    bool sx_empty(Nodo) const;
    bool dx_empty(Nodo) const;

    //void costr(Bin_treec<T>);
    void erase(Nodo);

    T read(Nodo) const;
    void write(Nodo , value_type );

    void ins_root(Nodo);
    void ins_sx(Nodo);
    void ins_dx(Nodo);

//ALTRE FUNZIONI IMPLEMENTATE DA ME
    void print2Vers();//stampa come se fosse un albero n ario
//livello/altezza/profondità sono sinonimi

    int contaFoglie();  //funzionante
    int altezzaAlb();   //alias cammino massimo/livello massimo
    int liv_n(Nodo n);  //La radice ha livello 0. Il livello di un nodo è 1 più il livello del padre
    array<int,100> nodiCammino(Nodo n);   //dato una posizione, ossia un nodo ne dà gli altri sul percorso
    bool esisteCamminoFoglia(int path); //esiste un cammino di questa lunghezza fino a una foglia dato il cammino?
    bool foglia(Nodo n);    //il nodo n è foglia?
    int costoCammino(Nodo n);   //--se n è foglia-- ne individua il costo complessivo sommando le etichette dalla radice
    bool sumPath(int sum);  //verifica che ci sia un cammino con costo complessivo pari a sum, vedi metodo sopra
    int maxPath();          //individua il cammino dal costo massimo

  private:
      /**lunghezza massima array*/
    int MAXLUNG;
    Cella *spazio;
    /**elementi usati nell'array*/
    int nNodi;
    /**Verifica che ci sia un nodo iniziale dell'albero. Controllo se c'è la radice*/
    Nodo inizio;
    /**verifica chi è il prossimo nodo libero*/
    Nodo libera;
};

template <class T>
int Bin_treec<T>::contaFoglie()
{   int leafs=0;
    int i=0;
    while(i<MAXLUNG)
    {
        if(spazio[i].used && sx_empty(i) && dx_empty(i))
        {
            leafs++;
        }
        i++;
    }
    return leafs;
}

template <class T>
int Bin_treec<T>::altezzaAlb()
{
    if(empty())
    {
        return -1;
    }
    int i=0;
    int h=0;
    while(i<MAXLUNG)
    {
        if(spazio[i].used && sx_empty(i) && dx_empty(i) && spazio[i].livello>h)
        {
            h=spazio[i].livello;
        }
        i++;
    }
    return h;
}

template <class T>
int Bin_treec<T>::liv_n(Nodo n)
{
    if(n!=NIL)
    {
        return spazio[n].livello;
    }
}

/**il costo di un cammino è la somma delle etichette del cammino partendo dal nodo n a salire*/
template <class T>
int Bin_treec<T>::costoCammino(Nodo n)
{
    int costo=0;
    if(n==NIL || n<0 || n>MAXLUNG) //precondizioni
    {
        return costo;   //semplice: no archi no albero
    }
    int i=n;
    while(i>=root())  //costo del cammino da n fino a root
    {
        costo = costo + spazio[i].valore;
        i=spazio[i].genitore;
    }
    return costo;
}

/**n è foglia?*/
template <class T>
bool Bin_treec<T>::foglia(Nodo n)
{
    bool trovato=false;
    if(n==NIL || n<root() || n>MAXLUNG )
    {
        return trovato;
    }
    if(spazio[n].used && sx_empty(n) && dx_empty(n))
        trovato=true;

    return trovato;
}

/**dato un nodo n esiste un cammino foglia ad n?*/
template <class T>
bool Bin_treec<T>:: esisteCamminoFoglia(int path)
{   bool trovato=false;
    if(path<0 || path>altezzaAlb())
    {
        return trovato;
    }
    int i=0;
    while(i<MAXLUNG && trovato==false)
    {
        if(foglia(i) && spazio[i].livello==path)
        {
            trovato=true;
        }
        i++;
    }
    return trovato;
}

/**restituisce le POSIZIONI dei nodi coinvolti nel cammino nell'array*/
template <class T>
array<int,100> Bin_treec<T>::nodiCammino(Nodo n)
{
    array<int,100> nodi;
    int j=0;
    while(j<100)
    {
        nodi[j]= -1;
        j++;
    }
    if(n==NIL || n<root() || n>MAXLUNG )
    {
        return nodi;
    }
//-----------------------------------------------
    int pos=0;
    while(n>=root())
    {
        if(spazio[n].used)
        {   int temp=n;
            nodi[pos]=temp;
            pos++;
        }
        n = parent(n);  //a scalare
    }
    return nodi;
}

/**dato l'intero sum, determina se l'albero ha un path dalla radice ad un nodo foglia
con costo pari a sum*/
template <class T>
bool Bin_treec<T>::sumPath(int sum)
{   bool trovato=false;
    int leafs=contaFoglie();
    int cammini_pesati_nodi[leafs];
    int nodi_foglie[leafs];//le foglie da considerare
    int i=0;
    int j=0;
    while(i<MAXLUNG)
    {
        if(foglia(i))
        {
            nodi_foglie[j]=i;
            j++;
        }
        i++;
    }
    //l'array di foglie è riempito
    i=0;
    while(i<leafs)
    {
        cammini_pesati_nodi[i]=costoCammino(nodi_foglie[i]);
        i++;
    }

    i=0;
    while(i<leafs && trovato!=true)
    {
        if(cammini_pesati_nodi[i]==sum)
        {
            trovato=true;
        }
        i++;
    }
    return trovato;
}
///restituisce il costo del path piu costoso dalla radice ad un nodo foglia
template <class T>
int Bin_treec<T>::maxPath()
{
  int leafs=contaFoglie();
    int cammini_pesati_nodi[leafs];
    int nodi_foglie[leafs];//le foglie da considerare
    int i=0;
    int j=0;
    while(i<MAXLUNG)
    {
        if(foglia(i))
        {
            nodi_foglie[j]=i;
            j++;
        }
        i++;
    }
    //l'array di foglie è riempito
    i=0;
    while(i<leafs)
    {
        cammini_pesati_nodi[i]=costoCammino(nodi_foglie[i]);
        i++;
    }
    i=0;
    int max=cammini_pesati_nodi[i] ;
    while(i<leafs)
    {
        if(cammini_pesati_nodi[i]>max)
        {
            max=cammini_pesati_nodi[i];
        }
        i++;
    }
    return max;
}

template <class T>
void Bin_treec<T>::print2Vers(){
int i=0;
cout<<"["<<endl;
while(i<MAXLUNG)
    {       if(spazio[i].used)
            {
            int sx=spazio[i].sinistro;
            int dx=spazio[i].destro;
            cout<<"["<<i<<"] "<<"lv: "<<spazio[i].livello<<"--Nodo: "<<spazio[i].valore<<" : ";
            if(!sx_empty(i) /*&& spazio[sx].valore!=0*/)
            {
                cout<<spazio[sx].valore<<" ";
            }
            else
            {
                cout<<"NIL ";
            }
            if(!dx_empty(i)/*&& spazio[dx].valore!=0*/)
            {
                cout<<spazio[dx].valore<<endl;
            }
            else
            {
                cout<<"NIL"<<endl;
            }
        }
        i++;
    }
cout<<"]"<<endl<<endl;
}

template <class T>
Bin_treec<T>::Bin_treec()
{
  MAXLUNG = 100;
  spazio = new Cella[MAXLUNG];
  create();
}
/**costruttore di copia per un valore div di maxlungh*/
template <class T>
Bin_treec<T>::Bin_treec(int nNodi): MAXLUNG(nNodi)
{
  spazio = new Cella[nNodi];
  create();
}


template <class T>
Bin_treec<T>::~Bin_treec()
{
  erase(inizio);
  delete[] spazio;
}

template <class T>
void Bin_treec<T>::create()
{
  inizio = NIL;
  for (int i = 0; i < MAXLUNG; i++)
    {
    //istruzione importante
      spazio[i].sinistro = (i+1) % MAXLUNG;
      //nemmeno un nodo viene usato
      spazio[i].used=false;
      //setto il livello di ogni nodo a -1
      spazio[i].livello= -1;
    }

  libera = 0;
  nNodi = 0;
}

template <class T>
bool Bin_treec<T>::empty() const
{
  return(nNodi == 0);
}

template <class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::root() const
{
  return(inizio);
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::parent(Nodo n) const
{
  if (n != inizio)
    return (spazio[n].genitore);
  else if(n==root())
        return -1;

    return(n);
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::sx(Nodo n) const
{
  if (!sx_empty(n))
    return (spazio[n].sinistro);
  else
    return(n);
};

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::dx(Nodo n) const
{
  if (!dx_empty(n))
    return (spazio[n].destro);
  else
    return(n);
}

template <class T>
bool Bin_treec<T>::sx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].sinistro == NIL);
}

template <class T>
bool Bin_treec<T>::dx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].destro == NIL);
}

template <class T>
void Bin_treec<T>::ins_root(Bin_treec<T>::Nodo n)
{
  if (inizio == NIL)
    {
      inizio = libera;
      libera = spazio[libera].sinistro;
      spazio[inizio].genitore=NIL;
      spazio[inizio].livello=0; //  la radice ha altezza/livello/profondità 0
      spazio[inizio].sinistro = NIL;
      spazio[inizio].destro = NIL;
      nNodi++;
    }
	else
		throw RootExists();
}

/** se casi di errori superati, inserisce un nodo VUOTO figlio sx di n , n è parde di un figlio sx vuoto.
A sua volta il figlio non ha figli*/
template <class T>
void Bin_treec<T>::ins_sx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].sinistro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
  else
    {
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].sinistro = q;

      spazio[q].sinistro = NIL;
      spazio[q].genitore = n;
      spazio[q].livello= spazio[n].livello+1;
      spazio[q].destro = NIL;
      nNodi++;
    }
}

/** se casi di errori superati, inserisce un nodo VUOTO figlio dx di n , n è parde di un figlio dx vuoto.
A sua volta il figlio non ha figli*/
template <class T>
void Bin_treec<T>::ins_dx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].destro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
	else
    {
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].destro = q;

      spazio[q].livello=spazio[n].livello+1;
      spazio[q].genitore = n;
      spazio[q].sinistro = NIL;
      spazio[q].destro = NIL;
      nNodi++;
    }
}


template <class T>
void Bin_treec<T>::erase(Nodo n)
{
  if (n != NIL) {
      if (!sx_empty(n))
        erase(spazio[n].sinistro);
      if (!dx_empty(n))
        erase(spazio[n].destro);
      if (n != inizio) {
          Nodo p = parent(n);
          if (spazio[p].sinistro == n)
            spazio[p].sinistro = NIL;
          else
            spazio[p].destro = NIL;
        }
      else
        inizio = NIL;
      nNodi--;
      spazio[n].sinistro = libera;
      libera = n;
    }
	else
		throw NullNode();
}

template <class T>
T Bin_treec<T>::read(Nodo n) const
{
  if (n != NIL && spazio[n].used == true)
    return (spazio[n].valore);
	else
		throw NullNode();
}

/**scrive il valore dell'ennesimo nodo e lo setta a riempito di un valore*/
template <class T>
void Bin_treec<T>::write(Nodo n, value_type a)
{
  if (n != NIL)
    {
     spazio[n].valore = a;
     spazio[n].used = true;
     if(n!=root())
     {
     Nodo genitore = spazio[n].genitore;
     spazio[n].livello = spazio[genitore].livello+1;    //altezza del nodo corretto non radice è quella del padre +1
     }
    }

	else
		throw NullNode();
}

std::ostream& operator<<(std::ostream& os,const std::array<int, 100u>& v);

std::ostream& operator<<(std::ostream& os,const std::array<int, 100u>& v)
{
   int i=0;
   os<<"[ ";
   while(i<100)
   {    if(v[i]!=Bin_treec<int>::NIL)
       os<<v[i]<<" ";
       i++;
   }
   os<<"]\n";
   return os;
}
#endif /* _Bin_treecC_H_ */
