#include <iostream>
#include "Queue.h"

using namespace std;

void radixsort(int number[], int n) {
int  k, factor=1;
const int radi = 10;
const int dig = 10;
Queue<int> queues[radi];
for (int i=0;i<dig;factor*=radi,i++){
	for (int j=0;j<n;j++)
		queues[(number[j]/factor)%radi].enqueue(number[j]);
	for (int j=k=0;j<radi;j++)
		while (!queues[j].isEmpty()){
			number[k++]=queues[j].dequeue();
		}
	}
}

void print(int *a,int sz) {
	for(int i=0;i<sz;i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
 int a[] = {4000, 30, 2400, 1, 342, 93, 233, 123};
	const size_t sz = sizeof(a)/sizeof(a[0])-1;

	cout << "Radix Sort: ";
    radixsort(a, sz);
	print(a,sz);

}
