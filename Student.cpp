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

void Student::printStudentInfo() const {
    cout << "Student Name: " << name << endl;
    cout << "Study Sets:" << endl;
    for (StudySet* set : studySets) {
        cout << "- " << set->getSetName() << endl;
    }
}

StudySet* Student::getStudySet(const string& setName) {
    for (StudySet* set : studySets) {
        if (set->getSetName() == setName) {
            return set;
        }
    }
    return nullptr;
}