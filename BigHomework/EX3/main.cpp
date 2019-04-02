#include<iostream>
#include "PriorityQueue.h"

using namespace std;


int main()
{
    PriorityQueue q;
    node n1(1,0),n2(0,1),n3(1,2),n4(3,3),n5(1,1),n6(2,2);
    q.enQueue(n1);
    q.enQueue(n2);
    q.enQueue(n3);
    q.enQueue(n4);
    q.enQueue(n5);
    q.enQueue(n6);
    for(int i=0; i<6;i++){
        node res = q.deQueue();
        cout << "(" << res.x << "," << res.y << "), ";
    }


    return 0;
}
