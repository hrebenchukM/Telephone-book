#include <stdlib.h>
#include <iostream>
#include "Telephone.h"
#include "PhoneBook.h"


using namespace std;

int menu() {
    cout << endl;
    cout << "1.Add new Contact:" << endl;
    cout << "2.Print Contacts:" << endl;
    cout << "3.Write to file:" << endl;
    cout << "4.Read from file:" << endl;
    cout << "5.Find by FIO:" << endl;
    cout << "6.Delete worker:" << endl;
    cout << "7.EXIT:" << endl;

    int choice;
    do {
        cout << "Enter your choice:";
        cin >> choice;
    } while (choice < 1 || choice > 7);
    return choice;
}








void doMenu(PhoneBook phoneBook) {
    int choice;
    

    do {
        choice = menu();
        switch (choice) {
        case 1:
            phoneBook.addContact();
            break;
        case 2:
            phoneBook.printAllContacts();
            break;
        case 3:
            phoneBook.writeToFile();
            break;
        case 4:
            phoneBook.readFromFile();
            break;
        case 5:
            phoneBook.printByFIO();
            break;

        case 6:
            phoneBook.deleteContact();
           // phoneBook.doDelete();
            
            break;
        case 7:
            cout << "Bye!" << endl;
            break;
        }
    } while (choice != 7);
}



int main()
{
    
    
	
    
    PhoneBook phoneBook = PhoneBook();
    doMenu(phoneBook);
   
}