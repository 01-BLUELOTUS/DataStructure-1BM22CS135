#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;


Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("head\n");
}

Node* insertAtFront(Node* head, int value)
{
    Node* newNode = createNode(value);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;

    return head;
}

Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    return newNode;
}

Node* insertAtPosition(Node* head, int value, int position)
{
    Node* newNode = createNode(value);

    if (head == NULL && position != 1)
    {
        printf("Invalid position for an empty list.\n");
        return head;
    }

    if (position == 1)
    {
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != head; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* deleteAtFront(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return NULL;
    }

    Node* temp = head->next;
    if (temp == head)
    {
        free(temp);
        return NULL;
    }

    head->next = temp->next;
    free(temp);
    return head;
}

Node* deleteAtEnd(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return NULL;
    }

    Node* current = head;
    while (current->next->next != head)
    {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = head;
    free(temp);
    return head;
}

Node* deleteAtPosition(Node* head, int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return NULL;
    }

    if (position == 1)
    {
        Node* temp = head->next;
        if (temp == head)
        {
            free(temp);
            return NULL;
        }

        head->next = temp->next;
        free(temp);
        return head;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }

    if (current->next == head)
    {
        printf("Invalid position to delete.\n");
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void freeList(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    Node* current = head->next;
    while (current != head)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
}

int main()
{
    Node* head = NULL;
    int choice, value, position;

    do
    {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at any position\n");
        printf("5. Delete at the front\n");
        printf("6. Delete at the end\n");
        printf("7. Delete at any position\n");
        printf("8. Display the linked list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (head != NULL)
                {
                    freeList(head);
                }
                head = createNode(0);
                printf("Linked list created.\n");
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtFront(head, value);
                printf("Node inserted at the beginning.\n");
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printf("Node inserted at the end.\n");
                break;

            case 4:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                printf("Node inserted at position %d.\n", position);
                break;

            case 5:
                head = deleteAtFront(head);
                printf("Node deleted from the front.\n");
                break;

            case 6:
                head = deleteAtEnd(head);
                printf("Node deleted from the end.\n");
                break;

            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                printf("Node deleted from position %d.\n", position);
                break;

            case 8:
                displayList(head);
                break;

            case 0:
                freeList(head);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return;
}
