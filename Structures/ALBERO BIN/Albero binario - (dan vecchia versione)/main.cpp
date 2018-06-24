#include"Albero Binario.h"

// -----------------------------------------------
// Inizio del Main
//
// Il programma che segue mostra come applicare le
// funzioni di cui sopra

int main(int argc, char *argv[])
{

	AlberoBinario<int> t1;
	AlberoBinario<int> t2;

	t2.settaAlberoBinVuoto();

	AlberoBinario<int> t3;

	t3.settaAlberoBinVuoto();

	AlberoBinario<int> t4;

	t4.settaAlberoBinVuoto();

	int X;

	t1.costruisciAlberoBin(2,t2,t2);
	t2.costruisciAlberoBin(1,t3,t3);
	t3.costruisciAlberoBin(7,t1,t2);

	t1.costruisciAlberoBin(4,t4,t4);
	t2.costruisciAlberoBin(9,t4,t4);
	t4.costruisciAlberoBin(3,t1,t2);

	t1.costruisciAlberoBin(5,t3,t4);
    /*
    In t1 c'è ora l'albero (o meglio, il puntatore all'albero)
    rappresentato qui sotto:


						5(t1)
					/		\

				7				3

				/\				/\

			2		1		4		9(t2)
	*/
	cout<<"\nStampa in simm:\n";
	t1.stampaSimmetrica();

	cout<<"\n\nStampa in Preorder:\n";
	t1.stampaInPreOrdine();

	cout<<"\n\nStampa in Postorder:\n";
	t1.stampaInPostOrdine();

	cout<<"\n\nLa radice dell 'albero è : "<<t1.leggiRadice();

	cout<<"\n\nIl numero totale dei nodi dell'albero è : "<<t1.contaNodi();

	cout<<"\n\nIl numero totale delle foglie dell'albero è : "<<t1.ContaFoglie();

	cout<<"\n\nQuesto albero ha altezza "<<t1.altezza()<<"(ivello "<<t1.altezza()+1<<")";

	if (t1.perfettamenteBilanciato()) cout<<"\n\nQuesto albero è perfettamente bilanciato.";
	else cout<<"\n\nQuesto albero non è perfettamente bilanciato.";

	cout<<"\n\nInserire un valore da cercare nell'albero : ";
	cin>>X;
	if (t1.ricerca(X)) cout<<"\n\tValore trovato!!";
	else cout<<"\n\tValore non trovato!!";


	t1.settaAlberoBinVuoto();

	cout<<"\n\n\n*******************************************************************";
	cout<<"\n*********** COSTRUZIONE DI UN ALBERO BINARIO DI RICERCA ***********";
	cout<<"\n*******************************************************************";
	cout<<"\n\n\nInserire tutti gli elementi (per terminare inserire 0)\n";

    do {
		cout<<"\tElemento : ";
		cin>>X;
		t1.inserimentoBilanciato(X);
	} while (X!=0);

	cout<<"\nStampa in simm:\n";
	t1.stampaSimmetrica();

	cout<<"\n\nStampa in Preorder:\n";
	t1.stampaInPreOrdine();

	cout<<"\n\nStampa in Postorder:\n";
	t1.stampaInPostOrdine();

	cout<<"\n\nLa radice dell 'albero è : "<<t1.leggiRadice();

	cout<<"\n\nIl numero totale dei nodi dell'albero è : "<<t1.contaNodi();

	cout<<"\n\nIl numero totale delle foglie dell'albero è : "<<t1.ContaFoglie();

	cout<<"\n\nQuesto albero ha altezza "<<t1.altezza()<<"(ivello "<<t1.altezza()+1<<")";;

	if (t1.perfettamenteBilanciato()) cout<<"\n\nQuesto albero è perfettamente bilanciato.";
	else cout<<"\n\nQuesto albero NON è perfettamente bilanciato.";

	cout<<"\n\nInserire un elemento da cercare con la ricerca dicotomica : ";
	cin>>X;

	if (t1.ricercaBinaria(X)) cout<<"\n\tValore trovato!!";
	else cout<<"\n\tValore non trovato!!";

	cout<<"\n\n\n\n\n";

  system("PAUSE");
  return 0;
}
