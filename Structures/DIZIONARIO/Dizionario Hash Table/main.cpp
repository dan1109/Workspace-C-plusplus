#include "Dizionario.h"
using namespace std;

//................................................................................................................
int main ()
{
    Nodo<string,int> a;
  Dizionario<string,int> d;
  a.settaChiave("abba");
  a.settaValore(88);
  cout<<"Il nodo e':"<<a<<endl;
  d.inserisci(a.leggiChiave(),a.leggiValore());
  cout<<"La chiave app?: "<<d.appartiene("abba")<<endl;
  cout<<"Recupera val dalla chiave :"<<d.recuperaValore("abba")<<endl;
    cout<<"Diz vuoto?: "<<d.dizionarioVuoto()<<endl;
  d.stampaDizionario();
      cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
  return 0;
}
