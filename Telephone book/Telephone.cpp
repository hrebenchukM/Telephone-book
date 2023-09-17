#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#define MAX_LEN 100
using namespace std;

char* check(string title, bool checkEmpty) {
	string buff = "";
	while (true) {
		cout << "Enter worker " << title << ": ";
		getline(cin >> ws, buff);

		if (buff.empty()) {
			cout << "Wrong input! Cannot be empty \n";
		}
		else
			break;
	}
	return copyLine(buff);
}

char* check(string title) {
	return check(title, true);
}



Telephone Telephone::input()
{
	Telephone t = Telephone();
	t.FIO = check("first name");
	t.phoneHome = check("Home phone");
	t.phoneMobile = check("Mobile phone");
	t.phoneWork = check("Work phone");
	t.comments = check("Comments", false);
	return t;
}

void Telephone::print(Telephone phone)
{
	cout << "    FIO:" << this->FIO;
	cout << "      Home Phone:" << this->phoneHome;
	cout << "      Work Phone:" << this->phoneWork;
	cout << "      Mobile Phone:" << this->phoneMobile;
	cout << "      Comments:" << this->comments;
}



void Telephone::printAllContacts(Telephone phone[], int size) {
	cout << endl << "Contacts list:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  N:          " << i + 1 << endl;
		print(phone[i]);
	}
}


void Telephone::writeToFile(Telephone phone[], int size)
{
	ofstream outputFile("telephone_data.txt"); 
	if (!outputFile) 
		return;

	outputFile << size << endl;
	for (int i = 0; i < size; i++) {
		outputFile << phone[i].FIO << endl;
		outputFile << phone[i].phoneHome << endl;
		outputFile << phone[i].phoneMobile << endl;
		outputFile << phone[i].phoneWork << endl;
		outputFile << phone[i].comments << endl;
	}
	cout << "Success!" << endl;
}


char* copyLine(string line) {
	char* result = new char[line.length() + 1];
	strcpy_s(result, line.length() + 1, line.c_str());
	return result;
}

void Telephone::readFromFile(Telephone phone[], int &size) {
	ifstream file("telephone_data.txt");

	if (file.is_open()) {

		string line;
		getline(file, line);
		int count = stoi(line);

		for (int i = 0; i < count; i++) {
			Telephone* t = new Telephone;
			getline(file, line);
			t->FIO = copyLine(line);
			getline(file, line);
			t->phoneHome = copyLine(line);
			getline(file, line);
			t->phoneMobile = copyLine(line);
			getline(file, line);
			t->phoneWork = copyLine(line);
			getline(file, line);
			t->comments = copyLine(line);
			phone[i] = *t;
		}
		size = count;
		file.close();
	}
	else {
		cout << "Oops!" << std::endl;
	}
}

void Telephone::deleteContact(Telephone phone[], int& size, int userNumber)

{
	int index = userNumber - 1;
	for (int i = index; i < size - 1; i++) {
		phone[i] = phone[i + 1];
	}
	size--;
}


int Telephone::searchByFIO(Telephone phone[], int size, string nameKey) {
	for (int i = 0; i < size; i++) {
		if (phone[i].FIO.find(nameKey) !=std::string::npos) 
	{
			return i;
	}
	}
	return -1;
}


void Telephone::printByFIO(Telephone phone[], int& size) {
	string nameKey;
	cout << "Enter the last name to find:";
	getline(cin >> ws, nameKey,
		'\n'); 
	int index = searchByFIO(phone, size, nameKey);
	if (index >= 0) {
		print(phone[index]);
	}
	else {
		cout << "No such worker found" << endl;
	}
}

