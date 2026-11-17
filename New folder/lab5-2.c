
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

// STACK OPERATIONS

void push() {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}

void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// QUEUE OPERATIONS

void enqueue() {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully\n");
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n1. Push\n2. Pop\n3. Display\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: push(); break;
                    case 2: pop(); break;
                    case 3: displayStack(); break;
                    default: printf("Invalid choice\n");
                }
                break;

            case 2:
                printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: enqueue(); break;
                    case 2: dequeue(); break;
                    case 3: displayQueue(); break;
                    default: printf("Invalid choice\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

