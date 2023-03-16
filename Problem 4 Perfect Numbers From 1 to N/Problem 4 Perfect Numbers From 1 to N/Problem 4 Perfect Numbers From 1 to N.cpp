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

void PrintPerfectNumToN(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPerfect(i))
            cout << i << endl;
    }
}

int main()
{
    string msg = "Please enter your number : ";
    PrintPerfectNumToN(ReadPrositiveNum(msg));
}