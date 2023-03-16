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

void CopyReverseArray(int MyArray[100], int MyArray2[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        MyArray2[i] = MyArray[ArrayLenght-i-1];
}

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    
    int MyArray[100], MyArray2[100], ArrayLenght = ReadPrositiveNum("Please enter number of element : ");

    FillArrayRandomNum(MyArray, ArrayLenght);
        
    CopyReverseArray(MyArray, MyArray2, ArrayLenght);

    cout << "\nArray element : \n";
    PrintArray(MyArray, ArrayLenght);

    cout << "\nReverse Array element : \n";
    PrintArray(MyArray2, ArrayLenght);
}