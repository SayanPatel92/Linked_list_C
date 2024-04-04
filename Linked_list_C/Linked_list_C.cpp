#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;           // Data stored in the node.
    struct Node* next;  // Pointer to the next node in the list.
} Node;

// Function to create a new node
Node* createNode(int data) {
    // Allocate memory for a new node and initialize its data
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insert(Node** head, int data) {
    // Create a new node and make it the new head of the list
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtTail(Node** head, int data) {
    // Create a new node and append it to the end of the list
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific index in the linked list
void insertAtIndex(Node** head, int data, int index) {
    // Create a new node and insert it at the specified index
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) {
        insert(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL) {
            printf("Index out of range.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(Node** head, int data) {
    // Delete the node with the given data from the list
    Node* temp = *head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to update the value of a node
void updateNode(Node* head, int oldData, int newData) {
    // Update the data of the node with the given old data
    while (head != NULL) {
        if (head->data == oldData) {
            head->data = newData;
            return;
        }
        head = head->next;
    }
    printf("Element not found.\n");
}

// Function to get the value at a specific index
int getAtIndex(Node* head, int index) {
    // Return the data at the specified index in the list
    for (int i = 0; i < index; i++) {
        if (head == NULL) {
            printf("Index out of range.\n");
            exit(1);
        }
        head = head->next;
    }
    if (head == NULL) {
        printf("Index out of range.\n");
        exit(1);
    }
    return head->data;
}

// Function to print the linked list
void printList(Node* head) {
    // Print the data of each node in the list
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    // Free the memory allocated for each node in the list
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the linked list implementation
int main() {
    Node* head = NULL;

    // Inserting elements
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insertAtTail(&head, 40);
    insertAtIndex(&head, 25, 2);

    // Printing the list
    printf("Original List: ");
    printList(head);

    // Deleting an element
    deleteNode(&head, 30);
    printf("List after deletion: ");
    printList(head);

    // Updating an element
    updateNode(head, 20, 50);
    printf("List after updating: ");
    printList(head);

    // Getting value at index
    printf("Value at index 2: %d\n", getAtIndex(head, 2));

    // Freeing memory
    freeList(head);

    return 0;
}