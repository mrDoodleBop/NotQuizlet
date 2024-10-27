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

}


Student::Student(string studentName){
    this->name = studentName;
}

string Student::getName() {
    return this->name;
}


void Student::addStudySet(StudySet* set) {
    
    //add the argument set into the list of linked lists in the student class:

}


void Student::printStudentInfo() {
    cout << "\n\n|---------- Student Information ----------|";
    cout << "\n\t\tStudent Name: " << name;
    cout << "\n\t\tStudy Sets:";

    int n = 1;

    //traverse the list and print the name of every study set in the list:
    for(list<StudySet>::iterator i = studySets->begin(); i != studySets->end(); i++){
        
        cout << "\n\t\t" << n << ". " << i->getName() << " ";
        n++;

    }//end of for loop

}
