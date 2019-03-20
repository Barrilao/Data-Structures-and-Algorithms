#include<iostream>
#include "mystack.h"

using namespace std;

int main(){
    int num,total=0;
    cout << "Enter a decimal: ";
    cin >> num;
    Stack<int> s;

    while(num > 0){
        total = num%2;
        num/=2;
        s.push(total);
    }
    while(s.getTopLevel()>0){
        cout << s.pop();
    }
    return 0;
}
