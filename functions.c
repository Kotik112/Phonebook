#include <stdio.h>
#include <stdbool.h>

#define MAX_PHONE_ENTRIES 10
#define MAX_NUMBER_LEN 15 
#define MAX_NAME_LEN 25

void print_menu(void) {
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
    fgets(*phone_number, MAX_NUMBER_LEN, stdin);
    getchar();  //tar bort new line från stdin
}