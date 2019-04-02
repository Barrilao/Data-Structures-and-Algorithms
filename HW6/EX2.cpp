#include <iostream>
#include "list.h"

using namespace std;

LinkedList<int> duplicate(LinkedList<int> l) {
	LinkedList<int> d;
	Node<int> *p1, *p2;

	p1 = l.pfirst;
	int n;
	while (p1 != NULL) {
		n = 0;
		p2 = l.pfirst;
		while (p2 != NULL) {
			if (p1->info == p2->info) {
				n++;
			}
			p2 = p2->next;
		}
		if (n >= 2) {
			d.addFirst(p1->info);
			l.removeLastOccurrence(p1->info);
		}
		p1 = p1->next;
	}

	return d;
}


int main() {
	LinkedList<int> list1;
	list1.addFirst(3);
	list1.addFirst(9);
	list1.addFirst(5);
	list1.addFirst(2);
	list1.addFirst(9);
	list1.addLast(5);
	list1.addLast(1);

	cout << "The list of duplicate elements: " << endl;
	duplicate(list1).printList();

}
