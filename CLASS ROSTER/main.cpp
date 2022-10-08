/*F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
 2.  Create an instance of the Roster class called classRoster.
 3.  Add each student to classRoster.
 4.  Convert the following pseudo code to complete the rest of the  main() function:
 classRoster.printAll();
 classRoster.printInvalidEmails();

 //loop through classRosterArray and for each element:
 classRoster.printAverageDaysInCourse(current_object's student id);

 classRoster.printByDegreeProgram(SOFTWARE);
 classRoster.remove("A3");
 classRoster.printAll();
 classRoster.remove("A3");
 //expected: the above line should print a message saying such a student with this ID was not found.*/

#include <iostream>
#include "roster.h"
using namespace std;
//using std::endl;

int main()
{
	cout << "Course: C867 Scripting and Programming - Applications\n" << "Programming Language: C++\n" << "ID: 001303738\n" << "Name: Bryan Yang" << std::endl << std::endl;

	//long string to parse
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bryan,Yang,byang10@wgu.com,29,11,22,33,SOFTWARE"
	};

	const int studentDataTable = 5;//size array
	Roster roster;//create roster with default parameterless construtor; everything = 0

	for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
	//display all students
	cout << "Displaying all student:" << std::endl;
	roster.printAll();
	cout << std::endl;

	//display all students in the software degree program
	cout << "Displaying all software students:" << std::endl;
	roster.printByDegreeType(SOFTWARE);
	cout << std::endl;

	//display all students who have email addresses with incorrect format 
	cout << "Displaying invalid email address:" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	//display the average number of days each student spends for the 3 classes
	cout << "Displaying average days per class:" << std::endl;
	for (int i = 0; i < studentDataTable; i++)
	{
		roster.printAverageDays(roster.classRosterArray[i]->getID());
	}
	cout << std::endl;

	//remove student A3 and print remaining students
	cout << "Remove student A3" << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;

	//double check by causing an error when A3 is not found
	cout << "Remove student A3" << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl << std::endl;

}
