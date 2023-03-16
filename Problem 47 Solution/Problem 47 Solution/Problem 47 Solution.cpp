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

int MyRound(float Number)
{
    int IntPart = Number;
    float FractionPart = GetFractionNum(Number);

    if (abs(FractionPart) > 0)
    {        
        if (Number < 0)
            return --Number;
        else
            return ++Number;
    }
    else    
            return Number;
    
}

int main()
{
    float Number = ReadNum("Please enter Number : ");
    cout << "My Round Result =  " << MyRound(Number) << endl;
    cout << "C++ Round Result = " << round(Number) << endl;
}