#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
} Node;

 Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head)
{
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* insertAtBeginning(Node* head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data)
{
    Node* newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    return head;
}


Node* insertAfterNode(Node* head, int data, int afterData)
{
    Node* newNode = createNode(data);
    Node* current = head;

    while (current != NULL && current->data != afterData)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with data %d not found.\n", afterData);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}


Node* insertBeforeNode(Node* head, int data, int beforeData)
{
    Node* newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    if (head->data == beforeData)
    {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->data != beforeData)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with data %d not found.\n", beforeData);
        free(newNode);
        return head;
    }

    prev->next = newNode;
    newNode->next = current;

    return head;
}

Node* insertAtPosition(Node* head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1)
    {
        return insertAtBeginning(head, data);
    }

    Node* newNode = createNode(data);
    Node* current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}


Node* deleteFirstNode(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}


Node* deleteLastNode(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);

    return head;
}


Node* deleteAfterNode(Node* head, int afterData)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    Node* current = head;

    while (current != NULL && current->data != afterData)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Node with data %d not found or no node after it.\n", afterData);
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);

     return head;
}

int main()
{
    Node* head = NULL;
    int option, data, afterData, beforeData, position;
    int listCreated = 0;

    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Insert at the beginning");
        printf("\n 4: Insert at the end");
        printf("\n 5: Insert after a given node");
        printf("\n 6: Insert before a given node");
        printf("\n 7: Insert at any position");
        printf("\n 8: Delete the first node");
        printf("\n 9: Delete the last node");
        printf("\n 10: Delete the node after a given node");
        printf("\n 11: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

           switch (option)
           {
            case 1:
                head = createNode(0);
                head->next = NULL;
                listCreated = 1;
                printf("\nLinked List Created");
                break;
            case 2:
                if (listCreated)
                    displayList(head->next);
                else
                    printf("\nLinked List not created yet.");
                break;
            case 3:
                if (listCreated)
                {
                    printf("\nEnter data to insert at the beginning: ");
                    scanf("%d", &data);
                    head->next = insertAtBeginning(head->next, data);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 4:
                if (listCreated)
                {
                    printf("\nEnter data to insert at the end: ");
                    scanf("%d", &data);
                    head->next = insertAtEnd(head->next, data);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 5:
                if (listCreated)
                {
                    printf("\nEnter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter the value after which to insert: ");
                    scanf("%d", &afterData);
                    head->next = insertAfterNode(head->next, data, afterData);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 6:
                if (listCreated)
                {
                    printf("\nEnter data to insert: ");
                     scanf("%d", &data);
                    printf("Enter the value before which to insert: ");
                    scanf("%d", &beforeData);
                    head->next = insertBeforeNode(head->next, data, beforeData);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 7:
                if (listCreated)
                {
                    printf("\nEnter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter the position at which to insert: ");
                    scanf("%d", &position);
                    head->next = insertAtPosition(head->next, data, position);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 8:
                if (listCreated)
                {
                    head->next = deleteFirstNode(head->next);
                    printf("\nFirst Node Deleted");
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 9:
                if (listCreated)
                {
                    head->next = deleteLastNode(head->next);
                    printf("\nLast Node Deleted");
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 10:
                if (listCreated)
                {
                    printf("\nEnter the value after which to delete: ");
                    scanf("%d", &afterData);
                    head->next = deleteAfterNode(head->next, afterData);
                } else
                {
                    printf("\nLinked List not created yet.");
                }
                break;
            case 11:
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    } while (option != 11);


    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
