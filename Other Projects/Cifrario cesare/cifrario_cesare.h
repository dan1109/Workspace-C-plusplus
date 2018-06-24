#ifndef CIFRARIO_CESARE_H_INCLUDED
#define CIFRARIO_CESARE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



class cifrario_cesare{
    public:




void stampa_situazione(){

    string line;//APRIAMO IL FILE E SEMPLICEMENTE STAMPIAMOLO RIGA PER RIGA GRAZIE AD UNA FUNZIONE AD OC
   ifstream myfile ("originale.txt");
cout<<"messaggio originale:"<<endl;
if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
          }
    myfile.close();//CHIUDIAMO DANIEL BUFL
  }
  else cout << "Unable to open file";
////////////////////////////////////////////////////////////////////////////
    cout<<"spiazzamento:"<<endl;
     string line2;//APRIAMO IL FILE E SEMPLICEMENTE STAMPIAMOLO RIGA PER RIGA GRAZIE AD UNA FUNZIONE AD OC
   ifstream myfile2 ("spiazzamento.txt");
if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      cout << line << '\n';
          }
    myfile2.close();//CHIUDIAMO DANIEL BUFL
  }
  else cout << "Unable to open file";
 /////////////////////////////////////////////////////////////////////////////
     string line3;//APRIAMO IL FILE E SEMPLICEMENTE STAMPIAMOLO RIGA PER RIGA GRAZIE AD UNA FUNZIONE AD OC
   cout<<"messaggio codificato:"<<endl;
   ifstream myfile3 ("cifrato.txt");
if (myfile3.is_open())
  {
    while ( getline (myfile3,line) )
    {
      cout << line << '\n';
          }
    myfile3.close();//CHIUDIAMO DANIEL BUFL
  }
  else cout << "Unable to open file";
 //////////////////////////////////////////////////////////
}

void codifica_cesare(){
    string line;//APRIAMO IL FILE E SEMPLICEMENTE STAMPIAMOLO RIGA PER RIGA GRAZIE AD UNA FUNZIONE AD OC
   ifstream myfile ("originale.txt");
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













void codifica(char a[],char b[]){
const char * filename = "originale.txt";
//const char * filename2 = "spiazzamento.txt";
//const char * filename3 = "cifrato.txt";                                //
char alfabeto[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char alfabetomodificato[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
FILE *fp;//per originale
FILE *fp2;//per cifrato
int spiazzamento = 0;
int indiceRelativo=0;
fp=fopen("spiazzamento.txt","r");
fscanf(fp,"%d",&spiazzamento);
fp2=fopen("cifrato.txt","w");
const int dim=26;
//char * buffer;
long size;
ifstream file (filename, ios::in|ios::binary|ios::ate);
size = file.tellg();
file.seekg (0, ios::beg);//                           acquisizione di originale.txt in a
a = new char [size];
file.read (a, size);
file.close();
//for(int i=0;i<4;i++){cout<<a[i]<<endl;}//funziona
//cout<<spiazzamento;//funziona
////////////////////////////////////////////////////////////////////////////////////////
//for(int i=0;i<26;i++){cout<<alfabeto[i]<<endl;}//funziona
//nel caso di spiazzamento negativo lo "trasformo in positivo"
if(spiazzamento<0){
        spiazzamento=spiazzamento*-1;}//lo trasformo in positivo

        indiceRelativo=spiazzamento;
        while(indiceRelativo>dim-1){
        indiceRelativo=indiceRelativo-(dim-1);}


for(int i=0;i<dim;i++){
    if(i+spiazzamento>dim-1){
        //cout<<"yo";
         indiceRelativo=indiceRelativo-(dim-1);}





    alfabetomodificato[i]=alfabeto[indiceRelativo];
//cout<<indiceRelativo<<endl;//funzion

    indiceRelativo++;

}
//for(int i=0;i<26;i++){cout<<alfabetomodificato[i]<<endl;}
//cout<<size<<endl;//lunghezza parola originale in size
int j=0;
for(int i=0;i<size;i++){
    j=0;
    while(alfabeto[j]!=a[i]){j++;}
    b[i]=alfabetomodificato[j];

}
for(int i=0;i<size;i++){fprintf(fp2,"%c",b[i]);}

fclose(fp);
fclose(fp2);
}


void sacsacsacas(){}

};


#endif // CIFRARIO_CESARE_H_INCLUDED
