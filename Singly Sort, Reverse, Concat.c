#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

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

void display(Node* head)
{
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* insertAtEnd(Node* head, int data)
{
    Node* newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

Node* reverse(Node* head)
{
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

Node* concat(Node* L1, Node* L2)
{
    if (L1 != NULL && L2 != NULL)
    {
        Node* temp = L1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = L2;
    }
    else
    {
        printf("Either L1 or L2 is NULL\n");
    }
    return L1;
}


int main()
{
    Node* L1 = NULL;
    Node* L2 = NULL;
    int option, data;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create List 1");
        printf("\n 2: Create List 2");
        printf("\n 3: Display List 1");
        printf("\n 4: Display List 2");
        printf("\n 5: Reverse List 1");
        printf("\n 6: Concatenate List 1 and List 2");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter data for List 1: ");
            scanf("%d", &data);
            L1 = insertAtEnd(L1, data);
            break;
        case 2:
            printf("\nEnter data for List 2: ");
            scanf("%d", &data);
            L2 = insertAtEnd(L2, data);
            break;
        case 3:
            display(L1);
            break;
        case 4:
            display(L2);
            break;
        case 5:
            L1 = reverse(L1);
            printf("\nList 1 reversed.\n");
            break;
        case 6:
            L1 = concat(L1, L2);
            printf("\nLists concatenated.\n");
            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid option.\n");
        }
    } while (option != 7);

    while (L1 != NULL)
    {
        Node* temp = L1;
        L1 = L1->next;
        free(temp);
    }

    while (L2 != NULL)
    {
        Node* temp = L2;
        L2 = L2->next;
        free(temp);
    }

    return 0;
}
