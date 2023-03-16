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

int ReversNum(int Number)
{
    int RevNum = 0;
    while (Number > 0)
    {
        RevNum = (RevNum * 10) + (Number % 10);
        Number = Number / 10;
    }
    return RevNum;
}

bool IsPalindrome(int Number)
{
    return Number == ReversNum(Number);
}

int main()
{
    int Num = ReadPrositiveNum("Please enter your number : ");
    if (IsPalindrome(Num))
        cout << endl << Num << " is Palindrome number\n";
    else
        cout << endl << Num << " is Not Palindrome number\n";
}