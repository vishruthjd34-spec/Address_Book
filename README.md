# 📒 Address Book in C

*A lightweight, menu-driven contact manager for the terminal — with file storage and input validation.*

![Language](https://img.shields.io/badge/language-C-blue?logo=c)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20WSL-lightgrey)
![Storage](https://img.shields.io/badge/storage-text%20file-green)

</div>

---

## 📖 About

This project is a console-based *Address Book* written in C. You can create, search, edit, delete and list contacts from a simple menu. Contacts are saved to a plain text file (contacts.txt) when you exit and loaded automatically the next time you start the program.

It was built to practise core C concepts: *structures, arrays, string handling, file I/O, modular programming (multiple .c/.h files) and input validation*.

---

## ✨ Features

| | Feature | Description |
|---|---------|-------------|
| ➕ | *Create contact* | Add a new contact with name, mobile number and email |
| 🔍 | *Search contact* | Search by name, mobile number or email (partial match works) |
| ✏️ | *Edit contact* | Find a contact, pick it, and update name, mobile or email |
| 🗑️ | *Delete contact* | Search, choose the match, and remove it |
| 📋 | *List contacts* | Shows all contacts in a table, *sorted alphabetically* by name |
| 💾 | *Save & load* | Data is written to contacts.txt on exit and read back on startup |
| ✅ | *Input validation* | Rejects bad names, phone numbers and emails, and blocks duplicates |
| ⏳ | *Loading animation* | Small "Loading....." effect for a nicer feel |

---

## 🛡️ Validation Rules

| Field | Rule |
|-------|------|
| 👤 *Name* | Letters, spaces and . only (no digits or symbols) |
| 📱 *Mobile* | Exactly *10 digits, and must be **unique* |
| 📧 *Email* | Exactly one @, a . after the @, *no capital letters, and must be **unique* |

---

## 📸 Screenshots

> Captured from the real program running in a terminal, using sample data.

### 🏠 Main Menu
![Main menu](screenshots/01_menu.png)

### 📋 List All Contacts
![List contacts](screenshots/02_list.png)

### ➕ Create a Contact
![Create contact](screenshots/03_create.png)

### 🔍 Search a Contact
![Search contact](screenshots/04_search.png)

### 🗑️ Delete a Contact
![Delete contact](screenshots/05_delete.png)

### ✅ Input Validation
Here an invalid email (Kiran@Gmail) is rejected, and the program asks again until a valid one is entered.

![Validation](screenshots/06_validation.png)

---

## 🗂️ Project Structure


AddressBook/
├── main.c          # 🚪 Entry point and menu loop
├── contact.c       # 🧠 Create / search / edit / delete / list + validation
├── contact.h       # 📐 Contact & AddressBook structures, function declarations
├── file.c          # 💾 Save and load contacts to/from contacts.txt
├── file.h          # 📐 File function declarations
├── populate.c      # 🧪 Optional dummy contact data
├── populate.h      # 📐 Populate function declaration
├── Makefile        # 🔧 Build shortcuts
├── screenshots/    # 📸 Images used in this README
└── README.md       # 📄 You are here


### 🧩 Data Structures

c
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];   // up to 100 contacts
    int contactCount;
} AddressBook;


---

## 🚀 Getting Started

### ✅ Prerequisites
- A C compiler such as *GCC*
- Linux, macOS, or Windows with *WSL* / MinGW (the loading animation uses unistd.h)

### 📥 Clone the repository
bash
git clone https://github.com/<your-username>/<your-repo-name>.git
cd <your-repo-name>


### 🔧 Build

Using make:
bash
make


Or directly with GCC:
bash
gcc -Wall -o addressbook main.c contact.c file.c populate.c


### ▶️ Run
bash
./addressbook


### 🧹 Clean build files
bash
make clean


---

## 🎮 How to Use

When the program starts you will see this menu:


Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit
Enter your choice:


| Choice | What happens |
|:------:|--------------|
| *1* | Enter name → mobile → email. Invalid input is asked again. |
| *2* | Choose search type (name / mobile / email), type your keyword, matches are shown. |
| *3* | Search, pick the contact number from the results, then choose what to edit. |
| *4* | Search, pick the contact number from the results, and it is deleted. |
| *5* | Displays every contact in a sorted table. |
| *6* | Saves everything to contacts.txt and exits. |

> ⚠️ *Remember:* choose *6 (Save and Exit)* to save your changes. Closing the terminal without it will lose new changes.

---

## 💾 Data File Format

Contacts are stored in contacts.txt, one per line, as comma-separated values:


name,phone,email


Example:

Aarav Sharma,9876543210,aarav@gmail.com
Priya Nair,9123456780,priya@gmail.com
Rahul Verma,9988776655,rahul@yahoo.com


The file is created automatically the first time you save. If it doesn't exist, the program starts with an empty address book.

---

## 🧠 Concepts Used

- 🧱 Structures (struct) and arrays of structures
- 🔤 String functions: strcmp, strcpy, strstr
- 📂 File handling: fopen, fprintf, fscanf, fclose
- 🧩 Modular code with multiple source and header files
- 🔁 Loops, switch-case and input validation
- 🫧 Bubble sort for alphabetical listing

---

## 🔮 Future Improvements

- [ ] 🔠 Allow uppercase letters in emails (convert to lowercase automatically)
- [ ] 🔢 Support country codes in phone numbers
- [ ] 📤 Export contacts to CSV
- [ ] 🔐 Sort by other fields (phone / email)
- [ ] 📦 Support more than 100 contacts using dynamic memory

---

## 👨‍💻 Author

*Vishruth J D*

⭐ If you found this project helpful, consider giving it a star on GitHub!
