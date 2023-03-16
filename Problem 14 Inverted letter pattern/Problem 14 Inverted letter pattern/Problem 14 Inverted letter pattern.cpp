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
    
    for (int Letter = 64 + Number; Letter >= 64; Letter--)
    {

        for (int j = Letter - 64; j >= 1; j--)
            cout << (char)Letter;

        cout << "\n";
    }
}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");

    PrintInvertedLetterPattern(Number);
}