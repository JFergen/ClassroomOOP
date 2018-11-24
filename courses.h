#include <iostream>
#include <string>
#include "course.h"  // Inspiration from pattdyn3.cpp
using namespace std;

class courses
{
private:
	int numCourses;
	int maxCourses;
	int id;
	course *courseList; // Pointer for a collection of courses
public:
	courses(); // Constructor for courses
	~courses(); // Destructor
	void addCourse();
	void printCourses();
	int findCourseByID(int cID);
	void addNumStudents(int i);
	int getNumStudents(int i);
	string getCourseName(int i);
	void storeCourses();
	void loadCourses();
};
