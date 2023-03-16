#include <iostream>

using namespace std;

int ReadPrositiveNum(string Message)
{
    int Number;
    string Wrong = "";
    do {
        cout << Wrong <<Message;
        cin >> Number;
        Wrong = "Wrong!! ";
    } while (Number <= 0);
    return Number;
}

bool CheckPerfect(int Number)
{
    int sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            sum += i;
        }
    }

    return sum == Number;
}

void PrintResult(int Number)
{
    if (CheckPerfect(Number))
        cout << Number <<" Perfect Number\n";
    else
        cout << Number << " is not Perfect Number\n";
}

int main()
{
    string msg = "Please enter your number : ";
    PrintResult(ReadPrositiveNum(msg));
}