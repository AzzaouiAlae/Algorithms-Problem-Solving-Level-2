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

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

enPrimeOrNot CheckNumPrime(int Number)
{
    if (Number == 1 || Number == 2)
        return Prime;

    for (int i = 2; i < round(Number / 2); i++)
    {
        if (Number % i == 0)
            return NotPrime;
    }
    return Prime;
}

void CopyPrimeNumArrayElement(int MyArray[100], int MyArray2[100], int ArrayLenght, int& Arr2Lenght)
{
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (CheckNumPrime(MyArray[i]) == Prime)
            AddArrayElement(MyArray[i], MyArray2, Arr2Lenght);
    }
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

    int MyArray[100], MyArray2[100], Arr2Lenght = 0, ArrayLenght = ReadPrositiveNum("Please enter the number of element : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    CopyPrimeNumArrayElement(MyArray, MyArray2, ArrayLenght, Arr2Lenght);

    cout << "Array 1 element : ";
    PrintArray(MyArray, ArrayLenght);
    cout << endl;
    cout << "Array 2 Prime numbers : ";
    PrintArray(MyArray2, Arr2Lenght);
    cout << endl;
}