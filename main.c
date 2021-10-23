/* TODO 
1.  Make a function to find the first available free index and return that index.
2.
*/

#include "phonebook.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Hur portar/includar jag över dessa definitioner till andra filer? */
#define MAX_PHONE_ENTRIES 10
#define MAX_NUMBER_LEN 15 
#define MAX_NAME_LEN 25

int main(int argc, char *argv) {
    int index = 0, menu_choice;
    static Phonebook phonebook[MAX_PHONE_ENTRIES];
    print_menu();
    scanf("%d", &menu_choice);
    system("cls");
    switch (menu_choice)
    {
    case 1:     /* New entry */
        //get_free_index()
        //input_name_and_number()
        break;

    case 2:     /* Search by name */
        /* code */
        break;

    case 3:     /* Print all the phonebook contents. */     
        /* code */
        break;
    
    default:
        printf("Invalid input.\n");
        break;
    }
    
    return 0;
}
