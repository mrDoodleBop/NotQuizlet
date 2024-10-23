/*
    File Name : Student.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"
#include "StudySet.h"

Student::Student(string studentName) : name(studentName) {}

string Student::getName() const {
    return name;
}

void Student::addStudySet(StudySet* set) {
    studySets.push_back(set);
}



void Student::printStudentInfo() {
    
}


