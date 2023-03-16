#include <iostream>

using namespace std;

void PrintArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << MyArray[i] << "  ";
    cout << endl;
}

bool IsPalindromeArray(int MyArray[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
    {
        if (MyArray[i] != MyArray[ArrayLenght-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    int Array1[6] = { 10,20,30,30,20,10 };

   
    cout << "Array 1 element:\n";
    PrintArray(Array1, 6);

    if(IsPalindromeArray(Array1, 6))
        cout << "\nYes, Array is Palindrome.\n";
    else
        cout << "\nNo, Array is not Palindrome.\n";

}