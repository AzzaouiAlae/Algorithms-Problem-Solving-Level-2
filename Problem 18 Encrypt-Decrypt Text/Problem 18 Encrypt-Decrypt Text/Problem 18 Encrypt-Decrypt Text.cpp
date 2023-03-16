#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Pass = "";
    cout << "Please enter your text : ";
    getline(cin, Pass);
    cout << endl;
    return Pass;
}

void EncryptText(string& Text, short EncryptKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] += EncryptKey;
    }
}

void DecryptText(string& Text, short EncryptKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] -= EncryptKey;
    }
}

int main()
{
    const short EncryptKey = 2;
    string Text = ReadText();
    EncryptText(Text, EncryptKey);
    cout << "Text After Encryption " << Text << endl;
    DecryptText(Text, EncryptKey);
    cout << "Text After Decryption " << Text << endl;
}