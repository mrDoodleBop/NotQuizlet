/*
    File Name : Student.cpp
    Author Name : Mackenzie Raleigh & Michael Cates
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"
#include "StudySet.h"

Student::Student(){

    this->name = "N/A";
    this->studySets->setSize(0);

}


Student::Student(string studentName, int tableSize){
    this->name = studentName;
    this->studySets->setSize(tableSize);
}

string Student::getName() {
    return this->name;
}


void Student::addStudySet(StudySet* set) {
    
    //determine the key (literally just the length of the name of the set for this project):
    int key = set->getName().size();

    //add set to the hash table:
    studySets->putValue(key, set);

}

// Finds a StudySet by name
StudySet Student::findStudySetByName(const std::string* setName) {
    
    //since the key is just the length of the name of the list, get the key:
    int key = setName->size();

    //call the value function using the key:
    return studySets->value(key);
    

}

void Student::printStudentInfo() {
<<<<<<< HEAD

    cout << "\n\t\t|---------- Student Information ----------|";
    cout << "\n\t\tStudent Name: " << name;

    //check if table is empty:
    if(studySets->isEmpty()){

        cout << "\n\n\t\tYou have no study sets!";

    } else {
        
        cout << "\n\n\t\tDisplaying your study sets!";
        //if not empty, print the table:
        studySets->printHashTable();
=======
    cout << "\n\n\t\t|---------- Student Information ----------|";
    cout << "\n\t\tStudent Name: " << name;

    cout << "\n\n\t\tTesting if the list is empty...";

    for(list<StudySet>::iterator i = studySets->begin(); i != studySets->end(); i++){

        if((i == studySets->begin()) && (i->getName() == "N/A")){
            cout << "\n\n\t\tYou have no study sets! Please create some and try again.";
            return;
        }
>>>>>>> origin/main

    }//end of conditional branch 

   studySets->printHashTable();


    return;

}//end of printStudentInfo function

