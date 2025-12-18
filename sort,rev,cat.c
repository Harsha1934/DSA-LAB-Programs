#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    if (!temp) {
        printf("Empty\n");
        return;
    }
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort(struct Node *head) {
    if (!head) return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (!head1) return head2;
    struct Node *temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;
    printf("Lists concatenated successfully.\n");
    return head1;
}

int main() {
    insert(&head1, 5);
    insert(&head1, 1);
    insert(&head1, 3);
    insert(&head1, 2);
    display(head1);
    printf("sorted ");
    sort(head1);
    display(head1);
    printf("reversed ");
    reverse(&head1);
    display(head1);
    insert(&head2, 9);
    insert(&head2, 8);
    insert(&head2, 7);
    display(head2);
    head1 = concatenate(head1, head2);
    display(head1);

    return 0;
}

