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

void CopyArrayElement(int MyArray[100], int MyArray2[100], int ArrayLenght, int &Arr2Lenght)
{    
    while (Arr2Lenght < ArrayLenght)
        AddArrayElement(MyArray[Arr2Lenght], MyArray2, Arr2Lenght);
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

    CopyArrayElement(MyArray, MyArray2, ArrayLenght, Arr2Lenght);

    cout << "Array 1 element : ";
    PrintArray(MyArray, ArrayLenght);

    cout << "Array 2 element after copy : ";
    PrintArray(MyArray2, ArrayLenght);
}