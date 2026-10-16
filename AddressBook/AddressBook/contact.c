#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


void loading()
{
    printf("Loading");
    for(int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(90000); 
    }
    printf("\n");
}
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    loading();
    if(addressBook->contactCount == 0)
    {
        printf("\n+------------------------------------------------------------+\n");
        printf("|                     Empty Contact List                       |\n");
        printf("+--------------------------------------------------------------+\n");
        return;
    }
    for(int i = 0 ; i < addressBook->contactCount-1 ; i++)
    {
        for(int j = 0 ; j < addressBook->contactCount - i - 1 ; j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf("\n+-------------------------------------------------------------+\n");
    printf("|                        List Of Contacts                       |\n");
    printf("+---------------------------------------------------------------+\n");
    printf("\n+-------------------------------------------------------------+\n");
    printf("| %-20s | %-15s | %-25s |\n", "Name", "Mobile", "Email");
    printf("+---------------------------------------------------------------+\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
         printf("| %-20s | %-15s | %-25s |\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    printf("+---------------------------------------------------------------+\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int validate_name(char *name)
{
    char *temp = name;
        while(*temp)
        {
            if((*temp >='A' && *temp <= 'Z')||(*temp >= 'a' && *temp <= 'z')||*temp == ' '||*temp =='.')
            {
                temp++;
            }
            else
            {    
                return 0;//invalid
            }
        }
return 1;//valid
    }

int validate_mobile(char *mobile)
{
    char *temp = mobile;
    int len = 0;
    while(*temp)
    {
        if(*temp >= '0' && *temp <='9')
        {
            temp++;
            len++;
        }
        else 
            return 0;
    }
    return len;
}   

int unique_no(AddressBook *addressBook, char *mobile)
{
    for(int  i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].phone,mobile) == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int validate_mail(char *mail)
{
    char *temp = mail;
    int flag = 0,i = 0;
    int pos_at = 0,pos_dot = 0;
    while(*temp)
    {
        if(*temp >= 'A' && *temp <= 'Z')
        return 0;
        temp++;
    }
    temp = mail;
    while(temp[i] != '\0')
    {
        if(temp[i] == '@')
        {   
            flag++;
            pos_at = i;
        }
        if(temp[i] == '.')
           pos_dot = i;
        i++;
    }
    if(flag != 1)
    {
        return 0;
    }
    if(pos_at != 0 && pos_dot > pos_at && pos_dot != pos_at+1 && temp[pos_dot + 1] != '\0')
        return 1;
    else
        return 0;

}
int unique_mail(AddressBook *addressBook,char *mail)
{
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].email,mail) == 0)
        {
            return 0;
        }
    }
    return 1;
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("\n+-------------------------------------------------------------------+\n");
    printf("|                              Create Contact                         |\n");
    printf("+---------------------------------------------------------------------+\n");
    char name[20];

    while(1)
    {
        printf("Enter The Name : \n");
        scanf(" %[^\n]", name);
        int valid = validate_name(name);
        if(valid == 1)// valid
            break;
    }

    char mobile[11];

    while(1)
    {
        printf("Enter the mobile number : ");
        scanf(" %[^\n]",mobile);
        int valid = validate_mobile(mobile);
        if(valid == 10)//valid
        {

        if(unique_no(addressBook,mobile) == 0)
        {
            printf("Phone number is already exist.\n");
            continue;
        }
        else
            break;
        }
    }

    char mail[30];

    while(1)
{
    printf("Enter the Email id : ");
    scanf(" %[^\n]", mail);

    int valid = validate_mail(mail);

    if(valid == 0)
    {
        printf("Invalid Email format\n");
        continue;
    }

    if(unique_mail(addressBook, mail) == 0)
    {
        printf("Email already exists\n");
        continue;
    }

    break;
}
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, mobile);
    strcpy(addressBook->contacts[addressBook->contactCount].email, mail);
    addressBook->contactCount++;
    loading();
    printf("\n+----------------------------------------------------------------+\n");
    printf("|                     Contact Created Successful                   |\n");
    printf("+------------------------------------------------------------------+\n");
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    if(addressBook->contactCount == 0)
    {
        printf("\n+----------------------------------------------------------+\n");
        printf("|                    Contact Book Is Empty                   |\n");
        printf("+------------------------------------------------------------+\n");
    }
    int found = 0 , choice;
    printf("Search the contact by\n1.Name\n2.Mobile Number\n3.Mail id\n");
    scanf("%d",&choice);
    char search[30];
    if(choice == 1)
    printf("Enter the name : \n");
    else if(choice == 2)
    printf("Enter the Mobile Number : \n");
    else if(choice == 3)
    printf("Enter the Mail id : \n");
    else
    {   
        printf("Invalid Entry \n");
        return;
    }

    scanf(" %[^\n]",search);
    loading();
    printf("\n+----------------------------------------------------------------+\n");
    printf("| %-20s | %-15s | %-25s |\n", "Name", "Mobile", "Email");
    printf("+----------------------------------------------------------------+\n");
    
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        int match = 0;
        if(choice == 1 && strstr(addressBook->contacts[i].name,search))
        {
            match = 1;
        }
        else if(choice == 2 && strstr(addressBook->contacts[i].phone,search))
        {
            match = 1;
        }
        else if(choice == 3 && strstr(addressBook->contacts[i].email,search))
        {
            match = 1;
        }
        if(match == 1)
        {
            
            printf("| %-20s | %-15s | %-25s |\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("+----------------------------------------------------------------+\n");
            found = 1;
        }
    }
    if(found == 0)
    {
        printf("\n+-------------------------------------------------------------+\n");
        printf("|                     Contact Not Found                         |\n");
        printf("+---------------------------------------------------------------+\n");
    return;
}
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    if(addressBook->contactCount == 0)
    {
        printf("\n+------------------------------------------------------------+\n");
        printf("|                    Contact Book Is Empty                     |\n");
        printf("+--------------------------------------------------------------+\n");
        return;
    }
    int choice;
    char search[30];
    printf("1.Name\n2.Mobile Number\n3.Mail id\n");
    scanf("%d",&choice);
    int matchs[100];
    int count = 0;
    if(choice == 1)
    {
        printf("Enter the Name : \n");
    }
    else if(choice == 2)
    {
        printf("Enter the Mobile Number : \n");
    }
    else if(choice == 3)
    {
        printf("Enter the Mail id : \n");
    }
    else
    {
        printf("Invalid Input Try again.\n");
        return;
    }
    scanf(" %[^\n]",search);
    loading();
    printf("\n+-------------------------------------------------------------+\n");
    printf("|                           Edit Contact                        |\n");
    printf("+---------------------------------------------------------------+\n");
    printf("\n+----------------------------------------------------------------+\n");
    printf("| %-20s | %-15s | %-25s |\n", "Name", "Mobile", "Email");
    printf("+----------------------------------------------------------------+\n");
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        int match = 0;
        if(choice == 1 && strstr(addressBook->contacts[i].name,search))
        {
            match = 1;
        }
        else if(choice == 2 && strstr(addressBook->contacts[i].phone,search))
        {
            match = 1;
        }
        else if(choice == 3 && strstr(addressBook->contacts[i].email,search))
        {
            match = 1;
        }
        if(match)
        {
            matchs[count] = i;
            printf("| %d . %-20s | %-15s | %-25s |\n", count + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("+----------------------------------------------------------------+\n");
            count++;
        }
        
    }
    if(count == 0)
    {
        printf("\n+--------------------------------------------------------+\n");
        printf("|                      Contact Not Found                    |\n");
        printf("+-----------------------------------------------------------+\n");
        return;
    }
    int edit;
    int pick;
    printf("Enter the selection from (1-%d)\n",count);
    scanf("%d",&pick);
    if(pick < 1 || pick > count)
    {
        printf("Invalid selection\n");
        return;
    }
    int indx = matchs[pick - 1];
    printf("what you want to edit ?\n1.Name\n2.Mobile Number\n3.Mail id\n");
    scanf("%d",&edit);
    if(edit == 1)
    {
        char name[20];
        while(1)
        {
        printf("Enter the name :\n");
        scanf(" %[^\n]",name);
        if(validate_name(name))
            {   
            strcpy(addressBook->contacts[indx].name,name);
            break;
            }
        }
    }
    else if(edit == 2)
    {
        char mobile[11];
        while(1)
        {
        printf("Enter the Mobile Number you want to edit : \n");
        scanf(" %[^\n]",mobile);
        if(validate_mobile(mobile) == 10)
        {
            if(unique_no(addressBook,mobile))
            {
                strcpy(addressBook->contacts[indx].phone , mobile);
                break;
            }
            else
            {
                printf("This number is already exits\n");
            }
        }
    }
}
    else if(edit == 3)
    {
        char mail[30];
        while(1)
        {
        printf("Enter the Mail id you want to edit : \n");
        scanf(" %[^\n]",mail);
        if(validate_mail(mail))
        {
            strcpy(addressBook->contacts[indx].email,mail);
        }
        
    }
}
    else
    {
        printf("Invalid input !!!");
        return;
    }
    printf("\n+---------------------------------------------------------+\n");
    printf("|                  Contact Edited Successfully              |\n");
    printf("+-----------------------------------------------------------+\n");
   return;

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   if(addressBook->contactCount == 0)
   {
    printf("There is no contact to delete\n");
    return;
   }
   printf("Enter the choice\n1.Name\n2.Mobile Number\n3.Mail id\n");
   int choice;
   scanf("%d",&choice);
   char search[30];
   int count = 0;
   int matchs[100];
   if(choice == 1)
   {
        printf("Enter the Name what do you want to search?\n");
   }
   else if(choice == 2)
   {
        printf("Enter the Mobile Number what do you want to search?\n");
   }
   else if(choice == 3)
   {
        printf("Enter the Mail id what do you want to search?\n");
   }
   else
   {
        printf("Inavlid Entry !!!\n");
        return;
   }
   scanf(" %[^\n]",search);
   printf("\tName\tMobile Number\tMail id\t\n");
   printf("Contact Matched Details.\n");
   printf("\n+----------------------------------------------------------------+\n");
   printf("| %-20s | %-15s | %-25s |\n", "Name", "Mobile", "Email");
   printf("+----------------------------------------------------------------+\n");
   for(int i = 0 ; i < addressBook->contactCount ; i++)
   {
        int match = 0;
        if(choice == 1 && strstr(addressBook->contacts[i].name,search))
        {
            match = 1;
        }
        else if(choice == 2 && strstr(addressBook->contacts[i].phone,search))
        {
            match = 1;
        }
        else if(choice == 3 && strstr(addressBook->contacts[i].email,search))
        {
            match = 1;
        }
        if(match)
        {
            matchs[count] = i;
            printf("| %d . %-20s | %-15s | %-25s |\n", count + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("+----------------------------------------------------------------+\n");
            count++;
        }
   }
   if(count == 0)
   {
    printf("\n+---------------------------------------------------------------------+\n");
    printf("|                           Contact Not Found                           |\n");
    printf("+-----------------------------------------------------------------------+\n");
    return;
   }
   int pick;
   printf("Enter the (1-%d) you want to delete?\n",count);
   scanf("%d",&pick);
   if(pick < 1 || pick > count)
   {
    printf("Invalid Entry !!!\n");
    return;
   }
   int indx = matchs[pick - 1];
   for(int i = indx ; i < addressBook->contactCount -1 ; i++)
   {
    addressBook->contacts[i] = addressBook->contacts[i+1];
   }
   addressBook->contactCount--;
   printf("\n+--------------------------------------------------------------------+\n");
   printf("|                     Contact Deleted Successfully                     |\n");
   printf("+----------------------------------------------------------------------+\n");
   return;
}
