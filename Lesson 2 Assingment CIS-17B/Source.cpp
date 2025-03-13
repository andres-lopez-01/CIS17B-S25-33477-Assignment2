#include "Library.h"

Library* Library::instance = nullptr;  // Definition of the static member variable

void displayMenu();       // Displays the main menu
void displayBookMenu();   // Displays the book management submenu
void displayUserMenu();   // Displays the user management submenu

int main() {
    Library* lib = Library::getInstance();
    int choice;

    while (true) {
        displayMenu();  // Show the main menu
        cin >> choice;

        if (choice == 4) break;  // Exit the program

        switch (choice) {
        case 1: {  // Manage Books
            int bookChoice;
            while (true) {
                displayBookMenu();  // Show book management submenu
                cin >> bookChoice;

                if (bookChoice == 3) break;  // Go back to the main menu

                switch (bookChoice) {
                case 1: {  // Add a book
                    string title, author;
                    int isbn = 0;
                    cout << ">> Enter the Title: ";
                    cin.ignore(); getline(cin, title);
                    cout << ">> Enter the Author: "; getline(cin, author);
                    cout << ">> Enter the ISBN (number): "; 
                    cin >> isbn;
                    while (!(cin >> isbn)) {
                        cin.clear(); // Clear error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
                        cout << "Invalid ISBN. Please enter a valid number: ";
                    }
                    lib->addBook(Book(title, author, isbn));
                    break;
                }
                case 2:  // List all books
                    cout << "Books Listed Below:" << endl;
                    lib->listAllBooks();
                    cout << endl << endl;
                    break;
                default:
                    cout << "!! ERROR: Invalid choice.\n";
                }
            }
            break;
        }
        case 2: {  // Manage Users
            int userChoice;
            while (true) {
                displayUserMenu();  // Show user management submenu
                cin >> userChoice;

                if (userChoice == 3) break;  // Go back to the main menu

                switch (userChoice) {
                case 1: {  // Add a user
                    int userType;
                    string name;
                    cout << ">> Enter 1 for Student or 2 for Faculty: ";
                    cin >> userType;
                    if (userType != 1 && userType != 2) {
                        cout << "!! ERROR: Only valid options are 1 or 2\n";
                        break;
                    }
                    cout << ">> Enter name: ";
                    cin.ignore(); getline(cin, name);
                    lib->addUser(new User(name, userType == 1 ? "Student" : "Faculty"));
                    break;
                }
                case 2:  // List users
                    cout << "Users Listed Below:" << endl;
                    lib->listAllUsers();
                    cout << endl << endl;
                    break;
                default:
                    cout << "!! ERROR: Invalid choice.\n";
                }
            }
            break;
        }
        case 3:
            cout << "> Transaction management not implemented yet.\n";
            break;
        default:
            cout << "!! ERROR: Invalid choice.\n";
        }
    }

    cout << "Thank you for using the Library System!" << endl;
    return 0;
}

void displayMenu() {
    cout << "Welcome to the Library: \n1. Manage Books \n2. Manage Users \n3. Manage Transactions \n4. Exit" << endl;
}

void displayBookMenu() {
    cout << "Manage Books:\n1. Add Book\n2. List All Books\n3. Go Back\n";
}

void displayUserMenu() {
    cout << "Manage Users:\n1. Add User\n2. List Users\n3. Go Back\n";
}
