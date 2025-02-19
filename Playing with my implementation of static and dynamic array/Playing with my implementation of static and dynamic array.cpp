// Playing with my implementation of static and dynamic array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"C:/Users/Work/Downloads/MyArray.h"
#include"C:/Users/Work/Downloads/VectorPrime.h"


#include<array> 
#include <iostream>
#include<vector> 



int main()
{
	MyArray<int, 14> fourteenDalmations =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
	};

	//fourteenDalmations.print(); 
	//fourteenDalmations.modifyElement(12313, 121233);

	fourteenDalmations.insertElementAt(1, 999);

	fourteenDalmations.print(); 
	
}
