#include "course.h"

course::course()
{
	numStudents = 0;
}

void course::setID(int id)
{	
	ID = id;
}

void course::setName(string className)
{	
	name = className;
}

void course::setBuilding(int buildingNum)
{
	building = buildingNum;
}

void course::setRoom(int roomNum)
{
	room = roomNum;
}

void course::setTime(int timeNum)
{
	time = timeNum; // This will be military time (0-24)
}

void course::addNumStudents()
{
	numStudents += 1;
}

int course::getID()
{
	return ID;
}


string course::getName()
{
	return name;
}

int course::getBuilding()
{
	return building;
}
	
int course::getRoom()
{
	return room;
}

int course::getTime()
{
	return time;
}

void course::setNumStudents(int nStudents)
{
	numStudents = nStudents;
}

int course::getNumStudents()
{
	return numStudents;
}
