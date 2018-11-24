#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class enrollment // Inspiration from pattdyn3.cpp
{
private:
	int ID;
	int studentID;
	int courseID; 
	int *grades; // List of grades
	int gradeCounter; // Number of grades per student
	int maxGrades; // Max number of grades  (10)
	float avgGrade;
	char letterGrade;
public:
	enrollment();
	~enrollment();
	void setID(int id); 
	void setStudID(int id);
	void setCourseID(int courseIDNum);
	void setGrade();
	void setAvgGrade();
	void setLetterGrade(float totalGrade);
	int getID();
	int getStudID();
	int getCourseID();
	void getGrades();
	float getAvgGrade();
	char getLetterGrade();
	int getGradeCounter();
	void getGrades2();
	void setGradeCounter(int gCounter);
	void setGrades(int *gList);
};
