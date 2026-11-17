
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// CREATE DOUBLY LINKED LIST

void create() {
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

// INSERT NODE TO THE LEFT OF A SPECIFIC NODE

void insertLeft() {
    struct node *newnode, *temp;
    int value;

    printf("Enter value before which to insert: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Specified node not found\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->prev = temp->prev;
    newnode->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;

    printf("Node inserted successfully\n");
}

// DELETE NODE BASED ON VALUE

void deleteNode() {
    struct node *temp;
    int value;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully\n");
}

// DISPLAY DOUBLY LINKED LIST

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// MAIN FUNCTION

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Create List\n");
        printf("2. Insert to Left\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                insertLeft();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

