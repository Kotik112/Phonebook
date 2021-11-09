#include "phonebook.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static Phonebook phonebook[MAX_PHONE_ENTRIES];
/* True/1 = Occupied, False/0 = Available */
static bool occupied[MAX_PHONE_ENTRIES];

int phonebook_add(Phonebook *new_entry) {
    int free_slot = find_free_slot();
    if (free_slot == -1) {
        return -1;
    }
    memcpy(&phonebook[free_slot], new_entry, sizeof(Phonebook)); //dubbelkolla

    /* Mark that slot as occupied. */
    occupied[free_slot] = true;
    //printf("Name: %s, Phone Nr: %s.\n", phonebook[free_slot].name, phonebook[free_slot].phone_number);
    return 0;
}

/* Loop through the entire phonebook and check if 
                    there is an available free slot.*/
int find_free_slot(void) {
    for (int i = 0; i < MAX_PHONE_ENTRIES; i++) {
        if (!occupied[i]) {
            return i;
        }
    }
    /* -1, did not find an empty slot */
    return -1;
}

/* Searches the phonebook for an entry matcing the search_query */
int phonebook_search(const char search_query[MAX_NAME_LEN]) {
    for (int i = 0; i < MAX_PHONE_ENTRIES; i++) {
        if (search_query == phonebook[i].name) {
            return i;
        }
    }
    return -1;
}

void phonebook_print_index(int index) {
    printf("Name: %s, Phone Nr: %s.\n", phonebook[index].name, phonebook[index].phone_number);
}

void phonebook_print_contents(void) {
    for (int i = 0; i < MAX_PHONE_ENTRIES; i++) {
        if (occupied[i] == true) {
            printf("Name: %s, Phone Nr: %s.\n", phonebook[i].name, phonebook[i].phone_number);
        }   
    }
}

/* Ignores any unnecessary symbols and spaces from the raw input by user */
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
    converted = temporary_number;
    converted[k] = '\0';
     
    return 0;
}

bool is_number(char c) {
    return c > '0' && c < '9';
}



/* phonebook_search() */