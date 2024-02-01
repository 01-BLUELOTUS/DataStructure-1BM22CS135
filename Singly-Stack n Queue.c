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

void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* push(Node* top, int data)
{
    Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top)
{
    if (top == NULL)
    {
        printf("Stack underflow.\n");
        return NULL;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

Node* enqueue(Node* rear, int data)
{
    Node* newNode = createNode(data);
    if (rear == NULL)
    {
        return newNode;
    }
    rear->next = newNode;
    return newNode;
}

Node* dequeue(Node* front)
{
    if (front == NULL)
    {
        printf("Queue underflow.\n");
        return NULL;
    }
    Node* temp = front;
    front = front->next;
    free(temp);
    return front;
}

int main() {
    Node* Top = NULL;
    Node* Front = NULL;
    Node* Rear = NULL;

    int option, data;

    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Push onto Stack");
        printf("\n 2: Pop from Stack");
        printf("\n 3: Enqueue into Queue");
        printf("\n 4: Dequeue from Queue");
        printf("\n 5: Display Stack");
        printf("\n 6: Display Queue");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter data to push onto stack: ");
                scanf("%d", &data);
                Top = push(Top, data);
                break;
            case 2:
                Top = pop(Top);
                printf("Stack after pop: ");
                display(Top);
                break;
            case 3:
                printf("Enter data to enqueue into queue: ");
                scanf("%d", &data);
                Rear = enqueue(Rear, data);
                if (Front == NULL) {
                    Front = Rear;
                }
                break;
            case 4:
                Front = dequeue(Front);
                printf("Queue after dequeue: ");
                display(Front);
                break;
            case 5:
                printf("Stack: ");
                display(Top);
                break;
            case 6:
                printf("Queue: ");
                display(Front);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    } while (option != 7);


    while (Top != NULL)
    {
        Node* temp = Top;
        Top = Top->next;
        free(temp);
    }

    while (Front != NULL)
    {
        Node* temp = Front;
        Front = Front->next;
        free(temp);
    }

    return 0;
}

