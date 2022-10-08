/*1. Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
 •  student ID
 •  first name
 •  last name
 •  email address
 •  age
 •  array of number of days to complete each course
 •  degree program*/

#pragma once
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student
{
//define constant
public:
	//constant size of the array; each student has 3 courses lengths in days
	const static int daysArray = 3;

//accessible to the object only
private:
	string student_ID;
	string first_name;
	string last_name;
	string email_address;
	int age;
	int days[daysArray];
	DegreeType degreeType;

//define methods
public:
	//parameterless construtor - sets to default values (always include)
	Student();

	//full constructor
	Student(string student_ID, string first_name, string last_name, string email_address, int age, int days[], DegreeType degreeType);

	//destructor
	~Student();

	//getters or accessors
	string getID();
	string getTitle();
	string getFirst_name();
	string getLast_name();
	string getEmail_address();
	int getAge();
	int* getDays();
	DegreeType getDegreeType(); //array name and pointer are simialar however an array name is always a constant and a pointer is only a constant if declared as such

	//setters or mutators
	void setID(string student_ID);
	void setFirst_name(string first_name);
	void setLast_name(string last_name);
	void setEmail_address(string email_address);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeType(DegreeType degreeType); //seperate class

	static void printHeader(); //print data header for title

	void print(); //displays 'this' data
};	
	
