// Muhammad Asyraf Aiman bin Roslan - BI18110014
#ifndef ADMIN_H
#define ADMIN_H
#include "NodeType.h"
#include <iostream>
#include <fstream>		// used for file operations
using namespace std;

extern int select(int &choice, int start, int end);

class Admin {
    private:
        string username;		// admin username
        string password;		// admin password
        bool verified;			// verification of login details
        string successLogin;	// last successful login
        string failLogin;		// last failed login
		string loginDetail;		// stored login detail's location
		int encryptKey;			// encryption key
		ifstream in;			// input file stream
		ofstream out;			// output file stream
		NodeType *head;         // head of linked list

    public:
        Admin();										// constructor
        ~Admin();										// destructor
        bool verify(string name, string pass);			// verify the entered details
        bool isVerified();								// check if the user is verified
		void setUsername();								// set new username
        void setPassword();								// set new password
        void loginActivity();							// show previous login activity
        void login();									// login to the system
        void logout(); 									// logout from the system
        string encrypt(string input);					// encrypt string
        string decrypt(string input);					// decrypt string
        void load();									// load from file
        void save();									// save to file
        void showMenu();								// show menu for admin
};
#endif
