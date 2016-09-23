#ifndef TEAM_H
#define TEAM_H
#include "Academic.h"
#include "Student.h"
#include "Admin.h"

class Team
{
private:
	char *teamName;
	Academic teamLider;
	Student *studentMembers;
	int stSize;
	Admin *adminMembers;
	int adSize;
	Academic *academicMembers;
	int acSize;
public:
	Team();
	Team(char*);
	void SetTeamName(char*);
	const char* GetTeamName();
	void SetTeamLider(int, char*, char*, int, char*, int, int, int, int);
	Academic GetTeamLider();
	void AddNewMember();
	void ListMembers();
	float AnnualCostOfTeam();
	void SearchForMember();

};

#endif // !TEAMS_H
