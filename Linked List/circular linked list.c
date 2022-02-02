#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
        newpointer->next=head;
    }
    last = newpointer;
}

void PushFront()
{
    struct Node *newpointer;
    newpointer = getnode();
    newpointer->next = head;
    head = newpointer;
    last->next=head;
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
        while (pointer->next != head)
        {
            previous_pointer = pointer;
            pointer = pointer->next;
        }
        previous_pointer->next = head;
        free(pointer);
    }
}

void PopFront()
{
    struct Node *pointer;
    pointer = head;
    head = head->next;
    last->next=head;
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
    do
    {
        printf("%d\t", pointer->data);
        pointer = pointer->next;
    }while(pointer->next!=head);
    printf("\n");
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
    printf("Please enter node number to insert after node:::");
    scanf("%d", &node);
    PushDefined(node);
    printf("------------------------------Traversing in Linked List------------------------------\n");
    Traverse();
    printf("-------------------------------------------------------------------------------------\n\n");
    printf("------------------------------Pop Desired in Linked List------------------------------\n");
    printf("Please enter node number to be deleted:::");
    scanf("%d", &node);
    PopDefined(node);
    printf("--------------------------Traversing in Linked List--------------------------\n");
    Traverse();
    printf("-----------------------------------------------------------------------------\n\n");

    //SizeCount();

    return 0;
}
