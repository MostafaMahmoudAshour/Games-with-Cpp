#include <iostream>
#include <random>
#include <ctime>
#include <cctype>

using namespace std;

int Q_NO = 1;
int CORRECT = 0;
int WRONG = 0;
bool ask[10] = {true, true, true, true, true, true, true, true, true, true};

void display_random_question();
void display();
void question(string question, string a, string b, string c, string d, char correct_answer);
void result();

int main()
{
    display();
    return 0;
}

void display(){
    system("cls");
    cout << "Question NO: " << Q_NO << "\t\tCorrect Answers: " << CORRECT << "\t\tWrong Answers: " << WRONG << endl << endl;
    display_random_question();
}

void display_random_question(){
    // Generate a random number
    srand(time(0));
    bool is_question_remaining = false;
    for(int i = 0; i < 10; i++){
        if(ask[i]){
            is_question_remaining = true;
            break;
        }
    }
    while(is_question_remaining){
        int no = rand()%10;
        if(ask[no]){
            ask[no] = false;
            switch(no){
            case 0:
                question("Which language supports the Object Oriented Programming Paradigm ?", "C language",
                         "C++ language", "Cobol language", "Fortran language", 'b');
                         break;
            case 1:
                question("What is a variable ?", "An empty container in which we store data",
                         "Box", "Data type", "Language", 'a');
                         break;
            case 2:
                question("What is the size of wchar_t in C++ ?", "Based on the number of bits in the system",
                         "2 or 4", "4", "2", 'a');
                         break;
            case 3:
                question(" Who invented C++ ?", "Dennis Ritchie",
                         "Ken Thompson", "Brian Kernighan", "Bjarne Stroustrup", 'd');
                         break;
            case 4:
                question("Which of the following is the correct way to use the standard namespace in C++ ?", "Using namespace std;",
                         "Using namespace standard;", "Using standard namespace;", "Standard namespace used;", 'a');
                         break;
            case 5:
                question("Which of the following is used for comments in C++ ?", "/* comment */",
                         "// comment", "// comment */", "both // comment or /* comment */", 'd');
                         break;
            case 6:
                question("Which of the following user-defined header file extension used in c++ ?", "hg",
                         "cpp", "h", "hf", 'c');
                         break;
            case 7:
                question("Which of the following is a correct identifier in C++ ?", "VAR_1234",
                         "$var_name", "7VARNAME", "7var_name", 'a');
                         break;
            case 8:
                question("Which of the following is not a type of Constructor in C++ ?", " Default constructor",
                         "Parameterized constructor", "Copy constructor", "Friend constructor", 'd');
                         break;
            case 9:
                question("Which of the following type is provided by C++ but not C ?", "double",
                         "float", "int", "bool", 'd');
                         break;
            }
        }
    }
    result();
}
void result(){
    system("cls");
    cout << "Total Questions: " << Q_NO - 1 << endl;
    cout << "Correct Answers: " << CORRECT << endl;
    cout << "Wrong Answers: " << WRONG << endl;
    if(CORRECT > WRONG)
        cout << "Result: Passed" << endl;
    else if(WRONG > CORRECT)
        cout << "Result: Failed" << endl;
    else
        cout << "Result: Tie" << endl;
}

void question(string question, string a, string b, string c, string d, char correct_answer){
    cout << question << endl;
    cout << "A.\t" << a << endl;
    cout << "B.\t" << b << endl;
    cout << "C.\t" << c << endl;
    cout << "D.\t" << d << endl;

    char answer;
    cin >> answer;
    if(tolower(answer) == correct_answer)
        CORRECT++;
    else
        WRONG++;

    Q_NO++;
    display();
}
