#ifndef MEMBERSHIPS_H
#define MEMBERSHIPS_H
#include "Team.h"

class Memberships
{
private:
	Team *teams;
	int numbOfTeams;
public:
	Memberships();
	~Memberships();
	void AddNewTeam();
	void SearchForMember();
	void PrintTeams();
	void PrintTeam();
	void PrintFees();
	void PrintFee();
};

#endif // !MEMBERSHIPS_H
