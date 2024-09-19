#include <stdio.h>
#define size 10
int arr[size];

// to avoid garbage value
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
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already!\n", key, arr[key]);
        printf("Unable to insert %d\n", value);
    }
}

void print()
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n", value);
}

int main()
{
    // Key (24,52,91,67,48,83)
    init();
    insert(24);
    insert(52);
    insert(91);
    insert(67);
    insert(48);
    insert(83);
    printf("Hash table\n");
    print();
    printf("\n");

    printf("Deleting value ..\n");
    del(91);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    return 0;
}