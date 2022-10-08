#pragma once
#include "student.h"
#include <stdio.h>

class Roster
{
public:
	int lastIndex = -1;
	const static int studentDataTable = 5;
	Student* classRosterArray[studentDataTable];//not dynamically declared

public://parse | function | destructor
	void parse(string row); //parse set of coma delimited strings, extract data, create dataset
	void add(string sStudent_ID,
		string sFirst_name,
		string sLast_name,
		string sEmail_address,
		int sAge,
		int sDay1,
		int sDay2,
		int sDay3,
		DegreeType sDegreeType);

	//once student objects are created, functions can be call
	void printAll();//calls print() for each book
	void printByDegreeType(DegreeType degreeType);//DegreeType passed in, print by DegreeType
	void printInvalidEmails();//valid email includes an '@' (at sign) and '.' (period) however no ' ' (space)
	void printAverageDays(string student_ID);//prints average days used for each class
	bool removeStudentByID(string student_ID);//find student and remove
	~Roster();//destructor
};
