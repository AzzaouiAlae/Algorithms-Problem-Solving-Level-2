#include <iostream>

using namespace std;

void PrintAAAtoZZZ()
{
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int h = 65; h <= 90; h++)
            {
                cout << (char)i << (char)j << (char)h << " ";
            }            
            cout << "--------\n";
        }
        cout << "=========\n";
    }
}

int main()
{
    PrintAAAtoZZZ();
}