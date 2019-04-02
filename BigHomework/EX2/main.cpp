#include <iostream>
#include <cstring>
#include "building.h"


using namespace std;

int main()
{
    int res[4][5];
    memset(res, 0, sizeof(res));
    res[0][0] =1;
    int CJbuilding[4][5] = {
        {0, 104, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 101, 102},
        {0, 0, 0, 0, 0}
    };
    Building CJ(2,3,res);
    Stack<node> ress, real_ress;
    ress = CJ.mapping(CJbuilding);
    while(!ress.isEmpty()){
        real_ress.push(ress.pop());
    }
    cout << "The path can be:";
    while(!real_ress.isEmpty()){
        node p = real_ress.pop();
        cout << " -> (" << p.x << "," << p.y << ")";
    }

    cout << "\n";

    return 0;
}
