#include "Book.h"

Book::Book() {//default constructor
	title = " ";
	author = " ";
	ISBN = -1;
	availability = true;
}
Book::Book(string title, string author, int ISBN) { //Constructor
	this->title = title;
	this->author = author;
	this->ISBN = ISBN;
}

string Book::getTitle() const{
	return title;
}

string Book::getAuthor() const{
	return author;
}

int Book::getISBN() const{
	return ISBN;
}

bool Book::getAvailability() const{
	return availability;
}