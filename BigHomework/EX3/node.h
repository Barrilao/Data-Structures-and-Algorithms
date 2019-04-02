#include<iostream>

using namespace std;

class node {
    public:
        int x, y;
        double priority;

        node(int i, int j)
        {
            x = i;
            y = j;
            priority = sqrt(pow(x,2)+pow(y,2));
        }
        node(){
            x=0;
            y=0;
            priority=0;
        }
};
