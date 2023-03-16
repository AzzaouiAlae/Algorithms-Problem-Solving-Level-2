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

void SearchForNum( int MyArray[100], int ArrayLenght)
{    
    int NumSearch = ReadPrositiveNum("Please enter a Number to Search for : ");

    cout << "\nNumber you are looking for is : " << NumSearch << endl << endl;

    int NumPosition = FindNumPositionInArray(NumSearch, MyArray, ArrayLenght);

    if (NumPosition == -1)    
        cout << "The Number Not found -)\n";

    else
    {
        cout << "The Number found at position: " << NumPosition << endl;
        cout << "The Number found at order: " << NumPosition + 1 << endl << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], ArrayLenght = ReadPrositiveNum("Please enter The Number of element : ");
    cout << "Array 1 element : ";

    FillArrayRandomNum(MyArray, ArrayLenght);

    PrintArray(MyArray, ArrayLenght);    

    SearchForNum(MyArray, ArrayLenght);
}