#include <iostream>
#include <cstdlib>

using namespace std;

enum QuesLevel{Easy = 1, Med = 2, Hard = 3, MixLevel = 4};

enum OpType{Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stResults
{
    short HowManyQues;
    QuesLevel Level;
    OpType Operation;
    short RightAnswers = 0;
    short WrongAnswers = 0;
    bool Pass;
};

int ReadNumberInRange(string Message, int From, int To)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

short RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void ChooseNumbers(short Number[2], stResults AllResults)
{
    switch (AllResults.Level)
    {
    case Easy : Number[0] = RandomNumber(1, 10);
                Number[1] = RandomNumber(1, 10);
                break;
    case Med :  Number[0] = RandomNumber(10, 30);
                Number[1] = RandomNumber(10, 30);
                break;
    case Hard : Number[0] = RandomNumber(20, 100);
                Number[1] = RandomNumber(20, 100);
                break;
    default : Number[0] = RandomNumber(1, 100);
              Number[1] = RandomNumber(1, 100);
              break;
    }             
}

void PrintQuestion(short Number[2], stResults AllResults, OpType Mix)
{
    if (AllResults.Operation != MixOp)
    {
        switch (AllResults.Operation)
        {
        case Add: cout << Number[0] << " + " << Number[1] << " = "; break;            
        case Sub: cout << Number[0] << " - " << Number[1] << " = "; break;
        case Mul: cout << Number[0] << " * " << Number[1] << " = "; break;
        case Div: cout << Number[0] << " * " << Number[1] << " = "; break;
        default : break;
        }
    }
    else
    {
        switch (Mix)
        {
        case Add: cout << Number[0] << " + " << Number[1] << " = "; break;
        case Sub: cout << Number[0] << " - " << Number[1] << " = "; break;
        case Mul: cout << Number[0] << " * " << Number[1] << " = "; break;
        case Div: cout << Number[0] << " * " << Number[1] << " = "; break;
        default: break;
        }
    }
}

short RightAnser(short Number[2], stResults AllResults, OpType Mix)
{
    if (AllResults.Operation != MixOp)
    {
        switch (AllResults.Operation)
        {
        case Add: return Number[0] + Number[1];
        case Sub: return Number[0] - Number[1];
        case Mul: return Number[0] * Number[1];
        case Div: return Number[0] / Number[1];
        default: break;
        }
    }
    else
    {
        switch (Mix)
        {
        case Add: return Number[0] + Number[1];
        case Sub: return Number[0] - Number[1];
        case Mul: return Number[0] * Number[1];
        case Div: return Number[0] / Number[1];
        default: break;
        }
    }
}

void PrintAnser(short Number[2], stResults &AllResults, OpType Mix, short PlayerAnser)
{
    short rightAnser = RightAnser(Number, AllResults, Mix);

    if (PlayerAnser == rightAnser)
    {
        cout << "_______________________\n";
        cout << "Right Anser :-)\n\n";
        system("color 2F");
        AllResults.RightAnswers++;
    }
    else
    {
        cout << "_______________________\n";
        cout << "Worng Answer :-(\n";
        cout << "The Right Answer is : " << rightAnser << endl << endl;
        system("color 4F");
        AllResults.WrongAnswers++;
    }
}

void QuestionResult(short Number[2], stResults &AllResults)
{
    OpType Mix = MixOp;
    if(AllResults.Operation == MixOp)
        Mix = (OpType)RandomNumber(1, 4);

    PrintQuestion(Number, AllResults, Mix);

    short PlayerAnser;

    cin >> PlayerAnser;

    PrintAnser(Number, AllResults, Mix, PlayerAnser);
}

void Questions(stResults &AllResults)
{
    short NumQuestion[2];
    for (short i = 0; i < AllResults.HowManyQues; i++)
    {
        ChooseNumbers(NumQuestion, AllResults);
        cout << "\nQuestion [" << i + 1 << "/" << AllResults.HowManyQues << "]\n";
        QuestionResult(NumQuestion, AllResults);
    }
    AllResults.Pass = AllResults.RightAnswers >= AllResults.WrongAnswers;

}

string PassFail(stResults AllResults)
{
    if (AllResults.Pass)
    {
        system("color 2F");
        return "\n____________________________\nFinal Results is Pass :-)\n____________________________\n";
    }
    else 
    {
        system("color 4F");
        return "\n____________________________\nFinal Results is Fail :-(\n____________________________\n";
    }
}

string LevelName(stResults AllResults)
{
    string Level[5] = { "", "Easy", "Mid", "Hard", "MixLevel" };
    return Level[AllResults.Level]; 
}

string OpTypeName(stResults AllResults)
{
    string Type[6] = { "", "Add", "Sub", "Mul", "Div", "MixOp" };
    return Type[AllResults.Operation];
}

void FinalResults(stResults AllResults)
{    
    cout << PassFail(AllResults);
    cout << "Number Of Questons          : " << AllResults.HowManyQues << endl;
    cout << "Question Level              : " << LevelName(AllResults) << endl;
    cout << "Operation Type              : " << OpTypeName(AllResults) << endl;
    cout << "Number Of the right answers : " << AllResults.RightAnswers << endl;
    cout << "Number of Wrong answers     : " << AllResults.WrongAnswers << endl;
    cout << "____________________________\n";    
}

bool PlayAgain()
{
    char YesNo;
    cout << "\nDo You Wount To Play Again? y/n : ";
    cin >> YesNo;
    return YesNo == 'y' || YesNo == 'Y';
}

void Game()
{
    do {
        system("CLS");
        system("color 0F");
        stResults AllResults;
        AllResults.HowManyQues = ReadNumberInRange("How Many Question do you Want to answer? : ", 1, 100);

        AllResults.Level = (QuesLevel)ReadNumberInRange("Enter Questions Level 1)Easy, 2)Med, 3)Hard, 4)Mix : ", 1, 4);

        AllResults.Operation = (OpType)ReadNumberInRange("Enter Operation Type 1)Add, 2)Sub, 3)Mul, 4)Div, 5)Mix : ", 1, 5);

        Questions(AllResults);

        FinalResults(AllResults);
    } while (PlayAgain());
    
}

int main()
{
    srand((unsigned)time(NULL));

    Game();
}