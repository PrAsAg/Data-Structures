#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

struct Node //structure for list node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *last;

struct Node *getnode()
{
    struct Node *newpointer;
    newpointer = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a Data to add in Queue :: ");
    scanf("%d", &newpointer->data);
    newpointer->next = NULL;
    return newpointer;
}

void Enqueue()
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
    system("cls");
}
/*
void PushFront()
{
    struct Node *newpointer;
    newpointer = getnode();
    newpointer->next = head;
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
*/

/*
void Pop()
{
    struct Node *pointer, *previous_pointer;
    if (head == NULL)
        printf("Stack is Empty !!!!!!!!\n");
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
        system("cls");
    }
}

*/

void Dequeue()
{
    struct Node *pointer;
    pointer = head;
    head = head->next;
    free(pointer);
    system("cls");
}

/*
PopDefined(int node)
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


*/
void Traverse()
{
    struct Node *pointer;
    pointer = head;
    if (head == NULL)
        printf("Queue Is Empty:::\n");
    else
    {
        while (pointer != NULL)
        {
            printf("%d\t", pointer->data);
            pointer = pointer->next;
        }
        printf("\n");
    }
}
/*
SizeCount(){
    struct Node *pointer;
    int size=0;
    pointer = head;
    while (pointer != NULL)
    {
        size+=sizeof(struct Node);

        pointer = pointer->next;
    }
    printf("Total Size is::::%d",size);

}
*/
int main()
{
    int node;
    char choice;
    while (true)
    {
        printf("Please Enter::\n\t'1' for Enqueue to Queue::\n\t'2' for Dequeue from Queue::\t\t");
        scanf("%d", &node);
        if (node == 1)
        {
            Enqueue();
            printf("-----------------------------------Queue Condition-----------------------------------\n");
            Traverse();
            printf("-------------------------------------------------------------------------------------\n");
        }
        else
        {
            Dequeue();
            printf("-----------------------------------Queue Condition-----------------------------------\n");
            Traverse();
            printf("--------------------------------------------------------------------------------------\n");
        }
    }
    /*
    printf("-------------------------Traversing Linked List-------------------------\n");
    Traverse();
    printf("-------------------------Push Front in Linked List-------------------------\n");
    PushFront();
    Traverse();
    printf("-------------------------Push Back in Linked List-----------------------\n");
    PushBack();
    Traverse();
    printf("-------------------------Pop Front in Linked List-------------------------\n");
    PopFront();
    Traverse();
    printf("-------------------------Pop Back in Linked List-------------------------\n");
    PopBack();
    Traverse();
    printf("-------------------------Push Desired in Linked List-------------------------\n");
    printf("Please enter node number to insert after node:::");
    scanf("%d", &node);
    PushDefined(node);
    printf("-------------------------Traversing in Linked List-------------------------\n");
    Traverse();
    printf("-------------------------Push Desired in Linked List-------------------------\n");
    printf("Please enter node number to be deleted:::");
    scanf("%d", &node);
    PopDefined(node);
    printf("---------------------Traversing in Linked List---------------------\n");
    Traverse();
    */
    //SizeCount();

    return 0;
}
