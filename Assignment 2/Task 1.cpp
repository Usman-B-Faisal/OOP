#include<iostream>
using namespace std;

int main()
{
	int size1 = 0, size2 = 0, k = 0, temp = 0;
	char* a = new char[size1], * b = new char[size2];
	const char* U = new char[27];
	U = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// ENTERING ALPHABETS IN ARRAY A
	cout << "Enter size of Array A:";
	cin >> size1;
	cout << "Enter Elements of Array A (In Capital Letters):\n";
	for (int i = 0; i < size1; i++)
	{
		cin >> a[i];
		if (a[i] < 'A' || a[i]>'Z')
		{
			cout << "\nInvalid Input: Enter Alphabets ranging from A-Z in Capital Letters";
			return 0;
		}
	}
	// ENTERING ALPHABETS IN ARRAY B
	cout << "Enter size of Array B:";
	cin >> size2;
	cout << "Enter Elements of Array B (In Capital Letters):\n";
	for (int i = 0; i < size2; i++)
	{
		cin >> b[i];
		if (b[i] < 'A' || b[i]>'Z')
		{
			cout << "\nInvalid Input: Enter Alphabets ranging from A-Z in Capital Letters";
			return 0;
		}
	}
	// INTERSECTION
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
		{
			if (a[i] == b[j])
			{
				k++;
			}
		}
	temp = k;
	char* n = new char[k];
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
		{
			if (a[i] == b[j])
			{
				n[k - temp] = a[i];
				temp--;
			}
		}
	cout << "\nA n B = \n";
	for (int i = 0; i < k; i++)
	{
		if (i % 13 == 0)
		{
			cout << endl;
		}
		cout << n[i] << "\t";
	}
	cout << endl;
	// UNION
	k = 0, temp = 0;
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
		{
			if (a[i] == b[j])
			{
				k++;
			}
		}
	int sizeu = size1 + size2 - k;
	char* u = new char[sizeu];
	for (int i = 0; i < size1; i++)
	{
		u[i] = a[i];
	}
	for (int i = 0; i < size2; i++)
	{
		int count = 0;
		for (int j = 0; j < size1; j++)
		{
			if (a[j] == b[i])
			{
				count = 1;
				break;
			}
		}
		if (count != 1)
		{
			u[size1 + temp] = b[i];
			temp++;
		}
	}
	cout << "\nA u B = \n";
	for (int i = 0; i < sizeu; i++)
	{
		if (i % 13 == 0)
		{
			cout << endl;
		}
		cout << u[i] << "\t";
	}
	cout << endl;
	// U - (A u B)
	k = 0;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < sizeu; j++)
		{
			if (U[i] == u[j])
			{
				k++;
			}
		}
	int sizeCu = 26 + k;
	temp = 0;
	char* Cu = new char[sizeCu];
	for (int i = 0; i < sizeCu; i++)
	{
		int count = 0;
		for (int j = 0; j < sizeu; j++)
		{
			if (U[i] == u[j])
			{
				count = 1;
				break;
			}
		}
		if (count != 1)
		{
			Cu[temp] = U[i];
			temp++;
		}
	}
	cout << "\nU - (A u B) = \n";
	for (int i = 0; Cu[i] != '\0'; i++)
	{
		if (i % 13 == 0)
		{
			cout << endl;
		}
		cout << Cu[i] << "\t";
	}
	cout << endl;
	// A'
	k = 0;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < size1; j++)
		{
			if (U[i] == a[j])
			{
				k++;
			}
		}
	int sizeCa = 26 + k;
	temp = 0;
	char* Ca = new char[sizeCa];
	for (int i = 0; i < sizeCa; i++)
	{
		int count = 0;
		for (int j = 0; j < size1; j++)
		{
			if (U[i] == a[j])
			{
				count = 1;
				break;
			}
		}
		if (count != 1)
		{
			Ca[temp] = U[i];
			temp++;
		}
	}
	cout << "\nA' = \n";
	for (int i = 0; Ca[i] != '\0'; i++)
	{
		if (i % 13 == 0)
		{
			cout << endl;
		}
		cout << Ca[i] << "\t";
	}
	cout << endl;
	// B'
	k = 0;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < size2; j++)
		{
			if (U[i] == b[j])
			{
				k++;
			}
		}
	int sizeCb = 26 + k;
	temp = 0;
	char* Cb = new char[sizeCb];
	for (int i = 0; i < sizeCb; i++)
	{
		int count = 0;
		for (int j = 0; j < size2; j++)
		{
			if (U[i] == b[j])
			{
				count = 1;
				break;
			}
		}
		if (count != 1)
		{
			Cb[temp] = U[i];
			temp++;
		}
	}
	cout << "\nB' =\n";
	for (int i = 0; Cb[i] != '\0'; i++)
	{
		if (i % 13 == 0)
		{
			cout << endl;
		}
		cout << Cb[i] << "\t";
	}
	cout << endl;
	// DELETING ARRAYS
	delete[]U;
	delete[]a;
	delete[]b;
	delete[]n;
	delete[]u;
	delete[]Cu;
	delete[]Ca;
	delete[]Cb;
	return 0;
}