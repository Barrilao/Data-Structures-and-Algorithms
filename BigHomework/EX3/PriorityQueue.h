#include <bits/stdc++.h>
#include "MyStack.h"

using namespace std;

class PriorityQueue {
    private:
        AdvancedStack s1, s2;
    public:
        void enQueue(node x)
        {
            bool out = false;

            while (!out || !s1.isEmpty()) {
                double maxx = s1.getMax().priority;
                if(!s1.isEmpty()&&s1.peek().priority <= x.priority){
                    s2.push(s1.peek());
                    s1.pop();
                }
                else{
                    s2.push(x);
                    x.priority = maxx+1;
                    out = true;
                }
            }

            while (!s2.isEmpty()) {
                s1.push(s2.peek());
                s2.pop();
            }
        }
        node deQueue()
        {
            if (s1.isEmpty()) {
                cout << "Q is Empty";
                exit(0);
            }
            node x = s1.peek();
            s1.pop();
            return x;
        }
};
