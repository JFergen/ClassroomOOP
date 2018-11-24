#include <string>
#include <iostream>
#include "enrollment.h"
#include "students.h"
#include "courses.h"
using namespace std;

class enrollments // Inspiration from pattdyn3.cpp
{
private:
	int numEnrollments;
	int maxEnrollments;
	int id;
	enrollment *enrollmentList; 
public:
	enrollments();
	~enrollments();
	void addEnrollment(students *s, courses *c);
	void printStudentsInCourse(students *s, courses *c);
	void addStudentGrade(students *s, courses *c);
	void printStudentGrades(students *s, courses *c);
	void getStudentAvg(students *s, courses *c);
	void getClassAvg(students *s, courses *c);
	void storeData(students *s, courses *c);
	void loadData(students *s, courses *c);
	void loadEnrollments();
	void storeEnrollments();
};
