#include<iostream>
using namespace std;

void cirshift(int &a,int &b,int&c);
int main()
{
	int x=0,y=0,z=0;
	cout<<"Enter X: ";cin>>x;
	cout<<"Enter Y: ";cin>>y;
	cout<<"Enter Z: ";cin>>z;
	cout<<"Before Shifting: \n";
	cout<<"X = "<<x<<endl;
	cout<<"Y = "<<y<<endl;
	cout<<"Z = "<<z<<endl;
	cirshift(x,y,z);
	cout<<"After Shifting: \n";
	cout<<"X = "<<x<<endl;
	cout<<"Y = "<<y<<endl;
	cout<<"Z = "<<z<<endl;
}
void cirshift(int &a,int &b,int&c)
{
	int tempA=b,tempB=c,tempC=a;
	a=tempA;
	b=tempB;
	c=tempC;
	
}