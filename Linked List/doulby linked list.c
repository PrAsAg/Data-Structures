#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *last;

struct Node *GetNewNode()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a Data to add in Linked List :: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void PushFront()
{
    struct Node *newNode;
    newNode = GetNewNode();
    if (head == NULL)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void PushBack()
{
    struct Node *pointer;
    struct Node *newNode;
    pointer = head;

    newNode = GetNewNode();
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        /*
        while (pointer->next != NULL)
            pointer = pointer->next; // Go To last Node
        pointer->next = newNode;
        newNode->prev = pointer;
        */
        last->next = newNode;
        newNode->prev = last;
    }
    last = newNode;
}

void PushAfterNode(int node)
{
    struct Node *pointer, *newNode;
    int count = 1;
    pointer = head;
    if (node == 1)
        goto bash;
    while (true)
    {
        pointer = pointer->next;
        count++;
        if (count == (node))
            break;
    }
    if (pointer->next == NULL)
    {
        PushBack();
        return NULL;
    }
bash:
    newNode = GetNewNode();
    pointer->next->prev = newNode;
    newNode->next = pointer->next;
    newNode->prev = pointer;
    pointer->next = newNode;
}
void PushBeforeNode(int node)
{
    struct Node *pointer, *newNode, *previous_node;
    int count = 1;
    pointer = head;
    if (node == 1)
    {
        PushFront();
        return NULL;
    }
    while (true)
    {
        previous_node = pointer;
        pointer = pointer->next;
        if ((pointer->next) == NULL)
        {
            printf("Such Node Cannot Be Added!!!!!!\n");
            return NULL;
        }

        count++;
        if (count == node)
            break;
    }
    newNode = GetNewNode();
    previous_node->next->prev = newNode;
    newNode->next = previous_node->next;
    previous_node->next = newNode;
    newNode->prev = previous_node;
}

void PopAfterNode(int node)
{
    struct Node *pointer;
    int count = 1;
    pointer = head;
    while (true)
    {
        pointer = pointer->next;
        count++;
        if (count == node)
            break;
        if (count > node)
        {
            printf("Node not Found!!!!\n");
            return NULL;
        }
    }
    pointer->next->next->prev = pointer;
    pointer->next = pointer->next->next;
    //pointer->next=pointer->next->next;
    //pointer->prev->next = pointer->next;
}

void PopBeforeNode(int node)
{

    int count = 1;
    struct Node *pointer;
    if (node == 1)
    {
        printf("Error!!!!");
        return NULL;
    }
    while (true)
    {
        pointer = pointer->next;
        count++;
        if (count == node)
            break;
    }
    pointer->prev->prev->next = pointer;
    pointer->prev = pointer->prev->prev;
}
void PopRequiredNode(int node)
{
    struct Node *pointer;
    int count = 1;
    if (node == 1)
    {
        PopFront();
        return NULL;
    }
    pointer = head;
    while (true)
    {
        pointer = pointer->next;
        count++;
        if (count == node)
            break;
        if (count > node)
        {
            printf("Node not Found!!!!\n");
            return NULL;
        }
    }

    pointer->next->prev = pointer->prev;
    pointer->prev->next = pointer->next;

    // pointer->next->next->prev = pointer;
    // pointer->next = pointer->next->next;
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
        last = previous_pointer;
        //pointer->prev->next=NULL;
        free(pointer);
    }
}

void PopFront()
{
    struct Node *pointer;
    pointer = head;
    head = head->next;
    head->prev = NULL;
    free(pointer);
}

void Traverse()
{
    struct Node *temp;
    temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReverseTraverse()
{
    struct Node *pointer;
    pointer = last;
    if (pointer == NULL)
        printf("Error\n");
    else
    {
        /*
        while (temp->next != NULL) //last node traversal
        {
            temp = temp->next;
        }

        */

        printf("Reverse: ");
        while (pointer != NULL)
        {
            printf("%d\t", pointer->data);
            pointer = pointer->prev; //traversing backward using prvv pointer
        }
    }
    printf("\n");
}

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
    ReverseTraverse();
    printf("----------------------------------------------------------------------------------\n\n");

    printf("------------------------------Push Front in Linked List------------------------------\n");
    PushFront();
    Traverse();
    ReverseTraverse();
    printf("-------------------------------------------------------------------------------------\n\n");

    printf("------------------------------Push Back in Linked List----------------------------\n");
    PushBack();
    Traverse();
    ReverseTraverse();
    printf("----------------------------------------------------------------------------------\n\n");

    printf("------------------------------Pop Front in Linked List------------------------------\n");
    PopFront();
    Traverse();
    ReverseTraverse();
    printf("-------------------------------------------------------------------------------------\n\n");

    printf("------------------------------Pop Back in Linked List------------------------------\n");
    PopBack();
    Traverse();
    ReverseTraverse();
    printf("-----------------------------------------------------------------------------------\n\n");

    printf("------------------------------Push After Desired Node in Linked List------------------------------\n");
    printf("Please enter node number to insert after node:::");
    scanf("%d", &node);
    PushAfterNode(node);
    printf("------------------------------Traversing in Linked List------------------------------\n");
    Traverse();
    ReverseTraverse();
    printf("-------------------------------------------------------------------------------------\n\n");

    printf("------------------------------Push Before Desired Node in Linked List------------------------------\n");
    printf("Please enter node number to insert before node:::");
    scanf("%d", &node);
    PushBeforeNode(node);
    printf("------------------------------Traversing in Linked List------------------------------\n");
    Traverse();
    ReverseTraverse();
    printf("---------------------------------------------------------------------------------------------------\n\n");

    printf("------------------------------Pop After Desired Node  in Linked List------------------------------\n");
    printf("Please enter node number after to be deleted:::");
    scanf("%d", &node);
    PopAfterNode(node);
    printf("--------------------------Traversing in Linked List--------------------------\n");
    Traverse();
    ReverseTraverse();
    printf("---------------------------------------------------------------------------------------------------\n\n");

    printf("------------------------------Pop  Desired Node in Linked List------------------------------\n");
    printf("Please enter node number to be deleted:::");
    scanf("%d", &node);
    PopRequiredNode(node);
    printf("--------------------------Traversing in Linked List--------------------------\n");
    Traverse();
    ReverseTraverse();
    printf("---------------------------------------------------------------------------------------------\n\n");

    // printf("------------------------------Pop Before Desired Node Desired in Linked List------------------------------\n");
    // printf("Please enter node number before to be deleted:::");
    // scanf("%d", &node);
    // PopBeforeNode(node);
    // printf("--------------------------Traversing in Linked List--------------------------\n");
    // Traverse();
    // ReverseTraverse();
    // printf("--------------------------------------------------------------------------------------------------------\n\n");

    //SizeCount();

    return 0;
}
