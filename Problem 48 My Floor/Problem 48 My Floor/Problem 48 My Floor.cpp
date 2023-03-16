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

int MyFloor(float Number)
{
    if(Number >=0)
        return Number;

    else
    {
        int IntPart = Number;
        float FractionPart = GetFractionNum(Number);
        if (abs(FractionPart) >= 0.5)
            return Number - 1;
        else
            return Number;
    }
}

int main()
{
    float Number = ReadNum("Please enter Number : ");
    cout << "My Floor Result =  " << MyFloor(Number) << endl;
    cout << "C++ Floor Result = " << floor(Number) << endl;
}