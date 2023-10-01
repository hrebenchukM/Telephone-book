#pragma once
#include "Telephone.h"
#include <iostream>
using namespace std;


class PhoneBook {
private:
	Contact* contacts[10];
	int size = 0;
public:
	~PhoneBook();
	static char* copyLine(string line);
	void writeToFile();
	void readFromFile();
	void deleteContact();
	void printByFIO();
	int searchByFIO(string nameKey);
	void printAllContacts();
	//void doDelete();
	void addContact();
};

