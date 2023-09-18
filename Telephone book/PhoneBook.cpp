#include "PhoneBook.h"
#include "Telephone.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Contact PhoneBook::addContact() {
	Contact phone = phone.input();
	contacts[size] = phone;
	//contacts[size] = new Contact();
	phone.print();
	size++;
	return phone;
}


void PhoneBook::printAllContacts() {
	cout << endl << "Contacts list:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  N:          " << i + 1 << endl;
		contacts[i].print();
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
			outputFile << contacts[i].getFIO() << endl;
			outputFile << contacts[i].getPhoneHome() << endl;
			outputFile << contacts[i].getPhoneMobile() << endl;
			outputFile << contacts[i].getPhoneWork() << endl;
			outputFile << contacts[i].getComments() << endl;
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

		for (int i = 0; i < count; i++) {
			Contact t = Contact();

			getline(file, line);
			if (!line.empty()) {
				t.setFIO(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t.setPhoneHome(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t.setPhoneMobile(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t.setPhoneWork(copyLine(line));
			}

			getline(file, line);
			if (!line.empty()) {
				t.setComments(copyLine(line));
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



/*
void PhoneBook::readFromFile() {
	ifstream file("telephone_data.txt");

	if (file.is_open()) {

		string line;
		getline(file, line);
		int count = stoi(line);

		for (int i = 0; i < count; i++) {
			Contact t = Contact();
			getline(file, line);
			t.setFIO(copyLine(line));
			getline(file, line);
			t.setPhoneHome(copyLine(line));
			getline(file, line);
			t.setPhoneMobile(copyLine(line));
			getline(file, line);
			t.setPhoneWork(copyLine(line));
			getline(file, line);
			t.setComments(copyLine(line));
			contacts[i] = t;
		}
		size = count;
		file.close();
	}
	else {
		cout << "Oops!" << std::endl;
	}
}
*/
/*
void PhoneBook::deleteContact(int userNumber)

{
	
	int index = userNumber - 1;
	//delete contacts[index];
	for (int i = index; i < size - 1; i++) {
		contacts[i] = contacts[i + 1];
	}
	size--;
}

 
void PhoneBook::doDelete()
{
	int userNumber;
	int userAnswer;
	do {
			
		cout << "Input number of worker to delete";
		cin >> userNumber;
	} while (userNumber <= 0);

	(contacts[userNumber - 1]).print();
	cout << "are you sure that you want to delete this worker?(1=yes,0=no):" << endl;
	cin >> userAnswer;
	if (userAnswer == 1)
	{
		deleteContact( userNumber);
	}
	else {
		cout << "okay (-_-)" << endl;
	}
}

*/

void PhoneBook::deleteContact() {
	int userNumber;
	int userAnswer;
	
	//Contact::getShouldDeleteMemory;
	
	do {

		cout << "Input number of worker to delete";
		cin >> userNumber;
	} while (userNumber <= 0);

	int index = userNumber - 1;
	if (index >= 0 && index < size) {
		contacts[index].print(); // Вывести информацию о контакте
		cout << "Do you want to delete this contact? (1=yes, 0=no): ";
		int userAnswer;
		cin >> userAnswer;
		if (userAnswer == 1) {
			//delete contacts[index]; // Удалить контакт, вызвав его деструктор
			contacts[index].setShouldDelete(true);
			for (int i = index; i < size - 1; i++) {
				contacts[i] = contacts[i + 1];
			}
			size--;
		}
		else {
			cout << "Contact was not deleted." << endl;
		}
	}
}


int PhoneBook::searchByFIO(string nameKey) {
	for (int i = 0; i < size; i++) {

		if (string(contacts[i].getFIO()).find(nameKey) != std::string::npos)
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
		contacts[index].print();
	}
	else {
		cout << "No such worker found" << endl;
	}
}

