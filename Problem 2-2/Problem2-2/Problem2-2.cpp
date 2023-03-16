#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    string wrong = "";
    do {
        cout << wrong << Message;
        cin >> Number;
        wrong = "Number must be > 0!! ";
    } while (Number < 0);
    return Number;
}

enum enPrimeOrNot {
    Prime = 1, NotPrime = 2
};

enPrimeOrNot CheckNumPrime(int Number)
{
    if (Number == 1 || Number == 2)
        return Prime;

    for (int i = 2; i < Number; i++)
    {
        if (Number % i == 0)
            return NotPrime;
    }
    return Prime;
}

void PrintPrimeNumbers()
{
    int Number = ReadPositiveNumber("Please enter your number : ");
    for (int i = 1; i <= Number; i++)
    {
        if (CheckNumPrime(i) == Prime)
            cout << i << endl;        
    }
}

int main()
{
    PrintPrimeNumbers();
}