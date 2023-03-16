#include <iostream>

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

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << " ";
    cout << endl;
}

void AddArrayElement(int Number, int MyArray[100], int& ArrayLenght)
{
    MyArray[ArrayLenght] = Number;
    ArrayLenght++;
}

void InputUserNumberInArray(int MyArray[100], int& ArrayLenght)
{
    bool AddMore = true;
    do
    {
        int Number = ReadPrositiveNum("Please enter number : ");
        AddArrayElement(Number, MyArray, ArrayLenght);

        cout << "do you want to add more numbers? (0/1) : ";
        cin >> AddMore;

    } while (AddMore);
    
}

int main()
{
    int MyArray[100], ArrayLenght = 0;
    InputUserNumberInArray(MyArray, ArrayLenght);

    //AddArrayElement(MyArray, ArrayLenght);
    cout << "\nElement Array : ";
    PrintArray(MyArray, ArrayLenght);
}