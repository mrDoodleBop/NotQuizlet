/*
    File Name : StudySet.h
    Author Name : 
    Date : 10/10/2024
    Purpose : Header file for the StudySet class
*/

#ifndef STUDYSET_H
#define STUDYSET_H

#include <iostream>
#include <string>
#include <list> //to create a list of terms and definitions

using namespace std;
template <typename T>
class StudySet{

    private:
        T name;
        list<T>* set;//will be an alternating list of "terms" and "definitions" -> the terms are at even indexes and the definitions are at odd indexes (even though lists don't technically work with indexes, its just for visualization)
        
        //structure for the list nodes:
        struct listNode{
            T value;
            listNode *next;
        };

        //pointer for the head of the list:
        listNode *head;



    public:

        //constructor:
        StudySet(){
            name = NULL;
            head = NULL;
        }

        //Destructor
        ~StudySet();

        //accessor:
        T getName();

        //mutator:
        void setName(T);

        //print info function:
        void printSetInfo();

};//end of StudySet class



#endif
