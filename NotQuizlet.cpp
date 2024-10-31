/*
    File Name : NotQuizlet.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : Driver file for the NotQuizlet program
*/

#include "Functions.h"

//main function:
int main(){

    //variables:
    char flag;
    string name, fileName;
    int age, year, choice;


    Student* user = new Student;


    system("CLS");
    cout << "\n\n\t\t|---------- NOT QUIZLET ----------|";
    cout << "\n\n\t\tWould you like to begin? (y/n) : ";
    cin >> flag;

    if(flag == 'y' || flag == 'Y'){

        cout << "\n\n\t\t|---------- Creating Student Profile ----------|";
        cout << "\n\t\tEnter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "\n\t\tEnter your age : ";
        cin >> age;
        cout << "\n\t\tEnter your year in school (1, 2, 3, 4, etc.) : ";
        cin >> year;

        user->setAge(age);
        user->setName(name);
        user->setYear(year);

    }//end of student creation


    //While loop to run as long as the user would like:
    while(flag == 'y' || flag == 'Y'){

        //print menu:
        cout << "\n\n\t\t|---------- Menu ----------|";
        cout << "\n\t\t1. See my Information";
        cout << "\n\t\t2. Create a Study Set";
        cout << "\n\t\t3. Edit a Study Set";
        cout << "\n\t\t4. Quiz Me Over a Set";
        cout << "\n\t\t5. Study a Set";
        cout << "\n\t\t6. End Program\n\t\tEnter your choice : ";

        cin >> choice;

        if(choice == 1){

            user->printStudent();

        } else if (choice == 2){

            user->createASet();

        } else if (choice ==3){

            user->editASet();

        } else if (choice == 4){

            user->quizASet();

        } else if(choice ==5){

            user->studyASet();

        } else {

            break;

        }//end of conditional branches


        /*
        //switch the user's choice:
        switch(choice){

            case 1 : 
                user->printStudent();
                break;
            case 2 :
                user->createASet();
                break;
            case 3:
                user->editASet();
                break;
            case 4:
                user->quizASet();
                break;
            case 5:
                user->studyASet();
                break;
            case 6:
                break;

        };//end of switch
        */

        cout << "\n\n\t\tWould you like to see the menu again? (y/n) : ";
        cin >> flag;

    }//end of while loop

    cout << "\n\n\t\tWould you like to save your student information to a txt file? (y/n) : ";
    cin >> flag;

    if(flag == 'y' || flag == 'Y'){

        cout << "\n\n\t\t|---------- Adding a File ----------|";
        cout << "\n\t\tEnter the desired file name, ending with .txt";
        getline(cin, fileName);

        addFile(user, fileName);

    }//end of conditional branch

    //delete allocated memory:
    delete user;

    
    //return value:
    return 0;
    
}//end of main function