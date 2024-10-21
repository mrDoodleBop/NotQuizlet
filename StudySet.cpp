/*
    File Name : StudySet.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : script file for the StudySet class
*/

#include "StudySet.h"

//Method Definitions:

template <typename T>
StudySet<T>::~StudySet(){

    listNode *nodePtr, *nextNode;

    //position nodePtr at the top of the stack:
    nodePtr = top;

    //traverse list deleting each node:
    while (nodePtr != NULL){
        
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;

    }//end of while loop

}//end of destructor method

template <typename T>
string StudySet<T>::getName(){

    return this->setName;

}//end of get name method

template <typename T>
void StudySet<T>::setName(string n){

    this->setName = n;

}//end of set name method