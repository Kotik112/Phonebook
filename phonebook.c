#include "phonebook.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Takes user input and formats the number to appropriate format. */
static void phonebook_add_entry(void) {
    char raw_number_input[MAX_NAME_LEN]; //Should this be bigger than MAX_NAME_LEN for extra/special chars?
    Phonebook new_entry;

    printf("Enter the name: \n");
    fgets(new_entry.name, MAX_NAME_LEN, stdin);
    getc(stdin);  //tar bort new line från stdin
    
    printf("Enter %d's phone number:\n", new_entry.name);
    fgets(raw_number_input, MAX_NR_LEN, stdin);
    getc(stdin);  //tar bort new line från stdin
    /* Formats the number to the correct format */
    phonebook_format_number(raw_number_input, new_entry.phone_number);
}

/* alters any unnecessary symbols and spaces from the raw characters adn */
int phonebook_format_number(const char* raw_number, char* converted) {
    char temporary_number[MAX_NR_LEN];
    size_t len = strlen(raw_number);
    if (len <= 0 || len > MAX_NR_LEN) {
        return -1;
    }
    int k = 0;
    for (int i = 0; i < MAX_NR_LEN; i++) {
        if (is_number(raw_number[i])) {
            temporary_number[k] = raw_number[i];
            k++;
        }
    }
    raw_number = temporary_number; 
    return 0;
}

bool is_number(char c) {
    return c > '0' && c < '9';
}

