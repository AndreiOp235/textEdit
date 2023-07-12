#include <iostream>
#include <windows.h>
#include <stdlib.h>

#include "loading.h"

//using namespace std;
using std::cin;
using std::cout;
using std::strcpy;
using std::string;
using std::endl;

void loading()
{

	std::cout << "##   ##   #####   ######   #######  ######     ##     #####" << endl;
	std::cout << "###  ##  ##   ##  # ## #    ##   #   ##  ##   ####     ## ##" << endl;
	std::cout << "#### ##  ##   ##    ##      ## #     ##  ##  ##  ##    ##  ##" << endl;
	std::cout << "## ####  ##   ##    ##      ####     #####   ##  ##    ##  ##  ######   ######" << endl;
	std::cout << "##  ###  ##   ##    ##      ## #     ##      ######    ##  ##" << endl;
	std::cout << "##   ##  ##   ##    ##      ##   #   ##      ##  ##    ## ##" << endl;
	std::cout << "##   ##   #####    ####    #######  ####     ##  ##   #####" << endl;
	Sleep(1000);
	system("CLS");

}

int meniu()
{
	cout << "NOTEPAD-- v0.0.2" << endl;
	cout << "Meniu instructiuni:" << endl;
	cout << "Introduceti comanda urmata de enter"<<endl;
	cout << "Mai multe intructiuni veti primi la fiecare instructiune in parte" << endl;
	cout << "1  INSERT(text) adauga textul" << endl;
	cout << "2  INSERT(text, poz) adauga text incepand cu pozitia k" << endl;
	cout << "3  DELETE(k, pos) sterge k cuvinte incepand cu pozita p" << endl;
	cout << "4  DELETE_all(word) sterge toate aparitiile unui cuvant" << endl;
	cout << "5  DELETE_TEXT() sterge TOATE cuvintele" << endl;
	cout << "6  FIND(word) cauta un cuvant si returneaza poziitiile si numarul de cuvinte" << endl;
	cout << "7  REPLACE(word1, word2) inlocuieste word1 cu word2" << endl;
	cout << "8  DISPLAY afiseaza textul" << endl;
	cout << "9  UNDO anuleaza ultima actiune" << endl;
	cout << "10 REDO anuleaza ultimul UNDO" << endl;
	cout << "11 EXIT iese din program" << endl;
	cout << "Orice alta optiune va reafisa meniul" << endl;
	
	int opt = int_safeRead();
	system("CLS");
	return opt;

}

int int_safeRead()
{

	int opt;
	cin >> opt;
	if (!cin)
	{
		cin.clear();
		cin.ignore(1000000, '\n'); //ignora caractere ce nu respecta tipul opt
		opt = 0;
	}

	return opt;
}

void final()
{
	cout << "====================================================================================" << endl;
}
