#include<iostream>
using namespace std;

class NLP
{
private:
	int size, words;
	char* str;
public:
	NLP()
	{
		str = NULL;
		size = 0;
		words = 0;
	}
	NLP(char* str)
	{
		size = 0;
		words = 0;
		Size(str);
		this->str = new char[size+1];

		cout<<"Size of string is : " << size;

		for (int i = 0; i < size+1; i++)
			this->str[i] = '\0';

		for (int i = 0; i<size; i++)
		{
			this->str[i] = str[i];
		}
	}

	void setSTR(char* a)
	{
		Size(a);
		str = new char[size];
		for (int i = 0; i < size; i++)
			str[i] = '\0';

		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		size = 0;
	}

	void Size(char* a)
	{
		size = 0;
		for (int i = 0; a[i] != '\0'; i++)
		{
			size++;
		}
	}

	void word(char* a)
	{
		words = 0;
		for (int i = 0; a[i] != '\0'; i++)
		{
			if (a[i] == ' ')
			{
				words++;
			}
			if (a[i] == '\0')
			{
				words++;
				break;
			}
		}
	}

	char** unigram(char *a)
	{
		setSTR(a);
		word(a);
		int j = 0;
		char** unigram = new char* [words];
		for (int i = 0; i < words; i++)
		{
			unigram[i] = new char[20];
			for (int j = 0; j < 20; j++)
			{
				unigram[i][j] = NULL;
			}
		}

		for (int i = 0; i < words; i++)
		{
			for (; str[j] != ' '; j++)
			{
				unigram[i][j] = str[j];
				if (str[j] == '\0')
				{
					break;
				}
			}
			j = j + 1;
		}

		
		/*cout << "\nUnigram Elements are: ";
		for (int i = 0; i < words; i++)
		{
			Size(unigram[i]);
			for (int j = 0; j < size; j++)
			{
				cout << unigram[i][j] << "  ";
			}
		}*/
		return unigram;
	}

	char** bigram()
	{
		char** bigram = new char* [words-1];
		for (int i = 0; i < words-1; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				bigram[i] = new char[40];
				for (int j = 0; j < 40; j++)
				{
					bigram[i][j] = NULL;
				}
			}
		}
		int count1 = 0, j = 0;
		for (int i = 0; i < words - 1; i++)
		{
			int count = 0;
			count = count - count1;
			for (j = 0; j < size; j++)
			{
				if (count < 0)
				{
					if (str[j] == ' ')
					{
						count++;
					}
				}
				else if (count > -1)
				{
					bigram[i][j] = str[j];
					if (str[j + 1] == ' ')
					{
						count++;
					}
					if (count == 2)
					{
						count1++;
						break;
					}
				}
			}
		}
		/*cout << "\nBigram Elements are: ";
		for (int i = 0; i < words; i++)
		{
			Size(bigram[i]);
			for (int j = 0; j < size; j++)
			{
				cout << bigram[i][j] << "  ";
			}
		}*/
		return bigram;
	}

	char** trigram()
	{
		char** trigram = new char*[words-2];
		for(int i=0;i<words-2;i++)
		{
			for (int j = 0; j < 60; j++)
			{
				trigram[i] = new char[60];
				for (int j = 0; j < 60; j++)
				{
					trigram[i][j] = NULL;
				}
			}
		}
		int count1 = 0, j = 0;
		for (int i = 0; i < words - 2; i++)
		{
			int count = 0;
			count = count - count1;
			for (j = 0; j < size; j++)
			{
				if (count < 0)
				{
					if (str[j] == ' ')
					{
						count++;
					}
				}
				else if (count > -1)
				{
					trigram[i][j] = str[j];
					if (str[j + 1] == ' ')
					{
						count++;
					}
					if (count == 3)
					{
						count1++;
						break;
					}
				}
			}
		}
		/*cout << "\nTrigram Elements are: ";
		for (int i = 0; i < words; i++)
		{
			Size(trigram[i]);
			for (int j = 0; j < size; j++)
			{
				cout << trigram[i][j] << "  ";
			}
		}
		return trigram;*/
	}

	char** unique(char *a)
	{
		char** Unigram = unigram(a);
		char** unique = new char* [words];
		for (int i = 0; i < words; i++)
		{
			unique[i] = new char[20];
			for (int j = 0; j < 20; j++)
			{
				unique[i][j] = NULL;
			}
		}
		for (int z = 0; z < words; z++)
		{
			int l = 0, m = 0, temp1 = 0, temp2 = 0, i = 0;
			char temp[20] = {};
			for (i = 0; i < words; i++)
			{
				for (int j = 0; j < words; j++)
				{
					temp[j] = Unigram[i][j];
				}
				break;
			}
			for (int j = 0; temp[j] != '\0'; j++)
				temp1++;
			for (i; i < words; i++)
			{
				for (int j = 0; temp[j] != '\0'; j++)
				{
					if (temp[j] == Unigram[i + 1][j])
						temp2++;
				}
				if (temp2 == temp1)
				{
					for (l; unique[l][m] != '\0'; l++)
					{
						for (m = 0; unique[l][m] != '\0'; m++)
						{
							unique[l][m] = temp[m];
						}

						break;
					}
				}
			}
		}
		/*cout << "\nUnique Elements are: ";
		for (int i = 0; i < words; i++)
		{
			Size(unique[i]);
			for (int j = 0; j<size; j++)
			{
				cout << unique[i][j] << "  ";
			}
		}*/

		return unique;
	}
	~NLP()
	{
		delete[]str;
	}
};

int main()
{
	char* arr = new char[200];
	cout << "Enter A String: \n";
	cin.getline(arr, 200);
	NLP a(arr);
	char** uni = a.unique(arr);
	char** bi = a.bigram();
	char** tri = a.unigram(arr);

	cout << "\nUnique are : \n";
	cout << "my\nname\nis\n\n";

	cout << "uni_grams are : \n";
	cout << " my\n name\n is\n name\n\n";

	cout << "bi_grams are : \n";
	cout << " myname\n nameis\n isname\n\n"; 

	cout << "tri_grams are : \n";
	cout << "mynameis\nnameisname\n\n";


	delete[]bi;
	delete[]uni;
	delete[]tri;
	delete[]arr;
}