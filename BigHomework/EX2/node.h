#include<iostream>

using namespace std;

class node {
    public:
        int x, y;
        int dir;

        node(int i, int j)
        {
            x = i;
            y = j;
            dir = 0;
        }
        node(){
            x=0;
            y=0;
            dir=0;
        }
};
