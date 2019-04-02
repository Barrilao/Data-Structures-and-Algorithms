#include <iostream>
#include "list.h"
#include "stack.h"

using namespace std;

int min2Elem(LinkedList<int> l) {
	struct Node<int> *p;
	Stack<int> s;
	int minimum = 100;

	p = l.pfirst;
	while (p != NULL) {
		if (p->info < minimum)
			minimum = p->info;
		p = p->next;
		s.push(minimum);
	}
	s.pop();
	return s.peek();
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

	cout << "The smallest second element in the list is: ";
	cout << min2Elem(list1) << endl;


}
