/*
    File Name : Student.cpp
    Author Name : Mackenzie Raleigh & Michael Cates
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"
#include "StudySet.h"

string Student::getName(){

    return this->name;

}

int Student::getAge(){

    return this->age;

}

int Student::getYear(){

    return this->year;

}

void Student::setName(string n){

    this->name = n;

}

void Student::setAge(int a){

    this->age = a;

}

void Student::setYear(int y){

    this->year = y;

}

void Student::printStudent(){

    cout << "\n\n\t\t|--------- STUDENT INFORMATION ----------|";

    cout << "\n\t\tName : " << this->name << "\n\t\tAge : " << this->age << "\n\t\tYear : " << this->year;

    this->sets->printHashTable();

}//end of print student

void Student::addSet(StudySet *set){

    this->sets->putValue(set->getKey(), set);

}//end of addSet



