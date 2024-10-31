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

    nodePtr = head;

    while(nodePtr!=NULL){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }

}//end of destructor

bool StudySet::isEmpty(){

    if(!head){
        return true;
    } else 
        return false;

}//end of isEmpty

int StudySet::getLength(){

    int counter = 0;
    listNode* nodePtr;

    nodePtr = head;

    while(nodePtr != tail){
        counter++;
        nodePtr = nodePtr->next;

        if(nodePtr == tail)
            counter++;
    }

    return counter;

}//end of get length

int StudySet::search(string n){

    listNode *nodePtr;
    int position;

    nodePtr = head;
    position = 0;

    while(nodePtr){

        if(*nodePtr->value == n)
            return position;//return the position of the argument in the list

        position++;

        nodePtr = nodePtr->next;
    }

    return -1;//not found in list

}//end of search

string StudySet::getNodeValue(int pos){

    listNode *nodePtr;

    if(!head){
        return "N/A";
    } else {
        if(pos == 0)
            return *head->value;
        
        nodePtr = head;
        int currentPos = 0;

        while(pos >= currentPos && nodePtr != NULL){

            if(pos == currentPos)
                return *nodePtr->value;

            currentPos++;
            nodePtr = nodePtr->next;
        }
    }

}//end of get node value

void StudySet::appendNode(string n){

    listNode *newNode;

    newNode = new listNode;
    newNode->value = &n;
    newNode->next = NULL;

    if(!head){

        head = newNode;
        tail = newNode;

    } else {

        tail->next = newNode;
        tail = newNode;

    }

}//end of append

void StudySet::insertNode(int pos, string n){

    listNode *nodePtr, *newNode;

    newNode = new listNode;
    newNode->value = &n;

    if(!head){
        if(pos != 0){

            cout << "\n\n\t\tCannot insert new data at a position that doesn't exist. \nAdding data to position 1";


        }

        head = newNode;
        tail = newNode;

    } else {

        nodePtr = head;
        int nodeCount = 0;

        if(pos == 0){

            newNode->next = head;
            head = newNode;

        } else {

            while(nodePtr != tail &&  nodeCount < pos){

                nodeCount++;
                if(nodeCount == pos)
                    break;

                nodePtr = nodePtr->next;

            }

            if(nodePtr->next == NULL)
                tail = newNode;

            newNode->next = nodePtr->next;
            nodePtr->next = newNode;

        }

    }

}//end of insert

void StudySet::deleteNode(string n){

    listNode *nodePtr, *prevNode;

    if(!head){
        return;
    }

    if(*head->value == n){

        nodePtr = head->next;
        delete head;
        head = nodePtr;

    } else {

        nodePtr = head;


        while(nodePtr != NULL && *nodePtr->value != n){

            prevNode = nodePtr;
            nodePtr = nodePtr->next;

        }


        if(nodePtr){

            if(nodePtr == tail){

                tail = prevNode;

            }

            prevNode->next = nodePtr->next;
            delete nodePtr;

        }

    }

}//end of delete

void StudySet::displayList() const{

    listNode *nodePtr;

    if(head != NULL){

        nodePtr = head;

        while(nodePtr){

            cout << nodePtr -> value << endl;

            nodePtr = nodePtr->next;

        }

    } else {

        cout << "\nThere is no data in the list.\n\n";

    }

}//end of display

void StudySet::insertionSort(){

    string key;
    int j;

    for(int i = 1; i < getLength(); i++){

        key = getNodeValue(i);
        j = i-1;
        while(j >= 0 && getNodeValue(j) > key){

            j = j-1;

        }

        deleteNode(key);
        insertNode(j+1, key);

    }

}//end of insertion sort

void StudySet::swap(int pos1, int pos2){

    listNode *nodePtr1 = NULL;
    listNode *nodePtr2 = NULL;
    string *tempValue;

    nodePtr1 = head;

    int currentPos = 0;

    while(nodePtr1 != NULL && pos1 != currentPos){

        nodePtr2 = nodePtr2->next;
        currentPos++;

    }

    tempValue = nodePtr1->value;
    nodePtr1->value = nodePtr2->value;
    nodePtr2->value = tempValue;

}//end of swap


