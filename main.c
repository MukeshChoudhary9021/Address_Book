#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    AddressBook addressBook;	//declare addressbook variable
    initialize(&addressBook);	//initialize the address book

    do{

	printf("\n");
	printf("========================================\n");
	printf("          ADDRESS BOOK SYSTEM\n");
	printf("========================================\n");
	printf("1. Create Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List All Contacts\n");
	printf("6. Save & Exit\n");
	printf("========================================\n");
	printf("Enter your choice: ");


	//scanf("%d", &choice);

	if(scanf("%d", &choice) != 1)	//we use scanf here
	{
	    printf("Invalid input. Please enter a number.\n");

	    while(getchar() != '\n');   // clear buffer

	    continue;
	}
	switch(choice)
	{
	    case 1:	//call function to create new contact
		createContact(&addressBook);
		break;

	    case 2:	//call function to search for a contact
		searchContact(&addressBook);
		break;

	    case 3:	//call function to edit an contact
		editContact(&addressBook);
		break;

	    case 4:	//call function to delete a contact
		deleteContact(&addressBook);
		break;

	    case 5:	//call function to list all contact
		listContact(&addressBook);
		break;

	    case 6:	//call function to save the contact and exit 
		saveContactsTofile(&addressBook);
		break;

	    default:
		printf("\n========================================\n");
		printf(" ERROR: Invalid Choice\n");
		printf(" Please Select Between 1 And 6\n");
		printf("========================================\n");
		break;
	}

    }while(choice != 6);


    return 0;
}

