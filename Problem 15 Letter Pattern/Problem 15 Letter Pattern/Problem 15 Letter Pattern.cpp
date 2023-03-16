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

void PrintLetterPattern(int Number)
{
    for (int Letter = 65; Number >= 1; Letter++)
    {
        Number--;
        for (int j = 1; j <= Number - (65 + Number - 1 - Letter); j++)
            cout << (char)Letter;

        cout << "\n";
    }
}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");

    PrintLetterPattern(Number);
}