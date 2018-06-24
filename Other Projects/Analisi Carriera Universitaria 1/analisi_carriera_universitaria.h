#ifndef ANALISI_CARRIERA_UNIVERSITARIA_H_INCLUDED
#define ANALISI_CARRIERA_UNIVERSITARIA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
#endif // ANALISI_CARRIERA_UNIVERSITARIA_H_INCLUDED
//CLASS DANIEL BUFL E WOGGTEK
//DEFINE DALIEL BUFL
class analisi_carriera_universitaria{
    public:
void stampa_esami(){
    string line;//APRIAMO IL FILE E SEMPLICEMENTE STAMPIAMOLO RIGA PER RIGA GRAZIE AD UNA FUNZIONE AD OC
   ifstream myfile ("libretto.txt");
if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
          }
    myfile.close();//CHIUDIAMO DANIEL BUFL
  }
  else cout << "Unable to open file";
}

float media_aritmetica_ponderata_esami(){

    int voto=0;
    int crediti=0;
    int numero_esami=0;

    int numeratore=0;
    int denominatore=0;
    float risultato;

    ifstream inFile;//E UN TIPO CHE CI SERVE PER APRIRE I FILE IN C++
    inFile.open("libretto.txt");
    string nome_esame;


   if(inFile.fail()){
    cerr<<"Errore nell'aperturadel File"<<endl;//APRIAMO IL FILE
    exit(1);
   }

 while(!inFile.eof()){
  inFile>>nome_esame>>voto>>crediti;//ACQUISIAMO NELLE VARIABILI RIGA PER RIGA IL NOME ESAME VOTO E CREDITI
  numeratore=numeratore+(voto*crediti);//CON LE VARIABILI APPENA ACQUISITE CALCOLIAMO MAN MANO IL VALORE AL NUMERATORE

 denominatore=denominatore+crediti;//CON LE VARIABILI APPENA ACQUISITE CALCOLIAMO MAN MANO IL VALORE AL DENOMINATORE

    }
risultato=(float)numeratore/(float)denominatore;//CONVERTIAMO IN FLOAT I VALORI PRIMA DI ASSEGNARLI AL RISULTATO

//DANIEL BUFL
//WOGGTEK
return(risultato);


}






};
