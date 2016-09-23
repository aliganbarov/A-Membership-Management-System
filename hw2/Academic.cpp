#include <iostream>
#include "Academic.h"
#include <string.h>

using namespace std;

Academic::Academic()
{
	employeeId = 0;
	title = NoTitle;
	date.day = 0;
	date.month = 0;
	date.year = 0;
}

Academic::Academic(char* firstName, char* lastName, int numb, char* email, int employeeId, int title, int day, int month, int year) : Member(firstName, lastName, numb, email)
{
	this->employeeId = employeeId;
	if (title == 1) this->title = Assistant;
	else if (title == 2) this->title = Instructor;
	else if (title == 3) this->title = Doctor;
	else if (title == 4) this->title = AssistantProfessor;
	else if (title == 5) this->title = AssociateProfessor;
	else if (title == 6) this->title = Professor;
	else this->title = NoTitle;
	date.day = day;
	date.month = month;
	date.year = year;
}

void Academic::SetEmployeeId(int employeeId)
{
	this->employeeId = employeeId;
}

const int Academic::GetEmployeeId()
{
	return employeeId;
}

void Academic::SetTitle(int title)
{
	if (title == 1) this->title = Assistant;
	else if (title == 2) this->title = Instructor;
	else if (title == 3) this->title = Doctor;
	else if (title == 4) this->title = AssistantProfessor;
	else if (title == 5) this->title = AssociateProfessor;
	else if (title == 6) this->title = Professor;
	else this->title = NoTitle;
}

const int Academic::GetTitle()
{
	return title;
}

void Academic::SetDate(int day, int month, int year)
{
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
}

const Academic::Date Academic::GetDate()
{
	return date;
}

int Academic::Fee()
{
	int discount = 2016 - date.year;
	return discount > 5 ? 100 : 20 * (10 - discount);
}

void Academic::Printer()
{
	Member::Printer();
	cout << "EmployeeId: " << employeeId << endl << "Title: " << title << endl << "Registration date: " << date.year << endl;
}