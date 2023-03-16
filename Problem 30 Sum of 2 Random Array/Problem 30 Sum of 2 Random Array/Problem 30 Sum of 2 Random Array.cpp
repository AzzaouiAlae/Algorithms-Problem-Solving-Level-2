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

void Sum2ArrayNumbers(int MyArray[100], int MyArray2[100], int ArraySum[100], int ArrayLenght)
{    
    for (int i = 0; i < ArrayLenght; i++)
        ArraySum[i] = MyArray[i] + MyArray2[i];
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

    int MyArray[100], MyArray2[100], ArraySum[100], ArrayLenght = ReadPrositiveNum("enter the Number of elements : ");

    FillArrayRandomNum(MyArray, ArrayLenght);
    FillArrayRandomNum(MyArray2, ArrayLenght);

    cout << "\nArray 1 Elements : \n";
    PrintArray(MyArray, ArrayLenght);    

    cout << "\nArray 2 Elements : \n";
    PrintArray(MyArray2, ArrayLenght);

    Sum2ArrayNumbers(MyArray, MyArray2, ArraySum, ArrayLenght);

    cout << "\nSum of Elements : \n";
    PrintArray(ArraySum, ArrayLenght);

    cout << "\nMax Number is : " << MaxNumInArray(ArraySum, ArrayLenght);
}