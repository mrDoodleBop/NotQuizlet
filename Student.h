/*
    File Name : Student.h
    Author Name : Mackenzie Raleigh & Michael Cates
    Date : 10/10/2024
    Purpose : Header file for the Student class
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "StudySet.h"
#include "HashTable.h"
#include <string>
#include <list>

using namespace std;

// Forward declaration of StudySet class (since StudySet will be included later)
//class StudySet;

class Student {
private:
  
    string name;                 // Student's name
<<<<<<< HEAD
    HashTable * studySets = new HashTable();    // Pointer to a list of pointers to StudySet objects
=======
    list<StudySet>* studySets;    // list of pointers to StudySet objects
>>>>>>> origin/main

public:
    // Constructor to initialize student name

    Student();

    Student(string, int);

    // Accessor to get the student's name
    string getName();

    // Method to add a StudySet to the student's list of sets
    void addStudySet(StudySet*);

    // Method to find a StudySet by name
    StudySet findStudySetByName(const string* setName);

    // Method to print student information and all study sets
    void printStudentInfo();


};

#endif 