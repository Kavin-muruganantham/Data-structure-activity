#include <stdio.h>
#include <stdlib.h>

// Definition for a singly linked list node
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

// Function to find the middle element of the linked list
void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* slow = head;
    struct Node* fast = head;

    // Traverse the list with slow and fast pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
    }

    // When the fast pointer reaches the end, slow pointer will be at the middle
    printf("The middle element is: %d\n", slow->data);
}

// Function to append a node at the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list (for testing)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    struct Node* head = NULL;

    // Append some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Linked list: ");
    printList(head);

    findMiddle(head);

    return 0;
}
