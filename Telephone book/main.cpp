#include <stdlib.h>
#include <iostream>
#include "Telephone.h"

using namespace std;

int main()
{
	Telephone phone[10];
	Telephone t = Telephone::input();
	//phone[0] = t;
	//Telephone::writeToFile(phone,1);
	t.print();
	int size = 0;
//	Telephone::readFromFile(phone, size);
//	phone[0].print();

	//string s = "Bla bla";
	//const char* ss = copyLine(s);
	//cout << ss;

}