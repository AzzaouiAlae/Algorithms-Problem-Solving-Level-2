#include <iostream>
#include <cstdlib>

using namespace std;

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

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

void CopyPrimeNumArray(int MyArray[100], int MyArray2[100], int ArrayLenght, int &Arr2Lenght)
{
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (CheckNumPrime(MyArray[i]) == Prime)
        {
            MyArray2[Arr2Lenght] = MyArray[i];
            Arr2Lenght++;
        }        
    }        
}

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], MyArray2[100], Arr2Lenght = 0, ArrayLenght = ReadPrositiveNum("enter the Number of elements : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    cout << "\nArray 1 Elements : \n";
    PrintArray(MyArray, ArrayLenght);

    CopyPrimeNumArray(MyArray, MyArray2, ArrayLenght, Arr2Lenght);

    cout << "\nArray 2 Prime Elements After Copy : \n";
    PrintArray(MyArray2, Arr2Lenght);
}