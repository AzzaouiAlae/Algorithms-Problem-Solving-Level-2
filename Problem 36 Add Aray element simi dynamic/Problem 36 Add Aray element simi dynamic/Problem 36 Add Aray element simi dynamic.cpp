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
        cout << MyArray[i] << "  ";
    cout << endl;
}

bool MoreNumCheck()
{
    bool check = false;
    cout << "do you want to add more numbers? (0/1) : ";
    cin >> check;
    return check;
}

void AddArrayElement(int MyArray[100], int& ArrayLenght)
{
    MyArray[ArrayLenght] = ReadPrositiveNum("Please enter a number : ");

    while (true)
    {               
        ArrayLenght++;
        if (MoreNumCheck())                   
            MyArray[ArrayLenght] = ReadPrositiveNum("\nPlease enter a number : ");        
        else
            return;
    }
}

int main()
{
    int MyArray[100], ArrayLenght = 0;

    AddArrayElement(MyArray, ArrayLenght);
    cout << "\nElement Array : ";
    PrintArray(MyArray, ArrayLenght);    
}