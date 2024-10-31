/*
    File Name : HashTable.h
    Author Name : Michael Cates
    Date : 10/30/2024
    Purpose : Hash table implementation file

    this is what will be used to store all StudySet objects into the Student class
*/

#ifndef HASHTABE_H
#define HASHTABLE_H

#include "StudySet.h"
#include "Student.h"

using namespace std;

//Inlcudes:

class HashTable{

    private:

        //Initialze the structure for the HashEntry:
        struct HashEntry{

            int key;
            StudySet value;
            HashEntry *next;

        };//end of HashEntry structure

        //Initialize the table size and hash array
        int tableSize = 0;
        HashEntry** hashArray;


    public:

        HashTable(){

            tableSize = 0;

        }//end of default constructor

        HashTable(int size){

            tableSize = size;
            hashArray = new HashEntry*[tableSize];

            //initialize each bucket to NULL:
            for(int i = 0; i < tableSize; i++){

                hashArray[i] = NULL;

            }//end of for loop

        }//end of constructor method

        ~HashTable(){

            //iterate through the table:
            for(int i = 0; i < tableSize; i++){

                HashEntry* prevEntry = NULL;
                HashEntry* entry = hashArray[i];

                while(entry != NULL){

                    prevEntry = entry;
                    entry = entry->next;
                    delete prevEntry;

                }//end of inner while loop

            }//end of for loop

            //delete the array:
            delete [] hashArray;

        }//end of destructor method

        StudySet value(int key){

            //get the bucket index:
            int bucketIndex = key % tableSize;

            if(hashArray[bucketIndex] == NULL){//if the bucket is empty

                cout << "\n\n\t\tYou have no study sets!";
                return hashArray[bucketIndex]->value;

            } else {

                HashEntry *entry = hashArray[bucketIndex];

                //while the bucket isn't empty and the current key isn't the one we are looking for:
                while(entry != NULL && entry->key != key){

                    entry = entry->next;

                }//end of inner while loop

                if(entry == NULL){//if the entry is empty

                    cout << "\n\n\t\tThe study set is empty!";
                    return hashArray[bucketIndex]->value;

                } else { //otherwise return the value the key guards

                    return entry->value;

                }

            }//end of conditional

        }//end of value method

        void putValue(int key, StudySet *value){//place a passed value under the passed key at the correct index

            //dynamically allocate a new hash entry:
            HashEntry *newHE = new HashEntry;

            newHE->key = key;
            newHE->value = *value;
            newHE->next = NULL;


            int bucketIndex = key % tableSize;

            cout << "\n\n\t\tBUCKET " << bucketIndex << endl;

            if(hashArray[bucketIndex] == NULL){//no collision (good)

                hashArray[bucketIndex] == newHE;

            } else { //collision (annoying)

                HashEntry *entry = hashArray[bucketIndex];

                while(entry->next != NULL){

                    entry = entry->next;

                }//end of while loop

                if(entry->key == key){

                    entry->value = *value; //update the value for this key

                } else {

                    entry->next = newHE;

                }//end of conditional branch

            }//end of conditional branch

        }//end of putValue method

        void removeValue(int key){

            HashEntry *entry;
            HashEntry *prevEntry;

            int bucketIndex = key % tableSize;

            if(hashArray[bucketIndex] != NULL){

                //traverse through the list and find matched key:
                prevEntry = NULL;
                entry = hashArray[bucketIndex];

                while(entry->next != NULL & entry->key != key){

                    prevEntry = entry;
                    entry = entry->next;

                }//end of while loop

                if(entry->key == key){

                    if(prevEntry == NULL){

                        HashEntry *nextEntry = entry->next;

                        delete entry;
                        hashArray[bucketIndex] = nextEntry; //re-link the list

                    } else {

                        HashEntry *next = entry->next;
                        
                        delete entry;

                        prevEntry->next = next;

                    }//end of conditional branch

                }//end of conditional branch 

            }//end of conditional branch

        }//end of remove value method
            
        void printHashTable(){

            cout << "\n\n\t\t|---------- StudySets ----------|";

            //iterate through the table:
            for(int i = 0; i < tableSize; i++){

                if(hashArray[i] != NULL){
                    HashEntry *entry = hashArray[i];

                    while(entry->next != NULL){

                        cout << "\n\t\t----->\t" << entry->value.getName();
                        entry = entry->next; 

                    }//end of while loop
                
                } else {

                    cout << "\n\t\tNULL";

                }//end of conditional branch


            }//end of for loop

        }//end of printHashTable method


        int getSize(){

            return this->tableSize;

        }//end of getSize function


        void setSize(int size){

            this->tableSize = size;

        }

        bool isEmpty(){

            HashEntry *entry = new HashEntry;

            for(int i = 0; i < tableSize; i++){

                entry = hashArray[i];

                if(entry->value.getName() != "N/A"){

                    return false;
                }

            }

            return true;

        }

};//end of hash table class


#endif