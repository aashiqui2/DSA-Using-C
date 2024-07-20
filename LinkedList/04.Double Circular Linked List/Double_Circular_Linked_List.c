#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *head = NULL;

void insertAtBeginning(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        node *tail = head->prev;
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }
    printf("Inserted %d at the beginning\n", val);
}

void insertAtEnd(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        node *tail = head->prev;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
    printf("Inserted %d at the end\n", val);
}

void insertAtPos(int pos, int val)
{
    if (pos == 0)
    {
        insertAtBeginning(val);
        return;
    }

    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;

    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    printf("Inserted %d at pos %d\n", val, pos);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    printf("Elements in the list are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head->prev;
    printf("Elements in the list from end are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node *tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
    printf("Node deleted at beginning\n");
}

void delete_end()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head->prev;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = head;
        head->prev = temp->prev;
    }
    free(temp);
    printf("Node deleted at end\n");
}

void deleteFromPos(int pos)
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head;
    if (pos == 0)
    {
        delete_begin();
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

int search(int val)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = head;
    int pos = 0;
    do
    {
        if (temp->data == val)
        {
            printf("Value %d found at position %d\n", val, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value %d not found in the list\n", val);
    return -1;
}

int length()
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 0;
    node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\n --------Linked List Menu-----------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at specified position\n");
        printf("4. Display the list\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete from specified position\n");
        printf("8. Search for a value\n");
        printf("9. Get the length of the list\n");
        printf("10. Display the list from end\n");
        printf("11. Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtBeginning(val);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtPos(pos, val);
            break;
        case 4:
            display();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteFromPos(pos);
            break;
        case 8:
            printf("Enter the value to search for: ");
            scanf("%d", &val);
            search(val);
            break;
        case 9:
            printf("Length of the list is %d\n", length());
            break;
        case 10:
            displayFromEnd();
            break;
        case 11:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}
