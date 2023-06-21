#include<iostream>
using namespace std;

int newsize=0;
int* shrinkArray(int* arr1,int size);
int main()
{
	int size=10,*arr1=new int[size];
	cout << "Enter array of 10 elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr1[i];
	}
	int*ptr=shrinkArray(arr1,size);
	cout<<"Shrinked array is: "<<endl;
	for (int i=0;i<newsize;i++)
	{
		cout<<ptr[i]<<"\t";
	}
	delete [] arr1;
	delete [] ptr;
	return 0;
}
int* shrinkArray(int* arr1,int size)
{
	cout << "Enter what size do you want to shrink it to: ";
	
	cin >> newsize;
	int* temp = new int[newsize];
	for (int i = 0; i < newsize; i++)
	{
		temp[i] = arr1[i];
	}
	return temp;
}