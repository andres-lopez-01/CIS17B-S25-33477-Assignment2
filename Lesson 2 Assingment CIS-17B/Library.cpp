#include "Library.h"

Library* Library::getInstance() {
    if (instance == nullptr) {
        instance = new Library();
    }
    return instance;
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addUser(User* user) {
    users.push_back(user);
}

Book* Library::findBookByTitle(const string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    throw runtime_error("No book with that title exists.");
}

User* Library::findUserByID(int userID) {
    for (auto& user : users) {
        if (user->getUserID() == userID) {
            return user;
        }
    }
    throw runtime_error("No User with that ID exists.");
}

// List all books
void Library::listAllBooks() {
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "Book " << i << ":\n";
        cout << "Title: " << books[i].getTitle() << "\n";
        cout << "Author: " << books[i].getAuthor() << "\n";
        cout << "ISBN: " << books[i].getISBN() << "\n";
        cout << "Available: " << (books[i].getAvailability() ? "Yes" : "No") << "\n";
    }
}

// List all users
void Library::listAllUsers() {
    for (auto& user : users) {
        cout << "User " << user->getUserID() << ":\n";
        cout << "Name: " << user->getName() << "\n";
        cout << "Books Checked Out:\n";
        for (auto& book : user->getBorrowedBooks()) {
            //cout << "" - "" << " TESTTT Book Title!";
            //cout << "   - " << book->getTitle() << "\n";
        }
    }
}

