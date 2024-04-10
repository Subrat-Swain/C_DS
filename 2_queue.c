// Program For Static Queue Using Array
#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int rear = -1, front = 0;
void insert();
void delete1();
void display();
void temp();
void main()
    {
        int choice;
        do
        {
            printf("\n---------------Queue------------");
            printf("\n1.Insert\n2.Delete\n3.Display\n4.Temp\n5.Exit");
            printf("\n--------------------------------");
            printf("\nEnter Your Choice:");
            scanf("%d", &choice);
            switch(choice)
                {
                    case 1: insert(); break;
                    case 2: delete1(); break;   // delete is a keyword
                    case 3: display(); break;
                    case 4: temp(); break;
                    case 5: break;
                    default: printf("\nInvalid Choice");
                }
        } while (choice != 5);
    }
void insert()
    {
        int n;
        if(rear == MAXSIZE -1)  // condition for Queue overflow
            printf("\nQueue is overflow!!!");
        else
            {
                printf("\nEnter an element:");
                scanf("%d", &n);
                rear++;
                queue[rear] = n;
            }
    }
void delete1()  // Due to array it will not permanently delete
    {
        int n;
        if(front > rear)    // condtion for Queue is Empty
            printf("\nQueue is Empty!!!");
        else
            {
                n = queue[front];
                front++;
                printf("\nDeleted Element is: %d", n);
            }
    }
void display()
    {
        int i;
        if(front > rear)    // condtion for Queue is Empty
            printf("\nQueue is Empty!!!");
        else    
            {
                printf("\nQueue Elements are:");
                for(i = rear; i >= front; i--)
                    {
                        printf("%5d ",queue[i]);
                    }
            }
    }
void temp() // optional. checking static allocation of array
    {
        int i;
        printf("\nTemporary Queue is:");
        for(i = MAXSIZE-1; i >= 0; i--)
            {
                printf("%5d",queue[i]);
            }
    }