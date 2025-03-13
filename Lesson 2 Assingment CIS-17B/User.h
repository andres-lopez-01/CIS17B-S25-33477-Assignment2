#pragma once
#include <string>
#include <vector>
using namespace std;
class User {
private:
	string name;
	int userID;
	string type;
	vector<string> borrowedBooks;

public:
	User(string, string);

	string getName() const; // returns the name

	int getUserID() const;//retruns the User ID

	vector<string> getBorrowedBooks() const; // returns the liost of borrowed books
};