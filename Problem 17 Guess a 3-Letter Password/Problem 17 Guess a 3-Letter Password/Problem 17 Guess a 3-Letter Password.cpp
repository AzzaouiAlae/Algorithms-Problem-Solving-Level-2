#include <iostream>
#include <string>

using namespace std;

string ReadPass()
{
    string Pass = "";
    cout << "Please enter your password : ";
    cin >> Pass;
    cout << endl; 
    return Pass;
}

string Word(int i, int j, int h)
{
    string word = "";
    word = word + (char)i;
    word = word + (char)j;
    word = word + (char)h;
    return word;
}

bool CheckPass(string Word, string Pass)
{
    return Word == Pass;
}

void GessPassword(string Pass)
{    
    int counter = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int h = 65; h <= 90; h++)
            {
                counter++;
                      
                cout << "Trail [" << counter << "] : " << Word(i, j, h) << "\n";

                if (CheckPass(Word(i, j, h), Pass))
                {
                    cout << "\nPassword is " << Pass << endl 
                         << "found After " << counter << " Trial(s)\n";
                    return;
                }
            }                           
            cout << "--------\n";
        }
        cout << "=========\n";
    }
}

int main()
{
    GessPassword(ReadPass());
}