# Address Book (C)

A simple console-based address book written in C. Contacts are stored in a plain text file (`contacts.txt`).

## Features
- Create, search, edit and delete contacts
- List all contacts (sorted by name) in a table
- Save contacts to a file on exit and load them on startup

## Project structure
| File | Purpose |
|------|---------|
| `main.c` | Menu loop |
| `contact.c / contact.h` | Contact operations (create, search, edit, delete, list) |
| `file.c / file.h` | Save/load contacts to `contacts.txt` |
| `populate.c / populate.h` | Dummy contact data |

## Build and run
```bash
make
./addressbook
```
Or without make:
```bash
gcc -Wall -o addressbook main.c contact.c file.c populate.c
./addressbook
```

## Data format
`contacts.txt` stores one contact per line: `name,phone,email`

## Author
Vishruth J D
