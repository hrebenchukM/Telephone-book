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
	void print();
	static void writeToFile(Telephone phone[], int size);
	static void readFromFile(Telephone phone[], int& size);
;
};

char* copyLine(string);
