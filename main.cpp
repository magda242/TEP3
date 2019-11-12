// TEP3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "table.h"
#include <iostream>

int main()
{
	/*
	Table* table1 = new Table("tabela", 8);
	table1->print_table();
	table1->table[0] = 5;
	table1->table[3] = 6;
	table1->print_table();

	table1->setNewSize(3);
	table1->print_table();
	table1->setNewSize(9);
	table1->print_table();
	table1->setName("aaa");

	Table table2(*table1);

	table2.print_table();
	table2.setName("bbb");

	delete table1;

	// procedury

	mod_tab(&table2, 1);
	table2.print_table();

	mod_tab(table2, 2);
	table2.print_table();

	*/


	//Table c_tab_0, c_tab_1;
	//c_tab_0.setNewSize(6);
	//c_tab_1.setNewSize(4);
	//c_tab_0 = c_tab_1;
	//c_tab_0.print_table();
	// jak się skończyło?
	// źle bo wywdaliło wyjątek w delete_scalar.cpp
	// bo jak table w obu obiektach wskazuja na te sama tablice to jak usunie sie jedna to przy probie
	// usuniecia drugiej nie bedzie sie dalo

	// jak bez destruktora?
	// bez destruktora dziala ale nie wywoluje sie destruktor bo go nie ma i pamiec sie nie zwalnia
	// c++ zapewnia domyslny operator przypisania (=) dzieki czemu dlugosc tablicy zmienia sie poprawnie
	// ale referencja na tablicę zostaje skopiowana

	Table c_tab_0, c_tab_1;
	c_tab_0.setNewSize(6);
	c_tab_1.setNewSize(4);

	c_tab_0.setValueAt(0, 1);
	c_tab_0.setValueAt(1, 2);
	c_tab_0.setValueAt(2, 3);
	c_tab_0.setValueAt(3, 4);
	c_tab_0.setValueAt(4, 5);
	c_tab_0.setValueAt(5, 6);

	c_tab_1.setValueAt(0, 51);
	c_tab_1.setValueAt(1, 52);
	c_tab_1.setValueAt(2, 53);
	c_tab_1.setValueAt(3, 54);

	c_tab_0.print_table();
	c_tab_0 += c_tab_1 += c_tab_0;
	c_tab_0.print_table();
	c_tab_0 += 6;
	c_tab_0.print_table();




	/* initialize table */
	c_tab_0 = c_tab_1; 
	c_tab_1.setValueAt(2, 123);
	c_tab_0.print_table();
	c_tab_1.print_table();

	Table c_tab_2 = c_tab_0 + c_tab_1;
	c_tab_2.print_table();






	// [51, 52, 123, 54] sie wyswietli dwa razy bo
	// jak przypiszemy c_tab_1 do c_tab_0 to domyslny operator przypisania skopiuje nam wszystkie wartości pól
	// czyli name, tableSize, oraz referencję do table
	// a przez to, że skopiuje nam referencję do table, to wszystkie zmiany jakie zrobimy w c_tab_1 będą widoczne również
	// w c_tab_0. name i tableSize skopiują się poprawnie.


}