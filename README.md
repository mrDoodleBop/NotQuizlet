# NotQuizlet
CSC 1310-001 Lab Assignment #2
Not Quizlet

DIVISION OF LABOR : 
 1. Michael Cates - StudySet Class, Driver File, Functions File (specific functions, not the whole file)
 2. Mackenzie Raleigh - Student Class, Functions File (specific functions, not the whole file)

Program Overview: 
This program will perform in a way like the Quizlet website. It will allow the user, most likely a student, to create a list of study sets, which includes a list of terms/ definitions that they can study and quiz themselves on.

Program Flow:
The program will ask the user whether or not they would like to begin the program
Once the user enters the correct flag value, it will begin a while loop to run the program as long as they would like to:
1.	First the user needs to create a Student object to house their information
2.	Once this object is created, the program will then display a menu of options to choose from
“Not Quizlet” will provide the user with the options to create a set, edit a set, study a set, or quiz over a set. 
1.	Create a Set
a.	Allow the user to create a StudySet object and add their terms and definitions and then add that to the list of sets in the student class

2.	Edit a Set
a.	Display the names of the current sets in the user’s Student object and allow them to choose which one they would like to edit
b.	Once the desired set has been chosen, the program will give the user options on what they would like to do:
i.	Delete a term
1.	Ask the user the term they would like to delete
2.	Remove the value at the index of the term AND the value at the index of the term+1 (Removes the term and the definition)

ii.	Add a term
1.	Take in the information for the new term the user would like to add
2.	Add the new term to the end of the list

iii.	Edit a term
1.	Get the term that the user would like to edit
2.	Get the new term the user would like to enter
3.	Replace the value at the index of the term with the new string value

iv.	Edit a Definition
1.	Get the term that the user would like to edit the definition for
2.	Get the new definition the user would like to enter
3.	Replace the value at index of the term + 1 with the new definition (This is the location of the definition: The position of the term points to the next node which is the position of the definition)

3.	Study a Set
a.	This function of the program allows the user to study their material
b.	It will display a random definition from the list of terms and the user can press any key on their keyboard to view the term, until they enter “stop” or “Stop”
i.	The method that will be used to find a definition in the list is to generate a random ODD number within the range of the length of the list and find the value at that number
1.	The definitions will be housed in ODD indexes
 
4.	Quiz over a Set
a.	Works the same as study a set, essentially, except when the definition is displayed, the user must enter the term that matches that definition and the program will validate their input
i.	Displaying a wrong answer message if wrong and a correct answer message if right
b.	(Possible Idea)
i.	Every time a quiz is performed, the displayed information and the user input are recorded into a text file
ii.	When the quiz is over, the program calculates the grade on the quiz and adds it to the bottom of the file

Classes to be Used:
1.	StudySet
 a.	Will house a linked list of terms and definitions of string
  i.	The terms will be housed in the even indexed nodes and the definitions will be housed in the odd indexed nodes (ex: term1 at index 0, and definition1 at index 1)
 b.	Will also be home to other information about the set
  i.	Name of the set, The course that the set relates to, the subject that the set covers, and a summary of the study set, all of type string
  ii.	All of this along with the rest of the required properties of a linked list class 😊
2.	Student
 a.	Will include the user’s information including a linked list of StudySet type
 b.	User information that will be used includes their name, age, year in school, and the linked list

Other Information:
