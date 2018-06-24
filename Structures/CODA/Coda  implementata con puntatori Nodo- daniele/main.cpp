#include "Nodo.h"
#include "Coda.h"
//in relata è una coda poi modifico...
//funziona TUTTO
int main()
{
    Coda<int> p;
    cout<<"Coda vuota?: "<<p.codaVuota()<<endl;
    Nodo<int>* nodo;
    nodo=new Nodo<int>;
    int i;
    i=1;
    while(i<=5)
    {
        p.inCoda(i);
        i++;
    }
    p.fuoriCoda();
    cout<<"NUme ele: "<<p.leggiNumElem()<<endl;
    cout<<"Elemento in coda: "<<p.leggiCoda()<<endl;
    cout<<"Coda vuota?: "<<p.codaVuota()<<endl;
    p.stampaCoda();
    cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
    return 0;
}
