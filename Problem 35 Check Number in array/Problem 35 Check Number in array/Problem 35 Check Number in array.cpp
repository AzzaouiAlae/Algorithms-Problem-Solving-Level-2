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

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], ArrayLenght = ReadPrositiveNum("Please enter the number of elements : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    PrintArray(MyArray, ArrayLenght);

    int NumSearch = ReadPrositiveNum("\nPlease enter a number to search for : ");

    cout << "\nNumber you are looking for is : " << NumSearch << endl;

    if (CheckNumInArray(NumSearch, MyArray, ArrayLenght))    
        cout << "Yes, The number is found\n";
    else
        cout << "No, The number is not found\n";
}