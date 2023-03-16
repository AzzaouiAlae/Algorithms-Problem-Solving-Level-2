#include <iostream>

using namespace std;

int ReadNegativeNum(string Message)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number > 0);
    return Number;
}

int MyABS(int Num)
{
    if (Num > 0)
        return Num;
    else
        return Num * -1;
}

int main()
{
    int Num = ReadNegativeNum("Please enter Negative Number : ");
    cout << "My ABS : " << MyABS(Num) << endl;

    cout << "C++ ABS : " << abs(Num) << endl;
}