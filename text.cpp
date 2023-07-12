#include "lista.h"
#include "text.h"

Element* creare(char text[])
{
    Element* p = new Element;
    p->data = text;
    p->next = 0;
    p->next = 0;
    return p;
}
