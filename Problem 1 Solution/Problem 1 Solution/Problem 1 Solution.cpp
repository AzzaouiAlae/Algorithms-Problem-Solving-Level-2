#include <iostream>
#include <string>

using namespace std;

void PrintTableHeader() {

    cout << endl;

    for (int i = 0; i < 3; i++)
        cout << "\t";

    cout << "Multiplication Table From 1 to 10\n\n";    

    for (int i = 1; i <= 10; i++)
        cout << "\t" << i;

    cout << endl;    

    for (int i = 0; i < 85; i++)
        cout << "_";

    cout << endl;
}

string Colum(int i) {

    string Colum = "";
    if(i != 10)
        Colum = to_string(i) + "   |";
    else
        Colum = to_string(i) + "  |";

    for (int j = 1; j <= 10; j++)
    {
        Colum = Colum + "\t" + to_string(i * j);
    }
    return Colum;
}

void PrintMultiplicationTable() {

    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
        cout << Colum(i) << endl;
}

int main()
{
    PrintMultiplicationTable();
}