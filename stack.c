#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &x);
        stack[++top] = x;
     
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
