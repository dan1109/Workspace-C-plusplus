#include "Insieme_vettore_bool.h"
#include "Lista.h"
// L'insieme funziona perfettamente. NON PERDO A E B NELLE OPERAZIONI
int main()
{
    Insieme<int> I;
    Insieme<int> U;
    Insieme<int> D;

    Insieme<int> A;
    Insieme<int> B;
    int i=1;
    while(i<=4)
    {
        A.inserisci(i);
        i++;
    }
     i=3;
    while(i<=7)
    {
        B.inserisci(i);
        i++;
    }
   U.unione(&A,&B);
    cout<<"Unione:";
   U.stampaInsieme();
   I.intersezione(&A,&B);
   cout<<"Intersez:";
   I.stampaInsieme();
   D.differenza(&A,&B);
   cout<<"diff:";
   D.stampaInsieme();
    cout<<" A e B: ";
    A.stampaInsieme();
   B.stampaInsieme();
    //system("PAUSE");
    cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
    return 0;
}
