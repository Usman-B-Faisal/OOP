#include<iostream>
using namespace std;

int main()
{
	char* str = new char[200], * vov = new char[100], * sortAlp = new char[5];
	int a = 0, e = 0, I = 0, o = 0, u = 0, con = 0, Vovels = 0, k = 0, * sortNum = new int[5];
	cout << "Enter a Sentence: ";
	cin.getline(str, 200);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'A' || str[i] == 'a') { a++; Vovels++; vov[k] = str[i]; k++; }
		else if (str[i] == 'E' || str[i] == 'e') { e++; Vovels++; vov[k] = str[i]; k++; }
		else if (str[i] == 'I' || str[i] == 'i') { I++; Vovels++; vov[k] = str[i]; k++; }
		else if (str[i] == 'O' || str[i] == 'o') { o++; Vovels++; vov[k] = str[i]; k++; }
		else if (str[i] == 'U' || str[i] == 'u') { u++; Vovels++; vov[k] = str[i]; k++; }
		else if ((str[i] != 'A' || str[i] != 'a') && (str[i] != 'E' || str[i] != 'e') && (str[i] != 'I' || str[i] != 'i') && (str[i] != 'O' || str[i] != 'o') && (str[i] != 'U' || str[i] != 'u') && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] > 'a' && str[i] <= 'z'))) { con++; }
	}
	cout << "Total Consonants: " << con << endl;
	cout << "Total Vovels: " << Vovels << endl;
	cout << "Sorted Array of Vovels with Frequency in Decreasing Order: \n";
	sortAlp[0] = 'A', sortAlp[1] = 'E', sortAlp[2] = 'I', sortAlp[3] = 'O', sortAlp[4] = 'U';
	sortNum[0] = a, sortNum[1] = e, sortNum[2] = I, sortNum[3] = o, sortNum[4] = u;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (sortNum[i] > sortNum[j])
			{
				int temp = sortNum[i];
				sortNum[i] = sortNum[j];
				sortNum[j] = temp;
				char temp1 = sortAlp[i];
				sortAlp[i] = sortAlp[j];
				sortAlp[j] = temp1;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << sortAlp[i] << ": \t" << sortNum[i] << endl;
	}
	delete[]str;
	delete[]vov;
	delete[]sortAlp;
	delete[]sortNum;
}