/*
    File Name : Student.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"
#include "StudySet.h"

template <typename T>
Student<T>::Student(){

    this->name = "N/A";

}

template <typename T>
Student<T>::Student(T studentName){
    this->name = studentName;
}

template <typename T>
string Student<T>::getName() {
    return this->name;
}


template<typename T>
void Student<T>::addStudySet(StudySet<T> set) {
    studySets.push_back(set);
}


template<typename T>
void Student<T>::printStudentInfo() {
    cout << "\n\n|---------- Student Information ----------|";
    cout << "\n\t\tStudent Name: " << name;
    cout << "\n\t\tStudy Sets:";
    for (StudySet* set : studySets) {
        set->printSetInfo();  // Call printSetInfo for each study set
        cout << "\n\n---------------------------" << endl; // Separator for clarity
    }
}
