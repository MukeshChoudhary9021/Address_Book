# Project Title

Address Book Management System in C

## Overview

This project is a console-based Address Book Management System developed using the C programming language. It allows users to store, manage, search, edit, and delete contact information efficiently. The contact details are stored in a CSV file, ensuring that data is preserved even after the program is closed.

The project focuses on managing three essential fields:

* Name
* Phone Number
* Email Address

## Features

* Create new contacts
* Search contacts by Name, Phone Number, or Email
* Edit existing contact details
* Delete contacts
* Display all contacts in sorted order
* Store contacts permanently using a CSV file
* Input validation for Name, Phone Number, and Email
* Duplicate Phone Number and Email detection
* Console-based user interface

## Working Principle

The program stores all contacts in an AddressBook structure during execution.

When the program starts:

1. Contacts are loaded from the CSV file.
2. Data is stored in an array of structures.
3. Users can perform various operations through a menu-driven interface.
4. Any changes made are saved back to the CSV file before exiting.

The system validates user inputs and prevents duplicate phone numbers or email addresses.

## Contact Information Fields

| Field         | Description                   |
| ------------- | ----------------------------- |
| Name          | Contact Name                  |
| Phone Number  | Unique 10-digit Mobile Number |
| Email Address | Unique Email ID               |

## Functional Modules

### Create Contact

* Accepts Name, Phone Number, and Email.
* Validates user input.
* Checks for duplicate entries.
* Stores contact information.

### Search Contact

* Search by Name
* Search by Phone Number
* Search by Email

### Edit Contact

* Modify Name
* Modify Phone Number
* Modify Email Address

### Delete Contact

* Search and remove existing contacts.

### List Contacts

* Displays all contacts.
* Sorts contacts alphabetically using Bubble Sort.

### Save Contacts

* Writes all contact details to a CSV file.

## Requirements

* GCC Compiler
* Linux / Windows Operating System
* C Standard Library

## Limitations

* Maximum number of contacts is fixed.
* Console-based interface only.
* Supports only Name, Phone Number, and Email fields.
* No password protection.

## Future Improvements

* Graphical User Interface (GUI)
* Contact grouping and categorization
* Multiple phone numbers per contact
* Contact import/export functionality
* Password-protected address book
* Database integration (MySQL/SQLite)
* Birthday and reminder support

## Key Concepts Used

* Structures in C
* Arrays of Structures
* File Handling
* CSV File Operations
* String Manipulation
* Searching Algorithms
* Sorting Algorithms (Bubble Sort)
* Input Validation
* Modular Programming

## Applications

* Personal Contact Management
* Student Contact Records
* Employee Directory Management
* Small Business Contact Storage
* Digital Address Book Systems

## Conclusion

The Address Book Management System provides an efficient way to store and manage contact information. The project demonstrates practical implementation of file handling, structures, searching, sorting, and data validation concepts in C programming while maintaining data persistence through CSV files.
