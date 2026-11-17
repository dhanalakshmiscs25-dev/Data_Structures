
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create() {
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully\n");
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL, *current = head, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node *concatenate(struct node *head1,
                         struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Sort List 1\n");
        printf("5. Reverse List 1\n");
        printf("6. Concatenate Lists\n");
        printf("7. Display Result\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = create();
                break;

            case 2:
                head2 = create();
                break;

            case 3:
                display(head1);
                break;

            case 4:
                sort(head1);
                break;

            case 5:
                head1 = reverse(head1);
                printf("List reversed successfully\n");
                break;

            case 6:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Lists concatenated successfully\n");
                break;

            case 7:
                display(head1);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

