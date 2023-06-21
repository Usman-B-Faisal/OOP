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
		cout << "---Result---\n";
		cout << "Time: " << hour << ':' << min << ':' << sec;//displaying time
	}
	time operator * (float f)//multipling a number with hours, mins and secs of TIME 1
	{
		time A1;
		if (f >= 0) //check: not letting negative number multiply
		{
			A1.sec = sec * f;
			A1.min = min * f;
			A1.hour = hour * f;
		}
		else cout << "<Error: Enter positive number to multiply TIME 1 with next time>\n";
		return A1;
	}
	time operator - (time const& t) {

		time A2;
		if (t.sec > sec)//for subtraction of bigger number from a smaller number
		{
			--min;
			sec += 60;
		}
		A2.sec = sec - t.sec;
		if (t.min > min)//for subtraction of bigger number from a smaller number
		{
			--hour;
			min += 60;
		}
		A2.min = min - t.min;
		if (t.hour > hour)//for subtraction of bigger number from a smaller number
		{
			hour += 12;
		}
		A2.hour = hour - t.hour;
		return A2;
	}

};
int main()
{
	int hours = 0, mins = 0, secs = 0, hours1 = 0, mins1 = 0, secs1 = 0, n = 0;
	cout << "---TIME 1---\n";
	cout << "Enter hours: ";
	cin >> hours;
	cout << "Enter mins: ";
	cin >> mins;
	cout << "Enter secs: ";
	cin >> secs;
	cout << "---TIME 2---\n";
	cout << "Enter hours: ";
	cin >> hours1;
	cout << "Enter mins: ";
	cin >> mins1;
	cout << "Enter secs: ";
	cin >> secs1;
	if (hours < 0 || mins < 0 || secs < 0)//check: value cannot be smaller than 0
	{
		cout << "\n<Invalid Input>\n";
		return 0;
	}
	if (hours1 < 0 || mins1 < 0 || secs1 < 0)//check: value cannot be smaller than 0
	{
		cout << "\n<Invalid Input>\n";
		return 0;
	}
	time a(hours, mins, secs), a1(hours1, mins1, secs1), a2, a3;
	a2 = a - a1;
	a2.display();
	cout << "\nEnter the number you want to multiply with TIME 1 with: ";
	cin >> n;
	a3 = a * n;
	a3.display();
	return 0;
}