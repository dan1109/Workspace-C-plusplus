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

#include "TreeList.h"

int main(){

	TreeList<char> Tree;    //dichiara un albero char

	Tree.ins_autom();

	Tree.print();
    int lv=2;

    cout<<endl<<"Nodi foglie dell'albero: "<<Tree.leggiNumLeafs()<<endl;
	cout<<"Nodi al livello "<<lv<<": "<<Tree.nodes_level(lv)<<endl;
	cout<<"Altezza dell'albero: "<<Tree.higth()<<endl;
	return 0;
}
