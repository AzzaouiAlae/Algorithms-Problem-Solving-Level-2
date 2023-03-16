#include <iostream> 
#include <string>
using namespace std;

void Print1To10() {
    cout << char(9);

    for (int i = 1; i <= 10; i++)    
        cout << char(9) << i;
    
    cout << endl;
}

void PrintTab(int Num) {
    for (int i = 0; i < Num; i++)
        cout << char(9);
}

void Print_(int Num) {
    for (int i = 0; i < Num; i++)
        cout << "_";
}

int CalcMultip(int i, int j) {
    return i * j;
}

void MultipTable() {
    for (int i = 1; i <= 10; i++)    {
        cout << to_string(i) << char(9) << "|";

        for (int j = 1; j <= 10; j++)                 
            cout << char(9) << CalcMultip(i, j);
        
        cout << endl;        
    }
}

void PrintResult()
{
    cout << endl;
    PrintTab(4);
    cout << "   Multiplication Table From 1 to 10\n\n";
    Print1To10();
    Print_(90);
    cout << endl;
    MultipTable();
}

int main()
{
    PrintResult();
}