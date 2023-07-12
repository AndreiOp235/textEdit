#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "loading.h"
#include "lista.h"
#include "text.h"
#include "stiva.h"

//using namespace std;
using std::cin;
using std::cout;
using std::strcpy;
using std::getline;
using std::string;
using std::vector;
using std::endl;
using std::to_string;


int main()
{
	loading();
	int opt = meniu();
	lista cuvinte, goale;

	stiva* undo = new stiva;
	stiva* redo = new stiva;

	char blank;
	while (opt != 11)
	{
		switch (opt)
		{
		case 1:
		{
			cout << "INSERT(text) adauga textul. Scrieti textul ce se doreste a fi introdus urmat de ENTER." << endl;
			string s_buff;
			blank=getchar(); //debounce ultimul ENTER
			getline(cin, s_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c_buff = new char[s_buff.length() + 1];
			char* c_copie = new char[s_buff.length() + 1];
			strcpy_s(c_buff, s_buff.length() + 1, s_buff.c_str());
			strcpy_s(c_copie, s_buff.length() + 1, c_buff);
			
			operatie* op = new operatie;
			op->ID_op = 1;
			op->arg1 = c_copie;
			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			cuvinte.Insert(c_buff);

			final();
			break;
		}

		case 2:
		{
			cout << "INSERT(text, pos) adauga textul incepand cu pozitia pos(numerotarea incepe de la 1). Scrieti textul ce se doreste a fi introdus urmat de ENTER, dupa pozitia si iar ENTER." << endl;
			string s_buff;
			blank = getchar(); //debounce ultimul ENTER
			getline(cin, s_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c_buff = new char[s_buff.length() + 1];
			char* c_copie = new char[s_buff.length() + 1];
			strcpy_s(c_buff, s_buff.length() + 1, s_buff.c_str());
			strcpy_s(c_copie, s_buff.length() + 1, c_buff);

			//blank = getchar();
			int poz = int_safeRead();

			while (poz <= 0)
			{
				cout << "Pozitie incorecta, mai incercati" << endl;
				poz = int_safeRead();
			}

			string pars = to_string(poz);
			char* poz_buff = new char[pars.length() + 1];
			strcpy_s(poz_buff, pars.length() + 1, pars.c_str());

			operatie* op = new operatie;
			op->ID_op = 2;
			op->arg1 = c_copie;
			op->arg2 = poz_buff;
			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			try
			{
				cuvinte.Insert(c_buff, poz);
			}
			catch (const char* e)
			{
				cout << e<<endl;
			}

			final();
			break;
		}
		case 3:
		{
			cout << "DELETE(k, pos) sterge k cuvinte incepand cu pozitia pos(numerotarea incepe de la 1). Scrieti numarul de cuvinte ce se doreste sters urmat de ENTER, dupa pozitia si iar ENTER." << endl;

			//blank = getchar();
			int k= int_safeRead();

			while (k < 1)
			{
				cout << "Numar incorect, mai incercati" << endl;
				k = int_safeRead();
			}

			int poz = int_safeRead();

			while (poz <= 0)
			{
				cout << "Pozitie incorecta, mai incercati" << endl;
				poz = int_safeRead();
			}

			string pars = to_string(poz);
			char* poz_buff = new char[pars.length() + 1];
			strcpy_s(poz_buff, pars.length() + 1, pars.c_str());

			string pars_k = to_string(k);
			char* k_buff = new char[pars_k.length() + 1];
			strcpy_s(k_buff, pars_k.length() + 1, pars_k.c_str());

			operatie* op = new operatie;
			op->ID_op = 2;
			op->arg1 = k_buff;
			op->arg2 = poz_buff;
			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			try
			{
				cuvinte.Delete(k,poz);
			}
			catch (const char* e)
			{
				cout << e << endl;
			}

			final();
			break;
		}
		case 4:
		{
			cout << "DELETE_all(word) sterge toate aparitiile unui cuvant. Cuvantul se va introduce si dupa ENTER" << endl;
			string s_buff;
			blank = getchar(); //debounce ultimul ENTER
			getline(cin, s_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c_buff = new char[s_buff.length() + 1];
			char* c_copie = new char[s_buff.length() + 1];
			strcpy_s(c_buff, s_buff.length() + 1, s_buff.c_str());
			strcpy_s(c_copie, s_buff.length() + 1, c_buff);

			operatie* op = new operatie;
			op->ID_op = 4;
			op->arg1 = c_copie;

			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			try
			{
				cuvinte.Delete_All(c_buff);
				//op arg2 ar trebui sa primeasca pozitiile de pe care s-a sters
			}
			catch (const char* e)
			{
				cout << e << endl;
			}
			final();

			break;
		}
		case 5:
		{
			cout << "5  DELETE_TEXT() sterge TOATE cuvintele" << endl;

			operatie* op = new operatie;
			op->ID_op = 5; 
			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			try
			{
				cuvinte.Delete();
			}
			catch (const char* e)
			{
				cout << e << endl;
			}

			final();
			break;
		}
		case 6:
		{
			cout << "FIND(word) cauta un cuvant si returneaza poziitiile si numarul de cuvinte. Cuvantul se va introduce si dupa ENTER" << endl;
			string s_buff;
			blank = getchar(); //debounce ultimul ENTER
			getline(cin, s_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c_buff = new char[s_buff.length() + 1];
			strcpy_s(c_buff, s_buff.length() + 1, s_buff.c_str());

			try
			{
				std::vector<int> poz=cuvinte.Find(c_buff);
				cout << "S-au gasit " << poz[0] << " instante ale cuvantului " << c_buff<<" pe pozitiile" << endl;

				for (int i = 1; i < poz.size(); i++)
					cout << poz[i] << " ";
				cout << endl;
			}
			catch (const char* e)
			{
				cout << e << endl;
			}

			final();
			break;
		}
		case 7:
		{
			cout << "REPLACE(word1, word2) inlocuieste word1 cu word2. Se va introduce primul cuvant, ENTER, cuvantul ce il va inlocui si ENTER." << endl;
			string s_buff;
			blank = getchar(); //debounce ultimul ENTER
			getline(cin, s_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c_buff = new char[s_buff.length() + 1];
			char* c_copie = new char[s_buff.length() + 1];
			strcpy_s(c_buff, s_buff.length() + 1, s_buff.c_str());
			strcpy_s(c_copie, s_buff.length() + 1, c_buff);

			string s2_buff;
			getline(cin, s2_buff); // permite inserarea unui numar de caractere fara a stii initial lungimea sa
			char* c2_buff = new char[s2_buff.length() + 1];
			char* c2_copie = new char[s2_buff.length() + 1];
			strcpy_s(c2_buff, s2_buff.length() + 1, s2_buff.c_str());
			strcpy_s(c2_copie, s2_buff.length() + 1, c2_buff);

			operatie* op = new operatie;
			op->ID_op = 7;
			op->arg1 = c_copie;
			op->arg2 = c2_copie;
			undo->Push(op);

			while (!redo->isEmpty()) //nu mai are sens sa tinem minte viitorul
			{
				redo->pop();
			}

			try
			{
				cuvinte.Replace(c_buff,c2_buff);
				//op arg3 ar trebui sa primeasca pozitiile de pe care s-a sters
			}
			catch (const char* e)
			{
				cout << e << endl;
			}

			break;
			final();
		}
		case 8:
		{
			try
			{
				cuvinte.Display();
				cout << endl;
			}
			catch (const char* e)
			{
				cout <<e<< endl;
			}

			final();
			break;
		}
		
		case 9:
		{
			try
			{
				if (!undo->isEmpty())
				{
					redo->Push(undo->TOP());
					s_atom aux = undo->TOP();
					cout << "Anulam operatia cu numarul " << aux->ID_op<<endl;

					if (aux->arg1)
					{
						cout << "De argumente " << aux->arg1<<endl;
					}

					if (aux->arg2)
					{
						cout << aux->arg2 << endl;
					}
				}
					

				undo->pop(); // pentru a prinde eroarea
			}
			catch (const char* e)
			{
				cout << e <<" UNDO nu a putut fi efectuata: nu exista operatii anterioare." << endl;
			}

			final();
			break;
		}
		case 10:
		{
			try
			{
				if (!redo->isEmpty())
				{
					undo->Push(redo->TOP());

					s_atom aux = redo->TOP();
					cout << "Anulam operatia cu numarul " << aux->ID_op << endl;

					if (aux->arg1)
					{
						cout << "De argumente " <<endl<< aux->arg1 << endl;
					}

					if (aux->arg2)
					{
						cout << aux->arg2 << endl;
					}
				}

				redo->pop();  // pentru a prinde eroarea
				cout << endl;
			}
			catch (const char* e)
			{
				cout << e << " REDO nu a putut fi efectuata: nu exista operatii viitoare." << endl;
			}

			final();
			break;
		}
		default:
			break;
		}

		opt = meniu();

	}

	return 0;
}