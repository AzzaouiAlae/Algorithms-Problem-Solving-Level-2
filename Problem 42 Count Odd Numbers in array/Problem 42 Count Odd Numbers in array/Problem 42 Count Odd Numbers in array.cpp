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
        MyArray[i] = RandomNumber(1, 100);
}

void AddArrayElement(int Number, int MyArray[100], int& ArrayLenght)
{
    MyArray[ArrayLenght] = Number;
    ArrayLenght++;
}

enum enOddorEven { Odd = 1, Even = 2 };

enOddorEven CheckOddOrEven(int Num)
{
    if (Num % 2 == 0)
        return Even;
    else
        return Odd;
}

int OddCount(int MyArray[100], int ArrayLenght)
{
    int OddNumCount = 0;
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (CheckOddOrEven(MyArray[i]) == Odd)
            OddNumCount++;
    }
    return OddNumCount;
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

    cout << "Odd Numbers Count is : " << OddCount(MyArray, ArrayLenght) << endl;
}