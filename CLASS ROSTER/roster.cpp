/*E.  Create a Roster class (roster.cpp) by doing the following:
 1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
 2.  Create a student object for each student in the data table and populate classRosterArray.
 a.  Parse each set of data identified in the “studentData Table.”
 b.  Add each student object to classRosterArray.
 3.  Define the following functions:
 a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
 b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
 c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
 d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
 e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.

 Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

 f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type*/

#include <string>
#include "roster.h"

void Roster::parse(string studentData)//parses each row
{
	int rhs = studentData.find(',');//find the comma and return index
	string sStudent_ID = studentData.substr(0, rhs);//extract substring in front of coma: student_ID

	int lhs = rhs + 1;//move past previous comma
	rhs = studentData.find(',', lhs);
	string sFirst_name = studentData.substr(lhs, rhs - lhs);//first_name

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	string sLast_name = studentData.substr(lhs, rhs - lhs);//last_name

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	string sEmail_address = studentData.substr(lhs, rhs - lhs);//email_address

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));//age

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	int sDay1 = stod(studentData.substr(lhs, rhs - lhs));//first number of days

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	int sDay2 = stod(studentData.substr(lhs, rhs - lhs));//second number of days

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	int sDay3 = stod(studentData.substr(lhs, rhs - lhs));//third number of days

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);

	DegreeType sDegreeType = SECURITY;//degreeType

	if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') sDegreeType = SECURITY;
	else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == '0') sDegreeType = SOFTWARE;
	else if (studentData.at(lhs) == 'N') sDegreeType = NETWORK;

	add(sStudent_ID, sLast_name, sFirst_name, sEmail_address, sAge, sDay1, sDay2, sDay3, sDegreeType);

}

//adding a method that combines strings and creates object in repository
void Roster::add(string student_ID, string first_name, string last_name, string email_address, int age, int day1, int day2, int day3, DegreeType degreeType)
{
	//days back into an array for constructor
	int dayArray[3] = { day1, day2, day3 };
	//make new book object, first index being -1
	classRosterArray[++lastIndex] = new Student(student_ID, first_name, last_name, email_address, age, dayArray, degreeType);//full constructor
}

//print all students using tab delimited output
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

//print invalid emails
void Roster::printInvalidEmails()
{
	bool any = false;//default: no invalid emails
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email_address = (classRosterArray[i]->getEmail_address());//creating a variable to shorten below statment
		if ((email_address.find("@") == string::npos) || (email_address.find(" ") != string::npos) || (email_address.find(".") == string::npos))
		{
			any = true;
			//any reassigned true if the conditional statement requirement is met
			cout << email_address << ":" << classRosterArray[i]->getFirst_name() << std::endl;//print invalid email
		}
	}
	if (!any)cout << "None" << std::endl;//print if no invalid student IDs
}

//print average days
void Roster::printAverageDays(string student_ID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == student_ID)
		{
			cout << student_ID << ":";
			cout << (classRosterArray[i]->getDays()[0] +
					classRosterArray[i]->getDays()[1] +
					classRosterArray[i]->getDays()[2]) / 3 << std::endl;
			//divide by number of course day counts
		}
	}
}

//display students matching degree type
void Roster::printByDegreeType(DegreeType degreeType)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeType() == degreeType) classRosterArray[i]->print();
	}
	cout << std::endl;
}

//take student ID for student to be removed as parameter
bool Roster::removeStudentByID(string student_ID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)//use last index since it may change
	{
		if (classRosterArray[i]->getID() == student_ID)
		{
			success = true; //student found
			if (i < studentDataTable - 1)
			{
				Student* temp = classRosterArray[i];//swap places with last student
				classRosterArray[i] = classRosterArray[studentDataTable - 1];//move point not the data in memory
				classRosterArray[studentDataTable - 1] = temp;
			}
			Roster::lastIndex--; //last student not destroyed but hidden
		}
	}
	if (success)
	{
		cout << student_ID << " removed from roster." << std::endl << std::endl;
		this->printAll();//display all students except removed students
	}
	else cout << student_ID << " not found." << std::endl << std::endl;
	return 0;
}

//remove dynamically allocated objects; the repository dynamically creates book objects therefore must be used to destroy them
Roster::~Roster()
{
	cout << "Destructor called!" << std::endl << std::endl;
	for (int i = 0; i < studentDataTable; i++)//size of number of books stay the same unlike last index
	{
		cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;//set to nullptr to no longer pointed at that address to prevent crash
	}
}