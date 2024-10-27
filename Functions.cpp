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
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand()

using namespace std;

//FUNCTION DEFINITIONS:


/*
    MACKENZIE !

    for editASet function:

    1. ask the user for the name of the set they would like to enter
    2. search the list of studySets in the Student class for the name of the set the user is looking for 
        a. if the name is not in the list display a message to the user informing them, and allow them to enter a new name to search for
    3. ask the user whether they would like to change a term or a definition in the set
    4. search the study set object for the user's input
    5. ask the user what they would like to change the value to
    6. change the value
    7. display a message to the user that the value they wanted to change has been updated

*/


void editASet(Student* student) {
    std::string setName, term, newTermOrDefinition;
    int choice;

    // Step 1: Ask for the set name
    std::cout << "Enter the name of the study set you would like to edit: ";
    std::getline(std::cin, setName);

    // Step 2: Search for the study set by name
    StudySet* set = student->findStudySetByName(setName);
    while (set == nullptr) {
        std::cout << "Study set not found. Please enter a valid study set name: ";
        std::getline(std::cin, setName);
        set = student->findStudySetByName(setName);
    }

    // Step 3: Ask the user to edit a term or definition
    std::cout << "Would you like to edit a (1) term or (2) definition? Enter 1 or 2: ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore remaining newline in input buffer

    if (choice == 1) {
        // Step 4: Edit a term
        std::cout << "Enter the term you would like to edit: ";
        std::getline(std::cin, term);

        // Check if term exists
        if (set->hasTerm(term)) {
            std::cout << "Enter the new term: ";
            std::getline(std::cin, newTermOrDefinition);
            set->updateTerm(term, newTermOrDefinition);
            std::cout << "The term has been successfully updated.\n";
        } else {
            std::cout << "Term not found in this set.\n";
        }
    } else if (choice == 2) {
        // Step 5: Edit a definition
        std::cout << "Enter the term whose definition you want to edit: ";
        std::getline(std::cin, term);

        // Check if term exists
        if (set->hasTerm(term)) {
            std::cout << "Enter the new definition: ";
            std::getline(std::cin, newTermOrDefinition);
            set->updateDefinition(term, newTermOrDefinition);
            std::cout << "The definition has been successfully updated.\n";
        } else {
            std::cout << "Term not found in this set.\n";
        }
    } else {
        std::cout << "Invalid choice. Please enter 1 for term or 2 for definition.\n";
    }
}
/*
}


    MACKENZIE !

    for quizASet function:
    1. ask the user the name of the set they would like to quiz over
    2. search the list of sets in the student class for the name they entered
        a. if the name is not in the set inform the user and allow them to enter a new name to search for
    3. once the set has been found ask the user how many questions they would like the quiz to be
    4. in a for loop that asks the user's desired number of questions (if the number of questions is greater than the size of the list, than everytime you hit the end of the list restart from the beginning):
        a. start at the beginning of the list
        b. display the definition and have the user enter the term 
        c. run an if/ else statement to test their input
        d. if the user was correct display a message saying they were correct and 
        add a point to a score variable and if not, don't change the score, just display an incorrect message to the user
    5. after the for loop, divide the user's score by the number of questions and then multiply it by 100
    6. display the user's quiz score and ask them if they would like to go again
        a. this will only allow them to requiz over the same set, if they want to quiz over a different set they will have 
        to go back to the menu and choose the quiz a set option again to restart the function


*/


void quizASet(Student* student) {
    std::string setName;
    int numQuestions;
    char tryAgain;
    
    // Step 1: Ask for the study set name
    std::cout << "Enter the name of the study set you would like to quiz over: ";
    std::getline(std::cin, setName);

    // Step 2: Search for the study set by name
    StudySet* set = student->findStudySetByName(setName);
    while (set == nullptr) {
        std::cout << "Study set not found. Please enter a valid study set name: ";
        std::getline(std::cin, setName);
        set = student->findStudySetByName(setName);
    }

    do {
        // Step 3: Ask for the number of quiz questions
        std::cout << "How many questions would you like the quiz to be? ";
        std::cin >> numQuestions;
        std::cin.ignore(); // Ignore newline in the input buffer

        int score = 0;
        int setSize = set->getNumberOfTerms(); // Assuming this method returns total term/definition pairs

        // Step 4: Quiz the user
        for (int i = 0; i < numQuestions; ++i) {
            int index = i % setSize; // Loop back if numQuestions > setSize
            std::string definition = set->getDefinitionAt(index);
            std::string correctTerm = set->getTermAt(index);

            std::string userAnswer;
            std::cout << "Definition: " << definition << "\nYour answer: ";
            std::getline(std::cin, userAnswer);

            // Step 4c: Check answer
            if (userAnswer == correctTerm) {
                std::cout << "Correct!\n";
                score++;
            } else {
                std::cout << "Incorrect. The correct answer was: " << correctTerm << "\n";
            }
        }

        // Step 5: Calculate score
        double percentage = (static_cast<double>(score) / numQuestions) * 100;
        std::cout << "Your quiz score: " << percentage << "%\n";

        // Step 6: Ask to retry
        std::cout << "Would you like to take the quiz again on this set? (y/n): ";
        std::cin >> tryAgain;
        std::cin.ignore(); // Ignore remaining newline in input buffe

}

*


void createASet(Student* user){ 

    //variables:
    string name;

    string in;

    char flag;

    //get name of the set:
    cout << "\n\n\t\t|---------- Creating a Set ----------|";
    cout << "\n\t\tEnter the desired name of the set : ";
    getline(cin, name);

    //dynamically allocate a new study set object:
    StudySet *newSet = new StudySet(name);

    do{

        cout << "\n\t\tEnter a term : ";
        getline(cin, in);

        newSet->append(in);

        cout << "\n\t\tEnter the term's definition : ";
        getline(cin, in);

        newSet->append(in);


    }while(flag != 'n' || flag != 'N');

    //append the new set to the list in the student object:
    user->addStudySet(newSet);

    //delete allocated memory:
    

}//end of createASet function

