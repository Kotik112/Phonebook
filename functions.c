#include "phonebook.h"
#include <stdio.h>
#include <stdbool.h>


static void print_menu(void) {
    printf("\n*****\tMAIN MENU\t*****\n");
    printf("1.\tNew entry to the phone book.\n");
    printf("2.\tSearch for an entry by name.\n");
    printf("3.\tShow all entries.\n");
    //printf("4.");
}

bool input_name_and_number(char* name, char* phone_number) {
    printf("Enter the name: \n");
    fgets(*name, MAX_NAME_LEN, stdin);
    getchar();  //tar bort new line från stdin

    printf("Enter the persons phone number:\n");
    fgets(*phone_number, MAX_NR_LEN, stdin);
    getchar();  //tar bort new line från stdin
}