#include <stdio.h>
#define SIZE 5

int q[SIZE];
int f = -1, r = -1;

void insert(int value) {
    if (r == SIZE - 1) {
        printf("The queue is full\n");
    } else {
        if (f == -1)
            f = 0;
        r++;
        q[r] = value;
        printf("Inserted: %d\n", value);
    }
}

void delete() {
    if (f == -1 || f > r) {
        printf("The queue is empty\n");
    } else {
        printf("Deleted: %d\n", q[f]);
        f++;
        if (f > r) {
            f = r = -1;
        }
    }
}

void display() {
    if (f == -1 || f > r) {
        printf("The queue is empty\n");
    } else {
        printf("The elements are:\n");
        for (int i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    delete();
    display();
    return 0;
}
