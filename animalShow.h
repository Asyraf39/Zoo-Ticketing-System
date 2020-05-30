// Sazwan Ariffin Bin Sa’adan - BI18110029
#ifndef ANIMALSHOW_H
#define ANIMALSHOW_H
#include <iostream>
#include <fstream>
#include "NodeType.h"
using namespace std;

extern int select(int &choice, int start, int end);

class AnimalShow
{
	private :

		int opt;
		int birdshow;
		int sealionshow;
		int utanshow;
		ofstream outFile; // to write
		ifstream inFile; // to read
		NodeType *start;

    public :
    	AnimalShow();
    	void InsertItem(string item);
    	void MakeEmpty();
    	void load(string filename);
    	void save(string filename);
    	void manageAnimalShow(string filename);
    	void editAnimalShow(string filename);
    	void displayAnimalShow(string filename);
    	void buyAnimalShow(string filename);


};
#endif
