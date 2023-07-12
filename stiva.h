#pragma once
struct operatie
{
	int ID_op=0;
	char* arg1 = 0, * arg2 = 0;
};

typedef operatie* s_atom;

struct s_Element
{
	s_atom data;
	s_Element* next;
};
class stiva
{
private:
	s_Element* top;
public:
	stiva();

	s_Element* getVarf();
	void setVarf(s_Element* newTop);
	void Push(s_atom data);
	void pop();

	s_atom TOP();

	bool isEmpty();
};
