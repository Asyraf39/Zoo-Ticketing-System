// Muhammad Asyraf Aiman bin Roslan - BI18110014
#ifndef ADMIN_CPP
#define ADMIN_CPP
#include "Admin.h"
#include "Entrance.cpp"
#include "Report.cpp"
#include "AnimalFood.cpp"
#include "animalShow.cpp"
#include <iostream>
#include <ctime>		// used for get date and time information
#include <fstream>		// used for file operations
using namespace std;

Admin::Admin() {	// constructor
	username = "";
	password = "";
	verified = false;
	successLogin = "";
	failLogin = "";
	loginDetail = "Admin.txt";
	encryptKey = 3539;
	// initialise linked list
	head = NULL;
	for(int i=0; i<4; i++) {
	    NodeType* temp = new NodeType;
	    temp->next = head;
	    head = temp;
	}
}

Admin::~Admin() {	// destructor
    // delete linked list
    NodeType* temp;
    while(head!=NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool Admin::verify(string name, string pass) {	// verify the entered details
	load(); // load from file

	if(username == name && password == pass) {	// if correct details
		verified =  true;   // user is verified
	}
	else {	// if incorrect details
		verified = false;   // user is not verified
	}

    return isVerified();    // return verification result
}

bool Admin::isVerified() {	// check if the user is verified
	return verified;    // return verified status
}

void Admin::setUsername() {	// set the new admin username
	// prompt user for password
	cout << "Enter password: ";
	cin >> this->password;

	if(verify(this->username, this->password) == true) {	// if user is verified
		// prompt user for username
		cout << "Enter new username: ";
		cin >> this->username;

		save(); // save new username
		cout << endl << "Username successfully changed" << endl;    // inform user
	}
	else {	// if user is not verified
		// inform user
		cout << endl << "Wrong password!" << endl;
		cout << "You will be immediately logged out!" << endl;
	}
}

void Admin::setPassword() {	// set the new admin password
	// prompt user for current password
	cout << "Enter current password: ";
	cin >> this->password;

	if(verify(this->username, this->password) == true) {	// if user is verified
        system("cls");  // clear screen
        string temp;    // variable declaration

        while(temp != this->password) {
            // prompt user for new password
            cout << "Enter new password: ";
            cin >> this->password;

            // prompt user to confirm password
            cout << "Confirm password : ";
            cin >> temp;

            if(temp != this->password) {    //if different password
                cout << endl << "Password is different! Please try again" << endl;  // inform user
                system("pause");    // wait for user
                system("cls");  // clear screen
            }
        }

		save(); // save new password
		cout << endl << "Password successfully changed" << endl;    // inform user
	}
	else {	// if user is not verified
		// inform user
		cout << endl << "Wrong password!" << endl;
		cout << "You will be immediately logged out!" << endl;
	}
}

void Admin::loginActivity() {	// show previous login activity
	// print last login time
    cout << "Last successful login: " << successLogin << endl;
    cout << "Last failed login: " << failLogin << endl;
}

void Admin::login() {	// login to the system
	string username, password, choice;  // variable declaration

	// check if file exists
	ifstream exist(loginDetail.c_str());
	if(!exist) {
		// inform user
		cout << "File does not exist!" << endl;
		cout << "Please contact the administrator to solve this issue!" << endl;

		system("pause");    // wait for user
		return;     // exit function
	}

	do {    // attempt login
		choice = "";    // clear user choice

		// prompt user for username and password
		cout << "Enter username: ";
		cin >> this->username;
		cout << "Enter password: ";
		cin >> this->password;

		time_t now = time(0);   // save current time

		if(verify(this->username, this->password) == true) {	// if user is verified
			// save current time to file
		    successLogin = ctime(&now);
		    successLogin.erase(successLogin.end()-1);
		    save();

		    // inform and wait for user
			cout << "\nLogin successful" << endl;
			system("pause");
		}
		else {	// if user is not verified
			// save current time to file
		    failLogin = ctime(&now);
		    failLogin.erase(failLogin.end()-1);
		    save();

		    // prompt user to try again
			cout << "Wrong username or password!" << endl;
			cout << "Try again? Y or N: ";
			cin >> choice;

			// input validation
			while(choice != "Y" && choice != "y" && choice != "N" && choice != "n")  {
				cout << "Invalid input!" << endl;
				cout << "Try again? Y or N: ";
				cin >> choice;
			}

			system("cls");  // clear screen
		}
	}
	while(choice == "Y" || choice == "y");  // retry login
}

void Admin::logout() {	// logout from the system
    verified = false;   // unverify user
    cout << "Logout successful" << endl;    // inform user
}

string Admin::encrypt(string input) {	// encrypt string
	// encrypt each character
	for(unsigned i=0; i<input.length(); i++) {
		input[i] += encryptKey;
	}

	return input;   // return encrypted string
}

string Admin::decrypt(string input) {	// decrypt string
	// decrypt each character
	for(unsigned i=0; i<input.length(); i++) {
		input[i] -= encryptKey;
	}

	return input;   // return decrypted string
}

void Admin::load() {	// load from file
	in.open(loginDetail.c_str());   // open file

	// load from file line by line
    NodeType* temp = head;
    while(temp != NULL) {
        getline(in, temp->data);
        temp = temp->next;
    }
    temp = head;

	// decrypt username and password
	username = decrypt(temp->data);
    temp = temp->next;
	password = decrypt(temp->data);
    temp = temp->next;

	// get last login time
	successLogin = temp->data;
    temp = temp->next;
	failLogin = temp->data;
    temp = temp->next;

	in.close();     // close file
	delete temp;
}

void Admin::save() {	// save to file
	out.open(loginDetail.c_str());  // open file
	NodeType *temp = head;

	// save encrypted username and password
	temp->data = encrypt(username);
    temp = temp->next;
	temp->data = encrypt(password);
    temp = temp->next;

	// save last login time
	temp->data = successLogin;
    temp = temp->next;
	temp->data = failLogin;
    temp = temp->next;

	// save to file line by line
    temp = head;
    while(temp != NULL) {
        out << temp->data << endl;
        temp = temp->next;
    }

	out.close();    // close file
	delete temp;
}

void Admin::showMenu() {	// show menu for admin
	// variable to store choice
	int choice;
	// start login attempt
    login();

    // show menu while user is verified
    while(isVerified()) {
    	// clear screen
    	system("cls");

    	Entrance e;
    	Report r;
    	AnimalFood AF;
    	AnimalShow AS;

    	// show login activity
    	loginActivity();
    	cout << endl;

    	// menu options
    	cout << "1. Manage ticket - Local" << endl;
    	cout << "2. Manage ticket - Foreigner" << endl;
    	cout << "3. Manage animal show" << endl;
    	cout << "4. Manage animal food" << endl;
    	cout << "5. Show report" << endl;
	    cout << "6. Change username" << endl;
	    cout << "7. Change password" << endl;
	    cout << "8. Logout" << endl;

	    // get user choice
	    choice = select(choice, 1, 8);
	    // clear screen
	    system("cls");

	    // actions based on choice
	    switch(choice) {
	        case 1:
	            e.manageTicket("ticketMalaysian.txt");
	            break;
            case 2:
	            e.manageTicket("ticketForeigner.txt");
                break;
            case 3:
                AS.manageAnimalShow("AnimalShowPrice.txt");
                break;
            case 4:
                AF.manageAnimalFood("AnimalFoodPrice.txt");
                break;
            case 5:
                r.displayVisitor();
                r.displaySale();
                break;
	    	case 6:
	    		// set new username
	    		setUsername();
                // wait for user
                system("pause");
	    		break;
	    	case 7:
	    		// set new password
	    		setPassword();
                // wait for user
                system("pause");
	    		break;
	    	case 8:
	    		// log out
				logout();
				cout << endl;
                // wait for user
                system("pause");
	    		break;
	    	default:
	    		break;
		}
	}
}
#endif

