#include "enrollments.h"

enrollments::enrollments() // Constructor
{
	numEnrollments = 0;
	maxEnrollments = 2; // MAX NUMBER OF STUDENTS. CHANGE THIS EVENTUALLY	
	id = 5000;	

	enrollmentList = new enrollment[maxEnrollments];
}

enrollments::~enrollments() // Destructor
{
	delete [] enrollmentList;
}

void enrollments::addEnrollment(students *s, courses *c) // Adds new enrollment to the list
{
	int studID;
	int classID;

	if(numEnrollments == maxEnrollments) // If I need to make more memory allocated
	{
		enrollment *temp;
		temp = new enrollment[maxEnrollments + 2]; // Add 2 more to the list
		
		for(int i = 0; i < numEnrollments; i++)
		{
			temp[i] = enrollmentList[i]; // Copies old array into new array
		}
		
		delete [] enrollmentList; // No headless orphans

		maxEnrollments += 2; // Add 2 more to the max amount

		enrollmentList = temp; // Copies new data into bigger array
	}

	cout << "Enter Student ID: "; 
	cin >> studID;
	cin.ignore();
	
	if(s->findNameByID(studID) != -1) // Finds if student exists
	{
		enrollmentList[numEnrollments].setStudID(studID);
		cout << s->getStudentName(s->findNameByID(studID)) << " has been found. " << endl << endl;
		
		if(s->getNumClasses(s->findNameByID(studID)) == 5) // If the student is in 5 classes already
		{
			cout << "You cannot be enrolled in more than 5 classes." << endl << endl;
			return;
		}
		
		cout << "Enter Course ID to enroll: ";
		cin >> classID;
		cin.ignore();
		
		if(c->findCourseByID(classID) != -1) // Finds if coursse exists
		{
			enrollmentList[numEnrollments].setCourseID(classID);
			cout << c->getCourseName(c->findCourseByID(classID)) << " has been found. " << endl;
			
			if(c->getNumStudents(c->findCourseByID(classID)) == 48) // If the course has 48 kids already
			{
				cout << "This course can not exceed 48 students." << endl << endl;
				return;
			}

			c->addNumStudents(c->findCourseByID(classID)); // Adds number of students in course by 1
			s->addNumClasses(s->findNameByID(studID)); // Adds number of classes the student is taking by 1
			cout << "Your enrollment ID is: " << id << endl << endl;
			enrollmentList[numEnrollments].setID(id);
			
			id++;
		}		
		else
		{
			cout << "Class ID does not exist." << endl << endl;
			return;
		}
	}
	else
	{
		cout << "Student ID does not exist." << endl << endl;
		return;
	}

	numEnrollments++;
}

void enrollments::printStudentsInCourse(students *s, courses *c) // Prints out all the students
{
	int classID;

	cout << "Enter course ID: ";
	cin >> classID;
	cin.ignore();

	if(c->findCourseByID(classID) == -1) // Check if course exists
	{
		cout << "Course does not exist." << endl << endl;
		return;
	}

	cout << c->getCourseName(c->findCourseByID(classID)) << " has been found. Printing students: " << endl << endl;
	
	for(int j = 0; j < numEnrollments; j++)
	{
		if(enrollmentList[j].getCourseID() == classID)
		{
			cout << "Name: " << s->getStudentName(s->findNameByID(enrollmentList[j].getStudID())) << endl;
			cout << "ID: " << enrollmentList[j].getStudID() << endl << endl;
		}
	}
}

void enrollments::addStudentGrade(students *s, courses *c)
{
	int classID;
	int studID;
	bool found = false;

	cout << "Enter course ID: "; // Getting class to add grades in
	cin >> classID;

	if(c->findCourseByID(classID) == -1)
	{
		cout << "Course does not exist." << endl << endl;
		return;
	}
	
	cout << "Found " << c->getCourseName(c->findCourseByID(classID)) << endl << endl;

	cout << "Enter student ID: "; // Getting student ID
	cin >> studID;

	for(int i = 0; i < numEnrollments; i++)
	{
		if(enrollmentList[i].getStudID() == studID)
		{
			found = true;
			cout << "Found " << s->getStudentName(s->findNameByID(studID)) << endl << endl;
			enrollmentList[i].setGrade();
		}
	}

	if(!found)
	{
		cout << "Student with ID: " << studID << " is not in this course." << endl << endl;
		return;
	}

	
}

void enrollments::printStudentGrades(students *s, courses *c) // Prints grades of 1 student for 1 class
{
	int classID;
	int studID;
	bool found = false;

	cout << "Enter course ID: ";
	cin >> classID;

	if(c->findCourseByID(classID) == -1)
	{
		cout << "Course does not exist." << endl << endl;
		return;
	}

	cout << "Found " << c->getCourseName(c->findCourseByID(classID)) << endl << endl;

	cout << "Enter student ID: ";
	cin >> studID;

	for(int i = 0; i < numEnrollments; i++)
	{
		if(enrollmentList[i].getStudID() == studID)
		{
			found = true;
			cout << "Found " << s->getStudentName(s->findNameByID(studID)) << endl << endl;
			cout << "Printing grades: " << endl;
			enrollmentList[i].getGrades(); 
		}
	}
}

void enrollments::getStudentAvg(students *s, courses *c) // Gets 1 students avg from 1 class
{
	int classID;
	int studID;
	bool found = false;

	cout << "Enter course ID: ";
	cin >> classID;

	if(c->findCourseByID(classID) == -1)
	{
		cout << "Course does not exist." << endl << endl;
		return;
	}

	cout << "Found " << c->getCourseName(c->findCourseByID(classID)) << endl << endl;

	cout << "Enter student ID: ";
	cin >> studID;

	for(int i = 0; i < numEnrollments; i++)
	{
		if(enrollmentList[i].getStudID() == studID)
		{
			found = true;
			cout << "Found " << s->getStudentName(s->findNameByID(studID)) << endl << endl;
			enrollmentList[i].setAvgGrade();
			cout << "Avg grade: " << enrollmentList[i].getAvgGrade() << endl << endl;
		}
	}
}

void enrollments::getClassAvg(students *s, courses *c) // Gets the avg of all the students in 1 class
{
	int classID;
	float courseAvg = 0;
	int numStudents = 0;

	cout << "Enter course ID: ";
	cin >> classID;

	if(c->findCourseByID(classID) == -1)
	{
		cout << "Course does not exist." << endl << endl;
		return;
	}

	cout << "Found " << c->getCourseName(c->findCourseByID(classID)) << endl << endl;

	for(int i = 0; i < numEnrollments; i++)
	{
		if(enrollmentList[i].getCourseID() == classID)
		{
			courseAvg = (enrollmentList[i].getAvgGrade() + courseAvg);
			++numStudents;	
		}
	}

	cout << "Course average: " << (courseAvg/numStudents) << endl << endl;

}

void enrollments::storeEnrollments()
{
	ofstream fout;
	fout.open("enrollments.dat");

	fout << numEnrollments << endl;

	for(int i = 0; i < numEnrollments; i++)
	{
		fout << enrollmentList[i].getID() << " " << enrollmentList[i].getStudID() << " " << enrollmentList[i].getCourseID() << " " << enrollmentList[i].getGradeCounter() << " "; fout.close();  enrollmentList[i].getGrades2(); fout << endl; 
	}

	fout.close();
}

void enrollments::loadEnrollments()
{
	ifstream fin;

	int id;
	int studID;
	int courseID;
	int numGrades;
	int *studGrades;
	

	fin.open("enrollments.dat");

	fin >> numEnrollments;

	for (int i = 0; i < numEnrollments; i++)
	{
		studGrades = new int[enrollmentList[i].getGradeCounter()];
	}

	enrollmentList = new enrollment[numEnrollments];

	for(int i = 0; i < numEnrollments; i++)
	{
		fin >> id >> studID >> courseID >> numGrades;

		studGrades = new int[numGrades];
		for(int j = 0; j < numGrades; j++)
		{
			fin >> studGrades[j]; 
		}

		enrollmentList[i].setID(id);
		enrollmentList[i].setStudID(studID);
		enrollmentList[i].setCourseID(courseID);
		enrollmentList[i].setGradeCounter(numGrades);
		enrollmentList[i].setGrades(studGrades);
	}
}

void enrollments::storeData(students *s, courses *c)
{
	cout << "Storeing data..." << endl << endl;

	s->storeStudents();
	c->storeCourses();
	storeEnrollments();

	cout << "...Complete" << endl << endl;
}

void enrollments::loadData(students *s, courses *c)
{
	cout <<"Getting data..." << endl << endl;

	s->loadStudents();
	c->loadCourses();
	loadEnrollments();

	cout << "...Complete" << endl << endl;
}
