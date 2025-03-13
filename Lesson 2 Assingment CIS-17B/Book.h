#pragma once
#include <string>
using namespace std;

class Book{ //Book class
private://private variables
	string title;
	string author;
	int ISBN;
	bool availability;

public: //public  getters and setters
	Book(); //default constructor
	Book(string, string, int); //Constructor

	string getTitle() const;// returns book title

	string getAuthor() const;//returns author name

	int getISBN() const; //gets ISBN

	bool getAvailability() const; //returns true if book is available;
};