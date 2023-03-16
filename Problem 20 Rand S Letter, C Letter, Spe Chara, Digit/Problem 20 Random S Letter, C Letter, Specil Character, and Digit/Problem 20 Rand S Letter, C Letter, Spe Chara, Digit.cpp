#include <iostream>
#include <cstdlib>

using namespace std;

enum enRandomChar{ SmallLetter = 1, CapitalLetter = 2, SpecilCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char RandomChar(enRandomChar MyRandom)
{
    switch (MyRandom)
    {
    case SmallLetter: return (char)RandomNumber(97, 122);
    case CapitalLetter: return (char)RandomNumber(65, 90);
    case SpecilCharacter: return (char)RandomNumber(33, 47);
    case Digit: return (char)RandomNumber(48, 57);
    default: RandomNumber(33, 122);
    }        
}

int main()
{
    srand((unsigned)time(NULL));
    for(int i =0; i <= 30; i++)
    cout << RandomChar(Digit) << endl;
}