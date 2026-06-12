#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "contact.h"
//#include "file.h"
#include <ctype.h>

void initialize(AddressBook *addressBook)
{
    addressBook -> contact_count = 0;	//intialize the number of contact in address book with 0

    FILE *fp;	//declare a file pointer to read the contact form a file
    fp = fopen("contact.csv","r");	//check if the file was opened successfully
    if(fp == NULL)
    {
	perror("ERROR: Unable to open contacts.csv file\n");
	return;
    }

    while(fscanf(fp," %49[^,],%14[^,],%49[^\n]", 
		addressBook -> contacts[addressBook -> contact_count].name,
		addressBook -> contacts[addressBook -> contact_count].phone,
		addressBook -> contacts[addressBook -> contact_count].email) == 3)
    {
	addressBook -> contact_count++;	//increment the contact after successfully reading a contact
    }

    fclose(fp);
}

//number validate function
int name_validate(char *name)
{
    int i = 0;
    while(name[i] != '\0')
    {
	if(!( isalpha(name[i]) || name[i] == ' ' )) return 1;
	i++;
    }
    return 0;
}

//number validate function
int number_validate(char *number)
{
    int i = 0;
    while(number[i] != '\0')
    {
	if( !(isdigit(number[i])) || strlen(number) != 10 ) return 1;
	i++;
    }
    return 0;
}

//email validation function
int email_validate(char *email)
{
    if( !(strstr(email, "@gmail.com"))) return 1;

    return 0;

}

//name duplicate checking function
int is_name_duplicate(AddressBook *addressBook, char*name)
{
    for(int i =0;i<addressBook->contact_count; i++)
    {
	if(strcmp(addressBook->contacts[i].name,name) == 0) return 1;
    }
    return 0;
}

//phone number duplicate checking function
int is_phone_duplicate(AddressBook *addressBook, char *phone)
{
    for(int i = 0; i< addressBook->contact_count; i++)
    {
	if(strcmp(addressBook->contacts[i].phone,phone) == 0) return 1;
    }
    return 0;

}

//email duplicate checking function
int is_email_duplicate(AddressBook *addressBook, char *email)
{
    for(int i = 0; i<addressBook->contact_count; i++)
    {
	if(strcmp(addressBook->contacts[i].email,email) == 0) return 1;
    }
    return 0;
}




void createContact(AddressBook *addressBook)
{
    printf("\n========================================\n");
    printf("           CREATE CONTACT\n");
    printf("========================================\n");

    //1 //for name 
    char name[50];

    //step1: read a name from user
    printf("Enter Name  : ");

    scanf(" %[^\n]", name);

    //step2: validate the name 
    while(name_validate(name) == 1 || is_name_duplicate(addressBook, name) == 1)
    {
	if(name_validate(name) == 1)printf("ERROR: Name validation fails, Please enter valid name..\n");
	else printf("ERROR: name provided is already exist, please enter a unique name\n");
	printf("Enter Name  : ");

	scanf(" %[^\n]", name);
    }

    //2 //for phone number
    char phone[50];

    //step1: read a phone number from user
    printf("Enter Phone : ");
    scanf(" %[^\n]", phone);

    //step2: validate the phone number
    while(number_validate(phone) == 1 || is_phone_duplicate(addressBook, phone) == 1)
    {
	if(number_validate(phone) == 1) printf("ERROR: phone number validation failed, please enter valid number\n");
	else printf("ERROR: phone number proviede is already exist, please enter a unique number");

	printf("Enter Phone : ");
	scanf(" %[^\n]", phone);
    }

    //3 //for email
    char email[50];

    //step1: read a email_id
    printf("Enter Email : ");
    scanf(" %[^\n]", email);

    while(email_validate(email) == 1 || is_email_duplicate(addressBook, email) == 1 )
    {
	if(email_validate(email) == 1) printf("ERROR: Email validation fails, please enter a valid gmail address");
	else
	    printf("ERROR: This Email already exists, please enter a unique email..\n");

	printf("Enter Email : ");
	scanf(" %[^\n]", email);
    }

    //after name, phone_number and email validation copy to actual variable
    strcpy(addressBook->contacts[addressBook->contact_count].name,name);
    strcpy(addressBook->contacts[addressBook->contact_count].phone,phone);
    strcpy(addressBook->contacts[addressBook->contact_count].email,email);
    printf("\n========================================\n");
    printf(" Contact Created Successfully\n");
    printf("========================================\n");
    addressBook->contact_count++; 
}

int search_name(AddressBook *addressBook, char *name)
{
    for(int i = 0; i<addressBook->contact_count; i++)
    {
	if(strcasecmp(addressBook->contacts[i].name,name) == 0) return i;
    }
    return -1;
}

int search_phone(AddressBook *addressBook, char *phone)
{
    for(int i = 0; i<addressBook->contact_count; i++)
    {
	if(strcmp(addressBook->contacts[i].phone,phone) == 0) return i;
    }
    return -1;
}

int search_email(AddressBook *addressBook, char *email)
{
    for(int i = 0; i<addressBook->contact_count; i++)
    {
	if(strcmp(addressBook->contacts[i].email,email) == 0) return i;
    }
    return -1;
}



void searchContact(AddressBook *addressBook)
{
    int choice;
    int j;
    do{
	//display option
	printf("\n========================================\n");
	printf("           SEARCH CONTACT\n");
	printf("========================================\n");
	printf("1. Search By Name\n");
	printf("2. Search By Phone Number\n");
	printf("3. Search By Email\n");
	printf("4. Back To Main Menu\n");
	printf("========================================\n");

	printf("Enter your choice: ");

	//get the user choice
	if(scanf("%d", &choice) != 1)
	{
	    printf("\nInvalid input. Please enter a number.\n");

	    while(getchar() != '\n'); // clear buffer

	    continue;
	}

	//switch case
	switch(choice)
	{
	    case 1:
		char name[50];
		printf("Enter the name: ");
		scanf(" %[^\n]", name);

		j = search_name(addressBook, name);
		if(j == -1)
		{
		    printf("\n========================================\n");
		    printf("      CONTACT NOT FOUND\n");
		    printf("========================================\n");
		}

		else
		{
		    printf("\n========================================\n");
		    printf("          CONTACT FOUND\n");
		    printf("----------------------------------------\n");
		    printf("Name   : %s\n", addressBook->contacts[j].name);
		    printf("Mobile : %s\n", addressBook->contacts[j].phone);
		    printf("Email  : %s\n", addressBook->contacts[j].email);
		    printf("========================================\n");
		}
		break;

	    case 2: 
		char phone[11];
		printf("Enter the phone number : ");
		scanf(" %[^\n]", phone);

		j = search_phone(addressBook, phone);
		if(j == -1)
		{
		    printf("\n========================================\n");
		    printf("      CONTACT NOT FOUND\n");
		    printf("========================================\n");
		}
		else
		{
		    printf("\n========================================\n");
		    printf("          CONTACT FOUND\n");
		    printf("========================================\n");
		    printf("Name   : %s\n", addressBook->contacts[j].name);                                                            
		    printf("Mobile : %s\n", addressBook->contacts[j].phone);                                                           
		    printf("Email  : %s\n", addressBook->contacts[j].email);
		    printf("========================================\n");
		}
		break;

	    case 3:
		char email[50];
		printf("Enter the Email : ");
		scanf(" %[^\n]", email);

		j = search_email(addressBook, email);
		if(j == -1)
		{
		    printf("\n========================================\n");
		    printf("      CONTACT NOT FOUND\n");
		    printf("========================================\n");
		}
		else
		{
		    printf("\n========================================\n");
		    printf("          CONTACT FOUND\n");
		    printf("========================================\n");
		    printf("Name   : %s\n", addressBook->contacts[j].name);                                                              
		    printf("Mobile : %s\n", addressBook->contacts[j].phone);                                                               
		    printf("Email  : %s\n", addressBook->contacts[j].email);
		    printf("========================================\n");
		}
		break;

	    case 4 :

		printf("\n========================================\n");
		printf(" Returning To Main Menu\n");
		printf("========================================\n");
		break;

	    default:
		printf("Invalid choice, please try again: ");
		break;


	}



    }while(choice != 4);
}





void editContact(AddressBook *addressBook)
{
    char name[50];
    printf("Enter the name of the contact to be edit : ");
    scanf(" %[^\n]", name);

    int matchedIndices[100];
    int matchCount = 0;

    for (int i = 0; i < addressBook->contact_count; i++)
    {
	if (strncasecmp(addressBook->contacts[i].name,
		    name,
		    strlen(name)) == 0)
	{
	    matchedIndices[matchCount] = i;
	    matchCount++;
	}
    }

    if(matchCount == 0)
    {
	printf("Contact Not found!\n");
	return;
    }

    int index = -1;
    if(matchCount > 1)
    {
	printf("Multiple contacts found:\n");

	for(int i =0;i<matchCount;i++)
	{
	    printf(" %d. %s\n", i+1, addressBook->contacts[matchedIndices[i]].name);
	}
	int selectedIndex;
	printf("Select a contach number to edit : ");
	scanf("%d", &selectedIndex);

	if(selectedIndex<1 || selectedIndex > matchCount)
	{
	    printf("Invalid selection.\n");
	    return ;
	}

	index = matchedIndices[selectedIndex-1];
    }
    else
    {
	index = matchedIndices[0];
    }

    printf("\n=================================================\n");
    printf("              CONTACT DETAILS\n");
    printf("=================================================\n");
    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);
    printf("=================================================\n");

    int choice;
    do
    {
	printf("\nWhat would you like to edit?\n");
	printf("1. Edit Name\n");
	printf("2. Edit Phone Number\n");
	printf("3. Edit Email\n");
	printf("4. Return\n");

	printf("Enter the choice: ");
	scanf("%d",&choice);

	switch (choice)
	{
	    case 1:
		{
		    char newName[50];
		    printf("Enter the new name : ");
		    scanf(" %[^\n]", newName);

		    while(name_validate(newName) == 1)
		    {
			printf("ERROR: Name Validation failed, please enter a valid name...\n");
			printf("Enter the new name : ");
			scanf(" %[^\n]", newName);
		    }

		    strcpy(addressBook->contacts[index].name,newName);
		    printf("\nName Updated Successfully\n");
		    break;
		}

	    case 2:
		{
		    char newPhone[11];
		    printf("Enter the new phone number: ");
		    scanf(" %[^\n]", newPhone);

		    while(number_validate(newPhone) == 1 || is_phone_duplicate(addressBook,newPhone) == 1)
		    {
			printf("ERROR: Phone number validation failed, please enter a valid number..\n");
			printf("ENter the new phone number: ");
			scanf(" %[^\n]", newPhone);
		    }

		    strcpy(addressBook->contacts[index].phone,newPhone);
		    printf("\nPhone Number Updated Successfully\n");
		    break;

		}
	    case 3: 
		{
		    char newEmail[50];
		    printf("Enter the new email: ");
		    scanf(" %[^\n]", newEmail);

		    while(email_validate(newEmail) == 1 || is_email_duplicate(addressBook,newEmail) == 1)
		    {
			printf("ERROR: Email validation failed, please enter a valid email..\n");
			printf("Enter the new email: ");
			scanf(" %[^\n]", newEmail);
		    }

		    strcpy(addressBook->contacts[index].email, newEmail);
		    printf("\nEmail Updated Successfully\n");
		    break;
		}

	    case 4:
		printf("Exiting edit menu...\n");
		break;

	    default:
		printf("Invaid choice, please try again.\n");
	}

    }while(choice != 4);

    saveContactsTofile(addressBook);
    printf("\n========================================\n");
    printf(" Contact Upadated Successfully\n");
    printf("========================================\n");


}



void deleteContact(AddressBook *addressBook)
{
    char name[50];
    printf("Enter the first two charcters of the contact's name to delete: ");
    scanf(" %[^\n]", name);

    int matchedIndices[100];
    int matchCount = 0;

    for(int i =0;i <addressBook->contact_count; i++)
    {
	int result = strncasecmp(addressBook->contacts[i].name,
		name,
		strlen(name));

	if(result == 0)
	{
	    matchedIndices[matchCount] = i;
	    matchCount++;
	}
    }

    if(matchCount == 0)
    {
	printf("Contact NOT found!..\n");
	return;
    }

    int index;
    if(matchCount > 1)
    {
	printf("Multiple contacts found:\n");
	for(int i = 0;i<matchCount;i++)
	{
	    printf("%d. %s\n", i+1, addressBook->contacts[matchedIndices[i]].name);
	}

	int choice;
	printf("Select the contact number to delete: ");
	scanf("%d", &choice);
	index = matchedIndices[choice-1];
    }
    else
    {
	index = matchedIndices[0];
    }

    printf("\n=================================================\n");
    printf("          CONTACT TO BE DELETED\n");
    printf("=================================================\n");

    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);

    printf("=================================================\n");

    for(int i =index;i<addressBook->contact_count-1;i++)
    {
	addressBook->contacts[i] = addressBook->contacts[i+1];
    }

    addressBook->contact_count--;

    saveContactsTofile(addressBook);
    printf("\n========================================\n");
    printf(" Contact Deleted Successfully\n");
    printf("========================================\n");
}


void listContact(AddressBook *addressBook)
{

    if(addressBook->contact_count == 0)
    {
	printf("Ooops No contacts Available.\n");
	return ;
    }

    Contact temp;	//temporary structure for sorting

    //Using bubble sort to sort contacts in alphabetically by name
    for(int i = 0;i < addressBook->contact_count;i++)
    {
	for(int j = i+1;j<addressBook->contact_count;j++)
	{
	    //Intersting swaping lexigraphical comparing
	    if(strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name) > 0)
	    {
		temp = addressBook->contacts[i];
		addressBook->contacts[i] = addressBook->contacts[j];
		addressBook->contacts[j] = temp;
	    }
	}
    }

    //printing total count of contact

    printf("\n=========================================================\n");
    printf("                     CONTACT LIST\n");
    printf("=========================================================\n");

    printf("Total Contacts : %d\n",
	    addressBook->contact_count);

    printf("---------------------------------------------------------\n");

    printf("%-6s %-15s %-15s %-30s\n",
	    "Sr.no",
	    "Name",
	    "Phone",
	    "Email");

    printf("---------------------------------------------------------\n");

    for(int i = 0; i < addressBook->contact_count; i++)
    {
	printf("%-6d %-15s %-15s %-30s\n",
		i + 1,
		addressBook->contacts[i].name,
		addressBook->contacts[i].phone,
		addressBook->contacts[i].email);
    }

    printf("=========================================================\n");

}

void saveContactsTofile(AddressBook *addressBook)
{

    FILE *fp;
    fp = fopen("contact.csv","w");

    if(fp == NULL)
    {
	printf("\n========================================\n");
	printf(" ERROR: Unable To Save Contacts\n");
	printf("========================================\n");
	return;
    }

    for(int i = 0;i<addressBook->contact_count;i++)
    {
	fprintf(fp, "%s,%s,%s\n",
		addressBook->contacts[i].name,
		addressBook->contacts[i].phone,
		addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("\n========================================\n");
    printf(" Contacts Saved Successfully\n");
    printf(" Total Contacts Saved : %d\n",
	    addressBook->contact_count);
    printf(" Thank You For Using Address Book\n");
    printf("========================================\n");
}







