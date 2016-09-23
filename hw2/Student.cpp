#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	studentId = 0;
	type = NoType;
	numbOfCompetitions = 0;
}

Student::Student(char* firstName, char* lastName, int numb, char* email, int studentId, int type, int numbOfCompetitions) : Member(firstName, lastName, numb, email)
{
	this->studentId = studentId;
	if (type == 1) this->type = Full;
	else if (type == 2) this->type = Competitor;
	else this->type = NoType;
	this->numbOfCompetitions = numbOfCompetitions;
}

void Student::SetStudentId(int studentId)
{
	this->studentId = studentId;
}

int Student::GetStudentId()
{
	return studentId;
}

void Student::SetType(int type)
{
	if (type == 1) this->type = Full;
	else if (type == 2) this->type = Competitor;
	else this->type = NoType;
}

int Student::GetType()
{
	return type;
}

void Student::SetNumbOfCompetitions(int numbOfCompetitions)
{
	this->numbOfCompetitions = numbOfCompetitions;
}

int Student::GetNumbOfCompetitions()
{
	return numbOfCompetitions;
}

int Student::Fee()
{
	if (type == Full) return 50;
	else if (type == Competitor) return numbOfCompetitions * 10;
	else return 0;
}

void Student::Printer()
{
	Member::Printer();
	cout << "Student ID: " << studentId << endl << "Type: " << type<< endl << "Number of Competitions: " << numbOfCompetitions << endl;
}