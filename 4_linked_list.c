// Program for Linked List :- Dynamic Memory Allocation i.e at runtime
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create();
void insert_first();
void insert_middle();
void insert_last();
void delete_first();
void delete_middle();
void delete_last();
void display();
struct node
    {
        int data;
        struct node *add;
    };struct node *start = NULL, *temp, *new1, *prev, *next;
void main()
    {
        int choice;
        do
        {
            printf("\n------------Linked List-------------");
            printf("\n 1. Create\n 2. Insert At First\n 3. Insert At Middle\n 4. Insert At Last\n 5. Delete At First\n 6. Delete At Middle\n 7. Delete at Last\n 8. Display\n 9. Exit");
            printf("\n------------------------------------");
            printf("\nEnter Your Choice:");
            scanf("%d", &choice);
            switch(choice)
                {
                    case 1: create(); break;
                    case 2: insert_first(); break;
                    case 3: insert_middle(); break;
                    case 4: insert_last(); break;
                    case 5: delete_first(); break;
                    case 6: delete_middle(); break;
                    case 7: delete_last(); break;
                    case 8: display(); break;
                    case 9: break;
                    default: printf("\nInvalid Choice!!!!!");
                }
        } while (choice != 9);
    }
void create()
    {
        int n;
        char ch;
        printf("\nEnter an Element:");
        scanf("%d", &n);
        // malloc returns void pointer so we have to explicitly change the pointer type into  struct node pointer type
        start = (struct node*)(malloc(sizeof(struct node)));
        start -> data = n;
        start -> add = NULL;    // -> is also a member acess operator usally using pointer
        temp = start;
        printf("\nWant To Continue(y/n):");
        ch = getche();
        while(ch == 'y' || ch == 'Y')
            {
                printf("\nEnter Next Element:");
                scanf("%d", &n);
                new1 = (struct node*)(malloc(sizeof(struct node)));
                new1 -> data = n;
                new1 -> add = NULL;
                temp -> add = new1;
                temp = temp -> add;
                printf("\nwant To Continue(y/n):");
                ch = getche();
            }
    }
void display()
    {
        if(start == NULL)
            printf("\nList Not Found!!!!!");
        else
            {
                temp = start;
                printf("\nList Elements are:");
                while(temp != NULL)                 // checking for temp add not temp->add for not skipping last element
                    {
                        printf("\t%d",temp -> data);
                        temp = temp -> add;
                    }
            }
    }
void insert_first()
    {
        int n;
        if(start == NULL)
            printf("\nList Not Found!!!!!");
        else
            {
                printf("\nEnter Element to Insert at First:");
                scanf("%d", &n);
                new1 = (struct node*)(malloc(sizeof(struct node)));
                new1 -> data = n;
                // new1 -> add = NULL;
                new1 -> add = start;
                start = new1;
            }
    }
void insert_last()
    {
        int n;
        if(start == NULL)
            printf("\nList Not Found!!!!");
        else
            {
                printf("\nEnter An Element To Insert At Last Of The List:");
                scanf("%d", &n);
                new1 = (struct node*)(malloc(sizeof(struct node)));
                new1 -> data = n;
                new1 -> add = NULL;
                temp = start;
                while(temp -> add != NULL)
                    {
                        temp = temp -> add;
                    }
                temp -> add = new1;
            }
    }
void insert_middle()
    {
        int n, pos, i = 1;
        if(start == NULL)
            printf("\nList Not Found!!!!!");
        else
            {
                printf("\nEnter An Element To Insert At %d Position: ", pos);
                scanf("%d", &n);
                new1 = (struct node*)(malloc(sizeof(struct node)));
                new1 -> data = n;
                new1 -> add = NULL;
                printf("\nEnter Position To Enter Element In The List:");
                scanf("%d", &pos);
                next = start;
                while(i < pos)
                    {
                        prev = next;
                        next = next -> add;
                        i++;
                    }
                prev -> add = new1;
                new1 -> add = next;
            }
    }
void delete_first()
    {
        if(start == NULL)
            printf("\nList Not Found!!!!!!!!");
        else
            {
                temp = start;
                start = start -> add;
                printf("\nDeleted Element is %d", temp -> data);
                free(temp);
            }
    }
void delete_last()
    {
        if(start == NULL)
            printf("\nList Not Found!!!!!!!!");
        else
            {
                temp = start;
                while(temp -> add != NULL)
                    {
                        prev = temp;
                        temp = temp -> add;
                    }
                prev -> add = NULL;
                printf("\nDeleted Element is %d", temp -> data);
                free(temp);
            }
    }
void delete_middle()
    {
        int pos, i = 1;
        if(start == NULL)
            printf("\nList Not Found!!!!!!");
        else
            {
                printf("\nEnter Position You want to Delete from The List:");
                scanf("%d", &pos);
                temp = start;
                while(i < pos)
                    {
                        prev = temp;
                        temp = temp -> add;
                        i++;
                    }
                next = temp -> add;
                prev -> add = next;
                printf("\nDeleted Element is: %d", temp -> data);
                free(temp);
            }
    }