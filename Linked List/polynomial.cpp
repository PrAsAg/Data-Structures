#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int pow,coeff;
	struct node *next;
};
struct node *head1,*head2,*head3;
struct node *getnode()
{
	struct node *np;
	np=(struct node*)malloc(sizeof(struct node));
	printf("\nPower: ");
	scanf("%d",&np->pow);
	printf("\nCoefficient: ");
	scanf("%d",&np->coeff);
	np->next=NULL;
	return np;
}
struct node *create(struct node *head)
{
	struct node *newptr,*ptr;
	do{
		newptr=getnode();
		if(head==NULL)
		{
			head=newptr;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=newptr;
		}
		printf("\nContinue?[y/n]\n");
	}while(getche()!='n');
	return head;
}

void add()
{
	struct node *ptr1,*ptr2,*ptr3,*np;
	ptr1=head1;
	ptr2=head2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(head3==NULL)
		{
			head3=(struct node*)malloc(sizeof(struct node));
			head3->next=NULL;
			ptr3=head3;
		}
		else
		{
			np=(struct node*)malloc(sizeof(struct node));
			np->next=NULL;
			ptr3->next=np;
			ptr3=np;
		}
		
		if(ptr1->pow>ptr2->pow)
		{
			ptr3->pow=ptr1->pow;
			ptr3->coeff=ptr1->coeff;
			ptr1=ptr1->next;
		}
		else if(ptr1->pow<ptr2->pow)
		{
			ptr3->pow=ptr2->pow;
			ptr3->coeff=ptr2->coeff;
			ptr2=ptr2->next;
		}
		else
		{
				ptr3->pow=ptr1->pow;
				ptr3->coeff=ptr1->coeff+ptr2->coeff;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
		}
	}
	while((ptr1!=NULL && ptr2==NULL) || (ptr2!=NULL && ptr1==NULL))
	{
		if(head3==NULL)
		{
			head3=(struct node*)malloc(sizeof(struct node));
			head3->next=NULL;
			ptr3=head3;
		}
		else
		{
			np=(struct node*)malloc(sizeof(struct node));
			np->next=NULL;
			ptr3->next=np;
			ptr3=np;
		}
		
		if(ptr1!=NULL)
		{
			ptr3->pow=ptr1->pow;
			ptr3->coeff=ptr1->coeff;
			ptr1=ptr1->next;
		}
		else
		{
			ptr3->pow=ptr2->pow;
			ptr3->coeff=ptr2->coeff;
			ptr2=ptr2->next;
		}
	}
}
void display(struct node *head)
{
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->next!=NULL)
			printf("%dX^%d + ",ptr->coeff,ptr->pow);
		else
			printf("%dX^%d ",ptr->coeff,ptr->pow);
		ptr=ptr->next;
	}
}
int main()
{
	head1=NULL;
	head2=NULL;
	head3=NULL;
	printf("\nEnter Ploynomial 1: ");
	head1=create(head1);
	printf("\nEnter Polynomial 2: ");
	head2=create(head2);
	add();
	printf("\nPolynomial 1: ");
	display(head1);
	printf("\nPolynomial 2: ");
	display(head2);
	printf("\nSum of Polynomials: ");
	display(head3);
	return 0;
}

