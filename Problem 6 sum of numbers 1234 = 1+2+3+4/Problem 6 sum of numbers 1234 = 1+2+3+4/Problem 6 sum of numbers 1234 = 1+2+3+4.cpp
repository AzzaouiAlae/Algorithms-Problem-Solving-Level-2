#include <iostream>
#include <string>

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

void SumOfDigits(int Number)
{
    int sum = 0;
    while (Number > 0)
    {
        sum += (Number % 10);
        Number = Number / 10;
    }
    cout << "Result = " << sum << endl;
}

int main()
{
    string msg = "Please enter Number : ";
    SumOfDigits(ReadPrositiveNum(msg));
}