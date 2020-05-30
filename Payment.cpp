// NUR SYAZWANI IZWANA BINTI MARUNDA(BI18110098)
#ifndef PAYMENT_CPP
#define PAYMENT_CPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Payment.h"
using namespace std;

Payment::Payment(string record, string ticket)
{
	adultTicket = 0;
	childrenTicket = 0;
	seniorTicket = 0;
	animalTicket = 0;
	animalFood = 0;

	totalAdult = 0;
	totalChildren = 0;
	totalSeniorCitizen = 0;

	totalWOW = 0;
	totalSLS = 0;
	totalTUS = 0;

	totalGiraffe = 0;
	totalMonkey = 0;
	totalElephant = 0;
	totalOstrich = 0;

	start = NULL;

	Load(record, ticket);
	totalSale = adultTicket + childrenTicket + seniorTicket + animalTicket + animalFood;
}

void Payment::Load(string record, string ticket)
{
	ifstream file;
	string temp;

    file.open(record.c_str());
	while(getline(file, temp)){
		InsertItem(temp);
	}

	NodeType *ptr = start;
    stringstream ss(ptr->data);
    getline(ss, temp, '-');
    totalAdult += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalChildren += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalSeniorCitizen += atoi(temp.c_str());

	file.close();
	MakeEmpty();

    file.open(ticket.c_str());
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	seniorTicket += totalSeniorCitizen * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	childrenTicket += totalChildren * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	adultTicket += totalAdult * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());

	file.close();
	MakeEmpty();

    file.open("AnimalShowBuy.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	ss.clear();
    ss.str(ptr->data);
    getline(ss, temp, '-');
    totalWOW += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalSLS += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalTUS += atoi(temp.c_str());

	file.close();
	MakeEmpty();

    file.open("AnimalShowPrice.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	animalTicket += totalTUS * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	animalTicket += totalSLS * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	animalTicket += totalWOW * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());

	file.close();
	MakeEmpty();

    file.open("AnimalFoodBuy.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	ss.clear();
    ss.str(ptr->data);
    getline(ss, temp, '-');
    totalGiraffe += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalMonkey += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalElephant += atoi(temp.c_str());
    getline(ss, temp, '-');
    totalOstrich += atoi(temp.c_str());

	file.close();
	MakeEmpty();

    file.open("AnimalFoodPrice.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	animalFood += totalOstrich * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	animalFood += totalElephant * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	animalFood += totalMonkey * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	animalFood += totalGiraffe * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());

	file.close();
	MakeEmpty();
}

void Payment::InsertItem(string item)
{
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start;
    start = temp;
}

void Payment::MakeEmpty() //To clear my list
{
    NodeType* temp;
    while(start!=NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void Payment::displayReceipt()
{
	cout << "--------------------------------" << endl;
    cout << "Adult Ticket: RM" << adultTicket << "\n"
		 << "Children Ticket: RM" << childrenTicket << "\n"
		 << "Senior Citizen: RM" << seniorTicket << "\n"
		 << "Animal Show Ticket: RM" << animalTicket << "\n"
		 << "Animal Food: RM" << animalFood << "\n";

	cout << "Total Sale: RM" << totalSale << "\n";
	cout << "--------------------------------" << endl << endl;
	system("pause");
}
#endif
