#include<stdio.h>
#include<stdlib.h>

void Enqueue(int x);
void Dequeue();
void Peek(); // Top()
void Display();

typedef struct node
{
	int data;
	struct node *next;
 }Node;
 
 
Node *front=0;
Node *rear=0;

void main()
{
	int choice,x;
	
	do
	{	printf("\n--------------\n");
		printf("0.Exit\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("Enter Choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\nEnter data: ");
					scanf("%d",&x);
					Enqueue(x);
					break;
			case 2: Dequeue(); 
					break;
			case 3:	Peek();
					break;
			case 4: Display();
					break;
		} 
	}while(choice!=0);
}

void Enqueue(int x)
{

	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = x;
	newnode->next = 0;
	
	if(front==0 && rear ==0)
	{
		front = rear = newnode;
		rear->next = front;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
		rear->next = front; 
	}
}

void Display()
{
	Node *temp=front;
	
	if(front==0 && rear==0)
	{
		printf("Empty Queue!\n");	
	}
	else
	{
		while(temp->next!=front)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);	
	}	
}

void Peek()
{
	if(front==0 && rear==0)
	{
		printf("Empty Queue!\n");
	}
	else
	{
		printf("Front data is %d",front->data);
	}
}

void Dequeue()
{
	Node *temp = front;
	if(front==0 && rear==0)
	{
		printf("Underflow/Empty Queue!\n");
	}
	else if(front==rear)
	{
		front = rear = 0;
		free(temp);
	}
	else
	{
		printf("The poped element is %d\n",front->data);
		front=front->next;
		rear->next=front;
		free(temp);
	}	
}

