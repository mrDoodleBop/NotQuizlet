/*
    File Name : StudySet.cpp
    Author Name : Michael Cates
    Date : 10/10/2024
    Purpose : script file for the StudySet class
*/

#include "StudySet.h"

//Method Definitions:

StudySet::~StudySet(){

    listNode *nodePtr, *nextNode;

    //position nodePtr at the top of the stack:
    nodePtr = head;

    //traverse list deleting each node:
    while (nodePtr != NULL){
        
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;

    }//end of while loop

}//end of destructor method

string StudySet::getName(){

    return this->name;

}//end of get name method

void StudySet::setName(string n){

    this->name = n;

}//end of set name method

void StudySet::printSetInfo(){

    listNode *nodePtr, *nextNode;

    nodePtr = head;

    //check if empty:
    if(head == NULL){

        cout << "\n\n\t\tThe list is empty! You have no study sets :(";

    } else {   

        string term;
        string def;

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

void StudySet::append(string value){

    listNode *newNode;

    newNode = new listNode;
    newNode->value = value;
    newNode->next = NULL;

    if(!head){

        head = newNode;
        tail = newNode;

    } else {

        tail->next = newNode;
        tail = newNode;

    }

    //delete allocated memory:
    delete newNode;

}//end of append function

bool StudySet::isEmpty(){

    if(!head){
        return true;
    } else {
        return false;
    }

}//end of the is empty function

void StudySet::remove(string n){
    //function will remove the term that the user enters plus the node next to the term (definition)

    listNode *nodePtr, *nextNode, *previousNode;

    //if the list is empty, do nothing:
    if(!head){

        cout << "\n\n\t\tThe list is empty. There is nothing to delete.";
        return;

    } 


    if(head->value == n){
        nodePtr = head->next;
        nextNode = nodePtr->next;

        //delete the term node and the definition node:
        delete head;
        delete nodePtr;

        nodePtr = nextNode;
        head = nodePtr;
        nextNode = head->next;
    } else {

        nodePtr = head;

        while (nodePtr != NULL && nodePtr->value != n){

            previousNode = nodePtr;
            nodePtr = nextNode;
            nextNode = nodePtr->next;

        }

        if(nodePtr){
            if(nodePtr == tail){

                tail = previousNode;

            }

            previousNode->next = nodePtr->next;
            delete nodePtr;
        }

    }
}

