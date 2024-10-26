/*
    File Name : Functions.cpp
    Author Name : Michael Cates & Mackenzie Raleigh
    Date : 10/10/2024
    Purpose : Function definitions file
*/


#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*
    MACKENZIE !
    *as a preface I am not trying to be an asshole about your code, I just wanna make sure that the program we submit follows the guidelines of the 
    rubric

    -> at first glance the code looks fantastic, but the biggest issue is that we are working with linked lists, so it's more complicated
    to access the values in the list nodes

    both of these functions, unfortunately, need to be changed to fit the data structure we are working with. The lecture slides and example programs over linked
    lists will help tremendously with this as well as my printSetInfo function that I wrote in the Set.cpp file

    any function where we need to access list nodes or traverse the list will follow a similar structure to the printSetInfo function


    editASet function:
        - you wont be able to access the nodes through simple indices
            1. You will need to create two node pointers
                 - the first is just nodePtr to point to the current node you are in 
                - the second in the nextNode pointer to point to the node after nodePtr

            2. You can then ask the user which set they would like to edit
            3. then do a linear search to traverse the list, similar to the way the printSetInfo function does and compare the name of each set to the
                name the user entered (ex: if(nodePtr-value.getName() == userInput) ) ; if the studySets in the list are all pointers than it would need to be
                value->getName() instead
            4. If/ when you find the user's desired set, you can ask which part of the set the user would like to change and move from there
                a. if they want to change the name, that would be the simplest action to perform
                b. if the want to change a term or a definition, you will need to as ask if they would like to change a term or a definition
                (terms are in even indices and definitions are in odd indices) -> the way i chose to keep track of terms and definitions is by making a counter 
                starting at 0 and using a while loop to traverse the list and at every iteration of the while loop, I incremented the counter
                    - if the counter % 2 == 0 then its a term if not, its a definition

                c. once you find what they want to change, then have the user input the desired change and perform that action


*/

template <typename T>
void editASet(Student<T>* student) {
    int setIndex;
    student->printStudySets();  // Assuming this prints the study sets list
    cout << "\n\n\t\tEnter the number of the set you wish to edit: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet<T>* set = &student->getStudySets()[setIndex];
        // Here, provide options like add, delete, edit terms/definitions, etc.
        // This part will need interaction with the user.
    } else {
        cout << "\n\n\t\tInvalid set index!" << endl;
    }
}

/*
    MACKENZIE !

    for the quizASet function, you will have to set up starting the quiz very similarly to the implementation of the editASet function

    1. Ask the user which set they would like to quiz over by name
    2. traverse the list linearly, like the last function, in search of the set that matches the name the user entered - if the set is either empty or
    the name doesn't exist in the set, output that to the user
    3. Once the correct set has been found, you will need a way to keep track of the terms and definitions:
        - again, I like to use the counter to determine if the position is even or odd
    4. perform a while loop to quiz the user
        a. ask the user how many questions they would like the quiz to be
        b. perform an inner for loop to run the user's desired amount of times
        c. each iteration of the for loop will print out a DEFINITION and ask the user to enter the term that matches it
        d. if the user enters the correct term, a point is added to their score, if not the score does not change
        e. after the for loop runs, divide the score by the number of questions and display their quiz grade

        the condition for checking the term against the definition can look something like this:
            //find a definition:
            listNode *nodePtr, *nextNode;

            nodePtr = head;

            //ask the user for the number of questions

            while (nodePtr != NULL && i < numQuestions) {
                nextNode = nodePtr->next;

                if(nextNode % 2 != 0){ -> meaning if the index nextNode is at is odd (odd index means definition)
                    //display the definition, ask the user to enter the correct term, and validate their input

                    //testing if the user is correct:
                    if( userInput == nodePtr->value){ //since nodePtr is one node behind nextNode it will be even if nextNode is odd, meaning it will be the matching term to the definition

                        //output that the user is correct
                        //add one point to the user's score
                        
                    } else {

                        //output that the user is incorrect

                    } //end of input validation

                }//end of testing if the nextNode index is odd

            }//end of while loop

    5. after the while loop, ask the user if they would like to run the quiz again, if they would then let the program run the quiz again
    6. if they want to run the quiz over a different set, they will have to go back to the menu and re-run the entire function again

*/

template <typename T>
void quizASet(Student<T>* student) {
    int setIndex;
    student->printStudySets();
    cout << "\n\n\t\tEnter the number of the set you wish to quiz over: ";
    cin >> setIndex;

    if (setIndex >= 0 && setIndex < student->getStudySets().size()) {
        StudySet* set = &student->getStudySets()[setIndex];
        // Implement the quizzing functionality
    } else {
        cout << "\n\n\t\tInvalid set index!" << endl;
    }
}

//FUNCTION DEFINITIONS