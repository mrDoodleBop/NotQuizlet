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
        string name;
        int age;
        int year; //1, 2, 3, etc

        //Hash table of pointers StudySet objects:
        HashTable* sets;
        
    public:

        //constructor:
        Student(){

            name = "N/A";
            age = 18;
            year = 1;

        }//end of default constructor

        Student(string n, int age, int year){

            this->name = n;
            this->age = age;
            this->year = year;

        }//end of overloaded constructor

        //destructor:
        ~Student(){

            cout << "\n\n\t\tDeleting Student Data...";
            sets->~HashTable();

        }

        //setters:
        void setName(string);

        void setAge(int);

        void setYear(int);

        void addSet(StudySet *set);

        //getters:
        string getName();

        int getAge();

        int getYear();

        //printStudent:
        void printStudent();
        

};

#endif 