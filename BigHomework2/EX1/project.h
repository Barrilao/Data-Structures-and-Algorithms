#include<iostream>
#include <string>

using namespace std;

class project{
	public:
		string name;
		int id;
	    project(string nam, int i)
        {
			name = nam;
			id = i;
        }
        project(){
			name = "0";
			id = -1;
        }
	
};
