#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int main()
{
    srand((unsigned)time(NULL));
    
    for(int i =0; i < 20; i++)
    cout << RandomNumber(1, 10) << endl;
}