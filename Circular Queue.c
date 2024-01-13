#include <stdio.h>
#include <conio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete_element(void);
void display(void);

int main()
{
    int option, val;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Display the queue");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != -1)
                printf("\n The number deleted is : %d", val);
            break;
        case 3:
            display();
            break;
        }
    } while (option != 4);
    getch();
    return 0;
}

void insert()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQUEUE OVERFLOW!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = num;
    }
}

int delete_element()
{
    int val;
    if (front == -1)
    {
        printf("\nQUEUE UNDERFLOW");
        return -1;
    }
    else
    {
        val = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return val;
    }
}

void display()
{
    int i = front;
    if (front == -1)
        printf("\nQUEUE UNDERFLOW");
    else
    {
        printf("\nFRONT: %d", front);
        printf("\nTHE QUEUE IS:");
        do
        {
            printf("\t %d", queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
        printf("REAR: %d", rear);
    }
}
