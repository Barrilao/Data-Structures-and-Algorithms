#include <iostream>
#include <mystack.h>

using namespace std;

int main()
{
    Stack<char> myStack;
    string s;

    cout << "Enter a phrase: ";
    cin >> s;

	char suite[20];
	int j=0;
	bool palindrome = true;
	for(int i=0; i<s.length(); i++){
		if(s[i]!=' '){
            myStack.push(s[i]);
            suite[j]=s[i];
            j++;
		}
	}
    int mid = (j/2)+1;
	bool paridad = false;
	if(j%2==0)
        paridad=true;

	for(int i=0; i<j;i++){
        if(myStack.pop()!=suite[i]){
            if(paridad||(!paridad&&j!=mid))
                palindrome=false;
            }
	}

	if(palindrome)
        cout << "It is palindrome :)";
	else
        cout << "It is not palindrome :(";

	return 0;
}




