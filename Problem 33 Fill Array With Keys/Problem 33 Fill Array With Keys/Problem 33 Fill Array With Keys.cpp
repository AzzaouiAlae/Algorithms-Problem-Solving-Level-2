#include <iostream>
#include <cstdlib>

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

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecilCharacter = 3, Digit = 4 };

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

void PrintArrayKeys(string Keys[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)
        cout << "Array [" << i << "] : " << Keys[i] << endl;
}

void FillArrayKeys(string Keys[100], int ArrayLenght)
{
    for (int i = 0; i < ArrayLenght; i++)    
        Keys[i] = GenearteKey();
    
}

int main()
{
    srand((unsigned)time(NULL));
    string Keys[100];
    int ArrayLenght = ReadPrositiveNum("Please enter Numbers of Keys : ");

    FillArrayKeys(Keys, ArrayLenght);
    cout << endl;
    PrintArrayKeys(Keys, ArrayLenght);    
}