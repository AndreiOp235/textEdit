#pragma once
#include <vector>
typedef char* Atom;
struct Element
{
	Atom data;
	Element* prev, * next;
};
class lista
{
private:
	Element *cap=0;
public:
	Element* getCap();
	void setCap(Element *newCap);

	void Insert(char text[]);
	void Insert(char text[],int poz);
	void Display();
	void Delete();
	void Delete(int k, int poz);
	void Delete_All(char text[]);
	void Replace(char text[], char text2[]);

	std::vector<int> Find(char text[]);
};
