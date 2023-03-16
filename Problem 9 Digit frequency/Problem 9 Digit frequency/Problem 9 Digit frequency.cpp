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

int DigitFrequency(int Number, short Digit)
{
    int sum = 0;
    while (Number > 0)
    {
        if (Number % 10 == Digit)
            sum++;
        Number = Number / 10;
    }
    return sum;
}

void PrintDigitFreq(int Number)
{
    int DigitFreq = 0;
    for (short digit = 1; digit <= 10; digit++)
    {
        DigitFreq = DigitFrequency(Number, digit);
        if(DigitFreq != 0)
            cout << "\nDigit " << digit << " Frequency is "
            << DigitFreq << " Time(s)." << "\n";
    }
}

int main()
{
    string msg = "Please enter your number : ";
    PrintDigitFreq(ReadPrositiveNum(msg));
}