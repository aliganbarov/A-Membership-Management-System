#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin()
{
	employeeId = 0;
	adminType = Null;
	socialType = NoType;
}

Admin::Admin(char* firstName, char* lastName, int numb, char* email, int employeeId, int adminType, int socialType) : Member(firstName, lastName, numb, email)
{
	this->employeeId = employeeId;
	if (adminType == 1) this->adminType = Manager;
	else if (adminType == 2) this->adminType = Secretary;
	else this->adminType = Null;
	if (socialType == 1) this->socialType = AllMagazines;
	else if (socialType == 2) this->socialType = GameGeek;
	else this->socialType = NoType;
}

void Admin::SetEmployeeId(int employeeId)
{
	this->employeeId = employeeId;
}

int Admin::GetEmployeeId()
{
	return employeeId;
}

void Admin::SetAdminType(int adminType)
{
	if (adminType == 1) this->adminType = Manager;
	else if (adminType == 2) this->adminType = Secretary;
	else this->adminType = Null;
}

int Admin::GetAdminType()
{
	return adminType;
}

void Admin::SetSocialType(int socialType)
{
	if (socialType == 1) this->socialType = AllMagazines;
	else if (socialType == 2) this->socialType = GameGeek;
	else this->socialType = NoType;
}

int Admin::GetSocialType()
{
	return socialType;
}

int Admin::Fee()
{
	if (socialType == 1) return 100;
	else if (socialType == 2) return 25;
	else return 0;
}

void Admin::Printer()
{
	Member::Printer();
	cout << "Employee ID: " << employeeId << endl << "Admin type: " << adminType << endl << "Social Type: " << socialType << endl;
}