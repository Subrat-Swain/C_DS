#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top = -1;
void push();
void pop();
void display();
void temp();
void main()
    {
        int choice;
        do
        {
            printf("\n------------Stack---------------");
            printf("\n1.Push\n2.Pop\n3.Display\n4.Temp\n5.Exit");
            printf("\n--------------------------------");
            printf("\nEnter Your Choice:");
            scanf("%d", &choice);
            switch(choice)
                {
                    case 1: push(); break;
                    case 2: pop(); break;
                    case 3: display(); break;
                    case 4: temp(); break;  // used for checking static allocation only
                    case 5: break;
                    default: printf("\nInvalid Choice");
                }
        } while (choice != 5);
    }
void push()
    {
        int n;
        if(top == MAXSIZE - 1)  // condition for stack overflow due to background data structure is array
            printf("\nStack is Overflow!!!!!");
        else
            {
                printf("\nEnter an Element:");
                scanf("%d", &n);
                top++;
                stack[top] = n;
            }
    }
void pop()
    {
        int n;
        if(top == -1)   // condition for stack is empty
            printf("\nStack Is Empty!!!!!");
        else
            {
                n = stack[top];
                top--;
                printf("\nPoped Element is:%d",n);
            }
    }
void display()
    {
        int i;
        if(top == -1)
            printf("\nStack is Empty!!!!");
        else    
            {
                printf("\nStack Elements are:");
                for(i = top; i >= 0; i--)
                    {
                        printf("\n%5d  ",stack[i]);
                    }
            }
    }
void temp() // Checking poped elements are permanent removed or not i.e static or not
    {
        int i;
        printf("\nTemporary Stack is:");
        for(i = 0; i <= MAXSIZE-1; i++)
            {
                printf("\n%5d",stack[i]);
            }
    }