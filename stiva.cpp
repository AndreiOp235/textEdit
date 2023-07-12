#include <stdlib.h>
#include <iostream>
#include <string>
#include "loading.h"
#include "lista.h"
#include "text.h"
#include "stiva.h"

using std::cin;
using std::cout;
using std::strcpy;
using std::getline;
using std::string;
using std::vector;
using std::endl;
using std::to_string;

s_Element* stiva::getVarf()
{
	return top;
}

void stiva::setVarf(s_Element* newTop)
{
	top = newTop;
}

stiva::stiva()
{
	top = 0;
}

void stiva::Push(s_atom data)
{
	s_Element* p = new s_Element;
	p->data = data;
	p->next = getVarf();
	setVarf(p);
}

void stiva::pop()
{
	if (!isEmpty())
	{
		setVarf(getVarf()->next);
	}
	else
	{
		throw "Operatia ";
	}
}

s_atom stiva::TOP()
{
	if (!isEmpty())
	{
		return getVarf()->data;
	}
	else
	{
		throw "lista goala";
	}
}

bool stiva::isEmpty()
{
	if (getVarf())
	{
		return false;
	}
	else 
	{
		return true;
	}
}
