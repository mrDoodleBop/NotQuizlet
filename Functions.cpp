/*
    File Name : Functions.cpp
    Author Name : Michael Cates & Mackenzie Raleigh
    Date : 10/10/2024
    Purpose : Function definitions file
*/


#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//FUNCTION DEFINITIONS:


/*
    MACKENZIE !

    for editASet function:

    1. ask the user for the name of the set they would like to enter
    2. search the list of studySets in the Student class for the name of the set the user is looking for 
        a. if the name is not in the list display a message to the user informing them, and allow them to enter a new name to search for
    3. ask the user whether they would like to change a term or a definition in the set
    4. search the study set object for the user's input
    5. ask the user what they would like to change the value to
    6. change the value
    7. display a message to the user that the value they wanted to change has been updated


void editASet(Student* student) {
    int setIndex;
    student->printStudySets();  // Assuming this prints the study sets list
    cout << "\n\n\t\tEnter the number of the set you wish to edit: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet* set = &student->getStudySets()[setIndex];
        // Here, provide options like add, delete, edit terms/definitions, etc.
        // This part will need interaction with the user.
    } else {
        cout << "\n\n\t\tInvalid set index!" << endl;
    }
}


    MACKENZIE !

    for quizASet function:
    1. ask the user the name of the set they would like to quiz over
    2. search the list of sets in the student class for the name they entered
        a. if the name is not in the set inform the user and allow them to enter a new name to search for
    3. once the set has been found ask the user how many questions they would like the quiz to be
    4. in a for loop that asks the user's desired number of questions (if the number of questions is greater than the size of the list, than everytime you hit the end of the list restart from the beginning):
        a. start at the beginning of the list
        b. display the definition and have the user enter the term 
        c. run an if/ else statement to test their input
        d. if the user was correct display a message saying they were correct and 
        add a point to a score variable and if not, don't change the score, just display an incorrect message to the user
    5. after the for loop, divide the user's score by the number of questions and then multiply it by 100
    6. display the user's quiz score and ask them if they would like to go again
        a. this will only allow them to requiz over the same set, if they want to quiz over a different set they will have 
        to go back to the menu and choose the quiz a set option again to restart the function



void quizASet(Student* student) {
    int setIndex;
    student->printStudySets();
    cout << "\n\n\t\tEnter the number of the set you wish to quiz over: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet* set = &student->getStudySets()[setIndex];
        // Implement the quizzing functionality
    } else {
        cout << "\n\n\t\tInvalid set index!" << endl;
    }
}

*/


void createASet(Student* user){ 

    //variables:
    string name;

    string in;

    char flag;

    //get name of the set:
    cout << "\n\n\t\t|---------- Creating a Set ----------|";
    cout << "\n\t\tEnter the desired name of the set : ";
    getline(cin, name);

    //dynamically allocate a new study set object:
    StudySet *newSet = new StudySet(name);

    do{

        cout << "\n\t\tEnter a term : ";
        getline(cin, in);

        newSet->append(in);

        cout << "\n\t\tEnter the term's definition : ";
        getline(cin, in);

        newSet->append(in);


    }while(flag != 'n' || flag != 'N');

    //append the new set to the list in the student object:
    user->addStudySet(newSet);

    //delete allocated memory:
    

}//end of createASet function

