#include <iostream>
#include<stdlib.h>
#include "alberobinario.h"
#include "cella.h"

using namespace std;

int main()
{
    BinAlbero<int> Tree;
    Tree.insBinRadice(new Cella<int>);
    Tree.scriviNodo(Tree.binRadice(),2345);
    cout<<"L'elemento radice dell'albero binario e': "<<Tree.binRadice()->getElemento();
    Tree.insFiglioSinistro(Tree.binRadice());
    Tree.insFiglioDestro(Tree.binRadice());
    Tree.scriviNodo(Tree.figlioSinistro(Tree.binRadice()),234);
    Tree.scriviNodo(Tree.figlioDestro(Tree.binRadice()),235);
    cout<<"\n\nIl figlio sinistro della radice dell'albero binario e': "<<Tree.figlioSinistro(Tree.binRadice())->getElemento();
    cout<<"\n\nIl figlio destro della radice dell'albero binario e': "<<Tree.figlioDestro(Tree.binRadice())->getElemento();
    return 0;
}
