/*
    File Name : Functions.h
    Author Name : Michael Cates
    Date : 10/24/24
    Purpose : House the function declarations for the NotQuizlet program
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Student.h"

//FUNCTION DECLARATIONS

/*
    Name : addFile
    Author Name : Michael Cates
    Arguments : Student object
    Returns : void
    Purpose : 
    -> this function will be able to save student information to a txt file in two scenarios
        1. the student wants to save all of their information, primarily study sets to a txt file
        2. the student quizzes over a study set and wants to save that quiz information to a txt file

    -> this function will need to ask the user the desired name of the txt file in order to ensure everything
    gets its own file
        - this will also ensure that the user's data isn't lost
        - this is because if everything was being saved to a new file, everytime the program was 
        run, it would delete the old information from the file and then enter the new
            -> everything having its own file will also help the user with organization and ease of access
            to exactly what they want to review later on, when the program is no longer running

    -> if the list of study sets is empty, the function will inform the user that and won't save a file, because it would
    be a waste of space to save an empty file
*/

void addFile(Student*user);

/*
    Name : 
    Author Name : Michael Cates
    Arguments : 
    Returns : 
    Purpose :
*/

void createASet(Student*user);

/*
    Name : createASet
    Author Name : Mackenzie Raleigh
    Arguments : 
        - Student* user: 
            - A pointer to a `Student` object that represents the user who is creating the study set. 
            - This pointer allows access to the student’s data and methods for managing study sets.
        
    Returns : 
        - void: This function does not return a value. 
        - Instead, it modifies the state of the `Student` object by creating and adding a new `StudySet` to the user's collection of study sets.

    Purpose : 
        - This function prompts the user to enter details for a new study set, such as its name and the terms and definitions to be included. 
        - It then creates the study set and adds it to the student's collection, enabling the user to organize their study material effectively.
*/
void editASet(Student* student);

/*
    Name : editASet
    Author Name : Mackenzie Raleigh
        - Student* student: A pointer to a `Student` object that represents the user who owns the study set being edited. 
        - This pointer allows access to the student's study sets and related methods.

    Returns : 
        - void: This function does not return a value. 
        - Instead, it modifies the specified study set based on user input.

    Purpose : 
        - This function allows the user to edit an existing study set. 
        - It prompts the user to select a study set and provides options for updating terms, definitions, or the name of the study set. 
        - The function may include functionality to add new terms, remove existing terms, or modify definitions. 
        - This interactive editing session aims to help the user keep their study materials up-to-date and relevant.
*/
void studyASet(Student *user);

/* 
    Name : studyASet
    Author Name : Mackenzie Raleigh
    Arguments : 
            - void: This function takes no arguments.
    Returns : 
        - void: This function does not return a value. 
        - Instead, it performs actions based on the study set selected by the user.

    Purpose : 
        - This function allows the user to study a selected study set by displaying the terms and their definitions. 
        - It may include options for reviewing the material, such as showing definitions and prompting the user to recall the corresponding terms. 
        - This interactive study session aims to reinforce the user's knowledge and retention of the study material.
*/
void quizASet(Student *user);

/*
    Name: quizASet
    Author Name: Mackenzie Raleigh
    Argurments: 
        -void: This function takes no arguments.
    Returns:
        - void: This function does not return a value. 
        - It handles the process of administering a quiz based on a selected study set.

    Purpose : 
        - This function administers a quiz to the user based on a selected study set. 
        - It prompts the user for the number of questions and evaluates their responses against the correct answers. 
        - The function provides feedback on the user's performance, including the score achieved, and may allow the user to retake the quiz. 
        - This interactive component aims to test the user's knowledge and reinforce learning through assessment.
*/


#endif