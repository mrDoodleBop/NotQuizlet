################################
# MAKEFILE FOR NOTQUIZLET      #
################################

#File Name : Makefile
#Author Name : Michael Cates
#Date : 10/26/2024



all					:	NOTQUIZLET

NOTQUIZLET			:	NotQuizlet.cpp Functions.cpp Student.cpp StudySet.cpp
					g++ *.cpp

Drive				: NotQuizlet.cpp
					g++ NotQuizlet.cpp

Func				: Functions.cpp	
					g++ functions.cpp

Stud 				: Student.cpp	
					g+ Student.cpp

Study 				: StudySet.cpp
					g++ StudySet.cpp

run					: a.exe

testSomething		: #a.exe < whatever the test case file is named

toFile				: #a.exe > whatever the output file is named

clear				:#makefile clear command