#include "enrollment.h"

enrollment::enrollment() // Constructor
{
	gradeCounter = 0;
	maxGrades = 1;
	grades = new int; // Allocates space for 1 new grade
	avgGrade = 0;	
}

enrollment::~enrollment() // Destructor
{
	delete [] grades;
}

void enrollment::setID(int id)
{	
	ID = id;
}

void enrollment::setStudID(int id)
{	
	studentID = id;
}

void enrollment::setCourseID(int courseIDNum)
{
	courseID = courseIDNum;
}

void enrollment::setGrade()
{	
	int gradeNum;

	if(gradeCounter == 10)
	{
		cout << "Error. This student can not have any more grades." << endl;
		return;
	}
	else if(gradeCounter == maxGrades)
	{
		int *temp;
		temp = new int[maxGrades]; // Allocates another grade
		
		for (int i = 0; i < gradeCounter; i++)
		{
			temp[i] = grades[i];
		}
		
		maxGrades++;
		
		delete [] grades;

		grades = temp;
	}

	if(gradeCounter < 10)
	{
		cout << "Grade (Note: Whole, positive numbers only 0-100): ";
		cin >> gradeNum;
		cin.ignore();

		while(gradeNum < 0 || gradeNum > 100)
		{
			cout << "Invalid number. Try again (Whole, positive numbers only 0-100): ";
			cin >> gradeNum;
			cin.ignore();
		}

		grades[gradeCounter] = gradeNum;

		gradeCounter++;
	}
}


void enrollment::setAvgGrade()
{
	for(int i = 0; i < gradeCounter; i++)
	{
		avgGrade += grades[i];	
	}
	
	avgGrade = (avgGrade/gradeCounter);
}

void enrollment::setLetterGrade(float totalGrade)
{
	if(totalGrade >= 90 && totalGrade <= 100)
	{
		letterGrade = 'A';
	}
	else if(totalGrade >= 80 && totalGrade <= 89)
	{
		letterGrade = 'B';
	}
	else if(totalGrade >= 70 && totalGrade <= 79)
	{
		letterGrade = 'C';
	}
	else if(totalGrade >= 60 && totalGrade >= 69)
	{
		letterGrade = 'D';
	}
	else if(totalGrade < 60 && totalGrade > 0)
	{
		letterGrade = 'F';
	}	
}
	
int enrollment::getID()
{
	return ID;
}

int enrollment::getStudID()
{
	return studentID;
}

int enrollment::getCourseID()
{
	return courseID;
}

void enrollment::getGrades()
{
	for(int i = 0; i < gradeCounter; i++)
	{
		cout << "Grade #" << i + 1 << ": " << grades[i] << endl;
	}	
}

float enrollment::getAvgGrade()
{
	return avgGrade;
}

char enrollment::getLetterGrade()
{
	return letterGrade;
}

int enrollment::getGradeCounter()
{
	return gradeCounter;
}

void enrollment::getGrades2()
{
	ofstream fout;
	fout.open("enrollments.dat", ofstream::app);

	for(int i = 0; i < gradeCounter; i++)
	{
		fout << grades[i] << " ";
	}
}

void enrollment::setGradeCounter(int gCounter)
{
	gradeCounter = gCounter;
}

void enrollment::setGrades(int *gList)
{
	grades = gList;
}
