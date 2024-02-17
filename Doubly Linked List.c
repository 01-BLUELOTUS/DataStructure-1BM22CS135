#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    printf("Node inserted.\n");
}

void insertLeft(Node** head, int data, int value)
{
    Node* newNode = createNode(data);
    if(*head == NULL)
    {
        printf("List is empty");
        return;
    }
    Node* temp = *head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found in the list.\n");
        return;
    }
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL)
    {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
    if (temp == *head)
    {
        *head = newNode;
    }

    printf("Node inserted.\n");
}


void deleteNode(Node** head, int value)
{
    Node* temp = *head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found in the list.\n");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node deleted.\n");
}

void display(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* head = NULL;
    int option, data, value;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Insert Node at Front");
        printf("\n 2: Insert Node to the left of the node");
        printf("\n 3: Delete Node based on Value");
        printf("\n 4: Display List");
        printf("\n 5: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nEnter data : ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d",&data);
                printf("Enter the value to which the data has to be insert: ");
                scanf("%d",&value);
                insertLeft(&head,data,value);
                break;
            case 3:
                if (head == NULL)
                {
                    printf("List is empty. Cannot delete.\n");
                } else
                {
                    printf("\nEnter value of the node to be deleted: ");
                    scanf("%d", &value);
                    deleteNode(&head, value);
                }
                break;
            case 4:
                display(head);
                break;
            case 5:
                while (head != NULL)
                {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    } while (option != 5);

    return 0;
}
