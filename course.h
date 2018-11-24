#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class course // Inspiration from pattdyn3.cpp
{
private:
	int ID;
	string name;
	int building; // Which building the class is in
	int room; // Which room the class is in
	int time; // Beginning time of the class. (All classes start on the hour and are 50 minutes long)
	int numStudents;
public:
	course();
	void setID(int id); 
	void setName(string className);
	void setBuilding(int buildingNum);
	void setRoom(int roomNum);
	void setTime(int timeNum);
	void addNumStudents();
	int getID();
	string getName(); // Name of class
	int getBuilding(); // Building number
	int getRoom(); // Room number
	int getTime(); // Military time
	void setNumStudents(int nStudents);
	int getNumStudents();
};
