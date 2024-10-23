/*
    File Name : Student.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"

template <typename T>
Student<T>::Student(T studentName){
    this->name = studentName;
}

template <typename T>
string Student<T>::getName() {
    return this->name;
}

/*

void Student::addStudySet(StudySet* set) {
    studySets.push_back(set);
}



void Student::printStudentInfo() {
    
}
*/