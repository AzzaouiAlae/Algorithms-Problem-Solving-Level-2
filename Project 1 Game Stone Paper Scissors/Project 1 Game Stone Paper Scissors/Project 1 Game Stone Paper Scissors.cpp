#include <iostream>
#include <cstdlib>

using namespace std;

enum enChoice { Stonne = 1, Paper = 2, Scissors = 3 };

short ReadNumberInRange(string Message, short From, short To)
{
    short Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

short ChoiceRound(short thisRound)
{
    short Choice = 0;
    cout << "\nRound [" << thisRound << "] begins : \n";
    cout << "Your Choice : 1)Stone, 2)Paper, 3)Scissors? : ";
    cin >> Choice;
    return Choice;
}

short RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

struct stResults {
    short Round = 0;
    short Player = 0;
    short Computer = 0;
    short Draw = 0;
    string FinalWinner = "";
};

string Choice(short choice)
{
    switch (choice)
    {
    case 1: return "Stone";
    case 2: return "Paper";
    case 3: return "Scissors";
    }
}

string Result(short Player, short Computer, stResults &AllResults)
{
    if (Player == Computer)
    {
        AllResults.Draw++;
        system("color 6F");
        return "No Winner";
    }
    else if (Player == Stonne)
    {
        switch (Computer)
        {       
        case Paper: AllResults.Computer++;
                    system("color 4F"); 
                    cout << "\a";
                    return "Computer";

        case Scissors: AllResults.Player++;
                    system("color 2F"); 
                    return "Player";
        }
    }
    else if (Player == Paper)
    {
        switch (Computer)
        {
        case Stonne: AllResults.Player++;
                     system("color 2F"); 
                     return "Player";

        case Scissors: AllResults.Computer++;
                       system("color 4F"); 
                       cout << "\a";
                       return "Computer";
        }
    }
    else if (Player == Scissors)
    {
        switch (Computer)
        {
        case Stonne: AllResults.Computer++;
                     system("color 4F"); 
                     cout << "\a";
                     return "Computer";

        case Paper: AllResults.Player++;
                    system("color 2F"); 
                    return "Player";
        }
    }
}

void ResultRound(short Player, short Computer, short i, stResults &AllResults)
{
    cout << "\n\n_________Round[" << i << "]__________\n";
    cout << "Player choice : " << Choice(Player) << endl;
    cout << "Computer choice : " << Choice(Computer) << endl;
    cout << "Round Winner : [" << Result(Player, Computer, AllResults) << "]\n";
    cout << "_________________________________________\n\n";         
}

string FinalWinner(stResults Result)
{
    if (Result.Player == Result.Computer)
    {
        system("color 6F");
        return "No Winner";
    }
    else if (Result.Player < Result.Computer)
    {
        system("color 4F");
        cout << "\a";
        return "Computer";
    }
    else
    {
        system("color 2F");
        return "Player";
    }
}

void PrintFinalResult (stResults Result)
{
    cout << "\t\t_________________________________________\n";
    cout << "\t\t\t+++ G a m e   O v e r +++\n";
    cout << "\t\t_________________________________________\n";
    cout << "\t\t____________[ Game Result ]______________\n";
    cout << "\t\t\tGame Rounds        : " << Result.Round << endl;
    cout << "\t\t\tPlayer Won Times   : " << Result.Player << endl;
    cout << "\t\t\tComputer Won Times : " << Result.Computer << endl;
    cout << "\t\t\tDraw Times         : " << Result.Draw << endl;
    cout << "\t\t\tFinal Winner       : " << FinalWinner(Result) << endl;
    cout << "\t\t_________________________________________\n\n";
}

bool PlayAgain()
{
    char YesNo;
    cout << "Do You Wount To Play Again? y/n : ";
    cin >> YesNo;
    return YesNo == 'y' || YesNo == 'Y';
}

void Game()
{
    do {
        system("CLS");
        system("color 0F");
      
        stResults AllResults;
        short Round = ReadNumberInRange("How Many Rounds 1 to 10 : ", 1, 10);
        AllResults.Round = Round;
        short Player, Computer;
        for (int i = 1; i <= Round; i++)
        {
            Player = ChoiceRound(i);

            Computer = RandomNumber(1, 3);

            ResultRound(Player, Computer, i, AllResults);
        }
        
        PrintFinalResult(AllResults);
        

    } while (PlayAgain());    
}

int main()
{
    srand((unsigned)time(NULL));    

    Game();
}
