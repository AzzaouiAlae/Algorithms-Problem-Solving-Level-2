#include <iostream>

using namespace std;

short FindNumPositionInArray(int NumSearch, int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (MyArray[i] == NumSearch)
            return i;
    }
    return -1;
}

bool CheckNumInArray(int NumSearch, int MyArray[100], int ArrayLenght)
{
    return FindNumPositionInArray(NumSearch, MyArray, ArrayLenght) != -1;
}

void AddArrayElement(int Number, int MyArray[100], int& ArrayLenght)
{
    MyArray[ArrayLenght] = Number;
    ArrayLenght++;
}

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

void CopyDistinctNum(int MyArray[10], int MyArray2[10], int& Arr2Lenght)
{
    for (int i = 0; i < 10; i++)
    {
        if (!CheckNumInArray(MyArray[i], MyArray2, Arr2Lenght))
            AddArrayElement(MyArray[i], MyArray2, Arr2Lenght);
    }
}

int main()
{
    int MyArr1[10] = { 10,10,10,50,20,50,70,70,70,90 };
    int Arr2[10], Arr2Lenght = 0;

    CopyDistinctNum(MyArr1, Arr2, Arr2Lenght);

    cout << "Array 1 element:\n";
    PrintArray(MyArr1, 10);
    cout << "\n";

    cout << "Array 2 distinct element:\n";
    PrintArray(Arr2, Arr2Lenght);
}