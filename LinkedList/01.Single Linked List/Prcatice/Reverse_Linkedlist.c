#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *push(Node *head, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = head;
    return newnode;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node *revereseLinkedList(Node *head)
{
    Node *prev=NULL;
    Node *temp=head;
    Node *next=NULL;

    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}

int main() 
{
    Node *head = NULL;
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    printf("Original linked list:\n");
    printList(head);

    printf("Reversed linked list:\n");
    head = revereseLinkedList(head);
    printList(head);

    return 0;
}