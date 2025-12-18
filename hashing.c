#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

void init(int m) {
    int i;
    for (i = 0; i < m; i++)
        hashTable[i] = -1;
}

void insert(int key, int m) {
    int index = key % m;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

void display(int m) {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main() {
    int n, m, i, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init(m);

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key, m);
    }

    display(m);

    return 0;
}
