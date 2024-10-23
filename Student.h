/*
    File Name : Student.h
    Author Name : 
    Date : 10/10/2024
    Purpose : Header file for the Student class
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "StudySet.h"
#include <string>
#include <stack>

using namespace std;

// Forward declaration of StudySet class (since StudySet will be included later)
//class StudySet;

template <typename T>
class Student {
private:
    string name;                 // Student's name
    stack<StudySet<T>> studySets;    // Pointer to a list of StudySet objects

public:
    // Constructor to initialize student name
    Student(T studentName);

    // Accessor to get the student's name
    string getName();

    // Method to add a StudySet to the student's list of sets
    void addStudySet(StudySet<T> set);

    // Method to print student information and all study sets
    void printStudentInfo();

};

#endif 