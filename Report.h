// NUR HANI BINTI ABD HALIL (BI18110114)
#ifndef REPORT_H
#define REPORT_H
#include <iostream>
#include <fstream>
#include "NodeType.h"
using namespace std;

class Report
{
	private:
		int totalAdultM;
		int totalChildrenM;
		int totalSeniorCitizenM;

		int totalAdultF;
		int totalChildrenF;
		int totalSeniorCitizenF;

        int totalWOW;
        int totalSLS;
        int totalTUS;

        int totalGiraffe;
        int totalMonkey;
        int totalElephant;
        int totalOstrich;

		// msia + foreigner
		int adultTicket;
		int childrenTicket;
		int seniorTicket;
		int totalSale;

		int animalTicket;
		int animalFood ;
		NodeType *start;

	public:
		Report();
		void displayVisitor();
		void displaySale();
		void load();
		void InsertItem(string item);
		void MakeEmpty();
};
#endif
