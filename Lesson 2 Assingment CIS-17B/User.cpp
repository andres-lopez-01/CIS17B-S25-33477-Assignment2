#include "User.h"
#include <random>

User::User(string name, string type) {
	this->name = name;
	this->type = type;
	this->userID = rand() % 9000 + 1000;

}

string User::getName() const {
	return name;
}

int User::getUserID() const {
	return userID;
}

vector<string> User::getBorrowedBooks() const {
		return borrowedBooks;
	}