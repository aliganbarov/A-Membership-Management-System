#ifndef MEMBER
#define MEMBER

class Member
{
private:
	char* firstName;
	char* lastName;
	int numb;
	char* email;

public:
	Member();
	Member(char*, char*, int, char*);
	Member(const Member &);
	void operator=(const Member &);
	~Member();
	const char* GetFirstName();
	void SetFirstName(char*);
	const char* GetLastName();
	void SetLastName(char*);
	int GetNumb();
	void SetNumb(int);
	const char*GetEmail();
	void SetEmail(char*);
	void Printer();
};

#endif // !MEMBER
