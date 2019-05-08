#include<iostream>
#include <string>

using namespace std;

class student{
	public:
		string name;
		int id;
	    student(string nam, int i)
        {
			name = nam;
			id=i;
        }
        student(){
			name = "0";
			id=-1;
        }

};
