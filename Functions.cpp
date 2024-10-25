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

template <typename T>
void editASet(Student<T>* student) {
    int setIndex;
    student->printStudySets();  // Assuming this prints the study sets list
    cout << "Enter the number of the set you wish to edit: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet<T>* set = &student->getStudySets()[setIndex];
        // Here, provide options like add, delete, edit terms/definitions, etc.
        // This part will need interaction with the user.
    } else {
        cout << "Invalid set index!" << endl;
    }
}

template <typename T>
void quizASet(Student<T>* student) {
    int setIndex;
    student->printStudySets();
    cout << "Enter the number of the set you wish to quiz over: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet* set = &student->getStudySets()[setIndex];
        // Implement the quizzing functionality
    } else {
        cout << "Invalid set index!" << endl;
    }
}

//FUNCTION DEFINITIONS