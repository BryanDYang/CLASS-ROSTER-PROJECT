/*2.  Create each of the following functions in the Student class:
 a.  an accessor (i.e., getter) for each instance variable from part D1
 b.  a mutator (i.e., setter) for each instance variable from part D1
 c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
 d.  constructor using all of the input parameters provided in the table
 e.  print() to print specific student data*/

#include "student.h"

 //parameterless constructor: sets to default values
Student::Student() 
{
	//(pointer)->(variable)
	this->student_ID = "";//empty string != null
	this->first_name = "";
	this->last_name = "";
	this->email_address = "";
	this->age = 0;
	for (int i = 0; i < daysArray; i++) this->days[i] = 0; //loops array and sets default price = 0
	this->degreeType = DegreeType::SECURITY;//default degree type to software using value created in Degree.h
}

//main constructor
Student::Student(string student_ID, string first_name, string last_name, string email_address, int age, int days[], DegreeType degreeType)
{
	//(pointer)->(variable)
	this->student_ID = student_ID;
	this->first_name = first_name;
	this->last_name = last_name;
	this->email_address = email_address;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
	this->degreeType = degreeType;
}

//destructor: executes nothing because nothing is created dynamtically
Student::~Student(){}

//getters or acessors
string Student::getID() { return this->student_ID; }
string Student::getFirst_name() { return this->first_name; }
string Student::getLast_name() { return this->last_name; }
string Student::getEmail_address() { return this->email_address; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }//array name is a pointer
DegreeType Student::getDegreeType() { return this->degreeType; }

//setters or mutators
void Student::setID(string student_ID) { this->student_ID = student_ID; }
void Student::setFirst_name(string first_name) { this->first_name = first_name; }
void Student::setLast_name(string last_name) { this->last_name = last_name; }
void Student::setEmail_address(string email_address) { this->email_address = email_address; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
//set each number of days individually
{
	for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType degreeType) { this->degreeType = degreeType; }

//print header
void Student::printHeader()
{
	//printout format
	cout << "ID" << '\t' << "First" << '\t' << "Last" << '\t' << "Email Address" << '\t' << "Age" << '\t' << "Days to Complete" << '\t' << "Degree" << std::endl;
}

//delimited tabs
void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirst_name() << '\t';
	cout << this->getLast_name() << '\t';
	cout << this->getEmail_address() << '\t';
	cout << this->getAge() << '\t';
	//grab days individually, not pointer or address
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	//degreeType to string: was an int, change to string by using Degree.h
	cout << degreeTypeStrings[this->getDegreeType()] << '\n';
}
