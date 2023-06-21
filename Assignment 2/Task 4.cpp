#include<iostream>
using namespace std;

int main()
{
	int size=0;
	cout<<"Enter size of array: ";
	cin>>size;
	int*arr=new int[size];
	cout<<"Enter values in array: "<<endl;
	for (int i=0;i<size;i++)
	{cin>>arr[i];
	}
	cout<<"\nA"<<"\tHistogram\n";
	for(int i=0;i<size;i++)
	{cout<<arr[i]<<"\t";
	for(int j=0;j<(arr[i]*2);j++)
	{cout<<"*";
	}
	cout<<endl;
	}
	return 0;
}