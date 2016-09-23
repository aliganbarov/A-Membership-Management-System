#ifndef ADMIN
#define ADMIN
#include "Member.h"

class Admin : public Member
{
private:
	int employeeId;
	enum AdminType {Null, Manager, Secretary } adminType;
	enum SocialType {NoType, AllMagazines, GameGeek } socialType;

public:
	Admin();
	Admin(char*, char*, int, char*, int, int, int);
	void SetEmployeeId(int);
	int GetEmployeeId();
	void SetAdminType(int);
	int GetAdminType();
	void SetSocialType(int);
	int GetSocialType();
	int Fee();
	void Printer();
};


#endif // !ADMIN
