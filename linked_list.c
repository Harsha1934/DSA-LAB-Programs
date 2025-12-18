#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void delete_begin() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Deleting %d from beginning\n", head->data);
    head = head->next;
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleting %d from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleting %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (pos == 1) {
        printf("Deleting %d from position %d\n", head->data, pos);
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position %d.\n", pos);
        return;
    }
    struct Node *del = temp->next;
    printf("Deleting %d from position %d\n", del->data, pos);
    temp->next = del->next;
    free(del);
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    if (temp == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(3);
    insert(2);
    insert(1);
    insert(4);
    insert(5);
    insert(6);
    display();
    delete_begin();
    delete_pos(2);
    delete_end();
    display();
    return 0;
}
