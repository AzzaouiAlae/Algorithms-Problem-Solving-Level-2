#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecilCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char RandomChar(enCharType MyRandom)
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

int ReadPrositiveNum(string Message)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

string GenerateWord(enCharType MyRandom, short Length)
{
    string Word = "";
    for (short i = 0; i < Length; i++)    
        Word += RandomChar(MyRandom);

    return Word;
}

string GenearteKey()
{
    string Key = "";
    for (int i = 0; i < 4; i++)
    {
        Key += GenerateWord(CapitalLetter, 4);

        if (i != 3)
            Key += "-";
    }
    return Key;
}

void GenerateKeys(int Key)
{
    for (int i = 1; i <= Key; i++)
    {
        cout << "Key [" << i << "] : " << GenearteKey();
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));    
    
    GenerateKeys(ReadPrositiveNum("Please enter Number of keys : "));
}