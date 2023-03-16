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

void PrintArray(int MyArray[100], int ArrayLenght)
{  
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

void CopyArray(int MyArray[100], int MyArray2[100], int ArrayLenght) 
{   
    for(int i = 0; i < ArrayLenght; i++)
        MyArray2[i] = MyArray[i];
}

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], MyArray2[100], ArrayLenght = ReadPrositiveNum("enter the Number of elements : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    cout << "\nArray 1 Elements : ";
    PrintArray(MyArray,ArrayLenght);

    CopyArray(MyArray, MyArray2, ArrayLenght);

    cout << "\nArray 2 Elements After Copy : ";
    PrintArray(MyArray2, ArrayLenght);
}