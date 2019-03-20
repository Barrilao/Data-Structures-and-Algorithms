#include <iostream>
#include "Queue.h"

using namespace std;

void radixsort(int data[], int n) {
int  k, factor=1;
const int radix = 10;
const int digits = 10;
Queue<int> queues[radix];
for (int i=0;i<digits;factor*=radix,i++){
	for (int j=0;j<n;j++)
		queues[(data[j]/factor)%radix].enqueue(data[j]);
	for (int j=k=0;j<radix;j++)
		while (!queues[j].isEmpty())
			data[k++]=queues[j].dequeue();
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
