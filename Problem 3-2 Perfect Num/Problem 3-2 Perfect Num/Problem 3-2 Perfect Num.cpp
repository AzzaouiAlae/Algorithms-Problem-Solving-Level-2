#include <iostream>

using namespace std;

enum enPerfectNum{Perfect = 1, NotPerfect = 2};

int ReadPrositiveNum(string Message)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

enPerfectNum CheckPerfect(int Number)
{
    int sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            sum += i;
        }
    }

    if (sum == Number)
        return Perfect;

    else
        return NotPerfect;    
}

void PrintResult(int Number)
{
    if (CheckPerfect(Number) == Perfect)    
        cout << "\nPerfect Number\n";
    else
        cout << "\nNumber is not Perfect\n";    
}

int main()
{
    string msg = "Please enter your number : ";
    PrintResult(ReadPrositiveNum(msg));
}