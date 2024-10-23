/*
    File Name : Student.h
    Author Name : 
    Date : 10/10/2024
    Purpose : Header file for the Student class
*/

// Forward declaration of StudySet class (since StudySet will be included later)
//class StudySet;

class Student {
private:
    string name;                 // Student's name
    list<StudySet> studySets;    // Pointer to a list of StudySet objects

public:
    // Constructor to initialize student name
    Student(string studentName);

    // Accessor to get the student's name
    string getName() const;

    // Method to add a StudySet to the student's list of sets
    void addStudySet(StudySet* set);

    // Method to print student information and all study sets
    void printStudentInfo() const;

};

#endif // STUDENT_H