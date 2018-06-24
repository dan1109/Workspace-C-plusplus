#include <string.h>
#include <iostream>
using namespace std;
//PROTOTIPI--------------------------------------------------------

//LA VERA STRUTTURA NASCOSTA. LA LISTA E' UN INSIEME DI NODI. UN NODO HA POI IL PUNTATORE AL SUCC.
struct NODE {
 char nome[80]; // nome concorrente
 int voto; //voto
 NODE * next; //puntatore al prossimo elemento
};
class LISTA {
 private:
 NODE *head;    //TESTA
 NODE *tail;    //CODA
                // TESTA E CODA SONO GLI UNICI VALORI CHE CONOSCIAMO DELLA LISTA ACCESSO DIRETTO
 public:
LISTA(); //cotruttore
~LISTA();//distruttore
void insertstart(char *, int ); //inserisci all’inizio
void insertend(char *, int ); //inserisci alla fine
void print(); //stampa la lista
void printTail(); // stampa la fine della lista
void printHead(); // stampa l’inizio della lista
 void clear(); //cancella la lista
NODE * search(char *); // ricerca l’elemento per nome
};

//IMPLEMENTAZIONE---------------------------------------------------------
//COSTRUTTORE
LISTA::LISTA(){
 head=NULL; // inizializzo a NULL sia la testa che la coda
 tail = NULL;
}
//DISTRUTTORE
LISTA::~LISTA(){
 clear(); // distruttore: cancello la lista
}
//FUNZIONE CLEAR
void LISTA::clear(){
NODE *walker = head; // Set a "walker node" to the front of the list. SI INIZIA DALLA TESTA
while(walker != NULL) //MENTRE CAMMINA
{
NODE *temp = walker; // Create a temp node CHE ASSUME LA CAMMINATA IN LISTA
walker = walker->next; // Move the walker to the next node on the list
delete temp; // Free the memory
}
head = tail = NULL; // Set everything to NULL PER CANCELLARE LA LISTA
}
//INSERISCI ALL'INIZIO DELLA LISTA (TESTA)
void LISTA::insertstart(char *nome, int voto){

 NODE *temp = new NODE;  // ALLOCAZIONE TEMPORANEO
 strcpy(temp->nome,nome); //INSERISCI IL NOME IN TEMP
 temp->voto = voto;       //STESSA COSA PER VOTO
 temp->next = head;       // DIVENTA TEMP LA TESTA DELLA LISTA, PUNTA A TESTA
 if(head == NULL) {            // SE NON CI SONO VALORI, TESTA E CODA SONO UGUALI(1 VALORE)
 tail=temp;
 }
 head = temp;
}
//INSERISCI ULTIMO ALLA FINE DELLA LISTA (CODA)
void LISTA::insertend(char *nome, int voto){

 NODE *temp = new NODE;strcpy(temp->nome,nome);
 temp->voto = voto;
 temp->next = NULL; //ESSENDO L'ULTIMO, NON HA NODI CHE LO SUCCEDONO, PUNTA A NULL
 if(head == NULL) head=temp;  // SE LA LISTA HA 0 NODI. TEMP SARA' IL PRIMO NODO TESTA
 if (tail != NULL)tail->next = temp;  //ALTRIMENTI IL PROSSSIMO DELLA CODA SARA' TEMP(ASSEGNAMENTO PUNTATORI A NODO)
 tail = temp;
}
//CERCA VALORE RESTITUISCE IL NODO
NODE * LISTA::search(char *nome){
 NODE *walker=head;
 while(walker != NULL){
 if(strcmp(nome,walker->nome) == 0) return walker;
 walker=walker->next;
 }
 return walker;
}
//IL NODO WALKER SCORRE LA LISTA PARTENDO DA TESTA. LA STAMPA
void LISTA::print(){
 NODE *walker=head; //UNICO VALORE NOTO E' LA TESTA.
 cout<<"Inizio Stampa Lista:\n";
 while(walker != NULL){  //NULL INDICA FINE LISTA
 cout << "Elemento:"<<walker->nome<<" Voto "<<walker->voto<<"\n";
 walker=walker->next;  //WALKER DIVENTA IL PROSSIMO NODO PUNTATO. ITERAZIONE IN AVANTI
 }
 cout << "Fine Stampa Lista\n\n";
}
//STAMPA CODA E TESTA. GLI ABBIAMO NELLA CLASSE. METODI FACILI DA IMLPEMENTARE
void LISTA::printTail(){
 cout << "Elemento Tail:"<<tail->nome<<" Voto "<<tail->voto<<"\n\n";
}
void LISTA::printHead(){
 cout << "Elemento Head:"<<head->nome<<" Voto "<<head->voto<<"\n\n";
}
int main(){
 LISTA A;
 for(int i=0;i<5;i++){
//Le liste linkate semplici
// Implementazione di classi in C++

//INSERIMENTO STUDENTE E VOTO DALL'INIZIO TESTA
 A.insertstart("pippoooo",i);
 }
 //STAMPA TUTTO
 A.print();
 A.printTail();
 A.printHead();
 //STAMPA TESTA E CODA E CANCELLAZIONE LISTA
 //NUOVA LISTA
 A.clear();
 //INSERISCI ALLA FINE NOME EVOTO
 A.insertend("clarabella",-1);
 //STAMPA DI NUOVO LA LISTA CON NUOVI ELEMENTI
 A.print();
 //INSERISCI ALL'INIZIO
 A.insertstart("orazio",27);
 //RISTAMPA PER VEDERE SE HA MESSO ELEMENTO IN TESTA
 A.print();
 //SE LA RICERCA NON DA NULL, STAMPA CHE C'è UN LISTA.
 if(A.search("clarabella") != NULL) cout <<"Ti ho Trovato\n";
 return 0;
}
//Si completi la classe con i metodi per:
//• Inserimento dopo un certo elemento;
//• Cancellazione di un elemento (attenzione se è il primo o l’ultimo)



/*
**ISTRUZIONI CLAUDIO
-USA TIPO STRINGA
-PROGRAMMAZIONE STRUTTURATA
-METTI UN SOLO RETURN PER FUNZIONE
-SETTA SOLO VARIABILE COME ASSEGNAMENTO
-ELIMINA TAIL E LE RELATIVE FUNZIONI ( ATTIENITI AL DOCENTE )
-ATTIENITI ALLE SPECIFICHE DELLE FUNZIONI DEL PROF
-MIGLIORA INDENTAZIONE DEI PROGRAMMI {, IF, WHILE
-COERENZA DI SCRITTURA DEL CODICE
-TIPO POSIZIONE E' UN PUNTATORE A CELLA
    Lista<int> l;
    Lista<int>::posizione pos = l.primoLista();
    l.insLista(1, pos);
    l.insLista(2, pos);
    l.insLista(3, pos);
-PER LA DOCUMENTAZIONE NON SERVE //
/**
template<class T>
void Cella<T>::setSucc(posizione p) {
    posizioneSuccessiva = p;
}
/**
/**
 *
 * @param p:
-METTI LA MAIUSCOLA TIPO insertedStart. (i minuscolo)

---posizione temp = new Cella<T>;
    temp->setValore(e);
    temp->setPrec(p);
    temp->setSucc(p->getSucc());
    (p->getSucc())->setPrec(temp);
    p->setSucc(temp);
    p = temp;
    numElementi++;

-USA SENTINELLA, NODO VUOTO CON CUI RIFERIRSI ALLA LISTA
 */

