#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define size 100

char stack[size];
int top=-1;

void push(char value);
char pop();
int precedence(char operators);

int main()
{
    char infix[size],postfix[size],character;
    int i=0,k=0;
    push('#');
    printf("Enter the Infix Expression:\n");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        character=infix[i++];
        if(character=='(')
        {
            push(character);
        }
        else if(isalnum(character))
        {
            postfix[k++]=character;
        }
        else if(character==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
            }
            char open=pop();
        }
        else if(character=='+'||character=='-'||character=='*'||character=='/'||character=='^')
        {
            while(precedence(character)<precedence(stack[top])||precedence(character)==precedence(stack[top])&&stack[top]!='^')
            {
                postfix[k++]=pop();
            }
            push(character);
        }
        else
        {
            printf("Please enter a valid expression of only operands and operators");
            return 0;
        }
    }
    while(stack[top]!='#')
    {
        postfix[k++]=pop();

    }
    postfix[k]='\0';
    printf("\n\nPostfix Expression: %s",postfix);
    return 0;
}

void push(char value)
{
    stack[++top]=value;
}

char pop()
{
    return stack[top--];
}

int precedence(char operators)
{
    if(operators=='^')
        return 3;
    else if (operators=='/'||operators=='*')
        return 2;
    else if(operators=='+'||operators=='-')
        return 1;
    else
        return 0;
}
