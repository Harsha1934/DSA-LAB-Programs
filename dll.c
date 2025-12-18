#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node* CreatenewNode(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createInsert(int x) {
    struct node *newNode = CreatenewNode(x);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertLeft(int value, int newValue) {

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    struct node *newNode = CreatenewNode(newValue);

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}


void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *t = head;

    while (t != NULL && t->data != value)
        t = t->next;

    if (t == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (t == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(t);
        return;
    }

    if (t->next == NULL) {
        t->prev->next = NULL;
        free(t);
        return;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}


void display() {
    struct node *t = head;

    if (t == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}


int main() {
    int choice, value, newVal;
       printf("1. Create (Insert at end)\n");
        printf("2. Insert LEFT of a value\n");
        printf("3. Delete a value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                createInsert(value);
                break;

            case 2:
                printf("Enter new value: ");
                scanf("%d", &newVal);
                printf("Insert LEFT of which value? ");
                scanf("%d", &value);
                insertLeft(value, newVal);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
