#include <iostream>

using namespace std;

enum enGameChoice{stone = 1, Paper = 2, Scissors = 3};

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

void ResetScreen();

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

struct stGameResult
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner Winner;
    string WinnerName;
};

struct stRoudInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

enGameChoice ReadPlayerChoice()
{
    short Choice = 1;

    do    {
        cout << "\nYour choice: 1)Stone, 2)Paper, 3)Scissors : ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoudInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return Draw;

    switch (RoundInfo.PlayerChoice)
    {
    case stone: 
        if (RoundInfo.ComputerChoice == Paper)
            return Computer;
        break;
    case Paper:
        if (RoundInfo.ComputerChoice == Scissors)
            return Computer;
        break;
    case Scissors:
        if (RoundInfo.ComputerChoice == stone)
            return Computer;
        break;
    }
    return Player;
}

string WinnerName(enWinner Winner)
{
    string ArrWinName[3] = { "Player", "Computer", "No Winner" };

    return ArrWinName[Winner - 1];
}

string ChoiceName(short Choice)
{
    string ArrChoice[3] = { "Stone", "Paper", "Scissors" };

    return ArrChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case Player: system("Color 2F");
        break;
    case Computer: system("Color 4F"); cout << "\a";
        break;
    default: system("Color 6F");
        break;   
    }
}

void PrintRoundResults(stRoudInfo RoundInfo)
{
    cout << "________Round [" << RoundInfo.RoundNumber << "] ________\n";
    cout << "Player Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
    cout << "________________________\n\n";

    SetWinnerScreenColor(RoundInfo.Winner);
}

void ResetScreen()
{
    system("CLS");
    system("color 0F");
}

enWinner HowWonTheGame(short PlayerWinTimes, short ComputerWinTime)
{
    if (PlayerWinTimes > ComputerWinTime)
        return Player;
    else if (PlayerWinTimes < ComputerWinTime)
        return Computer;
    else
        return Draw;
}

stGameResult FillGameResults(short HowManyRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResult GameResults;
    GameResults.PlayerWinTimes = PlayerWinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.GameRounds = HowManyRounds;
    GameResults.DrawTimes = DrawTimes;
    GameResults.Winner = HowWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.Winner);

    return GameResults;
}

stGameResult PlayGame(short HowManyRounds)
{
    stRoudInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRounds = 1; GameRounds <= HowManyRounds; GameRounds++)
    {
        cout << "\nRounds [" << GameRounds << "] begines:\n";
        RoundInfo.RoundNumber = GameRounds;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == Player)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

short ReadHowManyRounds()
{
    short GameRounds = 1;

    do {
        cout << "How Many Rounds 1 to 10: ";
        cin >> GameRounds;
    } while (GameRounds <= 0 || GameRounds > 10);
    return GameRounds;
}

string tab(short NumOfTabs)
{
    string t = "";
    for (short i = 0; i < NumOfTabs; i++)
    {
        t += "\t";
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << tab(2) << "_______________________________\n";
    cout << tab(2) << "   +++ G a m e   O v e r +++\n";
    cout << tab(2) << "________[ Game Result ]________\n";
}

void ShowFinalResults(stGameResult GameResult)
{
    cout << tab(2) << "Game Rounds           : " << GameResult.GameRounds << endl;
    cout << tab(2) << "Player Won Times      : " << GameResult.PlayerWinTimes << endl;
    cout << tab(2) << "Computer Won Times    : " << GameResult.ComputerWinTimes << endl;
    cout << tab(2) << "Draw Times            : " << GameResult.DrawTimes << endl;
    cout << tab(2) << "Final Winner          : " << GameResult.WinnerName << endl;
    cout << tab(2) << "_____________________________\n\n";

    SetWinnerScreenColor(GameResult.Winner);
}

void StartGame()
 {
    char PlayAgain = 'Y';

    do {
        ResetScreen();
        stGameResult GameResult = PlayGame(ReadHowManyRounds());

        ShowGameOverScreen();

        ShowFinalResults(GameResult);

        cout << tab(3) << "Do you want to play Again Y/N : ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
}