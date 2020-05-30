// Sazwan Ariffin Bin Sa’adan - BI18110029
#ifndef ANIMALSHOW_CPP
#define ANIMALSHOW_CPP
#include "animalShow.h"
#include <iostream>
#include <conio.h>
#include <sstream>
using namespace std;

AnimalShow::AnimalShow()
{
    start = NULL;
}

void AnimalShow::InsertItem(string item)
{
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start;
    start = temp;
}

void AnimalShow::MakeEmpty() //To clear my list
{
    NodeType* temp;
    while(start!=NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void AnimalShow::load(string filename)
{
    MakeEmpty();
    inFile.open(filename.c_str());
    string temp;
    while(getline(inFile, temp))
    {
        InsertItem(temp);
    }
    inFile.close();
}

void AnimalShow::save(string filename)
{
    outFile.open(filename.c_str());
    string temp = "";
    NodeType *ptr = start;
    while(ptr != NULL)
    {
        temp = ptr->data + temp;
        if(ptr->next != NULL)
        {
            temp = '\n' + temp;
        }
        ptr = ptr->next;
    }
    outFile << temp;
    outFile.close();
    delete ptr;
}

//-----------------------------------------------------------TICKET MANAGEMENT-----------------------------------------

void AnimalShow::manageAnimalShow(string filename)
{
	system("cls");

	cout << "1. Edit Animal Show\n"
	     << "2. Display All Available Animal Show\n"
	     << "3. Back\n\n";

	opt = select(opt, 1, 3);

	switch(opt)
	{
		case 1 :
			system ("cls");
			editAnimalShow(filename);
			break;

		case 2 :
			system ("cls");
			displayAnimalShow(filename);
			break;

		case 3 :
			break;

		default:
			cout << "Please enter a valid option!" << endl;
	}
}

void AnimalShow::editAnimalShow(string filename)
{
    load(filename);
    string temp = "";
    int count = 3;

    NodeType *ptr = start;
    while(ptr != NULL)
    {
        temp = to_string(count) + ". " + ptr->data + temp;
        if(ptr->next != NULL)
        {
            temp = '\n' + temp;
        }
        ptr = ptr->next;
        count--;
    }

    	cout << temp << endl;

	cout << "Choose a ticket: ";
	cin >> opt;
	if(opt < 1 || opt > 3)
    {
        cout << "Please enter a valid option!" << endl;
    }
    else
    {
        cout << "\nEnter animal show name & price: ";
        cin.ignore();
        getline(cin, temp);

        ptr = start;
        for(int i=0; i<3-opt; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = temp;
        save(filename);

        cout << "\nPress any key to return to Animal Show Management Menu ...." << endl;
        getch();
        manageAnimalShow(filename);
    }
}

void AnimalShow::displayAnimalShow(string filename)
{
    load(filename);
    string temp = "";
    NodeType *ptr = start;
    while(ptr != NULL)
    {
        temp = ptr->data + temp;
        if(ptr->next != NULL)
        {
            temp = '\n' + temp;
        }
        ptr = ptr->next;
    }
    delete ptr;
	cout << temp << endl;

	cout << "Press any key to return to Animal Show Management Menu ...." << endl;
	getch();
	manageAnimalShow(filename);
}

//--------------------------------------------------------------TICKET BUYING------------------------------------------

void AnimalShow::buyAnimalShow(string filename)
{
    load(filename);
    cout << "Please enter how many tickets you want to buy for the show of your choice: \n\n" << endl;

	cout << "Wings of Wonder (Bird Show) @ 1130AM: ";
	cin >> birdshow;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Wings of Wonder (Bird Show) @ 1130AM: ";
        cin >> birdshow;
	}

	cout << "Sea Lion Splash @ 8AM: ";
	cin >> sealionshow;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Sea Lion Splash @ 8AM: ";
        cin >> sealionshow;
	}

	cout << "The Utan Show @ 10AM: ";
	cin >> utanshow;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "The Utan Show @ 10AM: ";
        cin >> utanshow;
	}

    stringstream ss;
    ss << birdshow << "-" << sealionshow << "-" << utanshow;
    InsertItem(ss.str());

	save(filename);
}
#endif
