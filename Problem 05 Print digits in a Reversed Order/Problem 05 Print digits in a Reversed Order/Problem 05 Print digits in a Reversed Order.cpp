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

void PrintDigits(int Number)
{   
    while(Number > 0)
    {
        cout << (Number % 10) << endl;
        Number = Number / 10;
    }
}

int main()
{
    string msg = "Please enter Number : ";
    PrintDigits(ReadPrositiveNum(msg));
}