🚀 Address Book Management System
A menu-driven contact management application written in C, demonstrating structured programming, modular design, and file-based data persistence.

🧠 Overview
The Address Book Management System is a console-based application that allows users to efficiently manage contacts through a simple and interactive menu interface. The project is designed using modular programming principles, where each functionality is separated into different source files, making the code clean, scalable, and easy to maintain.

⚙️ Functionalities
The application provides the following operations:

Add Contact
Edit Contact
Search Contact
Delete Contact
List Contacts
Save & Exit
Exit
🔍 Feature Details
Add Contact → Create and store new contact details
Edit Contact → Modify existing contact information
Search Contact → Find contacts using name or phone number
Delete Contact → Remove a contact from the system
List Contacts → Display all stored contacts
Save & Exit → Save data to file (contact.txt) and exit
Exit → Exit the program without saving
🏗️ Project Structure
Address_Book/
│── main.c # Menu and program flow
│── contact.c # Contact operations (Add, Edit, Delete, etc.)
│── populate.c # Initialization logic
│── contact.h # Structure & function declarations
│── populate.h
│── contact.txt # Data storage file
│── README.md # Documentation

🔄 Program Flow
Start Program
↓
Initialize Address Book
↓
Display Menu
↓
User selects option (1–7)
↓
Perform operation
↓
Repeat until Exit

🧩 Concepts Used
Structures (struct AddressBook)
File Handling (fopen, fwrite, fread)
Modular Programming
Switch-case logic
String manipulation
🔄 How It Works
Program starts and initializes the address book
User is shown a menu with available operations
Based on user input, corresponding function is executed:
Add → stores new contact
Edit → modifies existing contact
Search → retrieves contact details
Delete → removes contact
Data is stored in a file (contact.txt)
On selecting "Save & Exit", all data is written to file
▶️ How to Run
gcc main.c contact.c populate.c -o address_book
./address_book
