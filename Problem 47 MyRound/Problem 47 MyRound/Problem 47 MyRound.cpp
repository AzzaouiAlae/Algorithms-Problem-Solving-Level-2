#include <iostream>

using namespace std;

float ReadNum(string Message)
{
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
}

int MyRound(float Number)
{
    if (Number < 0)
    {
        int Num = Number;
        if (float(Number - Num) < -0.49)
            return Number - 1;
        else
            return Number;
    }
    else
    {
        int Num = Number;
        if (float(Number - Num) > 0.49)
            return Number + 1;
        else
            return Number;
    }
}

int main()
{
    float Number = ReadNum("Please enter Number : ");
    cout << "My Round Result =  " << MyRound(Number) << endl;
    cout << "C++ Round Result = " << round(Number) << endl;
}