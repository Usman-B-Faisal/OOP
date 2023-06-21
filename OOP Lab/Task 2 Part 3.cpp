// EXERCISE NO.3
#include<iostream>
using namespace std;

int* InputArray(int& size);
void OutputArray(int* ptr, const int& size);

int* CompressArray(int* oArr, int& size);
int main()
{
    int size;
    int* ptr = InputArray(size);
    int* p = CompressArray(ptr, size);
    OutputArray(p, size);
}
int* InputArray(int& size)
{
    cout << "Enter Size: ";
    cin >> size;
    int* p = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> *(p + i);
    }
    return p;
}

void OutputArray(int* ptr, const int& size)
{
    cout << "Output Is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << endl;
    }
}

int* CompressArray(int* oArr, int& size)
{
    int* newArr = new int[size];
    int newSize = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (*(oArr + i) != *(oArr + i + 1))
        {
            *(newArr + (newSize++)) = *(oArr + i);
        }
    }
    *(newArr + (newSize++)) = *(oArr + (size - 1));
    size = newSize;
    return newArr;
}