// ch19.cpp : Defines the entry point for the console application.
//

#include "std_lib_facilities.h"
#include "myVector.h"


int main()
{
	
	myV::myVector<int> v;
	myV::myVector<int> v2;
	v.push_back(1); 
	v.push_back(2); 
	v.push_back(3); 
	v.push_back(4);  
	v2 = v;
	for (int i = 0; i < 4; i++)
	{
		std::cout << v2[i] << std::endl;
	}

	keep_window_open();
	return 0;
}

