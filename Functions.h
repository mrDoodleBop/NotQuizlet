/*
    File Name : Functions.h
    Author Name : Michael Cates
    Date : 10/24/24
    Purpose : House the function declarations for the NotQuizlet program
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "StudySet.h"
#include "Student.h"

//FUNCTION DECLARATIONS

/*
    Name : 
    Arguments : 
    Returns : 
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
*/
void addFile();

/*
    Name :
    Arguments : 
    Returns : 
    Purpose :
*/
void editASet();

/*
    Name :
    Arguments : 
    Returns : 
    Purpose :
*/
void studyASet();

/*
    Name :
    Arguments : 
    Returns : 
    Purpose :
*/
void quizASet();


#endif