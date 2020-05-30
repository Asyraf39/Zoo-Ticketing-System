// NUR HANI BINTI ABD HALIL (BI18110114)
#ifndef REPORT_CPP
#define REPORT_CPP
#include "Report.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

Report::Report() {
	totalAdultM = 0;
	totalChildrenM = 0;
	totalSeniorCitizenM = 0;

	totalAdultF = 0;
	totalChildrenF = 0;
	totalSeniorCitizenF = 0;

	totalWOW = 0;
	totalSLS = 0;
	totalTUS = 0;

	totalGiraffe = 0;
	totalMonkey = 0;
	totalElephant = 0;
	totalOstrich = 0;

	// msia + foreigner
	adultTicket = 0;
	childrenTicket = 0;
	seniorTicket = 0;

	animalTicket = 0;
	animalFood = 0;
	start = NULL;

	load();
	totalSale = adultTicket + childrenTicket + seniorTicket + animalTicket + animalFood;
}

void Report::InsertItem(string item)
{
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start;
    start = temp;
}

void Report::MakeEmpty() //To clear my list
{
    NodeType* temp;
    while(start!=NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void Report::displayVisitor()
{
	cout << "-------------------------------------------------------\n";

	cout << "VISITORS REPORT FOR TODAY. CATEGORY: MALAYSIAN" << endl;

	cout << "-------------------------------------------------------\n";

	cout << "Adult: " << totalAdultM << "\n"
		 << "Children: " << totalChildrenM << "\n"
		 << "Senior Citizen: " << totalSeniorCitizenM << "\n";

	cout << "-------------------------------------------------------\n";

	cout << "VISITORS REPORT FOR TODAY. CATEGORY: FOREIGNER" << endl;

	cout << "-------------------------------------------------------\n";

	cout << "Adult: " << totalAdultF << "\n"
		 << "Children: " << totalChildrenF << "\n"
		 << "Senior Citizen: " << totalSeniorCitizenF << "\n";

	cout << "-------------------------------------------------------\n";
}

void Report::displaySale()
{

	cout << "TOTAL SALE FOR TODAY." << endl;

	cout << "-------------------------------------------------------\n";

	cout << "Adult Ticket: RM" << adultTicket << "\n"
		 << "Children Ticket: RM" << childrenTicket << "\n"
		 << "Senior Citizen: RM" << seniorTicket << "\n"
		 << "Animal Show Ticket: RM" << animalTicket << "\n"
		 << "Animal Food: RM" << animalFood << "\n";

	cout << "Total Sale: RM" << totalSale << "\n";
	cout << "-------------------------------------------------------\n" << endl << endl;
	system("pause");
}

void Report::load()
{
	ifstream file;
	string temp;

	file.open("recordMalaysian.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	NodeType *ptr = start;
	while(ptr != NULL) {
		stringstream ss(ptr->data);
		getline(ss, temp, '-');
		totalAdultM += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalChildrenM += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalSeniorCitizenM += atoi(temp.c_str());
        ptr = ptr->next;
	}

	file.close();
	MakeEmpty();

	file.open("recordForeigner.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	while(ptr != NULL) {
		stringstream ss(ptr->data);
		getline(ss, temp, '-');
		totalAdultF += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalChildrenF += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalSeniorCitizenF += atoi(temp.c_str());
        ptr = ptr->next;
	}

	file.close();
	MakeEmpty();

	file.open("ticketMalaysian.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	seniorTicket += totalSeniorCitizenM * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	childrenTicket += totalChildrenM * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	adultTicket += totalAdultM * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());

	file.close();
	MakeEmpty();

	file.open("ticketForeigner.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	seniorTicket += totalSeniorCitizenF * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	childrenTicket += totalChildrenF * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());
    ptr = ptr->next;
	adultTicket += totalAdultF * atoi((ptr->data).substr((ptr->data).find('-') + 3).c_str());

	file.close();
	MakeEmpty();

	file.open("AnimalShowBuy.txt");
	while(getline(file, temp)){
		InsertItem(temp);
	}

	ptr = start;
	while(ptr != NULL) {
		stringstream ss(ptr->data);
		getline(ss, temp, '-');
		totalWOW += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalSLS += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalTUS += atoi(temp.c_str());
        ptr = ptr->next;
	}

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
	while(ptr != NULL) {
		stringstream ss(ptr->data);
		getline(ss, temp, '-');
		totalGiraffe += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalMonkey += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalElephant += atoi(temp.c_str());
		getline(ss, temp, '-');
		totalOstrich += atoi(temp.c_str());
        ptr = ptr->next;
	}

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
#endif
