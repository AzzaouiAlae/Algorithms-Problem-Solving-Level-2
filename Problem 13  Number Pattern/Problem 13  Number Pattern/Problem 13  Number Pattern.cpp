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

void PrintInvertedPattern(int Number)
{
    if (Number < 10)
    {
        for (int i = 1; Number >= i; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << i;

            cout << "\n";
        }
    }
    else
    {
        for (int i = 1; Number >= i; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << i;

            cout << "\n";
        }
    }
}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");
    PrintInvertedPattern(Number);
}