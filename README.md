# Address Book Management System in C

## Overview
This project is a console-based Address Book Management System developed using the C programming language. It allows users to store, manage, search, edit, and delete contact information efficiently. The contact details are stored in a CSV file, ensuring that data is preserved even after the program is closed.

The project focuses on managing three essential fields:
* **Name**
* **Phone Number**
* **Email Address**

---

## Features
* **Create** new contacts
* **Search** contacts by Name, Phone Number, or Email
* **Edit** existing contact details
* **Delete** contacts
* **Display** all contacts in sorted order
* **Store** contacts permanently using a CSV file
* **Input validation** for Name, Phone Number, and Email
* **Duplicate detection** for Phone Numbers and Emails
* Clean, console-based user interface

---

## How to Compile and Run

To run this project on a Linux system (or WSL), open your terminal in the project directory and run the following commands:

```bash
# 1. Compile the source files
gcc main.c contact.c -o address_book

# 2. Run the application
./address_book
```

---

## Working Principle
The program stores all contacts in an `AddressBook` structure during execution.

1. **On Startup:** Contacts are loaded automatically from the CSV file into an array of structures.
2. **Execution:** Users interact with the program through a fluid, menu-driven interface.
3. **On Exit:** Any changes made (additions, edits, deletions) are saved back to the CSV file securely before the program closes.

---

## Contact Information Fields

| Field | Description |
| :--- | :--- |
| **Name** | Contact Name |
| **Phone Number** | Unique 10-digit Mobile Number |
| **Email Address** | Unique Email ID |

---

## Functional Modules
* **Create Contact:** Accepts inputs, runs validation loops, and blocks duplicates.
* **Search Contact:** Multi-criteria filtering by Name, Phone, or Email.
* **Edit Contact:** Allows modular modification of individual fields.
* **Delete Contact:** Removes matching records dynamically.
* **List Contacts:** Displays a clean directory sorted alphabetically using the **Bubble Sort** algorithm.
* **Save Contacts:** Handles sequential file writing to the local CSV database.

---

## Requirements
* GCC Compiler
* Linux / Windows Operating System
* C Standard Library

---

## Key Concepts Demonstrated
* Advanced Structures in C
* Arrays of Structures
* Persistent File Handling (CSV File Operations)
* Dynamic String Manipulation
* Searching Algorithms
* Sorting Algorithms (Bubble Sort Implementation)
* Strict Input Validation Loops
* Modular / Multi-file Programming

---

## Limitations & Future Improvements

### Current Limitations
* Maximum number of contacts is fixed.
* Console-based interface only.
* No password protection layer.

### Future Improvements
* Graphical User Interface (GUI) wrapper
* Contact grouping and categorization
* Database integration (MySQL/SQLite)
* Birthday tracking and automated reminders
