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

void PrintInvertedPattern(int Number)
{
    if (Number < 10)
    {
        for (; Number > 0; Number--)
        {
            for (int i = Number; i > 0; i--)            
                cout << Number;
            
            cout << endl;
        }
    }
    else
    {
        for (; Number > 0; Number--)
        {
            for (int i = Number; i > 0; i--)            
                cout << Number << " ";
            
            cout << endl;
        }
    }

}

int main()
{
    int Number = ReadPrositiveNum("Please enter number : ");
    PrintInvertedPattern(Number);
}