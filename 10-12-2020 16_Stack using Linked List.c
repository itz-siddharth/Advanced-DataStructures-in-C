#include<stdio.h>
#include<stdlib.h>

void Push(int x);
void Pop();
void Peek(); // Top()
void Display();

typedef struct node
{
	int data;
	struct node *link;
 }Node;
 
 
Node *top = 0;

void main()
{
	int choice,x;
	
	do
	{	printf("\n--------------\n");
		printf("0.Exit\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("Enter Choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\nEnter data: ");
					scanf("%d",&x);
					Push(x);
					break;
			case 2: Pop(); 
					break;
			case 3:	Peek();
					break;
			case 4: Display();
					break;
		} 
	}while(choice!=0);
}

void Push(int x)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = x;
	newnode->link = top;
	top = newnode;

}

void Display()
{
	Node *temp = top;
	
	if(top==0)
	{
		printf("Empty Stack!\n");	
	}
	else
	{
		while(temp!=0)
		{
			printf("%d\n",temp->data);
			temp = temp->link;
		}
			
	}	
}

void Peek()
{
	if(top==0)
	{
		printf("Empty Stack!\n");
	}
	else
	{
		printf("Top element is %d",top->data);
	}
}

void Pop()
{
	Node *temp = top;
	if(top==0)
	{
		printf("Underflow");
	}
	else
	{
		printf("The poped element is %d",top->data);
		top=top->link;
		free(temp);
	}
	
	
}
