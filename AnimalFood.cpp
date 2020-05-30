// SALLYESTECA AVILA JAMES (BI17110061)
#ifndef ANIMALFOOD_CPP
#define ANIMALFOOD_CPP
#include "AnimalFood.h"
#include <iostream>
#include <conio.h>
#include <sstream>
using namespace std;

AnimalFood::AnimalFood()
{
    start = NULL;
}

void AnimalFood::InsertItem(string item)
{
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start;
    start = temp;
}

void AnimalFood::MakeEmpty() //To clear my list
{
    NodeType* temp;
    while(start!=NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void AnimalFood::load(string filename)
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

void AnimalFood::save(string filename)
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

void AnimalFood::manageAnimalFood(string filename)
{
	system("cls");

	cout << "1. Edit Animal Food\n"
	     << "2. Display All Available Animal Food\n"
	     << "3. Back\n\n";

	opt = select(opt, 1, 3);

	switch(opt)
	{
		case 1 :
			system ("cls");
			editAnimalFood(filename);
			break;

		case 2 :
			system ("cls");
			displayAnimalFood(filename);
			break;

		case 3 :
			break;

		default:
			cout << "Please enter a valid option!" << endl;
	}
}

void AnimalFood::editAnimalFood(string filename)
{
    load(filename);
    string temp = "";
    int count = 4;

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
	if(opt < 1 || opt > 4)
    {
        cout << "Please enter a valid option!" << endl;
    }
    else
    {
        cout << "\nEnter ticket name & price: ";
        cin.ignore();
        getline(cin, temp);

        ptr = start;
        for(int i=0; i<4-opt; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = temp;
        save(filename);

        cout << "\nPress any key to return to Animal Food Management Menu ...." << endl;
        getch();
        manageAnimalFood(filename);
    }
}

void AnimalFood::displayAnimalFood(string filename)
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

	cout << "Press any key to return to Animal Food Management Menu ...." << endl;
	getch();
	manageAnimalFood(filename);
}

//--------------------------------------------------------------TICKET BUYING------------------------------------------

void AnimalFood::buyAnimalFood(string filename)
{
    load(filename);
    cout << "Please enter how many unit of food you want to buy for the animal of your choice: " << endl;

	cout << "Giraffe : ";
	cin >> giraffe;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Giraffe : ";
        cin >> giraffe;
	}

	cout << "Ostrich : ";
	cin >> ostrich;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Ostrich : ";
        cin >> ostrich;
	}

	cout << "Monkey : ";
	cin >> monkey;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Monkey : ";
        cin >> monkey;
	}

	cout << "Elephant : ";
	cin >> elephant;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Elephant : ";
        cin >> elephant;
	}


    stringstream ss;
    ss << giraffe << "-" << ostrich << "-" << monkey << "-" << elephant;
    InsertItem(ss.str());

	save(filename);

}
#endif
