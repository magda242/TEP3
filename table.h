#pragma once

#include <string>
#include <iostream>

#include "constants.h"

class Table {
public:
	Table();
	Table(std::string Name, int Size);
	Table(Table &pcOther);
	~Table();

	void setName(std::string Name);
	bool setNewSize(int tableLength);
	bool append(Table *other);
	void setValueAt(int offset, int newValue);
	Table operator+(Table &table1);
	//Table operator=(Table &other);
	Table& operator+=(int item);
	Table& operator+=(Table &right);
	int getSize();
	Table* clone();

	void print_table();

	int* table;

private:
	std::string name;
	int size;
};
