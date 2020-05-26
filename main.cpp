#include <iostream>
#include "list.h"
using namespace std;
 int main()
{

	setlocale(LC_ALL, "ru");

	List<int> lst;
    cout << "List "<< endl;
	lst.insertFirst(5);
	lst.insertFirst(7);
	lst.insertFirst(101);
    lst.print();
	cout << endl << "deleteLast "<< endl;
	lst.deleteLast();
    lst.print();
	cout << endl << "deleteAtPos  2"  << endl;
	lst.deleteAtPos(1);
    lst.print();
    cout << endl << "new elements" << endl;
	lst.insertFirst(987879);
	lst.insertFirst(667);
    lst.print();
	lst.getLast();
	lst.print();
	return 0;
}
