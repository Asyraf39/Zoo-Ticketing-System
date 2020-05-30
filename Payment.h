// NUR SYAZWANI IZWANA BINTI MARUNDA(BI18110098)
#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include "NodeType.h"
using namespace std;

class Payment
{
	private:
		int totalAdult;
		int totalChildren;
		int totalSeniorCitizen;

        int totalWOW;
        int totalSLS;
        int totalTUS;

        int totalGiraffe;
        int totalMonkey;
        int totalElephant;
        int totalOstrich;

		int adultTicket;
		int childrenTicket;
		int seniorTicket;
		int totalSale;


		int animalTicket;
		int animalFood ;
		NodeType *start;



	public:

		Payment(string record, string ticket);
		void Load(string record, string ticket);
		void displayReceipt();
		void InsertItem(string item);
		void MakeEmpty();
};
#endif
