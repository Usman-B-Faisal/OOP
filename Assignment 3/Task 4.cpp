#include<iostream>
using namespace std;

class publication
{
	char *title;
	float price;
public:
	publication()
	{
		title=NULL;
		price = 0.0;
	}
	void getdata()
	{

		title = new char[50];
		cout << "Enter Title and press '.' to stop: ";
		cin.getline(title,50,'.');
		cout << "Enter Price Of The Book (Dollars): ";
		cin >> price;
	}
	void putdata()
	{
		cout<<"Title: "<<title;
		cout << "\nPrice: " << price<<" Dollars"<<endl;
	}
};
class book :public publication
{
	int pagecount;
public:
	book()
	{
		pagecount = 0;
	}
	void getdata()
	{
		publication::getdata();
		cout << "Enter Page Count: ";
		cin >> pagecount;
	}
	void putdata()
	{
		publication::putdata();

		cout << "\nFor Book Version:\n";
		cout << "Page Count: " << pagecount<<" Pages\n";
	}
};
class tape:public publication
{
	float playtime;
public:
	tape()
	{
		playtime = 0.0;
	}
	void getdata()
	{
		cout << "Enter Run Time (in minutes): ";
		cin >> playtime;
	}
	void putdata()
	{
		cout << "\nFor Tape Version:\n";
		cout << "Run Time: " << playtime<<" mins"<<endl;
	}
};
int main()
{
	book b;
	b.getdata();
	tape c;
	c.getdata();
	//Output
	cout << "---RESULT---\n";
	b.putdata();
	c.putdata();
	return 0;
}