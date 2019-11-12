#include "pch.h"
#include "table.h"

#include <iostream>

using namespace std;


//konstruktor bezparametrowy
Table::Table() {
	setNewSize(DEFAULT_SIZE);
	name = DEFAULT_NAME;

	cout << "bezp:" + name << endl;
}


int Table::getSize() {
	return size;
}

//konstruktor z parametrami
Table::Table(std::string Name, int TableLen) {
	setNewSize(TableLen);
	name = Name;

	cout << "parametr: " + name << endl;
}



//konstruktor kopiuj¹cy
Table::Table(Table &Other) {
	name = Other.name + "_copy";

	table = new int[Other.size];

	//	Kopiuje tablicê int
	for (int i = 0; i < Other.size; i++)
	{
		table[i] = Other.table[i];
	}

	size = Other.size;

	cout << "kopiuj: " + name << endl;

}
//destruktor

Table::~Table() {
	if (table != nullptr)
	{
		delete[] table;
	}

	cout << "usuwam " + name << endl;
}


void Table::setName(string Name) {
	name = Name;
}

bool Table::setNewSize(int tableLength) {
	if (tableLength <= 0)
	{
		return false;
	}

	int* temp = new int[tableLength];

	if (temp == nullptr)
	{
		return false;
	}

	if (table != nullptr)
	{ // byla juz zainicjalizowana
		if (tableLength <= size)
		{
			for (int i = 0; i < tableLength; i++)
			{
				temp[i] = table[i];
			}
		}
		else if (tableLength > size)
		{
			for (int i = 0; i < size; i++)
			{
				temp[i] = table[i];
			}

			for (int i = size; i < tableLength; i++)
			{
				temp[i] = DEFAULT_VALUE;
			}
		}
	}
	else
	{ // inicjalizowanie pierwszy raz
		for (int i = 0; i < tableLength; i++)
		{
			temp[i] = DEFAULT_VALUE;
		}
	}

	if (table != nullptr)
	{
		delete[] table;
	}

	table = temp;
	size = tableLength;
	return true;
}



/*
Metodê, CTable *pcClone(), która zwraca nowy obiekt klasy CTable, bêd¹cy klonem
obiektu dla którego pcClone() zosta³o wywo³ane.Na przyk³ad:
CTable c_tab;
CTable *pc_new_tab;
pc_new_tab = c_tab.pcClone();
*/

Table* Table::clone() {
	/*
	CTable c_tab;
	CTable *pc_new_tab;
	pc_new_tab = c_tab.pcClone();

	*/

	return new Table(*this);
}

// Table* a;
// a->b();
// (*a).b();

void mod_tab(Table *pcTab, int iNewSize) {
	pcTab->setNewSize(iNewSize);
}

void mod_tab(Table cTab, int iNewSize) {
	cTab.setNewSize(iNewSize);
}

void Table::print_table()
{
	cout << "[";
	std::string separator;
	for (int i = 0; i < size; i++)
	{
		cout << separator << table[i];
		separator = ", ";
	}
	cout << "]" << endl;
}



//wpisywanie wartoœci do tablicy
void Table::setValueAt(int offset, int newValue) {
	
		if (offset < 0 || offset >= size)
		{
			return;
		}

		table[offset] = newValue;
}
/*

Table Table::operator+=(Table &other) {
	int previousSize = size;
	setNewSize(other.size + size);
	for (int i = 0; i < other.size; i++) {
		table[i + previousSize] = other.table[i];
	}
	name = other.name;
	return *this;
}
*/

Table Table::operator+(Table &right) {
	Table left(*this);

	left.setNewSize(right.size + size);

	for (int i = 0; i < right.size; i++) {
		left.table[i + size] = right.table[i];
	}

	return left;
}



Table& Table::operator+=(int item)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		temp[i] = table[i];
	}
	temp[size] = item;
	delete[] table;
	table = temp;
	size = size + 1;
	return *this;
}

Table& Table::operator+=(Table &other) {
	int previousSize = size;
	setNewSize(other.size + size);
	for (int i = 0; i < other.size; i++) {
		table[i + previousSize] = other.table[i];
	}
	name = other.name;
	return *this;
}


//Table Table::operator=(Table &other)
//{
//	name = other.name;
//	size = other.size;
//	delete[] table;
//	table = new int[size];
//	for (int i = 0; i < size; i++) {
//		table[i] = other.table[i];
//	}
//	return *this;
//}

