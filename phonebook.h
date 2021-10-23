#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>

#define MAX_PHONE_ENTRIES 10
#define MAX_NR_LEN 15 
#define MAX_NAME_LEN 25

typedef struct phonebookStruct
{
    char name[MAX_NAME_LEN];
    char phone_number[MAX_NR_LEN];
}Phonebook;

int phonebook_format_number(const char* raw_number, char* converted);
bool is_number(char c);

#endif // PHONEBOOK_H
