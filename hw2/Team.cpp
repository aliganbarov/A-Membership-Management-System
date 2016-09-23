#include <iostream>
#include <string.h>
#include "Team.h"
#define MAX 1000000
using namespace std;

Academic AddingAcademicMember();
Admin AddingAdminMember();
Student AddingStudentMember();

Team::Team()
{
	teamName = new char[20];
	teamName = "No Name";
	academicMembers = new Academic[100];
	studentMembers = new Student[100];
	adminMembers = new Admin[100];
	stSize = 0;
	acSize = 0;
	adSize = 0;
}

Team::Team(char *teamName)
{
	this->teamName = new char[20];
	strcpy(this->teamName, teamName);
	academicMembers = new Academic[100];
	studentMembers = new Student[100];
	adminMembers = new Admin[100];
	stSize = 0;
	acSize = 0;
	adSize = 0;
}

void Team::SetTeamName(char *teamName)
{
	this->teamName = new char[20];
	strcpy(this->teamName, teamName);
}

const char* Team::GetTeamName()
{
	return teamName;
}

void Team::SetTeamLider(int employeeId, char* firstName, char* lastName, int numb, char* email, int title, int day, int month, int year)
{
	if (title == 1) title = 6;																									//corrections for title enum
	else title = 5;
	teamLider.SetEmployeeId(employeeId);
	teamLider.SetFirstName(firstName);
	teamLider.SetLastName(lastName);
	teamLider.SetNumb(numb);
	teamLider.SetEmail(email);
	teamLider.SetTitle(title);
	teamLider.SetDate(day, month, year);

}

Academic Team::GetTeamLider()
{
	return teamLider;
}

void Team::ListMembers()
{
	cout << "\nTeam: " << teamName << endl << "Team Leader: " << endl << teamLider.GetEmployeeId() << " " << teamLider.GetFirstName() << " " << teamLider.GetLastName() << " "<<
		teamLider.GetNumb() << " " << teamLider.GetEmail() << endl;
	int i;
	cout << "\nAcademic Staff Members: " << endl;
	for (i = 0; i < acSize; i++)
	{
		cout << academicMembers[i].GetEmployeeId() << " " << academicMembers[i].GetFirstName() << " " << academicMembers[i].GetLastName() << " " <<
			academicMembers[i].GetNumb() << " " << academicMembers[i].GetEmail() << endl;
	}
	cout << "\nStudent Members: " << endl;
	for (i = 0; i < stSize; i++)
	{
		cout << studentMembers[i].GetStudentId() << " " << studentMembers[i].GetFirstName() << " " << studentMembers[i].GetLastName() << " " <<
			studentMembers[i].GetNumb() << " " << studentMembers[i].GetEmail() << endl;
	}
	cout << "\nAdministrative Members: " << endl;
	for (i = 0; i < adSize; i++)
	{
		cout << adminMembers[i].GetEmployeeId() << " " << adminMembers[i].GetFirstName() << " " << adminMembers[i].GetLastName() << " " <<
			adminMembers[i].GetNumb() << " " << adminMembers[i].GetEmail() << endl;
	}
}

float Team::AnnualCostOfTeam()
{
	float totalFee = 0;
	int i, fee;
	totalFee += teamLider.Fee();
	for (i = 0; i < acSize; i++)
	{
		totalFee += academicMembers[i].Fee();
	}
	for (i = 0; i < adSize; i++)
	{
		totalFee += adminMembers[i].Fee();
	}
	for (i = 0; i < stSize; i++)
	{
		totalFee += studentMembers[i].Fee();
	}
	return totalFee;
}

void Team::SearchForMember()
{
	int id, memberType, i;
	cout << "Please indicate his/her role (1) Academic Staff (2) Student(3) Administrative Staff : ";
	while (true)																												//getting correct input
	{
		if ((cin >> memberType) && (memberType >= 1) && (memberType <= 3)) break;
		cout << "Enter correct Member Type ((1) Academic Staff (2) Student(3) Administrative Staff): ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (memberType == 1)																										//searching for academic member
	{
		cout << "Enter Employee ID: ";
		while (true)																											//getting correct input
		{
			if ((cin >> id) && (id >= 1) && (id <= MAX)) break;
			cout << "Enter correct Member Type ((1) Academic Staff (2) Student(3) Administrative Staff): ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		for (i = 0; i < acSize; i++)																							//traversing through all academic members
		{
			if (id == academicMembers[i].GetEmployeeId())																		//if match, print details
			{
				cout << "\nThe member has been found in the " << teamName << " team." << "The details are listed below" << endl;
				cout << academicMembers[i].GetEmployeeId() << " " << academicMembers[i].GetFirstName() << " " << academicMembers[i].GetLastName() << " " <<
					academicMembers[i].GetNumb() << " " << academicMembers[i].GetEmail() << endl;
			}
		}
	}
	else if (memberType == 2)																									//searching for student member
	{
		cout << "Enter Student ID: ";
		while (true)																											//getting correct input
		{
			if ((cin >> id) && (id >= 1) && (id <= MAX)) break;
			cout << "Enter correct Member Type ((1) Academic Staff (2) Student(3) Administrative Staff): ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		for (i = 0; i < stSize; i++)																							//traversing through all student members
		{
			if (id == studentMembers[i].GetStudentId())																			//if match, print details
			{
				cout << "\nThe member has been found in the " << teamName << " team." << "The details are listed below" << endl;
				cout << studentMembers[i].GetStudentId() << " " << studentMembers[i].GetFirstName() << " " << studentMembers[i].GetLastName() << " " <<
					studentMembers[i].GetNumb() << " " << studentMembers[i].GetEmail() << endl;
			}
		}
	}
	else if (memberType == 3)																									//searching for admin member
	{
		cout << "Enter Employee ID: ";
		while (true)																											//getting correct input
		{
			if ((cin >> id) && (id >= 1) && (id <= MAX)) break;
			cout << "\nEnter correct Member Type ((1) Academic Staff (2) Student(3) Administrative Staff): ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		for (i = 0; i < adSize; i++)																							//traversing through all members
		{
			if (id == adminMembers[i].GetEmployeeId())																			//if match, print details
			{
				cout << "\nThe member has been found in the " << teamName << " team." << "The details are listed below" << endl;
				cout << adminMembers[i].GetEmployeeId() << " " << adminMembers[i].GetFirstName() << " " << adminMembers[i].GetLastName() << " " <<
					adminMembers[i].GetNumb() << " " << adminMembers[i].GetEmail() << endl;
			}
		}
	}
	else
		cout << "Wrong choice! " << endl;
}

void Team::AddNewMember()
{
	int opt;
	char ch;
	while (1)
	{
		cout << "Would you like to add a new member to the team (Y/N): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "1.Academic Staff" << endl << "2.Student" << endl << "3.Administrative Staff" << endl << "Select Type: ";
			while (true)																							//getting correct input
			{
				if ((cin >> opt) && (opt >= 1) && (opt <= 3)) break;
				cout << "Enter correct option Member Type((1)Academic Type (2) Student (3) Administrative Staff): ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cout << "Enter the details of the team member: " << endl;
			switch (opt)
			{
			case 1:
				academicMembers[acSize++] = AddingAcademicMember();
				break;
			case 2:
				studentMembers[stSize++] = AddingStudentMember();
				break;
			case 3:
				adminMembers[adSize++] = AddingAdminMember();
				break;
			default:
				cout << "Choose correct option: ";
				break;
			}
		}
		else if (ch == 'N' || ch == 'n')
		{
			cout << "The team has been added to the university successfully!" << endl;
			return;
		}
		else
			cout << "Enter Y or N" << endl;
	}
}

Academic AddingAcademicMember()
{
	int employeeId, numb, title, day, month, year;
	char *firstName, *lastName, *email;
	firstName = new char[20];
	lastName = new char[20];
	email = new char[20];
	Academic temp;
	cout << "Employee ID: ";
	while (true)																							//getting correct input
	{
		if ((cin >> employeeId) && (employeeId >= 1) && (employeeId <= MAX)) break;
		cout << "Enter correct Employee ID: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "First name: ";
	cin >> firstName;
	cout << "Last name: ";
	cin >> lastName;
	cout << "Telephone number: ";
	while (true)																							//getting correct input
	{
		if ((cin >> numb) && (numb >= 1) && (numb <= MAX)) break;
		cout << "Enter correct Number: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Email: ";
	cin >> email;
	cout << "Academic Title (1) Assistant Professor (2) Doctor (3) Instructor (4) Assistant: ";
	while (true)																							//getting correct input
	{
		if ((cin >> title) && (title >= 1) && (title <= 4)) break;
		cout << "Enter correct Academic Title (1) Assistant Professor (2) Doctor (3) Instructor (4) Assistant: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Date membership initiated(dd mm yyyy): ";
	while (true)																							//getting correct input
	{
		if ((cin >> day >> month >> year) && (day >= 1) && (day <= 31) && (month >= 1) && (month <= 12) && (year >= 1) && (year <= 2016)) break;
		cout << "Enter correct Date(dd mm yyyy): ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	temp.SetDate(day, month, year);
	temp.SetFirstName(firstName);
	temp.SetLastName(lastName);
	temp.SetNumb(numb);
	temp.SetEmployeeId(employeeId);
	temp.SetTitle(title);
	temp.SetEmail(email);
	delete[] firstName;
	delete[] lastName;
	delete[] email;
	cout << "The academic member has been added to the team successfully!" << endl;
	return temp;
} 

Admin AddingAdminMember()
{
	int employeeId, numb, adminType, socialType;
	char *firstName, *lastName, *email;
	firstName = new char[20];
	lastName = new char[20];
	email = new char[20];
	Admin temp;
	cout << "Employee ID: ";
	while (true)																							//getting correct input
	{
		if ((cin >> employeeId) && (employeeId >= 1) && (employeeId <= MAX)) break;
		cout << "Enter correct Employee ID: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "First name: ";
	cin >> firstName;
	cout << "Last name: ";
	cin >> lastName;
	cout << "Telephone number: ";
	while (true)																							//getting correct input
	{
		if ((cin >> numb) && (numb >= 1) && (numb <= MAX)) break;
		cout << "Enter correct Number: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Email: ";
	cin >> email;
	cout << "Admin Type: (1) Manager (2) Secretary:  ";
	while (true)																							//getting correct input
	{
		if ((cin >> adminType) && (adminType >= 1) && (adminType <= 2)) break;
		cout << "Enter correct Admin Type (1) Manager (2) Secretary: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Social member type (1) All Magazines (2)Game Geek Monthly : ";
	while (true)																							//getting correct input
	{
		if ((cin >> socialType) && (socialType >= 1) && (socialType <= 2)) break;
		cout << "Enter correct Social Type (1) All Magazines (2)Game Geek Monthly: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	temp.SetSocialType(socialType);
	temp.SetFirstName(firstName);
	temp.SetLastName(lastName);
	temp.SetNumb(numb);
	temp.SetEmployeeId(employeeId);
	temp.SetAdminType(adminType);
	temp.SetEmail(email);
	delete[] firstName;
	delete[] lastName;
	delete[] email;
	cout << "The administrative member has been added to the team successfully!" << endl;
	return temp;
}

Student AddingStudentMember()
{
	int studentId, numb, type;
	char *firstName, *lastName, *email;
	firstName = new char[20];
	lastName = new char[20];
	email = new char[20];
	Student temp;
	cout << "Student ID: ";
	while (true)																							//getting correct input
	{
		if ((cin >> studentId) && (studentId >= 1) && (studentId <= MAX)) break;
		cout << "Enter correct Student ID: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "First name: ";
	cin >> firstName;
	cout << "Last name: ";
	cin >> lastName;
	cout << "Telephone number: ";
	while (true)																							//getting correct input
	{
		if ((cin >> numb) && (numb >= 1) && (numb <= MAX)) break;
		cout << "Enter correct Number: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Email: ";
	cin >> email;
	cout << "Student Member Type (1) Full (2) Competitor: ";
	while (true)																							//getting correct input
	{
		if ((cin >> type) && (type >= 1) && (type <= 2)) break;
		cout << "Enter correct Student Member Type (1) Full (2) Competitor: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	temp.SetFirstName(firstName);
	temp.SetLastName(lastName);
	temp.SetNumb(numb);
	temp.SetStudentId(studentId);
	temp.SetType(type);
	temp.SetEmail(email);
	delete[] firstName;
	delete[] lastName;
	delete[] email;
	cout << "The student member has been added to the team successfully!" << endl;
	return temp;
}