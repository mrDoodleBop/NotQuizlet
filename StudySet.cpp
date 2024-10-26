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
T StudySet<T>::getName(){

    return this->name;

}//end of get name method

template <typename T>
void StudySet<T>::setName(T n){

    this->name = n;

}//end of set name method

template <typename T> 
void StudySet<T>::printSetInfo(){

    listNode *nodePtr, *nextNode;

    nodePtr = head;

    //check if empty:
    if(head == NULL){

        cout << "\n\n\t\tThe list is empty! You have no study sets :(";

    } else {   

        /*
            These variables are not necessary in outputting the correct information for term and definition,
            but they are usefull for me in keeping track of the terms and definitions while programming considering
            how they are stored in the list

            --> they are also of a template typename because this program allows the user to store any data type they would like
            for terms and definitions, but the terms and definitions have to be the same data type
                1. useful for working with integers, strings, doubles, anythings


        */
        T term;
        T def;

        int i = 0; //iterator to help determine whether the value in the node is a term or definition

        //Displaying the header:
        cout << "\n\n\t\t|---------- " << this->name << " ----------|";

        //iterate through the list printing out the study set information:
        while(nodePtr != NULL){

            nextNode = nodePtr->next;

            //determine whether the value is a term or definition:
            if(i % 2 == 0){

                term = nodePtr->value;
                cout << "\n\t\tTerm : " << term;

            } else {

                def = nodePtr->value;
                cout << "\n\t\tDefinition : " << def;

            }//end of if/ else branch
            

        }//end of while loop

    }//end of if/ else branch

}//end of print set info function