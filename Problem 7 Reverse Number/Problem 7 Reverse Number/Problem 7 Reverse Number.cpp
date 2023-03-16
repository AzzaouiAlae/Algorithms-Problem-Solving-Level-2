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

void ReversNum(int Number)
{
    int RevNum = 0;
    while (Number > 0)
    {
        RevNum = (RevNum * 10) + (Number % 10);
        Number = Number / 10;
    }
    cout << "Revers is : " << RevNum;
}

int main()
{
    string msg = "Please enter your Number : ";
    ReversNum(ReadPrositiveNum(msg));
}