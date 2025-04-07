#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int value);
void insertEnd(Node** head, int value);
void printList(Node* head);
void deleteValue(Node** head, int value);
Node* search(Node* head, int value);
void updateValue(Node* head, int oldValue, int newValue);
int getNth(Node* head, int n);
int sumValues(Node* head);

// Create a node with a value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete node with a given value
void deleteValue(Node** head, int value) {
    Node* temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Not found

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Search for a value
Node* search(Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

// Update value
void updateValue(Node* head, int oldValue, int newValue) {
    Node* target = search(head, oldValue);
    if (target != NULL)
        target->data = newValue;
}

// Get nth element (0-based index)
int getNth(Node* head, int n) {
    int index = 0;
    while (head != NULL) {
        if (index == n)
            return head->data;
        head = head->next;
        index++;
    }
    return -1; // Not found
}

// Sum all node values
int sumValues(Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

// Main function
int main() {
    Node* head = NULL;

    // 1. Create list with values 1 to 10
    for (int i = 1; i <= 10; i++)
        insertEnd(&head, i);
    printf("Initial list:\n");
    printList(head);

    // 2. Insert 50 at the end
    insertEnd(&head, 50);
    printf("After inserting 50 at the end:\n");
    printList(head);

    // 3. Delete value 5
    deleteValue(&head, 5);
    printf("After deleting 5:\n");
    printList(head);

    // 4. Search for a value (e.g., 7)
    int val = 7;
    Node* found = search(head, val);
    if (found)
        printf("Value %d found in the list.\n", val);
    else
        printf("Value %d not found in the list.\n", val);

    // 5. Update value 3 to 77
    updateValue(head, 3, 77);
    printf("After updating 3 to 77:\n");
    printList(head);

    // 6. Access nth item (e.g., 4th)
    int n = 4;
    int nthValue = getNth(head, n);
    if (nthValue != -1)
        printf("The %d-th item is: %d\n", n, nthValue);
    else
        printf("Invalid index %d.\n", n);

    // 7. Sum of all values
    int total = sumValues(head);
    printf("Sum of all node values: %d\n", total);

    return 0;
}
