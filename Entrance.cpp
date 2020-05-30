// ERICA EKING (BI18110015)
#ifndef ENTRANCE_CPP
#define ENTRANCE_CPP
#include "Entrance.h"
#include "Admin.cpp"
#include "Payment.cpp"
#include "AnimalFood.cpp"
#include "animalShow.cpp"
#include <iostream>
#include <conio.h>
#include <sstream>
using namespace std;

Entrance::Entrance()
{
    start = NULL;
}

void Entrance::InsertItem(string item)
{
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start;
    start = temp;
}

void Entrance::MakeEmpty() //To clear my list
{
    NodeType* temp;
    while(start!=NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void Entrance::load(string filename)
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

void Entrance::save(string filename)
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

void Entrance::Intro()
{
	system ("cls");

	cout << "WELCOME TO ZOONILAND!\n" << endl;

	cout << "1. Local\n"
		 << "2. Foreigner\n"
		 << "3. Admin Login\n"
		 <<	"4. EXIT\n\n";

	opt = select(opt, 1, 4);

	Admin admin;
	switch(opt)
	{
		case 1 :
			system("cls");
			Menu("recordMalaysian.txt","ticketMalaysian.txt");
			break;

		case 2 :
			system("cls");
			Menu("recordForeigner.txt","ticketForeigner.txt");
			break;

		case 3 :
		    system("cls");
			admin.showMenu();
			Intro();
			break;

		case 4 :
			break;

		default:
			cout << "Please enter a valid option!" << endl;
			Intro();
	}
}

void Entrance::Menu(string record, string ticket)
{
	system("cls");

    Payment p(record, ticket);
    AnimalFood AF;
    AnimalShow AS;

	cout << "1. Buy Entrance Ticket\n"
	     << "2. Buy Animal Show Ticket\n"
	     << "3. Buy Animal Food\n"
	     << "4. Print Receipt\n"
	     << "5. Back\n\n";

    opt = select(opt, 1,5);

	switch(opt)
	{
		case 1:
			system("cls");
			buyTicket(record);
			Menu(record, ticket);
			break;

		case 2:
			system("cls");
			AS.buyAnimalShow("AnimalShowBuy.txt");
			Menu(record, ticket);
			break;

		case 3:
			system("cls");
			AF.buyAnimalFood("AnimalFoodBuy.txt");
			Menu(record, ticket);
			break;

		case 4:
			system("cls");
			p.displayReceipt();
			Menu(record, ticket);
			break;

		case 5:
			system("cls");
			Intro();
			break;

		default:
			cout << "Please enter a valid option!" << endl;
			Intro();

	}
}

void Entrance::AdminMenu()
{
	system("cls");

	cout << "1. Malaysian\n"
		 << "2. Foreigner\n"
		 << "3. Back\n\n"

	<< "Choose a category: ";
	cin >> opt;

			switch (opt)
			{
				case 1 :
					system ("cls");
					manageTicket("ticketMalaysian.txt");
					break;

				case 2 :
					system ("cls");
					manageTicket("ticketForeigner.txt");
					break;

				case 3 :
					system("cls");
					Intro();
					break;

				default :
					cout << "Please enter a valid option!" << endl;
					AdminMenu();
					break;
			}
}

//-----------------------------------------------------------TICKET MANAGEMENT-----------------------------------------

void Entrance::manageTicket(string filename)
{
	system("cls");

	cout << "1. Edit Ticket\n"
	     << "2. Display All Tickets\n"
	     << "3. Back\n\n";

    opt = select(opt, 1, 3);

	switch(opt)
	{
		case 1 :
			system ("cls");
			editTicket(filename);
			break;

		case 2 :
			system ("cls");
			displayTicket(filename);
			break;

		case 3 :
			break;

		default:
			cout << "Please enter a valid option!" << endl;
	}
}

void Entrance::editTicket(string filename)
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
        cout << "\nEnter ticket name & price: ";
        cin.ignore();
        getline(cin, temp);

        ptr = start;
        for(int i=0; i<3-opt; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = temp;
        save(filename);

        cout << "\nPress any key to return to Ticket Management Menu ...." << endl;
        getch();
        manageTicket(filename);
    }
}

void Entrance::displayTicket(string filename)
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

	cout << "Press any key to return to Ticket Management Menu ...." << endl;
	getch();
	manageTicket(filename);
}

//--------------------------------------------------------------TICKET BUYING------------------------------------------

void Entrance::buyTicket(string filename)
{
    load(filename);
    cout << "Please enter your option: " << endl;

	cout << "Adult = ";
	cin >> adult;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Adult = ";
		cin >> adult;
	}

	cout << "Chilren = ";
	cin >> children;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Chilren = ";
        cin >> children;
	}

	cout << "Senior Citizen = ";
	cin >> sc;
	while(cin.fail()){
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Invalid input! Try again\n";
        cout << "Senior Citizen = ";
        cin >> sc;
	}

    stringstream ss;
    ss << adult << "-" << children << "-" << sc;
    InsertItem(ss.str());

	save(filename);
}
#endif
