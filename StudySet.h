/*
    File Name : StudySet.h
    Author Name : Michael Cates
    Date : 10/10/2024
    Purpose : Header file for the StudySet class
*/

#ifndef STUDYSET_H
#define STUDYSET_H

#include <iostream>
#include <string>

using namespace std;

class StudySet{

    private:
        string name;
        
        //structure for the list nodes:
        struct listNode{
            string value;
            listNode *next;
        };

        //pointer for the head and tail of the list:
        listNode *head;
        listNode *tail;


    public:

        //constructor:
        StudySet(){
            name = "N/A";
            head = NULL;
            tail = NULL;
        }

        StudySet(string n){
            name = n;
            head = NULL;
            tail = NULL;
        }

        //Destructor
        ~StudySet();

        //accessor:
        string getName();

        //mutator:
        void setName(string);

        //print info function:
        void printSetInfo();

        //append:
        void append(string);

        //isEmpty:
        bool isEmpty();

        //remove term:
        void remove(string);

        // New methods
        bool hasTerm(const string& term);                 // Check if a term exists
        void updateTerm(const string& oldTerm, const string& newTerm); // Update a term
        void updateDefinition(const string& term, const string& newDefinition); // Update a definition

        //add a list:
        //->this function is only used when dealing with the studySets linked list in the student class:
        void appendList(StudySet*);

};//end of StudySet class



#endif
