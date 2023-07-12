#include <cstring>
#include <iostream>
#include <vector>
#include "lista.h"
#include "text.h"

//using namespace std;
using std::cin;
using std::cout;
using std::strcpy;
using std::string;
using std::vector;
using std::endl;

Element* lista::getCap()
{
    return cap;
}

void lista::setCap(Element* newCap)
{
    cap = newCap;
}

void lista::Insert(char text[])
{
    Element* end;
    if (getCap() == 0)
    {
        end = 0;
    }
    else
    {
        end = getCap();
        while (end->next)
        {
            end = end->next;
        }
    }

    char* pch;
    char* next_token=NULL;

    pch = strtok_s(text," ",&next_token);
    while (pch) 
    {
        //cout << pch << endl;
        Element* nou = creare(pch);

        if (getCap() == 0)
        {
            setCap(nou);
            cap->next = 0;
            cap->prev = 0;
            end = cap;
        }
        else
        {
            nou->prev = end;
            if (!end)
            {
                throw "memory management fail";
            }
            end->next = nou;
            end = end->next;
        }
        pch = strtok_s(NULL, " ", &next_token);
    }


}

void lista::Insert(char text[], int poz)
{
    Element* end;
    int i = 1,j=1;
    bool flag=true;

    if (getCap() == 0)
    {
        end = 0;
    }
    else
    {
        end = getCap();
        while (end->next)
        {
            end = end->next;
            i++;
        }

        end = getCap();
        while (end->next)
        {
            end = end->next;
            j++;
            if (j == poz)
                break;
            
        }
    }

    if (poz >= i+2)
    {
        throw "Inserarea nu a putut fi efectuata: pozitie invalida";
    }

    char* pch;
    char* next_token = NULL;

    if (getCap() == 0||((i+1)==poz))
    {
        return lista::Insert(text);
    }

    pch = strtok_s(text, " ", &next_token);
    while (pch)
    {
        //cout << pch << endl;
        Element* nou = creare(pch);

        if (getCap() == 0)
        {
            setCap(nou);
            cap->next = 0;
            cap->prev = 0;
            end = cap;
        }
        else
        {
            if (!end)
            {
                throw "memory management fail";
            }

            nou->prev = end->prev;
            if(end->prev)
            {
                end->prev->next = nou;
            }
            
            nou->next = end;
            end->prev = nou;
            //end = nou;
            
        }
        pch = strtok_s(NULL, " ", &next_token);
    }
}

void lista::Display()
{
    if (getCap())
    {
        Element* aux = cap;
        while (aux)
        {
            cout << aux->data << " ";
            aux = aux->next;
        }
    }

    else
        throw "Afisarea textului nu a putut fi efectuata: nu exista text in editor.";
}

void lista::Delete()
{
    Element* aux = getCap();
    Element* aux2;
    if (!getCap())
    {
        throw "Stergerea nu a putut fi efectuata: nu exista text in editor";
    }

    while (aux)
    {
        aux2 = aux;
        aux = aux->next;
        delete aux2;
    }

    setCap(0);
}

void lista::Delete(int k, int poz)
{
    Element* end = getCap();
    Element* aux;
    int i = 1;

    if (end == 0)
    {
        throw "Lista este goala";
    }
    else if (poz == 1)
    {
        while (end != 0 && k > 0)
        {
            aux = end;
            end = end->next;
            delete aux;
            k--;
        }
        setCap(end);
        if (end != 0)
        {
            end->prev = 0;
        }
    }
    else
    {
        while (end != 0 && i != poz - 1)
        {
            end = end->next;
            i++;
        }

        if (end == 0)
        {
            throw "Stergerea nu a putut fi efectuata: pozitie invalida";
        }

        Element* current = end->next;
        while (current != 0 && k > 0)
        {
            aux = current;
            current = current->next;
            delete aux;
            k--;
        }

        end->next = current;

        if (current != 0)
        {
            current->prev = end;
        }
    }
}

void lista::Delete_All(char text[])
{
    Element* end,*aux;
    end = getCap();

    if (!getCap())
        throw "Lista goala!";


    bool flag = false;
    while (end)
    {
        if (!strcmp(text,end->data))
        {
            cout << "s-a gasit cuvant"<<endl;
            aux = end;
            if (!end->next && !end->prev)
            {
                end = 0;
                delete aux;
            }
            else if (end->prev)
            {
                if (end->next)
                {
                    end->prev->next = end->next;
                    end->next->prev = end->prev;
                    end = end->next;
                    delete aux;
                }
                else
                {
                    end->prev->next = end->next;
                    end = 0;
                    delete aux;
                }
            }
            else
            {
                end->next->prev = 0;
                end = end->next;
                setCap(end);
                delete aux;
            }
        }
        else
        {
            end = end->next;
        }
        flag = true;
    }

    if (!flag)
    {
        throw "Stergerea nu a putut fi efectuata: text negasit";
    }

}

void lista::Replace(char text[], char text2[])
{
    bool flag = false;

    if (!getCap())
    {
        throw "Nu exista text in editor";
    }

    Element* end = getCap();

    while (end)
    {
        if (!strcmp(text, end->data))
        {
            if (end == getCap())
            {
                Element* aux=new Element;
                aux->next = getCap()->next;
                aux->data = new char[strlen(text2) + 1];
                strcpy_s(aux->data, strlen(text2) + 1, text2);
                setCap(aux);
            }
            else
            {
                end->data = new char[strlen(text2) + 1];
                strcpy_s(end->data, strlen(text2) + 1, text2);
            }
            
            flag = true;
        }

        end = end->next;
    }

    if(!flag)
    {
        throw "Inlocuirea nu putut fi efectuata: cuvant negasit";
    }
}

std::vector<int> lista::Find(char text[])
{
    std::vector<int> poz;
    poz.push_back(0);
    int i = 1;

    if (!getCap())
    {
        throw "Nu exista text in editor";
    }

    Element* end = getCap();

    while (end)
    {
        if (!strcmp(text, end->data))
        {
            poz[0]++;
            poz.push_back(i);
        }

        i++;
        end = end->next;
    }

    return poz;
}
