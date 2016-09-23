#ifndef STUDENT
#define STUDENT
#include "Member.h"

class Student : public Member
{
private:
	int studentId;
	enum Type {NoType, Full, Competitor } type;
	int numbOfCompetitions;

public:
	Student();
	Student(char*, char*, int, char*, int, int, int);
	void SetStudentId(int);
	int GetStudentId();
	void SetType(int);
	int GetType();
	void SetNumbOfCompetitions(int);
	int GetNumbOfCompetitions();
	int Fee();
	void Printer();
};

#endif // !STUDENT
