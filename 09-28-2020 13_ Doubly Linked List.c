// Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node;

//Function Prototype
Node* getNode(int data);
Node* CreateLinkedList();
int Getlength();
void Display(); // Display Linked List 
void Insert(); // Insert Node
void InsertAtBeg(); // O(1)
void InsertAtEnd(); // O(1)
void InsertAtPos();  //O(1)
void Delete(); // Delete Node
void DeleteFromBeg(); //O(1)
void DeleteFromEnd(); // O(1)
void DeleteFromPos(); // O(n)
void Search(); // Search Node 

Node *head = NULL;
Node *tail = NULL;

//Main Function
void main()
{	int choice;
		
	while(1)
	{	
		printf("\n\n-----Implementation of Doubly Linked List-----\n");
		printf("0. Exit\n");
		printf("1. Create LinkedList\n");
        printf("2. Display Linked List\n");
        printf("3. Insert Node\n");
		printf("4. Delete Node\n");
		printf("5. Search Node\n");
		printf("-----------------------------------------\n");
		printf("Enter choice:");
		scanf("%d", &choice);
		printf("\n");
        
		switch(choice)
		{	case 0: exit(0);
		
			case 1: head = CreateLinkedList();
					break;	
			case 2:	Display();
					break;
			case 3: Insert();
					break;
			case 4: Delete();
					break;
			case 5: Search();
					break;
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
					
		}		
	}			
}

//-----> getNode Function Definition
Node* getNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	printf("Node %d created!\n",newNode->data);
	return newNode;	
}

int Getlength()
{
	Node *current = head;
	int count = 0;  // Initialize count 

    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count;
	
}

Node* CreateLinkedList()
{	int data,i,n;
	Node *newnode;
	
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{	
		printf("Enter node %d: ",i+1);
		scanf("%d",&data);
		newnode = getNode(data);
		
		if(head==NULL)
		{
			head = tail = newnode;
		}
		else
		{
			tail->next = newnode;	
			newnode->prev = tail;
			tail = newnode; 
		}
		printf("\n");
	}
	return head;
}

void Display()
{
	Node *temp = head;
	
	while(temp!=0)
	{
		printf("%d <-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");	
}

void Insert()
{
	int choice;
	
	printf("1.Insert in the Begining\n");
	printf("2.Insert in the Middle\n");
	printf("3.Insert at the last\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: InsertAtBeg();
			break;
		case 2: InsertAtPos();
			break;
		case 3: InsertAtEnd();	
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Inserted in Linked List\n");
	printf("New Doubly Linked List!\n ");
	Display(head);
}

void InsertAtBeg()
{	
	int val;
	Node *newnode;
	
	//input
	printf("Enter node: ");
	scanf("%d",&val);
	
	//create node
	newnode = getNode(val);
	
	head->prev = newnode;
	newnode->next = head;
	head = newnode;
}

void InsertAtEnd()
{	
	int val;
	Node *newnode;
	
	//input
	printf("Enter node: ");
	scanf("%d",&val);
	
	//create node
	newnode = getNode(val);
	
	//update tail
	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}
void InsertAtPos()
{	
	int pos,len,val;
	
	//input node
	printf("Enter node: ");
	scanf("%d",&val);
	//get size 
	len = Getlength();
	//input position
	printf("Enter position: ");
	scanf("%d",&pos);
	
	
	if(pos<1 || pos>len)
	{
		printf("Invalid Position!\n");
	}
	else if(pos == 1)
	{
		Node *newnode;
		newnode = getNode(val);
	
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
	else
	{
		Node *newnode;
		Node *temp = head;
		
		newnode = getNode(val);
		int i=1;
		
		while(i < pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		
		temp->next = newnode;
		newnode->next->prev = newnode;
		
	}
} 

void Delete()
{
	int choice;
	
	printf("1.Delete from the Begining\n");
	printf("2.Delete from the Middle\n");
	printf("3.Delete from the last\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: DeleteFromBeg();
			break;
		case 2: DeleteFromPos();
			break;
		case 3: DeleteFromEnd();	
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Deleted in Linked List\n");
	printf("New Doubly Linked List!\n ");
	Display(head);
}

void DeleteFromBeg()
{
	Node *temp;
	
	if(head==NULL)
	{
		printf("Empty Doubly List!\n");
	}
	else
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		
		free(temp);	
	}
}
void DeleteFromEnd()
{
	Node *temp;
	if(tail==0)
	{
		printf("List is Empty!\n");
	}
	else
	{
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
//		tail->prev->next = NULL;
//		tail = tail->prev;
		
		free(temp);
	}
	
}
void DeleteFromPos()
{
	int pos, len, i=1;
	Node *temp = head;
	
	printf("Enter position: ");
	scanf("%d",&pos);
	len = Getlength();
	
	if(pos==1)
	{
		DeleteFromBeg();
	}
	else if(pos==len)
	{
		DeleteFromEnd();
	}
	else
	{
		while(i<pos)
		{
			temp = temp->next;
			i++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		free(temp);
	}
}

void Search() 
{
   int pos = 0;
   int data;
   
   printf("Enter node to search:");
   scanf("%d",&data);
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   Node *current = head;
   while(current!=NULL) 
   {
      pos++;
      if(current->data == data) {
         printf("%d found at position %d\n", data, pos);
         return;
      }

      if(current->next != NULL)
         current = current->next;
      else
         break;
   }

   printf("%d does not exist in the list\n", data);
}
