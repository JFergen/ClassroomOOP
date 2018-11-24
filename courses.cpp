#include "courses.h"

courses::courses() // Constructor
{
	numCourses = 0;
	maxCourses = 2; // MAX NUMBER OF STUDENTS. CHANGE THIS EVENTUALLY
	id = 1000;	

	courseList = new course[2];
}

courses::~courses() // Destructor
{
	delete [] courseList;
}

void courses::addCourse() // Adds new student to the list
{
	int buildingID;
	int timeStart;
	string temp;

	if(numCourses == maxCourses) // If I need to make more memory allocated
	{
		course *temp;
		temp = new course[maxCourses + 2]; // Add 2 more to the list
		
		for(int i = 0; i < numCourses; i++)
		{
			temp[i] = courseList[i]; // Copies old array into new array
		}
		
		delete [] courseList; // No headless orphans

		maxCourses += 2; // Add 2 more to the max amount

		courseList = temp; // Copies new data into bigger array
	}

	// Giving the course its id
	courseList[numCourses].setID(id);
	cout << "This course ID is: " << courseList[numCourses].getID() << endl << endl;
	id += 10; // Increment next id by 10	

	// Setting course's name
	cout << "Enter department and level of course. Examples:(CSCE1420)(MATH1710)(ART1310): ";
	cin >> temp;
	cin.ignore();
	courseList[numCourses].setName(temp);

	// Setting course building ID
	cout << "Enter the building ID where the course is located: ";
	cin >> buildingID;
	cin.ignore();
	courseList[numCourses].setBuilding(buildingID);

	// Setting the beginning time (military time)
	cout << "Enter the beginning time of the course (Note: Military time (00-24)): ";
	cin >> timeStart;
	cin.ignore();
	
	while(timeStart < 0 || timeStart > 24) // If time entered is not valid
	{
		cout << "Invalid. Time must be between 00-24 (hours). Try again: ";
		cin >> timeStart;
		cin.ignore();
	};
 
	courseList[numCourses].setTime(timeStart);

	cout <<	courseList[numCourses].getName() << " " << " has been added. " << endl;
	cout << "Course ID: " << courseList[numCourses].getID() << endl << endl;

	numCourses += 1;
}

void courses::printCourses() // Prints out all the courses
{
	for (int i = 0; i < numCourses; i++)
	{
		cout << "Course #" << i + 1 << ": " << courseList[i].getName() <<  endl;
		cout << "Course ID: " << courseList[i].getID() << endl;
		cout << "Location:	Building: " << courseList[i].getBuilding() << "	Room: " << courseList[i].getRoom() << endl;
		cout << "Time: " << courseList[i].getTime() << endl << endl;
	}	
}

int courses::findCourseByID(int cID)
{
	for(int i = 0; i < numCourses; i++)
	{
		if(courseList[i].getID() == cID)
		{
			return i;
		}
	}

	return -1;
}

void courses::storeCourses()
{
	ofstream fout;
	fout.open("courses.dat");

	fout <<  numCourses << endl;

	for(int i = 0; i < numCourses; i++)
	{
		fout << courseList[i].getID() << " " << courseList[i].getName() << " " << courseList[i].getBuilding() << " " << courseList[i].getRoom() << " " << courseList[i].getTime() << " " << courseList[i].getNumStudents();
	}	

	fout.close();
}

void courses::loadCourses()
{
	ifstream fin;
	
	int id;
	string name;
	int building;
	int room;
	int time;
	int nStudents;

	fin.open("courses.dat");

	fin >> numCourses;
	fin.ignore();

	courseList = new course[numCourses];
	
	for(int i = 0; i < numCourses; i++)
	{
		fin >> id >> name >> building >> room >> time >> nStudents;
		courseList[i].setID(id);
		courseList[i].setName(name);
		courseList[i].setBuilding(building);
		courseList[i].setRoom(room);
		courseList[i].setTime(time);
		courseList[i].setNumStudents(nStudents);
	}

	fin.close();	
}

void courses::addNumStudents(int i)
{
	courseList[i].addNumStudents();	
}

int courses::getNumStudents(int i)
{
	courseList[i].getNumStudents();
}

string courses::getCourseName(int i)
{
	return courseList[i].getName();
}
