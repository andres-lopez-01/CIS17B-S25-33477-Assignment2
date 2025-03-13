#pragma once
#include "Book.h"
#include "User.h"
#include <iostream>

using namespace std;

class Library {
private:
	static Library* instance;
	vector<Book> books;
	vector<User*> users;

    Library() {} // private constructor

public:
    static Library* getInstance();

    //add Book
    void addBook(const Book& book);

    //add User
    void addUser(User* user);

    //return Book
    Book* findBookByTitle(const string& title);

    //return user
    User* findUserByID(int userID);

    // List all books
    void listAllBooks();

    // List all users
    void listAllUsers();
    //borrow book
    void borrowBook(int userID, int isbn);
    //return book
    void returnBook(int userID, int isbn);
};