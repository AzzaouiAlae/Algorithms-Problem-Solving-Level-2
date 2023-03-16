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

void PrintInvertedLetterPattern(int Number)
{
    int test;
    for (int Letter = 65 + Number - 1; Letter >= 65; Letter--)
    {
        test = Letter - 64;
        for (int j = 1; j <= test; j++)
            cout << (char)Letter;

        cout << "\n";
    }
}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");

    PrintInvertedLetterPattern(Number);
}