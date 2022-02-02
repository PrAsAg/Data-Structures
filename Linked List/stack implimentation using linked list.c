#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <iomanip>

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
    printf("Enter a Data to add in Stack :: ");
    scanf("%d", &newpointer->data);
    newpointer->next = NULL;
    return newpointer;
}

void Push()
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

void Traverse()
{
    struct Node *pointer;
    pointer = head;
    if (head == NULL)
        printf("Stack Is Empty:::\n");
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

int main()
{
    int node;
    char choice;
    while (true)
    {
        printf("Please Enter::\n\t'1' for push to stack::\n\t'2' for pop from stack::\t\t");
        scanf("%d", &node);
        if (node == 1)
        {
            Push();
            printf("-----------------------------------Stack Condition-----------------------------------\n");
            Traverse();
            printf("-------------------------------------------------------------------------------------\n");
        }
        else
        {
            Pop();
            printf("-----------------------------------Stack Condition-----------------------------------\n");
            Traverse();
            printf("--------------------------------------------------------------------------------------\n");
        }
    }

    return 0;
}
