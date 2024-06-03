#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact(const char *name, const char *phone) {
    if (numContacts < MAX_CONTACTS) {
        strcpy(contacts[numContacts].name, name);
        strcpy(contacts[numContacts].phone, phone);
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full!\n");
    }
}

void displayContacts() {
    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact phone number: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
