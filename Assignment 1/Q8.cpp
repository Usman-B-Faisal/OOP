#include<iostream>
using namespace std;

int main()
{
	long value1=200000, value2=0;
	long *longptr;
	longptr=&value1;
	cout<<"Value of object pointed to by longptr is: "<<*longptr<<endl;
	value2=*longptr;
	cout<<"Value 2: "<<value2<<endl;
	cout<<"Adress of value 1: "<<&value1<<endl;
	cout<<"Adress stored in longptr: "<<longptr<<"\n which is same as adress of value 1";
	delete [] longptr;
	return 0;
}