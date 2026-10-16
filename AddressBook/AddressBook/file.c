#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contacts.txt","w");
    if(fp == NULL)
    {
        printf("Error in opening file\n");
        return;
    }

    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        fprintf(fp,"%s,%s,%s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.txt","r");

    if(fp == NULL)
    {
        printf("No previous contacts found.\n");
        return;
    }

    while(addressBook->contactCount < 100 &&
          fscanf(fp," %[^,],%[^,],%[^\n]",
          addressBook->contacts[addressBook->contactCount].name,
          addressBook->contacts[addressBook->contactCount].phone,
          addressBook->contacts[addressBook->contactCount].email) != EOF)
    {
        addressBook->contactCount++;
    }

    fclose(fp);
}