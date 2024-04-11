// Implementation of Cicular Queue by using Array:- Static
#include<stdio.h>
#define MAXSIZE 10
int cq[MAXSIZE], rear = -1, front = -1;
void insert();
void delete1();
void display();
void temp();
void main()
    {
        int choice;
        do
        {
            printf("\n--------------Circular Queue----------");
            printf("\n1.Insert\n2.Delete\n3.Display\n4.Temp\n5.Exit");
            printf("\n--------------------------------------");
            printf("\nEnter Your Choice:");
            scanf("%d", &choice);
            switch(choice)
                {
                    case 1: insert(); break;
                    case 2: delete1(); break;
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
        if((rear + 1) % MAXSIZE == front) // circular queue overflow condition
            printf("\nQueue Is Overflow!!!");
        else
            {
                printf("\nEnter an Element:");
                scanf("%d", &n);
                if(front == -1 && rear == -1)
                    {
                        front = 0;
                        rear = 0;
                    }
                else
                    rear = (rear + 1) % MAXSIZE;
                cq[rear] = n;
            }
    }
void delete1()
    {
        int n;
        if(front == -1 && rear == -1) // Circular Queue Empty condition
            printf("\nQueue is Empty!!!");
        else
            {
                n = cq[front];
                if(rear == front)
                    {
                        rear = -1;
                        front = -1;
                    }
                else
                    front = (front + 1) % MAXSIZE;
                printf("\nDeleted Element Is : %d", n);
            }
    }
void display()
    {
        int i;
        if(front == -1 && rear == -1)
            printf("\nQueue is Empty!!!");
        else
            {
                printf("\nQueue Elements are:");
                for(i = front; i != rear; i = (i +1) % MAXSIZE)
                    {
                        printf("%5d", cq[i]);
                    }
                printf("%5d", cq[i]);
            }
    }
void temp()
    {
        int i;
        printf("\nTemporary Queue is: ");
        for(i = MAXSIZE - 1; i >= 0; i--)
            {
                printf("%5d", cq[i]);
            }
    }