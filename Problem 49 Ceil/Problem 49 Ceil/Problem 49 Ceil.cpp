#include <iostream>

using namespace std;

float ReadNum(string Message)
{
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
}

float GetFractionNum(float Number)
{
    return Number - (int)Number;
}

int MyCeil(float Number)
{
    int IntPart = Number;
    float FractionPart = GetFractionNum(Number);

    if (FractionPart == 0)
        return Number;

    else
    {
        if (Number < 0)
            return Number;
        else
            return ++Number;
    }
               
}

int main()
{
    float Number = ReadNum("Please enter Number : ");
    cout << "My Ceil Result =  " << MyCeil(Number) << endl;
    cout << "C++ Ceil Result = " << ceil(Number) << endl;
}