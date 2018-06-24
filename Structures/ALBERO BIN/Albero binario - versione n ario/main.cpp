/***************************************************************************
 *   Copyright (C) 2012 by Nicola Di Mauro                                 *
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
//ALBERO BINARIO MODIFICATO DALLA STRUTTURA N ARIA
//NON HO TESTATO TUTTE LE FUNZIONI
#include "TreeList.h"

int main(){

	TreeList<char> Tree;    //dichiara un albero char

	TreeList<char>::node n;
	Tree.insRoot(n);
	Tree.writeNode(Tree.root(),'a');  //a vale 0

	Tree.insFirst(Tree.root(),'b');

	Tree.insFirst(Tree.pos_e('a'),'c');


	Tree.insFirst(Tree.pos_e('b'),'d');

    Tree.insFirst(Tree.pos_e('b'),'e');


    Tree.insFirst(Tree.pos_e('c'),'f');

    Tree.insFirst(Tree.pos_e('c'),'g');


    Tree.insFirst(Tree.pos_e('d'),'h');

	Tree.print();
    int lv=4;

    cout<<"Nodi foglie dell'albero: "<<Tree.leggiNumLeafs()<<endl;
	cout<<"Nodi al livello "<<lv<<": "<<Tree.nodes_level(lv)<<endl;
	cout<<"Livello dell'albero: "<<Tree.level()<<endl;
	cout<<"Altezza dell'albero: "<<Tree.higth()<<endl;
	return 0;
}
