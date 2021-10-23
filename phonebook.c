#include "phonebook.h"
#include <stdio.h>
#include "main.c"
#include <string.h>
#include <stdbool.h>

int phonebook_add(Phonebook *new_entry) {
    int free_slot = find_free_slot();
    if (free_slot == -1) {
        printf("Phonebook is out of memory!.\n");
        return -1;
    }
    memcpy(&phonebook[free_slot], new_entry, sizeof(Phonebook)); //dubbelkolla
    //phonebook[free_slot] = new_entry;

    /* Mark that slot as occupied. */
    occupied[free_slot] == true;
    return 0;
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



/* phonebook_search() */