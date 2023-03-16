#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPrositiveNum(string Message)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayRandomNum(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        MyArray[i] = RandomNumber(-100, 100);
}

void AddArrayElement(int Number, int MyArray[100], int& ArrayLenght)
{
    MyArray[ArrayLenght] = Number;
    ArrayLenght++;
}

int NegativeCount(int MyArray[100], int ArrayLenght)
{
    int NegativeNumCount = 0;
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (MyArray[i] < 0)
            NegativeNumCount++;
    }
    return NegativeNumCount;
}

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << " ";
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], ArrayLenght = ReadPrositiveNum("Please enter the number of element : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    cout << "Array 1 element : ";
    PrintArray(MyArray, ArrayLenght);
    cout << endl;

    cout << "Negative Numbers count is : " << NegativeCount(MyArray, ArrayLenght) << endl;
}