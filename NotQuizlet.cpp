/*
    File Name : NotQuizlet.cpp
    Author Name : 
    Date : 10/10/2024
    Purpose : Driver file for the NotQuizlet program
*/


#include "StudySet.h"
#include "Student.h"
#include "Functions.h"

//main function:
int main(){

    //variables:
    char flag; //->input validation will check for both lowercase and uppercase versions of the user's input 
    char fileFlag; //->same validation as flag - checks if the user would like to save their student information to a text file or not

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


        //while loop to run the program:
        while(flag != 'n' || flag != 'N'){

            //display menu of options for the user:
            cout << "\n\n\t\t|---------- Menu ----------|";
            cout << "\n\t\t1. See my Sets";
            cout << "\n\t\t2. Create a Set";
            cout << "\n\t\t3. Edit a Set";
            cout << "\n\t\t4. Study a Set";
            cout << "\n\t\t5. Quiz on a Set";
            cout << "\n\t\t6. End Program";

            //ask the user which of the choices they would like to perform:
            cout << "\n\n\t\tWhat option would you like? Enter 1 - 6 : ";
            cin >> menuChoice;

            //validate user input:
            while(menuChoice > 6 || menuChoice < 1){

                cout << "\n\n\t\tOh No! Your choice was invalid, please try again\nEnter 1 - 6 : ";
                cin >> menuChoice;

            }//end of menuChoice validation loop

            //switch statement to perform the user's desired task:
            switch(menuChoice){

                case 1:
                    //call the printStudentInfo() function
                    user.printStudentInfo();
                    break;
                case 2:
                    //call createSet function
                    createASet();
                    break;
                case 3:
                    //call editSet function
                    editASet();
                    break;
                case 4:
                    //call studyASet function
                    studyASet();
                    break;
                case 5:
                    //call quizSet function
                    quizASet();
                    break;
                case 6:
                    //ask the user if they would like to run the program again:
                    cout << "\n\n\t\tWould you like to see the menu again? (y/n) : ";
                    cin >> flag;

                    //flag validation loop
                    while(flag != 'n' && flag != 'N' && flag != 'y' && flag != 'Y'){

                        cout << "\n\n\t\tUh oh! You did not enter y or n. Please try again : ";
                        cin >> flag;

                    }//end of flag validation loop

                    if(flag == 'n' || flag == 'N'){

                        cout << "\n\n\t\tWould you like to save your student \ninformation to a text file on your computer? (y/n) : ";
                        cin >> fileFlag;

                        //fileFlag validation loop:
                        while(fileFlag != 'n' && fileFlag != 'N' && fileFlag != 'y' && fileFlag != 'Y'){

                            cout << "\n\n\t\tUh oh! You did not enter y or n. Please try again : ";
                            cin >> fileFlag;

                        }//end of flag validation loop


                        if(fileFlag == 'y' || fileFlag == 'Y'){

                            //call addFile function:
                            addFile(user);

                        }//end of fileFlag if statement

                    }
                    break;

            };//end of switch statement


        }//end of while loop

        //delete all dynamically allocated memory:

    }//end of creation of Student object/ program runtime


    //return value:
    return 0;
    
}//end of main function