#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
class Telephone
{
private:

	char* FIO;
	char* phoneHome;
	char* phoneWork;
	char* phoneMobile;
	char* comments;


public:
	static Telephone input();
	void print(Telephone phone);
	static void writeToFile(Telephone phone[], int size);
	static void readFromFile(Telephone phone[], int& size);


	static void printAllContacts(Telephone phone[], int size);

	static void deleteContact(Telephone phone[], int& size, int userNumber);
	static void printByFIO(Telephone phone[], int& size);
	int searchByFIO(Telephone phone[], int size, string nameKey);
	void printAllContacts(Telephone phone[], int size);
};

char* copyLine(string);
