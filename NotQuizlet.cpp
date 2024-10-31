/*
    File Name : NotQuizlet.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : Driver file for the NotQuizlet program
*/

#include "Functions.h"
#include "StudySet.h"
#include "Student.h"

//main function:
int main(){

    //variables:
    char flag;
    string name;
    int age, year;


    Student* user;


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

        user = new Student(name, age, year);

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
        cout << "\n\t\t6. End Program";

    }//end of while loop



    //delete allocated memory:
    delete user;

    
    //return value:
    return 0;
    
}//end of main function