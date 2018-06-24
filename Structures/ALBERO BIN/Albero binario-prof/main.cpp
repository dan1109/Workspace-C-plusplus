/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "Bin_treec.h"
#include <iostream>

using namespace std;


int main(){
	Bin_treec<int> T;
	typename Bin_treec<int>::Nodo n1, n2;

	T.ins_root(n1);
	T.write(T.root(),1);
	n1 = T.root();
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),2);
	n1 = T.dx(n1);
	T.write(n1, 3);
	T.ins_dx(n1);
	T.write(T.dx(n1), 4);
    T.ins_dx(T.dx(n1));
    T.write(T.dx(T.dx(n1)),5);
    T.ins_sx(T.dx(n1));
    T.write(T.sx(T.dx(n1)),6);

	T.print2Vers();
	int n=4;
	int path=3;
	cout<<"foglie dell'albero: "<<T.contaFoglie()<<endl;
	cout<<"altezza dell'albero: "<<T.altezzaAlb()<<endl;
	cout<<"Costo cammino fino al nodo n "<<n<<" E' uguale a: "<<T.costoCammino(n)<<endl;
    cout<<"E' foglia il nodo n "<<n<<"?: "<<T.foglia(n)<<endl;
    cout<<"Esiste un cammino ad un foglia con cammino pari a "<<path<<"? : "<<T.esisteCamminoFoglia(path)<<endl;
  //cout<<"Quali nodi sono coinvolti dalla radice al nodo n dove n vale :"<<n<<"? : "<<endl<<T.nodiCammino(n)<<endl;
    int sum=3;
    cout<<"Esiste un cammino pesato ad un foglia con cammino pari a "<<sum<<"? : "<<T.sumPath(sum)<<endl;
    sum=13;
    cout<<"Esiste un cammino pesato ad un foglia con cammino pari a "<<sum<<"? : "<<T.sumPath(sum)<<endl;
    cout<<"Cammino pesato massimo: "<<T.maxPath()<<endl;
	//T.print();
	//cout << T;
}
