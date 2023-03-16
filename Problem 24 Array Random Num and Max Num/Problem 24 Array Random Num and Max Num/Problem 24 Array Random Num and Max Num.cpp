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
    cout << endl << "Array Elements : ";

    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

int MaxNumInArray(int MyArray[100], int ArrayLenght)
{
    int MaxNum = 0;
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (MyArray[i] > MaxNum)
            MaxNum = MyArray[i];
    }
    return MaxNum;
}

int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], ArrayLenght = ReadPrositiveNum("Please enter the Lenght of Array : ");

    FillArrayRandomNum(MyArray, ArrayLenght);

    PrintArray(MyArray, ArrayLenght);

    cout << "\nMax Number is : " << MaxNumInArray(MyArray, ArrayLenght) << endl;
}