/*
    File Name : Student.cpp
    Author Name : Mackenzie Raleigh & Michael Cates
    Date : 10/10/2024
    Purpose : script file for the Student class
*/

#include "Student.h"
#include "StudySet.h"

string Student::getName(){

    return this->name;

}

int Student::getAge(){

    return this->age;

}

int Student::getYear(){

    return this->year;

}

void Student::setName(string n){

    this->name = n;

}

void Student::setAge(int a){

    this->age = a;

}

void Student::setYear(int y){

    this->year = y;

}

void Student::printStudent(){

    cout << "\n\n\t\t|--------- STUDENT INFORMATION ----------|";

    cout << "\n\t\tName : " << this->name << "\n\t\tAge : " << this->age << "\n\t\tYear : " << this->year;

    //print the data from the hashtable
    this->sets->printHashTable();

}//end of print student

void Student::addSet(StudySet *set){

    cout << "\n\t\tInside of the add set function.";

    //put the set into the hash table:
    this->sets->putValue(set->getKey(), set);

    cout << "\n\t\tset has been added, returning to the driver file...";

}//end of addSet

void Student::editASet() 
{

    string name, choice, term, def, oValue;
    int key, pos;

    cout << "\n\n\t\t|---------- Editing a Set ----------|";
    cout << "\n\t\tEnter the name of the set you would like to enter : ";
    cin.ignore();
    getline(cin, name);

    key = name.size();

    cout << "\n\n\t\tWould you like to change a term or a definition: ";
    getline(cin, choice);

    if(choice == "term" || choice == "Term"){

        //edit a term:
        cout << "\n\n\t\t|---------- Editing a Term ----------|";
        cout << "\n\t\tEnter the term you would like to enter: ";
        getline(cin, term);

        pos = sets->value(key).search(term);
        oValue = sets->value(key).getNodeValue(pos);

        while(oValue != term){

            cout << "\n\n\t\tUh oh! The term you entered was not found, please try another : ";
            getline(cin, term);

            pos = sets->value(key).search(term);
            oValue = sets->value(key).getNodeValue(pos);

        }//end of while loop

        cout << "\n\n\t\tEnter the new term you want : ";
        getline(cin, term);

        sets->value(key).insertNode(pos, term);

    } else if(choice == "Definition" || choice == "definition" || choice == "Def" || choice == "def"){

        //edit a definition:
        cout << "\n\n\t\t|---------- Editing a Definition ----------|";
        cout << "\n\t\tEnter the term that corresponds to the\ndefinition you would like to edit : ";
        getline(cin, term);

        pos = sets->value(key).search(term);
        oValue = sets->value(key).getNodeValue(pos);

        while(oValue != term){

            cout << "\n\n\t\tUh oh! The term you entered was not found, please try another : ";
            getline(cin, term);

            pos = sets->value(key).search(term);
            oValue = sets->value(key).getNodeValue(pos);

        }//end of while loop

        def = sets->value(key).getNodeValue(pos+1);  

        cout << "\n\n\t\tEnter the new definition you want : ";
        getline(cin, def);

        sets->value(key).insertNode(pos+1, def);

        

    } else {

        cout << "\n\n\t\tYou did not enter a valid option.\nPlease go back to the menu and try again.";
        return;

    }//end of conditional branches

    

    
}//end of edit a set function

void Student::createASet(){

    string name, term, def;
    char flag;

    //take in the name of the set:
    cout << "\n\n\t\t|---------- Creating a Study Set ----------|";
    cout << "\n\t\tEnter the desired name for the set : ";
    cin.ignore();
    getline(cin, name);

    //initialize the set:
    StudySet* set = new StudySet;
    set->setName(name);

    //allow the user to enter as many terms and defs as they would like:
    cout << "\n\n\t\tWould you like to begin entering terms and definitions? (y/n) : ";
    cin >> flag;

    while(flag == 'y' || flag == 'Y'){

        cout << "\n\n\t\tEnter a term : ";
        cin.ignore();
        getline(cin, term);

        cout << "\n\t\tEnter the term's definition : ";
        getline(cin, def);

        set->appendNode(term);
        set->appendNode(def);

        cout << "\n\n\t\tWould you like to enter another term? (y/n) : ";
        cin >> flag;

    }//end of while loop

    //add the set to the student object:
    cout << "\n\t\tAdding a study set...";
    this->addSet(set);

    //delete allocated memory:
    //delete set;

}//end of create a set

void Student::quizASet(){
    string name, term, def;

    //create a score variable:
    int key, score, numQuestions;
    score = 0;
    double grade;// score/numQuestions

    //create a list for the wrong answers:
    StudySet *wrongAns = new StudySet;

    //create a list to hold the correct term for the wrong answers:
    StudySet *rightAns = new StudySet;

    //Find out which set the student would like to quiz themselves over:
    cout << "\n\n\t\t|---------- QUIZ ----------|";
    cout << "\n\t\tHow many questions would you like this quiz to be? (i.e. 5, 10, 15, etc.) : ";
    cin >> numQuestions;

    cout << "\n\t\tEnter the name of the set you would like to quiz over : ";
    cin.ignore();
    getline(cin, name);

    key = name.size();

    //begin quizzing over the desired set:
    //print a definition:
    //ask user to input the correct term
    //-->if correct, add a point to score
    //-->if wrong, don't change the score
    for(int i = 0; i < numQuestions; i+= 2){

        cout << "\n\n\t\t-----> Question " << i+1 << ": ";
        cout << "\n\t\t" << sets->value(key).getNodeValue(i+1);
        cout << "\n\t\tEnter the term : ";
        getline(cin, term);

        if(term == sets->value(key).getNodeValue(i)){

            score++;

        } else {

            //add the wrong answer and definition to the wrong list:
            wrongAns->appendNode(term);
            wrongAns->appendNode(sets->value(key).getNodeValue(i+1));

            //add the right answer and definition to the right list:
            rightAns->appendNode(sets->value(key).getNodeValue(i));
            rightAns->appendNode(sets->value(key).getNodeValue(i+1));

        }

    }//end of for loop

    //calculate quiz grade:
    grade = score/numQuestions;

    //display every wrong answer the user entered along with the correct answer, so the user can review:
    cout << "\n\n\t\t|---------- Quiz Review ----------|";
    
    for(int i = 0; i < wrongAns->getLength(); i+=2){

        cout << "\n\n\t\t-----------------------------------------------";
        cout << "\n\t\tDefinition : " << wrongAns->getNodeValue(i+1);
        cout << "\n\t\tYou entered : " << wrongAns->getNodeValue(i);
        cout << "\n\t\tCorrect Answer : " << rightAns->getNodeValue(i);

    }//end of for loop

    //at the end, display the user's quiz grade:
    cout << "\n\n\t\tFINAL GRADE : " << grade;

    //delete allocated memory:
    delete wrongAns;
    delete rightAns;

}//end of quiz a set

void Student::studyASet(){
    string name, term, def;
    char flag;
    int key;

    //Find out which set the student would like to quiz themselves over:
    cout << "\n\n\t\t|---------- Study a Set ----------|";
    cout << "\n\t\tEnter the name of the set you would like to study : ";
    cin.ignore();
    getline(cin, name);

    key = name.size();

    cout << "\n\n\t\tWould you like to begin? (y/n) : ";
    cin >> flag;

    //begin quizzing over the desired set:
    //print a definition:
    //ask user to input the correct term
    //-->if correct, add a point to score
    //-->if wrong, don't change the score
    int i = 0;
    while(flag == 'y' || flag == 'Y'){

        cout << "\n\n\t\t-----> Question " << i+1 << ": ";
        cout << "\n\t\t" << sets->value(key).getNodeValue(i+1);
        cout << "\n\t\tEnter the term : ";
        cin.ignore();
        getline(cin, term);

        if(term == sets->value(key).getNodeValue(i)){

            cout << "\n\t\tCORRECT! GREAT JOB";

        } else {

            cout << "\n\t\tOops! Not quite! The correct answer is " << sets->value(key).getNodeValue(i);

        }

        cout << "\n\n\t\tWould you like another question? (y/n) : ";
        cin >> flag;
        i++;

    }//end of while loop

}//end of studyASet function
