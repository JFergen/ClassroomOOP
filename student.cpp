#include "student.h"

student::student()
{
	numClasses = 0;
}

void student::setID(int id)
{	
	ID = id;
}

void student::setName(string student)
{	
	name = student;
}

void student::setClassification(int classID)
{
	classification = classID;
}

void student::addNumClasses()
{
	numClasses += 1;
}

int student::getID()
{
	return ID;
}


string student::getName()
{
	return name;
}

int student::getClassification()
{
	return classification;
}
	
int student::getNumClasses()
{
	return numClasses;
}

void student::setNumClasses(int classAmount)
{
	numClasses = classAmount;
}
