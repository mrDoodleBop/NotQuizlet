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
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand()

using namespace std;

//FUNCTION DEFINITIONS:



void editASet(Student* student) 
{

    string name;
    int key;

    //get the key for the set:
    cout << "\n\n\t\tEnter the name of the set you would like to edit: ";
    getline(cin, name);

    key = name.size();

    //Ask the user if they are editing a term or a definition:

    //Edit the term or definition:

    
}//end of edit a set function



void quizASet(Student* student) 
{

    string name;
    int key;
    
    //get the key of the set:
    cout << "\n\n\t\tEnter the name of the set you would like to quiz over: ";
    getline(cin, name);

    key = name.size();

    //find the set with the key that matches the name:


    //begin quizzing the user:

}  //end of quizASet function 


void createASet(Student* user){ 

    //variables:
    string name;

    string in;

    char flag;

    //get name of the set:
    cout << "\n\n\t\t|---------- Creating a Set ----------|";
    cout << "\n\t\tEnter the desired name of the set : ";
    cin.ignore();
    getline(cin, name);

    cout << "\n\t\tWould you like to enter a term? (y/n) : ";
    cin >> flag;

    //dynamically allocate a new study set object:
    StudySet *newSet = new StudySet(name);

<<<<<<< HEAD
    cout << "\n\n\t\tWould you like to begin on your study set? (y/n) : ";
    cin >> flag;

    while(flag != 'n' && flag != 'N'){

=======
    while(flag != 'n' && flag != 'N'){
>>>>>>> origin/main
        cout << "\n\t\tEnter a term : ";
        cin.ignore();
        getline(cin, in);

        newSet->append(in);

        cout << "\n\t\tEnter the term's definition : ";
        getline(cin, in);

        newSet->append(in);

<<<<<<< HEAD
        cout << "\n\n\t\tWould you like to enter another term? (y/n) : ";
=======
        cout << "\n\n\t\tWould you like to add another term? (y/n) : ";
>>>>>>> origin/main
        cin >> flag;
    }//end of while loop

    //append the new set to the list in the student object:
    user->addStudySet(newSet);

    //delete allocated memory:
    delete newSet;
    

}//end of createASet function

<<<<<<< HEAD

void studyASet(Student *user){

    cout << "\n\n\t\tStudying a set.";

}//end of studyASet function


void addFile(Student *user){

    cout << "\n\n\t\tAdding a file...";

}//end of addFile function
=======
void studyASet(Student* user){

}//end of studyASet function

void addFile(Student* user){

}//end of addFile function

>>>>>>> origin/main
