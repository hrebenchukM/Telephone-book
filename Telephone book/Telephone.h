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
	//bool shouldDeleteMemory;


public:
	static Contact input2();
	void print();
	//static char* copyLine(string);
	void input();
	
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
		
		FIO = new char[strlen(v) + 1];
		strcpy_s(FIO, strlen(v) + 1, v);
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
	
		comments = new char[strlen(v) + 1];
		strcpy_s(comments, strlen(v) + 1, v);
	}


	/*void setShouldDelete(bool should) {
		shouldDeleteMemory = should;
	}*/

	/*bool getShouldDelete() {
		 return shouldDeleteMemory;
	}*/


	Contact()
	{
		
			FIO = nullptr;
			phoneHome = nullptr;
			phoneWork = nullptr;
			phoneMobile = nullptr;
			comments = nullptr;

		//shouldDeleteMemory = false; 
		
	}


	~Contact()
	{
		cout << "Total Destruction!!!";

		if (FIO != nullptr)
		{
			cout << "Delete -> " << FIO << "... \n";
			delete[]FIO;
		}

		delete[] phoneHome;
		delete[] phoneWork;
		delete[] phoneMobile;
		if (comments != nullptr)
		{
			cout << "Delete -> " << comments << "... \n";
			delete[]comments;
		}


	}

	
};


