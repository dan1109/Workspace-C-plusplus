#include <fstream>
#include <string>
#include <iomanip>
#include "cifrario_cesare.h"
using namespace std;

int main()
{
    char a[256];
    char b[256];
    cifrario_cesare stampa;
    cifrario_cesare lettura;

    lettura.codifica(a,b);
    stampa.stampa_situazione();


    return 0;
}
