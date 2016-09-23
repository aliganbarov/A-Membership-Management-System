#include <iostream>
#include <string.h>
#include "Member.h"

using namespace std;

Member::Member()
{
	firstName = new char[20];
	firstName = "No First Name";
	lastName = new char[20];
	lastName = "No Last Name";
	numb = 0;
	email = new char[20];
	email = "No Email";
}

Member::Member(char* firstName, char* lastName, int numb, char* email)
{
	this->firstName = new char[20];
	strcpy(this->firstName, firstName);
	this->lastName = new char[20];
	strcpy(this->lastName, lastName);
	this->numb = numb;
	this->email = new char[20];
	strcpy(this->email, email);
}

Member::Member(const Member &obj)
{
	this->firstName = new char[20];
	strcpy(this->firstName, obj.firstName);
	this->lastName = new char[20];
	strcpy(this->lastName, obj.lastName);
	this->numb = obj.numb;
	this->email = new char[20];
	strcpy(this->email, obj.email);
}

void Member::operator=(const Member &obj)
{
	this->firstName = new char[20];
	strcpy(this->firstName, obj.firstName);
	this->lastName = new char[20];
	strcpy(this->lastName, obj.lastName);
	this->numb = obj.numb;
	this->email = new char[20];
	strcpy(this->email, obj.email);
}

Member::~Member()
{
	delete[] firstName;
	delete[] lastName;
	delete[] email;
}

const char* Member::GetFirstName()
{
	return firstName;
}

void Member::SetFirstName(char* firstName)
{
	this->firstName = new char[20];
	strcpy(this->firstName, firstName);
}

const char* Member::GetLastName()
{
	return lastName;
}

void Member::SetLastName(char* lastName)
{
	this->lastName = new char[20];
	strcpy(this->lastName, lastName);
}

int Member::GetNumb()
{
	return numb;
}

void Member::SetNumb(int numb)
{
	this->numb = numb;
}

const char* Member::GetEmail()
{
	return email;
}

void Member::SetEmail(char* email)
{
	this->email = new char[20];
	strcpy(this->email, email);
}

void Member::Printer()
{
	cout << "First Name: " << firstName << endl << "Last Name: " << lastName << endl << "Number: " << numb << endl << "Email: " << email << endl;
}