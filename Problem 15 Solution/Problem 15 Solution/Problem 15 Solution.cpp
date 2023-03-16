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
    for (int Letter = 65; Letter <= 65 + Number - 1; Letter++)
    {        
        for (int j = 1; j <= Letter - 65 + 1; j++)
            cout << (char)Letter;

        cout << "\n";
    }
}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");

    PrintLetterPattern(Number);
}