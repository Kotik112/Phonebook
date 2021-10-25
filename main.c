/* TODO 
1.  Make a function to find the first available free index and return that index.
2.
*/

#include "phonebook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Takes user input and formats the number to appropriate format. */
static void add_entry(void) {
    char raw_number_input[MAX_NAME_LEN]; //Make bigger than MAX_NAME_LEN (+5/10) for extra/special chars?
    Phonebook new_entry;

    /* Name input: */
    printf("Enter the name: \n");
    fgets(new_entry.name, MAX_NAME_LEN, stdin);
    getc(stdin);  //tar bort new line från stdin
    printf("%s", new_entry.name);

    /* Phone number input: */
    printf("Enter the phone no.:\n", new_entry.name);
    fgets(raw_number_input, MAX_NR_LEN, stdin);
    getc(stdin);  //tar bort new line från stdin
    int format_status = phonebook_format_number(raw_number_input, new_entry.phone_number);
    if (format_status == -1) {
        printf("Phonebook Number formatter failed.\n");
    }
    int add_status = phonebook_add(&new_entry);
    if (add_status == -1) {
        printf("Phonebook is out of memory!.\n");
    }
}

static void search(void) {
    char name[MAX_NAME_LEN];
    printf("Search by name!\nEnter the name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    getc(stdin);
    int matching_index = phonebook_search(name);
    phonebook_print_index(matching_index);
    
}



static void print_menu(void) {
    printf("\n*****\tMAIN MENU\t*****\n");
    printf("1.\tNew entry to the phone book.\n");
    printf("2.\tSearch for an entry by name.\n");
    printf("3.\tShow all entries.\n");
    //printf("4.");
}

int main(int argc, char **argv) {
    while(true) {
        int menu_choice;
        print_menu();
        scanf("%d", &menu_choice);
        /* system("cls"); */
        switch (menu_choice)
        {
        case 1:     /* New entry */
            add_entry();
            break;

        case 2:     /* Search by name */
            search();
            break;

        case 3:     /* Print all the phonebook contents. */     
            phonebook_print_contents();
            break;
        
        /* default:
            printf("Invalid choice.\n");
            break; */
        }
    }   
    return 0;
}
