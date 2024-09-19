#include <stdio.h>
#include <stdlib.h>

#define size 7

int arr[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

void insert(int value)
{
    int key = value % size;
    int originalKey = key;
    
    while (arr[key] != -1)
    {
        printf("Collision at arr[%d], trying next slot...\n", key);
        key = (key + 1) % size; 
        if (key == originalKey) 
        {
            printf("Hash table is full, cannot insert %d\n", value);
            return;
        }
    }
    
    arr[key] = value;
    printf("%d inserted at arr[%d]\n", value, key);
}

void print()
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != -1)
            printf("arr[%d] = %d\n", i, arr[i]);
        else
            printf("arr[%d] = NULL\n", i);
    }
}

void search(int value)
{
    int key = value % size;
    int originalKey = key;

    while (arr[key] != -1)
    {
        if (arr[key] == value)
        {
            printf("Search Found: %d at arr[%d]\n", value, key);
            return;
        }
        key = (key + 1) % size;
        if (key == originalKey) 
        {
            break;
        }
    }
    printf("Search Not Found for %d\n", value);
}

void del(int value)
{
    int key = value % size;
    int originalKey = key;

    while (arr[key] != -1)
    {
        if (arr[key] == value)
        {
            arr[key] = -1;
            printf("%d deleted from arr[%d]\n", value, key);
            return;
        }
        key = (key + 1) % size;
        if (key == originalKey) 
        {
            break;
        }
    }
    printf("%d not present in the hash table\n", value);
}

int main()
{
    init(); 

    insert(24);
    insert(52);
    insert(91);
    insert(67);
    insert(48);
    insert(83);
    insert(44);

    printf("Attempting to insert 30 into a full hash table...\n");
    insert(30);

    printf("Hash table after insertion:\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    printf("Searching value 91..\n");
    search(91);

    printf("Deleting value 52..\n");
    del(52);
    printf("After deletion, hash table:\n");
    print();

    printf("Re-inserting value 52..\n");
    insert(52);

    printf("Final state of the hash table:\n");
    print();

    return 0;
}
