#include <iostream>
#include <map>
#include <vector>
#include "Cli.h"

using namespace std;

//TODO anytime you need to wait for user input to continue use function wait_for_input()

char Cli::manage_Input(const vector<char> &options_vector, bool allow_back)
{
    char option;

    while (true)
    {

        cout << "\n"
             << "Option: ";
        cin >> option;
        bool check_to_break = false;

        if (option == 'Q' || option == 'q'){system("clear"); check_quit = true; break;} // quit the tool

        // validar o input entre as 3 opções (infelizmente um input tp 14827634 é válido pq o primeiro caracter é válido, é oq é irmauns)
        for (char i : options_vector)
        {
            if (option == i || (allow_back && (option == 'b' || option == 'B'))){  // só permitir o 'B' se assim for dito no parametro
                check_to_break = true;
            }
        }

        cin.ignore(INT16_MAX, '\n'); // limpar o buffer para não invalidar uma vez por cada caracter de input, caso escrevam mais q um


        if (check_to_break) break;  // uso o check to break para sair do while loop e não do for :)

        cout << "Invalid Input, please try again"
             << "\n";
    }

    return option;
}

void Cli::startup()
{

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        char option;

        system("clear");
        if(check_quit) break;

        //////////////   Main menu  //////////////

        cout << "\n--- Select one of the following options: ---\n"
             << "\n"
             << "------------ Lists and searches ------------\n"
             << "\n"
             << "[1] - Search for student or student information"
             << "\n"
             << "[2] - Search for UC or UC information"
             << "\n"
             << "[3] - Search for Class or Class information"
             << "\n\n"
             << "------------------ Tools ------------------\n"
             << "\n"
             << "[4] - Class permute"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> v = {'1', '2', '3', '4'};
        option = manage_Input(v, false);

        switch (option) {
            case '1':
                student_Tab();
                break;
            case '2':
                uc_Tab();
                break;
            case '3':
                class_Tab();
                break;
            case '4':
                class_Permute_Tab();
                break;
        }
    }


}


void Cli::student_Tab()
{
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
        if(check_quit) break;
        cout << "\n----------- Students Information -----------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - Get schedule"
             << "\n"
             << "[2] - List Students"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                get_Student_Schedule();
                break;
            case '2':
                list_Students();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::uc_Tab() {
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;


        cout << "\n------------- Unidades Curriculares -------------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - List UCs"
             << "\n"
             << "[2] - Get UC Lectures"
             << "\n"
             << "[3] - Number of Students in given UC"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2','3'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_UCs();
                break;
            case '2':
                get_UC_Lectures();
                break;
            case '3':
                number_Student_UC();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::class_Tab() {

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n----------------- Classes ------------------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - List Classes"
             << "\n"
             << "[2] - Get Class Occupation"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_Classes();
                break;
            case '2':
                get_Class_Occupation();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }

    }
};


void Cli::class_Permute_Tab(){
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n--------------- Class Permute --------------\n"
             << "\n"
             << "---------- Choose how to permute -----------\n"
             << "\n"
             << "[1] - Between two students"
             << "\n"
             << "[2] - One student only"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                permute_Between_Students();
                break;
            case '2':
                permute_One_Student();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

//SUB MENUS


void Cli::get_Student_Schedule() {

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        string up;
        cout << "\nIntroduce the student's UP code (only the number): ";
        cin >> up;
        cout << "\n";
        system("clear");
        if(check_quit) break;

        // função para verificar se o estudante existe

        // o plano é para substituir o up no printf pelo nome do estudante
        // mas ainda não os tenho ent vai ficar o up por agr

        cout << "\n----------- Student up" << up << " ------------\n"
             << "\n"
             << "-------------- Choose a day: ---------------\n"
             << "\n"
             << "[1] - Monday"
             << "\n"
             << "[2] - Tuesday"
             << "\n"
             << "[3] - Wednesday"
             << "\n"
             << "[4] - Thursday"
             << "\n"
             << "[5] - Friday"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2', '3', '4', '5'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                print_Schedule(stoi(up), 1);
                check_To_Brake = true;
                break;
            case '2':
                print_Schedule(stoi(up), 2);
                check_To_Brake = true;
                break;
            case '3':
                print_Schedule(stoi(up), 3);
                check_To_Brake = true;
                break;
            case '4':
                print_Schedule(stoi(up), 4);
                check_To_Brake = true;
                break;
            case '5':
                print_Schedule(stoi(up), 5);
                check_To_Brake = true;
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::list_Students() {
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n--------------- List Students --------------\n"
             << "\n"
             << "------------------ List by -----------------\n"
             << "\n"
             << "[1] - Alphabetical Order"
             << "\n"
             << "[2] - UP Number"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2', '3', '4', '5'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_Students_alpha();
                break;
            case '2':
                list_Students_UP();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::list_Students_alpha(){
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n------- List Students Alphabetically -------\n"
             << "\n"
             << "[1] - Ascending Order"
             << "\n"
             << "[2] - Descending Order"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                //TODO for loop to print in ascending order
                break;
            case '2':
                //TODO for loop to print in descending order
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::list_Students_UP(){
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n------------ List Students By UP -----------\n"
             << "\n"
             << "[1] - Ascending Order"
             << "\n"
             << "[2] - Descending Order"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':

                for(auto student : _setStudent){
                    cout <<"\n" << student.get_Up() << ": " << student.get_Name();
                }
                wait_for_input();
                break;
            case '2':
                //TODO for loop to print in descending order
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}


void Cli::print_Schedule(int up, int day) {
    static std::map<int, std::string> Weekdays = {{1, "Monday"}, { 2,"Tuesday"}, {3,"Wednesday"}, {4,"Thursday"}, {5,"Friday"}};
    system("clear");

    //Student student1(student1.get_Name(), up);
    //auto student = _setStudent.find(student1);


    cout << "\n------ Student up" << up << " " << Weekdays.at(day) << "'s Schedule ------\n";
    //TODO print horario do estudante no dia x

    wait_for_input();
}

void Cli::list_UCs() {

    string year;

    cout << "\nIntroduce the academic year (1-3): ";
    cin >> year;
    system("clear");

    if(year=="1" or year=="2" or year=="3") {

        for (auto uc: _setUc) {

            string UcCode = uc.get_Code();

            if ((UcCode[6] - '0') == (stoi(year) - 1)) {
                cout << "\n" << UcCode;
            }
        }
    }
    else{
        cout << "Invalid Input, please try again\n";
    }
    cin.ignore(INT16_MAX, '\n');

    wait_for_input();
    system("clear");

}


void Cli::get_UC_Lectures(){
    string classCode;

    cout << "\nIntroduce the Class Code (1LEIC01 - 3LEIC15): ";
    cin >> classCode;
    system("clear");

    //TODO Mostrar as aulas da uc dado a string de class code

}


void Cli::number_Student_UC() {
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //Mostrar o numero de students incritos nessa UC

}


void Cli::list_Classes(){

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

        cout << "\n--------------- List Classes ---------------\n"
             << "\n"
             << "------------------- List -------------------\n"
             << "\n"
             << "[1] - All"
             << "\n"
             << "[2] - By UC"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_All_UCs();
                break;
            case '2':
                list_By_UC();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }

    }

}

void Cli::list_All_UCs(){
    //TODO listar todas as turmas
}


void Cli::list_By_UC(){

    string ucCode;
    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //TODO listar as turmas por UC dada
}


void Cli::get_Class_Occupation() {

    string ucCode;
    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //TODO mostrar quantidade de alunos inscritos na uc dada
}

void Cli::permute_Between_Students(){
    system("clear");

    string studentUp1="", studentUp2="";
    cout << "\n----------- Permute two Students -----------\n"
         << "\n"
         << "Choose the first Student (up): ";
    cin >> studentUp1;

    cout << "\nChoose the second Student (up): ";
    cin >> studentUp2;
    cout << "\n";

    if(permute_Between_Students(stoi(studentUp1), stoi(studentUp2))){
        cout << "Student up" << studentUp1 << " changed classes with Student up" << studentUp2 << endl;
    }else{
        cout << "Permute was not possible" << endl;
    }
}


bool Cli::permute_Between_Students(int student1, int student2) {return 1;}

void Cli::permute_One_Student(){
    system("clear");

    string studentUp1="";
    string classCode="";
    cout << "\n----------- Permute one Student ------------\n"
         << "\n"
         << "Choose Student (up): ";
    cin  >> studentUp1;
    cout << "\n"
         << "Choose Class to move student (1LEIC01 - 3LEIC15): ";
    cin  >> classCode;
    cout << "\n";

    if(permute_One_Student(stoi(studentUp1), classCode)){
        cout << "Student up" << studentUp1 << " was changed to class " << classCode << endl;
    }else{
        cout << "Permutation was not possible due to inbalance between classes";
    }

}

bool Cli::permute_One_Student(int studentUp1, string classCodeToChangeTo) {return 1;}




void Cli::wait_for_input(){
    do
    {
        cout << '\n' << "Press ENTER to continue...";
    } while (cin.get() != '\n');

}
