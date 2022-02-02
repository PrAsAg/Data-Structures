#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdbool.h>

struct Node //structure for list node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *last = NULL;

struct Node *getnode()
{
    struct Node *newpointer;
    newpointer = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a Data to add in Linked List :: ");
    scanf("%d", &newpointer->data);
    newpointer->next = NULL;
   // system("cls");
    return newpointer;
}

void PushBack()
{
    struct Node *newpointer;
    newpointer = getnode();
    if (head == NULL)
    {
        head = newpointer;
    }
    else
    {
        last->next = newpointer;
    }
    last = newpointer;
}

void PushFront()
{
    struct Node *newpointer;
    newpointer = getnode();
    newpointer->next = head;
    if(head == NULL)
        last = newpointer;
    head = newpointer;
}

void PushDefined(int node)
{
    struct Node *newpointer, *pointer;
    int count = 1;
    pointer = head;
    while (pointer != NULL)
    {
        count++;
        pointer = pointer->next;
        if (count == node)
            break;
    }
    //newpointer = getnode();
    if (pointer == NULL)
        printf("Such node cannot be created::::::\n");
    else
    {
        newpointer = getnode();
        newpointer->next = pointer->next;
        pointer->next = newpointer;
    }
}

void PopBack()
{
    struct Node *pointer, *previous_pointer;
    if (head == NULL)
        printf("Linked LIst is Empty !!!!!!!!\n");
    else
    {
        pointer = head;
        while (pointer->next != NULL)
        {
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        previous_pointer->next = NULL;
        free(pointer);
    }
}

void PopFront()
{
    struct Node *pointer;
    pointer = head;
    head = head->next;
    free(pointer);
}

void PopDefined(int node)
{
    struct Node *pointer, *previous_pointer;
    int count = 1;
    if (head == NULL)
        printf("Linked List is empty::::");
    else
    {
        pointer = head;
        while (pointer != NULL)
        {
            count++;
            previous_pointer = pointer;
            pointer = pointer->next;
            if (count == node)
                break;
        }
        if (pointer == NULL)
            printf("Such node isnot found::::::\n");
        else
        {
            previous_pointer->next = pointer->next;
            free(pointer);
        }
    }
}

void Traverse()
{
    struct Node *pointer;
    pointer = head;
    printf("------------------------------Traversing Linked List------------------------------\n");
    while (pointer != NULL)
    {

        printf("%d\t", pointer->data);
        pointer = pointer->next;
    }
    printf("\n----------------------------------------------------------------------------------\n\n");
    printf("\n");
}
void Getnode()
{
    int node;
    printf("Please enter node number to insert after node:::");
    scanf("%d", &node);
    PushDefined(node);
}

void delnode()
{
    int node;
    printf("Please enter node number to be deleted:::");
    scanf("%d", &node);
    PopDefined(node);
}
/*
SizeCount(){
    struct Node *pointer;
    int size=sizeof(struct node);
    pointer = head;
    while (pointer != NULL)
    {
        size+=sizeof(struct Node);

        pointer = pointer->next;
    }
    printf("Total Size is::::%d bytes",size);

}
*/
int main()
{

    int choice;
    while(true){
        printf("Please Enter Your Choice??\n");
        printf("\t1 - To Push front\n");
        printf("\t2 -To POP Front\n");
        printf("\t3 -To PUSH Back\n");
        printf("\t4 -To POP Back\n");
        printf("\t5 -To PUSH After Node\n");
        printf("\t6 -To POP NODE\n");

        scanf("%d",&choice);
        switch (choice){
            case 1:
                PushFront();
                //Traverse();
             break;
            case 2:
                PopFront();
                //Traverse();
                 break;
            case 3:
                PushBack();
                //Traverse();
                 break;
            case 4:
                PopBack();
               // Traverse();
                 break;
            case 5:
                Getnode();
               // Traverse();
                 break;
            case 6:
                delnode();
               // Traverse();
                 break;
            default:
                printf("Error input!!!!\n");
        }
        system("cls");
        Traverse();




    }









/*


    int node;
    printf("-----------------------------Creating Linked List------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        PushBack();
    }
    system("cls");
    printf("------------------------------Traversing Linked List------------------------------\n");
    Traverse();
    printf("----------------------------------------------------------------------------------\n\n");
    printf("------------------------------Push Front in Linked List------------------------------\n");
    PushFront();
    Traverse();
    printf("-------------------------------------------------------------------------------------\n\n");
    printf("------------------------------Push Back in Linked List----------------------------\n");
    PushBack();
    Traverse();
    printf("----------------------------------------------------------------------------------\n\n");
    printf("------------------------------Pop Front in Linked List------------------------------\n");
    PopFront();
    Traverse();
    printf("-------------------------------------------------------------------------------------\n\n");
    printf("------------------------------Pop Back in Linked List------------------------------\n");
    PopBack();
    Traverse();
    printf("-----------------------------------------------------------------------------------\n\n");
    printf("------------------------------Push Desired in Linked List------------------------------\n");

    printf("------------------------------Traversing in Linked List------------------------------\n");
    Traverse();
    printf("-------------------------------------------------------------------------------------\n\n");
    printf("------------------------------Pop Desired in Linked List------------------------------\n");

    printf("--------------------------Traversing in Linked List--------------------------\n");
    Traverse();
    printf("-----------------------------------------------------------------------------\n\n");

    //SizeCount();
*/
    return 0;
}
