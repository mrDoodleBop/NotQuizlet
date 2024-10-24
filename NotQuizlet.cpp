/*
    File Name : NotQuizlet.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : Driver file for the NotQuizlet program
*/


#include "StudySet.h"
#include "Student.h"


//main function:
int main(){

    //variables:
    char flag; //->input validation will check for both lowercase and uppercase versions of the user's input 

    string userName;
    int menuChoice;

    //asking user if they would like to begin:
    system("CLS");
    cout << "\n\n\t\t|---------- NotQuizlet! ----------|";
    cout << "\n\t\tWould you like to begin? (y/n) : ";
    cin >> flag;
    
    //validation:
    while(flag != 'n'  && flag != 'N' && flag != 'y' && flag != 'Y'){

        cout << "\n\n\t\tUh Oh! You did not enter y or n. Please try again : ";
        cin >> flag;

    }//end of flag validation loop

    if(flag == 'y' || flag == 'Y'){
        
        //Create a Student object to house all of the user's data:
        cout << "\n\n\t\t|---------- Creating Your Profile ----------|";
        cout << "\n\t\tEnter your name : ";
        cin.ignore();
        getline(cin, userName);
        Student user = new Student(userName);

    }//end of creation of Student object

    //while loop to run the program:
    while(flag != 'n' || flag != 'N'){

        //display menu of options for the user:
        cout << "\n\n\t\t|---------- Menu ----------|";
        cout << "\n\t\t1. Create a Set";
        cout << "\n\t\t2. Edit a Set";
        cout << "\n\t\t3. Study a Set";
        cout << "\n\t\t4. Quiz on a Set";
        cout << "\n\t\t5. End Program";

        //ask the user which of the choices they would like to perform:
        cout << "\n\n\t\tWhat option would you like? Enter 1 - 5 : ";
        cin >> menuChoice;

        //validate user input:
        while(menuChoice > 5 || menuChoice < 1){

            cout << "\n\n\t\tOh No! Your choice was invalid, please try again\nEnter 1 - 5 : ";
            cin >> menuChoice;

        }//end of menuChoice validation loop

        //switch statement to perform the user's desired task:
        switch(menuChoice){

            case 1:
                //call createSet function
                break;
            case 2:
                //call editSet function
                break;
            case 3:
                //call studyASet function
                break;
            case 4:
                //call quizSet function
                break;
            case 5:
                //ask the user if they would like to run the program again:

                //if/ else branch to check what the user would like to do
                //---> if yes, re-run the program from the creation of the menu
                //---> if no, ask the user if they would like to save data to a txt file
                //------> if yes, call the addFile function
                //------> if no, delete all allocated memory and end the program
                break;

        };//end of switch statement


    }//end of while loop


    //return value:
    return 0;
    
}//end of main function