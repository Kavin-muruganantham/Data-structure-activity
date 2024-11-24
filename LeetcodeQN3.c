#include <stdio.h>
#include <stdlib.h>

// Definition for singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int position, int data) {
    struct Node* newNode = createNode(data);

    if (position == 1) { // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Inserting at the end.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Save next
        current->next = prev;  // Reverse the current node
        prev = current;        // Move prev one step ahead
        current = next;        // Move current one step ahead
    }
    *head = prev; // Update head to the new front
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;

    // Inserting nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("List after inserting at the beginning: ");
    printList(head);

    insertAtPosition(&head, 2, 25);
    printf("List after inserting 25 at position 2: ");
    printList(head);

    insertAtPosition(&head, 5, 5);
    printf("List after inserting 5 at position 5: ");
    printList(head);

    // Reversing the linked list
    printf("Reversing the list...\n");
    reverseList(&head);
    printf("Reversed list: ");
    printList(head);

    return 0;
}
