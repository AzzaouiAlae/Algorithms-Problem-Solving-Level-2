#include <iostream>
#include <cstdlib>

using namespace std;

enum enOparationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

enum enQuestionLevel {Easy = 1, Med = 2, Hard = 3, MixLevel = 4};

struct stQuestion {
    int Number1;
    int Number2;
    enOparationType QuestionOpType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer;
    int PlayerAnswer;
    bool AnsewerIsRight;
};

struct stQuezz {
    short HowManyQuestions;    
    enOparationType OpType;
    enQuestionLevel QuestionsLevel;
    stQuestion QuestionList[10];
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPass;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadNumberInRange(string Message, int From, int To)
{
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

int CorrectAnswers(stQuestion Question)
{
    switch (Question.QuestionOpType)
    {
    case Add: return Question.Number1 + Question.Number2;
    case Sub: return Question.Number1 - Question.Number2;
    case Mul: return Question.Number1 * Question.Number2;
    case Div: return Question.Number1 / Question.Number2;
    default: return Question.Number1 + Question.Number2;        
    }
}

enQuestionLevel ReadQuestionLevel()
{
    enQuestionLevel Level = (enQuestionLevel)ReadNumberInRange("Enter Question Level 1)Easy, 2)Med, 3)Hard, 4)Mix :", 1, 4);

    return Level;
}

enOparationType ReadOparationType()
{
    enOparationType Oparation = (enOparationType)ReadNumberInRange("Enter Oparation Type 1)Add, 2)Sub, 3)Mul, 4)Div, 5)Mix :", 1, 5);

    return Oparation;
}

stQuestion GenerateQuestion(stQuezz& Quezz, short QuestionNumber)
{
    stQuestion Question;
    Question.QuestionLevel = Quezz.QuestionsLevel;
    Question.QuestionOpType = Quezz.OpType;

    if (Quezz.OpType == MixOp)    
        Question.QuestionOpType = (enOparationType)RandomNumber(1, 4);

    if(Quezz.QuestionsLevel == MixLevel)
        Question.QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);

    if (Question.QuestionLevel == Easy)
    {
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);

        Question.CorrectAnswer = CorrectAnswers(Question);
    }
    else if (Question.QuestionLevel == Med)
    {
        Question.Number1 = RandomNumber(20, 50);
        Question.Number2 = RandomNumber(20, 50);

        Question.CorrectAnswer = CorrectAnswers(Question);
    }
    else
    {
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);

        Question.CorrectAnswer = CorrectAnswers(Question);
    }
    return Question;
}

void GenerateQuestions(stQuezz& Quezz)
{
    for (short Question = 0; Question < Quezz.HowManyQuestions; Question++)    
        Quezz.QuestionList[Question] = GenerateQuestion(Quezz, Question);    
}

string OpTypeText(enOparationType OparationTypeText)
{
    string ArrayOpTypeText[6] = { "", "+", "-", "*", "/", "Mix"};

    return ArrayOpTypeText[OparationTypeText];
}

string QuesLevel(enQuestionLevel Level)
{
    string ArrayQuesLevel[5] = { "", "Easy", "Med", "Hard", "MixLevel" };
    return ArrayQuesLevel[Level];
}

void PrintQuestions(stQuezz Quezz, short QuesNum)
{
    cout << "\nQuestion [" << QuesNum + 1 << "/" << Quezz.HowManyQuestions << "] \n";
    cout << Quezz.QuestionList[QuesNum].Number1 << " " 
         << OpTypeText(Quezz.QuestionList[QuesNum].QuestionOpType) 
         << " " << Quezz.QuestionList[QuesNum].Number2 << " = ";
}

void SetScreenColor(bool AnsewerIsRight)
{
    if (AnsewerIsRight)
        system("color 2F");
    else
        system("color 4F");
}

void ReadAndCorrect(stQuezz &Quezz, short QuesNum)
{
    cin >> Quezz.QuestionList[QuesNum].PlayerAnswer;

    if (Quezz.QuestionList[QuesNum].PlayerAnswer == Quezz.QuestionList[QuesNum].CorrectAnswer)
    {
        cout << "________________\n";
        cout << "Right Ansewrs :-)\n";
        Quezz.QuestionList[QuesNum].AnsewerIsRight = true;
        SetScreenColor(Quezz.QuestionList[QuesNum].AnsewerIsRight);
        Quezz.NumberOfRightAnswers++;
    }
    else
    {
        cout << "________________\n";
        cout << "Wrong Ansewrs :-(\n";
        cout << "The Right Answer is : " << Quezz.QuestionList[QuesNum].CorrectAnswer;
        Quezz.QuestionList[QuesNum].AnsewerIsRight = false;
        SetScreenColor(Quezz.QuestionList[QuesNum].AnsewerIsRight);
        Quezz.NumberOfWrongAnswers++;
    }
}

void AskQuestionsAndCorrectAnsewrs(stQuezz &Quezz)
{
    for (short QuesNum = 0; QuesNum < Quezz.HowManyQuestions; QuesNum++)
    {
        PrintQuestions(Quezz, QuesNum);

        ReadAndCorrect(Quezz, QuesNum);
    }
}

string FinalPass(bool IsPass)
{
    if (IsPass)
    {
        SetScreenColor(IsPass);
        return "Pass :-)";        
    }
    else
    {
        SetScreenColor(IsPass);
        return "Fail :-(";
    }
    return "Pass :-)";
}

void PrintResult(stQuezz& Quezz)
{
    Quezz.IsPass = (Quezz.NumberOfRightAnswers >= Quezz.NumberOfWrongAnswers);
    cout << "\n\n_________________________\n";
    cout << "Final Result is : " << FinalPass(Quezz.IsPass);
    cout << "\n_________________________\n";
    cout << "Number Of Questons          : " << Quezz.HowManyQuestions << endl;
    cout << "Question Level              : " << QuesLevel(Quezz.QuestionsLevel) << endl;
    cout << "Operation Type              : " << OpTypeText(Quezz.OpType)<< endl;
    cout << "Number Of the right answers : " << Quezz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong answers     : " << Quezz.NumberOfWrongAnswers << endl;
    cout << "____________________________\n\n";
}

void StartMahtGame()
{
    stQuezz Quezz;
    Quezz.HowManyQuestions = ReadNumberInRange("How Many Question do you want to answer? 1-10: ", 1, 10);    
    Quezz.QuestionsLevel = ReadQuestionLevel();
    Quezz.OpType = ReadOparationType();

    GenerateQuestions(Quezz);
    AskQuestionsAndCorrectAnsewrs(Quezz);
    PrintResult(Quezz);

}

bool PlayAgain() {
    char playAgain;
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;
    return  playAgain == 'Y' || playAgain == 'y';
}

void ResteScreen()
{
    system("cls");
    system("color 0F");
}

void Game()
{
    do {
        ResteScreen();
        StartMahtGame();
    } while (PlayAgain());
}

int main()
{
    srand((unsigned)time(NULL));

    

    Game();
}