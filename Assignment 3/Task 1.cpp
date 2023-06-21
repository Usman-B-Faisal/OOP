#include<iostream>
using namespace std;

class time
{
	int hour, min, sec;
public:
	time()//constructor initializes all to 0
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	time(int h, int m, int s)//constructor assigns value to all
	{
		hour = h;
		min = m;
		sec = s;
	}
	void display()//display displays them in 11:59:59 format
	{
		for (int i = 0;; i++)//loop runs till time is in 11:59:59 format
		{
			if (sec > 59)
			{
				min++;
				sec -= 60;
			}
			if (min > 59)
			{
				hour++;
				min -= 60;
			}
			if (hour > 11)
			{
				hour -= 12;
			}
			if (hour < 12 && min < 60 && sec < 60)//Ending loop when time is in 11:59:59 format
			{
				break;
			}
		}
		cout << "Time: " << hour << ':' << min << ':' << sec;//displaying time
	}
};
int main()
{
	int hours = 0, mins = 0, secs = 0;
	cout << "Enter hours: ";
	cin >> hours;
	cout << "Enter mins: ";
	cin >> mins;
	cout << "Enter secs: ";
	cin >> secs;
	if (hours < 0 || mins < 0 || secs < 0)//check: value cannot be smaller than 0
	{
		cout << "Invalid Input\n";
		return 0;
	}
	time a(hours, mins, secs);
	a.display();//displaying time
	return 0;
}