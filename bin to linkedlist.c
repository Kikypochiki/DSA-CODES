#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverseCircularLinkedList(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        return;  // Empty list or single-node list
    }

    struct Node* current = *head, *prev = NULL, *next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    // Update the head pointer to the new head (the last node in the original list)
    *head = prev;
}

void printCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    // Create a circular linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = head;

    printf("Original circular linked list: ");
    printCircularLinkedList(head);

    reverseCircularLinkedList(&head);

    printf("Reversed circular linked list: ");
    printCircularLinkedList(head);

    return 0;
}
