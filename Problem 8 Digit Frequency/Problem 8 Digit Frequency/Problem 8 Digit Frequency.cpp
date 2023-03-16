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

int main()
{
    int Number = ReadPrositiveNum("Plaese enter Number : ");
    short Digit = ReadPrositiveNum("Plaese enter digits : ");
   

    cout << "\nDigit " << Digit << " Frequency is " 
         << DigitFrequency(Number, Digit) << " Time(s)." << "\n";
}