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

void PrintDigits(int Number)
{
    while (Number > 0)
    {
        cout << (Number % 10) << endl;
        Number = Number / 10;
    }
}

void PrintDigitsInOrder()
{
    int Num = ReversNum(ReadPrositiveNum("Please enter your number : "));

    PrintDigits(Num);
}

int main()
{
    PrintDigitsInOrder();
}