#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

class Contact
{
private:

	char* FIO;
	char* phoneHome;
	char* phoneWork;
	char* phoneMobile;
	char* comments;
	bool shouldDeleteMemory;


public:
	static Contact input();
	void print();
	//static char* copyLine(string);

	
	char* getFIO() {
		return FIO;
	}

	char* getPhoneHome() {
		return phoneHome;
	}

	char* getPhoneWork() {
		return phoneWork;
	}

	char* getPhoneMobile() {
		return phoneMobile;
	}
	
	char* getComments() {
		return comments;
	}

	void setFIO(char* v) {
		FIO = v;
	}

	void setPhoneHome(char* v) {
		phoneHome = v;
	}

	void setPhoneWork(char* v) {
		phoneWork = v;
	}

	void setPhoneMobile(char* v) {
		phoneMobile = v;
	}
	
	void setComments(char* v) {
		comments = v;
	}


	void setShouldDelete(bool should) {
		shouldDeleteMemory = should;
	}


	Contact()
	{
		
			FIO = nullptr;
			phoneHome = nullptr;
			phoneWork = nullptr;
			phoneMobile = nullptr;
			comments = nullptr;

		shouldDeleteMemory = false; 
		
	}

	
	~Contact()
	{
		if (shouldDeleteMemory)
		{
			delete[] FIO;
			delete[] phoneHome;
			delete[] phoneWork;
			delete[] phoneMobile;
			delete[] comments;
		}
	}

	//~Contact();

	
	//static void writeToFile(Contact contacts[], int size);
	//static void readFromFile(Contact contacts[], int& size);
	
	//static void printByFIO(Contact contacts[], int& size);
	//static int searchByFIO(Contact contacts[], int size, string nameKey);
	//static void printAllContacts(Contact contacts[], int size);
	//static Contact addContact(Contact contacts[], int& size);

	//static void deleteContact(Contact contacts[], int& size, int userNumber);
	//static void doDelete(Contact contacts[], int& size);
};


