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

void FillArrayInOrder(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        MyArray[i] = i+1;
}

void CopyArray(int MyArray[100], int MyArray2[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        MyArray2[i] = MyArray[i];
}

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

void swapCalc(int& Num1, int& Num2)
{
    int Temp;
    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void ShuffleOrderArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        swapCalc(MyArray[RandomNumber(1, ArrayLenght) - 1], MyArray[RandomNumber(1, ArrayLenght) - 1]);
}


int main()
{
    srand((unsigned)time(NULL));

    int MyArray[100], ArrayLenght = ReadPrositiveNum("enter the Number of elements : ");

    FillArrayInOrder(MyArray, ArrayLenght);

    cout << "\nArray Elements : \n";
    PrintArray(MyArray, ArrayLenght);

    ShuffleOrderArray(MyArray, ArrayLenght);

    cout << "\nShuffle Array Elements : \n";
    PrintArray(MyArray, ArrayLenght);

}