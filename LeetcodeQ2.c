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

// Function to append a new node to the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, the new node becomes the head
    } else {
        struct Node* temp = *head;
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the new node to the last node
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    
    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Move head to the next node
        free(temp); // Free the old head node
        return;
    }

    // Search for the key to be deleted
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
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

// Function to search for a node with a given value
void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node with value %d found.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", key);
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Adding nodes to the list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Initial list: ");
    printList(head);

    // Search for a node
    searchNode(head, 20);
    searchNode(head, 50);

    // Delete a node
    printf("Deleting node with value 20...\n");
    deleteNode(&head, 20);
    printList(head);

    // Delete a node that's not in the list
    printf("Deleting node with value 50...\n");
    deleteNode(&head, 50);
    
    printf("Final list: ");
    printList(head);

    return 0;
}
