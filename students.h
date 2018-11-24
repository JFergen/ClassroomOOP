#include <iostream>
#include <string>
#include "student.h"  // Inspiration from pattdyn3.cpp
using namespace std;

class students
{
private:
	int numStudents;
	int maxStudents;
	int id;
	student *studentList; // Pointer for a collection of students
public:
	students(); // Constructor for students
	~students(); // Destructor
	void addStudent();
	void printStudents();
	int findNameByID(int studID);
	void addNumClasses(int i);
	int getNumClasses(int i);
	string getStudentName(int i);
	int getNumStudents();
	void storeStudents();
	void loadStudents();
};
