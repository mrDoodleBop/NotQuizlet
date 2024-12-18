/*
    File Name : StudySet.h
    Author Name : Michael Cates
    Date : 10/10/2024
    Purpose : Header file for the StudySet class

    //nodes will house strings
        -> even indexes = terms
        -> odd indexes = definitions
*/

#ifndef STUDYSET_H
#define STUDYSET_H

#include <iostream>
#include <string>

using namespace std;

/*

    StudySet is used to store the user's list of terms and definitions for a specific study set
        -> each study set has a name and a key (the length of the name) 
            -> key is for storage into the HashTable
        
        -> the terms are placed into even indices while the definitions are stored in the odd indices
            -> if we are in the location of a definition, then we know the matching term by just going to the previous node
            -> if we are in the location of a term, then we know the matching definition by just going to the next node

*/

class StudySet{

    private:

        string name;
        int key = name.size(); // for storage in the hash table -> key is the length of the name of the set

        struct listNode{

            string *value;
            listNode *next;

        };//end of listNode

        listNode *head;
        listNode *tail;

    public:
        //constructor:
        StudySet(){

            head = NULL;
            tail = NULL;

        }

        //destructor:
        ~StudySet();

        bool isEmpty();

        int getLength();

        int search(string);

        string getNodeValue(int);

        void appendNode(string);

        void insertNode(int, string);

        void deleteNode(string);

        void displayList() const;

        void insertionSort();

        void swap(int, int);

        //setters:

        string getName(){

            return this->name;

        }

        int getKey(){

            return this->key;

        }

        //getters:
        void setName(string n){

            this->name = n;

        }
        
        void setKey(int k){

            this->key = k;

        }


};//end of StudySet class

#endif
