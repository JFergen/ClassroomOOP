#include <iostream>
#include <fstream>
using namespace std;

class student // Inspiration from pattdyn3.cpp
{
private:
	int ID;
	string name;
	int classification; // (1 for freshman, 2 for sophomore...)
	int numClasses;
public:
	student();
	void setID(int id); 
	void setName(string student);
	void setClassification(int classID);
	void addNumClasses();
	void setNumClasses(int classAmount);
	int getID();
	string getName();
	int getClassification();
	int getNumClasses();
};
