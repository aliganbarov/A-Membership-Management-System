#include "Memberships.h"
#include "Team.h"
#include "Academic.h"
#include <iostream>
#define MAX 1000000
using namespace std;

Memberships::Memberships()
{
	teams = new Team[100];
	numbOfTeams = 0;
}

Memberships::~Memberships()
{
	delete[] teams;
}

void Memberships::AddNewTeam()
{
	char *teamName, *firstName, *lastName, *email;
	int employeeId, numb, title, day, month, year;
	teamName = new char[20];
	firstName = new char[20];
	lastName = new char[20];
	email = new char[20];
	cout << "Enter Team Name: ";
	cin >> teamName;
	teams[numbOfTeams].SetTeamName(teamName);
	cout << "Enter the details of the team leader" << endl << "Employee ID: ";
	while (true)																							//getting correct input
	{
		if ((cin >> employeeId) && (employeeId >= 1) && (employeeId <= MAX)) break;
		cout << "Enter correct Employee ID: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "Telephone number: ";
	while (true)																							//getting correct input
	{
		if ((cin >> numb) && (numb >= 1) && (numb <= MAX)) break;
		cout << "Enter correct Number: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Email address: ";
	cin >> email;
	cout << "Academic Title (1) Professor (2) Associate: ";
	while (true)																							//getting correct input
	{
		if ((cin >> title) && (title >= 1) && (title <= 2)) break;
		cout << "Enter correct Title (1) Professor (2) Associate: ";
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
	cout << "The team leader has been added to the team successfully!" << endl;
	teams[numbOfTeams].SetTeamLider(employeeId, firstName, lastName, numb, email, title, day, month, year);						//making new team lider
	teams[numbOfTeams++].AddNewMember();																						//adding members and increasing number of teams
	
	delete[] teamName;
	delete[] firstName;
	delete[] lastName;
	delete[] email;
}

void Memberships::SearchForMember()
{
	int i;
	for (i = 0; i < numbOfTeams; i++)
	{
		teams[i].SearchForMember();
	}
}

void Memberships::PrintTeams()
{
	int i;
	for (i = 0; i < numbOfTeams; i++)
		teams[i].ListMembers();
}

void Memberships::PrintTeam()
{
	char *teamName;
	teamName = new char[20];
	cout << "Team Name: ";
	cin >> teamName;
	int i;
	for (i = 0; i < numbOfTeams; i++)
	{
		if (strcmp(teams[i].GetTeamName(), teamName) == 0)
			break;
	}
	teams[i].ListMembers();
	delete[] teamName;
}

void Memberships::PrintFees()
{
	float totalFees = 0;
	int i;
	for (i = 0; i < numbOfTeams; i++)
	{
		totalFees += teams[i].AnnualCostOfTeam();
	}
	cout << "Total annual cost is %" << totalFees << endl;
}

void Memberships::PrintFee()
{
	float totalFee;
	char *teamName = new char[20];
	int i;
	cout << "Team Name: ";
	cin >> teamName;
	for (i = 0; i < numbOfTeams; i++)
	{
		if (strcmp(teams[i].GetTeamName(), teamName) == 0)
			break;
	}
	if (i < numbOfTeams)
		cout << "Total annual cost for the " << teamName << " team is $" << teams[i].AnnualCostOfTeam() << endl;
	else
		cout << "Team wasn't found!" << endl;
	delete[] teamName;
}