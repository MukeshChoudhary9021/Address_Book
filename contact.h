#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

//creating contact structure
typedef struct 
{
    char name[50];
    char phone[20];
    char email[50];
}Contact;

//creating addressbook structure along with using contact structure
typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contact_count;		//keep track of number of contacts
}AddressBook;

//function prototype

//function to initialize 
void initialize(AddressBook *addressbook);

//function to create contact
void createContact(AddressBook *addressBook);

//function to search contact
void searchContact(AddressBook *addressBook);

//function to edit contact
void editContact(AddressBook *addressBook);

//function to delete contact
void deleteContact(AddressBook *addressBook);

//function to list contact
void listContact(AddressBook *addressBook);

//function to save and exit to file
void saveContactsTofile(AddressBook *addressBook);

#endif



