#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define size 10

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head[size];
struct Node *tail[size];

void InitializeHeadAndTail()
{
    for (int i = 0; i < size; i++)
    {
        head[i] = NULL;
        tail[i] = NULL;
    }
}

void GetData(int *data)
{
   printf("Please Enter %d data for Sorting??\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d.", i + 1);
        scanf("%d", &data[i]);
    }
    system("cls");


//    data[0]=253;
//    data[1] =140;
//    data[2] =980;
//    data[3] =647;
//    data[4] =289;
//    data[5] =186;
//    data[6] =155;
//    data[7] =787;
//    data[8] =328;
//    data[9] =100;

}

void DisplayData(int *data)
{
    printf("-------------------------------------------------ARRAY-CONDITION-------------------------------------------------\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
        Sleep(300);
    }
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
}

struct Node *getnode(int value)
{
    struct Node *newpointer;
    newpointer = (struct Node *)malloc(sizeof(struct Node));
    newpointer->data = value;
    newpointer->next = NULL;
    return newpointer;
}

void Push(int headno, int *data)
{
    struct Node *newpointer;
    newpointer = getnode(data);
    if (head[headno] == NULL)
    {
        head[headno] = newpointer;
    }
    else
    {
        tail[headno]->next = newpointer;
    }
    tail[headno] = newpointer;
}

void Traverse()
{
    printf("-------------------------------------------------List Condition-------------------------------------------------\n");
    int i;
    struct Node *pointer;
    for (i = 0; i < size; i++)
    {
        printf("HEAD-%d", i);
        pointer = head[i];
        if (head[i] == NULL){
            printf("------->NULL\n");
            Sleep(300);
        }
        else
        {
            while (pointer != NULL)
            {
                printf("------->%d", pointer->data);
                pointer = pointer->next;
                Sleep(300);
            }
            printf("\n");
        }
    }
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
}

void ExtractLinkedList(int *data)
{
    int i, j = 0;
    struct Node *pointer;
    for (i = 0; i < size; i++)
    {
        pointer = head[i];
        if (head[i] == NULL)
            continue;
        else
        {
            while (pointer != NULL)
            {
                data[j++] = pointer->data;
                pointer = pointer->next;
            }
        }
    }
}

void SortData(int *data)
{
    //int temp[size];

    int max;
    max = MaxDigit(data);
    int i, j,k, rem,temp;
   //for(i = 0; i < size; i++)
   //{
   //    temp[i] = data[i];
   //}
    for (j = 0; j < max; j++)
    {
        for (i = 0; i < size; i++)
        {
            temp=data[i];
            for (k = 0; k < j;k++)
                temp = temp / 10;
            rem = temp % 10;
            Push(rem, data[i]);
        }
        ExtractLinkedList(data);
        Traverse();
        DisplayData(data);
        InitializeHeadAndTail();

    }
}

int MaxDigit(int *data)
{
    int n, i;
    int count = 0, tempcount = 0;
    for (i = 0; i < size; i++)
    {
        n = data[i];
        while (n != 0)
        {
            n /= 10;
            ++tempcount;
        }

        if (count < tempcount)
            count = tempcount;
        tempcount = 0;
    }
    return count;
}

int main()
{
    int data[size];
    InitializeHeadAndTail();
    GetData(data);
    DisplayData(data);
    SortData(data);
    getch();

    return 0;
}
