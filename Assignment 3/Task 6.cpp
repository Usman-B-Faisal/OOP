#include<iostream>
using namespace std;

class publication
{
	char* title;
	float price;
public:
	publication()
	{
		title = NULL;
		price = 0.0;
	}
	void getdata()
	{

		title = new char[50];
		cout << "Enter Title and press '.' to stop: ";
		cin.getline(title, 50, '.');
		cout << "Enter Price Of The Book (Dollars): ";
		cin >> price;
	}
	void putdata()
	{
		cout << "Title: " << title;
		cout << "\nPrice: " << price << " Dollars" << endl;
	}
};
//class sales
//{
//	float Sales[3];
//public:
//	sales()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			Sales[i] = 0.0;
//		}
//	}
//	float getdata()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cout << "Enter Amount Of Sale " << i + 1 << ": ";
//			cin >> Sales[i];
//		}
//		cout << endl;
//		return Sales[3];
//	}
//	void putdata()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cout << "\nAmount Of Sale " << i + 1 << ": " << Sales[i];
//		}
//	}
//};
//class book :public publication, public sales
//{
//	int pagecount;
//public:
//	book()
//	{
//		pagecount = 0;
//	}
//	void getdata()
//	{
//		publication::getdata();
//		cout << "Enter Page Count: ";
//		cin >> pagecount;
//		sales::getdata();
//	}
//	void putdata()
//	{
//		publication::putdata();
//		cout << "\nFor Book Version:\n";
//		cout << "Page Count: " << pagecount << " Pages";
//		sales::putdata();
//	}
//};
//class tape :public publication,public sales
//{
//	float playtime;
//public:
//	tape()
//	{
//		playtime = 0.0;
//	}
//	void getdata()
//	{
//		cout << "Enter Run Time (in minutes): ";
//		cin >> playtime;
//		sales::getdata();
//	}
//	void putdata()
//	{
//		cout << "\n\nFor Tape Version:\n";
//		cout << "Run Time: " << playtime << " mins";
//		sales::putdata();
//	}
//};
class Disk: public publication
{
	int temp;
public:
	Disk()
	{
		temp = 0;
	}
	void getdata()
	{
		publication::getdata();
		cout << "What disk type do you want?\nFor CD enter '0'\nFor DVD enter '1'\nEnter Number: ";
		cin >> temp;
	}
	void putdata()
	{
		publication::putdata();
		cout << "Disk Type: ";
		if (temp == 0)
			cout << "CD";
		if (temp == 1)
			cout << "DVD";
	}
};

int main()
{
//	book b;
//	b.getdata();
//	tape c;
//	c.getdata();
//	b.putdata();
//	c.putdata();
	Disk d;
	d.getdata();
	cout << "---RESULT---\n";
	d.putdata();
	return 0;
}