// ERICA EKING (BI18110015)
#ifndef ENTRANCE_H
#define ENTRANCE_H
#include <iostream>
#include <fstream>
#include "NodeType.h"
using namespace std;

extern int select(int &choice, int start, int end);

class Entrance
{
	private:
		int opt;
		int adult, children, sc;
		ofstream outFile; // to write
		ifstream inFile; // to read
		NodeType *start;

	public:
	    Entrance();
		void Intro();
		void Menu(string record, string ticket);
		void AdminMenu();
		void manageTicket(string filename);
		void editTicket(string filename);
		void displayTicket(string filename);
		void buyTicket(string filename);
        void InsertItem(string item);
        void MakeEmpty();
        void load(string filename);
        void save(string filename);
};
#endif
