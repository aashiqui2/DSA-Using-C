#include <stdio.h>
#include <stdlib.h>

// Definition of the singly linked list node using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to reverse the linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    
    head = prev;
    return head;
}

// Utility function to push a new node at the beginning
Node* push(Node* head, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = head;  // Make new node point to the current head
    return new_node;        // Return the new head
}

// Utility function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the reverse function
int main() {
    Node* head = NULL;
    
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    head = push(head, 5);  // Update head with the new node
    head = push(head, 4);  // Update head with the new node
    head = push(head, 3);  // Update head with the new node
    head = push(head, 2);  // Update head with the new node
    head = push(head, 1);  // Update head with the new node
    
    printf("Original linked list:\n");
    printList(head);  // Pass head to traverse the list
    
    head = reverseLinkedList(head);  // Pass head to modify the list
    
    printf("Reversed linked list:\n");
    printList(head);  // Pass head to traverse the list
    
    return 0;
}
