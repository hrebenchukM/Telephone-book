#include "PhoneBook.h"
#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PhoneBook::addContact() {// 
	// �������� �������� � ����
	// ���� �� ������� ���������� �� � �����
	// � ���������� �� � ������ ���������
	// �� ��� ���������� ����������� �� ����������� ���� �������� ������ Contact
	// ��� ������ � �������� �� ������������ ������ �������� ������ �� ����������
	// � ���� ������� ��������� ����������� �� ������� � ���� ������� �� ���� ������� � ����������
	// ��������� ������ ��������: ����� ������  ������ Contact � ������� � ���� �������� ��������� �� �� ������������ ��� ������� � ����, � ��� ������ ���� ��������� ����������� �����
	// ������� ������� ������ �� �� �������� Contact � �� ���������� Contact, ������� ����� ��������� �� ������ ������ Contact � ����
	// � ����� ����� ������������ �� ������� � ���������
	Contact* phone=new Contact();
	phone->input();
	contacts[size] = phone;
	phone->print();
	size++;
}


void PhoneBook::printAllContacts() {
	cout << endl << "Contacts list:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  N:          " << i + 1 << endl;
		contacts[i]->print();
	}
}


PhoneBook::~PhoneBook()
{
	for (int i = 0; i < size; i++) {
		delete contacts[i];
	}
}

char* PhoneBook::copyLine(string line) {
	char* result = new char[line.length() + 1];
	strcpy_s(result, line.length() + 1, line.c_str());
	return result;
}

void PhoneBook::writeToFile()
{
	//ofstream outputFile("telephone_data.txt");
	//if (!outputFile)
	//	return;
	ofstream outputFile("telephone_data.txt");
	if (!outputFile.is_open()) {
		cerr << "Failed to open the file for writing." << endl;
		return;
	}
	else {


		outputFile << size << endl;
		for (int i = 0; i < size; i++) {
			outputFile << contacts[i]->getFIO() << endl;
			outputFile << contacts[i]->getPhoneHome() << endl;
			outputFile << contacts[i]->getPhoneMobile() << endl;
			outputFile << contacts[i]->getPhoneWork() << endl;
			outputFile << contacts[i]->getComments() << endl;
		}
		cout << "Success!" << endl;
	}
}

void PhoneBook::readFromFile() {
	ifstream file("telephone_data.txt");
	
	if (file.is_open()) {

		string line;
		getline(file, line);
		int count = stoi(line);

		Contact* t;
		for (int i = 0; i < count; i++) {
			t = new Contact();

			getline(file, line);
			if (!line.empty()) {
				t->setFIO(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t->setPhoneHome(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t->setPhoneMobile(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t->setPhoneWork(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t->setComments(copyLine(line));
			}

			contacts[i] = t;
		}
		size = count;
		file.close();
	}
	else {
		cout << "Oops!" << std::endl;
	}
}





void PhoneBook::deleteContact() {
	int userNumber;
	int userAnswer;
	
	
	do {

		cout << "Input number of worker to delete";
		cin >> userNumber;
	} while (userNumber <= 0);

	int index = userNumber - 1;
	if (index >= 0 && index < size) {
		
		contacts[index]->print(); // ������� ���������� � ��������
		cout << "Do you want to delete this contact? (1=yes, 0=no): ";
		int userAnswer;
		cin >> userAnswer;
		if (userAnswer == 1) {
			
			Contact* deleteContact = contacts[index];
			size--;
			for (int i = index; i < size; i++) {
				contacts[i] = contacts[i + 1];
			}
			delete deleteContact;
			////contacts[index].setShouldDelete(true);
			//
			//Contact c = contacts[index];
			//c.~Contact();
			
		}
		else {
			cout << "Contact was not deleted." << endl;
		}
	}
}


int PhoneBook::searchByFIO(string nameKey) {
	for (int i = 0; i < size; i++) {

		if (string(contacts[i]->getFIO()).find(nameKey) != std::string::npos)
		{
			return i;
		}
	}
	return -1;
}


void PhoneBook::printByFIO() {
	string nameKey;
	cout << "Enter the last name to find:";
	getline(cin >> ws, nameKey,
		'\n');
	int index = searchByFIO(nameKey);
	if (index >= 0) {
		contacts[index]->print();
	}
	else {
		cout << "No such worker found" << endl;
	}
}

