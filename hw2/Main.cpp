#include <iostream>
#include "Memberships.h"
using namespace std;

void menu();

int main()
{
	cout << "Welcome to University ICSE Membership Management System!" << endl;
	menu();

	system("PAUSE");
	return 0;
}

void menu()
{
	int opt;
	Memberships m;
	while (1)
	{
		cout << "\n1. Create team\n2. Search a member by ID\n3. List all members\n4. List total annual cost\n5. List all members of a given team" <<
			endl << "6. List total annual cost of a given team\n7. Exit\nYour choice: ";
		while (true)																							//getting correct input
		{
			if ((cin >> opt) && (opt >= 1) && (opt <= 7)) break;
			cout << "Enter correct option: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (opt)
		{
		case 1:
			m.AddNewTeam();
			break;
		case 2:
			m.SearchForMember();
			break;
		case 3:
			m.PrintTeams();
			break;
		case 4:
			m.PrintFees();
			break;
		case 5:
			m.PrintTeam();
			break;
		case 6:
			m.PrintFee();
			break;
		case 7:
			exit(1);
			break;
		default:
			cout << "Wrong option!" << endl;																		//though never come to this..
		}
	}
}