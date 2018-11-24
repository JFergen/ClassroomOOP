#include "students.h"

students::students() // Constructor
{
	numStudents = 0;
	maxStudents = 2; // MAX NUMBER OF STUDENTS. CHANGE THIS EVENTUALLY
	id = 100000;	

	studentList = new student[2];
}

students::~students() // Destructor
{
	delete [] studentList;
}

void students::addStudent() // Adds new student to the list
{
	int classYear;
	string temp;

	if(numStudents == maxStudents) // If I need to make more memory allocated
	{
		student *temp;
		temp = new student[maxStudents + 2]; // Add 2 more to the list
		
		for(int i = 0; i < numStudents; i++)
		{
			temp[i] = studentList[i]; // Copies old array into new array
		}
		
		delete [] studentList; // No headless orphans

		maxStudents += 2; // Add 2 more to the max amount

		studentList = temp; // Copies new data into bigger array
	}

	// Giving the student their id
	studentList[numStudents].setID(id);
	cout << "Your student ID is: " << studentList[numStudents].getID() << endl << endl;
	id += 5; // Increment next id by 5	

	// Getting student's first name
	cout << "Enter your first name: ";
	cin >> temp;
	cin.ignore();
	studentList[numStudents].setName(temp);

	// Getting student classification
	cout << "Enter (1) for Freshman. (2) for Sophomore. (3) for Junior. Or (4) for Senior: ";
	cin >> classYear;
	cin.ignore();
	
	if(classYear < 1 || classYear > 4) // If they enter a wrong classification
	{
		cout << "Invalid. Enter your classification; (1) for Freshman. (2) for Sophomore. (3) for Junior. Or (4) for Senior: ";
		cin >> classYear;
		cin.ignore();
	}
 
	studentList[numStudents].setClassification(classYear);

	cout << studentList[numStudents].getName() << " has been added. " << endl << endl;

	numStudents += 1;
}

void students::printStudents() // Prints out all the students
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student #" << i + 1 << ":" << endl;
		cout << "ID: " << studentList[i].getID() << endl;
		cout << "Name: " << studentList[i].getName() << endl;
		
		switch(studentList[i].getClassification())
		{
			case 1: cout << "Classification: Freshman" << endl << endl;
			break;
			
			case 2: cout << "Classification: Sophomore" << endl << endl;
			break;
			
			case 3: cout << "Classification: Junior" << endl << endl;
			break;

			case 4: cout << "Classification: Senior" << endl << endl;
			break;
		}		
	}	
}

int students::findNameByID(int studID)
{
	for(int i = 0; i < numStudents; i++)
	{
		if(studentList[i].getID() == studID)
		{
			return i;
		}
	}
	
	return -1;
}

void students::addNumClasses(int i)
{
	studentList[i].addNumClasses();
}

int students::getNumClasses(int i)
{
	studentList[i].getNumClasses();
}

string students::getStudentName(int i)
{
	return studentList[i].getName();
}

int students::getNumStudents()
{
	return numStudents;
}

void students::storeStudents()
{
	ofstream fout;
	fout.open("students.dat");

	fout << numStudents << endl;

	for(int i = 0; i < numStudents; i++)
	{
		fout << studentList[i].getID() << " " << studentList[i].getName() << " " << studentList[i].getClassification() << " " << studentList[i].getNumClasses() << endl;
	}

	fout.close();
}

void students::loadStudents()
{
	ifstream fin;
	
	int id;
	string name;
	int classification;
	int nClasses;

	fin.open("students.dat");

	fin >> numStudents;
	fin.ignore();

	studentList = new student[numStudents];

	for(int i = 0; i < numStudents; i++)
	{
		fin >> id >> name >> classification >> nClasses;
		studentList[i].setID(id);
		studentList[i].setName(name);
		studentList[i].setClassification(classification);
		studentList[i].setNumClasses(nClasses);
	}

	fin.close();
}
