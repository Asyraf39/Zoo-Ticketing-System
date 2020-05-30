// SALLYESTECA AVILA JAMES (BI17110061)
#ifndef ANIMALFOOD_H
#define ANIMALFOOD_H
#include <iostream>
#include <fstream>
#include "NodeType.h"
using namespace std;

extern int select(int &choice, int start, int end);

class AnimalFood
{
	private :

		int opt;
		int giraffe;
		int monkey;
		int elephant;
		int ostrich;
		ofstream outFile; // to write
		ifstream inFile; // to read
		NodeType *start;

    public :
    	AnimalFood();
    	void InsertItem(string item);
    	void MakeEmpty();
    	void load(string filename);
    	void save(string filename);
    	void manageAnimalFood(string filename);
    	void editAnimalFood(string filename);
    	void displayAnimalFood(string filename);
    	void buyAnimalFood(string filename);


};
#endif
