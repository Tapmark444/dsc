#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Initialize hash table */
void init() {
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

/* Insert key using linear probing */
void insert(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

/* Search key in hash table */
void search(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == startIndex)
            break;
    }

    printf("Key %d not found\n", key);
}

/* Display hash table */
void display() {
    int i;
    printf("Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Index %d : %d\n", i, hashTable[i]);
}

/* Main function */
int main() {
    int choice, key;

    init();

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
/*
INPUT :
Enter your choice: 1
Enter key to insert: 23
Enter key to insert: 33
Inserted 33 at index 4
Hash Table:
Index 0 : -1
Index 1 : -1
Index 2 : -1
Index 3 : 23
Index 4 : 33
Index 5 : -1
Index 6 : -1
Index 7 : -1
Index 8 : -1
Index 9 : -1
Enter key to search: 33
OUTPUT:
Key 33 found at index 4

*/
