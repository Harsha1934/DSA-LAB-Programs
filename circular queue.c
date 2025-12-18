#include <stdio.h>
#define SIZE 5

int q[SIZE];
int f = -1, r = -1;

void insert(int value) {
    if ((f == 0 && r == SIZE - 1) || ((r + 1) % SIZE) == f) {
        printf("The queue is full\n");
    } else {
        if (f == -1) {
            f = 0;
            r = 0;
        } else {
            r = (r + 1) % SIZE;
        }
        q[r] = value;
        printf("Inserted: %d\n", value);
    }
}

void delete() {
    if (f == -1) {
        printf("The queue is empty\n");
    } else {
        printf("Deleted: %d\n", q[f]);
        if (f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % SIZE;
        }
    }
}

void display() {
    if (f == -1) {
        printf("The queue is empty\n");
    } else {
        int i = f;
        printf("The elements are:\n");
        while (1) {
            printf("%d ", q[i]);
            if (i == r)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    display();

    delete();
    delete();
    insert(55);
    insert(65);
    display();

    delete();
    insert(75);
    display();

    return 0;
}
