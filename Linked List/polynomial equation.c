#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

//structure for list node
struct Node
{
    int power;
    int coefficient;
    struct Node *next;
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *head3 = NULL;
struct Node *last1;
struct Node *last2;
struct Node *last3;

//pointer type function for polynomial equation  1 and 2 to insert power and coefficient  to respective;
struct Node *getnode()
{
    struct Node *newpointer;
    newpointer = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Power :: ");
    scanf("%d", &newpointer->power);
    printf("Enter Coefficient:: ");
    scanf("%d", &newpointer->coefficient);
    newpointer->next = NULL;
    return newpointer;
}

//pointer type function for summed equation to insert power and coefficient  to respective;
struct Node *madenode(int power, int coefficient)
{
    struct Node *newpointer;
    newpointer = (struct Node *)malloc(sizeof(struct Node));
    newpointer->power = power;
    newpointer->coefficient = coefficient;
    newpointer->next = NULL;
    return newpointer;
}

//function to create third linked list i.e. summed polynomial equation;
void EnqueueThree(int power, int coefficient)
{
    struct Node *newpointer;
    newpointer = madenode(power, coefficient);
    if (head3 == NULL)
    {
        head3 = newpointer;
    }
    else
    {
        last3->next = newpointer;
    }
    last3 = newpointer;
    // system("cls");
}

/*

struct Node *create(struct Node *head)
{
    struct Node *newpointer, *pointer;
    do
    {
        newpointer = getnode();
        if (head == NULL)
        {
            head =newpointer;
        }
        else
        {
            pointer = head;
            while (pointer->next != NULL)
                pointer = pointer->next;
            pointer->next = newpointer;
        }
        printf("\nContinue?[y/n]\n");
    } while (getche() != 'n');
    return head;
}

*/

//function to link first polynomial equation;
void EnqueueOne()
{
    struct Node *newpointer;
    newpointer = getnode();
    if (head1 == NULL)
    {
        head1 = newpointer;
    }
    else
    {
        last1->next = newpointer;
    }
    last1 = newpointer;
    // system("cls");
}

//function to link second polynomial equation;
void EnqueueTwo()
{
    struct Node *newpointer;
    newpointer = getnode();
    if (head2 == NULL)
    {
        head2 = newpointer;
    }
    else
    {
        last2->next = newpointer;
    }
    last2 = newpointer;
    // system("cls");
}

//function to traverse linked lists;
void Traverse(struct Node *head)
{
    struct Node *pointer;
    pointer = head;
    if (head == NULL)
        printf("Queue Is Empty:::\n");
    else
    {
        while (pointer != NULL)
        {
            printf("%dX^%d + ", pointer->coefficient, pointer->power);
            pointer = pointer->next;
        }
        printf("\n");
    }
}

// function to add parameters in ploynomial equation 1;
void ListOne()
{
    printf("Enter values for First Polynomial :::\n ");
    do
    {
        // Enqueue(head1,last1);
        EnqueueOne();
        printf("Press any key for Continue and press'n' for break???\n");
    } while (getch() != 'n');
}

// function to add parameters in ploynomial equation 2;
void ListTwo()
{
    printf("Enter values for Second Polynomial :::\n ");
    do
    {
        //Enqueue(head2,last2);
        EnqueueTwo();
        printf("Press any key for Continue and press'n' for break???\n");
    } while (getch() != 'n');
}

//function to merge polynomial equation 1 and equation 2;
void merge()
{
    last1->next = head2;
}

//function to get maximun power in the polynomial equation;
int getmax(struct Node *head)
{
    struct Node *pointer;
    int max = 0;
    pointer = head;
    while (pointer != NULL)
    {
        if (max < pointer->power)
            max = pointer->power;
        pointer = pointer->next;
    }
    return max;
}

//function for addition of two polynomial equations;
void add(struct Node *head, int max)
{
    struct Node *pointer;
    int i, coefficient = 0;
    pointer = head;

    for (i = 0; i <= max; i++)
    {
        while (pointer != NULL)
        {
            if (pointer->power == i)
            {
                coefficient = coefficient + pointer->coefficient;
            }
            pointer = pointer->next;
        }
        if (coefficient != 0)
            EnqueueThree(i, coefficient);
        pointer = head;
        coefficient = 0;
    }
}

int main()
{
    int max;

    //create linked list 1 for storing polynomial equation 1;
    ListOne();
    printf("-------------------------------------------------POLY-1-------------------------------------------------\n");
    Traverse(head1);
    printf("--------------------------------------------------------------------------------------------------------\n");

    //create linked list 2 for storing polynomial equation 2;
    ListTwo();
    printf("-------------------------------------------------POLY-2-------------------------------------------------\n");
    Traverse(head2);
    printf("--------------------------------------------------------------------------------------------------------\n\n\n");

    printf("Press Any key to continue!!!!!!!!!!!!!!!!!!\t");
    getch();
    system("cls");

    //display ploynomial equation 1;
    printf("-------------------------------------------------POLY-1-------------------------------------------------\n");
    Traverse(head1);
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    //display polynominal equation 2;
    printf("-------------------------------------------------POLY-2-------------------------------------------------\n");
    Traverse(head2);
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    //display merged polynomial equation;
    merge();
    printf("----------------------------------------------MERGED-POLY-----------------------------------------------\n");
    Traverse(head1);
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    max = getmax(head1);

    add(head1, max);

    //display summed polynomial equation;
    printf("------------------------------------------------SUMMATIOM-----------------------------------------------\n");
    Traverse(head3);
    printf("--------------------------------------------------------------------------------------------------------\n");

    return 0;
}
