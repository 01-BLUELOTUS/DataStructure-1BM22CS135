#include<stdio.h>
#include<stdlib.h>

#define  MAX 50
#define MAXTAB 10

typedef struct
{
    int key;
}emp;

typedef struct
{
    int key;
}tableEntry;

int hashfun(int key)
{
    return key%MAXTAB ;
}

void linearProbing(emp employee[], tableEntry table[], int key)
{

    int index = hashfun(key);
    while(table[index].key!=-1)
    {
        index = (index+1)%MAXTAB;
    }
    table[index].key = key;
 }

void quadraticProbing(emp employee[], tableEntry table[],int key)
{
    int index = hashfun(key);
    int i=1;
    while(table[index].key!=-1)
    {
        index = (index+ i + (i*i))%MAXTAB;
        i++ ;
    }
    table[index].key = key;
}

void doubleHashing(emp employee[], tableEntry table[],int key)
{
    int index = hashfun(key);
    int i=1;
    int hash2 = (MAXTAB-2) - key % (MAXTAB-2);
    while(table[index].key!=-1)
    {
        index = (index+hash2*1)%MAXTAB;
        i++ ;
    }
    table[index].key = key;
}

void print(tableEntry table[])
{
    for (int i = 0;i<MAXTAB;i++)
    {
        if(table[i].key!=-1)
        {
            printf("Hash: %d, key: %d\n",i,table[i].key);
        }
     }
 }

int main()
{
    emp employee[MAXTAB];
    tableEntry table[MAXTAB];
    int num;
    for(int i = 0;i<MAXTAB;i++)
    {
        table[i].key = -1;
    }
    printf("--------------------------------------------\n");
    printf("Linear Probing Collision Technique\n");
    printf("Enter the Number of Employees: ");
    scanf("%d",&num);
    for(int i = 0;i<num;i++)
    {
        printf("Enter the ID of %d employee ",(i+1));
        scanf("%d",&employee[i].key);
        linearProbing(employee, table, employee[i].key);
    }
    printf("The Linear Probing Hashing Table:\n");
    print(table);
    printf("\n");
    printf("--------------------------------------------\n");
    printf("Quadratic Probing Collision Technique\n");
    printf("Enter the Number of Employees: ");
    scanf("%d",&num);
    for(int i = 0;i<num;i++)
    {
        printf("Enter the ID of %d employee ",(i+1));
        scanf("%d",&employee[i].key);
        quadraticProbing(employee, table, employee[i].key);
    }
    printf("The Quadratic Probing Hashing Table:\n");
    print(table);
    printf("\n");
    printf("--------------------------------------------\n");
    printf("Double Hashing Collision Technique\n");
    printf("Enter the Number of Employees: ");
    scanf("%d",&num);
    for(int i = 0;i<num;i++)
    {
        printf("Enter the ID of %d employee ",(i+1));
        scanf("%d",&employee[i].key);
        doubleHashing(employee, table, employee[i].key);
    }
    printf("The Linear Probing Hashing Table:\n");
    print(table);
    printf("\n");
    printf("--------------------------------------------\n");

    return 0;
}
