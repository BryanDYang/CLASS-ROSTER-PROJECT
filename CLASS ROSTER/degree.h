/*
 C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

 Note: This information should be included in the degree.h file.
 */

#pragma once
#include <string>

enum DegreeType{SECURITY, NETWORK, SOFTWARE};

//Pararlle array pops out a string for each DegreeType. Using DegreeType as an index
static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };