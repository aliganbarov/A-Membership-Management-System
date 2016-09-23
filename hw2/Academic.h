#ifndef ACADEMIC
#define ACADEMIC
#include "Member.h"

class Academic : public Member
{
private:
	int employeeId;
	enum Title {NoTitle, Assistant, Instructor, Doctor, AssistantProfessor, AssociateProfessor, Professor}title;
	struct Date { int day; int month; int year; }date;

public:
	Academic();
	Academic(char * firstName, char * lastName, int numb, char * email, int employeeId, int title, int day, int month, int year);
	void SetEmployeeId(int);
	const int GetEmployeeId();
	void SetTitle(int);
	const int GetTitle();
	void SetDate(int, int, int);
	const Date GetDate();
	int Fee();
	void Printer(); //override
};


#endif // !ACADEMIC
