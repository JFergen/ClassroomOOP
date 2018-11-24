#include "enrollments.h"

// display student information
//  +----------------------------------------------+
//  | 	     Joseph Fergen     	11159614           |
//  |	     josephfergen@my.unt.edu               |
//  | Description: Gradebook that is updated by the| 
//  | user.                                        |
//  +----------------------------------------------+


// Global variables (collections)
students kids;
courses  classes;
enrollments enroll; 


int main()
{
	// Initial output (course stuff)
	cout << "+----------------------------------------------+" << endl;
        cout << "|       Computer Science and Engineering       |" << endl;
        cout << "|        CSCE 1040 - Computer Science II       |" << endl;
        cout << "| 	  	   Homework 2                  |" << endl;
	cout << "|       Joseph Fergen josephfergen@my.unt.edu  |" << endl;
	cout << "+----------------------------------------------+" << endl << endl << endl;



	int choice = -1; // User's choice
	
	do 
	{
		cout << "MENU OPTIONS:" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Add a new student" << endl;
		cout << "2 - Print out all students" << endl;
		cout << "3 - Add a new course" << endl;
		cout << "4 - Print the courses" << endl;
		cout << "5 - Add student to course (Note: Must have at least 1 student and course added)" << endl;
		cout << "6 - Print out all students in a course" << endl;
		cout << "7 - Add a grade for a student in a course (Note: Must have a student added to a course)" << endl;
		cout << "8 - Print grades for a student in a course (Note: Must have a student added to a course)" << endl;
		cout << "9 - Print average grade of a student in a course" << endl;
		cout << "10 - Print average grade of all students in a course" << endl;
		cout << "11 - Store data in file" << endl;
		cout << "12 - Load data from file" << endl;
		
		cout << "Enter choice: ";
		cin >> choice;
	
	switch (choice)
	{
		case 1: kids.addStudent();
		break;
		case 2: kids.printStudents();
		break; 
		case 3: classes.addCourse();
		break;
		case 4: classes.printCourses();
		break;
		case 5: enroll.addEnrollment(&kids, &classes);
		break;
		case 6: enroll.printStudentsInCourse(&kids, &classes);
		break;
		case 7: enroll.addStudentGrade(&kids, &classes); 
		break;
		case 8: enroll.printStudentGrades(&kids, &classes);
		break;
		case 9: enroll.getStudentAvg(&kids, &classes);
		break;
		case 10: enroll.getClassAvg(&kids, &classes);
		break;
		case 11: enroll.storeData(&kids, &classes);
		break;
		case 12: enroll.loadData(&kids, &classes);
		break;
	}
	
	}while(choice != 0); // Goes until user enters 0

	return 0;
}
