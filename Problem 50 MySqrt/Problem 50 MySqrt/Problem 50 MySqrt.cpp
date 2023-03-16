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

float MySqrt(float Number)
{
    for (float i = 0; i < Number; i += 0.001)
    {
        if (i * i >= Number)
            return int(i * 100)  / (float)100;
    }
}

int main()
{
    float Number = ReadNum("Please enter Number : ");
    cout << "My MySqrt Result =  " << MySqrt(Number) << endl;
    cout << "C++ MySqrt Result = " << sqrt(Number) << endl;
}