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

class StudySet{

    private:

        string name;
        int key; // for storage in the hash table

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
